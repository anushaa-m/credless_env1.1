================================================================================
                          OS LAB CODES - ALL PROGRAMS
================================================================================

================================================================================
1. SHELL - CALCULATOR (menu driven)
================================================================================

echo menu driven calculator
while true
do
echo "1. addition 2. subtraction 3. multiplication 4. division 5. exit"
echo -n "enter your choice: "
read choice
if [$choice -eq 5]
then
echo"exiting program"
break
else
read -p "enter first number: " a
read -p "enter second number: " b
case $choice in
1)
result=$((a+b))
;;
2)
result=$((a-b))
;;
3)
result=$((a*b))
;;
4)
if [$b -eq 0]
then
echo" division by zero not possible"
else
result=$((a/b))
fi
;;
esac
echo "result is $result"
fi
done


================================================================================
2. SHELL - SHAPE AREA AND PERIMETER FINDER
================================================================================

echo "shape area and perimeter finder"
while true
do
echo "1. circle 2. rectangle 3. triangle 4.exit "
read -p "enter choice: " choice
if [ $choice -eq 4 ]
then
echo "exiting program"
break
else
case $choice in
1)
read -p "enter radius: " r
area=$(bc <<< "scale=2;3.14 * $r * $r")
perimeter=$(bc <<< "scale=2;2 * 3.14 * $r")
;;
2)
read -p "enter length: " l
read -p "enter breadth: " b
area=$((l * b))
perimeter=$((2 *(l+b)))
;;
3)
read -p "enter base: " b
read -p " enter height: " h
read -p "enter side 1 " a
read -p " enter side 2 " s2
read -p "enter size 3 " c
area=$(bc <<< "scale=2;($b * $h) / 2")
perimeter=$((a+s2+c))
;;
esac
echo "area is $area"
echo "perimeter is $perimeter"
fi
done


================================================================================
3. SHELL - STRING OPERATIONS
================================================================================

echo "string operations"
while true
do
echo "1. find length 2. concatenate strings 3. compare strings 4.reverse string 5. exit"
read -p "enter your choice" choice
if [ $choice -eq 5 ]
then
echo "exiting"
break
else
case $choice in
1)
read -p "enter a string: " str
length=${#str}
echo "length of string is $length"
;;
2)
read -p "enter string 1 " str1
read -p "enter string 2 " str2
result=$str1$str2
echo "concatenated string is $result"
;;
3)
read -p "enter string 1 " str1
read -p "enter string 2 " str2
if ["$str1"= "$str2"]
then
echo "strings are equal"
else
echo"strings are unequal"
fi
;;
4)
read -p "enter string: " str
rev=$(rev <<< "$str")
echo "reversed string is $rev"
;;
*)
echo "invalid choice"
;;
esac
fi
Done


================================================================================
4. SHELL - BUBBLE SORT
================================================================================

echo "bubble sort program"
read -p "enter number of elements" n
echo "enter elements"
for((i=0;i<n;i++))
do
read arr[$i]
done
for((i=0;i<n-1;i++))
do
for((j=0;j<n-1-i;j++))
do
if [ ${arr[$j]} -gt ${arr[$((j+1))]} ]
then
temp=${arr[$j]}
arr[$j]=${arr[$((j+1))]}
arr[$((j+1))]=$temp
fi
done
done
for((i=0;i<n;i++))
do
echo "${arr[$i]}"
done


================================================================================
5. SHELL - LINEAR SEARCH AND BINARY SEARCH
================================================================================

echo "linear search"
read -p "enter the number of elements" n
echo "enter elements one by one"
for((i=0;i<n;i++))
do
read arr[$i]
done
read -p "enter element to search" key
found=0
for ((i=0;i<n;i++))
do
if [ ${arr[$i]} -eq $key ]
then
echo "element found at position $((i+1))"
found=1
break
fi
done
if [ $found -eq 0 ]
then
echo "element not found"
fi

