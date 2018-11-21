/*
	数据结构练习1
*/


#include <stdio.h>
#define MAXSIZE 100
/*
	定义一个结构体，elem表示任意类型顺序存储数组，last表示最大下标
*/
typedef struct{
	int elem[MAXSIZE];
	int last;
}seq;
/*
	Ins函数用来在数组中插入e，并保持数组正序
*/
seq* Ins(seq * p_seq,const int e)
{
/*
	确定插入的位置i
*/
	int i = 0;
	while((i < (p_seq->last+1))&&e >= (p_seq->elem[i]))
		i++;
	int j = p_seq->last - i + 1;
	for(int k = 0;j >= 0;j--){
		p_seq->elem[p_seq->last-k+1]=p_seq->elem[p_seq->last-k];
		k++;}
	p_seq->elem[i]=e;
	p_seq->last++;
	return p_seq;		
}
int main()
{	
	seq L={{1,2,3,4,5,6,7,8,9},8};
	seq* p_L = Ins(&L,1);
	for(int i=0;i<=p_L->last;i++)
		printf("%d\n",p_L->elem[i]);
	return 0;
}
