#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <math.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

// Parrent:
//  Create Integer var in shared memory
// launch a child process 
//  wait(NULL)
// release


// Child 
// Ask user for val between 10 and 20 
// Increment the value in shared mem 


int main(void) {
  int shmid = MO(shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0600));
  int* var = (int *)MOP(shmat(shmid, NULL, 0));
  char buff[20];

  if(fork() == 0) {
    int val = 0;
    do {
        printf("Insira um numero de 10 a 20: ");
        if (fgets(buff, sizeof(buff), stdin) != NULL) {
            val = atoi(buff);
        }
    } while (val < 10 || val > 20);

    // Incrementar no shared memory até 'val'
    while (*var < val) {
        (*var)++;
        printf("Filho: %d\n", *var);
    }
    
    _exit(0); // Terminar o processo filho com sucesso
}
  }

  wait(NULL);
  
  while (*var > 1) {
    printf("Pai: %d\n", *var);
    (*var)--;
  }

  MO(shmdt(var));
  MO(shmctl(shmid, IPC_RMID, NULL));

  return 0;
}
