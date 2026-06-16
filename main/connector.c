#include <stdio.h>
// declaring popen and pclose valid for MacOS/Linux and Windows universally
#ifdef _WIN32
    #define popen _popen
    #define pclose _pclose
#endif
// Additional feature to manage project using improve-cli tool
int connector(void)
{
    printf("connector\n");
    printf("This will help this tool to extend its functionality \nby integrating improve-cli, an open source project management tool to help you track your \nprogress in various project by entering tasks accomplished in the same.\n");
    printf("This program will now execute some commands on your system to manage and install improve-cli\n");
    // Checking whether the user has already installed improve-cli on their system
    // checking if python exists on system
    char *python_key[3];
    char *python_key[0] = "py --version 2>&1";
    char *python_key[1] = "python --version 2>&1";
    char *python_key[2] = "python3 --version 2>&1";
    for(int i = 0; i < 3; i++)
    {
        // TODO: Factorize this popen and pclose block into a function
        FILE *fp = popen(python_key[i], "r");
        if (!fp)
        {
            return 1;
        }
        char buffer[512];
        fgets(buffer, sizeof(buffer), fp);
        // TODO: return the value of python keyword that worked and save it in a variable
    }
    char *improve_check = " -c \\\"import importlib.util; print(importlib.util.find_spec('improve') is not None)\\\"";
    // TODO: add python keyword and run the check command using strcat
}