#include "includes.h"
#include "printa.hpp"
#include "xor.h"

//antidbg



void remove_scrollbar()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);
}
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//int main(int argc, char* argv[])

//______________________________________ANTI

auto main(int argc, char** argv) -> int
{
	//ANTI REV
	
	

	//ANTIREV
	SetConsoleTitleA(xorstr_("Shelly.cc"));
	SMALL_RECT windowSize = { 0, 0, 60, 25 };
	SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
	remove_scrollbar();
	printa->project<3>("\t\t\tShelly.cc");

	

	std::cout << "\t   "; printa->print<loading>(xorstr_("Connecting to Server...\n"));
	
	WSADATA wsa_data;
	SOCKADDR_IN addr;

	int wsa = WSAStartup(MAKEWORD(2, 2), &wsa_data);
	if (wsa != 0)
	{
		WSACleanup();
		return 0;
	}

	const auto server = socket(AF_INET, SOCK_STREAM, 0);

	InetPton(AF_INET, ip, &addr.sin_addr.s_addr);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);

	int con = connect(server, reinterpret_cast<SOCKADDR*>(&addr), sizeof(addr));
	if (con != 0)
	{
		int charcharchar;
		//std::cout << ""; printa->print<info>("");
		std::cout << "\t   "; printa->print<fail>(xorstr_("Connection Failed :(\n"));
		std::cout << "\t   "; printa->print<help>(xorstr_("You may want to check your connection ;]\n"));
		std::cout << "\t   "; printa->print<help>(xorstr_("Else the servers are down\n"));
		cin >> charcharchar;
		closesocket(server);
		WSACleanup();
		return 0;
	}
	

	//printf("connected\n");
	//std::cout << "\t   "; printa->print<loading>("Connecting to Server...\n");
	//Sleep(100);
	std::cout << "\t   "; printa->print<ok>(xorstr_("connected\n"));

	//program
	int pid = getpid();
	string license, buffer;

	//get license
	//printf("enter your license: ");
	std::cout << "\t   "; printa->print<input>(xorstr_("enter your license: "));
	cin >> license;

	//get hwid
	query();
	hwid += m_CPU + m_ComputerName + m_Physical;
	hwid.erase(remove_if(hwid.begin(), hwid.end(), isspace), hwid.end());

	//prepare and send initialization data and make encryption key
	string preInit = "initcheck__" + hwid + "__" + version + "__" + license;

	string akey = gen_random(32, pid);
	string aiv = gen_random(16, pid);

	string initData = security::encrypt(preInit, akey, aiv);
	buffer = initData + "__" + to_string(pid * 3 - 796);

	send(server, buffer.c_str(), 2048, 0);

	//receive version check and validate
	buffer = recvDec(server, akey, aiv);
	if (buffer == "badinitcheck")
	{
		printf("request took too long\n");
		closesocket(server);
		WSACleanup();
		system("pause");
	}
	else if (buffer == "goodver")
	{
		//receive license and ban check
		buffer = recvDec(server, akey, aiv);
		if (buffer == "hwidban")
		{
			//printf("you have been banned from using our services\n");
			std::cout << "\t   "; printa->print<fail>(xorstr_("you have been banned!\n"));
			closesocket(server);
			WSACleanup();
			system("pause");
		}
		else if (buffer == "invalid" || buffer == "expired")
		{
			int waaait;
			//printf("your license is invalid or expired\n");
			std::cout << "\t   "; printa->print<fail>(xorstr_("your license is invalid or expired\n"));
			closesocket(server);
			WSACleanup();
			
			cin >> waaait;
		}
		else if (buffer == "badhwid")
		{
			//printf("your license is bound to a different hwid\n");
			std::cout << "\t   "; printa->print<fail>(xorstr_("HWID mismatch\n"));
			closesocket(server);
			WSACleanup();
			system("pause");
		}
		else
		{
			//printf("sucessfully logged in\n");
			std::cout << "\t   "; printa->print<ok>(xorstr_("sucessfully logged in\n"));
			Sleep(1337);

			//system("cls");
			program();

			closesocket(server);
			WSACleanup();
			system("pause");
		}
	}
	else
	{
		//printf("invalid version\n");
		std::cout << "\t   "; printa->print<fail>(xorstr_("invalid version\n"));
		closesocket(server);
		WSACleanup();
		system("pause");
	}

	closesocket(server);
	WSACleanup();
	return 0;
} 

/*#include "printa.hpp"
auto main(int argc, char** argv) -> int
{
	printa->project<3>("printa");

	printa->print<ok>("hello world\n");
	printa->print<input>("input smthn : \n");
	printa->print<loading>("loading somwfing...\n");
	printa->print<fail>("stupid errorr!\n");
	return std::getchar();
}*/



