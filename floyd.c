#include<stdio.h>
void floyd(int n);

int w[10][10];

int main() {
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&w[i][j]);
    floyd(n);
        for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            printf("%d ",w[i][j]);
        printf("\n");
        }

}

void floyd(int n) {
    for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++) {
        if(w[i][j]>w[i][k]+w[k][j])
            w[i][j] = w[i][k] + w[k][j];
    }
}