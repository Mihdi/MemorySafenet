#ifndef MEMORY_SAFENET_UTILS
#define MEMORY_SAFENET_UTILS
/**
 * \file utils.h
 * \brief header for utilitary functions of this module
 * \author Mehdi (Add your name if you modify this file, just so we know who
 * touched it) \version 0.1
 *
 * This file is not to be imported outside this module. It contains functions
 * that are useful for the creation of the exported functions
 *
 */
#include <stdbool.h>

#include "export.h"

// GARBAGE STATE PARAMETERS

#ifndef GARBAGE_HASHSET_SIZE
#    define GARBAGE_HASHSET_SIZE 64
#endif // GARBAGE_HASHSET_SIZE

#ifndef GARBAGE_HASHING_LAMBDA
#    define GARBAGE_HASHING_LAMBDA modulo_hashing
#endif // GARBAGE_HASHING_LAMBDA

// END OF GARBAGE STATE PARAMETERS

/**
 * \fn garbage_state(bool protect, bool reset);
 * \brief used to interact with garbage_state. Please never call this function
 * directly as any misinteraction may cause serious border effects.
 *
 * \param protect if set, garbage_state will ignore given reset value
 * \param reset if set and protect is not set, return inner state and reset
 * inner static to new
 *
 * \return pointer to inner state before reset if any, can be NULL if inner init
 * failed
 */
struct hashset *garbage_state(bool protect, bool reset);

/**
 * \fn modulo_hashing(void *p, size_t sz)
 * \brief Naive hash that returns the modulo of p as size_t by the given size
 *
 * \param p the pointer
 * \param sz the size of the ring
 *
 * \return modulo of p by sz
 */
size_t modulo_hashing(void *p, size_t sz);

#endif // MEMORY_SAFENET_UTILS