#include <stdio.h>
void insertionSort(int arr[], int n)//function definition of insertion sort
{
	int i,j;
	int key;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;//storing elements from temporary array to 
//original array
	}
}
void merge(int a[],int m,int b[],int n,int c[]){//function to merge
//here first combine then sort it with insertion sort
    for(int i=0;i<m;i++){
        c[i]=a[i];
    }
    for(int i=0;i<n;i++){
        c[i+m]=b[i];
    }
    
    insertionSort(c,m+n);//calling sort
}

int main()//drive main function8
{
    int m, n,target,check=-1;
    scanf("%d%d", &m, &n);
//input size of arrays
    int a[m], b[n],c[m+n];//diclaring arrays
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);//taking input to first array
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);//taking input to second array
    }
    scanf("%d",&target);
//taking input of target element
    merge(a, m, b, n,c);//calling merge function
    for(int i=0;i<m+n;i++){//for checking if the target element is in sorted array
//after merging
        if(c[i]==target){
            check=i;
        }
    }
    if(check==-1){
        printf("%d",-1);
    }else{
        printf("%d",check);
    }
    

    return 0;
}
