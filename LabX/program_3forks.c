#include <stdio.h>
#include <unistd.h>


int main () {

printf("Original process PID:%d\n", getpid());
printf("PID of the process that started running our program:%d\n", getppid());

 //First fork
 fork();

 //Second fork
 fork();

 //Third fork
 fork();

 printf("Child process PID:%d, Parent process PID:%d\n", getpid(), getppid());

 sleep(2);

 return 0;

}

