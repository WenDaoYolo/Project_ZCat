#include "../include/DataBase.h"
#include "../include/UserBase.h"
extern void level_database(const char*);
extern void level_userbase();
extern char g_filename[64];
extern bool g_LoginSuccess;

int main()
{
    level_userbase();

    if(g_LoginSuccess)
        level_database(g_filename); 

    return 0;
}