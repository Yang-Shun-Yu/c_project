#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_TASKS 100
#define MAX_TASK_NAME 50

typedef struct task
{
    char name[MAX_TASK_NAME];
    int completed;
}task;

int get_choice(){
    int choice;
    printf("\nWhat would you like to do?\n");
    printf("1. Add a new task\n");
    printf("2. Mark a task as completed\n");
    printf("3. Delete a task\n");
    printf("4. Display tasks\n");
    printf("5. Quit\n");

    printf("Enter your choice: ");
    scanf("%d",&choice);
    return choice;
}

void add_task(task*tasks,int *num_tasks){
    if (*num_tasks==MAX_TASKS)
    {
        printf("Sorry, you have reached the maximum number of tasks.\n");
        return;
    }

    printf("\nEnter the task description:");
    scanf("%s",tasks[*num_tasks].name);
    //scanf("%[^\n]",tasks[*num_tasks].name);
    //fgets(tasks[*num_tasks].name,50,stdin);
    //scanf("%s",tasks[*num_tasks].name);
    tasks[*num_tasks].completed = 0;
    (*num_tasks)++;
    printf("Task added successfully! \n");
    
}

void mark_task_completed(task*tasks,int num_tasks){
    int task_num;
    printf("\nEnter the task number to mark as completed :");
    scanf("%d",&task_num);
    if (task_num<1 || task_num > num_tasks)
    {
        printf("Invalid task number. Please try again.\n");
        return;
    }
    tasks[task_num-1].completed = 1;
    printf("Task marked as completed!\n");
}

void delete_task(task*tasks,int *num_tasks){
    int task_num,i;
    printf("\nEnter the task number to delete: ");
    scanf("%d",&task_num);
    if (task_num < 1 || task_num > *num_tasks)
    {
        printf("Invalid task number.Please try again.\n");
        return;
    }
    for ( i = task_num; i < *num_tasks; i++)
    {
        strcpy(tasks[i-1].name,tasks[i].name);
        tasks[i-1].completed = tasks[i].completed;
    }
    (*num_tasks)--;
    printf("Task deleted successfully!\n");
}

void display_tasks(task*tasks,int num_tasks){
    int i;
    if (num_tasks == 0)
    {
        printf("You have no tasks.\n");
        return;
    }
    printf("\nHere are your tasks:\n");
    for ( i = 0; i < num_tasks; i++)
    {
        printf("%d. %s",i+1,tasks[i].name);
        if (tasks[i].completed)
        {
            printf("(completed)");
        }
        printf("\n");
        
    }
    
}

int main(){
    task tasks[MAX_TASKS];
    int num_tasks = 0;
    int choice;
    printf("Welcome to CLI Todo List Manager!\n");
    while (1)
    {
        choice = get_choice();
        switch (choice)
        {
        case 1:
            printf("You select %d choice",choice);
            add_task(tasks,&num_tasks);
            break;
        case 2:
            printf("You select %d choice",choice);
            mark_task_completed(tasks,num_tasks);
            break;
        case 3:
            printf("You select %d choice",choice);
            delete_task(tasks,&num_tasks);
            break;
        case 4:
            printf("You select %d choice",choice);
            display_tasks(tasks,num_tasks);
            break;
        case 5:
            printf("\nGoodbye!\n");
            exit(0);
        
        default:
            printf("\nInvalid input \n");
            break;
        }
    }
    return 0;
}


