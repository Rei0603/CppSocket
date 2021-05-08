#ifdef _MSC_VER
#pragma comment(lib, "ws2_32.lib")
#endif

#ifdef _WIN32
    #define DLL_EXPORT __declspec(dllexport)
#else//_WIN32
    inline static void closesocket(int s){close(s);}
#endif//_WIN32
#include "../include/ccocket.h"


Csocket::Csocket()
:m_FD(-1)
{}

Csocket::Csocket(int domain, int type, int protocol)
:Csocket()
{
    m_FD = ::socket(domain, type, protocol);
}

Csocket::Csocket(const Csocket& obj)
{
	cpy(obj);
}

Csocket::~Csocket(void)
{
	close();
}

void Csocket::close(){
    ::closesocket(m_FD);
    m_FD = -1;
}
int Csocket::socket(int domain, int type, int protocol)
{
    if(isOK()){
        closesocket(m_FD);
    }
    m_FD = ::socket(domain, type, protocol);
    return m_FD;
}
int Csocket::getFD()
{
    return m_FD;
}
bool Csocket::isOK(){
    return (m_FD < 0) ? false : true;
}

void Csocket::cpy(const Csocket& obj)
{
    m_FD = obj.m_FD;
}


Csocket& Csocket::operator=(const Csocket& obj)
{
    if(isOK()){
        close();
    }
    cpy(obj);
    return *this;
}

