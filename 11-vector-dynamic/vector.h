#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vector {
    void *data;
    size_t element_size;
    size_t size;
    size_t capacity;
} Vector;

// Allocate vector to initial capacity (block_size elements),
// Set element_size, size (to 0), capacity
void init_vector(Vector *vector, size_t block_size, size_t element_size);

// If new_capacity is greater than the current capacity,
// new storage is allocated, otherwise the function does nothing.
void reserve(Vector *vector, size_t new_capacity);

// Resizes the vector to contain new_size elements.
// If the current size is greater than new_size, the container is
// reduced to its first new_size elements.
// If the current size is less than new_size,
// additional zero-initialized elements are appended
void resize(Vector *vector, size_t new_size);

// Add element to the end of the vector
void push_back(Vector *vector, void *value);

// Remove the last element from the vector
void pop_back(Vector *vector);

// Insert new element at index (0 <= index <= size) position
void insert(Vector *vector, int index, void *value);

// Remove all elements from the vector
void clear(Vector *vector);

// Erase element at position index
void erase(Vector *vector, int index);

// Erase all elements that compare equal to value from the container
void erase_value(Vector *vector, void *value, int(*cmp)(const void*, const void*));

// Erase all elements that satisfy the predicate from the vector
void erase_if(Vector *vector, int (*predicate)(void *));

// Request the removal of unused capacity
void shrink_to_fit(Vector *vector);


#endif