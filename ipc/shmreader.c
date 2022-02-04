#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 

#define SEED 65
  
int main() 
{ 
    key_t key;
    int shmid;
    char *shm_address;

    key = ftok("./shmfile", SEED); 
    shmid = shmget(key, 1024, 0666|IPC_CREAT); 

    shm_address = (char*) shmat(shmid, NULL, 0); 
  
    printf("Data read from memory: %s\n", shm_address); 

    shmdt(shm_address); 
    shmctl(shmid, IPC_RMID, NULL); 
     
    return 0; 
} 