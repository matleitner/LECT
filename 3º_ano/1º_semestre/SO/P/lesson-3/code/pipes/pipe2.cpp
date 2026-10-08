/* pipe2.c
 *
 * Use of the system call 'pipe'
 *   to establish a communication channel
 *   between two processes, parent and child.
 *
 * This program produces the same result as
 * the command
 * "ls -l | sort -n -k 5,6"
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <stdlib.h>
#include <fcntl.h>

#include "process.h"

int main(void)
{
    /* create a pipe */
    int fd[2];
    ppipe(fd);

    /* forking current process */
    if (pfork() == 0) /* this branch is only executed by the child process */
    {
        /* redirect stdout to pipe */
        if (dup2(fd[1], STDOUT_FILENO) == -1)
        {
            perror("Fail redirecting stdout: ");
            abort();
        }

        /* close unnecessary file descriptors; it must be done. */
        close(fd[0]);
        close(fd[1]);

        /* replace process program */
        pexecl("/bin/ls", "ls", "-l", NULL);
    }
    else /* this branch is only executed by the parent process */
    {
        /* redirect stdin to pipe */
        if (dup2(fd[0], STDIN_FILENO) == -1)
        {
            perror("Fail redirecting stdin: ");
            abort();
        }

        /* close unnecessary file descriptors; it must be done. */
        close(fd[0]);
        close(fd[1]);

        /* replace process program */
        pexecl("/bin/sort", "sort", "-n", "-k", "5", NULL);
    }

    /* never get here, parent or child */
    return 0;
}
