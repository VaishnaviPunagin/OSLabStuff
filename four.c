#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int g = 0;

void *myThreadFun(void *vargp) //all threads execute this func()
{
    int *myid = (int *)vargp; //value arg passed is stored in this thread
    static int s = 0; //static variable, to see changes
    ++s; ++g; //change values of static and global var
    printf("Thread ID: %d, Static: %d, Global: %d\n", *myid, ++s, ++g);
}

int main()
{
    int i;
    pthread_t tid;
    for (i = 0; i < 3; i++)
        pthread_create(&tid, NULL, myThreadFun, (void *)&tid); 
    pthread_exit(NULL);
    return 0;
}
