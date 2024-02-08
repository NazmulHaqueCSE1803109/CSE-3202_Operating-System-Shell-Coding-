#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>

int count=0;
int a[10];
pthread_mutex_t m;

void* producer()
{
    int item;
    while(1)
    {
        int x=rand()%100;
        pthread_mutex_lock(&m);
        a[count]=x;
        printf("Produced Item : %d\n",x);
        count=count+1;
        pthread_mutex_unlock(&m);
        if(count==10)
        {
            sleep(2);
        }
    }
}

void* consumer()
{
    while(1)
    {
        pthread_mutex_lock(&m);
        count=count-1;
        int y=a[count];
        printf("Consumed Item : %d\n",y);
        pthread_mutex_unlock(&m);
        if(count==0)
        {
            sleep(2);
        }
    }
}

int main()
{
    pthread_t t1,t2;
    pthread_mutex_init(&m,NULL);
    pthread_create(&t1,NULL,&producer,NULL);
    pthread_create(&t2,NULL,&consumer,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_mutex_destroy(&m);
    return 0;
}