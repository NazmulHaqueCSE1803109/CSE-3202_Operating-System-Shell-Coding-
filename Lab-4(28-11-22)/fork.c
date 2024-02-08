#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
fork();
fork();
printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid());
printf("hello world\n");
return 0;
}
