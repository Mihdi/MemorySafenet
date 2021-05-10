#ifndef GENERIC_HASHSET
#define GENERIC_HASHSET

/**
 * \file export.h
 * \brief header exporting generic hashset
 * \author Mehdi (Add your name if you modify this file, just so we know who
 * touched it) \version 0.1
 *
 * generic_hashset, with safe operations.
 *
 */

#include "../memory_safenet/export.h"
#include "../unsafe_generic_hashset/export.h"

/**
 * \fn init_hashset(size_t size, size_t (*hash)(void *, size_t));
 * \brief init a hashset safely
 *
 * \param size, the size of the hash_set, the wider, the less collisions
 * \param hash, the hashing function takes the element and the size of the
 * hashset, and returns that element's position. Optimize this if possible
 *
 * \return safe empty struct hashset on success, NULL on failure
 */
struct hashset *init_hashset(size_t size, size_t (*hash)(void *, size_t));

/**
 * \fn add2hashset(void *to_be_added, struct hashset *hs);
 * \brief safely adds the element to the hashset
 *
 * \param to_be_added, the element to be added
 * \param hs, the hashset in which the element will be added
 *
 * \return true on success, false on failure
 */
bool add2hashset(void *to_be_added, struct hashset *hs);

/**
 * \fn rmv_from_hashset(void *to_be_rmvd, struct hashset *hs);
 * \brief safely removes the element from the hashset
 *
 * \param to_be_rmvd, the element to be removed
 * \param hs, the hashset from which the element will be removed
 *
 * \return true on success, false on failure
 */
bool rmv_from_hashset(void *to_be_rmvd, struct hashset *hs);

/**
 * \fn free_hashset(struct hashset *hs);
 * \brief safely frees the given hashset and all of its hash_elements
 *
 * \param hs, the hashset to be freed
 *
 */
void free_hashset(struct hashset *hs);

#endif // GENERIC_HASHSET