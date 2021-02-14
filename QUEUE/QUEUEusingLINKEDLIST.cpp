#include<stdio.h>
#include<stdlib.h>
int enqueue();
int dequeue();
int peek();
int display();
int len();

struct node
{
	int data;
	struct node* link;
};
struct node* front = NULL;
struct node* rear = NULL;
struct node* temp = NULL;
struct node* newnode;

int main()
{
	int loop =1;
	int option;
	while(loop)
	{
		printf("\n1.Enqueue, 2.Dequeue, 3.display, 4.Peek, 5.length, 6.Quit\n");
		printf("Choose the option\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				peek();
				break;
			case 5:
				len();
				break;
			case 6:
				loop=0;
				break;
			default:
				printf("The option is not valid\n");
		}
		
	}
	return 0;
}

int createnode()
{
	int ele;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data\n");
	scanf("%d", &ele);
	newnode->data = ele;
	newnode->link= NULL;
	return 0;
}
int enqueue()
{
	createnode();
	if(front==NULL)
	{
		front = newnode;
		rear = newnode;
		rear->link=newnode;
	}
	else
	{
		rear->link = newnode;
		rear = newnode;
		newnode->link=front;
	}
	return 0;
}

int dequeue()
{
	if(front==NULL)
	{
		printf("The queue is empty\n");
	}
	else{
		temp = front;
		front= front->link;
		rear->link = front;
		free(temp);
		if(front == rear)
		{
			front->link=NULL;
		}
		
	}
	return 0;
}
int display()
{
	temp=front;
	if(temp==NULL)
	{
		printf("The queue is empty\n");
	}
	else{
		while(temp!=rear)
		{
			printf("%d\t",temp->data);
			temp = temp->link;
		}
		printf("%d\t",rear->data);
	}
	
	return 0;
}
int peek()
{
	if(front==NULL)
	{
		printf("The queue is empty\n");
	}
	else
	printf("%d is the peek value", front->data);
}
int len()
{
	temp=front;
	if(temp==NULL)
	{
		printf("The queue is empty\n");
	}
	else{
			int count=1;
		while(temp!=rear)
		{
			temp=temp->link;
			count++;
		}
		printf("%d\t is the length of the queue\n",count);
	}
	return 0;
}

