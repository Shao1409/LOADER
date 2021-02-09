#pragma once

//defines
#define _CRT_NONSTDC_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS

//main
#include <iostream>
#include <fstream>
#include <filesystem>

//socket
#include <winsock2.h>

//crypto
#include "../shared/crypto/crypto.h"

//time
#include <chrono>

//extra
#pragma comment(lib,"WS2_32")

//namespaces
using namespace std;
using namespace chrono;
namespace fs = filesystem;

/*************************************************************/
inline string version = "0.0.1";    //version of your program
inline constexpr int port = 1337;   // port
/*************************************************************/

//declarations
void on_client_connect(LPVOID Ar);

void sendEnc(SOCKET s, string data, string akey, string aiv);
string recvDec(SOCKET s, string akey, string aiv);

string gen_random(int len, int pid);
string gen_random_with_delay(int len, int pid, int delay);
string gen_random_ms(int len, int change);

void commands();
void on_client_connect(LPVOID Ar);

inline int connections = 0;
inline ofstream file;

struct ARGS {
    SOCKET* soc;
    string* str;
};