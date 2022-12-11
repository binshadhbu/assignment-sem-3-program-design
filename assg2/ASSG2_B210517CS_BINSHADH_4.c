#include<stdio.h>
int binarysearch(int a[],int begin,int end,int t){//function for binary search
    int mid;//middle elements
    mid=(end+begin)/2;//finding midddle elements
    if(end>=begin){
        if(a[mid]==t){
            return mid;//return mid vlaue as index
        }
        else if(a[mid]>t){//changing end index
            end=mid-1;
            return binarysearch(a,begin,end,t);//recursive function calling after index change
        }
        else if(a[mid]<t){//changing begin index
            begin=mid+1;
            return binarysearch(a, begin, end, t);//recursive function calling after index change
        }
        
    }
    return -1;//return -1 as false case
}
int main(){//main function
    int n,t;
    scanf("%d %d",&n,&t);
    int a[n];
    for(int i=0; i<n;i++){
        scanf("%d",&a[i]);//taking input
    }
    int bin=binarysearch(a,0,n-1,t);
    printf("%d\n",bin);
    for(int i=0;i<n;i++){
        if(a[i]>t){
            printf("%d ",i)//print index;
        }
    }
   
    
    return 0;
}
