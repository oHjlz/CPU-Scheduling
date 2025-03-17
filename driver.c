#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "cpu.h"
#include "task.h"

// Function to read tasks from schedule.txt
void readTasks(char filename[]){
    FILE *file = fopen(filename, "r"); // opening file
    if(!file){
        printf("Error: Could not open %s\n", filename);
        exit(1);
    }

    char taskName[20]; //stores the task name
    int priority, burst; //stores priority and cpu burst time


    //Reads one line at a time, reading each characyer until a comma is found. 
    //runs as long as there is 3 values 
    while (fscanf(file, "%[^,], %d, %d\n", taskName, &priority, &burst) == 3) {

        add(strdup(taskName),priority,burst);
        //printf("Task Name: %s, Priority: %d, Burst: %d\n", taskName, priority, burst);

    }

    fclose(file);
}

int main(int argc, char *argv[]){
    //Check to see if the program is being run correctly
    //i.e: ./program schedule.txt
    if(argc != 2){
        printf("Usage: %s schedule.txt\n", argv[0]);
        return 1;
    }
    readTasks(argv[1]);  // Load tasks from schedule.txt
    schedule();  // Call the scheduling algorithm (FCFS, SJF, RR, etc.)

    return 0;

}
