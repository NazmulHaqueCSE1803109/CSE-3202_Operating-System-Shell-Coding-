#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

void* producer()
{
printf("HI! I am Producer.\n");
}
void* consumer()
{
printf("HI! I am Consumer.\n");
}

int main()
{
pthread_t t1,t2;
pthread_create(&t1,NULL,&producer,NULL);
pthread_create(&t2,NULL,&consumer,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
return 0;
}
