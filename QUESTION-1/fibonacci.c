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


Node* makeFunc(TypeTag type) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = type;
    return node;
}

void calc(Node* node) {
    if (node == NULL) {
        printf("Invalid input node\n");
        return;
    }

    switch (node->type) {
        case ADD:
            printf("add : %d\n", *((int*)node + 1) + *((int*)node + 2));
            break;
        case MUL:
            printf("mul : %d\n", *((int*)node + 1) * *((int*)node + 2));
            break;
        case SUB:
            printf("sub : %d\n", *((int*)node + 1) - *((int*)node + 2));
            break;
        case FIBO:
            int n = *((int*)node + 1);
            int fib[n + 1];
            fib[0] = 0;
            fib[1] = 1;
            for (int i = 2; i <= n; i++) {
                fib[i] = fib[i - 1] + fib[i - 2];
            }
            printf("fibo : %d\n", fib[n]);
            break;
        default:
            printf("Invalid function type\n");
            break;
    }
}


// Node* makeAdd(Node* left, Node* right) {
//     Node* node = makeFunc(ADD);
//     node->left = left;
//     node->right = right;
//     return node;
// }

// Node* makeMul(Node* left, Node* right) {
//     Node* node = makeFunc(MUL);
//     node->left = left;
//     node->right = right;
//     return node;
// }

// Node* makeSub(Node* left, Node* right) {
//     Node* node = makeFunc(SUB);
//     node->left = left;
//     node->right = right;
//     return node;
// }

// Node* makeFibo(Node* left, Node* right) {
//     Node* node = makeFunc(FIBO);
//     node->left = left;
//     node->right = right;
//     return node;
// }


