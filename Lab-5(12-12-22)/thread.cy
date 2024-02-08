#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int a[10];
int count=0;
void* producer()
{

while(1)
{
int x=rand();
if(count==9)
{
sleep(10);
}
a[count]=x;
printf("produce item: %d\n",x);
count=count+1;
}
}
void* consumer()
{
while(1)
{
int y;
if(count==0)
{
sleep(10);
}
y=a[count];
count=count-1;
printf("counsume item: %d\n",y);
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
