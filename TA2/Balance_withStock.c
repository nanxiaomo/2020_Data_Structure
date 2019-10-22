#include <stdio.h>
#define SIZE 100
unsigned char stack[SIZE];
int sp;
void int_stack() { sp = SIZE; }
// 进栈
int push(unsigned char data) {
  if (sp < 0) return -1;
  --sp;
  stack[sp] = data;
  return 1;
}
// 出栈
int pop(void) {
  unsigned char data;
  if (sp < 0) {
    return -1;
  }
  data = stack[sp];
  ++sp;
  return data;
}
// 计算栈中高度
int depth(void) { return SIZE - sp; }
int balance(unsigned char *p) {
  unsigned char c;
  int_stack();
  for (; (c = *p) != '\0'; p++) {
    switch (c) {
      case '(':
      case '[':
      case '{':
        push(c);
        break;
      case ')':
        if (depth() == 0 || pop() != '(') {
          return 0;
        }
        break;
      case ']':
        if (depth() == 0 || pop() != '[') {
          return 0;
        }
        break;
      case '}':
        if (depth() == 0 || pop() != '{') {
          return 0;
        }
        break;

      default:
        break;
    }
  }
  if (depth() == 0) {
    return 1;
  } else {
    return 0;
  }
}
/*第一问验证结果
int main(void) {
    int_stack();
    push('(');
    push('(');
    push('[');
    push('{');
    printf("%c\n",pop());
    printf("%c\n",pop());
    printf("%c\n",pop());
    printf("%c\n",pop());
    return 1;
}
*/

int main(void) {
  unsigned char *input0 = "{a({}))b";
  unsigned char *input1 = "{a({)})b";
  unsigned char *input2 = "][";
  unsigned char *input3 = "[]";
  printf("%d\n", balance(input0));
  printf("%d\n", balance(input1));
  printf("%d\n", balance(input2));
  printf("%d\n", balance(input3));
  return 1;
}