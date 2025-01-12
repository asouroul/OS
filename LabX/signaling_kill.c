#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void sig_handler(int sig) {
 printf("Child received signal SIGUSR1 (signal %d)\n", sig);
 printf("Terminating...\n");
 exit(0);
}


 int main () {
 pid_t pid;

 pid = fork();

 if(pid<0){
    perror("fork");
    exit(EXIT_FAILURE);
  }
 else if(pid == 0) {
  //In child process
  if(signal(SIGUSR1, sig_handler) == SIG_ERR){
    perror("signal");
    exit(EXIT_FAILURE);
  }
 printf("Child waits for signal...\n");
 while(1){
   pause();
 }
}
 else {

 sleep(2);

printf("Parent %d sending SIGUSR1 signal to Child %d\n", getpid(), pid);

if(kill(pid,SIGUSR1) == -1) {
  perror("kill");
  exit(EXIT_FAILURE);
}

sleep(1);
  }

return 0;

}


