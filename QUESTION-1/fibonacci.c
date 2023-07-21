#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    TypeTag type;
} Node;

typedef enum TypeTag {
    ADD,
    MUL,
    SUB,
    FIBO
} TypeTag;