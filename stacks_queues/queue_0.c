#include <stdio.h>
#include <stdlib.h>

/**
 * this code was written by Arup Guha
 * 6/20/07
 * written in COP 3502 to illustrate an array implementation of a stack
*/

#define EMPTY -1
#define INIT_SIZE 10

/* stores our queue */
struct queue
{
    int *elements;
    int front;
    int numElements;
    int queueSize;
};

void init(struct queue *qPtr);
int enqueue(struct queue *qPtr, int val);
int dequeue(struct queue *qPtr);
int empty(struct queue *qPtr);
int front(struct queue *qPtr);

/**
 * pre-condition: qPtr points to a valid struct queue
 * post-condition: the struct that qPtr points will be set up to represent an
 * empty queue
*/

void init(struct queue *qPtr)
{
    /* the front index is 0, as is the number of elements */
    qPtr->elements = malloc(sizeof(int) * INIT_SIZE);
    qPtr->front = 0;
    qPtr->numElements = 0;
    qPtr->queueSize = INIT_SIZE;
}

/**
 * pre-condition: qPtr points to a valid struct queue and val is the value
 * to enqueue into the queue pointed to by qPtr
 * post-condition: if the operation is successful, 1 will be returned,
 * otherwise no change will be made to the queue and 0 will be returned
 * NOTE: right now, i do not know how to detect that the realloc failed, so
 * 0 does not get returned
*/

int enqueue(struct queue *qPtr, int val)
{
    int i;

    /* regular case where our queue is not full */
    if (qPtr->numElements != qPtr->queueSize)
    {
        /*
         * enqueue the current element. note the use of mod for the wraparound
         * case. edit the number of elements
        */
       qPtr->elements[(qPtr->front + qPtr->numElements) % qPtr->queueSize] = val;
       (qPtr->numElements)++;

       return (1);
    }

    /* case where the queue is full, we must find more space before we enqueue */
    else
    {
        /* allocate more space */
        qPtr->elements = realloc(qPtr->elements, (qPtr->queueSize) * sizeof(int) * 2);

        /*
         * copy all of the items that are stored "before" front and copy them
         into their new correct location
        */
       for (i = 0; i <= qPtr->front - 1; i++)
            qPtr->elements[i + qPtr->queueSize] = qPtr->elements[i];
        
        /*
         * enqueue the new item, now that there is no space. we are guaranteed
         * that no wraparound is necessary here.
        */
       qPtr->elements[i + qPtr->queueSize] = val;

       /*
        * more bookkeeping: the size of the queue has doubled and the number of
        * elements has increased by one
       */
      (qPtr->queueSize) *= 2;
      (qPtr->numElements)++;

      return (1);
    }
}

/**
 * pre-condition: qPtr points to a valid struct queue
 * post-condition: if the queue pointed to by qPtr is non-empty, then the value
 * at the front of the queue is deleted from the queue and returned. otherwise, -1
 * is returned to signify that the queue was already empty when the dequeue was attempted
*/

int dequeue(struct queue *qPtr)
{
    int retval;

    /* empty case */
    if (qPtr->elements == 0)
        return (EMPTY);

    /* store the value that should be returned */
    retval = qPtr->elements[qPtr->front];

    /*
    adjust the index to the front of the queue accordringly */
    qPtr->front = (qPtr->front + 1) % qPtr->queueSize;
    /* we have one fewer element in the queue */
    (qPtr->numElements)--;

    return (retval);
}

/**
 * pre-condition: qPtr points to a valid struct queue
 * post-condition: returns true if the queue pointed to by qPtr is empty
*/

int empty(struct queue *qPtr)
{
    return (qPtr->numElements == 0);
}

/**
 * pre-condition: qPtr points to a valid struct queue
 * post-condition: if the queue pointed to by qPtr is non-empty, the value
 * stored at the front of the queue is returned. otherwise, -1 is returned
 * to signify that this queue is empty
*/

int front(struct queue *qPtr)
{
    if (qPtr->numElements != 0)
        return (qPtr->elements[qPtr->front]);
    else
        return (EMPTY);
}

/**
 * main - program entry point
 * 
 * Return: Always 0
*/

int main(void)
{
    int i;

    /* allocate space for our queue and initialise it */
    struct queue *MyQueuePtr = malloc(sizeof(struct queue));
    if (MyQueuePtr == NULL)
    {
        free(MyQueuePtr);
        return (-1);
    }
    init(MyQueuePtr);

    /* enqueue some items */
    enqueue(MyQueuePtr, 3);
    enqueue(MyQueuePtr, 7);
    enqueue(MyQueuePtr, 4);

    /* try one dequeue */
    printf("Dequeue %d\n", dequeue(MyQueuePtr));

    /* enqueue one more item, then try several dequeues and one front */
    enqueue(MyQueuePtr, 2);
    printf("Dequeue %d\n", dequeue(MyQueuePtr));
    printf("At Front of Queue Now: %d\n", front(MyQueuePtr));
    printf("Dequeue %d\n", dequeue(MyQueuePtr));
    printf("Dequeue %d\n", dequeue(MyQueuePtr));

    /* see if we can detect an empty queue */
    printf("Is empty: %d\n", empty(MyQueuePtr));

    /**
     * try enqueuing and dequeing again to make sure our previous operations
     * did not corrupt the queue
    */
   enqueue(MyQueuePtr, 5);
   enqueue(MyQueuePtr, 9);

   /* try lots of enqueues to test the dynamic capability of the queue */
   for (i = 30; i < 60; i++)
        enqueue(MyQueuePtr, i);
    
    /* dequeue everything! */
    while (!empty(MyQueuePtr))
        printf("Dequeue %d\n", dequeue(MyQueuePtr));

    return (0);
}
