#include<stdio.h>
int main(){//caling main function
    char name[1000],c;//declaring variable with array and a harector
    scanf("%s",name);
    int freq=1;//declaring variable for frequency
    for(int i=0;name[i]!='\0';i++){
        int count =1;//initial value of count as 1
        char c=name[i];
        name[i]='0';
        for(int j=0;name[j]!='\0';j++){
            if((name[j]==c)&&(name[j]!='0')){
                count++;
                name[j]='0';//to not to check already checked index
            }

        }
        freq=freq*count;//changing the frequency

    }
    printf("%d\n",freq);
    

    return 0;

}
