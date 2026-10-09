/**
 * @file
 *
 * \brief A client-server concurrent application, implemented using processes.
 *
 * \author (2016-2024) Artur Pereira <artur at ua.pt>
 * \author (2022-2024) Miguel Oliveira e Silva <mos at ua.pt>
 */

#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>
#include <math.h>
#include <stdint.h>
#include <ctype.h>

#include  "sos.h"
#include  "utils.h"
#include  "dbc.h"
#include  "hdp.h"

#define USAGE "Synopsis: %s [options]\n"\
	"\t----------+-------------------------------------- ---------------\n"\
	"\t  Option  |          Description                                 \n"\
	"\t----------+------------------------------------------------ -----\n"\
	"\t -n num   | number of iterations per client (dfl: 10; max: 100)  \n"\
	"\t -s num   | number of servers (dfl: 1; max 10)                   \n"\
	"\t -c num   | number of clients (dfl: 4; max 50)                   \n"\
	"\t -h       | this help                                            \n"\
	"\t----------+----------------------------------------------- ------\n"

/* ******************************************************* */
/* The server life cycle */

void server(uint32_t id)
{
#ifdef __DEBUG__
fprintf(stderr, "%s(id: %u)\n", __FUNCTION__, id);
#endif

    printf("Server #%u: ready for service\n", id);

    char req[MAX_STRING_LEN+1];
    req[MAX_STRING_LEN] = '\0';
    Response resp;
    while (true)
    {
        uint32_t token = getPendingRequest();
        getRequestData(token, req);
        resp = produceResponse(req);
        putResponseData(token, &resp);
        notifyClient(token);
    }
}

/* ******************************************************* */
/* string generator (auxiliary function for the client) */

const char *generateString(uint32_t id)
{
    static bool firstTime = true;
    if (firstTime)
    {
        srand(getpid());
        firstTime = false;
    }
    char str[MAX_STRING_LEN+1];
    sprintf(str, "%02u", id);
    str[2] = ' ';
    str[3] = '-';
    str[4] = ' ';
    uint32_t n1 = random_int(7, 9);
    uint32_t n2 = random_int(n1+10, MAX_STRING_LEN/2);
    uint32_t n3 = random_int(n2+3, MAX_STRING_LEN-5);
    for (uint32_t i = 5; i < n1; i++) str[i] = random_int('0', '9');
    str[n1] = ' ';
    for (uint32_t i = n1+1; i < n2; i++) str[i] = random_int('a', 'z');
    str[n2] = ' ';
    for (uint32_t i = n2+1; i < n3; i++) str[i] = random_int('A', 'Z');
    uint32_t n4 = random_int(1,3);
    for (uint32_t i = 0; i < n4; i++) str[n3+i] = '!';
    str[n3+n4] = '\0';
    return strdup(str);
}

/* ******************************************************* */
/* The client life cycle */

void client(uint32_t id, uint32_t niter)
{
#ifdef __DEBUG__
fprintf(stderr, "%s(id: %u, niter: %u, ...)\n", __FUNCTION__, id, niter);
#endif

    Response resp;
    for (uint32_t i = 0; i < niter; i++)
    {
        /* generate a string */
        const char *req = generateString(id);

        /* call the service */
        uint32_t token = getFreeBuffer();
        putRequestData(token, req);
        submitRequest(token);
        waitForResponse(token);
        getResponseData(token, &resp);
        releaseBuffer(token);

        /* print string and response */
        printf("\e[32;01m| %-50s | %02u,%02u,%02u | %02u |\e[0m\n", 
                req, resp.noChars, resp.noDigits, resp.noLetters, id);
    }
}

/* ******************************************************* */

/*   main thread: it starts the simulation and launches the server and client threads */
int main(int argc, char *argv[])
{
    uint32_t niter = 10;     ///< number of iterations
    uint32_t nservers = 1;   ///< number of servers
    uint32_t nclients = 4;   ///< number of clients

    /* command line processing */
    int option;
    while ((option = getopt(argc, argv, "n:s:c:h")) != -1)
    {
        switch (option)
        {
            case 'n':
                niter = atoi(optarg);
                if (niter > 100)
                {
                    fprintf(stderr, "Too many iterations!\n");
                    fprintf(stderr, USAGE, basename(argv[0]));
                    return EXIT_FAILURE;
                }
                break;
            case 's':
                nservers = atoi(optarg);
                if (nservers > 10)
                {
                    fprintf(stderr, "Too many servers!\n");
                    fprintf(stderr, USAGE, basename(argv[0]));
                    return EXIT_FAILURE;
                }
                break;
            case 'c':
                nclients = atoi(optarg);
                if (nclients > 50)
                {
                    fprintf(stderr, "Too many clients!\n");
                    fprintf(stderr, USAGE, basename(argv[0]));
                    return EXIT_FAILURE;
                }
                break;
            case 'h':
                printf(USAGE, basename(argv[0]));
                return EXIT_SUCCESS;
            default:
                fprintf(stderr, "Non valid option!\n");
                fprintf(stderr, USAGE, basename(argv[0]));
                return EXIT_FAILURE;
        }
    }

    /* init support data structure */
    init();

    /* launching the servers */
    pid_t spid[nservers];   /* servers' processes */
    printf("[main] Launching %u server processes\n", nservers);
    for (uint32_t i = 0; i < nservers; i++)
    {
        /* replace this comment with your code */
        UNUSED(server);
        UNUSED(spid);
    }

    /* launching the clients */
    pid_t cpid[nclients];   /* clients' processes */
    printf("[main] Launching %d client processes, each performing %d transactions\n", nclients, niter);
    for (uint32_t i = 0; i < nclients; i++)
    {
        /* replace this comment with your code */
        UNUSED(client);
        UNUSED(cpid);
    }

    /* waiting for clients to conclude */
    for (uint32_t i = 0; i < nclients; i++)
    {
        /* replace this comment with your code */
    }

    /* forcing/asking servers to conclude */
    for (uint32_t i = 0; i < nservers; i++)
    {
        /* replace this comment with your code */
    }

    /* waiting servers to conclude */
    for (uint32_t i = 0; i < nservers; i++)
    {
        /* replace this comment with your code */
    }

    /* releasing resources and quitting */
    destroy();
    return EXIT_SUCCESS;
}

