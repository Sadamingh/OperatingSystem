#include <stdio.h> 
#include <string.h>
#include <sys/ipc.h> 
#include <sys/shm.h> 
  
int main() 
{
    key_t key;
    int shmid;
    char *str;

    key = ftok("./shmfile", 65); 
    shmid = shmget(key, 1024, 0666|IPC_CREAT); 
    str = (char*) shmat(shmid, NULL, 0); 
  
    strcpy(str, "Hello, shared memory.");
      
    shmdt(str); 
  
    return 0; 
} 