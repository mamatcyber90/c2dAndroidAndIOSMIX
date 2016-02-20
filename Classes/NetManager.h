//
//  NetManager.h
//  SovrTest
//
//  Created by 赵永铖 on 16/1/5.
//
//

#ifndef __SovrTest__NetManager__
#define __SovrTest__NetManager__

#include <stdio.h>

class NetManager{
private:
    NetManager();
    ~NetManager();
public:
    static NetManager * getInstance();
    void writeMessage(std::string msg);
    
};

#endif /* defined(__SovrTest__NetManager__) */
