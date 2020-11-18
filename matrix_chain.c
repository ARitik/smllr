#include<stdio.h>

int MatrixChainOrder(int p[],int i,int j);

int main() {
    int n;
    printf("Enter number of matrices\n");
    scanf("%d",&n);
    int arr[n+1];
    printf("Enter Matrices");
    for(int i = 0;i<=n;i++) {
        scanf("%d",&arr[i]);
    }
    printf("%d",MatrixChainOrder(arr,1,n));
}

int MatrixChainOrder(int p[],int i,int j) {
    if(i==j) 
        return 0;
    int min = 99999;
    int count;
    for(int k=i;k<j;k++) {
        count = MatrixChainOrder(p,i,k) + MatrixChainOrder(p,k+1,j) + (p[i-1]*p[j]*p[k]);
        if(count<min)
            min = count;
    }
    return min;
}

// #include<stdio.h>

// int MatrixChainOrder(int p[], int n) 
// { 


//     int m[n][n]; 

//     int i, j, k, L, q; 

//     for (i = 1; i < n; i++) 
//         m[i][i] = 0; 

//     for (L = 2; L < n; L++) { 
//         for (i = 1; i < n - L + 1; i++)  
//         { 
//             j = i + L - 1; 
//             m[i][j] = 9999; 
//             for (k = i; k <= j - 1; k++)  
//             { 

//                 q = m[i][k] + m[k + 1][j] 
//                     + p[i - 1] * p[k] * p[j]; 
//                 if (q < m[i][j]) 
//                     m[i][j] = q; 
//             } 
//         } 
//     } 

//     return m[1][n - 1]; 
// } 

// // Driver  code 
// int main() 
// { 
//     int arr[] = { 1, 2, 3, 4 }; 
//     int size = sizeof(arr) / sizeof(arr[0]); 

//     printf("Minimum number of multiplications is %d ", MatrixChainOrder(arr, size)); 

//     getchar(); 
//     return 0; 
// }


// /*
// 1) Job Sequencing
// 2) Prim Algo [x][o]
// 3) Floyd Warshall [x][o]
// 4) Matrix Chain [x]
// 5) N Queens [x][o]
// 6) Sum of Subsets [x][o]
// */