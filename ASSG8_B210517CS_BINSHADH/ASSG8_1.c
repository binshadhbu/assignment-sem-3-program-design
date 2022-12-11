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

node *searchNode(node *root, int val) {
    node *p = root;
    while (p != NULL && p->val != val) {
        if (val >= p->val) {
            p = p->right;
        }
        else { 
            p = p->left;
        }
    }
    return p;
}

node *findMax(node *root) {
    if (root == NULL) {
        return NULL;
    }
    node *p = root;
    while (p->right != NULL) {
        p = p->right;
    }
    return p;
}

node *findMin(node *root) {
    if (root == NULL) {
        return NULL;
    }
    node *p = root;
    while (p->left != NULL) {
         p = p->left;
    }
    return p;
}

void inorderTraversal(node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ",root->val);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(node *root) {
    if (root != NULL) {
        printf("%d ",root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(node *root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ",root->val);
    }
}

int main() {
    node *root = NULL, *temp = root;
    unsigned char c = 0;
    int val = 0;
    while (c != 'e') {
        scanf(" %c", &c);
        switch (c) {
            case 'a':
                scanf("%d", &val);
                temp = createNode(val);
                insertNode(&root, temp);
                break;
            case 's':
                scanf("%d", &val);
                temp = searchNode(root, val);
                if (temp == NULL) {
                    printf("NotFound\n");
                }
                else {
                    printf("Found\n");
                }
                break;
            case 'x':
                temp = findMax(root);
                if (temp == NULL) {
                    printf("NIL\n");
                }
                else {
                    printf("%d\n",temp->val);
                }
                break;
            case 'n':
                temp = findMin(root);
                if (temp == NULL) {
                    printf("NIL\n");
                }
                else {
                    printf("%d\n",temp->val);
                }
                break;
            case 'i':
                if (root == NULL) {
                    printf("NIL\n");
                    break;
                }
                inorderTraversal(root);
                printf("\n");
                break;
            case 'p':
                if (root == NULL) {
                    printf("NIL\n");
                    break;
                }
                preorderTraversal(root);
                printf("\n");
                break;
            case 't':
                if (root == NULL) {
                    printf("NIL\n");
                    break;
                }
                postorderTraversal(root);
                printf("\n");
                break;
            case 'e':
                break;
            default:
                printf("Invalid input\n");
        }
    }
    return 0;
}
