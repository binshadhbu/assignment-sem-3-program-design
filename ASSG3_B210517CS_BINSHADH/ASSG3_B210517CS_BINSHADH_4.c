#include<stdio.h>
void read_and_store(int a[],int n){//function to read and store elements 
//calling by r
    for(int i=0;i<n;i++){
                scanf("%d",&a[i]);
            }
    
}

//function print array elements 
//activate by p
void print(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

//function to find sum of digits by giving index
//call by d with index
//return the sum
int digit_sum(int d){
    int sum=0;
        while(d/10!=0){
            sum=sum+d%10;
            d=d/10;
        
    }if(d<10){
        sum=sum+d;
    }
    return sum;
    
}
//sorting function by insertion
void insertion_sort(int b[],int n){

    int k;
    for(int i=1;i<n;i++){
        int j=i-1;
        int k=b[i];
        while(j>-1&&b[j]>k){
            b[j+1]=b[j];
            j--;
        }
        b[j+1]=k;
    }
    
}

//function to arang the array elements by question
void sortorder(int a[],int n,int b[]){
    int c[n];
    for(int i=0;i<n;i++){
        b[i]=digit_sum(a[i]);
    }
    insertion_sort(b,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(b[i]==digit_sum(a[j])){
                c[i]=a[j];
                a[j]=0;
                break;
            }
            
        }
    }
    for(int i=0;i<n;i++){
        a[i]=c[i];
    }
    
}


int main(){
    char ac;
    int n,a[100000],b[100000],d;
    scanf("%c",&ac);//first taking input
    while(ac!='t'){//calling function according input
        if(ac=='r'){
            scanf("%d",&n);
            read_and_store(a,n);
            
        }if(ac=='p'){
            print(a,n);
            printf("\n");
        }
        if(ac=='d'){
            scanf("%d",&d);
            printf("%d\n",digit_sum(a[d]));
        }
        if(ac=='s'){
            sortorder(a,n,b);
            
        }
        scanf("%c",&ac);
        
    }
    if(ac=='t'){
        printf("%d",-1);
        
        return 0;
    }
    
}
