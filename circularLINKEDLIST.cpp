#include<stdio.h>
#include<stdlib.h>
int del();
int insert();
int createnode();  
int display();  

struct node{
	int data;
	struct node* link;
};
struct node* newnode;
struct node* tail = NULL;
int option;
int main(){
	int loop =1;
	while(loop)
	{
		printf("Choose the option 1 to insert, 2 to display, 3 to delete an element, 4 to Quit\n");
		scanf("%d",&option);
		switch (option)
		{
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			case 3:
				del();
				break;
			case 4:
				loop = 0;
				break;
			default:
				printf("Not a valid option\n");		
		}
	}
	return 0;
}
int insert()
{
	createnode();
	if(tail==NULL)
	{
		tail = newnode;
		newnode->link = newnode;
	}
	else
	{
		printf("Choose the option 1 to insert at beginnig, 2 at end, 3 at a particular position\n");
		scanf("%d",&option);
		switch (option)
			{
				case 1:
					newnode->link= tail->link;
					tail->link = newnode;
					break;
				case 2:
					newnode->link= tail->link;
					tail->link = newnode;
					tail = newnode;
					break;
				case 3:
					{
						printf("Enter the position to insert the new element\n");
						int pos,i=1;
						scanf("%d",&pos);
						struct node* temp;
						struct node* prev;
						temp = tail->link;
						if(pos==1)
						{
							newnode->link=tail->link;
							tail->link = newnode;
						}
						else{
							if(temp==tail)
							{
								newnode->link= tail->link;
								tail->link = newnode;
								tail = newnode;
							}
							else{
								while(i<pos && temp!=tail)
							{
								prev = temp;
								temp=temp->link;
								i++;
							}
							if(temp==tail && i>pos)
							{
								newnode->link= tail->link;
								tail->link = newnode;
								tail = newnode;
								printf("hello\n");
							}
							else{
								newnode->link = temp;
								prev->link = newnode;
							}
							}
							
							}
						
						break;
					}
				default:
					printf("Not a valid option\n");
			}
	}
	return 0;
}
int del()
{
		printf("Choose the option 1 to delete at beginnig, 2 at end, 3 at a particular position\n");
		scanf("%d",&option);
		struct node* temp;
		switch (option)
			{
				case 1:
					temp = tail->link;
					tail->link = temp->link;
					free(temp);
					break;
				case 2:
					struct node* prev;
					prev = tail->link;
					while(prev->link!=tail)
					{
						prev = prev->link;
					}
					temp = tail;
					prev->link = temp->link;
					tail = prev;
					free(temp);
					break;
				case 3:
					{
						printf("Enter the position after which to delete the element\n");
						int pos,i=1;
						scanf("%d",&pos);
						struct node* prev;
						temp = tail->link;
						if(pos==1)
						{
							tail->link = temp->link;
							free(temp);
						}else{
							while(i<pos && temp!=tail)
							{
								prev = temp;
								temp=temp->link;
								i++;
							}
							if(temp==tail)
							{
								prev->link = tail->link;
								tail = prev;
								free(temp);
							}
							else{
								prev->link = temp->link;
								free(temp);
							}
						}
						
						break;
					}
				default:
					printf("Not a valid option\n");
			}
	return 0;
}
int display()
{
	struct node* temp;
	temp = tail->link;
	do
	{
		printf("%d\t", temp->data);
		temp = temp->link;
	}while(temp != tail->link);
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
