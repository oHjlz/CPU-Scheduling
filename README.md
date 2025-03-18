# CPU Scheduling Algorithms

This project implements various CPU scheduling algorithms in C, providing a way to simulate and analyze task scheduling on the CPU. The goal is to evaluate different algorithms' behavior and performance in terms of waiting time, task order, and responsiveness.

## Table of Contents
1. [Introduction](#1-introduction)
2. [Implemented Scheduling Algorithms](#2-implemented-scheduling-algorithms)
3. [Implementation Details](#3-implementation-details)
4. [How to Compile and Run](#4-how-to-compile-and-run)
5. [Test Cases & Results](#5-test-cases--results)
6. [Conclusion](#6-conclusion)
7. [References](#7-references)


## 1. Introduction

### Purpose of CPU Scheduling
CPU scheduling determines the order in which processes are executed on the CPU. It aims to optimize CPU utilization, 
reduce waiting time, and improve system responsiveness.

### How CPU Scheduling is Achieved
The CPU scheduler selects processes based on specific scheduling algorithms. Scheduling decisions depend on factors 
like arrival time, burst time, priority, and fairness.

### Functionality
Each scheduling algorithm is tested by parsing a text file named schedule.txt, which contains tasks in the 
following format: Task #, priority, CPU-burst. The file is read line by line, and each line represents a task or node,
which is then added to a linked list that simulates a queue.

The linked list is organized differently depending on the specific algorithm being used. Each algorithm’s scheduling function 
is implemented with its unique logic to ensure the correct task ordering based on the algorithm's requirements. As a result, tasks 
are processed and executed in the order determined by the scheduling strategy.

### Makefile Overview

A Makefile automates the compilation of the scheduling program, streamlining the build process for different scheduling algorithms. It specifies how source files should be compiled and linked to create executables efficiently.

  -Compilation Commands: Run make fcfs, make sjf, make rr, make priority, or make priorityrr to build the corresponding scheduler.
  -Cleanup: Use make clean to remove compiled files and reset the project.
  -Efficiency: Only recompiles modified files, saving time and ensuring consistency.

This ensures that each scheduling algorithm is compiled correctly with minimal effort. 

## 2. Implemented Scheduling Algorithms

### 2.1 First-Come, First-Served (FCFS)
- **Concept**: The simplest scheduling algorithm, tasks are executed in the order they arrive.
- **How It Was Implemented**: A linked list maintains task order. Tasks are executed sequentially.
- **Example Execution Order**: `T1 -> T2 -> T3 -> T4 -> T5`
- **Pros**: Simple to implement.
- **Cons**: Can cause long waiting times due to the convoy effect.

### 2.2 Shortest Job First (SJF)
- **Concept**: Tasks with the shortest burst time are executed first.
- **How It Was Implemented**: A search is performed to find and execute the shortest task.
- **Example Execution Order**: `T6 (10ms) -> T4 (15ms) -> T5 (20ms) -> T1 (20ms)`
- **Pros**: Reduces waiting time.
- **Cons**: Can cause starvation for longer tasks.

### 2.3 Priority Scheduling
- **Concept**: Tasks with higher priority execute first.
- **How It Was Implemented**: Tasks are selected based on priority level.
- **Example Execution Order**: `T8 (Priority 10) -> T5 (Priority 5) -> T4 (Priority 5)`
- **Pros**: Important tasks are prioritized.
- **Cons**: Starvation for low-priority tasks.

### 2.4 Round Robin (RR)
- **Concept**: Each task gets a fixed time quantum, then moves to the back of the queue.
- **How It Was Implemented**: Tasks are cycled through, each running for a time quantum.
- **Example Execution Order**: `T8 (10ms) -> T7 (10ms) -> T6 (10ms) -> T5 (10ms)`
- **Pros**: Fair for all tasks, prevents starvation.
- **Cons**: Increased context switching overhead.

### 2.5 Priority Round Robin (Priority RR)
- **Concept**: Combines priority scheduling with Round Robin. Tasks with the same priority use Round Robin within their group.
- **How It Was Implemented**: Tasks are grouped by priority and then run in a Round Robin manner within each priority group.
- **Example Execution Order**: `T8 (25ms, finishes) -> T5 (10ms) -> T4 (10ms) -> T5 (10ms, finishes)`
- **Pros**: Prioritizes important tasks while ensuring fairness.
- **Cons**: Increased complexity.

## 3. Implementation Details

- **Programming Language Used**: C
- **Data Structures Used**:
  - Linked List for task management
  - Queue Behavior for Round Robin scheduling
- **Key Functions**:
  - `add()`: Adds a task to the list.
  - `pickNextTask()`: Selects the next task based on the scheduling algorithm.
  - `schedule()`: Executes tasks based on the selected algorithm.
  - `delete()`: Removes completed tasks.

## 4. How to Compile and Run

### Compiling the Code
```bash
make fcfs
make sjf
make priority
make rr
make priority_rr
```
##  Running the Scheduler
```
./fcfs schedule.txt
./sjf schedule.txt
./priority schedule.txt
./rr schedule.txt
./priority_rr schedule.txt
```
## 5. Test Cases & Results
**-Test Case 1: SJF**
-Command: ./sjf schedule.txt

Output:

![image](https://github.com/user-attachments/assets/5407b33e-77e9-4e14-84c8-7064fc492462)





**-Test Case 2: FCFS**
Command: ./fcfs schedule.txt

Output:

![image](https://github.com/user-attachments/assets/11fc0cbb-017c-4632-a90d-907cd7a1c4b9)

(Note: The tasks are added to the front of the list, so this is first come first serve)

**-Test Case 3: Priority Scheduling**
Command: ./priority schedule.txt

Output:

![image](https://github.com/user-attachments/assets/fc4a24fd-c0aa-49c8-b8c9-6f7ebb25c122)


-**Test Case 4: Round Robin (RR)**
Command: ./rr schedule.txt

Output:

![image](https://github.com/user-attachments/assets/cd5aba30-c513-4971-8d60-76f1c73a9e26)

(Repeat in round-robin fashion until all tasks are finished.)

**-Test Case 5: Priority Round Robin (Priority RR)**
Command: ./priority_rr schedule.txt

Output:

![image](https://github.com/user-attachments/assets/0068c808-e1ca-4143-97ce-231af4671227)


(Repeat in priority round-robin fashion until all tasks are finished.)

## 6. Conclusion
Summary of Findings

  -FCFS: Simple but inefficient.

  -SJF: Optimal for waiting time but can lead to starvation.

  -Priority Scheduling: Prioritizes important tasks but risks starvation for low-priority ones.

  -Round Robin: Fair and prevents starvation, but with overhead.

  -riority Round Robin: Balances priority and fairness.

## 7. References 
Operating System Concepts by Abraham Silberschatz, Peter Baer Galvin, and Greg Gagne – A comprehensive resource on operating system 
principles, including CPU scheduling algorithms.

O/S Course Materials – Course-specific materials covering CPU scheduling and operating systems concepts.

Online Resources on CPU Scheduling Algorithms – Various articles, tutorials, and documentation on the implementation and analysis of 
CPU scheduling algorithms:

    -GeeksforGeeks - CPU Scheduling Algorithms

    -TutorialsPoint - Operating System - CPU Scheduling

Linux Manual Pages – Official documentation on process scheduling and system calls relevant to task scheduling in Unix-like 
perating systems:

    -Linux Process Scheduling




