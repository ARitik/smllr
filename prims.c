#include<stdio.h>
int minDistance(int distance[],int mst[]);
//Less than 10 vertices
    int n = 5;
int main() {

    int a[5][5] = { { 0, 2, 0, 6, 0 }, 
                        { 2, 0, 3, 8, 5 }, 
                        { 0, 3, 0, 0, 7 }, 
                        { 6, 8, 0, 0, 9 }, 
                        { 0, 5, 7, 9, 0 } }; 
    int parent[10];
    int mst[10] = {0};
    int distance[10];
    for(int i=0;i<n;i++)
        distance[i] = 9999;
    distance[0] = 0;
    parent[0] = -1;

    for(int count=0;count<n;count++) {
        int u = minDistance(distance,mst);
        printf("%d",u);
        mst[u] = 1;

        for(int i=0;i<n;i++) {
            if(a[u][i] && mst[i] == 0 && a[u][i] < distance[i])
                parent[i] = u;
                distance[i] = a[u][i];
        }
    }

    // for(int k=0;k<n;k++) {
    //     printf("%d",parent[k]);
    // }

    // printf("%d",parent[2]);

    }

    int minDistance(int distance[],int mst[]) {
        int min=9999;
        int min_index;
        for(int i=0;i<n;i++) {
            if(mst[i]==0 && distance[i]<min) {
                min = distance[i];
                min_index = i;
            }
        }
        return min_index;
    }