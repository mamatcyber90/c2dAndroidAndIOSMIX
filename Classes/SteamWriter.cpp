//
//  SteamWriter.cpp
//  SovrTest
//
//  Created by 赵永铖 on 16/1/5.
//
//

#include "SteamWriter.h"



SteamWriter::SteamWriter(){
    m_nDataSize = 0;
    m_nWriteIndex = 0;
    m_pData = NULL;
    m_bReleaseData = true;
    
}

SteamWriter::~SteamWriter(){
    if(m_bReleaseData){
        delete[] m_pData;
    }
}

bool SteamWriter::init(){
    return init(512);
}

bool SteamWriter::init(int capacity){
    m_pData = new schar[capacity];
    memset(m_pData, 0, capacity);
    m_nDataSize = capacity;
    m_nWriteIndex = 0;
    return true;
}

bool SteamWriter::init(schar * data, int capacity){
    if (data) {
        m_pData = data;
    }else{
        m_pData  = new schar[capacity];
        memset(m_pData, 0, capacity);
    }
    m_nDataSize = capacity;
    m_nWriteIndex = 0;
    return  true;
}

SteamWriter * SteamWriter::create(){
    SteamWriter * pRet = new SteamWriter();
    if (pRet && pRet->init()) {
        pRet->autorelease();
        return pRet;
    }
    delete pRet;
    pRet = NULL;
    return NULL;
}

SteamWriter * SteamWriter::create(int capacity){
    SteamWriter * pRet = new SteamWriter();
    if (pRet && pRet->init(capacity)) {
        pRet->autorelease();
        return pRet;
    }
    delete pRet;
    pRet = NULL;
    return NULL;
}

SteamWriter * SteamWriter::create(schar * data , int capacity){
    SteamWriter * pRet = new SteamWriter();
    if (pRet && pRet->init(data,capacity)) {
        pRet->autorelease();
        return pRet;
    }
    delete pRet;
    pRet = NULL;
    return NULL;

}


//write data
void SteamWriter::writeByte(schar v){
    ensureCapacity(position() + 1);
    m_pData[m_nWriteIndex++] = v;
}

void SteamWriter::writeShort(short v){
    int writeLen = sizeof(short);
    CCLOG("write short size = %d",writeLen);
    ensureCapacity(position() + writeLen);
    for (int i = 0 ; i < writeLen ; i++) {
        m_pData[m_nWriteIndex++] =   ( v >> (8 * (writeLen - i - 1))) & 0xff;
    }
}

void SteamWriter::writeInt(int  v){
    int writeLen = sizeof(int);
    CCLOG("write writeInt size = %d",writeLen);
    ensureCapacity(position() + writeLen);
    for (int i = 0 ; i < writeLen ; i++) {
        m_pData[m_nWriteIndex++] =   ( v >> (8 * (writeLen - i - 1))) & 0xff;
    }
}

void SteamWriter::writeLong(long  v){
    int writeLen = sizeof(long);
    CCLOG("write writeLong size = %d",writeLen);
    ensureCapacity(position() + writeLen);
    for (int i = 0 ; i < writeLen ; i++) {
        m_pData[m_nWriteIndex++] =   ( v >> (8 * (writeLen - i - 1))) & 0xff;
    }

}

void SteamWriter::writeInt64(int64_t v){
    //编译器处理的问题 把 int64都用 unsigned long long 进行处理
    unsigned long long lv = (unsigned long long)v;
    int writeLen = sizeof(int64_t);
    CCLOG("write int64_t size = %d",writeLen);
    ensureCapacity(position() + writeLen);
    for (int i = 0 ; i < writeLen ; i++) {
        m_pData[m_nWriteIndex++] = ( lv >> (8 * (writeLen - i - 1))) & 0xff;
    }

}


void SteamWriter::writeFloat(float v){
    int writeLen = sizeof(float);
    int intValue = 0;
    memcpy(&intValue, &v, writeLen);
    ensureCapacity(position() + writeLen);
    for (int i  = 0; i < writeLen; i++) {
        m_pData[m_nWriteIndex ++] = (intValue >> (8 * (writeLen - i - 1))) & 0xff;
    }
}

void SteamWriter::writeBytes(const char * byte ,int len){
    if (byte == NULL || len == 0) {
        return;
    }
    ensureCapacity(position() + len);
    memcpy(&m_pData[position()], byte, len);
    m_nWriteIndex += len;
}

void SteamWriter::writeUtf(const char * v){
    //写字符串格式 先写字符串长度 一个 short 然后再写 bytes 这样服务器解析比较方便
    int len = 0;
    while (v[len] != '\0') {
        len++;
    }
    writeShort(len);
    writeBytes(v, len);
}


//other setting
void SteamWriter::setReleaseData(bool bReleaseData){
    m_bReleaseData = bReleaseData;
}

schar* SteamWriter::getData(){
    return m_pData;
}

int SteamWriter::getDataSize(){
    return m_nDataSize;
}


void SteamWriter::ensureCapacity(int capacity){
    //check param
    if (capacity < 0 || capacity < m_nDataSize) {
        CCLOG("dont need realloc");
        return;
    }
    int oldCapacity = m_nDataSize;
    int newCapacity = 0;

    while (capacity > m_nDataSize) {
        oldCapacity = oldCapacity<<1;
        newCapacity = oldCapacity;
        CCLOG("realloc size....");
        if (newCapacity < 0) {
            newCapacity = 2147483647;
            break;
        }
        if (newCapacity > capacity) {
            newCapacity = capacity;
            break;
        }
    }
    
    schar * newBuf = new schar[newCapacity];
    memset(newBuf, 0, newCapacity);
    memcpy(newBuf, m_pData, oldCapacity);
    delete []m_pData;
    m_pData = newBuf;
    m_nDataSize = newCapacity;
}

void SteamWriter::setPosition(int position){
    m_nWriteIndex = position;
}

void SteamWriter::reset(){
    m_nWriteIndex = 0;
}




