/*
 * @description:带有头节点的链表
 *    头节点的作用：了操作的统一与方便而设立的，放在第一个元素结点之前，其数据域一般无意义
 * @method: createLink 初始化链表，建立头节点
 *          insert_head 头插节点
 *          insert_tail 尾插节点
 */
#include <stdio.h>
#include <stdlib.h>
//声明节点结构
typedef struct Node {
  int data;           //存储整形元素
  struct Link *next;  //指向直接后继元素的指针
} Node;
typedef struct Node *LinkList; /* 定义LinkList */

/**
 * @description: 创建链表，返回头节点
 */
LinkList createLink() {
  Node *head = (LinkList *)malloc(sizeof(Node));
  head->next = NULL;
  return head;
}
/**
 * @description: 元素的头插法
 * @param LinkList *L 需要插入元素的链表
 *        int x  新插入元素的数据
 * @return: 插入后的链表
 */
LinkList insert_head(LinkList *L, int x) {
  // 创建新的元素
  Node *new = (Node *)malloc(sizeof(Node));
  new->data = x;
  new->next = NULL;
  Node *head = (Node *)malloc(sizeof(Node));
  head = L;
  new->next = head->next;
  head->next = new;
  return head;
}
/**
 * @description: 元素的尾插法
 * @param LinkList *L 需要插入元素的链表
 *        int x  新插入元素的数据
 * @return: 插入后的链表
 */
LinkList insert_tail(LinkList *L, int x) {
  // 创建新的元素
  Node *new = (Node *)malloc(sizeof(Node));
  new->data = x;
  new->next = NULL;
  // 现在所在的元素
  Node *cur = (Node *)malloc(sizeof(Node));
  cur = L;
  // 找到最后元素
  while (cur->next) {
    cur = cur->next;
  }
  cur->next = new;
  return L;
}
void printList(LinkList *L) {
  Node *cur = (Node *)malloc(sizeof(Node));
  cur = L;
  if (cur->next == NULL) {
    printf("链表为空\n");
  } else {
    while (cur->next) {
      cur = cur->next;
      printf("%d,", cur->data);
    }
    printf("\n");
  }
}
int main() {
  LinkList l_h = createLink();
  printf("头插法：\n");
  for (int i = 0; i < 5; i++) {
    l_h = insert_head(l_h, i);
  }
  printList(l_h);  // 输出的值 4,3,2,1,0*/
  // 尾插法
  printf("未插法：\n");
  LinkList l_t = createLink();
  for (int i = 0; i < 5; i++) {
    l_t = insert_tail(l_t, i);
  }
  printList(l_t);  // 输出的值 0,1,2,3,4
  return 1;
}