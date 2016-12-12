#include<stdio.h>
#include<stdlib.h>
#define startsize 100
typedef struct{
int *top;
int *base;
int size;
}zhan;
void init(zhan *s){
s->base=(int *)malloc(startsize*sizeof(int));
if(!s)
printf("error");
s->top=s->base;
s->size=startsize;
}
void gettop(zhan *s){
if(s->top==s->base)
printf("没有栈顶元素\n");
printf("栈顶元素为：  %d\n\n",*(s->top-1));
}
void push(zhan *s,int e){
*s->top++=e;
}
void pop(zhan *s){
printf("出栈元素为： %d\n\n",*(--s->top));
}
int main(){
int n,e;
zhan s;
while(n!=5){
printf("1.建立一个栈\n");
printf("2.将元素入栈\n");
printf("3.将元素出栈\n");
printf("4.得到栈顶元素\n");
printf("5.退出\n");
scanf("%d",&n);
switch(n){
case 1:
       init(&s);
	   printf("栈已将创建好了\n\n");
	   break;
case 2:
	   printf("请输入要入栈的元素：  ");
	   scanf("%d",&e);
	   printf("\n");
	   push(&s,e);
	   break;
case 3:
	   pop(&s);
	   break;
case 4:
	   gettop(&s);
	   break;
}
}
}