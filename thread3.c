#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>

int a[10];
int count=0;


void* producer()
{
while(1)
{
int x=rand()%100;
if(count==10)
{
sleep(2);
}
a[count]=x;
count=count+1;
printf("Produced item : %d\n",x);
}
}

void* consumer()
{
while(1)
{
if(count==0)
{
sleep(2);
}
int y=a[count];
count=count-1;
printf("Consumed item : %d\n",y);
}
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
