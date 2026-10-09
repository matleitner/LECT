/*
 *  \brief SoS: Statistics on Strings, a simple client-server application
 *    that computes some statistics on strings
 *
 * \author (2022-2026) Artur Pereira <artur at ua.pt>
 * \author (2022-2026) Miguel Oliveira e Silva <mos at ua.pt>
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <stdint.h>
#include <ctype.h>

#include <new>

#include "sos.h"
#include "utils.h"
#include "dbc.h"
#include "hdp.h"

/** \brief Number of transaction buffers */
#define  NBUFFERS         5

/** \brief indexes for the fifos of free buffers and of pending requests */
enum { 
    FREE_BUFFER = 0, 
    PENDING_REQUEST = 1 
};

/* -------------------------------------------------------------------- */

/** \brief interaction buffer data type */
struct BUFFER 
{
    char req[MAX_STRING_LEN+1];
    Response resp;
};

/* -------------------------------------------------------------------- */

/** \brief the fifo data type to store indexes of buffers */
struct Fifo
{
    uint32_t ii;               ///< point of insertion
    uint32_t ri;               ///< point of retrieval
    uint32_t cnt;              ///< number of items stored
    uint32_t tokens[NBUFFERS]; ///< storage memory
};

/* -------------------------------------------------------------------- */

/** \brief The fifo manipulation functions */

/* Insert a token into a fifo */
static void fifoIn(uint32_t semIndex, uint32_t token)
{
#if __DEBUG__
    fprintf(stderr, "%s(semIndex: %u, token: %u)\n", __func__, semIndex, token);
#endif

    /* check preconditions */
    require(semIndex == FREE_BUFFER or semIndex == PENDING_REQUEST, "semIndex is not valid");
    require(token < NBUFFERS, "Token is not valid");

    /* replace this comment with your code */
}

/* -------------------------------------------------------------------- */

/* Retrieve a token from a fifo  */
static uint32_t fifoOut(uint32_t semIndex)
{
#if __DEBUG__
    fprintf(stderr, "%s(semIndex: %u)\n", __func__, semIndex);
#endif

    /* check preconditions */
    require(semIndex == FREE_BUFFER or semIndex == PENDING_REQUEST, "semIndex is not valid");

    /* replace this comment and the following line with your code */
    return 0xFFFFFFFF;
}

/* -------------------------------------------------------------------- */
/* -------------------------------------------------------------------- */

/** \brief the data type representing all the shared area.
 *    Fifo 0 is used to manage tokens of free buffers.
 *    Fifo 1 is used to manage tokens of pending requests.
 */
struct SharedArea
{
    /* A fix number of transaction buffers */
    BUFFER pool[NBUFFERS];

    /* A fifo for tokens of free buffers and another for tokens with pending requests */
    Fifo fifo[2];

    /* array of 2 semaphores to allow mutual exclusion in the access to the fifos */
    int fifoAccess;

    /* array of 2 semaphores to block process until the corresponding fifo is not empty
     *    Control of fullness is not necessary because the capacity of the fifos is equal
     *    to the number of buffers, so insertion in a full fifo will never occur.
     */
    int fifoNotEmpty;

    /* array of N BUFFERS semaphores to block clients 
     *    while waiting for the response to their requests.
     */
    int respAvailable;
};

/** \brief pointer to shared area dynamically allocated */
int sharedAreaId = -1;
SharedArea *sharedArea = NULL;


/* -------------------------------------------------------------------- */

/* Allocate and init the internal supporting data structure,
 *   including all necessary synchronization resources
 */
void init(void)
{
#if __DEBUG__
    fprintf(stderr, "%s()\n", __func__);
#endif

    require(sharedArea == NULL, "Shared area must not yet exist");

    /* replace this comment with your code */
    UNUSED(fifoOut);
    UNUSED(fifoIn);
}

/* -------------------------------------------------------------------- */

/* Free all allocated synchronization resources and data structures */
void destroy()
{
    require(sharedArea != NULL, "Shared area must be allocated");

    /* replace this comment with your code */
}

