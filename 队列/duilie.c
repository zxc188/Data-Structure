#include<stdio.h>
#include<stdlib.h>
typedef struct Lnode{
int data;
struct Lnode *next;
}Lnode;
typedef struct{
Lnode *top;
Lnode *base;
}Q;
void init(Q *s){
s->top=(Lnode*)malloc(100*sizeof(Lnode));
s->base=s->top;
s->top->next=NULL;
}
void push(Q *s,int e){
Lnode *p=(Lnode*)malloc(sizeof(Lnode));
p->data=e;
s->base->next=p;
s->base=p;
}
void pop(Q *s){
	if(s->top==s->base)
		exit(-1);
printf("出对元素为：  %d\n\n",s->top->next->data);
s->top=s->top->next;
}
int main(){
Q s;
int n,e;
while(n!=4){
printf("1.建立一个队列\n");
printf("2.将元素入队\n");
printf("3.将元素出对\n");
printf("4.退出\n");
scanf("%d",&n);
switch(n){
case 1:
      init(&s);
	  printf("队列已经创建好了\n\n");
	  break;
case 2:
      printf("请输入要插入的元素:   ");
	  scanf("%d",&e);
      push(&s,e);
	  printf("\n");
	  break;
case 3:
      pop(&s);
	  break;
}
}
}