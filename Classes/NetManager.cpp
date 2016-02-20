//
//  NetManager.cpp
//  SovrTest
//
//  Created by 赵永铖 on 16/1/5.
//
//

#include "NetManager.h"
#include "cocos2d.h"
using namespace cocos2d;

NetManager::NetManager(){

}

NetManager::~NetManager(){

}

NetManager * m_Instance = NULL;
NetManager * NetManager::getInstance(){
    if (!m_Instance) {
        m_Instance = new NetManager();
    }
    return m_Instance;
}

void NetManager::writeMessage(std::string msg){
    CCLOG("writeMessage!");
}