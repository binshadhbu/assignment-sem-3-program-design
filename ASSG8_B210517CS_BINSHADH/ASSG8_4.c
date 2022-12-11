#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 10000

struct node {
    int val;
    struct node *left, *right;
};
typedef struct node node;

void printTree(node *root) {
    if (root != NULL) {
        printTree(root->left);
        printTree(root->right);
        printf("%d ",root->val);
    }
}
// try to remove i += 2 and i + 1
node *buildTree(const char *A) { 
    static size_t i = 0;
    i += 2;
    if (A[i] == ')') {
        return NULL;
    }
    size_t k = 0;
    char *temp = (char *)malloc(9 * sizeof(char));
    node *p = (node *)malloc(sizeof(node));
    k = 0;
    while (isdigit(A[i])) {
        temp[k++] = A[i++];
    }
    temp[k] = '\0';
    p->val = atoi(temp);
    ++i;
    p->left = buildTree(A);
    do {
        i += 2;
    } while (A[i] == ')');
    p->right = buildTree(A);
    return p;
}

int main() { 
    char *A = (char *)malloc(MAX * sizeof(char));
    scanf("%[^\n]%*c", A);
    node *root = buildTree(A);
    printTree(root);
    printf("\n");
    return 0;
}
