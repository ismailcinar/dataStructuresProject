#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct student {
	int number;
	char name[40];
	int midterm,final;
	double average;
	struct student * next;
};

typedef struct student node;

node * add(node * head)
{
	node*stu=(node * )malloc(sizeof(node));
	printf("student number:  "); scanf("%d",&stu->number);
	printf("student name:  "); scanf("%s",&stu->name);
	printf("student midterm:  "); scanf("%d",&stu->midterm);
	printf("student final:  "); scanf("%d",&stu->final);
	stu->average=stu->midterm * 0.6 + stu->final * 0.4;
	if(head==NULL)
	{ 
		head=stu;
		head->next=NULL;
		
	}
	else
	{	
		stu->next=head;
		head=stu;
	}
	return head;
}
node * delete(node * head)
{
	bool sonuc= false;
	if(head==NULL)
	{
		printf("list is empty");
		return head;
	}
	else
	{ 		int stunum;
		printf("student number: ");  scanf("%d",&stunum);
		if(head->number==stunum && head->next==NULL)
		{
			free(head);
			head=NULL;
			sonuc=true;
		}
		else if(head->number==stunum && head->next!=NULL)
		{
			node * p =head->next;
			free(head);
			head=p;
			sonuc=true;
		}
		else
		{
			node *p=head;
			node *q=head;
			while(p->next!=NULL)
			{
				if(p->number==stunum)
				{
					q->next=p->next;
					free(p);	
					sonuc=true;
					break;
				}
				q=p;
				p=p->next;
			}
				if(p->number==stunum)
				{
					q->next=NULL;
					free(p);	
					sonuc=true;
				}
		if(!sonuc)
		printf("%d numarli ogrenci listede yok \n",stunum);
	}
	}
	
		return head;

}
node * print(node * head)
{
	if(head==NULL)
	{
		printf("list is empyt");
		
	}
	else
	{
		node *p=head;
		while(p!=NULL)
		{
			printf("------------------------- \n");
			printf("Number : %d  Name : %s  Midterm : %d Final : %d Average : %.2f \n",p->number,p->name,p->midterm,p->final,p->average);
			p=p->next;
			
		}
	}
		return head;

}
node * highPoint(node * head)
{	
system("cls");
int bigPoint=head->average;
node * bigNode= head;
if(head==NULL)
{
	printf("list is empty");	
}
	else 
	{
		node * p =head;
		while(p!=NULL)
		{
			if(bigPoint< p->average)
			{
				bigPoint=p->average;
				bigNode=p;
			}
			p=p->next;
		}
		printf("En yuksek ortalamasý olan ogrenci bilgileri: \n");
		printf("number: %d \n",bigNode->number);
		printf("name: %s \n",bigNode->name);
		printf("midterm: %d \n",bigNode->midterm);
		printf("final: %d \n",bigNode->final);
				printf("average: %.2f \n",bigNode->average);


		
	}
		return head;

}



int main() {
	int choose;
	node *head=NULL;
	while(1)
	{
		printf("tek yonlu dogrusal bagli liste \n");
		printf("1-- add \n");
		printf("2-- delete \n");
		printf("3-- print \n");
		printf("4-- the most point \n");
		printf("0-- exit \n");
		printf("make your choose: [0-4] \n");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1: head = add(head);
			break;
			case 2: head = delete(head);
			break;
			case 3: head = print(head);
			break;
			case 4: head = highPoint(head);
			break;
			case 0: exit(0);
			default : printf("wrong choose");
		}

	}
	
	return 0;
}
