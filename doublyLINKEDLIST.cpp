#include<stdio.h>
#include<stdlib.h>
int del();
int insert();
int createnode();  
int display();  

struct node{
	int data;
	struct node* next;
	struct node* prev;
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
					head->prev=newnode;
					newnode->next=head;
					head=newnode;
					break;
				case 2:
					tail->next= newnode;
					newnode->prev = tail;
					tail = newnode;
					break;
				case 3:
					{
						printf("Enter the position to insert the new element\n");
						int pos,i=1;
						scanf("%d",&pos);
						struct node* temp;
					//	struct node* bef;
						temp = head;
						if(pos==1)
						{
							head->prev = newnode;
							newnode->next=head;
							head = newnode;
						}
						else{
							while(i<pos && temp->next!=NULL)
							{
								temp=temp->next;
								i++;
							}
							if(temp->next==NULL)
							{
								temp->next = newnode;
								newnode->prev=temp;
								tail = newnode;
							}
							else{
								newnode->next = temp;
								newnode->prev = temp->prev;
								(temp->prev)->next = newnode;
								temp->prev = newnode;
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
					head = temp->next;
					free(temp);
					break;
				case 2:
					struct node* bef;
					bef = head;
					while(bef->next!=tail)
					{
						bef = bef->next;
					}
					temp = tail;
					tail = bef;
					bef->next = NULL;
					free(temp);
					break;
				case 3:
					{
						printf("Enter the position after which to delete the element\n");
						int pos,i=1;
						scanf("%d",&pos);
						struct node* bef;
						temp = head;
						if(pos==1)
						{
							head = temp->next;
							free(temp);
						}else{
							while(i<pos && temp->next!=NULL)
							{
								bef = temp;
								temp=temp->next;
								i++;
							}
							if(temp->next==NULL)
							{
								bef->next = NULL;
								tail = bef;
								free(temp);
							}
							else{
								bef->next = temp->next;
								temp->next->prev = bef;
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
		temp = temp->next;
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
	newnode->prev = NULL;
	newnode->next = NULL;
	return 0;
}
