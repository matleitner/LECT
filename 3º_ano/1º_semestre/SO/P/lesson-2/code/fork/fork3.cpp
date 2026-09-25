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
    bwRandomDelay(100, 100000);
    printf("After the fork, in the child: PID = %d, PPID = %d\n", getpid(), getppid());
  }
  else
  {
    bwRandomDelay(100, 100000);
    printf("After the fork at the same time as child, in the parent: PID = %d, PPID = %d\n", getpid(), getppid());
    // wait serve para esperar que o processo filho acabe para o pai continuar
    // ao rodar várias vezes o programa o processo pai e filho executam "ao mesmo tempo" mas como o delay é random
    // às vezes é o pai primeiro outras o filho
    //
    pwait(NULL); // equivalent to wait(.), dealing internally with error situations
    printf("After child process\n");
  }

  return EXIT_SUCCESS;
}

