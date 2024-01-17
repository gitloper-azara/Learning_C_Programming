#!/usr/bin/python3


def insertionSort(n, list=[]):
    for i in range(n):
        key = list[i]
        j = i - 1

        while j >= 0 and list[j] > key:
            list[j + 1] = list[j]
            j = j - 1
        list[j + 1] = key

def printList(size, list=[]):
    for i in range(size):
        print(f'{list[i]} ', end='')

if __name__ == '__main__':
    lst = [12, 11, 13, 5, 6]
    n = len(lst)

    print('Original array:')
    printList(n, lst)

    insertionSort(n, lst)

    print('\nSorted array:')
    printList(n, lst)
    print()
