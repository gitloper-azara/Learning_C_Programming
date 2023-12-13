#include <stdio.h>

/**
 * this code was written by Arup Guha
 * 6/20/07
 * written in COP 3502 to illustrate an array implementation of a stack
*/

/**
 * the array will store the items in the stack, first in index 0,
 * then 1, etc. top will represent the index to the top element in
 * the stack. if the stack is empty, top will be -1.
*/

#define SIZE 10
#define EMPTY -1

struct stack
{
    int items[SIZE];
    int top;
};

void initialise(struct stack *stackPtr);
int full(struct stack *stackPtr);
int push(struct stack *stackPtr, int value);
int empty(struct stack *stackPtr);
int pop(struct stack *stackPtr);
int top(struct stack *stackPtr);

void initialise(struct stack *stackPtr)
{
    stackPtr->top = -1;
}

/* returns true if the stack pointed  to by stackPtr is full */
int full(struct stack *stackPtr)
{
    return (stackPtr->top == SIZE - 1);
}

/* returns true of the stack pointed to by stackPtr is empty */
int empty(struct stack *stackPtr)
{
    return (stackPtr->top == EMPTY);
}

/**
 * if the push occurs, 1 is returned. if the stack is full and the push
 * can not be done, 0 is returned
*/

int push(struct stack *stackPtr, int value)
{
    /* check if the stack is full */
    if (full(stackPtr))
        return (0);

    /* add value to the top of the stack and adjust the value of the top */
    stackPtr->items[stackPtr->top + 1] = value;
    (stackPtr->top)++;

    return (1);
}

/**
 * pre-condition: the stack pointed to by stackPtr is NOT empty
 * post-condition: the value on the top of the stack is popped and returned
 * NOTE: if the stack pointed to by stackPtr is empty, -1 is returned
*/

int pop(struct stack *stackPtr)
{
    int retval;

    /* check the case that the stack is empty */
    if (empty(stackPtr))
        return (EMPTY);

    /**
     * retrieve the item from the top of the stack, adjust the top and return
     * the item
    */
   retval = stackPtr->items[stackPtr->top];
   (stackPtr->top)--;

   return (retval);
}

/**
 * pre-condition: the stack pointed to by stackPtr is NOT empty
 * post-condition: the value at the top of the stack is returned
 * NOTE: if the stack pointed to by stackPtr is empty, -1 is returned
*/

int top(struct stack *stackPtr)
{
    /* take care of the empty case */
    if (empty(stackPtr))
        return (EMPTY);
    
    /* return the desired item */
    return (stackPtr->items[stackPtr->top]);
}

/**
 * main - program starting point
 * 
 * Return: Always 0
*/

int main(void)
{
    int i;
    struct stack mine;

    /* set up the stack and push a couple items, then pop one */
    initialise(&mine);
    push(&mine, 4);
    push(&mine, 5);
    printf("Popping %d\n", pop(&mine));

    /* push a couple more and test top */
    push(&mine, 22);
    push(&mine, 16);
    printf("At top now = %d\n", top(&mine));

    /* pop all three off */
    printf("Popping %d\n", pop(&mine));
    printf("Popping %d\n", pop(&mine));
    printf("Popping %d\n", pop(&mine));

    /* check if list is empty */
    if (empty(&mine))
        printf("The stack is empty as expected.\n");

    /* fill the stack again */
    for (i = 0; i < 10; i++)
        push(&mine, i);

    /* check if list is full */
    if (full(&mine))
        printf("This stack is full as expected.\n");

    /* pop everything off */
    for (i = 0; i < 10; i++)
        printf("Popping %d\n", pop(&mine));

    return (0);
}
