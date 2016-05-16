#include<stdio.h>

int main()
{
    int i,N,fn[10]={1};
    double e=2.5;
    i=1;
    while(i<10){
        fn[i]=i*fn[i-1];
        i++;
    }
    printf("n e\n");
    printf("- -----------\n");
    printf("0 1\n");
    printf("1 2\n");
    printf("2 2.5\n");
    i=3;
    while(i<10){
        e+=1.0/fn[i];          
        printf("%d %.9lf\n",i,e);
        i++;
    }
    return 0;
}
