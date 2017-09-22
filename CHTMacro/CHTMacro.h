//
//  CHTMacro.h
//  CHTMacroDemo
//
//  Created by cht on 2017/3/31.
//  Copyright © 2017年 cht. All rights reserved.
//

#ifndef CHTMacro_h
#define CHTMacro_h

/* *************************** Color ***************************************/

// RGB颜色转换（16进制->10进制）
#define CHTHexColor(rgbValue)\
\
[UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 \
alpha:1.0]

// 颜色(RGB)
#define CHTRGBColor(r, g, b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]

// 颜色(RGBA)
#define CHTRGBAColor(r, g, b, a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]

//随机颜色
#define CHTRandomColor [UIColor colorWithRed:(random() % 256 / 255.0f) green:(random() % 256 / 255.0f) blue:(random() % 256 / 255.0f) alpha:1]

/* *************************** App ***************************************/

// App Delegate
#define kAppDelegate             [UIApplication sharedApplication].delegate
// App Window
#define kAppWindow [UIApplication sharedApplication].keyWindow
// App Name
#define kAppDisplayName          [[NSBundle mainBundle] \
objectForInfoDictionaryKey:@"CFBundleDisplayName"]
// App Version
#define kAppDisplayVersion     [[[NSBundle mainBundle] infoDictionary] \
objectForKey:@"CFBundleShortVersionString"]
#define kUserDefaults      [NSUserDefaults standardUserDefaults]
#define kNotificationCenter [NSNotificationCenter defaultCenter]

// System Language
#define CHTCurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])

/* *************************** Frame ***************************************/

// Screen width & height
#define CHTScreenWidth         [[UIScreen mainScreen] bounds].size.width
#define CHTScreenHeight        [[UIScreen mainScreen] bounds].size.height

// 系统控件默认高度
#define kStatusBarHeight        (20.f)
#define kTopBarHeight           (44.f)
#define kBottomBarHeight        (49.f)
#define kCellDefaultHeight      (44.f)
#define kEnglishKeyboardHeight  (216.f)
#define kChineseKeyboardHeight  (252.f)
//适配iPhone X
#define kNavigationBarHeight    (([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) ? 88 : 64: 64))

// View 坐标(x,y)和宽高(width,height)
#define X(v)                    (v).frame.origin.x
#define Y(v)                    (v).frame.origin.y
#define WIDTH(v)                (v).frame.size.width
#define HEIGHT(v)               (v).frame.size.height
#define CENTER_X(v)             (v).center.x
#define CENTER_Y(v)             (v).center.y

#define MinX(v)                 CGRectGetMinX((v).frame)
#define MinY(v)                 CGRectGetMinY((v).frame)

#define MidX(v)                 CGRectGetMidX((v).frame)
#define MidY(v)                 CGRectGetMidY((v).frame)

#define MaxX(v)                 CGRectGetMaxX((v).frame)
#define MaxY(v)                 CGRectGetMaxY((v).frame)

/* *************************** Version ***************************************/

// 当前版本
#define FSystemVersion          ([[[UIDevice currentDevice] systemVersion] floatValue])
#define DSystemVersion          ([[[UIDevice currentDevice] systemVersion] doubleValue])
#define SSystemVersion          ([[UIDevice currentDevice] systemVersion])

//判断 iOS 8 或更高的系统版本
#define IOS_VERSION_8_OR_LATER (([[[UIDevice currentDevice] systemVersion] floatValue] >=8.0)? (YES):(NO))

/* *************************** Device ***************************************/

// 判断当前的iPhone设备/系统版本
//判断是否为iPhone
#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)

//判断是否为iPad
#define IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

//判断是否为ipod
#define IS_IPOD ([[[UIDevice currentDevice] model] isEqualToString:@"iPod touch"])

// 判断是否为 iPhone 5SE
#define iPhone5SE [[UIScreen mainScreen] bounds].size.width == 320.0f && [[UIScreen mainScreen] bounds].size.height == 568.0f

// 判断是否为iPhone 6/6s
#define iPhone6_6s [[UIScreen mainScreen] bounds].size.width == 375.0f && [[UIScreen mainScreen] bounds].size.height == 667.0f

// 判断是否为iPhone 6Plus/6sPlus
#define iPhone6Plus_6sPlus [[UIScreen mainScreen] bounds].size.width == 414.0f && [[UIScreen mainScreen] bounds].size.height == 736.0f

#define isRetina ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), ［UIScreen mainScreen] currentMode].size) : NO)

// 判断是真机还是模拟器
#if TARGET_OS_IPHONE
//iPhone Device
#endif

#if TARGET_IPHONE_SIMULATOR
//iPhone Simulator
#endif

/* *************************** Method ***************************************/

// 弱引用/强引用
#define CHTWeakSelf(type)  __weak typeof(type) weak##type = type;
#define CHTStrongSelf(type)  __strong typeof(type) type = weak##type;

// 设置图片
#define CHTSetImage(imageName) [UIImage imageNamed:imageName]

// 设置字体
#define CHTTextFont(fontSize) [UIFont systemFontOfSize:fontSize]

// view 设置边框圆角
#define LRViewBorderRadius(View, Radius, Width, Color)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

// 由角度转换弧度 由弧度转换角度
#define CHTDegreesToRadian(x) (M_PI * (x) / 180.0)
#define CHTRadianToDegrees(radian) (radian*180.0)/(M_PI)

// 获取一段时间间隔
#define kStartTime CFAbsoluteTime start = CFAbsoluteTimeGetCurrent();
#define kEndTime  NSLog(@"Time: %f", CFAbsoluteTimeGetCurrent() - start)

/**************************** nil ***************************************/

// 字符串是否为空
#define kStringIsEmpty(str) ([str isKindOfClass:[NSNull class]] || str == nil || [str length] < 1 ? YES : NO )
// 数组是否为空
#define kArrayIsEmpty(array) (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0)
// 字典是否为空
#define kDictIsEmpty(dic) (dic == nil || [dic isKindOfClass:[NSNull class]] || dic.allKeys == 0)
// 是否是空对象
#define kObjectIsEmpty(_object) (_object == nil \
|| [_object isKindOfClass:[NSNull class]] \
|| ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) \
|| ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] == 0))

/**************************** 沙盒 ***************************************/

//获取沙盒 temp
#define CHTPathTemp NSTemporaryDirectory()

//获取沙盒 Document
#define CHTPathDocument [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]

//获取沙盒 Cache
#define CHTPathCache [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]

/* *************************** Log ***************************************/

//打印位置的 NSLog
//release 状态下禁用NSLog 及 CHTLog
#ifndef __OPTIMIZE__
#define NSLog(...) NSLog(__VA_ARGS__)
#define CHTLog(format, ...) do {                                                                     \
fprintf(stderr, "<%s : %d> %s\n",                                                               \
[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String],                      \
__LINE__, __func__);                                                                            \
(NSLog)((format), ##__VA_ARGS__);                                                               \
fprintf(stderr, "-----------------------------------------------------------------------\n");   \
} while (0)
#else
#define NSLog(...)
#define CHTLog(...)
#endif



#endif /* CHTMacro_h */
