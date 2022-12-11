#include<stdio.h>
#include <stdlib.h>
struct Node{
    int key;
    struct Node *left,*right,*parent;
}*root;
typedef struct Node node;
void insert(int k){
    node * t=root,*r=NULL,*p;
    if(root==NULL){
        p=(node *)malloc(sizeof(node));
        p->key=k;
        p->left=p->right=p->parent=NULL;
        root=p;
    }else {
        while (t != NULL) {
            r = t;
            if (k < t->key) { t = t->left; }
            else if (k > t->key) { t = t->right; }
            else return;
        }
        p = (node *) malloc(sizeof(node));
        p->key = k;
        p->left = p->right = p->parent = NULL;
        if (k < r->key)r->left = p;
        else r->right = p;
    }
}
void inorder(node *t){

    if(!root)printf("( )");
    if(t){printf("( ");
        printf("%d ",t->key);
        inorder(t->left);

        if(t->right==NULL)printf("( ) ");
        if(t->left==NULL)printf("( ) ");
        inorder(t->right);
        printf(") ");
    }
}
int main() {
    root=NULL;
    int k;
    char ch;

    while (1) {
        scanf("%c", &ch);
        switch (ch) {
            case 'i':
                scanf("%d", &k);
                insert(k);
                break;
            case 'p':
                inorder(root);
                printf("\n");
                break;
            case 'e':
                return 0;
        }
    }
}
