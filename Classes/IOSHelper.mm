//
//  IOSHelper.m
//  SovrTest
//
//  Created by 赵永铖 on 15/12/30.
//
//
#import "iOSHelper.h"
#import <Foundation/Foundation.h>

#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)




static IOSHelper * mInstance = nil;
IOSHelper * IOSHelper::getInstance(){
    if (!mInstance) {
        mInstance = new IOSHelper();
    }
    return mInstance;
    
}

IOSHelper::IOSHelper(){
    
    
    
}

IOSHelper::~IOSHelper(){

}



void IOSHelper::getDeviceID(string & deviceId){
    NSString * uuid;
    //使用 udid 的将不会被通过审核 请注意。
    if (SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.0"))
    {
         uuid = [[[UIDevice currentDevice] identifierForVendor] UUIDString];
    }
    else
    {
        uuid = nil;
    }

    if (uuid) {
        deviceId =  [uuid UTF8String];
        NSLog(@"uuid = %s",deviceId.c_str());
    }
    
}


