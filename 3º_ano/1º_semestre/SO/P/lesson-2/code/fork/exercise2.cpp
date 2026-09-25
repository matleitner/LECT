#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "delays.h"
#include "process.h"

int main(void)
{
  printf("Before the fork: PID = %d, PPID = %d\n", getpid(), getppid());

  pid_t ret = pfork(); // equivalent to fork(), dealing internally with error situations
  if (ret == 0)
  {
    execlp("ls", "ls", "-l", NULL);
    printf("After the fork, in the child: PID = %d, PPID = %d\n", getpid(), getppid());
  }
  else
  {
    for(int i = 0; i<40; i++) printf("=");
    printf("\n");
    pwait(NULL);
    for(int i = 0; i<40; i++) printf("=");
      printf("\n");
    //pwait(NULL); // equivalent to wait(.), dealing internally with error situations
  }


  return EXIT_SUCCESS;
}


