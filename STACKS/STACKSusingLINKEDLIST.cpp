#include<stdio.h>
#include<stdlib.h>
int push();
int pop();
int topele();
int len();
int display();
int createnode();
int choice;
struct node* temp;
struct node{
	int data;
	struct node* link;
};
struct node* top;
struct node* newnode;
int main()
{
	top = NULL;
	int loop = 1;
	while(loop)
		{
			printf("Choose the option 1 to push, 2 to pop, 3 to top, 4 to display, 5 to quit\n");
			scanf("%d",&choice);
				switch (choice)
			{
				case 1:
					push();
					break;
				case 2:
					pop();
					break;
				case 3:
					topele();
					break;
				case 4:
					display();
					break;
				case 5:
					loop=0;
					break;
				default:
					printf("Option selected not valid\n");
			}				
		}
}

int push()
{
	createnode();
	if(top==NULL)
	{
		top = newnode;
	}
	else{
		newnode->link = top;
		top = newnode;
	}

	return 0;
}
int pop()
{
	if(top==NULL)
	{
		printf("The stack is empty\n");
	}
	else{
		temp = top;
		top = top->link;
		free(temp);
	}
	return 0;
}
int topele()
{
	if(top==NULL)
	{
		printf("The stack is empty\n");
	}
	else{
		printf("%d is the top element and is %d th element\n", top->data,len());
	}
	return 0;
}
int len()
{
	temp = top;
	int i=0;
	while(temp!=NULL)
	{
		i++;
		temp = temp->link;
	}
	return i;	
}
int display()
{
	if(top==NULL)
	{
		printf("The stack is empty\n");
	}
	else
	{
		temp =top;
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
	int element;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data\n");
	scanf("%d", &element);
	newnode->data=element;
	newnode->link = NULL;
	return 0;
}
