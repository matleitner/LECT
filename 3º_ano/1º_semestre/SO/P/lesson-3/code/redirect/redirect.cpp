/* 
 * redirect.cpp
 * 
 * Using system call 'dup2'
 *
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd;
    mode_t fd_mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

    printf("Writing to \"stdout\" (first message)\n");

    /* open 'my.file' file */
    if ((fd = open("my.file", O_WRONLY | O_CREAT, fd_mode)) == -1)
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
    printf("Writing to \"stdout\" (second message)\n");
    return 0;
}
