#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <libgen.h>
#include <stdlib.h>
#include <string.h>

#include "fifo.h"

void fifoInit(Fifo *f)
{
    /* init fifo */
    f->in = f->out = 0;
    f->count = 0;
    memset(f->data, 0x0, N*sizeof(Item));
    
    /* init conditions variables */
    NZ(pthread_cond_init(&f->notFull, NULL));
    NZ(pthread_cond_init(&f->notEmpty, NULL));

    /* init access mutex */
    NZ(pthread_mutex_init(&f->access, NULL));
}

static bool fifoIsFull(Fifo *f)
{
    return f->count == N;
}

static bool fifoIsEmpty(Fifo *f)
{
    return f->count == 0;
}

void fifoInsert(Fifo *f, Item item)
{
    /* lock access on entry */
    NZ(pthread_mutex_lock(&f->access));

    /* wait until fifo is not full */
    while (fifoIsFull(f))
    {
        NZ(pthread_cond_wait(&f->notFull, &f->access));
    }

    /* make insertion */
    f->data[f->in] = item;
    f->in = (f->in + 1) % N;
    f->count++;

    /* signal fifo is not empty */
    NZ(pthread_cond_broadcast(&f->notEmpty));

    /* unlock access before quitting */
    NZ(pthread_mutex_unlock(&f->access));
}

Item fifoRetrieve(Fifo *f)
{
    /* lock access on entry */
    NZ(pthread_mutex_lock(&f->access));

    /* wait until fifo is not empty */
    while (fifoIsEmpty(f))
    {
        NZ(pthread_cond_wait(&f->notEmpty, &f->access));
    }

    /* memorize item to be returned */
    Item ret = f->data[f->out];

    /* update fifo */
    f->out = (f->out + 1) % N;
    f->count--;

    /* signal fifo is not empty */
    NZ(pthread_cond_broadcast(&f->notFull));

    /* unlock access before quitting */
    NZ(pthread_mutex_unlock(&f->access));

    /* return item */
    return ret;
}

void fifoDestroy(Fifo *f)
{
    NZ(pthread_cond_destroy(&f->notFull));
    NZ(pthread_cond_destroy(&f->notEmpty));
    NZ(pthread_mutex_destroy(&f->access));
    f->count = 0;
    f->in = f->out = 0;
}
