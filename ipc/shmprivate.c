#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SEED 65
#define SHARED_MEM_SIZE 1024

typedef struct {
    char message[SHARED_MEM_SIZE];
    int size;
} datamemory;

int main(int argc, char *argv[]) {
  
    pid_t pid;
    int status;
    int shmid;
    datamemory *shm_address;

    shmid = shmget(IPC_PRIVATE, sizeof(datamemory), 0666|IPC_CREAT);
    shm_address = (datamemory *) shmat(shmid, NULL, 0);

    pid = fork();
    if (pid) {
        sleep(1);
        strcpy(shm_address->message, "Hello, shared memory.");
        shm_address->size = sizeof("Hello, shared memory.");
        sleep(1);
        shmdt(shm_address);
        return 0;
    } else {
        printf("SHM Content: %s\n", shm_address->message);
        sleep(2);
        printf("SHM Content: %s\n", shm_address->message);
    }

    shmdt(shm_address);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}