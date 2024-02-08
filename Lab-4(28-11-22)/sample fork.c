#include<iostream>
#include<unistd.h>
#include<sys/types.h>
using namespace std;
int main()
{
  //create child processes
  //so that they create more processes
  //within them
  fork();
  fork();
  fork();
  cout<<"Will Smith"<<endl;

  return 0;
}
