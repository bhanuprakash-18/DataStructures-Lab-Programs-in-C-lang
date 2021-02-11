#include<stdio.h>
int enqueue();
int dequeue();
int peek();
int display();
int front=-1;
int rear=-1;
int q[100];
int n;

int main()
{
	int loop =1;
	int option;
	printf("Enter the size of the queue\n");
	scanf("%d",&n);
	while(loop)
	{
		printf("\n1.Enqueue, 2.Dequeue, 3.display, 4.Peek, 5.Quit\n");
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
				loop=0;
				break;
			default:
				printf("The option is not valid\n");
		}
		
	}
}

int enqueue()
{
	int x;
	
	if(rear==-1 && front == -1)
	{
		rear++;
		front++;
		printf("Enter the element\n");
		scanf("%d",&x);
		q[rear]=x;	
	}
	else
	{
		if((rear+1)%n==front)
			printf("The queue is full\n");
		else
		{
			rear = (rear+1)%n;
			printf("Enter the element\n");
			scanf("%d",&x);
			q[rear]=x;
		}
		
	}
	return 0;
}

int dequeue()
{
	if(rear==-1 && front == -1)
	{
		printf("The queue is empty");
	}
	else 
	{
	if(front==rear)
	{
		rear=front=-1;
	}
	else
	{
		front = (front+1)%n;
	}
	}
	return 0;
}
int peek()
{
	if(front==rear==-1)
	{
		printf("The queue is empty\n");
	}
	else
	printf("%d is the peek element",q[front]);
	return 0;
}

int display()
{
	if(front==rear==-1)
	printf("The queue is empty\n");
	else
	{	int temp=front;
			while(temp!=rear)
			{
				printf("%d\t",q[temp]);
				temp = (temp+1)%n;
			}
			printf("%d\t",q[rear]);
	}
}


