#include "array.h"

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 4

Array array_new(void) {
    Array a;
    a.cap  = INITIAL_CAPACITY;
    a.len  = 0;
    a.data = malloc(a.cap * sizeof(int));
    if (a.data == NULL) {
        fprintf(stderr, "array_new: out of memory\n");
        exit(1);
    }
    return a;
}

void array_free(Array *a) {
    free(a->data);
    a->data = NULL;
    a->len = a->cap = 0;
}

void array_push(Array *a, int value) {
    if (a->len == a->cap) {              /* slab is full: grow it */
        a->cap *= 2;
        a->data = realloc(a->data, a->cap * sizeof(int));
        if (a->data == NULL) {
            fprintf(stderr, "array_push: out of memory\n");
            exit(1);
        }
    }
    a->data[a->len++] = value;
}

int array_get(const Array *a, size_t index) {
    if (index >= a->len) {
        fprintf(stderr, "array_get: index %zu out of bounds (len %zu)\n",
                index, a->len);
        exit(1);
    }
    return a->data[index];
}

void array_set(Array *a, size_t index, int value) {
    if (index >= a->len) {
        fprintf(stderr, "array_set: index %zu out of bounds (len %zu)\n",
                index, a->len);
        exit(1);
    }
    a->data[index] = value;
}

size_t array_len(const Array *a) {
    return a->len;
}

void array_print(const Array *a) {
    printf("[");
    for (size_t i = 0; i < a->len; i++) {
        printf("%d%s", a->data[i], (i + 1 < a->len) ? ", " : "");
    }
    printf("]\n");
}

/* --- demo: same as the C++/Python/Rust examples -------------------------- */
int main(void) {
    Array a = array_new();
    array_push(&a, 10);
    array_push(&a, 20);
    array_push(&a, 30);
    array_print(&a);            /* [10, 20, 30] */

    printf("%d\n", array_get(&a, 1));   /* 20 */

    array_set(&a, 1, 99);
    array_print(&a);            /* [10, 99, 30] */

    printf("%zu\n", array_len(&a));     /* 3 */

    array_free(&a);
    return 0;
}
