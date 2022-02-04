#include <stdio.h>
#include <pthread.h>

typedef int mutex_type;
int Counter[26] = {0};

void mutex_init(mutex_type *mu) {
    *mu = 0;
}

void mutex_lock(mutex_type *mu) {
    while (*mu == 1) {}
    *mu = 1;
}

void mutex_unlock(mutex_type *mu) {
    *mu = 0;
}

mutex_type lock;

void *task(void *ptr)
{   
    char letter;
    int index;

    letter = fgetc(ptr);
    index = letter - 65;

    while (letter != 10) {
        index = (int) letter - 65;
        mutex_lock(&lock);
        Counter[index]++;
        mutex_unlock(&lock);
        letter = fgetc(ptr);
    }

    return NULL;
}

int main() {

    FILE *fp1, *fp2;
    fp1 = fopen("test.txt", "r");
    fp2 = fopen("test.txt", "r");

    int i;
    fseek (fp2, 161, SEEK_SET);

    mutex_init(&lock);

    pthread_t hThread1, hThread2;
    pthread_create(&hThread1, NULL, task, fp1);
    pthread_create(&hThread2, NULL, task, fp2);
    
    pthread_join(hThread1, NULL);
    pthread_join(hThread2, NULL);

    fclose(fp1);
    fclose(fp2);

    // // print all counters
    // for (i=0; i<26; i++) {
    //     printf("%c: %d\n", i+65, Counter[i]);
    // }
    
    // print the first counter for A
    printf("A: %d\n", Counter[0]);

    return 0;
}