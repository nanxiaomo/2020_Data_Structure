#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
/*****************************************************************
设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。

循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。

你的实现应该支持如下操作：

MyCircularQueue(k): 构造器，设置队列长度为 k 。
Front: 从队首获取元素。如果队列为空，返回 -1 。
Rear: 获取队尾元素。如果队列为空，返回 -1 。
enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
isEmpty(): 检查循环队列是否为空。
isFull(): 检查循环队列是否已满。

&&&&&&&&&&&&&&&&&&&&&&&&&
以下写法head 和 tail 总是在 初始化的数字k 之内。
******************************************************************/

typedef struct {
    int *list;
    int head;
    int tail;
    int size;
} MyCircularQueue;
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *newcq =  (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    newcq->list = (int *)malloc(sizeof(int) * (k));
    newcq->head = -1;
    newcq->tail = -1;
    newcq->size = k;
    return newcq;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
  if (myCircularQueueIsFull(obj)) {
       return false;
    }
    if (myCircularQueueIsEmpty(obj)) {
       obj->head=0;
    }
    obj->tail=(obj->tail+1)%obj->size;
    obj->list[obj->tail]=value;
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return false;
    }
    if (obj->head==obj->tail) {
        obj->head=-1;
        obj->tail=-1;
        return true;
    }
    obj->head=(obj->head+1)%obj->size;
    return true; 
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    return obj->list[obj->head];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    return obj->list[obj->tail];
  
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (obj->head==-1) {
        return true;
    }
    return false;
}


/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if (((obj->tail + 1) % (obj->size))== obj->head)
    {
        return true;
    }
    return false;  
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj);
}
int main()
{
    MyCircularQueue *q;
    q = myCircularQueueCreate(8);

    int arr[] = {2, 1, 4, 3, 8, 7, 6, 9};
    for (int i = 0; i < 8; i++)
    {
        myCircularQueueEnQueue(q,arr[i]);
    }
    for (int i = 0; i < 8; i++)
    {
        printf(" %d", q->list[i]);
    }
    
    return 0;
}