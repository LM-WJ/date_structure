# include <stdio.h>
# include <stdlib.h>

//��ʼ�� 
#define ERROR 0  //���� 
#define OK 1 	//��ȷ
#define Overflow 2 //���� 
#define Underflow 3 //���� 
#define NotPresent 4 //Ԫ�ز����� 
#define Duplicate 5 //���ظ�Ԫ�� 
 
//ת���������� 
typedef int ElemType;
typedef int status; 

//����˳���ṹ�� 
typedef struct seqlist
{
	int n;		 	//���� 
	int maxlength; 	//��������� 
	ElemType *element; 	//elemtypeΪ�Զ������� 
}Seqlist;

//��ʼ������ռ� 
status Init(Seqlist *L,int mSize)
{
	L->maxlength = mSize;
	L->n = 0;
	L->element=(ElemType*)malloc(sizeof(ElemType)*mSize);
	if(!L->element)
		return ERROR;
	return OK;
}
//��������,����ai 
status Find(Seqlist *L,int i,ElemType *x)
{
	if(i<0 || i>L->n-1)		//�ж��Ƿ�Խ�� 
		return ERROR; 	
	*x = L->element[i];  //ͨ��x���ز��� 
	return OK;
 } 
//�������㣬��ai������Ԫ��x 
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
 //ɾ������
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
//������� 
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

//��������
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

