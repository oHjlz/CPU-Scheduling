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
 void schedule() {
    Task *current;
    int quantum = 10;
    
    // sanity checker
    traverse(head);
    
    while (head != NULL) {
        current = pickNextTask();  // This gets the highest priority task

        int currPriority = current->priority;
        
        struct node *temp = head;
        //if the task is the only one in its priority group
        int isOnlyTask = 1;

        while(temp != NULL){
            //checking if the the tasks after the current task have the same priority
            //if any do, set to 0
            //check to make sure, your not comparing current to itself
            if(temp->task->priority == currPriority && temp->task != current){
                isOnlyTask = 0;
            }
            temp = temp->next;
        }

        //if task is by itself in its priority group run it, delete the task 
        //and continue to next iteration
        if(isOnlyTask){
            run(current, current->burst);
            printf("Task %s finished.\n" , current->name);
            delete(&head, current);
            continue;
        }


        // When burst can be completed in one quantum
        if (current->burst <= quantum) {
            run(current, current->burst);
            printf("Task %s finished.\n" , current->name);
            delete(&head, current);
        } else {
            run(current, quantum);
            current->burst -= quantum;
            
            // Need to move this task to end of its priority group
            // First find and remove the node containing this task
            struct node *prev = NULL;
            struct node *temp = head;
            
            // Find the node with the current task
            while (temp != NULL && temp->task != current) {
                prev = temp;
                temp = temp->next;
            }
            
            // If found and not at head
            if (temp != NULL && prev != NULL) {
                prev->next = temp->next;  // Remove from current position
            } 
            // If it's the head node
            else if (temp != NULL) {
                head = temp->next;  // Update head
            }
            
            // Now find where to reinsert - at end of same priority group
            int priority = current->priority;
            
            struct node *insert_after = NULL;
            struct node *scan = head;
            
            // Find the last node with the same priority
            while (scan != NULL) {
                if (scan->task->priority == priority) {
                    insert_after = scan;
                }
                scan = scan->next;
            }
            
            // If found a node with same priority, insert after it
            if (insert_after != NULL) {
                temp->next = insert_after->next;
                insert_after->next = temp;
            } 
            // If no other node with same priority, insert at head
            else {
                temp->next = head;
                head = temp;
            }
        }
    }
}
 
 /**
  * Returns the next task selected to run.
  */
 Task *pickNextTask()
 {
    struct node *temp = head;
    struct node *largest = head;

    while(temp != NULL){
       if(temp->task->priority > largest->task->priority){
           largest = temp;
       }
       temp = temp->next;
    }
    return largest->task;
 }
 