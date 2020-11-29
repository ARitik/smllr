from functools import reduce


def subsets(given_set):
    subset = [0]*len(given_set)
    generate_subsets(given_set,subset,0)

def generate_subsets(given_set,subset,i):
    if i==len(given_set):
        display_subsets(subset)
    else:
        subset[i] = 0
        generate_subsets(given_set,subset,i+1)
        subset[i] = given_set[i]
        generate_subsets(given_set,subset,i+1)

def display_subsets(subset):
    # print(subset)
    sum = reduce((lambda x,y: x+y),subset)
    print(sum)

subsets([1,2,3,4])