#include<stdio.h>
#include<stdlib.h>
#define startsize 100
#define addsize 10
typedef struct{
int *ele;
int length;
}student;
void init(student *s){
s->ele=(int *)malloc(startsize*sizeof(int));
s->length=0;
}
void add(student *s,int i,int e){
int j;
j=s->length;
for(;j>=i;j--){
s->ele[j]=s->ele[j-1];
}
s->ele[i-1]=e;
s->length++;
}
int get(student *s,int i){
     if(i<0||i>s->length)
		 exit(-1);
	return s->ele[i-1];
}
void change(student *s,int i,int e){
if(i<0||i>s->length)
exit(-1);
s->ele[i-1]=e;
}
void del(student *s,int i){
	for(;i<=s->length;i++){
	s->ele[i-1]=s->ele[i];
	}
}
int main(){
student s;
init(&s);
add(&s,1,10);
add(&s,1,5);
change(&s,1,15);
del(&s,1);
printf("%d\n",get(&s,1));
}
