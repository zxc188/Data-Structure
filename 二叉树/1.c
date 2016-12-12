#include<stdio.h>
#include<stdlib.h>
typedef struct Tree{
int data;
struct Tree *zchild;
struct Tree *ychild;
}Tree;

//����
typedef struct{
  Tree data;
  Tree *next;
}L;
typedef struct {
L *base;
L *top;
}duilie;
void initduilei(duilie *d){
d->top=(L*)malloc(100*sizeof(L));
d->base=d->top;
}
void rudui(duilie *d,Tree t){
L *p=(L*)malloc(sizeof(L));
p->data=t;
d->base->next=p;
d->base=p;
}
Tree chudui(duilie *d){
	Tree f;
d->top=d->top->next;
f=d->top->data;
return f;
}
int isornot(duilie *d){
	if(d->top==d->base){
	return 1;
	}else{
	return 0;
	}
}

//ջ
typedef struct{
Tree *base;
Tree *top;
int size;
}zhan;
void initzhan(zhan *s){
	s->base=(Tree *)malloc(100*sizeof(Tree));
	if(!s)
		exit(-1);
s->top=s->base;
s->size=100;
}

Tree* gettop(zhan *s){
if(s->top==s->base)
exit(-1);
return s->top-1;
}

void pop(zhan *s){
--s->top;
}

void push(zhan *s,Tree t){
*s->top=t;
++s->top;
}
int isempty(zhan *s){
	if(s->top==s->base){
    return 1;
	}else{
	return 0;
	}
}

//��
void init(Tree *s){
	int i;
Tree *a[9];
for(i=0;i<9;i++){
a[i]=(Tree *)malloc(sizeof(Tree));
a[i]->data=i;
}
s->data=10;
s->zchild=a[8];
s->ychild=a[6];
a[8]->zchild=a[4];
a[8]->ychild=a[0];
a[6]->zchild=NULL;
a[6]->ychild=a[5];
a[4]->zchild=a[3];
a[4]->ychild=NULL;
a[0]->ychild=a[2];
a[0]->zchild=NULL;
a[5]->ychild=a[1];
a[5]->zchild=a[7];
a[3]->zchild=NULL;
a[3]->ychild=NULL;
a[2]->zchild=NULL;
a[2]->ychild=NULL;
a[7]->zchild=NULL;
a[7]->ychild=NULL;
a[1]->zchild=NULL;
a[1]->ychild=NULL;
}
//ǰ������ĵݹ��㷨
void pre_traverse(Tree *pTree)  
{  
    if(pTree)  
    {  
        printf("%d  ",pTree->data);  
        if(pTree->zchild)  
            pre_traverse(pTree->zchild);  
        if(pTree->ychild)  
            pre_traverse(pTree->ychild);      
    }  
}  
//ǰ������ķǵݹ��㷨
void qian(Tree *tree){
   zhan s;
   Tree *now;
initzhan(&s);
now=tree;
while(now||!isempty(&s)){
printf("%d  ",now->data);
push(&s,*now);
now=now->zchild;
while(!now&&!isempty(&s)){
now=gettop(&s);
now=now->ychild;
pop(&s);
}
}

}
//��������ĵݹ��㷨
void in_traverse(Tree *s){
	if(s){
		if(s->zchild){
		in_traverse(s->zchild);
		}
		printf("%d  ",s->data);
        if(s->ychild){
		in_traverse(s->ychild);
		}
	}
}

//��������ķǵݹ��㷨
void zhong(Tree *tree){
zhan s;
Tree *now;
initzhan(&s);
now=tree;
while(now || !isempty(&s)){
	if(now->zchild){
	push(&s,*now);
	now=now->zchild;
	}
    else{
	printf("%d  ",now->data);
	now=now->ychild;
	while(!now&&!isempty(&s)){
	now=gettop(&s);
	pop(&s);
	printf("%d  ",now->data);
	now=now->ychild;
	}
	}
}


	
}
//��������ĵݹ��㷨
void beh_traverse(Tree *s){
	if(s){
		if(s->zchild){
		beh_traverse(s->zchild);
		}
        if(s->ychild){
		beh_traverse(s->ychild);
		}
		printf("%d  ",s->data);
	}
}
//��������ķǵݹ��㷨
void ceng(Tree *s){
duilie d;
initduilei(&d);
rudui(&d,*s);
while(!isornot(&d)){
Tree g;
g=chudui(&d);
printf("%d  ",g.data);
if(g.zchild){
rudui(&d,*g.zchild);
}
if(g.ychild){
rudui(&d,*g.ychild);
}
}
}
int main(){
Tree c;
int k;

while(k!=5){
printf("0.����һ����\n");
printf("1.ǰ�����һ����\n");
printf("2.�������һ����\n");
printf("3.�������һ����\n");
printf("4.�������һ����\n");
printf("5.�˳�\n");
scanf("%d",&k);
switch(k){
case 0:
       init(&c);
	   printf("���Ѿ���������\n\n");
	   break;
case 1:
	   printf("ǰ�����Ϊ:\n");
	   qian(&c);
	   printf("\n\n");
	   break;
case 2:
	   printf("�������Ϊ:\n");
	   zhong(&c);
	   printf("\n\n");
	   break;
case 3:
	  printf("�������Ϊ:\n");
	  beh_traverse(&c);
	  printf("\n\n");
	  break;
case 4:
	  printf("�������Ϊ:\n");
	  ceng(&c);
	  printf("\n\n");
	  break;
}
}
return 0;
}