/* -------------------------------------------------------------------- */
/* -------------------------------------------------------------------- */

uint32_t getFreeBuffer()
{
#if __DEBUG__
    fprintf(stderr, "%s()\n", __func__);
#endif

    /* replace this comment and the following line with your code */
    return 0xFFFFFFFF;
}

/* -------------------------------------------------------------------- */

void putRequestData(uint32_t token, const char *data)
{
#if __DEBUG__
    fprintf(stderr, "%s(token: %u, ...)\n", __func__, token);
#endif

    require(token < NBUFFERS, "Token is not valid");
    require(data != NULL, "Data pointer can not be NULL");

    char *req = sharedArea->pool[token].req;
    strncpy(req, data, MAX_STRING_LEN);
    req[MAX_STRING_LEN] = '\0';
}

/* -------------------------------------------------------------------- */

void submitRequest(uint32_t token)
{
#if __DEBUG__
    fprintf(stderr, "%s(token: %u)\n", __func__, token);
#endif

    require(token < NBUFFERS, "Token is not valid");

    /* replace this comment with your code */
}

/* -------------------------------------------------------------------- */

void waitForResponse(uint32_t token)
{
#if __DEBUG__
    fprintf(stderr, "%s(token: %u)\n", __func__, token);
#endif

    require(token < NBUFFERS, "Token is not valid");

    /* replace this comment with your code */
}

/* -------------------------------------------------------------------- */

void getResponseData(uint32_t token, Response *resp)
{
#if __DEBUG__
    fprintf(stderr, "%s(token: %u, ...)\n", __func__, token);
#endif

    require(token < NBUFFERS, "token is not valid");
    require(resp != NULL, "Resp pointer can not be NULL");

    *resp = sharedArea->pool[token].resp;
}

/* -------------------------------------------------------------------- */

void releaseBuffer(uint32_t token)
{
#if __DEBUG__
    fprintf(stderr, "%s(token: %u)\n", __func__, token);
#endif

    require(token < NBUFFERS, "Token is not valid");

    /* replace this comment with your code */
}

/* -------------------------------------------------------------------- */
/* -------------------------------------------------------------------- */

uint32_t getPendingRequest()
{
#if __DEBUG__
    fprintf(stderr, "%s()\n", __func__);
#endif

    /* replace this comment and the following line with your code */
    return 0xFFFFFFFF;}

/* -------------------------------------------------------------------- */

void getRequestData(uint32_t token, char *data)
{
#if __DEBUG__
    fprintf(stderr, "%s(token: %u, ...)\n", __func__, token);
#endif

    require(token < NBUFFERS, "Token is not valid");
    require(data != NULL, "Data pointer can not be NULL");

    char *req = sharedArea->pool[token].req;
    strncpy(data, req, MAX_STRING_LEN);
    data[MAX_STRING_LEN] = '\0';
}

/* -------------------------------------------------------------------- */

Response produceResponse(char *req)
{
#if __DEBUG__
    fprintf(stderr, "%s(req: %s)\n", __func__, req);
#endif

    Response resp = {0,0,0};
    for (uint32_t i = 0; req[i] != '\0'; i++)
    {
        resp.noChars++;
        if (isdigit(req[i])) resp.noDigits++;
        if (isalpha(req[i])) resp.noLetters++;
    }
    return resp;
}

/* -------------------------------------------------------------------- */

void putResponseData(uint32_t token, Response *resp)
{
#if __DEBUG__
    fprintf(stderr, "%s(token: %u, ...)\n", __func__, token);
#endif

    require(token < NBUFFERS, "token is not valid");
    require(resp != NULL, "Resp pointer can not be NULL");

    sharedArea->pool[token].resp = *resp;
}

/* -------------------------------------------------------------------- */

void notifyClient(uint32_t token)
{
#if __DEBUG__
    fprintf(stderr, "%s(token: %u)\n", __func__, token);
#endif

    require(token < NBUFFERS, "Token is not valid");

    /* replace this comment with your code */
}

/* -------------------------------------------------------------------- */


/* -------------------------------------------------------------------- */
