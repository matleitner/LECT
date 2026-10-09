/*
 * An implementation of the bounded-buffer problem
 *
 * NC producers and NC consumers communicate through a fifo.
 * The fifo has a fixed capacity.
 * NI items will be produced by the producers and consume by the consumers.
 * An item is composed of 2 equal integers, ranging from 1 to NI.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <math.h>
#include <libgen.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>

#include "fifo.h"
#include "hdp.h"
#include "dbc.h"
#include "utils.h"

// Custom includes
#include <signal.h>
static void printUsage(FILE* fp, const char* cmd)
{
    fprintf(fp, "Synopsis %s [options]\n"
            "\t----------+-------------------------------------------------------\n"
            "\t  Option  |          Description                                  \n"
            "\t----------+-------------------------------------------------------\n"
            "\t -i num   | number of items per producer [dfl: 500]               \n"
            "\t -p num   | number of producers [dfl: 5]                          \n" "\t -c num   | number of consumers [dfl: 5]                          \n"
            "\t -V       | verbose mode (only show wrong messages) [dfl: verbose] \n"
            "\t -h       | this help                                             \n"
            "\t----------+-------------------------------------------------------\n", cmd);
}

//////////////////////////////////////////////////////////////////////

/*
 * Each producer will produce values from 1 to ni and will insert them into the fifo.
 * Note that the same value is placed into fields v1 and v2 of a fifo item.
 */
void producer(uint32_t id, Fifo *f, uint32_t ni)
{
    for (uint32_t i = 1; i <= ni; i++)
    {
        /* insert item into fifo and show it */
        uint32_t v = id * 1000000 + i; // the value inserted includes the id 
        Item item = {id, v, v};
        fifoInsert(f, item);
    }
}

//////////////////////////////////////////////////////////////////////

/*
 * As the number of consumers can be different from the number of producers,
 * no way to know how many items will be retrieved by each consumer.
 * So, each consumer works in an infinite loop, retrieving items and printing them.
 * If the item retrieved is anomalous, it is printed 
 */
void consumer(uint32_t id, Fifo *f, bool verbose)
{
    while (true)
    {
        //usleep(0);
        /* retrieve item from fifo */
        Item item = fifoRetrieve(f);

        if (item.id == 9999)
        {
            if (verbose)
                printf("[Consumidor %u] Recebido aviso de fim. A terminar...\n", id);
            break; // Sai do while(true) e faz exit(EXIT_SUCCESS) lá em baixo
        }
        /* print it */
        uint32_t id1 = item.v1 / 1000000;
        uint32_t id2 = item.v2 / 1000000;
        if (item.id == 0 or item.v1 == 0 or id1 != item.id or id2 != item.id or item.v1 != item.v2)
            printf("\e[31;01mConsumer %u retrieved (%u,%u,%u) from the fifo\e[0m\n", id, item.id, item.v1, item.v2);
        else if (verbose)
            printf("\e[32;01mConsumer %u retrieved (%u,%u,%u) from the fifo\e[0m\n", id, item.id, item.v1, item.v2);
    }
}

//////////////////////////////////////////////////////////////////////
Fifo *theFifo;
int shmid;
static void Interrupt (int signum)
{
    if (signum == SIGINT) {

      fifoDestroy(theFifo);
      MO(shmdt(theFifo));
      MO(shmctl(shmid, IPC_RMID, NULL));
      printf("Acabou no interrupt\n");
      exit(EXIT_SUCCESS);
    }
}


int main (int argc, char *argv[])
{
    // Codigo exxtra 
    struct sigaction sigact;
    sigact.sa_handler = Interrupt;
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = 0;
    sigaction (SIGINT, &sigact, NULL);

    /* */
    uint32_t ni = 500;      /* number of items */
    uint32_t np = 5;        /* number of producers */
    uint32_t nc = 5;        /* number of consumers */
    bool verbose = false;   /* consumer print mode */

    /* command line arguments */
    const char *optstr = "i:p:c:d:Vh";

    int option;
    do
    {
        switch ((option = getopt(argc, argv, optstr)))
        {
            case 'i': // number of items produced per producer
                ni = atoi(optarg);
                break;

            case 'p': // number of producers
                np = atoi(optarg);
                break;

            case 'c': // number of consumers
                nc = atoi(optarg);
                break;

            case 'h':
                printUsage(stdout, basename(argv[0]));
                return 0;
                break;

            case 'V': // consumer verbose mode
                verbose = true;
                break;

            case -1:
                break;

            default:
                fprintf(stderr, "Not valid option\n");
                printUsage(stderr, basename(argv[0]));
                return EXIT_FAILURE;
        }
    } while (option >= 0);

    printf("Parameters: %d producers, %d consumers, %d items\n", np, nc, ni);

    /* create the shared memory and init it as a fifo  */
    shmid = MO(shmget(IPC_PRIVATE, sizeof(Fifo), IPC_CREAT | 0600));
    theFifo = (Fifo *)MOP(shmat(shmid, NULL, 0));
    fifoInit(theFifo);

    /* launch child processes to play as consumers */
    pid_t cpid[nc];
    for (uint32_t i = 0; i < nc; i++)
    {
        if ((cpid[i] = MO(fork())) == 0)
        {
            signal(SIGINT, SIG_DFL);
            consumer(i+1, theFifo, verbose);
            exit(EXIT_SUCCESS);
        }
    }

    /* launch child processes to play as producers */
    pid_t ppid[np];
    for (uint32_t i = 0; i < np; i++)
    {
        if ((ppid[i] = MO(fork())) == 0)
        {
            signal(SIGINT, SIG_DFL);
            producer(i+1, theFifo, ni);
            exit(EXIT_SUCCESS);
        }
    }

    /* wait for producers fo finish */
    for (uint32_t i = 0; i < np; i++)
    {
        MO(waitpid(ppid[i], NULL, 0));
        printf("Producer %u finished\n", i+1);
    }

//    for (uint32_t i = 0; i < nc; i++)
//    {
//        MO(kill(cpid[i], SIGKILL));
//        printf("Consumer %u finished\n", i+1);
//    }
    for (uint32_t i = 0; i < nc; i++)
    {
        Item dummyItem = {9999, 0, 0}; // id 9999 identifica o fim
        fifoInsert(theFifo, dummyItem);
    }
    /* wait for consumers fo finish */
    for (uint32_t i = 0; i < nc; i++)
    {
        MO(waitpid(cpid[i], NULL, 0));
        printf("Consumer %u finished\n", i+1);
    }

    /* remove resources */
    fifoDestroy(theFifo);
    MO(shmdt(theFifo));
    MO(shmctl(shmid, IPC_RMID, NULL));
    printf("Tudo destruido\n");

    return 0;
}

