#include<stdio.h>
int push();
int pop();
int topele();
int display();
int a[100];
int top;
int choice;
int main()
{
	top = -1;
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
	top++;
	printf("Enter the element\n");
	scanf("%d",&a[top]);
	return 0;
}
int pop()
{
	if(top<0)
	{
		printf("The stack is empty");
	}
	else{
		printf("%d\n",a[top]);
		top--;
	}
	return 0;
}
int topele()
{
	if(top<0)
	{
		printf("The stack is empty");
	}
	else{
		printf("%d is the top element and is %d th element\n", a[top],top+1);
	}
	return 0;
}
int display()
{
	int i =0;
	while(i<=top)
	{
		printf("%d\t",a[i]);
		i++;
	}
	return 0;	
}

