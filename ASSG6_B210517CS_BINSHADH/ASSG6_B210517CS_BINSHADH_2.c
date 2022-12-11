
#include <stdio.h>
#include <stdlib.h>
    struct node{
        int key;
        struct node *next;
    };
    struct node *first,*last;
    struct node *create(int x){
        struct node *ne;
        ne=(struct node *)malloc(sizeof(struct node));
        ne->key=x;
        ne->next=NULL;
        return ne;
    }
    void List_Insert_Back(struct node * L,int k){
        struct node * ne, *temp=first;
        ne=create(k);
                
        if(first==NULL){
            first=ne;
            last=ne;
        }
        else {
            last->next=ne;
            last=ne;
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
            printf("%d ",p->key);
            p=p->next;
        }
        printf("\n");
    }

    void LIST_DELETE_LAST(struct node * L,int k){
        for(int i=0;i<k;i++){
            struct node * p=first,*q=NULL;
            if(p==NULL){
                printf("Empty ");

            }else{
                while(p->next!=NULL){
                    q=p;
                    p=p->next;
                }
                if(q==NULL){
                    first=NULL;
                }
                else if(q->next!=NULL){
                    q->next=NULL;
                    last=q;
                }
                printf("%d ",p->key);
                free(p);
            }

        }printf("\n");

    }
    void empty(){
        struct node * p=first;
        if(p==NULL){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
}
    int main()
    {
        char c;
        scanf("%c",&c);
        while(c != 't'){
            int k;
            switch(c){
                case 'e':empty();break;
                case 'i':scanf("%d",&k);List_Insert_Back(first,k);break;
                case 'd':scanf("%d",&k);LIST_DELETE_LAST(first,k);break;
                case 'p':print(first);break;
                case 't':return 0;
            }
            scanf("%c",&c);
        }
        return 0;
    }
