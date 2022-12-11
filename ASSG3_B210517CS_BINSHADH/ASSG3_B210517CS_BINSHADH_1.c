
#include <stdio.h>

void insertionSort(double arr[], int n)//function definition of insertion sort
{
	int i,j;
	double key;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}



int main()//main function
{
	int n;
	scanf("%d",&n);//taking input to variable n
	double arr[n],b[n];
	for(int i=0;i<n;i++){
	    scanf("%lf",&arr[i]);//taking input to array elements
	    b[i]=arr[i];
	}

	insertionSort(arr, n);//calling sorting function
// 	for(int i=0;i<n;i++){
// 	    printf("%lf ",b[i]);
// 	}
// 	if(b[0]!=arr[0]){
// 	    printf("%s","NO");
// 	}
	for(int i=0;i<n;i++){//for print index of array
	    double c=b[i];
	    for(int j=0;j<n;j++){
	        if(arr[j]==c){
	            printf("%d ",j);
	        }
	    }
	}

	return 0;
}
