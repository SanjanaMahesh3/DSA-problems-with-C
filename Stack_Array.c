#include<stdio.h>
#include<stdlib.h>
int push(int *s, int *t, int size, int x);
void display(int *s, int *t);
int pop(int *s, int *t);
void rev(int *s,int t,int size);
void swap(int *s,int t,int t2);
void sort(int *s,int t);
int main()
{
	int size,top,ch,x,k;
	int *s;
	printf("enter the size of the stack\n");
	scanf("%d",&size);
	s=(int*) malloc(size*sizeof(int));
	top=-1;
	while(1)
	{
		//display(s,&top);
		printf("\n 1: PUSH\n");
		printf("\n 2: POP\n");
		printf("\n 3: REVERSE\n");
		printf("\n 4: DISP\n");
		printf("\n 5: SORT\n");
		printf("enter your choice\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("enter the element to push\n");
				scanf("%d",&x);
				k=push(s,&top,size,x);
				break;
			case 2: k = pop(s,&top);
				break;
			case 3: rev(s,top,size);
			        break;
			case 4: display(s,&top);
				break;
			case 5: sort(s,top);
				break;
		}
	}
}
int pop(int *s, int *t)
{
	int x;
	if(*t==-1)
		{
		printf("Stack is empty -- UNDERFLOW\n");
		return -1;
		}
	else
		{
			x = s[*t];
			(*t)--;
			return x;
		}

}






int push(int *s, int *t, int size, int x)
{
		if(*t==size-1)
		{
		printf("stack overflow\n");
		}
		else
		{

			(*t)++; // *t= *t+1,(*t)+=1, ++(*t)
			s[*t]=x;
			return x;
		}

}
void display(int *s, int *t)
{
	int i;
	if(*t==-1)
		printf("Stack is empty..underflow\n");
	else
		{
			for(i=*t;i>=0;i--)
			{
				printf("%d - ", s[i]);
			}
		}
}
void rev(int *s,int t,int size)
{
	int mid;
	if(size%2==0)
	{
		mid=((size-1)/2)+1;
		printf("Mid :%d\n",mid);
		int top2=0;
		do
		{
			swap(s,t,top2);
			printf("Top2 : %d\n",top2);
			top2++;
			(t)--;
		}while(top2!=mid);

	}
	else
	{
		//printf("Odd\n");
		mid=(size/2);
		printf("Mid :%d\n",mid);
		int top2=0;
		do
		{
			swap(s,t,top2);
			top2++;
			t--;
		}while(top2!=mid);

	}
}
void swap(int *s,int t,int t2)
{
	int x=s[t];
	s[t]=s[t2];
	s[t2]=x;
}
void sort(int *s,int t)
{
	//printf("Top : %d",t);
	do
	{
	for(int i=(t-1);i>=0;i--)
	{
		if(s[t]>s[i])
		{
			swap(s,t,i);
		}
	}
	t--;
}while(t!=-1);
}
