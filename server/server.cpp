#include "includes.h"
#include "../client/printa.hpp"
#include <windows.h> 

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


 

int main()
{
    //rezize
    
    SMALL_RECT windowSize = { 0, 0, 1550, 40 };
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
    //resize
    printa->project<3>("\t\t\tShelly.cc - Server");
    //make folder for licenses if does nto exist yet
    if (!fs::exists("./licenses"))
        fs::create_directories("licenses");

    CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)commands, NULL, NULL, NULL);

    WSADATA wsa_data;
    SOCKADDR_IN server_addr, client_addr;

    int wsa = WSAStartup(MAKEWORD(2, 2), &wsa_data);
    if (wsa != 0)
        return 0;

    const auto server = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    ::bind(server, reinterpret_cast<SOCKADDR*>(&server_addr), sizeof(server_addr));
    listen(server, 0);


    printf("____________________________\n\n");
    printf("listening for connections...\n");
    printf("____________________________\n\n");

    int client_addr_size = sizeof(client_addr);

    for (;;)
    {
        SOCKET client;
        if ((client = accept(server, reinterpret_cast<SOCKADDR*>(&client_addr), &client_addr_size)) != INVALID_SOCKET)
        {
            //using structure to pass multiple data via CreateThread()
            SOCKET soc = client;
            string str = inet_ntoa(client_addr.sin_addr); //client's IP
            ARGS args = { &soc, &str };

            CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)on_client_connect, &args, NULL, NULL);
        }

        const auto last_error = WSAGetLastError();

        if (last_error > 0)
        {
            printf("error: %i\n", last_error);
        }
    }
    closesocket(server);
    WSACleanup();
    return 1;
}