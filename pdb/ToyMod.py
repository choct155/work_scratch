from typing import *
import numpy as np

########################################
# QUICK EXPOSITION ON STATE OBSERVANCE #
########################################

def toyDiv(n = 1000):
    valSet = list(range(10))
    quotients = []
    for i in range(n):
        x = np.random.choice(valSet)
        y = np.random.choice(valSet)
        q = x / y
        quotients.append(int(x) / int(y))
    return quotients


#################################
# TRAVERSING MULTIPLE FUNCTIONS #
#################################

def getMedian(xs: List[int], sort_f: Callable[[List[int]], List[int]]) -> int:
    sortedList: List[int] = sort_f(xs)
    outVal: int = middleValue(sortedList)
    return outVal

# Maybe we want to modify how we identify the "middle" value in a list
def middleValue(xs: List[int]) -> int:
    listLength: int = len(xs)
    preIdx: int = listLength // 2
    if listLength % 2 == 0:
        return (xs[preIdx] + xs[preIdx + 1]) / 2
    else:
        return xs[preIdx + 1]

# Maybe we want to use a different sorting algorithm
def builtinSort(xs: List[int]) -> List[int]:
    return sorted(xs)


######################
# TRACKING RECURSION #
######################

#def quicksort(xs: List[int]) -> List[int]:
#def subbedValAtIndex(val: int, idx: int) -> List[int]:
#def swappedElements(xs: List[int], left: Tuple(int, int), right: Tuple(int, int)) -> List[int]:
#def nextLesserVal(xs: List[int], pivot: int) -> Tuple(int, int):
def nextGreaterVal(xs: List[int], pivot: int) -> Tuple(int, int):
    def ngvBool(xs: List[int], idx: int, found: bool, lastElem: Tuple(int, int)) -> Tuple(int, int):
        if found:
            return lastElem
        restOfList: List[int] = xs[1:]
        newIdx: int = idx + 1
        isFound: bool = xs[0] > pivot
        testedElem: Tuple(int, int) = (idx, xs[0])
        ngvBool(restOfList, newIdx, isFound, testedElem)
    return ngvBool(xs, 0, False, (0,0))

def intMap(xs: List[int], identity: int, f: Callable[[int, int], int]) -> int:
    return intMapAcc(xs, identity, f)

def intMapAcc(xs: List[int], acc: int, f: Callable[[int, int], int]) -> int:
    if len(xs) == 0:
        return acc
    newAcc: int = f(xs[0], acc) 
    return intMapAcc(xs[1:], newAcc, f)

def add(x: int, y: int) -> int:
    return x + y

def prod(x: int, y: int) -> int:
    return x * y




