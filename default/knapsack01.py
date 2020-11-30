wt=[1,1,1]
W = 2
val = [10,20,30]
n = 3



def knapsack(W,wt,val,n):

    if n==0 or W==0:
        return 0

    if wt[n-1] > W:
        return knapsack(W,wt,val,n-1)
    else:
        return max(val[n-1]+knapsack(W-wt[n-1],wt,val,n-1),knapsack(W,wt,val,n-1))




print(knapsack(W,wt,val,n))