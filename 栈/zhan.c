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
printf("û��ջ��Ԫ��\n");
printf("ջ��Ԫ��Ϊ��  %d\n\n",*(s->top-1));
}
void push(zhan *s,int e){
*s->top++=e;
}
void pop(zhan *s){
printf("��ջԪ��Ϊ�� %d\n\n",*(--s->top));
}
int main(){
int n,e;
zhan s;
while(n!=5){
printf("1.����һ��ջ\n");
printf("2.��Ԫ����ջ\n");
printf("3.��Ԫ�س�ջ\n");
printf("4.�õ�ջ��Ԫ��\n");
printf("5.�˳�\n");
scanf("%d",&n);
switch(n){
case 1:
       init(&s);
	   printf("ջ�ѽ���������\n\n");
	   break;
case 2:
	   printf("������Ҫ��ջ��Ԫ�أ�  ");
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