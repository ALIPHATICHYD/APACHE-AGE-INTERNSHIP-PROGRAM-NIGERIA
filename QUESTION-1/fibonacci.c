#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag {
    ADD,
    MUL,
    SUB,
    FIBO
} TypeTag;

typedef struct Node {
    TypeTag type;
    struct Node* left;
    struct Node* right;
} Node;

Node* makeFunc(TypeTag type);
void calc(Node* node);

Node* makeFunc(TypeTag type) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Error: Memory allocation failed for node.\n");
        exit(EXIT_FAILURE);
    }
    node->type = type;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void calc(Node* node) {
    if (node == NULL) {
        printf("Invalid input node\n");
        return;
    }

    switch (node->type) {
        case ADD:
            printf("add : %d\n", ((int*)node->left)[0] + ((int*)node->right)[0]);
            break;
        case MUL:
            printf("mul : %d\n", ((int*)node->left)[0] * ((int*)node->right)[0]);
            break;
        case SUB:
            printf("sub : %d\n", ((int*)node->left)[0] - ((int*)node->right)[0]);
            break;
        case FIBO: {
            int n = ((int*)node->left)[0];
            int* fib = (int*)malloc((n + 1) * sizeof(int));
            if (fib == NULL) {
                printf("Error: Memory allocation failed for fibonacci array.\n");
                exit(EXIT_FAILURE);
            }
            fib[0] = 0;
            fib[1] = 1;
            for (int i = 2; i <= n; i++) {
                fib[i] = fib[i - 1] + fib[i - 2];
            }
            printf("fibo : %d\n", fib[n]);
            free(fib);
            break;
        }
        default:
            printf("Invalid function type\n");
            break;
    }
}

int main() {
    Node* add = makeFunc(ADD);
    *((int*)add->left) = 1;
    *((int*)add->right) = 2;
    calc(add);

    Node* mul = makeFunc(MUL);
    *((int*)mul->left) = 3;
    *((int*)mul->right) = 4;
    calc(mul);

    Node* sub = makeFunc(SUB);
    *((int*)sub->left) = 5;
    *((int*)sub->right) = 6;
    calc(sub);

    Node* fibo = makeFunc(FIBO);
    *((int*)fibo->left) = 10;
    calc(fibo);

    free(add->left);
    free(add->right);
    free(add);

    free(mul->left);
    free(mul->right);
    free(mul);

    free(sub->left);
    free(sub->right);
    free(sub);

    free(fibo->left);
    free(fibo);

    return 0;
}