echo "binary search"
read -p "enter number of elements"n
echo "enter elements in sorted order"
for ((i=0;i<n;i++))
do
read arr[$i]
done
read -p "enter element to search" key
low=0
high=$((n-1))
found=0
while [ $low -le $high ]
do
mid=$((( $low + $high ) / 2))
if [ ${arr[mid]} -eq $key ]
then
echo "element found at $((mid+1))"
found=1
break
elif [ ${arr[$mid]} -lt $key ]
then
low=$((mid+1))
else
high=$((mid-1))
fi
done
if [ $found -eq 0 ]
then
echo "element not found"
fi


================================================================================
6. SHELL - DATABASE MANAGEMENT SYSTEM
================================================================================

#!/bin/bash
file="database.txt"
touch $file
echo "database management system"
while true
do
echo "1. add record 2. delete record 3. modify record 4. display record 5. exit"
read -p "enter your choice" ch
case $ch in
1)
read -p "enter id: " idy
read -p "enter name: " name
read -p "enter age: " age
echo "$idy | $name | $age" >> $file
echo "record added successfully"
;;
2)
read -p "enter id to delete: " idy
grep -v "^$idy |" $file > temp.txt
mv temp.txt $file
echo "record deleted successfully"
;;
3)
read -p "enter id to modify" idy
grep -v "^$idy |" $file >temp.txt
read -p "enter new name: " name
read -p "enter age: " age
echo "$idy | $name | $age" >> temp.txt
mv temp.txt $file
echo "record modified successfully"
;;
4)
echo "database records"
cat $file
;;
5)
echo "exiting.."
break
;;
*)
echo "invalid choice"
;;
esac
done


================================================================================
7. C - MULTITHREADED SUM (1L.c) - compile: gcc 1L.c -o 1L -pthread
================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int start;
    int end;
    long sum;
} ThreadData;

void* CalSum(void* arg)
{
    ThreadData* data = (ThreadData*)arg;
    data->sum = 0;

    for(int i = data->start; i <= data->end; i++)
    {
        data->sum += i;
    }

    printf("Thread (%d to %d) Sum = %ld\n",
           data->start, data->end, data->sum);

    pthread_exit(NULL);
}

