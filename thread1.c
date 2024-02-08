#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* producer()
{
int* v=(int*) malloc(sizeof(int));
*v=7;
return v;
}

int main()
{
pthread_t t1;
int value=3;
int *res;
pthread_create(&t1,NULL,&producer,&value);
pthread_join(t1,(void*)&res);
printf("%d\n",*res);
return 0;
}
