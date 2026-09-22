#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "delays.h"
#include "process.h"

int main(void) {
  printf("Before the fork: PID = %d, PPID = %d\n", getpid(), getppid());

  pid_t ret =
      pfork(); // equivalent to fork(), dealing internally with error situations
  if (ret == 0) {
    pexecl("./child", "./child", NULL);
    printf("why doesn't this message show up?\n");
    return EXIT_FAILURE;
  } else {
    // pwait(NULL); // equivalent to wait(.), dealing internally with error
    // situations
    printf("I'm the parent: PID = %d, PPID = %d\n", getpid(), getppid());
    usleep(1000);
  }

  return EXIT_SUCCESS;
}
