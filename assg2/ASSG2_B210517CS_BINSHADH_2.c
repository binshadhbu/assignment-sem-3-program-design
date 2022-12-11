#include<stdio.h>
int main(){
    int n,k,m;
    scanf("%d %d",&n,&k);//taking input of n and k
    m=n/k;
    int b[m][k];//declaring a 2d array with n elements
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);//taking input of array elements
    }
    int p=0;//for the elements
    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            b[i][j] = a[p];
            p++;
        }
    }
    int check;//variable for checking whaeather the elements is there or not
    scanf("%d",&check);
    int count=0;
    for (int i = 0; i < m; i++)
    {
        
        for (int j = 0; j < k; j++)
        {
            if (b[i][j] == check)
            {
                count++;//changing the count 
                break;
            }
    }
    
    }
    printf("%d\n",count);//printing count

}
