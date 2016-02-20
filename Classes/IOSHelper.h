//
//  IOSHelper.h
//  SovrTest
//
//  Created by 赵永铖 on 15/12/30.
//
//

#ifndef SovrTest_IOSHelper_h
#define SovrTest_IOSHelper_h
#include "cocos2d.h"
using namespace cocos2d;
using namespace std;

class IOSHelper {

private:
    IOSHelper();
    ~IOSHelper();
    
public:
    static IOSHelper * getInstance();
    void getDeviceID(string & deviceId);

};

#endif
