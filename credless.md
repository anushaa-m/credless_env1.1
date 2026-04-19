

---

## 🔹 1. IPC using Pipe

```c
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char msg[] = "Hello from parent";
    char buffer[100];

    pipe(fd);

    if(fork() > 0) {
        close(fd[0]);
        write(fd[1], msg, strlen(msg)+1);
        close(fd[1]);
    } else {
        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(fd[0]);
    }
    return 0;
}
```

---

## 🔹 2. Matrix Multiplication

```c
#include <stdio.h>

int main() {
    int r1, c1, r2, c2;
    scanf("%d %d", &r1, &c1);
    scanf("%d %d", &r2, &c2);

    if(c1 != r2) {
        printf("Not possible\n");
        return 0;
    }

    int A[10][10], B[10][10], C[10][10];

    for(int i=0;i<r1;i++)
        for(int j=0;j<c1;j++)
            scanf("%d",&A[i][j]);

    for(int i=0;i<r2;i++)
        for(int j=0;j<c2;j++)
            scanf("%d",&B[i][j]);

    for(int i=0;i<r1;i++)
        for(int j=0;j<c2;j++) {
            C[i][j]=0;
            for(int k=0;k<c1;k++)
                C[i][j]+=A[i][k]*B[k][j];
        }

    for(int i=0;i<r1;i++) {
        for(int j=0;j<c2;j++)
            printf("%d ",C[i][j]);
        printf("\n");
    }
}
```

---

## 🔹 3. Banker’s Algorithm

```c
#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d",&n,&m);

    int alloc[n][m], max[n][m], need[n][m], avail[m];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&max[i][j]);

    for(int i=0;i<m;i++)
        scanf("%d",&avail[i]);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            need[i][j] = max[i][j] - alloc[i][j];

    int finish[n], safe[n];
    for(int i=0;i<n;i++) finish[i]=0;

    int count=0;
    while(count<n) {
        int found=0;
        for(int i=0;i<n;i++) {
            if(!finish[i]) {
                int ok=1;
                for(int j=0;j<m;j++)
                    if(need[i][j]>avail[j]) ok=0;

                if(ok) {
                    for(int j=0;j<m;j++)
                        avail[j]+=alloc[i][j];
                    safe[count++]=i;
                    finish[i]=1;
                    found=1;
                }
            }
        }
        if(!found) {
            printf("Unsafe\n");
            return 0;
        }
    }

    printf("Safe Sequence: ");
    for(int i=0;i<n;i++)
        printf("P%d ", safe[i]);
}
```

---

## 🔹 4. Producer–Consumer (Semaphore)

```c
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define SIZE 5

int buffer[SIZE], in=0, out=0;
sem_t empty, full;
pthread_mutex_t mutex;

void* producer(void* p){
    for(int i=0;i<5;i++){
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        buffer[in]=i;
        printf("Produced %d\n",i);
        in=(in+1)%SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

void* consumer(void* c){
    for(int i=0;i<5;i++){
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        int item=buffer[out];
        printf("Consumed %d\n",item);
        out=(out+1)%SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main(){
    pthread_t p,c;
    sem_init(&empty,0,SIZE);
    sem_init(&full,0,0);
    pthread_mutex_init(&mutex,NULL);

    pthread_create(&p,NULL,producer,NULL);
    pthread_create(&c,NULL,consumer,NULL);

    pthread_join(p,NULL);
    pthread_join(c,NULL);
}
```

---

## 🔹 5. Round Robin Scheduling

```c
#include <stdio.h>

int main() {
    int n,tq;
    scanf("%d",&n);

    int bt[n], rem[n];
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
        rem[i]=bt[i];
    }

    scanf("%d",&tq);

    int time=0;
    while(1){
        int done=1;
        for(int i=0;i<n;i++){
            if(rem[i]>0){
                done=0;
                if(rem[i]>tq){
                    time+=tq;
                    rem[i]-=tq;
                } else {
                    time+=rem[i];
                    printf("P%d finished at %d\n",i,time);
                    rem[i]=0;
                }
            }
        }
        if(done) break;
    }
}
```

---

## 🔹 6. Shell Database Script

```bash
#!/bin/sh

db="student.txt"

while true
do
echo "1.Create 2.Insert 3.Display 4.Search 5.Delete 6.Exit"
read ch

case $ch in
1) > $db ;;
2)
read roll name marks
echo "$roll $name $marks" >> $db
;;
3) cat $db ;;
4)
read roll
grep "^$roll" $db
;;
5)
read roll
grep -v "^$roll" $db > temp.txt
mv temp.txt $db
;;
6) break ;;
*) echo "Invalid" ;;
esac
done
```

---
