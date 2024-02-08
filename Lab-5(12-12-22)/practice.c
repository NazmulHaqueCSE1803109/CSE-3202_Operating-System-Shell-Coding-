#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include<time.h>

int ran2()
{
   time_t t;
   srand((unsigned)time(&t));
   return (rand()%6)+1;
}



int c1 = 0,s1=0,c=0;
int c2 = 0,s2=0;
void *producer()
{
   
    int a[6];
    if(c1<=6)
    {
     int x=ran2();
      a[c1]=x;
      c1++;
    }
    for(int i=0;i<6;i++)
    {
      s1 +=a[i];
    }
 
    
}

void *consumer()
{
    int b[6];
    
    if(c2<=6)
    {
      int x=random();
      b[c2]=x;
      c2++;
    }
    for(int i=0;i<6;i++)
    {
      s2 +=b[i];
    }
  
    
}

int main()
{
    pthread_t t1, t2;
    
   
    while(s1==s2)
    {
       pthread_create(&t1, NULL, &producer, NULL);
       pthread_create(&t2, NULL, &consumer, NULL);
       pthread_join(t1, NULL);
       pthread_join(t2, NULL);
       if(c>0)
       {
         printf("Tie.\n");
       }
       c++;
    }
    
      if(s1>s2)
      {
         printf("producer win.\n");
      }
      else
      {
         printf("Consumer win.\n");
      }
    
    return 0;
}
