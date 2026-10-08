#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "delays.h"
#include "process.h"


int main(int argc, char** argv) {
  if(argc < 2) {

    printf("Falta de argumentos.\n");
    return 1;
  }
  printf("Before the fork: PID = %d, PPID = %d\n", getpid(), getppid());
  
  pid_t ret = pfork(); // equivalent to fork(), dealing internally with error situations
  if (ret == 0) {
    int fd;
    mode_t fd_mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
        if ((fd = open(argv[1], O_WRONLY | O_CREAT, fd_mode)) == -1)
    {
        perror("Fail opening file \"my.file\": ");
        return 1;
    }

    /* redirecting stdout to file */
    if (dup2(fd, STDOUT_FILENO) == -1)
    {
        perror("Fail redirecting stdout: ");
        close(fd);
        return 1;
    }

    close(fd);
  
 
    execlp("./child", "./child", NULL);
    printf("why doesn't this message show up?\n");
    return EXIT_FAILURE;
  } else {
    pwait(NULL); // equivalent to wait(.), dealing internally with error
    // situations
    printf("I'm the parent: PID = %d, PPID = %d\n", getpid(), getppid());
    usleep(1000);
  }

  return EXIT_SUCCESS;
}
