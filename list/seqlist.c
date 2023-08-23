# include <stdio.h>
# include <stdlib.h>

//初始化 
#define ERROR 0  //错误 
#define OK 1 	//正确
#define Overflow 2 //上溢 
#define Underflow 3 //下溢 
#define NotPresent 4 //元素不存在 
#define Duplicate 5 //有重复元素 
 
//转换数据类型 
typedef int ElemType;
typedef int status; 

//定义顺序表结构体 
typedef struct seqlist
{
	int n;		 	//长度 
	int maxlength; 	//最大允许长度 
	ElemType *element; 	//elemtype为自定义类型 
}Seqlist;

//初始化分配空间 
status Init(Seqlist *L,int mSize)
{
	L->maxlength = mSize;
	L->n = 0;
	L->element=(ElemType*)malloc(sizeof(ElemType)*mSize);
	if(!L->element)
		return ERROR;
	return OK;
}
//查找运算,查找ai 
status Find(Seqlist *L,int i,ElemType *x)
{
	if(i<0 || i>L->n-1)		//判断是否越界 
		return ERROR; 	
	*x = L->element[i];  //通过x返回参数 
	return OK;
 } 
//插入运算，在ai处插入元素x 
status Insert(Seqlist *L,int i,ElemType x)
{
	int j;
	if(i<-1 || i>L->n-1)
		return ERROR;
	if(L->n == L->maxlength)
		return ERROR;
	for(j = L->n-1;j>i;j--)
	{
		L->element[j+1] = L->element[j];
	}
	L->element[i+1] = x;
	L->n++;
	return OK;
 } 
 //删除运算
 status Delete(Seqlist *L,int i)
 {
 	int j;
	if(i<0 || i>L->n-1)
		return ERROR;
	if(!L->n)
		return ERROR;
	for(j=i+1;j<L->n-1;j++)
		L->element[j-1] =L->element[j];
	L->n--;
 	return OK;
 }
//输出运算 
status Output(Seqlist *L)
{
	int i;
	if(L->n == 0)
		return ERROR;
	for(i=0;i<L->n;i++)
	{
		printf("%d ",L->element[i]);
	}
	printf("\n");
	return OK;
}

//撤销运算
void Destroy(Seqlist *L)
{
	free(L->element);
	L->maxlength = 0;
	L->n = 0;
 } 
int main()
{
	int i;
	Seqlist list;
	Init(&list,10);
	for(i=0;i<10;i++)
	{
		Insert(&list,i-1,i);
	}
	Output(&list);
	Delete(&list,0);
	Output(&list);
	Destroy(&list);
 } 

