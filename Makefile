# Makefile for scheduling program
#
# make fcfs - for FCFS scheduling
# make sjf  - for SJF scheduling
# make rr   - for Round Robin scheduling
# make priority - for Priority scheduling
# make priorityrr - for Priority Round Robin scheduling

CC=gcc
CFLAGS=-Wall

clean:
	rm -rf *.o
	rm -rf fcfs sjf rr priority priority_rr  # clean up all executables

# Round Robin Scheduling
rr: driver.o list.o CPU.o schedule_rr.o
	$(CC) $(CFLAGS) -o rr driver.o schedule_rr.o list.o CPU.o

# Priority Round Robin Scheduling
priority_rr: driver.o list.o CPU.o schedule_priority_rr.o
	$(CC) $(CFLAGS) -o priority_rr driver.o schedule_priority_rr.o list.o CPU.o

# Priority Scheduling
priority: driver.o list.o CPU.o schedule_priority.o
	$(CC) $(CFLAGS) -o priority driver.o schedule_priority.o list.o CPU.o

# FCFS Scheduling
fcfs: driver.o list.o CPU.o schedule_fcfs.o
	$(CC) $(CFLAGS) -o fcfs driver.o schedule_fcfs.o list.o CPU.o

# SJF Scheduling
sjf: driver.o list.o CPU.o schedule_sjf.o
	$(CC) $(CFLAGS) -o sjf driver.o schedule_sjf.o list.o CPU.o

# Object file rules
schedule_priority.o: schedule_priority.c
	$(CC) $(CFLAGS) -c schedule_priority.c

schedule_priority_rr.o: schedule_priority_rr.c
	$(CC) $(CFLAGS) -c schedule_priority_rr.c

schedule_rr.o: schedule_rr.c
	$(CC) $(CFLAGS) -c schedule_rr.c

schedule_fcfs.o: schedule_fcfs.c
	$(CC) $(CFLAGS) -c schedule_fcfs.c

schedule_sjf.o: schedule_sjf.c
	$(CC) $(CFLAGS) -c schedule_sjf.c

# Driver file
driver.o: driver.c
	$(CC) $(CFLAGS) -c driver.c

# List file (linked list functionality)
list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

# CPU file (handling CPU logic)
CPU.o: CPU.c cpu.h
	$(CC) $(CFLAGS) -c CPU.c
