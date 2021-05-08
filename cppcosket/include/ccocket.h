#pragma once
#ifndef DLL_EXPORT
#ifdef _WIN32
#define DLL_EXPORT __declspec(dllimport)
#else//_WIN32
#define DLL_EXPORT
#endif//_WIN32
#endif//DLL_EXPORT


#ifdef _WIN32
#include <WinSock2.h>
#else//_WIN32
#include <sys/types.h>
#include <sys/socket.h>
#endif//_WIN32

class DLL_EXPORT Csocket{
    int m_FD;
    Csocket();
    void cpy(const Csocket& obj);

public:
    Csocket(int domain, int type=SOCK_STREAM, int protocol=0);
	Csocket(const Csocket& obj);
	virtual ~Csocket(void);
	virtual int socket(int domain, int type=SOCK_STREAM, int protocol=0);
    virtual int getFD(void);
    virtual bool isOK(void);
    virtual void close(void);
    Csocket& operator=(const Csocket& obj);
};
