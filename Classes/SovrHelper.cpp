//
//  SovrHelper.cpp
//  SovrTest
//
//  Created by 赵永铖 on 15/12/30.
//
//

#include "SovrHelper.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "IOSHelper.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "CppCallJava.h"
#endif




static SovrHelper * m_instance = NULL;
SovrHelper * SovrHelper::getInstance(){
    if (!m_instance) {
        m_instance = new SovrHelper();
    }
    return m_instance;
}

SovrHelper::SovrHelper(){

}

SovrHelper::~SovrHelper(){

}


void SovrHelper::checkDeviceID(){
    std::string abc;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    IOSHelper::getInstance()->getDeviceID(abc);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    androidCheckDeviceID(abc.c_str());
#endif
    
}

void SovrHelper::methodCall(std::string msg){
    CCLOG("method call :  %s ",msg.c_str());
}


