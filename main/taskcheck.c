#include <stdio.h>
//program starts here
typedef struct
{
    char affirmation;
    char * task;
    bool taskstatus;
} taskstruct;
int count = 0;
void taskcheck(void);
//defined a data type called taskstruct which allows us to find all relevant info at one place
taskstruct taskname[];
//taskname is a variable of our defined data type
int main(int argc , char *argv)
{
    //checking for improper use of this program
    if(argc == 1)
    {
        printf("Usage: ./taskcheck (tasks)");
        return 1;
    }
    else if(argc > 4)
    {
        printf("This program was intended to be used with 3 tasks only, to add more please refer how to by the documentation");
    }
    else
    {
       for(int i = 1; i < argc; i++)
       {
        //asign names to the defined data type for easy access
        taskname[i - 1].task = argv[i];
        taskname[i - 1].taskstatus = false;
       }
       count = argc - 1;
       //Run the main logic
       taskcheck();
    }
}
 void taskcheck(void)
{
    for(int i = 0; i < count - 1; i++)
    {
        printf("Task %i: %s\n", i + 1, taskname[i].task);
        scanf(" %c", &taskname[i].affirmation);
        if(taskname[i].affirmation == 'y')
        {
            printf("Good! Looks like you have done your %s work.", taskname[i].task);
        }
        else
        {
            printf("Looks like you entered a different character or havent done you work");
            taskcheck();
        }
    }
    return;
}