#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

#include "process.h"

#define NTIMES 100

static void Interrupt (int signum)
{
    if (signum == SIGINT) {
        printf("\nStay calm, I haven't reached %u yet!\n", NTIMES);
    }
    else if (signum == SIGTERM) {
        printf("\nStay calm, I haven't reached %u yet don't kill me pls'!\n", NTIMES);
    }
    else { 
        printf ("A signal different from SIGINT was received\n");
        exit (EXIT_FAILURE);
    }
}

int main(void)
{
    /* Installing the handling routine */
    struct sigaction sigact;
    sigact.sa_handler = Interrupt;
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = 0;
    psigaction (SIGTERM, &sigact, NULL);

    /* counting */
    printf("PID = %u\n", getpid());
    for (uint32_t i = 0; i < NTIMES; i++)
    { 
        printf ("\r%08u ", i);
        fflush (stdout);
        usleep(500000);
    }
    printf ("\n");

    return EXIT_SUCCESS;
}

