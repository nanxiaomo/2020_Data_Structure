#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 24

struct buffer{
    char store[BUFSIZE];
    int head,tail;
};
typedef struct buffer *BUFF;

int put_str(struct buffer *buf,char *str){
    int i = buf->tail;
    while(i - buf-> head <BUFSIZE) {
        buf->store[i++% BUFSIZE] = *str;
        if(*str == '\0'){
            buf->tail = i;
            return 1;
        }else{
            str++;
        }
    }
    return 0;
}

int get_str(struct buffer *buf,char *dest){
    int i = buf->head;
    if(i == buf->tail) return 0;
    do {
        // 有疑问
        *dest = buf->store[i++%BUFSIZE];
        //*dest = *(dest++);
    }while(*dest++!='\0');
    buf->head = i;
    return 1;
}
/*
* 打印出buf中信息
*/
void print_buf(struct buffer *buf) {
    printf("buffer 中的head：%d\n",buf->head);
    printf("buffer 中的的tail：%d\n",buf->tail);
    for (int i= 0;i<BUFSIZE;i++){
        printf("%c",buf->store[i]);
    }
	printf("\n");
}
int main()
{

    BUFF buf1 = (BUFF) malloc(sizeof(struct buffer));
    buf1->head = 12;
    buf1->tail = 12;
	char *dest = (char*)malloc(sizeof(char)*BUFSIZE);
    put_str(buf1,"ten");
    print_buf(buf1);
    put_str(buf1,"six");
    print_buf(buf1);
    put_str(buf1,"three");
    print_buf(buf1);
    put_str(buf1,"four");
    print_buf(buf1);
    put_str(buf1,"seven");
    print_buf(buf1);
    put_str(buf1,"two");
    print_buf(buf1);
    put_str(buf1,"eight");
    print_buf(buf1);
	get_str(buf1,dest);
	print_buf(buf1);
	get_str(buf1,dest);
	print_buf(buf1);
	for(int i=0; i<BUFSIZE;i++){
        printf("%c", dest[i]);
	}
    return 0;
}
