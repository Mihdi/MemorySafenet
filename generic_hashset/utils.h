#ifndef GENERIC_HASHSET_UTILS
#define GENERIC_HASHSET_UTILS
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

#include "export.h"

/**
 * \fn struct hash_element *init_hash_element(void)
 * \brief safely init a hash_element
 *
 * \return empty struct hash_element on success, NULL on failure
 */
struct hash_element *init_hash_element(void);

#endif // GENERIC_HASHSET_UTILS