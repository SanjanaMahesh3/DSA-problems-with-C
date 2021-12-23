#include<stdio.h>
#include<stdlib.h>
int insert_rear(int *q, int *f, int *r, int size, int x);
int delete_front(int *q, int *f, int *r, int size);
void display(int *q, int f, int r, int size);

int main()
{
	int *q;
	int f,r,size,ch,x,k;
	f=-1;
	r=-1;
	printf("enter the size of Q\n");
	scanf("%d",&size);
	q=(int*)malloc(size*(sizeof(int)));
	while(1)
	{
		display(q,f,r,size);
		printf("\n1: Insert Rear\n");
		printf("2:Delete front\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("enter the value of x\n");
			scanf("%d",&x);
			k=insert_rear(q,&f,&r,size,x);
			break;

			case 2:k=delete_front(q,&f,&r,size);
			break;

		}
	}

}
int insert_rear(int *q, int *f, int *r, int size, int x)
{
	if((*r+1) % size == *f)
	{
		printf(" Q is full\n");
		return -1;
	}
	*r = (*r+1)%size;
	q[*r]=x;
		if(*f==-1)
		*f=0;
	return 1;
}


int delete_front(int *q, int *f, int *r, int size)
{

	int x;
	if(*f==-1)
		{
			printf("Q is Empty\n");
			return -1;
		}
	x=q[*f];
	if(*f==*r)
		*f=*r=-1;
	else
		*f=(*f+1)%size;
	return x;
}
void display(int *q, int f, int r, int size)
{
	int i;
	if(f==-1)
		printf("Q is empty\n");
	else
	{
		while(f!=r)
		{
			printf("%d - ", q[f]);
			f=(f+1)%size;
		}
		printf("%d - ", q[f]);
	}
}
