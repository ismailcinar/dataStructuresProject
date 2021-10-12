#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct otopark{
	char plaka[10];
	char tip[20];
	int ucret;
	struct otopark * next;
	struct otopark * prev;
};

typedef struct otopark node;

node * giris (node * head)
{
	node * arac=(node *)malloc(sizeof(node));
	printf("otoparka girecek arac bilgileri : \n");
	printf("plakasi : "); scanf("%s",&arac->plaka);
	printf("tipi    : "); scanf("%s",&arac->tip);
	printf("ucreti  : "); scanf("%d",&arac->ucret);
	if(head==NULL)
	{
		head=arac;
		head->next=NULL;
		head->prev=NULL;
		printf("%s plakali arac otoparka ilk arac olarak giris yapti \n",head->plaka);
	}
	else
	{
		arac->next=head;
		head->prev=arac;
		head=arac;
		head->prev=NULL;
		printf("%s plakali arac otoparka giris yapti \n",head->plaka);
	
	}
	
	return head;
}
node * cikis (node * head)
{
	bool sonuc=false;
	if(head==NULL)
	{
		printf("otoparkta bekleyen arac yok ! \n");
		return head;
	}
	else
	{
		char aPlaka[10];
		printf("cikis yapacak arac plakasi  : "); 
		scanf("%s",aPlaka);
		if(head->next==NULL && (strcmp(head->plaka,aPlaka)==0))
		{
			free(head);
			head=NULL;
			printf("%s plakali son arac da otoparktan cikis yapti \n",aPlaka);
			sonuc=true;
		}
		else if (head->next!=NULL && (strcmp(head->plaka,aPlaka)==0))
		{
			node *p=head->next;
			free(head);
			head=p;
			p->prev=NULL;
			printf("%s plakali arac otoparktan cikis yapti \n",aPlaka);
			sonuc=true;
		}
		else
		{
			node *p=head;
			while(p->next!=NULL)
			{
				if(strcmp(p->plaka,aPlaka)==0)
				{
					node *p3=p->next;
					node *p2=p->prev;
					free(p);
					p2->next=p3;
					p3->prev=p2;
					printf("%s plakali arac otoparktan cikis yapti \n",aPlaka);
					sonuc=true;

				}
				p=p->next;
			}
			
			 if(strcmp(p->plaka,aPlaka)==0)
				{
					node *p3=p->prev;
					free(p);
					p3->next=NULL;
					printf("%s plakali arac otoparktan cikis yapti \n",aPlaka);
					sonuc=true;
					
				}
		}
		if(!sonuc)
		printf("%s plakali arac otoparkta yok !!! \n",aPlaka); 11
	}
	
	return head;
}
node * yazdir (node * head)
{
	system("cls");
	if(head==NULL)
	{
		printf("otoparkta bekleyen arac yok !!! \n");
		
	}
	else
	{
		node *p=head;
		printf("otoparkta bekleyene arac bilgileri \n");
		while(p!=NULL)
		{
			printf("%s plakali arac bilgileri : tipi : %s  ucreti :  %d \n",p->plaka,p->tip,p->ucret);
			p=p->next;
		}
	}
	
	return head;
}
node * aracSayisi (node * head)
{	
	system("cls");

	int toplam=0;

	if(head==NULL)
	{
		printf("otoparkta bekleyen arac yok !!! \n");
		
	}
	else
	{
		node *p=head;
		while(p!=NULL)
		{
			toplam++;
			p=p->next;
		}
		printf("otoparkta bekleyen arac sayisi : %d \n",toplam);
	}
	
	return head;
}
node * toplamUcret (node * head)
{
		system("cls");

	
	int toplam=0;

	if(head==NULL)
	{
		printf("otoparkta bekleyen arac yok !!! \n");
		
	}
	else
	{
		node *p=head;
		while(p!=NULL)
		{
			toplam+=p->ucret;
			p=p->next;
		}
		printf("otoparkta bekleyen araclarin toplam ucreti : %d \n",toplam);
	}
	

	
	return head;
}


int main ()
{
	int secim;
	node * head=NULL;
	while(1)
	{
		printf("\nOTOPARK UYGULAMASI (cift yonlu dogrusal bagli liste)\n");
		printf("1---arac girisi \n");
		printf("2---arac cikisi \n");
		printf("3---araclari listele \n");
		printf("4---arac sayisi \n");
		printf("5---araclarin toplam ucreti \n");
		printf("0---cikis \n");
		printf("secim yapiniz [0-5] \n");
		scanf("%d",&secim);
		switch(secim)
		{
			case 1: head=giris(head);
			break;
			case 2: head=cikis(head);
			break;
			case 3: head=yazdir(head);
			break;
			case 4: head=aracSayisi(head);
			break;
			case 5: head=toplamUcret(head);
			break;
			case 0: exit(0);
			break;
			default : printf("hatali secim yaptiniz");
		}



	}
	return 0;
	
}
