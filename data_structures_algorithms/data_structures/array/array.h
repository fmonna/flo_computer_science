#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>

/*
 * A dynamic array of ints backed by a single contiguous block of memory.
 *
 * The storage is one malloc'd slab; `data[i]` is just `base + i * sizeof(int)`,
 * which is what makes index access O(1). When the slab fills up we realloc it
 * to double the capacity and copy the existing elements across.
 *
 * This is the part the C++, Python and Rust versions get for free from their
 * respective standard libraries (std::vector, list, Vec).
 */
typedef struct {
    int   *data;   /* contiguous storage                  */
    size_t len;    /* number of elements currently held   */
    size_t cap;    /* allocated capacity (>= len)         */
} Array;

Array  array_new(void);
void   array_free(Array *a);
void   array_push(Array *a, int value);
int    array_get(const Array *a, size_t index);    /* exits on out-of-bounds */
void   array_set(Array *a, size_t index, int value);/* exits on out-of-bounds */
size_t array_len(const Array *a);
void   array_print(const Array *a);

#endif /* ARRAY_H */
