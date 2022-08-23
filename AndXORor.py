#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'andXorOr' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY a as parameter.
#

def andXorOr(a):
    # Write your code here
    stack=[]
    mr=0
    for i in range(len(a)):
        while stack:
            result=stack[-1]^a[i]
            mr=max(mr,result)
            if stack[-1]>a[i]:
                stack.pop()
            else:
                break
        stack.append(a[i])
    return mr

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    a_count = int(input().strip())

    a = list(map(int, input().rstrip().split()))

    result = andXorOr(a)

    fptr.write(str(result) + '\n')

    fptr.close()
