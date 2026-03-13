#include <stdio.h>
//program starts here
typedef struct
{
    char affirmation;
    char * task;
} taskstruct;
void taskcheck(int c);
//defined a data type called taskstruct which allows us to find all relevant info at one place
taskstruct taskname[];
//taskname is a variable of our defined data type
int main(int argc , char *argv)
{
    //checking for improper use of this program
    if(int argc == 1)
    {
        printf("Usage: ./taskcheck (tasks)");
        return 1;
    }
    else if(int argc > 4)
    {
        printf("This program was intended to be used with 3 tasks only, to add more please refer how to by the documentation");
    }
    else
    {
       for(int i = 1; i < argc; i++)
       {
        //asign names to the defined data type for easy access
        taskname.task[i - 1] = argv[i];
       }
       for(int k = 0; k < argc-1; k++)
       {
        taskcheck(k);
       }
    }
}
void taskcheck(int c)
{
    
}