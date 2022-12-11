#include <stdio.h>
int count=1;
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
    count++;
    if(li<n&&a[li]>a[roi]){
        swap(&a[i],&a[li]);
        heapify(a,n,li);
    }

    if(ri<n&&a[ri]>a[roi]){
        swap(&a[i],&a[ri]);
        heapify(a,n,ri);
    }
}
void print(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}
void heap_sort(int a[],int n){
    max_heapify(a,n);

    for(int p=n-1;p>=0;p--){
        swap(&a[0],&a[p]);
        heapify(a,p,0);
    }
    print(a,n);
}
int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
   heap_sort(a,n);
    printf("\n");
    printf("%d",count);
    return 0;
}

