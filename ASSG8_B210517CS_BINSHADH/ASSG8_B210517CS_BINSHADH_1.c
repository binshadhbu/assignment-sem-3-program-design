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
//void inorder(node *t){
//
//    if(!root)printf("( )");
//    if(t){printf("( ");
//        printf("%d ",t->key);
//        inorder(t->left);
//
//        if(t->right==NULL)printf("( ) ");
//        if(t->left==NULL)printf("( ) ");
//        inorder(t->right);
//        printf(") ");
//    }
//}
void search(int k){
    node *t=root;
    if(root==NULL)printf("NotFound");
    else{
        while(t!=NULL){
            if(t->key==k){
                printf("Found");return;

            }else if(t->key<k){t=t->right;}
            else {t=t->left;}
        }
        printf("NotFound");
    }
}
void find_max(){
    node *t=root;
    if(root==NULL){
        printf("NIL");
    }else{
        while(t->right){
            t=t->right;
        }
    }printf("%d",t->key);
}
void find_min(){
    node *t=root;
    if(root==NULL){
        printf("NIL");
    }else{
        while(t->left){
            t=t->left;
        }
    }printf("%d",t->key);
}
void inorder(node *t){

    if(t){
        inorder(t->left);
        printf("%d ",t->key);
        inorder(t->right);
    }

}
void preorder(node *t){

    if(t){
        printf("%d ",t->key);
        preorder(t->left);
        preorder(t->right);
    }
}
void postorder(node *t){

    if(t){
        postorder(t->left);
        postorder(t->right);
        printf("%d ",t->key);
    }
}
int main() {
    root=NULL;
    int k;
    char ch;

    while (1) {
        scanf("%c", &ch);
        switch (ch) {
            case 'x':find_max();printf("\n"); break;
            case 'n':find_min();printf("\n"); break;
            case 'i':if(root==NULL)printf("NIL");else{inorder(root);}printf("\n");break;
            case 'p':if(root==NULL)printf("NIL");else{preorder(root);} printf("\n");break;
            case 't':if(root==NULL)printf("NIL");else {postorder(root);}printf("\n"); break;
            case 'a':
                scanf("%d", &k);
                insert(k);
                break;
            case 's':scanf("%d", &k);
                search(k);printf("\n");break;
            case 'e':
                return 0;
        }
    }
}
