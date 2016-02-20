//
//  SovrHelper.h
//  SovrTest
//
//  Created by 赵永铖 on 15/12/30.
//
//

#ifndef __SovrTest__SovrHelper__
#define __SovrTest__SovrHelper__

#include "cocos2d.h"
using namespace cocos2d;
using namespace std;

//using common Api to call Java or Oc
class SovrHelper : public Ref{
private:
    SovrHelper();
    ~SovrHelper();
    
public:
    static SovrHelper * getInstance();
    
    void checkDeviceID();
    
    //android test
    void methodCall(std::string msg);
    
public:
    string mDeviceID;
};


#endif /* defined(__SovrTest__SovrHelper__) */
