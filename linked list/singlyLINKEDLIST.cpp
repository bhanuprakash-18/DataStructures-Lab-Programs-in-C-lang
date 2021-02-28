#include<stdio.h>
#include<stdlib.h>
void del();
void insert();
void createnode();
void display();
int length();
int option,pos;
struct node{
	int data;
	struct node* link;
}*head=NULL,*newnode,*temp;

int main(){
	while(1){
		printf("\n\n****Choose the option***\n 1 to insert\n 2 to display\n 3 to delete an element\n 4 to find length\n 5. to Quit\n\n");
		scanf("%d",&option);
		switch (option){
			case 1:insert();break;
			case 2:display();break;
			case 3:del();break;
			case 4:printf("The length of list is %d",length());break;
			case 5:return 0;
			default:printf("invalid option\n");
		}
	}return 0;
}
void insert(){
	int l,i;
	createnode();
	printf("Enter the position of element to insert\n");
	scanf("%d",&pos);
	l=length();
	temp=head;
	if(pos==1){
		newnode->link=head;
		head = newnode;
	}
	else if(pos<=l+1){
		printf("\n2\t\t");
		for(i=0;i<pos-2;i++)
		temp=temp->link;
		newnode->link=temp->link;
		temp->link=newnode;
	}
	else printf("This position is not valid\n");
}
void del(){
	int l,i;
	if(head==NULL)
		printf("The list is empty\n");
		else{
	printf("Enter the position of element to delete\n");
	scanf("%d",&pos);
	l=length();
	struct node* temp1;
	temp=head;	
	if(pos==1){	
		head=temp->link;
		temp1=temp;
		free(temp1);	
	}
	else if(l>=pos){
		for(i=0;i<pos-2;i++)
		temp=temp->link;
		temp->link=(temp->link)->link;
		temp1=temp->link;
		free(temp1);
	}
	else printf("In this positon element is not present");
}}
void display(){
	temp = head;
	if(head==NULL)
		printf("The list is empty\n");
		else{
			printf("The elements in the list are\n");
			while(temp != NULL){
				printf("%d\t", temp->data);
				temp = temp->link;
			}
		}
}
int length(){
	temp=head;
	int len=0;
	while(temp!=NULL){
		len++;
		temp = temp->link;
	}
	return len;
}
void createnode(){
	int element;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data\n");
	scanf("%d", &element);
	newnode->data=element;
	newnode->link = NULL;
}
