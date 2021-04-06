#include<stdio.h> 
#include<stdlib.h> 
typedef struct node* nptr; 
typedef struct node{
	char value; 
	struct node* next; 
	struct node* prev;
}NODE; 

void insert(nptr* head, char data)
{
	nptr new;
	nptr temp; 
	new = (nptr)malloc(sizeof(NODE)); 
	new -> value = data; 
	if(*head == NULL)
	{
		new -> next = NULL; 
		new -> prev = NULL;
		(*head) = new;  
	}
	else
	{
		new -> next = NULL;
		for(temp = *head;temp->next!=NULL;temp=temp->next);
		temp -> next = new; 
		new -> prev = temp;
	}
}
void moveLeft(nptr* head, nptr* cursor)
{
	nptr temp; 
	if((*cursor)->prev==NULL)
	{
		return;  
	}
	else if(*cursor ==NULL)
	{
		for(temp = *head; temp!=NULL; temp=temp->next);
		*cursor = temp; 
	}
	else 
		*cursor = (*cursor) -> prev; 
}
void moveRight(nptr* head, nptr* cursor)
{
	if(*cursor ==NULL)
	{
		return;
	}
	else 				 
		*cursor  = (*cursor) -> next; 
}
void delete(nptr* head, nptr* cursor)
{
	nptr temp; 
	if((*cursor)->prev ==NULL )
		return;
	else if(*cursor==NULL)
	{
		for(temp = *head; temp!=NULL; temp=temp->next);
		(temp->prev)->next = NULL; 
		free(temp); 
	}
	else
	{
		temp = (*cursor) -> prev; 
		if(temp -> prev = NULL)
		{
			(*cursor) -> prev = NULL; 
			*head = *cursor; 
			free(temp);
		}
		else 
			temp -> prev -> next = temp -> next; 
			(*cursor) -> prev = temp -> prev;
			free(temp);
	}
}
void charadd(nptr* head, nptr* cursor, char c)
{
	int i = 0;
	nptr new; 
	nptr temp;
	new = (nptr)malloc(sizeof(NODE)); 
	new -> value = c;
	printf("%c", (*head)->value);
	printf("%p", *cursor);
	if(*cursor==NULL)
	{
		for(temp = *head; temp!=NULL; temp = temp->next);
		temp ->next = new; 
		new -> prev = temp; 
		new -> next = NULL; 
	}
	else if((*cursor)->prev ==NULL)
	{
		new -> prev = NULL; 
		new -> next = (*cursor);
		(*cursor) -> prev = new; 
		*head = new; 
	}
	else{
		new -> prev = (*cursor) -> prev;
		(*cursor)->prev->next = new; 
		(*cursor)->prev = new;
		new -> next = (*cursor); 
	}
}
int main()
{
	char sen[3001]; 
	int n,i=0; 
	int check =0;
	char m;
	char ad[1000]; 
	char c;
	nptr head = NULL;
	nptr temp; 
	nptr cursor = NULL;
	fgets(sen, 3001, stdin); 
	while(sen[i]!='\0')
	{
		insert(&head,sen[i]);
		i++; 
	}
	scanf("%d", &n); 
	for(i = 0; i<n;i++)
	{
		getchar();
		scanf("%c",&m);
		if(m=='A')
		{
			//fgets(ad, 1000, stdin);
			//while(ad[check]!='\0')
			//{
				printf("a");
				charadd(&head, &cursor, 'c');
				check++;
			//}
		}
		else if(m=='L')
		{
			moveLeft(&head,&cursor);
		}
		else if(m=='R')
		{
			moveRight(&head,&cursor);
		}
		else if(m=='B')
		{
			delete(&head, &cursor);
		}
	}
	for(temp = head; temp!=NULL; temp = temp->next)
	{
		printf("%c",temp->value);
		free(temp); 
	}
	return 0;
} 
