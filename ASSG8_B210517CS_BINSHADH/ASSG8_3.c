#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *left, *right, *p;
};
typedef struct node node;

node *createNode(int val) {
    node *p = (node*)malloc(sizeof(node));
    p->val = val;
    p->left = p->right = p->p = NULL;
    return p;
}

void insertNode(node **root, node *new) {
    node *p = *root, *q = NULL;
    while (p != NULL) {
        q = p;
        if (new->val >= p->val) {
            p = p->right;
        }
        else {
            p = p->left;
        }
    }
    if (q == NULL) {
        *root = new;
        return;
    }
    if (new->val >= q->val) {
        q->right = new;
    }
    else {
        q->left = new;
    }
    new->p = q;
    return;
}

void printTree(node *root) {
    printf("( ");
    if (root != NULL) {
        printf("%d ", root->val);
        printTree(root->left);
        printTree(root->right);
    }
    printf(") ");
    return;
}

int main() {
    int val = 0;
    node *root = NULL, *temp = root;
    unsigned char c = 0;
    while (c != 'e') {
        scanf(" %c", &c);
        switch (c) {
            case 'i':
                scanf("%d", &val);
                temp = createNode(val);
                insertNode(&root, temp);
                break;
            case 'p':
                printTree(root);
                printf("\n");
                break;
            case 'e':
                break;
            default:;
        }
    }
    return 0;
}
