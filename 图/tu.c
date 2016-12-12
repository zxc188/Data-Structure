#include<stdio.h>
#include<stdlib.h>
int visit[100];
//邻接表存数结构
typedef struct Ar{
  int place;
  struct Ar *other;
}Ar;
typedef struct{
  char data;
  Ar *next;
}tu;
typedef struct{
tu adjust[100];
int vem,l;
}G;


//队列
typedef struct style{
int t;
struct style *next;
}style;
typedef struct{
style *top;
style *base;
}duilie;
void initduilie(duilie *s){
    s->top=(style *)malloc(100*sizeof(style));
	s->base=s->top;
	s->top->next=NULL;
}
void push(duilie *s,int l){
style *p;
p=(style *)malloc(sizeof(style));
p->t=l;
p->next=NULL;
s->base->next=p;
s->base=p;
}
int pop(duilie *s){
	int t;
t=s->top->next->t;
s->top=s->top->next;
return t;
}
//创建一个图
void init(G *g){
    int i=0,v1,v2;
	    Ar *a;
	char u='A';
	g->vem=7;
	g->l=8;
	for(;i<g->vem;i++){
	g->adjust[i].data=u;
	g->adjust[i].next=NULL;
	u++;
	}
	for(i=0;i<g->l;i++){
	  printf("请输入一条边的两端v1,v2,为v1->v2\n");
	  scanf("%d,%d",&v1,&v2);
      a=(Ar*)malloc(sizeof(Ar));
	  a->place=v2;
	  a->other=g->adjust[v1].next;
	  g->adjust[v1].next=a;
	}
	printf("您定义的图的邻接表为:\n");
	for(i=0;i<g->vem;i++){
	printf("%c\t",g->adjust[i].data);
	a=g->adjust[i].next;
	while(a){
	printf("%d\t",a->place);
	a=a->other;
	}
	printf("\n");
	}
}
void DFS(G g,int i){
	Ar *a;
printf("%c\t",g.adjust[i].data);
visit[i]=1;
a=g.adjust[i].next;
if(a&&visit[a->place]==0){
DFS(g,a->place);
}
}
//深度遍历
void shen(G g){
int i;
for(i=0;i<100;i++){
visit[i]=0;
}
for(i=0;i<g.vem;i++){
	if(!visit[i]){
	DFS(g,i);
	}
}
}
//广度优先
void guang(G g){
  Ar *a;
  int i,j;
  duilie s;
  initduilie(&s);
  for(i=0;i<100;i++){
  visit[i]=0;
  }
  for(i=0;i<g.vem;i++){
	  if(!visit[i]){
	  printf("%c\t",g.adjust[i].data);
	  visit[i]=1;
	  push(&s,i);
	  while(!(s.top==s.base)){
	  j=pop(&s);
	  a=g.adjust[j].next;
	  while(a){
		  if(!visit[a->place]){
		  printf("%c\t",g.adjust[a->place]);
		  visit[a->pla=ce]1;
		  push(&s,a->place);
		  }
		  a=a->other;
	  }
	  }
	  }
  }
}
int main(){
G g;
int n;
while(n!=4){
printf("1.生成一个树\n");
printf("2.深度遍历一个树\n");
printf("3.广度遍历一个树\n");
printf("4.退出\n");
scanf("%d",&n);
switch(n){
case 1:
	init(&g);
	break;
case 2:
	shen(g);
	break;
case 3:
	guang(g);
	break;
case 4:
	return 0;
}
}
}