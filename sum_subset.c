#include<stdio.h>


int isSubsetSum(int set[],int n,int sum) {
    if(sum==0)
        return 1;
    if(n == 0)
        return 0;

    if(set[n-1]>sum)
        return isSubsetSum(set,n-1,sum);
    
    return isSubsetSum(set,n-1,sum) || isSubsetSum(set,n-1,sum-set[n-1]);
}



int main() {
    int n,sum;
    scanf("%d%d",&n,&sum);
    int set[n];
    for(int i=0;i<n;i++)
        scanf("%d",&set[i]);
    if(isSubsetSum(set,n,sum))
        printf("Found!");
    return 0;
}