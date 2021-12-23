//Linked List :
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void display(struct node *p);
void insert_front(struct node **p, int x);
void insert_end(struct node **p, int x);
void del_front(struct node **p);
void del_end(struct node **p);
void pos_ins(struct node **p, int x, int pos);
void pos_del(struct node **p, int pos);
void reverse(struct node **p);
int main()
{
	int ch,x,pos;
	struct node *first;
	first=NULL;
	while(1)
	{
	display(first);
	printf("\n 1: FRONT INSERTION\n");
	printf("2 : END INSERTION\n");
	printf("3 : FRONT DELETION\n");
	printf("4 : END DELETION\n");
	printf("5 : POSITION INSERTION\n");
	printf("6 : POSITION DELETION\n");
	printf("7: REVERSE\n");
	printf("enter your choice\n");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1: printf("enter the value\n");
			scanf("%d", &x);
			insert_front(&first,x);
				break;
		case 2: printf("enter the value\n");
			scanf("%d", &x);
			insert_end(&first,x);
				break;

		case 3: del_front(&first); break;

		case 4: del_end(&first); break;

		case 5 : printf("enter the value of node and its position\n");
			scanf("%d%d",&x,&pos);
			pos_ins(&first,x,pos);break;
		case 6: printf("enter the pos\n");
			scanf("%d",&pos);
			pos_del(&first, pos);
			break;

		case 7 : reverse(&first); break;
		case 8: display(first);
				break;
		case 10: exit(0);

	}//switch
	}//while

}//main
void reverse(struct node **p)
{
	struct node *temp, *prev, *pres;
	prev=NULL;
	pres=*p;

	while(pres!=NULL)
	{
		temp=pres->next;
		pres->next=prev;
		prev=pres;
		pres=temp;
	}
	*p=prev;
}














void pos_del(struct node **p, int pos)
{
	struct node *prev, *pres;
	int i=1;
	prev=NULL;
	pres=*p;
	while(pres!=NULL && i<pos)
	{
		prev=pres;
		pres=pres->next;
		i++;
	}
	if(pres==NULL)
	printf("Invalid pos\n");

	else if(prev==NULL)
	{
		*p = pres->next;
		printf("deleted node is %d\n", pres->data);
		free(pres);
	}
	else
	{
		prev->next=pres->next;
		printf("deleted node is %d\n", pres->data);
		free(pres);
	}



}


void pos_ins(struct node **p, int x, int pos)
{
	struct node *temp, *prev, *pres;
	int i;
	temp = (struct node*) malloc(sizeof (struct node));
	temp->data = x;
	temp-> next = NULL;
	i=1;
	prev=NULL;
	pres = *p;

	while(pres!=NULL && i<pos)
	{
		prev=pres;
		pres=pres->next;
		i++;
	}
	if(pres!=NULL)
	{
		if(prev==NULL)
		{
			temp->next=pres;
			*p=temp;
		}
		else
		{
			prev->next=temp;
			temp->next=pres;
		}
	}
	else
	{
		if (pos==i)
		{
			if(prev==NULL)
				{
					temp->next=*p;
					*p=temp;
				}
			else
				{
					prev->next=temp;
					temp->next=NULL;
				}
		}
		else
			printf("invalid pos\n");
	}
}
void del_end(struct node **p)
{
	struct node *prev, *pres;
	pres=*p;
	prev=NULL;
	if (*p == NULL)
		printf("list is empty\n");
	else if ((*p)->next == NULL)
		{
			*p=NULL;
			printf("deletd node value is %d\n", pres->data);
			free(pres);
		}
	else
	{
		while(pres->next!=NULL)
		{
			prev=pres;
			pres=pres->next;
		}
		prev->next = NULL;
		printf("deleted node value is %d\n", pres->data);
		free(pres);

	}

}






void del_front(struct node **p)
{
	struct node *pres;
	pres=*p;
	if(*p==NULL)
		printf("List is empty\n");
	else
		{
			*p = (*p)->next;
			printf("deleted node is %d\n", pres->data);
			free(pres);
		}
}






void display(struct node *p)
{
	if(p== NULL)
		printf("List is empty\n");
	else
	{
		while(p!=NULL)
		{
			printf("%d -> ", p->data);
			p=p->next;
		}
	}
}
void insert_front(struct node **p, int x)
{
	struct node *temp;
	temp = (struct node*) malloc(sizeof (struct node));
	temp->data = x;
	temp-> next = NULL;

	if(*p==NULL)
		*p = temp;
	else
		{
			temp->next = *p;
			*p=temp;
		}
}

void insert_end(struct node **p, int x)
{
	struct node *temp, *q;
	temp = (struct node*) malloc(sizeof (struct node));
	temp->data = x;
	temp-> next = NULL;

	if(*p==NULL)
		*p = temp;
	else
		{
			q=*p;
			while(q->next!=NULL)
				q=q->next;

				q->next=temp;
		}
}
void un()
