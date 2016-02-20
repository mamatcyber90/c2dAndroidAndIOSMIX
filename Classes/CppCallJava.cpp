//
//  CppCallJava.cpp
//  SovrTest
//
//  Created by 赵永铖 on 15/12/30.
//
//

#include "CppCallJava.h"
#include "cocos2d.h"
#include <jni.h>
#include "platform/android/jni/JniHelper.h"

#include "SovrHelper.h"


#define CLASSNAME "org/cocos2dx/cpp/AppActivity"


using namespace cocos2d;

extern "C"{
    void androidCheckDeviceID(const char * deviceID){
        JniMethodInfo t;
        if (JniHelper::getStaticMethodInfo(t, CLASSNAME, "checkDeviceID", "()Ljava/lang/String;")) {
//            CallStaticStringMethod  不存在？
            jstring deviceIDjstr = (jstring)t.env->CallStaticObjectMethod(t.classID,t.methodID);
            //jstring转换
//            deviceID = JniHelper::jstring2string(deviceIDjstr);
//            log("java deviceID = %s",deviceID.c_str());
            //内存回收
            t.env->DeleteLocalRef(deviceIDjstr);
        }
    }
    
    JNIEXPORT void JNICALL Java_org_cocos2dx_cpp_AppActivity_javaCallCppTest(JNIEnv *env, jobject obj ,jstring msg) {
        JniHelper::jstring2string(msg);
        const char *m_msg = env->GetStringUTFChars(msg, NULL);
        char *my_msg = new char[strlen(m_msg)+1];
        strcpy(my_msg, m_msg);
        SovrHelper::getInstance()->methodCall()
        delete[] my_msg;
    }

    
    
}

