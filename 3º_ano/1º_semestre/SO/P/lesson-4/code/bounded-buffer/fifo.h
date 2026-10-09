/**
 * \file
 *
 * \defgroup bb bounded-buffer fifo
 *
 * \details 
 *   Definition of the FIFO data type and manipulating functions
 *
 *   The fifo is defined for a maximum capacity of N items
 */
#pragma once

#include <stdint.h>
#include <stdlib.h>

#define N 20 ///< Capacity of the fifo

/** 
 * \brief The item for test purposes
 */
struct Item
{ 
    uint32_t id; ///< id of the producer
    uint32_t v1; ///< a general purpose field
    uint32_t v2; ///< another general purpose field
};

/**
 * \brief The FIFO data structure
 * \ingroup bb
 */
struct Fifo
{
    uint32_t count;     ///< number of items in fifo
    uint32_t in;        ///< index of first empty slot
    uint32_t out;       ///< index of first occupied slot
    Item data[N];       ///< the slots
    int sem;            ///< to be used in the sem-safe version; ignore in the unsafe version
};

/** 
 * \brief Init a fifo
 * \ingroup bb
 * \param f Pointer to the fifo
 */
void fifoInit(Fifo *f);

/** 
 * \brief Check if a fifo is full
 * \ingroup bb
 * \ingroup bb
 * \param f Pointer to the fifo
 */
bool fifoIsFull(Fifo *f);

/** 
 * \brief Check if a fifo is empty
 * \ingroup bb
 * \param f Pointer to the fifo
 */
bool fifoIsEmpty(Fifo *f);

/** 
 * \brief Insert a new item into a fifo
 * \ingroup bb
 * \param f Pointer to the fifo
 * \param item Item to be inserted
 */
void fifoInsert(Fifo *f, Item item);

/** 
 * \brief Retrieve an item from a fifo
 * \ingroup bb
 * \param f Pointer to the fifo
 * \return The item retrieved
 */
Item fifoRetrieve(Fifo *f);

/** 
 * \brief Destroy a fifo
 * \ingroup bb
 * \param f Pointer to the fifo
 */
void fifoDestroy(Fifo *f);

