#include "vector.h"


void init_vector(Vector *vector, size_t block_size, size_t element_size) {
    vector->data = malloc(block_size * element_size);
    vector->element_size = element_size;
    vector->size = 0;
    vector->capacity = block_size;
}


void reserve(Vector *vector, size_t new_capacity) {
    if (new_capacity > vector->capacity) {
        while (new_capacity > vector->capacity) {
            vector->capacity *= 2;
        }
        vector->data = realloc(vector->data, vector->element_size * vector->capacity);
    }
}


void resize(Vector *vector, size_t new_size) {
    if (new_size > vector->size) {
        reserve(vector, new_size);
        size_t new_elements_no = new_size - vector->size;
        memset(
                (char *) vector->data + vector->size * vector->element_size,
                0,
                new_elements_no * vector->element_size
        );
    }
    vector->size = new_size;
}


void pop_back(Vector *vector) {
    if (vector->size > 0) {
        vector->size--;
    }
}


void push_back(Vector *vector, void *value) {
    reserve(vector, vector->size + 1);
    memcpy(
            (char *) vector->data + vector->size * vector->element_size,
            value,
            vector->element_size
    );
    vector->size++;
}


void insert(Vector *vector, int index, void *value) {
    if (index < 0 || index > vector->size) {
        printf("%s", "error: Inserted element index should be in range [0, size - 1]\n");
        return;
    }

    if (index == vector->size) {
        push_back(vector, value);
        return;
    }

    reserve(vector, vector->size + 1);

    memmove(
            (char*) vector->data + (index + 1)  * vector->element_size,
            (char*) vector->data + index * vector->element_size,
            vector->element_size * (vector->size - index)
    );
    memcpy(
            (char *) vector->data + index * vector->element_size,
            value,
            vector->element_size
    );

    vector->size++;
}


void clear(Vector *vector) {
    vector->size = 0;
}


void erase(Vector *vector, int index) {
    if (index < 0 || index > vector->size - 1) {
        printf("error: Erased element index should be in range [0, size - 1]\n");
        return;
    }

    if (index != vector->size - 1) {
        memmove(
            (char*) vector->data + index * vector->element_size,
            (char*) vector->data + (index + 1) * vector->element_size,
            vector->element_size * (vector->size - index - 1)
        );
    }

    vector->size--;
}


void erase_value(Vector *vector, void *value, int (*cmp)(const void*, const void*)) {
    size_t i = 0;

    while (i < vector->size) {
        void *element_ptr = (char*)vector->data + i * vector->element_size;
        if (cmp(element_ptr, value) == 0) {
            erase(vector, i);
        } else {
            i++;
        }
    }
}


void erase_if(Vector *vector, int (*predicate)(void *)) {
    size_t i = 0;

    while (i < vector->size) {
        void *element_ptr = (char*)vector->data + i * vector->element_size;
        if (predicate(element_ptr) == 1) {
            erase(vector, i);
        } else {
            i++;
        }
    }
}


void shrink_to_fit(Vector *vector) {
    vector->data = realloc(vector->data, vector->element_size * vector->size);
    vector->capacity = vector->element_size;
}
