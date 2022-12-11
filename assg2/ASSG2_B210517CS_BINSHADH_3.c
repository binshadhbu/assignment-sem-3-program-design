#include<stdio.h>
int main(){
    int n,c=0;
    scanf("%d",&n);//taking  umber of elements
    int a[n];//declaring array
    for(int i=0; i<n; i++){//taking input of array elements
        scanf("%d",&a[i]);
    }
    for(int i=0; i<n; i++){
        if(a[0]==a[i]){
            c++;
        }
    }
    if(c==n){
        for(int i=0; i<n; i++){
            printf("%d ",a[i]);
        }

    }
    int max=a[0],smax=a[0];//variables for largest and second largest elements
    for(int i=0; i<n; i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    for(int i=0; i<n; i++){//finding second largest elements form array
        if((a[i]>smax)&&(a[i]!=max)){
            smax=a[i];
        }
    }
    for(int i=0; i<n; i++){
        if(a[i]!=smax){//print elements except second largest 
            printf("%d ",a[i]); 
        }
    }


    return 0;
}
