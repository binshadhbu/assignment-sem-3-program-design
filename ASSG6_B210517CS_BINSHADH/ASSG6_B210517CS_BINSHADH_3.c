#include <stdio.h>
#include <stdlib.h>
void enq(int a[],int n,int k){
    int tail=a[n];
    int head=a[n+1];//printf("%d",tail);
    if(tail==0&&head==0){
        a[tail]=k;
        a[n]=1;
    }
    else if((tail==4&&head==0)||head-tail==2){
        printf("Full\n");
    }else if(tail<n-1){
        a[tail]=k;
        a[n]++;
    }else if(tail==n-1){
        tail=0;
        a[tail]=k;
        a[n]=0;
    }
}
void deq(int a[],int n,int k){
    int tail=a[n];
    int head=a[n+1];
    for(int i=0;i<k;i++){
        if(tail==head){
            printf("Empty ");

        }else if(head<n-1){
            printf("%d ",a[head]);
            a[head]='\0';
            head++;
        }else if(head==n-1){
            head=0;
            printf("%d",a[head]);
            a[head]='\0';
            head++;
        }
        a[n+1]=head;
    }
    printf("\n");

}
void full (int a[],int n){
    int tail=a[n];
    int head=a[n+1];
    if(tail==n-1&&head==0||head-tail==2){
        printf("YES");
    }else{printf("NO");}
    printf("\n");
}
void empty(int a[],int n) {
    int tail=a[n];
    int head=a[n+1];
    if(tail==head){
        printf("YES");
    }else{printf("NO");}
    printf("\n");
}
void print(int a[],int n){
    for(int i=0;i<n;i++){printf("%d ",a[i]);}
    printf("\n");
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n+2];
    a[n]=0;
    a[n+1]=0;
    char ch;int k;
    scanf("%c",&ch);
    while(ch != 't'){
        switch(ch){
            case 'i': scanf("%d",&k);printf("%d",a[5]);enq(a,n,k);break;
            case 'f':full(a,n);break;
            case 'e':empty(a,n);break;
            case 'd':scanf("%d",&k);deq(a,n,k);break;
            case 'p':print(a,n);break;
            case 't':return 0;
        }
        scanf("%c",&ch);
    }
    return 0;
}
