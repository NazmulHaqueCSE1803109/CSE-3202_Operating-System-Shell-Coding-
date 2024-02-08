#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
int n1=fork();
if(n1>0)
{
 printf("[parent] pid %d\n",getpid());
 sleep(20); 
 int n2=fork();
 if(n2==0)
  {
    printf("[son] pid %d from [parent] pid %d \n",getpid(),getppid());
    sleep(20); 
   int n5=fork();
    if(n5>0)
     {
       int n6=fork();
       if(n6==0)
        {
          printf("[son] pid %d from [parent] pid %d \n",getpid(),getppid());
          sleep(20);
        }
        sleep(20);

     }
    else if(n5==0)
     {
       printf("[son] pid %d form [parent] pid %d \n",getpid(),getppid());
       sleep(20);
     }
     sleep(20);
  }
}
else if(n1==0)
{
  printf("[son] pid %d form [parent] pid %d \n",getpid(),getppid());
  sleep(20); 
 int n3=fork();
  if(n3>0)
   {
     int n4=fork();
     if(n4==0)
      {
        printf("[son] pid %d from [parent] pid %d \n",getpid(),getppid());
        sleep(20);
      }
      sleep(20);
   }
  else if(n3==0)
    {
       printf("[son] pid %d from [parent] pid %d \n",getpid(),getppid());
       sleep(20);
    }
     sleep(20);

}

return 0;
}
