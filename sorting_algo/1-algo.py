#!/usr/bin/python3


def selectionSort(n, lst=None):
    if lst is None:
        lst = []

    for i in range(n):
        minIndex = i

        for j in range(i + 1, n):
            if lst[j] < lst[minIndex]:
                minIndex = j

        temp = lst[minIndex]
        lst[minIndex] = lst[i]
        lst[i] = temp

def printlst(size, lst=[]):
    for i in range(size):
        print(f'{lst[i]} ', end='')
    print()

if __name__ == '__main__':
    lst = [12, 11, 13, 5, 6]
    n = len(lst)

    print('Original array:')
    printlst(n, lst)

    selectionSort(n, lst)

    print('Sorted array:')
    printlst(n, lst)
