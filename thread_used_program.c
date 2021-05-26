// gcc -o pthread thread_used_program.c -lpthread
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_THREADS 10

void *print_hello_World(void *tid)
{
    // thread ID 출력 & exit
    printf("Hello World. Greetings from thread %d\n", tid);
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    // create 10개의 threads & exit
    pthread_t threads[NUMBER_OF_THREADS];
    int status, i;

    for (i = 0; i < NUMBER_OF_THREADS; i++)
    {
        printf("Main here. Creating thread %d\n", i);
        status = pthread_create(&threads[i], NULL, print_hello_World, (void *)i);

        if (status != 0)
        {
            printf("Oops. pthread_create returned error code %d\n", status);
            exit(-1);
        }
    }
    exit(NULL);
}