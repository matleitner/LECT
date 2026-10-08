/* receiver.c
 *
 * Use of the a named pipe (fifo) ...
 * ... to receive data
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
    int n, fd;

    if ((fd = open("my.fifo", O_RDONLY)) == -1)
    {
        perror("Fail openning fifo\n");
        return 1;
    }

    printf("Received through fifo:\n");
    while ((n = read(fd, buf, BUF_LEN)) != 0)
    {
        printf("%s", buf);
    }
    return 0;
}
