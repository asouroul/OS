#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main () {

 int pipefd[2];
 pid_t pid;
 char msg[] = "Hello from parent process";
 char buffer[100];

 if (pipe(pipefd) == -1){
 perror("pipe error");
 return 1;
 }

 pid = fork();

 if (pid<0){
 perror("fork failed");
 return 1;
 }

 if (pid == 0){
 close(pipefd[1]);
 read(pipefd[0], buffer, sizeof(buffer));
 printf("Child process received: %s\n", buffer);
 close(pipefd[0]);
 }
 else{
 close(pipefd[0]);
 write(pipefd[1], msg, strlen(msg) + 1);
 printf("Message sent from Parent process: %s\n", msg);
 close(pipefd[1]);
 wait(NULL);
}

return 0;
}

