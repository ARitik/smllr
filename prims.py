# Input Adjacency Matrix [x]
# Generate intial Distance, MST and Parent Lists [x]
# Perform Prims Algorithm Operation and Generate Parent List
# Build Visualization

import sys

# GLOBAL LISTS
Dist = []
MST = []
Parent = []
adjacency_matrix = []


def generate_initial_lists(V):
    for i in range(V):
        Dist.append(sys.maxsize)
        MST.append(False)
        Parent.append(-1)
    Dist[0] = 0
    # print('[{} {} {}]'.format(Dist, MST, Parent))
    generate_mst_set(V)


def generate_mst_set(V):
    ticker = True
    while ticker:
        d1 = min(Dist)
        parent = Dist.index(d1)
        MST[parent] = True
        Dist[parent] = sys.maxsize
        for i in range(V):
            if adjacency_matrix[parent][i] != 0 and MST[i] != True:
                Parent[i] = parent
                Dist[i] = min(Dist[i], adjacency_matrix[parent][i])
        if False not in MST:
            ticker = False
    print(Parent)
    # print('[{} {} {}]'.format(Dist, MST, Parent))


def generate_adjacency_matrix():
    print(":: ADJACENCY LIST CREATION ::")
    # print("Enter number of vertices :")
    # V = int(input())

    # for i in range(V):
    #     adjacency_matrix.append([])
    #     for j in range(V):
    #         print('Enter weight for VERTEX :: {} -> {}'.format(i, j))
    #         adjacency_matrix[i].append(int(input()))
    V = 6
    global adjacency_matrix
    adjacency_matrix = [[0, 4, 6, 0, 0, 0],
                        [4, 0, 6, 3, 4, 0],
                        [6, 6, 0, 1, 0, 0],
                        [0, 3, 1, 0, 2, 3],
                        [0, 4, 0, 2, 0, 7],
                        [0, 0, 0, 3, 7, 0]
                        ]

    generate_initial_lists(V)


generate_adjacency_matrix()
