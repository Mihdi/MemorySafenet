#ifndef MEMORY_SAFENET
#define MEMORY_SAFENET

/**
 * \file export.h
 * \brief header exporting memory_safenet
 * \author Mehdi
 * \version 0.1
 *
 * Naive garbage collecting safety net. Guarantees that anything allocated will
 * be tracked and freed. Be careful when manipulating garbage_state and
 * garbage_dump as they rely on an inner state and any misuse may cause border
 * effects
 *
 */

#include <stdbool.h>
#include <stdlib.h>

#include "../unsafe_generic_hashset/export.h"

/**
 * \fn garbage_collect(void *to_be_added);
 * \brief used to tell garbage_state to track given pointer
 *
 * \param to_be_added the pointer that the garbage_state has to keep track of
 * from now on
 *
 * \return true on success, false on failure
 */
bool garbage_collect(void *to_be_added);

/**
 * \fn garbage_dump(bool are_you_sure);
 * \brief frees all pointers tracked by garbage state and resets garbage state
 *
 * \param are_you_sure is an extra security. Nothing will happen if not set
 *
 */
void garbage_dump(bool are_you_sure);

/**
 * \fn safe_malloc(size_t size);
 * \brief allocates a "safe" pointer of given size that must be freed using
 * `safe_free`
 *
 * the newly allocated pointer will be added to the garbage state and will thus
 * be tracked
 *
 * \param size the size of the memory to be allocated
 *
 * \return returns "safe" pointer of given size on success, or NULL on failure
 */
void *safe_malloc(size_t size);

/**
 * \fn safe_calloc(size_t nmemb, size_t size);
 * \brief allocates a "safe" pointer to a zero-filled memory space of given size
 * that must be freed using `safe_free`
 *
 * the newly allocated pointer will be added to the garbage state and will thus
 * be tracked, it points to a zero-filled memory space
 *
 * \param nmemb the number of entities to be allocated
 * \param size the size of an entity to be allocated
 *
 * \return returns "safe" pointer to a zero filled memory space of given size on
 * success, or NULL on failure
 */
void *safe_calloc(size_t nmemb, size_t size);

/**
 * \fn safe_realloc(void *safe_ptr, size_t size);
 * \brief re-allocates a "safe" pointer to a memory space of given size that
 * must be freed using `safe_free`
 *
 * the previous pointer will be removed from the garbage state if present, and
 * the newly re-allocated pointer will be added to the garbage state and will
 * thus be tracked, please not that it is technically possible to modify
 * safe-realloc to accept non safe pointers as arguments, but that this is not a
 * priority issue, and thus that it won't be done until specifically needed
 *
 * /!\ WARNING /!\
 * giving an unsafe pointer will cause safe_realloc to do nothing and return
 * NULL
 *
 * \param safe_ptr the "safe" pointer to be reallocated
 * \param size the size of the memory to which the new pointer points to
 *
 * \return returns "safe" pointer of given size on success, or NULL on failure
 */
void *safe_realloc(void *safe_ptr, size_t size);

/**
 * \fn safe_free(void *safe_ptr);
 * \brief frees a "safe" pointer and stops the garbage state's tracking of it
 *
 * the given "safe" pointer will be removed from the garbage state and then
 * freed. Please note that it is not because "safe" pointers will not be dumped
 * at the end that you should not safe_free them when they're no longer useful!
 *
 * //!\\ Does nothing if given pointer is not a safe pointer
 *
 * \param safe_ptr the "safe" pointer to be untracked and freed
 *
 */
void safe_free(void *safe_ptr);

/**
 * \fn safe_errx(void *safe_ptr);
 * \brief calls garbage dump then errx
 *
 * Calls garbage_dump on exit
 *
 *
 * \param eval the exit code
 * \param out_msg the msg to say goodbye UwU
 *
 */
void safe_errx(int eval, char *out_msg);

#endif // MEMORY_SAFENET