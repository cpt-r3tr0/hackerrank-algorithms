#!/bin/python3

import os
import sys
from operator import itemgetter

#
# Complete the realEstateBroker function below.
#
def realEstateBroker(clients, houses):
    #
    # Write your code here.
    #
    clients.sort(key=itemgetter(1, 0))
    houses.sort(key=itemgetter(0, 1))
    house_bought = []
    client_bought = []
    count = 0
    for client in clients:
        for house in houses:
            if (house[0] > client[0]) and (house[1] <= client[1]) and (house not in house_bought) and (client not in client_bought):
                count += 1
                house_bought.append(house)
                client_bought.append(client)
    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nm = input().split()

    n = int(nm[0])

    m = int(nm[1])

    clients = []

    for _ in range(n):
        clients.append(list(map(int, input().rstrip().split())))

    houses = []

    for _ in range(m):
        houses.append(list(map(int, input().rstrip().split())))

    result = realEstateBroker(clients, houses)

    fptr.write(str(result) + '\n')

    fptr.close()
