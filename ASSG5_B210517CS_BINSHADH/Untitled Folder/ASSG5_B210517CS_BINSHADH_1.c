#include <stdio.h>
#include <stdlib.h>
struct node{
    char key;
    struct node *next;
};
struct node *first;
struct node *create(char x){
    struct node *ne;
    ne=(struct node *)malloc(sizeof(struct node));
    ne->key=x;
    ne->next=NULL;
    return ne;
}
void List_Insert_Front(struct node * L,char k){
    struct node *ne;
    ne=create(k);
    ne->next=L;
    L=ne;
    first=ne;
}
void List_Insert_Back(struct node * L,char k){
    struct node * ne, *temp=first;
    ne=create(k);
    if(temp!= NULL){
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=ne;
    }else{
        first=ne;
    }
}
void print(struct node * L)
{
    struct node * p=first;
    if(first==NULL){
        printf("NULL\n");
        return;
    }
    while(p!=NULL)
    {
        printf("%c ",p->key);
        p=p->next;
    }
    printf("\n");
}
void LIST_DELETE_FIRST(struct node * L){
    struct node * p=first;
    if(L==NULL){
        printf("NULL\n");
        return;
    }
    first=first->next;
    printf("%c\n",p->key);
    free(p);
}
void LIST_DELETE_LAST(struct node * L){
    struct node * p=first,*q=NULL;
    if(L==NULL){
        printf("NULL\n");
        return;
    }
    while(p->next!=NULL){
        q=p;
        p=p->next;
    }
    if(q==NULL){
        first=NULL;
    }
    else if(q->next!=NULL){
        q->next=NULL;
    }
    printf("%c\n",p->key);
    free(p);
}
int main()
{
//    struct Node *list;
    char c,k,junk;
    scanf("%c",&c);
    while(c != 'e'){
        char k;
        switch(c){
            case 'f':scanf("%c%c",&junk,&k);List_Insert_Front(first,k);break;
            case 't':scanf("%c%c",&junk,&k);List_Insert_Back(first,k);break;
            case 'i':LIST_DELETE_FIRST(first);break;
            case 'l':LIST_DELETE_LAST(first);break;
            case 'p':print(first);break;
            case 'e':return 0;
        }
        scanf("%c%c",&junk,&c);
    }
    return 0;
}
