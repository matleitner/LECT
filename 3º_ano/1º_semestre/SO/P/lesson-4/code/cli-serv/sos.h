/**
 *  \defgroup SoS SoS
 *  \brief SoS: Statistics on Strings, a simple client-server application
 *    that computes some statistics on strings
 *
 * \author (2022, 2026) Artur Pereira <artur at ua.pt>
 * \author (2022) Miguel Oliveira e Silva <mos at ua.pt>
 *  @{ 
 * 
 */
#pragma once

/* 
 * In the material provided, there are functions and variables not used.
 * Not been used, they generate a warning at compile time.
 * To avoid this warning, the following macro is define.
 * In the final program, all occurrences of it should be removed.
 */
#define UNUSED(expr)    do { (void)(expr); } while (0)

/* -------------------------------------------------------------------- */

#include <stdint.h>

/** \brief max length of strings */
#define  MAX_STRING_LEN         49

/**
 * \brief The response data type
 */
struct Response
{
    uint32_t noChars = 0;   ///< Number of characters
    uint32_t noDigits = 0;  ///< Number of digits
    uint32_t noLetters = 0; ///< Number of letters
};

/** 
 * \brief Allocate and init the internal supporting data structure,
 *   including all necessary synchronization resources
 *
 * \remarks To be called before concurrency is launched
 */
void init(void);

/** 
 * \brief Free all allocated synchronization resources and data structures 
 *
 * \remarks To be called after concurrency has terminated
 */
void destroy(void);

/* -------------------------------------------------------------------- */

/**
 * \brief Get a free buffer
 *
 * \remarks To be used from the client side
 *
 * return A token representing the free buffer assigned for the transaction
 */
uint32_t getFreeBuffer();

/**
 * \brief Put request data
 *
 * \details Data will be copied from the given address, until the string terminator ('\0')
 *   or the buffer capacity is reached
 * 
 * \remarks To be used from the client side
 *
 * \param [in] data Pointer to initial of data
 * \param [in] token The token of the transaction buffer
 */
void putRequestData(uint32_t token, const char *data);

/**
 * \brief Submit a new request
 *
 * \remarks To be used from the client side
 *
 * \param [in] token The token of the buffer containing the request
 */
void submitRequest(uint32_t token);

/**
 * \brief Block client until the response is available
 *
 * \remarks To be used from the client side
 *
 * \param [in] token The token of the transaction buffer
 */
void waitForResponse(uint32_t token);

/**
 * \brief Extract response from the buffer
 *
 * \remarks To be used from the client side
 *
 * \param [in] token The token of the transaction buffer
 * \param [in] resp Pointer to container where the response is to be copied into
 */
void getResponseData(uint32_t token, Response *resp);

/**
 * \brief Make a buffer available for new transactions
 *
 * \details The client no long needs the buffer and releases it for new 
 *
 * \remarks To be used from the client side
 *
 * \param [in] token The token of the buffer used in the transaction
 */
void releaseBuffer(uint32_t token);

/* -------------------------------------------------------------------- */
/* -------------------------------------------------------------------- */

/**
 * \brief Get pending request
 *
 * \details Blocking function that retrieves the token of a buffer (containing a request)
 *    from the queue of pending requests
 *
 * \remarks To be used from the server side
 *
 * \return The token of a buffer containing a request
 */
uint32_t getPendingRequest();

/**
 * \brief Get request data
 *
 * \details Data will be copied from the buffer, until the string terminator ('\0')
 *   or the buffer capacity is reached
 * 
 * \remarks To be used from the server side
 *
 * \param [in] data Pointer to recipient where data is to be copied into
 * \param [in] token The token of the buffer to be accessed
 */
void getRequestData(uint32_t token, char *data);

/**
 * \brief produce response
 */
Response produceResponse(char *req);

/**
 * \brief Put response into the buffer
 *
 * \remarks To be used from the server side
 *
 * \param [in] token The token of the buffer to be accessed
 * \param [in] resp Pointer to container where the response is to be copied from
 */
void putResponseData(uint32_t token, Response *resp);

/**
 * \brief Signal client that the response is available
 *
 * \remarks To be used from the server side
 *
 * \param [in] token The token of the buffer to be accessed
 */
void notifyClient(uint32_t token);


/** @} */
