#include "includes.h"

string gen_random(int len, int pid)
{
    string temp;
    static const char chars[] = "0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    srand(((unsigned)time(NULL) * pid) / 2);
    for (int i = 0; i < len; ++i)
        temp += chars[rand() % (sizeof(chars) - 1)];
    return temp;
}

string gen_random_with_delay(int len, int pid, int delay)
{
    string temp;
    static const char chars[] = "0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    srand((((unsigned)time(NULL) - delay) * pid) / 2);
    for (int i = 0; i < len; ++i)
        temp += chars[rand() % (sizeof(chars) - 1)];
    return temp;
}

string gen_random_ms(int len, int change)
{
    string temp;
    unsigned __int64 ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    static const char chars[] = "0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    srand((unsigned)ms - change);
    for (int i = 0; i < len; ++i)
        temp += chars[rand() % (sizeof(chars) - 1)];
    return temp;
}