#include<stdio.h>
#include<stdlib.h>
typedef struct{
int data;
struct Lnod *next;
}Lnod,*linklist;
void init(linklist L){
L=(linklist)malloc(sizeof(Lnod));
L->next=NULL;
}
void add(linklist l,int i,int e){
linklist p,q;
int j=0;
p=l;
while(p&&j<i-1){
p=p->next;
	++j;
}
if(!p||j>i)
exit(-1);
q=(linklist)malloc(sizeof(Lnod));
q->data=e;
q->next=p->next;
p->next=q;
}
void get(linklist l,int i){
linklist p;
int j=1;
p=l->next;
while(p&&j<i){
p=p->next;;
++j;
}
if(!p||j>i)
exit(-1);
printf("%d\n",p->data);
}
void change(linklist l,int i,int e){
int j=0;
linklist p;
p=l;
while(p&&j<i){
p=p->next;
	++j;
}
if(!p||j>i)
exit(-1);
p->data=e;
}
void del(linklist l,int i){
linklist p,q;
int j=0;
p=l;
while(p&&j<i-1){
p=p->next;
++j;
}
if(!p||j>i-1)
exit(-1);
q=p->next;
p->next=q->next;
free(q);
}
int main(){
Lnod l;
init(&l);
add(&l,1,10);
add(&l,1,20);
change(&l,1,1);
del(&l,2);
get(&l,1);
}