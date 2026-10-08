#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "process.h"

#define BUF_LEN 200

int main(void) {
  char buf[BUF_LEN];
  int n, fd_read, fd_write;
  mkfifo("fifo_to_sender", 0666);
  mkfifo("fifo_to_receiver", 0666);

  fd_write = open("fifo_to_receiver", O_WRONLY);
  fd_read = open("fifo_to_sender", O_RDONLY);

  if (fd_read == -1 || fd_write == -1) {
    perror("Erro ao abrir os FIFOs");
    return 1;
  }
  if (pfork() == 0) {
    while ((n = read(fd_read, buf, BUF_LEN)) != 0) {
      printf("\nSender: %s", buf);
      fflush(stdout);
    }
  }
  else {
     while (fgets(buf, BUF_LEN, stdin) != NULL)
    {
        write(fd_write, buf, strlen(buf) + 1);
    }
   
  }
  return 0;
}


