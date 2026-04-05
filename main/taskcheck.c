#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Defined data type to store task information
typedef struct
{
    char affirmation;
    char *task;
    bool taskstatus;
} taskstruct;

#define MAX_TASKS 8

taskstruct *taskname = NULL;
int count = 0;

void taskcheck(void);

int main(int argc, char *argv[])
{
    // Checking for improper use of this program
    if (argc == 1)
    {
        printf("Usage: ./taskcheck <task1> <task2> ... (max 8 tasks)\n");
        return 1;
    }

    if (argc > MAX_TASKS + 1)
    {
        printf("Error: This program supports a maximum of %d tasks only.\n", MAX_TASKS);
        return 1;
    }

    // Allocate memory for tasks
    count = argc - 1;
    taskname = (taskstruct *)malloc(count * sizeof(taskstruct));

    if (taskname == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    // Assign task names and initialize status
    for (int i = 0; i < count; i++)
    {
        taskname[i].task = argv[i + 1];
        taskname[i].taskstatus = false;
        taskname[i].affirmation = '\0';
    }

    // Run the main logic
    taskcheck();

    // Free allocated memory
    free(taskname);
    taskname = NULL;

    return 0;
}

void taskcheck(void)
{
    // Process all tasks (fixed: was count - 1, which skipped last task)
    for (int i = 0; i < count; i++)
    {
        printf("Task %d: %s\n", i + 1, taskname[i].task);
        printf("Completed? (y/n): ");

        // Validate scanf return value
        if (scanf(" %c", &taskname[i].affirmation) != 1)
        {
            printf("Error: Invalid input. Please try again.\n");
            // Clear input buffer
            while (getchar() != '\n');
            i--; // Retry this task
            continue;
        }

        if (taskname[i].affirmation == 'y' || taskname[i].affirmation == 'Y')
        {
            taskname[i].taskstatus = true;
            printf("Good! You've completed your %s work.\n\n", taskname[i].task);
        }
        else if (taskname[i].affirmation == 'n' || taskname[i].affirmation == 'N')
        {
            printf("Make sure to complete your %s work.\n\n", taskname[i].task);
        }
        else
        {
            printf("Invalid input. Please enter 'y' or 'n'.\n\n");
            i--; // Retry this task
        }
    }

    // Print summary
    printf("\n--- Task Summary ---\n");
    int completed = 0;
    for (int i = 0; i < count; i++)
    {
        if (taskname[i].taskstatus)
            completed++;
        printf("Task %d: %s - %s\n", i + 1, taskname[i].task,
               taskname[i].taskstatus ? "Completed" : "Pending");
    }
    printf("Completed: %d/%d tasks\n", completed, count);
}
