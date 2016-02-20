//
//  SteamWriter.h
//  SovrTest
//
//  Created by 赵永铖 on 16/1/5.
//
//

#ifndef __SovrTest__SteamWriter__
#define __SovrTest__SteamWriter__

#include "cocos2d.h"
using namespace cocos2d;

typedef signed char schar;

class SteamWriter : public Ref{
public:
    SteamWriter();
    ~SteamWriter();
    
    bool init();
    bool init(int capacity);
    bool init(schar * data, int capacity);
    
    static SteamWriter * create();
    static SteamWriter * create(int capacity);
    static SteamWriter * create(schar * data , int capacity);
    
    
    //write data
    void writeByte(schar v);
    void writeShort(short v);
    void writeInt(int  v);
    void writeFloat(float v);
    void writeLong(long  v);
    void writeInt64(int64_t v);
    void writeBytes(const char * byte ,int len);
    void writeUtf(const char * v);
    
    void setReleaseData(bool bReleaseData);
    
    schar* getData();
    int getDataSize();
    
protected:
    void ensureCapacity(int capacity);
    void setPosition(int position);
    int position(){return m_nWriteIndex;}
    void reset();
    
private:
    int m_nWriteIndex;
    int m_nDataSize;
    schar* m_pData;
    bool m_bReleaseData;
    
};

#endif /* defined(__SovrTest__SteamWriter__) */
