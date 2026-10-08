/* pipe1.cpp
 *
 * Use of the system call 'pipe'.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

#include "process.h"

#define BUF_LEN 70

int main(void)
{
    /* create a buffer and fill it with a default pattern */
    char buf[BUF_LEN];
    memset(buf, '-', BUF_LEN - 1);
    buf[BUF_LEN - 1] = '\0';

    /* create a pipe */
    int fd[2];
    ppipe(fd);

    /* write to the pipe */
    const char *msg = "bla bla ...";
    int sz = strlen(msg);
    if (write(fd[1], msg, sz) != sz)
    {
        perror("Fail writing to the pipe: ");
        abort();
    }

    /* reading from the pipe */
    if (read(fd[0], buf, sizeof (buf)) <= 0)
    {
        perror("Fail reading from the pipe: ");
        abort();
    }

    printf("Contents of buffer: %s\n", buf);
    return 0;
}
