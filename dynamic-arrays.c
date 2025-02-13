#include <stdio.h>
#include <stdlib.h>

// DYNAMIC STACK FUNCTIONS
typedef struct {
    int *arr;
    int capacity;
    int size;
} DynamicArray;

DynamicArray *createArray(int initialCapacity) {
    /*
    Input: integer type for capacity size (in ints) 
    Output: Creates an array with dynamic size
    Size sets to 0, counts elements in array 
    */
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    array->arr = (int *)malloc(initialCapacity * sizeof(int));
    array->capacity = initialCapacity;
    array->size = 0;
    return array;
}

void destroyArray(DynamicArray *array) {
    /*
    Input: DynamicArray type
    Output: None
    Frees array then array object
    */
    free(array->arr);
    free(array);
}

void push(DynamicArray *array, int value) {
    /*
    Input: DynamicArray pointer, int value to put in array
    Output: None
    */
    // Check if array is full, if full, double capacity and realloc memory
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (int *)realloc(array->arr, array->capacity * sizeof(int));
    }
    array->arr[array->size++] = value;
}

int pop(DynamicArray *array) {
    /*
    Input: DynamicArray pointer
    Output: Value in the last position of array
    */
    if (array->size > 0) {
        return array->arr[--array->size];
    }
    return -1;
}

//DYNAMIC QUEUE FUNCTIONS
typedef struct {
    int *arr;
    int front;
    int back;
    int capacity;
} Queue;

Queue *createQueue(int initialCapacity) {
    /*
    Input: int type for capacity
    Mallocs array and queue 
    Sets front to 0th position and back to -1 (to check when empty)
    */
    Queue *q = malloc(sizeof(Queue));
    q->arr = malloc(sizeof(int) * initialCapacity);
    q->front = 0;
    q->back = -1;
    q->capacity = initialCapacity;
    return q;
}

int isEmpty(Queue *q) {
    /*
    If front is greater than back (0 > -1), return True
    */
    return q->front > q->back;
}

void enqueue(Queue *q, int value) {
    /*
    Input: Queue pointer, int type for value
    Output: None
    */
    if (q->back == q->capacity-1) {
        // Double capacity of array if full and realloc
        q->capacity *= 2;
        q->arr = realloc(q->arr, sizeof(int) *q->capacity);
    }
    // Increases back and sets value in queue
    q->arr[++q->back] = value;
}

int dequeue(Queue *q) {
    /*
    Input: Queue pointer
    Output: value in q[front]
    After setting value, moves all arr up 1
    */
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->arr[q->front];
    for (int i = q->front; i < q->back; ++i) {
        q->arr[i] = q->arr[i+1];
    }
    q->back--;

    return value;
}

void destroyQueue(Queue *q) {
    /*
    Free Queue array then queue object
    */
    free(q->arr);
    free(q);
}

int main() {
    // DYNAMIC STACK CALLING
    DynamicArray *array = createArray(2);
    for (int i = 0; i < 105; i++) {
        push(array, i * 2);
    }
    while (array->size > 0) {
        printf("Popped %d\n", pop(array));
    }
    destroyArray(array);

    // DYNAMIC QUEUE CALLING    
    printf("\n*** Dynamic Queue Starts Here ***\n");
    Queue *q = createQueue(2);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    while (!isEmpty(q)) {
        printf("%d\n", dequeue(q));
    }
    destroyQueue(q);

    return 0;
}