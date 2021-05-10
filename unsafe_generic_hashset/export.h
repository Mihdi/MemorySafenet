#ifndef UNSAFE_GENERIC_HASHSET
#define UNSAFE_GENERIC_HASHSET

/**
 * \file export.h
 * \brief header exporting generic hashset
 * \author Mehdi (Add your name if you modify this file, just so we know who
 * touched it) \version 0.1
 *
 * generic_hashset, with both unsafe and safe operations. The unsafe ones are to
 * be used for the garbage collector ONLY. You should use the garbage
 * collector's memory functions when developing ANY OTHER MODULE.
 *
 */

#include <stdbool.h>
#include <stddef.h>

/**
 * \struct hash_element
 * \brief block of a double-linked list holding a generic element, using a
 * sentinel
 *
 * hash_element is a structure specifically made to be used by hash_set to
 * handle collisions, for the sake of genericity, it contains a (void *) that
 * holds a given element. For the sake of ease of use, it is a double linked
 * list (frankly, the cost of just one extra pointer is definetly not that
 * high), and just for safety measures, it is a sentinel based list.
 */

struct hash_element
{
    void *val; /*!< held value (generic). */
    struct hash_element *prev; /*!< link to previous block */
    struct hash_element *next; /*!< link to next block */
};

/**
 * \struct hash_set
 * \brief stores a value with no duplicates, has both safe and unsafe ops, ops
 * are as close to O(1) as possible
 *
 * hash_element is a structure specifically made to be used by hash_set to
 * handle collisions, for the sake of genericity, it contains a (void *) that
 * holds a given element. For the sake of ease of use, it is a double linked
 * list (frankly, the cost of just one extra pointer is definetly not that
 * high), and just for safety measures, it is a sentinel based list.
 */
struct hashset
{
    size_t
        size; /*!< holds the size of hash_set, the wider the less collisions */
    struct hash_element **set; /*!< array holding the hash_elements, held
                                 element is the sentinel */
    size_t (*hash)(void *,
                   size_t); /*!< holds the hashing function taking the element
                               and the size of the hashset, and returns that
                               element's position in the hash_set */
};

/**
 * \fn unsafe_init_hashset(size_t size, size_t (*hash)(void *, size_t));
 * \brief init a hashset in an unsafe manner (meaning it uses malloc directly
 * and nothing it allocs will be tracked)
 *
 * \param size, the size of the hash_set, the wider, the less collisions
 * \param hash, the hashing function takes the element and the size of the
 * hashset, and returns that element's position. Optimize this if possible
 *
 * \return empty struct hashset on success, NULL on failure
 */
struct hashset *unsafe_init_hashset(size_t size,
                                    size_t (*hash)(void *, size_t));

/**
 * \fn unsafe_add2hashset(void *to_be_added, struct hashset *hs);
 * \brief adds the element to the hashset in an unsafe manner (meaning it uses
 * malloc directly and nothing it allocs will be tracked)
 *
 * \param to_be_added, the element to be added
 * \param hs, the hashset in which the element will be added
 *
 * \return true on success, false on failure
 */
bool unsafe_add2hashset(void *to_be_added, struct hashset *hs);

/**
 * \fn unsafe_rmv_from_hashset(void *to_be_rmvd, struct hashset *hs);
 * \brief removes the element from the hashset in an unsafe manner (meaning it
 * uses free directly and nothing it frees will be tracked)
 *
 * \param to_be_rmvd, the element to be removed
 * \param hs, the hashset from which the element will be removed
 *
 * \return true on success, false on failure
 */
bool unsafe_rmv_from_hashset(void *to_be_rmvd, struct hashset *hs);

/**
 * \fn is_in_hashset(void *sought, struct hashset *hs);
 * \brief tells if the element is in the hashset
 *
 * \param sought, the sought element
 * \param hs, the hashset in which we want to see if the element is
 *
 * \return true if element found, false otherwise
 */
bool is_in_hashset(void *sought, struct hashset *hs);

/**
 * \fn unsafe_free_hashset(struct hashset *hs);
 * \brief frees the given hashset and all of its hash_elements in an unsafe
 * manner (meaning it uses free directly and nothing it frees will be tracked)
 *
 * \param hs, the hashset to be freed
 *
 */
void unsafe_free_hashset(struct hashset *hs);

#endif // UNSAFE_GENERIC_HASHSET