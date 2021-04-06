#include<stdio.h> 
#include<stdlib.h> 
typedef struct node* nptr; 
typedef struct node{
	int data;
	nptr link;
}NODE; 
void insert(nptr* head, int data)
{
	nptr new;
	nptr temp;
	int change; 
	int count = 0,i;
	new = (nptr)malloc(sizeof(NODE)); 
	new->link = NULL;
	new->data = data; 
	if(*head==NULL)
	{
		*head = new;
		count++; 
	}
	else
	{
		for(temp = *head;temp->link!=NULL; temp=temp->link);
		temp->link = new; 
		count++;
	for(i=0;i<count;i++){
	for(temp = *head; temp->link!=NULL;temp=temp->link)
	{
		if((temp->data) > (temp->link->data))
		{
			change = temp->data;
			temp->data = temp->link->data;
			temp->link->data = change;
		}
	}
	}
	}

}
void printAll(nptr head)
{	
	nptr temp;
	for(temp = head; temp!=NULL; temp=temp->link)
		printf("%d ",temp->data);
}
int main()
{
	nptr head; 
	head = NULL; 
	int n; 
	scanf("%d", &n); 
	int i =0;
	int j; 
	for(i; i<n; i++)
	{
		scanf("%d",&j);
		insert(&head,j);
	}
	printAll(head);
	printf("\n");
	return 0;
}
