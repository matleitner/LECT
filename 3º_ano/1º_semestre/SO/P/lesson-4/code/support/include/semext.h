/**
 * \defgroup semext semext
 * \ingroup C-Cpp-library
 * \brief System-V Semaphore module.
 *
 * \details
 * This module adds (very frequent!) useful operations to System-V library semaphores.
 *
 * <p><b>group of semext</b>
 *
 * \author Miguel Oliveira e Silva
 * \date 2026
 * \version 1.0
 *  @{ 
 **/

/*!
 * \file
 * \brief System-V Semaphore module.
 */

#ifndef SEM_H
#define SEM_H

#include <sys/sem.h>
#include "hdp.h"
#include "dbc.h"

/**
 * \hideinitializer
 * Increment a semaphore (uses semop()).
 *
 * \param [in] semid [<code>int</code>] System-V semaphore id
 * \param [in] index [<code>int</code>] semaphore index in array
 */
#define semup(semid, index) \
   ({\
      struct sembuf op = {index, 1, 0}; \
      MO(semop(semid, &op, 1)); \
   })

/**
 * \hideinitializer
 * Decrement a semaphore (uses semop()).
 *
 * \param [in] semid [<code>int</code>] System-V semaphore id
 * \param [in] index [<code>int</code>] semaphore index in array
 */
#define semdown(semid, index) \
   ({\
      struct sembuf op = {index, -1, 0}; \
      MO(semop(semid, &op, 1)); \
   })

/**
 * \hideinitializer
 * Decrements atomically two (different) semaphores in a semaphore array (uses semop()).
 *
 * \param [in] semid [<code>int</code>] System-V semaphore id
 * \param [in] index1 [<code>int</code>] semaphore index in array
 * \param [in] index2 [<code>int</code>] semaphore index in array
 *
 *  <DL><DT><B>Precondition:</B></DT>
 *     <DD><code>index1 != index2</code></DD>
 *  </DL>
 *
 */
#define semdown2(semid, index1, index2) \
   ({\
      require (index1 != index2, "both semaphore indexes are equal!"); \
      struct sembuf ops[2] = {{(unsigned short)index1, -1, 0}, {(unsigned short)index2, -1, 0}}; \
      MO(semop(semid, ops, 2)); \
   })

/**
 * \hideinitializer
 * Atomically, increment and decrement two (different) semaphores in a System V semaphore array (uses semop()).
 *
 * \param [in] semid [<code>int</code>] System-V semaphore id
 * \param [in] up_index [<code>int</code>] semaphore index in array
 * \param [in] down_index [<code>int</code>] semaphore index in array
 *
 *  <DL><DT><B>Precondition:</B></DT>
 *     <DD><code>up_index != down_index</code></DD>
 *  </DL>
 *
 */
#define semupdown(semid, up_index, down_index) \
   ({\
      require (up_index != down_index, "both semaphore indexes are equal!"); \
      struct sembuf ops[2] = {{(unsigned short)up_index, 1, 0}, {(unsigned short)down_index, -1, 0}}; \
      MO(semop(semid, ops, 2)); \
   })

/**
 * \hideinitializer
 * Sets the value of the semaphore (uses semctl()).
 *
 * \param [in] semid [<code>int</code>] System-V semaphore id
 * \param [in] index [<code>int</code>] semaphore index in array
 * \param [in] value [<code>int</code>] desired semaphore value
 */
#define semsetval(semid, index, value) \
   ({\
      union semun { \
         int val; \
         struct semid_ds *buf; \
         unsigned short *array; \
      } semopts; \
      semopts.val = value; \
      MO(semctl(semid, index, SETVAL, semopts)); \
   })

#endif

/* ************************************************** */
/**
 * @} close group semext
 **/
/* ************************************************** */

