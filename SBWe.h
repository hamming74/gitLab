//
//  SBWeChatPay.h
//  SPaySDKDemo
//
//  Created by Ming on 16/8/3.
//  Copyright © 2016年 Yirupay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//#import "SPayClient.h"

@interface SBWeChatPay : NSObject

+ (instancetype)sharedInstance;

+ (instancetype)sPayClientSharedInstance;

- (void)wechatPayConfigScheme:(NSString *)scheme andId:(NSString *)appId;

/*
 微信预下单接口参数构造
 */
- (NSDictionary*)paywithtx:(NSString*)tx
                merOrderId:(NSString*)merOrderId
                    mer_no:(NSString*)mer_no
                  merAppId:(NSString*)merAppId
                 merUserId:(NSString*)merUserId
                 goodsName:(NSString*)goodsName
               goodsDetail:(NSString*)goodsDetail
                  orderAmt:(NSString*)orderAmt
             payExpireTime:(NSString*)payExpireTime
                  currency:(NSString*)currency
                terminalIp:(NSString*)terminalIp
                 notifyUrl:(NSString*)notifyUrl
              merOrderDate:(NSString*)merOrderDate
                  sign_msg:(NSString*)sign_msg;


/*
    微信下单
    交易代码
    NSString *tx;
    商户参数（流水号，商户号，商户appid，用户号，商户订单日期(格式：yyyyMMdd)）
    NSString *merOrderId, *mer_no, *merAppId, *merUserId, *merOrderDate, *signMsg;
    商品信息（商品名称，商品详情，金额）
    NSString *goodsName, *goodsDetail, *orderAmt;
    后台通知接口
    NSString *notifyUrl;

 */
- (void)SWXpayAction:(NSDictionary*)Info
      selfController:(UIViewController*)pushFromCtrl
             success:(void (^)(NSString *messageString))success
              failed:(void (^)(NSString *failNO))failure;




/*
 银行卡支付参数构造
 */
- (NSDictionary*)paywithId:(NSString*)merchantId
                 merUserId:(NSString*)merUserId
                    amount:(NSString*)amount
                merOrderNo:(NSString*)merOrderNo
               callbackUrl:(NSString*)callbackUrl
                 goodsName:(NSString*)goodsName
                 goodsDesc:(NSString*)goodsDesc
                 informUrl:(NSString*)informUrl
                signnature:(NSString*)signnature;


- (void)SBankPayAction:(NSDictionary*)postInfo
        selfController:(UIViewController*)pushFromCtrl
               success:(void (^)(NSString *messageString))success
                failed:(void (^)(NSString *failNO))failure;


#pragma mark - 使用微信APP支付和支付宝APP支付，必须实现以下三个UIApplicationDelegate代理方法

- (BOOL)application:(UIApplication *)application
didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

- (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
  sourceApplication:(NSString *)sourceApplication
         annotation:(id)annotation;

- (BOOL)application:(UIApplication *)application
      handleOpenURL:(NSURL *)url;

- (BOOL)application:(UIApplication *)app
            openURL:(NSURL *)url
            options:(NSDictionary<NSString*, id> *)options NS_AVAILABLE_IOS(9_0); // no equiv. notification. return NO if the application can't open for some reason
//
//- (void)applicationWillEnterForeground:(UIApplication *)application;



@end
