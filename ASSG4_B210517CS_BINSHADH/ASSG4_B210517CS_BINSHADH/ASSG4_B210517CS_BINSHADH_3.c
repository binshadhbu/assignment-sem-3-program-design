#include <stdio.h>
void heapify(float a[],int n,int i);
void swap(float *a,float *b);
void heap_sort(float a[],int n);
void max_heapify(float a[],int n){
    for(int p=n/2-1;p>-1;p--){
        heapify(a,n,p);
    }
}
void swap(float *a,float *b){
    float temp;
    temp = *a;
    *a=*b;
    *b=temp;
}
void heapify(float a[],int n,int i){
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
void heap_sort(float a[],int n){
    max_heapify(a,n);
    for(int p=n-1;p>=0;p--) {
        swap(&a[0], &a[p]);
        heapify(a, p, 0);
    }
}
int main (){
    int n,k;
    scanf("%d %d",&n,&k);
    int m=n-k;
    float  a[k],b[m];
    for(int i=0;i<k;i++){
        scanf("%f",&a[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%f",&b[i]);
    }
    heap_sort(a,k);
    heap_sort(b,m);
    printf("%0.2f %0.2f",a[k-1],b[m-1]);
    return 0;
}
