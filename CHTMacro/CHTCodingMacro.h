//
//  CHTCodingMacro.h
//  CHTMacroDemo
//
//  Created by cht on 2017/3/31.
//  Copyright © 2017年 cht. All rights reserved.
//

#ifndef CHTCodingMacro_h
#define CHTCodingMacro_h

// 一键实现property 属性归档 暂时不支持ivar
#import <objc/runtime.h>
#import <UIKit/UIKit.h>

typedef void(^CHTCodingHandler)(objc_property_t property, NSString * propertyName);

/// 遍历属性列表
#define CHTCodingHandlerDef    \
- (void)codingPropertiesWithHandler:(CHTPCodingHandler) codingHandler \
{ \
unsigned int propertyCount; \
objc_property_t *properties = class_copyPropertyList([self class], &propertyCount);\
for (int i = 0; i<propertyCount; i++) { \
\
objc_property_t property = properties[i];\
if (codingHandler) {\
\
codingHandler(property,[NSString stringWithUTF8String:property_getName(property)]);\
}\
}\
\
free(properties);\
}

// 序列化
#define CHTEncodeWithCoder \
- (void)encodeWithCoder:(NSCoder *)aCoder \
{ \
[self codingPropertiesWithHandler:^(objc_property_t property, NSString *propertyName) { \
[aCoder encodeObject:[self valueForKey:propertyName] forKey:propertyName]; \
}]; \
}

// 反序列化
#define CHTInitWithCoder \
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder \
{ \
self = [super init]; \
if (self) { \
[self codingPropertiesWi`thHandler:^(objc_property_t property, NSString *propertyName) { \
[self setValue:[aDecoder decodeObjectForKey:propertyName] forKey:propertyName]; \
}]; \
} \
return self; \
}

// 遵守NSCoding协议的model只要在.m中加入这句宏定义，即可实现序列化反序列化功能
#define CHTCodingPropertyImplementation \
LPCodingHandlerDef \
LPEncodeWithCoder \
LPInitWithCoder


#endif /* CHTCodingMacro_h */
