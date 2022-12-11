#include <stdio.h>
#include <stdlib.h>
void push(int a[],int k,int n){
    int top=a[n];
    if(a[top+1]!='\0'){
        printf("Full\n");
        return;
    }else{
        top++;
        a[top]=k;
        a[n]=top;
    }
}
void pop(int a[],int k,int n){
    for(int i=0;i<k;i++){
        if(a[n]==0){
        printf("Empty ");
    }else{
        printf("%d ",a[a[n]]);
        a[a[n]]='\0';
        a[n]--;
    }
    }printf("\n");
    
}
void full(int a[],int n){
    int top=a[n];
    if(top+2==n){
        printf("YES\n");
    }else{printf("NO\n");}
}
void empty(int a[],int n){
    int top=a[n];
    if(top==0){
        printf("YES\n");
    }else{printf("NO\n");}
    
}
int main(){
    int n,top;
    scanf("%d",&n);
    int a[n+1];
    a[n]=0;
char ch;
int junk=0;
scanf("%c",&ch);
while(ch!='t'){
    switch(ch){
        case 'i':scanf("%d",&junk);push(a,junk,n);break;
        case 'd':scanf("%d",&junk);pop(a,junk,n);break;
        case 'f':full(a,n);break;
        case 'e':empty(a,n);break;
        case 't':return 0;
    }scanf("%c",&ch);
}
return 0;
}
