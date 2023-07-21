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

int main() {
    Node* add = (*makeFunc(ADD))(10, 6);
    Node* mul = (*makeFunc(MUL))(5, 4);
    Node* sub = (*makeFunc(SUB))(mul, add);
    Node* fibo = (*makeFunc(FIBO))(sub, NULL);

    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);

    free(add);
    free(mul);
    free(sub);
    free(fibo);

    return 0;
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


// int main() {
//     Node* add = makeFunc(ADD);
//     *((int*)add + 1) = 10;
//     *((int*)add + 2) = 20;
//     calc(add);

//     Node* mul = makeFunc(MUL);
//     *((int*)mul + 1) = 10;
//     *((int*)mul + 2) = 20;
//     calc(mul);

//     Node* sub = makeFunc(SUB);
//     *((int*)sub + 1) = 10;
//     *((int*)sub + 2) = 20;
//     calc(sub);

//     Node* fibo = makeFunc(FIBO);
//     *((int*)fibo + 1) = 10;
//     calc(fibo);

//     return 0;
// }
