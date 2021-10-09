#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



struct musteri{
	int no;
	char ad[40];
	char urun[40];
	int ucret;
	char adres[80];
	struct musteri * next;
	
};
typedef struct musteri node;
node * ekle(node * head)
{
	node *m1=(node *)malloc (sizeof(node));
	printf("musteri no :");  scanf("%d",&m1->no);
	printf("Adi        :");  scanf("%s",&m1->ad);
	printf("Urun        :");  scanf("%s",&m1->urun);
	printf("ucret        :");  scanf("%d",&m1->ucret);
	printf("adres        :");  scanf("%s",&m1->adres);
	
	if(head==NULL)
	{
		head=m1;
		head->next=head;
		printf("liste olusturuldu, ilk musteri eklendi");
		
	}
	else
	{
		node *p=head;
		while(p->next!=head)
		{
			p=p->next;
		}
		m1->next=head;
		head=m1;
		p->next=head;
		printf("listeye musteri eklendi");
	}
	
	
	return head;
}
node * sil(node * head)
{	bool sonuc=false;
	if(head==NULL){
		printf("silinecek musteri yok");
		return head;
	}
	else
	{
		int mNo;
		printf("silinecek musteri no : "); scanf("%d",&mNo);
		if(head->next==head && head->no==mNo)
		{
			free(head);
			head=NULL;
			printf("listede kalan son musteri de silindi \n");
			sonuc=true;
			
		}
		else if(head->next!=head && head->no==mNo)
		{
			node *p=head;
			while(p->next!=head){
				p=p->next;
				
			}
			node * p2=head->next;
			free(head);
			head=p2;
			p->next=head;
			printf("%d numarali musteri silindi \n",mNo);
			sonuc=true;
		}
		else
		{
			node *p=head;
			node *p2=head;
			while(p->next!=head)
			{
				if(p->no==mNo) 
				{
				p2->next=p->next;
				free(p);
				printf("%d numarali musteri silindi \n",mNo);
			sonuc=true;

				} 
				p2=p;
				p=p->next;
			}
				if(p->no==mNo) 
				{
				p2->next=head;
				free(p);
				printf("%d numarali musteri silindi \n",mNo);
			sonuc=true;

				} 
		}
		if(!sonuc)
		printf("%d numarali musteri listede yok \n",mNo);
	}
	
	
	return head;
}
node * yazdir(node * head)
{	
	system("cls");
	if(head==NULL)
	{
		printf("liste bos");
	}
	else
	{
		node *p=head;
		while(p->next!=head)
		{
			printf("**************************** \n");
			printf("Musteri no: %d Adi %s  aldigi urun : %s  ucreti :  %d adres : %s  \n",p->no,p->ad,p->urun,p->ucret,p->adres);
			p=p->next;
		}
			printf("**************************** \n");
			printf("Musteri no: %d Adi %s  aldigi urun : %s  ucreti :  %d adres : %s  \n",p->no,p->ad,p->urun,p->ucret,p->adres);
	}
	return head;
}
node * ara(node * head)
{	system("cls");
bool sonuc=false;
	if(head==NULL)
	{
		printf("liste bos\n");
		return head;
	}
	else
	{
		int mNo;
		printf("Musteri no: "); scanf("%d",&mNo);
		node *p=head;
		while(p->next!=head)
		{
			if(p->no==mNo)
			{
				printf("%d numarali musteri bilgileri : \n");
				printf("adi         : %s\n",p->ad);
				printf("urun         : %s\n",p->urun);
				printf("ucret         : %d\n",p->ucret);
				printf("adres         : %s\n",p->adres);
				sonuc=true;

			}
			p=p->next;
		}
		if(p->no==mNo)
			{
				printf("%d numarali musteri bilgileri : \n");
				printf("adi         : %s\n",p->ad);
				printf("urun         : %s\n",p->urun);
				printf("ucret         : %d\n",p->ucret);
				printf("adres         : %s\n",p->adres);
			sonuc=true;

			}
			if(!sonuc)
			printf("%d numarali musteri listede yok \n", mNo);
		
	}
	
	return head;
}
node * toplamGelir(node * head)
{
	system("cls");
	int toplam=0;
	if(head==NULL)
	{
		printf("liste bos ! \n");
	}
	else
	{
		node *p=head;
		while(p->next!=head)
		{
			toplam+=p->ucret;
			p=p->next;
		}
		toplam+= p->ucret;
		printf("toplam geliriniz : %d",toplam);
	}
	
	return head;
}
int main()
 {
	int secim;
	node * head=NULL;
	while(1)
	{
		printf("\ntek yonlu dairesel bagli liste ile musteri takip uygulamasi\n");
		printf("1-- ekle \n");
			printf("2-- sil \n");
				printf("3-- yazdir \n");
					printf("4-- ara \n");
						printf("5-- toplam gelir \n");
							printf("0-- cikis \n");
								printf("seciminizi yapin [0-5] \n");
								scanf("%d",&secim);
								switch(secim)
								{
									case 1: head=ekle(head);
									break;
									case 2: head=sil(head);
									break;
									case 3: head=yazdir(head);
									break;
									case 4: head=ara(head);
									break;
									case 5: head=toplamGelir(head);
									break;
									case 0: exit(0);
									break;
									default : printf("hatali secim");
									
								}
	}
	
	
	
	return 0;
}
