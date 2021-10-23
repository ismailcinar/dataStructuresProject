#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct otogaleri {
	char plaka[20];
	char marka[20];
	char model[20];
	char renk[20];
	int aFiyat;
	int sFiyat;
	
	struct otogaleri * next;
	struct otogaleri * prev;


};

typedef struct otogaleri node;

node * al(node * head)
{
	node * arac=(node * )malloc(sizeof(node));
	printf("Otogaleriye girecek aracin bilgilerini giriniz : \n");
	printf("plaka :"); scanf("%s",&arac->plaka);
		printf("marka :"); scanf("%s",&arac->marka);
	printf("model :"); scanf("%s",&arac->model);
	printf("renk :"); scanf("%s",&arac->renk);
	printf("aFiyat :"); scanf("%d",&arac->aFiyat);
	arac->sFiyat = arac->aFiyat * 1.1;
	if(head==NULL)
	{
		head=arac;
		head->next=head;
		head->prev=head;
		printf("galeriye ilk arac girisi yapildi.\n");
		
	}
	else
	{
		node *p = head;
		while(p->next!=head)
		{
			p=p->next;
		}
		arac->next=head;
		head->prev=arac;
		head=arac;
		p->next=head;
		head->prev=p;
		printf("galeriye il arac ggirisi yapildi.\n");

	}
	return head;
}

node * sat(node * head)
{
	bool sonuc =false;
	if(head==NULL)
	{
		printf("galeride satilik arac yok \n");
		return head;
	}
	else
	{
		char aPlaka[20];
		printf("satisi yapilacak arac plakasi :"); scanf("%s",&aPlaka);
		if(head->next==head && (strcmp(head->plaka,aPlaka) == 0)  )
		{
			printf("%s plakali arac %d TLye satildi \n",head->plaka,head->sFiyat);
			sonuc=true;
			free(head);
			head=NULL;
		}
		else if(head->next!=head && (strcmp(head->plaka,aPlaka) == 0) )
		{
				printf("%s plakali arac %d TLye satildi \n",head->plaka,head->sFiyat);
							sonuc=true;
			node * p=head;
			while(p->next!=head)
			{
				p=p->next;
			}
			node *p2=head->next;
			free(head);
			head=p2;
			head->prev=p;
			p->next=head;
		}
		else
		{
			node * p =head;
			while(p->next!=head)
			{
				if(strcmp(p->plaka,aPlaka) == 0)
				{
					printf("%s plakali arac %d TLye satildi \n",p->plaka,p->sFiyat);
								sonuc=true;
					node *p2=p->prev;
					node *p3=p->next;
					free(p);
					p2->next=p3;
					p3->prev=p2;
				}
					p=p->next;
			}
			if(strcmp(p->plaka,aPlaka) == 0)
				{
					printf("%s plakali arac %d TLye satildi \n",p->plaka,p->sFiyat);
					sonuc=true;
					node *p2=p->prev;
					free(p);
					p2->next=head;
					head->prev=p2;
			
				}		
				

		}
		if(!sonuc)
		{
		printf("%s plakali arac galeride yok. \n",aPlaka);	
		}
	}
	return head;
}

node * yazdir(node * head)
{
	system("cls");
		if(head==NULL)
	printf("galeride arac yok \n");
	else
	{
		node * p=head;
		while(p->next!=head)
		{
			printf("%s plakali arac bilgileri : marka : %s model : %s renk : %s ucret : %d \n",p->plaka,p->marka,p->model,p->renk,p->aFiyat);
			p=p->next;
		}
			printf("%s plakali arac bilgileri : marka : %s model : %s renk : %s ucret : %d \n",p->plaka,p->marka,p->model,p->renk,p->aFiyat);
	}
	return head;
}

node * aracSayisi(node * head)
{
	system("cls");
	int adet=0;
	if(head==NULL)
	{
		printf("galeride arac yok. \n ");
	}
	else
	{
		node * p=head;
		while(p->next!=head)
		{
			adet++;
			p=p->next;
		}
		adet++;
		printf("galerideki mevcut arac sayisi : %d  \n",adet);
	}
	return head;
}



int main ()
{
	
	int secim;
	node * head= NULL;
	while(1)
	{
		printf("\nOtogaleri kayit uygulamasi \n");
		printf("1-- galeriye arac girisi \n");
		printf("2-- galeriden arac cikisi \n");
		printf("3-- galerideki arac listesi \n");
		printf("4-- galeriki arac sayisi \n");
		printf("0-- cikis \n");
				printf("seciminizi yapiniz \n");

		scanf("%d",&secim);
		
		switch(secim)
		{
			case 1: head=al(head);
			break;
			case 2: head=sat(head);
			break;
			case 3: head=yazdir(head);
			break;
			case 4: head=aracSayisi(head);
			break;
			case 0: exit(0);
			break;
			default : printf("hatali secim");
		}

	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
