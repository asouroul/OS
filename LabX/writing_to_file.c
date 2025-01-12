#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/file.h>

int main () {

 pid_t pid;


 pid = fork();

 if(pid<0){
  perror("fork");
  exit(EXIT_FAILURE);
   }


if(pid == 0) {

 FILE *fp = fopen("PID_output.txt", "a");
 if (fp == NULL) {
  perror("Error opening file");
  return EXIT_FAILURE;
 }

 if(flock(fileno(fp), LOCK_EX) < 0) {
    perror("Error locking file");
    fclose(fp);
    return EXIT_FAILURE;
}


fprintf(fp, "Child process PID: %d\n", getpid());
fflush(fp);

flock(fileno(fp), LOCK_UN);

if(fclose(fp) != 0) {
 perror("Error closing file");
 return EXIT_FAILURE;
 }


}
else if (pid>0) {

FILE *fp = fopen("PID_output.txt", "a");
 if (fp == NULL) {
  perror("Error opening file");
  return EXIT_FAILURE;
     }

if(flock(fileno(fp), LOCK_EX) < 0) {
    perror("Error locking file");
    fclose(fp);
    return EXIT_FAILURE;
}


fprintf(fp, "Parent process PID: %d\n", getpid());
fflush(fp);

flock(fileno(fp), LOCK_UN);

if (fclose(fp) != 0) {
   perror("Error closing file");
   return EXIT_FAILURE;
 }

}

return 0;

}


