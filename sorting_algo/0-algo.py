#!/usr/bin/python3


def insertionSort(n, lst=None):
    if lst is None:
        lst = []

    for i in range(n):
        key = lst[i]
        j = i - 1

        while j >= 0 and lst[j] > key:
            lst[j + 1] = lst[j]
            j = j - 1
        lst[j + 1] = key

def printlst(size, lst=None):
    if lst is None:
        lst = []

    for i in range(size):
        print(f'{lst[i]} ', end='')
    print()

if __name__ == '__main__':
    lst = [12, 11, 13, 5, 6]
    n = len(lst)

    print('Original array:')
    printlst(n, lst)

    insertionSort(n, lst)

    print('Sorted array:')
    printlst(n, lst)
