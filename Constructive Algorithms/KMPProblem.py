#!/bin/python3

import os
import sys

def min_frequency(x):
    index = -1
    min_freq = -1
    print(x)
    for i, freq in enumerate(x):
        if freq > 0 and (freq < min_freq or min_freq == -1) :
            min_freq = freq
            index = i
    return index

def next_nonzero_index(x,cur_index, banned):
    for i in range(cur_index, len(x)):
        if x[i] != 0 and i != banned:
            return i
    return "none"
#
# Complete the kmp function below.
#
def kmp(x):
    #
    # Write your code here.
    #
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    min_freq_index = min_frequency(x)
    result_string_list = list()

    if x[min_freq_index] < 2:
        result_string_list.append(alphabet[min_freq_index] * x[min_freq_index])
        for i,letter in enumerate(alphabet):
            if i != min_freq_index:
                result_string_list.append(letter * x[i])
    else:
        result_string_list.append(alphabet[min_freq_index])
        letters_left = x.copy()
        letters_left[min_freq_index] = letters_left[min_freq_index] - 1
        cur_index = next_nonzero_index(letters_left, 0, min_freq_index)
        while(letters_left[min_freq_index] > 0 and cur_index != "none" and cur_index > min_freq_index):
            # some stuff
            result_string_list.append(alphabet[min_freq_index] + alphabet[cur_index] )
            letters_left[cur_index] = letters_left[cur_index] - 1
            if(letters_left[cur_index] == 0):
                cur_index = next_nonzero_index(letters_left, 0, min_freq_index)
            letters_left[min_freq_index] = letters_left[min_freq_index] - 1
        for i, letter in enumerate(alphabet):
            # should be out of min_freq letter at this point
            result_string_list.append(letter * letters_left[i])

    return ''.join(result_string_list)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    x = list(map(int, input().rstrip().split()))

    result = kmp(x)

    fptr.write(result + '\n')

    fptr.close()
