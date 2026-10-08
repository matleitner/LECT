/* receiver.c
 *
 * Use of the a named pipe (fifo) ...
 * ... to send data
 *
 */
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUF_LEN 200

int main(void)
{
    char buf[BUF_LEN];
    int fd;

    if ((fd = open("my.fifo", O_WRONLY)) == -1)
    {
        perror("Fail openning fifo\n");
        return 1;
    }

    printf("Write things\n------------\n");
    while (fgets(buf, BUF_LEN, stdin) != NULL)
    {
        write(fd, buf, strlen(buf) + 1);
    }
    return 0;
}
