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
Running task = [T8] [10] [25] for 25 units.
Running task = [T7] [3] [30] for 30 units.
Running task = [T6] [1] [10] for 10 units.
Running task = [T5] [5] [20] for 20 units.
Running task = [T4] [5] [15] for 15 units.
Running task = [T3] [3] [25] for 25 units.
Running task = [T2] [3] [25] for 25 units.
Running task = [T1] [4] [20] for 20 units.

**-Test Case 2: FCFS**
Command: ./fcfs schedule.txt

Output:
Running task = [T8] [10] [25] for 25 units.
Running task = [T7] [3] [30] for 30 units.
Running task = [T6] [1] [10] for 10 units.
Running task = [T5] [5] [20] for 20 units.
Running task = [T4] [5] [15] for 15 units.
Running task = [T3] [3] [25] for 25 units.
Running task = [T2] [3] [25] for 25 units.
Running task = [T1] [4] [20] for 20 units.
(Note: The tasks are added to the front of the list, so this is first come first serve)

**-Test Case 3: Priority Scheduling**
Command: ./priority schedule.txt

Output:
Running task = [T8] [10] [25] for 25 units.
Running task = [T5] [5] [20] for 20 units.
Running task = [T4] [5] [15] for 15 units.
Running task = [T1] [4] [20] for 20 units.
Running task = [T7] [3] [30] for 30 units.
Running task = [T3] [3] [25] for 25 units.
Running task = [T2] [3] [25] for 25 units.
Running task = [T6] [1] [10] for 10 units.

-**Test Case 4: Round Robin (RR)**
Command: ./rr schedule.txt

Output:
Running task = [T8] [10] [25] for 10 units.
Running task = [T7] [3] [30] for 10 units.
Running task = [T6] [1] [10] for 10 units.
Task T6 finished.
Running task = [T5] [5] [20] for 10 units.
Running task = [T4] [5] [15] for 10 units.
Running task = [T3] [3] [25] for 10 units.
Running task = [T2] [3] [25] for 10 units.
Running task = [T1] [4] [20] for 10 units.
Running task = [T8] [10] [15] for 10 units.
Running task = [T7] [3] [20] for 10 units.
Running task = [T5] [5] [10] for 10 units.
Task T5 finished.
Running task = [T4] [5] [5] for 5 units.
Task T4 finished.
Running task = [T3] [3] [15] for 10 units.
Running task = [T2] [3] [15] for 10 units.
Running task = [T1] [4] [10] for 10 units.
Task T1 finished.
Running task = [T8] [10] [5] for 5 units.
Task T8 finished.
Running task = [T7] [3] [10] for 10 units.
Task T7 finished.
Running task = [T3] [3] [5] for 5 units.
Task T3 finished.
Running task = [T2] [3] [5] for 5 units.
Task T2 finished.
(Repeat in round-robin fashion until all tasks are finished.)

**-Test Case 5: Priority Round Robin (Priority RR)**
Command: ./priority_rr schedule.txt

Output:
Running task = [T8] [10] [25] for 25 units.
Task T8 finished.
Running task = [T5] [5] [20] for 10 units.
Running task = [T4] [5] [15] for 10 units.
Running task = [T5] [5] [10] for 10 units.
Task T5 finished.
Running task = [T4] [5] [5] for 5 units.
Task T4 finished.
Running task = [T1] [4] [20] for 20 units.
Task T1 finished.
Running task = [T7] [3] [30] for 10 units.
Running task = [T3] [3] [25] for 10 units.
Running task = [T2] [3] [25] for 10 units.
Running task = [T7] [3] [20] for 10 units.
Running task = [T3] [3] [15] for 10 units.
Running task = [T2] [3] [15] for 10 units.
Running task = [T7] [3] [10] for 10 units.
Task T7 finished.
Running task = [T3] [3] [5] for 5 units.
Task T3 finished.
Running task = [T2] [3] [5] for 5 units.
Task T2 finished.
Running task = [T6] [1] [10] for 10 units.
Task T6 finished.
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