int main()
{
    pthread_t t1, t2, t3, t4;

    ThreadData d1 = {1, 25000, 0};
    ThreadData d2 = {25001, 50000, 0};
    ThreadData d3 = {50001, 75000, 0};
    ThreadData d4 = {75001, 100000, 0};

    if (pthread_create(&t1, NULL, CalSum, &d1) != 0)
    {
        perror("Thread 1 creation failed");
        exit(1);
    }

    if (pthread_create(&t2, NULL, CalSum, &d2) != 0)
    {
        perror("Thread 2 creation failed");
        exit(1);
    }

    if (pthread_create(&t3, NULL, CalSum, &d3) != 0)
    {
        perror("Thread 3 creation failed");
        exit(1);
    }

    if (pthread_create(&t4, NULL, CalSum, &d4) != 0)
    {
        perror("Thread 4 creation failed");
        exit(1);
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    long total = d1.sum + d2.sum + d3.sum + d4.sum;

    printf("\nFinal Sum = %ld\n", total);

    return 0;
}


================================================================================
8. C - THREAD DEMO (thread_demo.c) - compile: gcc thread_demo.c -o thread_demo -pthread
================================================================================

// program name : thread_demo.c

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* worker(void* arg)
{
    int id = *(int*)arg;

    printf("Worker Thread %d started\n", id);
    printf("Thread %d ID: %lu\n", id, pthread_self());

    for(int i=1;i<=3;i++)
    {
        printf("Thread %d executing step %d\n", id, i);
        sleep(1);
    }

    printf("Worker Thread %d finished\n\n", id);

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    int id1 = 1;
    int id2 = 2;

    printf("\n====== Thread Demonstration Program ======\n\n");

    printf("Main Thread ID: %lu\n\n", pthread_self());

    printf("Main thread creating Thread 1\n");
    pthread_create(&t1, NULL, worker, &id1);

    printf("Main thread creating Thread 2\n");
    pthread_create(&t2, NULL, worker, &id2);

    printf("Main thread waiting for threads to finish...\n\n");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("All worker threads completed\n");

    printf("Main thread terminating\n");

    return 0;
}


================================================================================
9. C - SHARED MEMORY - p1_shared.c - compile: gcc p1_shared.c -o p1 -pthread
================================================================================

// program name : p1_shared.c

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* modify(void* arg)
{
    int *value = (int*)arg;

    printf("Thread %lu sees value = %d\n", pthread_self(), *value);

    (*value)++;

    printf("Thread %lu updated value = %d\n\n", pthread_self(), *value);

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    int number = 10;

    printf("Main thread value = %d\n\n", number);

    pthread_create(&t1, NULL, modify, &number);
    pthread_create(&t2, NULL, modify, &number);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final value in main thread = %d\n", number);

    return 0;
}


================================================================================
10. C - MESSAGE QUEUE SENDER (processA.c) - compile: gcc processA.c -o processA -lrt
================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>

#define Q_NAME "/uni_queue"
#define MAX_SIZE 1024

mqd_t mq;

void cleanup_exit(int sig)
{
    printf("\n[Sender] Shutting down and unlinking queue...\n");
    mq_close(mq);
    mq_unlink(Q_NAME); // The creator should usually be the one to unlink
    exit(0);
}

int main(void)
{
    char buffer[MAX_SIZE];
    struct mq_attr attr = { .mq_flags = 0, .mq_maxmsg = 10, .mq_msgsize = MAX_SIZE };

    // Register signal for Ctrl+C
    signal(SIGINT, cleanup_exit);

    // 1. Create the Queue (Write Only)
    mq = mq_open(Q_NAME, O_CREAT | O_WRONLY, 0644, &attr);
    if (mq == -1) { perror("mq_open"); exit(1); }

    printf("--- Process A (Sender) Ready ---\n");
    printf("Type messages to send to B. Type 'exit' to stop.\n");

    while (1)
    {
        printf("Send to B: ");
        fgets(buffer, MAX_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character

        // 2. Send the message
        if (mq_send(mq, buffer, strlen(buffer) + 1, 0) == -1)
        {
            perror("mq_send");
            break;
        }

        if (strcmp(buffer, "exit") == 0) break;
    }

    cleanup_exit(0);
    return 0;
}


================================================================================
11. C - MESSAGE QUEUE RECEIVER (processB.c) - compile: gcc processB.c -o processB -lrt
================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>

#define Q_NAME "/uni_queue"
#define MAX_SIZE 1024

mqd_t mq;

void handle_exit(int sig)
{
    printf("\n[Receiver] Closing connection...\n");
    mq_close(mq);
    exit(0);
}

int main(void)
{
    char buffer[MAX_SIZE + 1];
    signal(SIGINT, handle_exit);

    // 1. Open the existing Queue (Read Only)
    // We don't use O_CREAT here because we assume A starts first
    mq = mq_open(Q_NAME, O_RDONLY);
    if (mq == -1)
    {
        perror("mq_open (Is Process A running?)");
        exit(1);
    }

    printf("--- Process B (Receiver) Ready ---\n");
    printf("Waiting for messages from A...\n");

    while (1)
    {
        // 2. Receive the message (This blocks until data arrives)
        ssize_t bytes = mq_receive(mq, buffer, MAX_SIZE, NULL);

        if (bytes >= 0)
        {
            buffer[bytes] = '\0';
            printf("[B Received]: %s\n", buffer);

            if (strcmp(buffer, "exit") == 0)
            {
                printf("Exit command received. Goodbye.\n");
                break;
            }
        }
        else
        {
            perror("mq_receive");
            break;
        }
    }

    mq_close(mq);
    return 0;
}


================================================================================
12. C - SHARED MEMORY WRITER (shm_writer.c) - compile: gcc shm_writer.c -o shm_writer
================================================================================

// shm_writer.c
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    key_t key = 1234;
    // Create shared memory segment
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if (shmid < 0) {
        perror("shmget failed");
        return 1;
    }
    // Attach shared memory
    char *str = (char*) shmat(shmid, NULL, 0);
    if (str == (char*) -1) {
        perror("shmat failed");
        return 1;
    }
    printf("Write data to shared memory: ");
    fgets(str, 1024, stdin);
    printf("Data written to shared memory.\n");
    // Detach shared memory
    shmdt(str);
    return 0;
}


================================================================================
13. C - SHARED MEMORY READER (shm_reader.c) - compile: gcc shm_reader.c -o shm_reader
================================================================================

// shm_reader.c
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = 1234;
    // Access existing shared memory
    int shmid = shmget(key, 1024, 0666);
    if (shmid < 0) {
        perror("shmget failed");
        return 1;
    }
    // Attach shared memory
    char *str = (char*) shmat(shmid, NULL, 0);
    if (str == (char*) -1) {
        perror("shmat failed");
        return 1;
    }
    printf("Data read from shared memory: %s\n", str);
    // Detach shared memory
    shmdt(str);
    // Optional: remove shared memory
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}


