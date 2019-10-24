#include <stdio.h>
#include <stdlib.h>
//  L 为链表的头指针
//声明节点结构
typedef struct Node {
  int data;           //存储整形元素
  struct Link *next;  //指向直接后继元素的指针
} Node;
typedef struct Node *LinkList; /* 定义LinkList */
/**
 * @description: 元素的头插法插入
 * @param LinkList *L 需要插入元素的链表
 *        int x  新插入元素的数据
 * @return: 插入后的链表
 */
LinkList insert_head(LinkList *L, int x) {
  // 创建新的元素
  Node *new = (Node *)malloc(sizeof(Node));
  new->data = x;
  new->next = NULL;
  new->next = L;
  return new;
}
/**
 * @description: 元素的尾插法插入
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
  if (L == NULL) {
    return new;
  }
  // 找到最后元素
  while (cur->next) {
    cur = cur->next;
  }
  cur->next = new;
  return L;
}
/**
 * @description: 元素的头插法删除
 * @param LinkList *L 需要插入元素的链表
 *        int x  新插入元素的数据
 * @return: 删除后的链表
 */
LinkList delete_head(LinkList *L) {
  // 新的元素
  Node *head = (Node *)malloc(sizeof(Node));
  head = L;
  if (L == NULL) {
    return head;
  }
  return head->next;
}
/**
 * @description: 元素的尾部删除
 * @param LinkList *L 需要插入元素的链表
 *        int x  新插入元素的数据
 * @return: 删除后的链表
 * @note: 这里需要两个节点保存，一个节点找不上上一个位置
 */
LinkList delete_tail(LinkList *L) {
  // 现在所在的元素
  Node *cur = (Node *)malloc(sizeof(Node));  // 目前元素的下一个元素
  Node *next_elem = (Node *)malloc(sizeof(Node));
  cur = L;
  // 链表本身为空
  if (L == NULL) {
    return L;
  }
  // 只有一个元素
  next_elem = cur->next;
  if (next_elem == NULL) {
    return next_elem;
  }
  while (next_elem->next) {
    cur = next_elem;
    next_elem = next_elem->next;
  }
  free(next_elem);
  cur->next = NULL;
  // 因为next = null 并不意味着 current 访问不到 current.next,还是可以的，
  // 所以要写为 cur.next = null, 这样才能保证删除最后一个节点
  return L;

}
// 查找元素
Node findElem(LinkList *L,int x) {
  
}
// 删除指定元素
// 插入元素x后
// 打印链表
void printList(LinkList *L) {
  Node *cur = (Node *)malloc(sizeof(Node));
  cur = L;
  if (L == NULL) {
    printf("链表为空\n");
  } else {
    while (cur) {
      printf("%d,", cur->data);
      cur = cur->next;
    }
    printf("\n");
  }
}

int main() {
  LinkList l_h = NULL;
  // 头插法插入
  printf("头插法：\n");
  for (int i = 0; i < 5; i++) {
    l_h = insert_head(l_h, i);
  }
  printf("头插法插入后的链表：\n");
  printList(l_h);  // 输出的值 4,3,2,1,0*/
  for (int i = 0; i < 4; i++) {
    l_h = delete_head(l_h);
  }
  printf("头插法删除后的链表：\n");
  printList(l_h);  // 输出的值 0,1,2,3,4
  // 尾插法插入
  printf("尾插法：\n");
  LinkList l_t = NULL;
  for (int i = 0; i < 5; i++) {
    l_t = insert_tail(l_t, i);
  }
  printf("尾插法插入后的链表：\n");
  printList(l_t);  // 输出的值 0,1,2,3,4
  for (int i = 0; i < 4; i++) {
    l_t = delete_tail(l_t);
    printList(l_t);
  }
  printf("尾插法删除后的链表：\n");
  printList(l_t);  // 输出的值 0,1,2,3,4
  return 1;
}