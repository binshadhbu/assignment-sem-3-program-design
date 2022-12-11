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

node *treeSuc(node *p) {
    if (p == NULL) {
        return NULL;
    }
    if (p->right != NULL) {
        return findMin(p->right);
    }
    node *father = p->p;
    while (father != NULL && p == father->right) {
        p = father; 
        father = p->p;
    }
    return father;
}

node *treePred(node *p) {
    if (p == NULL) {
        return NULL;
    }
    if (p->left != NULL) {
        return findMax(p->left);
    }
    node *father  = p->p;
    while (father != NULL && p == father->left) {
        p = father; 
        father = p->p;
    }
    return father;
}

void preorderTraversal(node *root) {
    if (root != NULL) {
        printf("%d ",root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void replace(node **root, node *p, node *u) {
    if (p->p == NULL) {
        *root = u;
    }
    else if (p == p->p->left) {
        p->p->left = u;
    }
    else {
        p->p->right = u;
    }
    if (u != NULL) {
        u->p = p->p;
    }
    return ;
}
void deleteNode(node **root, node *p) {
    if (p->left == NULL) {
        replace(root, p, p->right);
    }
    else if (p->right == NULL) {
        replace(root, p, p->left);
    }
    else {
        
        node *s = treeSuc(p);
        if (s != p->right) {
            replace(root, s, s->right);
            s->right = p->right;
            s->right->p = s;
        }
        replace(root, p, s);
        s->left = p->left;
        s->left->p = s;
    }
    printf("%d\n",p->val);
    free(p);
    return;
}

int main() {
    node *root = NULL, *temp = root;
    int val = 0;
    unsigned char c = 0;
    while (c != 'e') {
        scanf(" %c",&c);
        switch (c) {
            case 'a':
                scanf("%d", &val);
                temp = createNode(val);
                insertNode(&root, temp);
                break;
            case 'd':
                scanf("%d", &val);
                temp = searchNode(root, val);
                if (temp == NULL) {
                    printf("NotFound\n");
                    break;
                }
                deleteNode(&root, temp);
                break;
            case 'c':
                scanf("%d", &val);
                temp = searchNode(root, val);
                if (temp == NULL) {
                    printf("NotFound\n");
                    break;
                }
                temp = treeSuc(temp);
                if (temp == NULL) {
                    printf("NotFound\n");
                    break;
                }
                printf("%d\n", temp->val);
                break;
            case 'r':
                scanf("%d", &val);
                temp = searchNode(root, val);
                if (temp == NULL) {
                    printf("NotFound\n");
                    break;
                }
                temp = treePred(temp);
                if (temp == NULL) {
                    printf("NotFound\n");
                    break;
                }
                printf("%d\n", temp->val);
                break;
            case 'p':
                if (root == NULL) {
                    printf("NIL\n");
                    break;
                }
                preorderTraversal(root);
                printf("\n");
                break;
            case 'e': 
                break;
            default:;
                
        }
    }
    return 0;
}
