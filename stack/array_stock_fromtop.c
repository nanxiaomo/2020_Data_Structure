/*
**
** 静态数组实现堆栈程序
** 从数组头部进栈从数组头部
** {0,0,0,0}
**  push(1);
**  {1,0,0,0}
**  push(2);
**  {1,2,0,0}
**  pop()
**  {1,2,0,0}
*/
#include <stdio.h>
#include "stack.h"

#define STACK_SIZE 100 /* 堆栈最大容纳元素数量 */

/*
** 存储堆栈中的数组和一个指向堆栈顶部元素的指针
*/
static STACK_TYPE stack[STACK_SIZE];
// 从头开始
static int top_element = -1;

/* push */
void push(STACK_TYPE value) {
  /* 压入堆栈之前先判断是否堆栈已满*/
  if (!is_full()) {
    top_element += 1;  // 这里写成 ++top_element 也可以，注意不要写成 top_element++;
    stack[top_element] = value;
  } else {
    printf("full stack\n");
  }
}

/* pop */
void pop(void) {
  /* 弹出堆栈之前先判断是否堆栈已空 */
  if (!is_empty()) {
    top_element -= 1;
  }else {
    printf("stack is empty\n");
  }
}

/* top */
STACK_TYPE top(void) {
  if (!is_empty()) {
    return stack[top_element];
  }else {
    return -1;
  }
}

/* is_empty */
int is_empty(void) { return top_element == -1; }

/* is_full */
int is_full(void) { return top_element == STACK_SIZE - 1; }

/*
** 定义一个print函数，用来打印堆栈里面的元素。
*/
void print(void) {
  int i;
  i = top_element;
  printf("打印出静态数组堆栈里面的值: ");
  if (i == -1) printf("这是个空堆栈\n");
  while (i != -1) printf("%d ", stack[i--]);
  printf("\n");
}
int main(void) {
  print();
  push(10);
  push(9);
  push(7);
  push(6);
  push(5);
  push(4);
  push(3);
  push(2);
  push(1);
  push(0);
  printf("push压入数值后：\n");
  print();
  printf("\n");
  pop();
  pop();
  printf("经过pop弹出几个元素后的堆栈元素:\n");
  print();
  printf("\n");
  printf("top()调用出来的值: %d\n", top());
  return 1;
}