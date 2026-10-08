#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "process.h"

int main(void) {
  /* create a pipe */
  int fd[2];
  ppipe(fd);

  /* filho 1 */
  if (pfork() == 0) /* this branch is only executed by the child process */
  {

    /* redirect stdout to pipe */

    if (dup2(fd[1], STDOUT_FILENO) == -1) {
      perror("Fail redirecting stdout: ");
      abort();
    }

    /* close unnecessary file descriptors; it must be done. */
    close(fd[0]);
    close(fd[1]);

    /* replace process program */
    pexecl("/bin/ls", "ls", "-l", NULL);
  }
  /* filho 2*/
  if (pfork() == 0) {

    /* redirect stdin to pipe */
    if (dup2(fd[0], STDIN_FILENO) == -1) {
      perror("Fail redirecting stdin: ");
      abort();
    }

    /* close unnecessary file descriptors; it must be done. */
    close(fd[0]);
    close(fd[1]);

    /* replace process program */
    pexecl("/bin/sort", "sort", "-n", "-k", "5", NULL);
  }

  /* close unnecessary file descriptors; it must be done. */
  close(fd[0]);
  close(fd[1]);
  pwait(NULL);
  pwait(NULL);

  /* never get here, parent or child */
  return 0;
}
