#include<stdio.h>
#include<stdlib.h>
int insertAtBegin();
int insertAtRear();
int deleteAtBegin();
int deleteAtRear();
int display();
int createnode();

struct node
{
	int data;
	struct node* link;
};
struct node* front=NULL;
struct node* rear=NULL;
struct node* temp;
struct node* newnode;
int option;
int main()
{
	int loop =1;
	while(loop)
	{
		printf("Choose the option 1 to insert at begin \n, 2 to insert at end\n, 3 to delete at begin\n, 4 to delete at rear\n, 5 to display\n, 6 to quit\n\n");
		scanf("%d",&option);
		switch (option)
		{
			case 1:
				insertAtBegin();
				break;
			case 2:
				insertAtRear();
				break;
			case 3:
				deleteAtBegin();
				break;
			case 4:
				deleteAtRear();
				break;
			case 5:
				display();
				break;
			case 6:
				loop = 0;
				break;
			default:
				printf("Not a valid option\n");		
		}
	}
	return 0;
}

int insertAtBegin()
{
	createnode();
	if(front==NULL)
	{
		front = newnode;
		rear = newnode;
		printf("hello");
	}
	else
	{
		newnode->link = front;
		front = newnode;
	}
}
int insertAtRear()
{
	createnode();
	if(front==NULL)
	{
		front = newnode;
		rear = newnode;
	}
	else
	{
		rear->link = newnode;
		rear = newnode;
	}
	return 0;
}

int deleteAtBegin()
{
	if(front==NULL)
	{
		printf("DEQUE is empty\n");
	}
	else
	{
		temp = front;
		front = front->link;
		free(temp);
	}
	return 0;
}
int deleteAtRear()
{
	if(front==NULL)
	{
		printf("DEQUE is empty\n");
	}
	else
	{
		temp = front;
		if(temp->link==NULL)
		{
			free(temp);
			front = NULL;
		}
		else
		{	
			while(temp->link!=rear)
			{
				temp = temp->link;
			}
			rear = temp;
			temp = temp->link;
			rear->link = NULL;
			free(temp);
		}
		
	}
	return 0;
}
int display()
{
	if(front==NULL)
	{
		printf("The DEQUE is empty\n");
	}
	else
	{
		temp = front;
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp = temp->link;
		}
	}
	return 0;
}

int createnode()
{
	int ele;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data\n");
	scanf("%d",&ele);
	newnode->data = ele;
	newnode->link = NULL;
	return 0;
}