================================================================================
14. C - FILE MOVE (copy + delete source) - compile: gcc filemove.c -o filemove
         Usage: ./filemove <source> <destination>
================================================================================

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    char ch;
    if (argc != 3)
    {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }
    fp1 = fopen(argv[1], "r");
    if (fp1 == NULL)
    {
        perror("Error opening source file");
        return 1;
    }
    fp2 = fopen(argv[2], "w");
    if (fp2 == NULL)
    {
        perror("Error opening destination file");
        fclose(fp1);
        return 1;
    }
    while ((ch = fgetc(fp1)) != EOF)
    {
        fputc(ch, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    if (remove(argv[1]) == 0)
    {
        printf("File moved successfully.\n");
    }
    else
    {
        perror("Error deleting source file");
    }
    return 0;
}


================================================================================
15. C - PIPE IPC (parent writes, child reads) - compile: gcc pipe.c -o pipe
================================================================================

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd[2];
    char write_msg[] = "Hello from parent";
    char read_msg[50];
    // Create pipe
    pipe(fd);
    // fd[0] -> read end
    // fd[1] -> write end
    if (fork() == 0)
    {
        // CHILD PROCESS
        close(fd[1]); // Close write end
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);
        close(fd[0]);
    }
    else
    {
        // PARENT PROCESS
        close(fd[0]); // Close read end
        write(fd[1], write_msg, strlen(write_msg) + 1);
        close(fd[1]);
    }
    return 0;
}


================================================================================
                              END OF FILE
================================================================================#include <stdio.h>

struct process
{
    int pid;
    int at;   // arrival time
    int bt;   // burst time
    int ct;   // completion time
    int tat;  // turnaround time
    int wt;   // waiting time
};

int main()
{
    int n, i;
    struct process p[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input
    for(i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Enter AT and BT for P%d: ", p[i].pid);
        scanf("%d %d", &p[i].at, &p[i].bt);
    }

    // FCFS logic
    for(i = 0; i < n; i++)
    {
        if(i == 0)
        {
            p[i].ct = p[i].at + p[i].bt;   // CT[0] = AT[0] + BT[0]
        }
        else
        {
            if(p[i].at > p[i-1].ct)
                p[i].ct = p[i].at + p[i].bt;
            else
                p[i].ct = p[i-1].ct + p[i].bt;
        }

        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }

    // Output
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt,
               p[i].ct, p[i].tat, p[i].wt);
    }

    return 0;
}

# Give execute permission first
chmod +x script.sh

# Then run
./script.sh

# OR run directly without chmod
bash script.sh

# Create a new file and paste code into it
nano filename.c
# (Ctrl+O to save, Ctrl+X to exit)

# Or use vim
vim filename.c
# (press i to insert, Esc then :wq to save and exit)

# List files
ls

# Check if file exists
ls -l filename.c

# Delete compiled output
rm filename

# Check running processes
ps aux

# Kill a process by name (useful if processA hangs)
pkill processA

# If message queue is stuck from previous run
# processA handles this on exit, but if it crashes:
ls /dev/mqueue/
rm /dev/mqueue/uni_queue

# If shared memory is stuck
ipcs -m           # list shared memory segments
ipcrm -m <shmid>  # remove by ID shown above