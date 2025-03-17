/**
 * Implementation of various scheduling algorithms.
 *
 * FCFS scheduling
 */
 
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 
 #include "task.h"
 #include "list.h"
 #include "cpu.h"
 
 
 // reference to the head of the list
 struct node *head = NULL;
 
 // sequence counter of next available thread identifier
 int nextTid = 0;
 
 Task *pickNextTask();
 
 // add a new task to the list of tasks
 void add(char *name, int priority, int burst) {
     // first create the new task
     Task *newTask = (Task *) malloc(sizeof(Task));
     
     newTask->name = name;
     newTask->tid = nextTid++;
     newTask->priority = priority;
     newTask->burst = burst;
 
     // insert the new task into the list of tasks 
     insert(&head, newTask);
 }
 
 /**
  * Run the FCFS scheduler
  */
 void schedule() 
{
     Task *current;
     int quantum = 10;
 
     // sanity checker
     traverse(head);
   
     while (head != NULL) {
         current = pickNextTask();
        
         //when burst can be ran in one quantum
         if(current->burst <= quantum){
            run(current, current->burst);
            printf("Task %s finished.\n" , current->name);
            delete(&head, current);
         }
         else{
            run(current, quantum); //run for the time quantum
            current->burst -= quantum; //subtracting the quantum, to get total burst left

            //Removing the first node, reassigning the head node
            //and making it a standalone node
            struct node *temp = head;
            head = head->next;
            temp->next = NULL;
            
            
            struct node *last = head;
            while(last->next != NULL){
                last = last->next;   //moving the node with burst left to the end
            }
            last->next = temp;
            
         }
     }
}
    
 
 
 /**
  * Returns the next task selected to run.
  */
 Task *pickNextTask()
 {
     return head->task;
 }
 