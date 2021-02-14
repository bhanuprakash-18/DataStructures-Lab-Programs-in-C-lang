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
struct node* head=NULL;;
struct node* newnode;
struct node* tail;
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
	if(head==NULL)
	{
		head = newnode;
		tail = newnode;
	}
	else
	{
		printf("Choose the option 1 to insert at beginnig, 2 at end, 3 at a particular position\n");
		scanf("%d",&option);
		switch (option)
			{
				case 1:
					newnode->link=head;
					head=newnode;
					break;
				case 2:
					tail->link= newnode;
					tail = newnode;
					break;
				case 3:
					{
						printf("Enter the position to insert the new element\n");
						int pos,i=1;
						scanf("%d",&pos);
						struct node* temp;
						struct node* prev;
						temp = head;
						if(pos==1)
						{
							newnode->link=temp;
							head = temp;
						}
						else{
							while(i<pos-1 && temp->link!=NULL)
							{
								prev = temp;
								temp=temp->link;
							}
							if(temp->link==NULL)
							{
								temp->link=newnode;
								tail = newnode;
							}
							else{
								newnode->link = temp;
							prev->link = newnode;
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
					temp = head;
					head = temp->link;
					free(temp);
					break;
				case 2:
					struct node* prev;
					prev = head;
					while(prev->link!=tail)
					{
						prev = prev->link;
					}
					temp = tail;
					tail = prev;
					prev->link = NULL;
					free(temp);
					break;
				case 3:
					{
						printf("Enter the position after which to delete the element\n");
						int pos,i=1;
						scanf("%d",&pos);
						struct node* prev;
						temp = head;
						if(pos==1)
						{
							head = temp->link;
							free(temp);
						}else{
							while(i<pos && temp->link!=NULL)
							{
								prev = temp;
								temp=temp->link;
							}
							if(temp->link==NULL)
							{
								prev->link = NULL;
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
	temp = head;
	while(temp != NULL)
	{
		printf("%d\t", temp->data);
		temp = temp->link;
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
