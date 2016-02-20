//
//  SovrGameSocket.h
//  SovrTest
//
//  Created by 赵永铖 on 16/1/5.
//
//

#ifndef __SovrTest__SovrGameSocket__
#define __SovrTest__SovrGameSocket__

#include <sys/socket.h>

//socket 相关
#define SOCKET int
#define SOCKET_ERROR -1
#define INVALID_SOCKET -1

//数据大小相关
#define MAX_MESSAGESIZE  (16 * 1024) //消息最大长度16k
#define BLOCKSECONDS 30 //INIT 函数阻塞时间30S
#define INBUFFERSIZE (64 * 1024) //接受数据缓存暂定最大64k
#define OUTBUFFERSIZE (8 * 1024) //发送数据缓存暂定最大8k

class TCPSocket{
public:
    TCPSocket();
    bool create(const char * serverIp, int serverPort , int tagid , int nBlockSec = BLOCKSECONDS,bool keepAlive = false);
    bool sendMsg(void * pbuf , int nSize);
    bool receiveMsg(void * pBuf , int & Size);
    bool flush();
    bool check();
    void destroy();
    
    SOCKET getSocket(){return m_socketClient;}
    int getTag(){return m_Tag;}

private:
    bool recvFromSocket(); //从网络中读取尽可能多的数据
    bool hasError();  //是否发生错误，注意，异步模式未完成非错误。
    void closeSocket();
    
    SOCKET m_socketClient;
    
    //发送数据缓冲
    char  m_bufOutput[OUTBUFFERSIZE];  // 可优化为指针数组
    int  m_nOutBufLen;
    
    //环形缓冲区
    char m_bufInput[INBUFFERSIZE];  //接受数据数组
    int m_nInBufLen;
    int m_nInBufStart; //inbuf使用循环式队列，该变量为队列起点  0 -(SIZE -1)
    
    int m_Tag;
    
    
};





#endif /* defined(__SovrTest__SovrGameSocket__) */
