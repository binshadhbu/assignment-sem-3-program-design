#include<stdio.h>//11, 22, 33, 44, 44, 44, 33, 22
void heapify(int a[],int n,int i);
void swap(int *a,int *b);
void heap_sort(int a[],int n);
void max_heapify(int a[],int n){
    for(int p=n/2-1;p>-1;p--){
        heapify(a,n,p);
    }
}
void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a=*b;
    *b=temp;
}
void heapify(int a[],int n,int i){
    int roi=i,li=2*i+1,ri=2*i+2;
    if(li<n&&a[li]>a[roi]){
        swap(&a[i],&a[li]);
        heapify(a,n,li);
    }

    if(ri<n&&a[ri]>a[roi]){
        swap(&a[i],&a[ri]);
        heapify(a,n,ri);
    }
}
void heap_sort(int a[],int n){
    max_heapify(a,n);
    for(int p=n-1;p>=0;p--) {
        swap(&a[0], &a[p]);
        heapify(a, p, 0);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int k;

    scanf("%d",&k);
    if(n==1){
        printf("%d",a[0]);
        return 0;
    }
    int c[2001]={0};int d[2001]={0};
//    for(int i=0;i<2001;i++){
//        if(c[i]!=0){
//            printf("%d is %d \n",i-999,c[i]);
//        }
//    }
    //    for(int i=0;i<2001;i++){
//        if(c[i]!=0){
//            printf("%d is %d \n",i-1000,c[i]);
//        }
//    }

    for(int i=0;i<n;i++){
        int index=a[i]+1000;
        c[index]++;
    }
//    for(int i=0;i<2001;i++){
//        if(c[i]!=0){
//            printf("%d is %d \n",i-1000,c[i]);
//        }
//    }
    for(int i=0;i<2001;i++){
        d[i]=c[i];
    }
    heap_sort(c,2002);
//    for(int i=0;i<k;i++){
//
//        for(int j=0;j<2002;j++){
//            if(c[2001-i]==d[j]){
//                printf("%d ",j-1000);
//                d[j]=0;
//                break;
//            }
//        }
////        printf("%d ",c[2001-i]);
//
//
//    }
//    for(int i=0;i<2001;i++){
//        if(c[i]!=0){
//            printf("%d is %d \n",i-1000,c[i]);
//        }
//    }


    for(int i=0;i<k;i++){
        int ind=c[2000-i];
        for(int j=0;j<2001;j++){
            if(d[j]==ind){
                printf("%d ",j-1001);
                break;
            }

        }
    }

    return 0;
}


