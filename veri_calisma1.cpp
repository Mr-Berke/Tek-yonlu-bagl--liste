#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Berke TOPBAÞ    
//tek yönlü baðlý listede ekleme(sona ekler) , araye ekleme(baþa da eklenebilir),listeleme, silme (aradan silme dahil,arama yapar...
//18.11.2023

struct node {
    int numara;
    char ad[50];
    struct node *next;	
};

typedef struct node Bliste;
Bliste *ilk = NULL, *son = NULL, *temp = NULL,*onceki=NULL;

void ekleme(int num, char *isim) {   
    Bliste *yeni = (Bliste*)malloc(sizeof(Bliste));
    yeni->numara = num;
    strcpy(yeni->ad, isim);
	
    if (ilk == NULL) {
        ilk = yeni;
        son = yeni;
        ilk->next = NULL;
    } else {
        son->next = yeni;
        son = yeni;
        son->next = NULL;
    }	
}

void araya_ekle(int num, char *isim, int indeks) { 
	
    Bliste *yeni = (Bliste*)malloc(sizeof(Bliste));
    yeni->numara = num;
    strcpy(yeni->ad, isim);
    yeni->next = NULL;

    if (indeks == 0) {
        yeni->next = ilk;
        ilk = yeni;
        
    } else {
        temp = ilk;
        int sayac = 0;

        while (sayac < indeks - 1 && temp != NULL) {
            temp = temp->next;
            sayac++;
        }
        yeni->next = temp->next;
        temp->next = yeni;

        if (temp == NULL) {
            printf("Belirtilen indeks bulunamadi.\n");
            return;
        }        
    }
}
void listeleme() {
    temp = ilk;
	
    if (temp == NULL) {
        printf("liste bostur\n");
    } else {
        while (temp != NULL) {
            printf(" %d\t%s\n", temp->numara, temp->ad);
            temp = temp->next;
        }
    }
}

Bliste *ara(int num) {
    temp = ilk;
    while (temp) {
        if (temp->numara == num) {
            printf("Aranan kisi bulundu: %s\t%d\n", temp->ad, temp->numara);
            return temp;
        }
        temp = temp->next;
    }
    printf("Aranan kisi bulunamadi!!\n");
    return NULL;
}

int sil(int numara)
{
    temp = ilk;

    while (temp != NULL)
    {
        if (temp->numara == numara)
        {
            if (onceki == NULL)
            {
                ilk= temp->next;
            }
            else
            {
                onceki->next = temp->next;
            }

            free(temp);
            printf("Kayit silindi: %d\n", numara);
            return 1;
        }
        onceki = temp;
        temp = temp->next;
    }

    printf("Aranan kayit bulunamadi: %d\n", numara);
    return 0;
}

int main() {
    int secim, numara;
    char isim[50];	
    
    while (1) {
    	printf("Secim yapiniz: 1 - Ekleme, 2 - Listeleme, 3 - Arama, 4-araya ekleme , 5-silme , 6- Cikis\n");
    	scanf("%d", &secim);
    
    	switch (secim) {
            case 1:
                printf("Eklenecek isim giriniz: ");
                scanf("%s", isim);
			
                printf("Eklenecek numarayi giriniz: ");
                scanf("%d", &numara);
			
                ekleme(numara, isim);
                break;
			
            case 2:
                listeleme();
                break;
            
            case 3:
                printf("Aranacak numarayi giriniz: ");
                scanf("%d", &numara);
                ara(numara);
                break;
                
            case 4:
            	int indeks;
            	
            	printf("eklenecek indeksi giriniz: ");
                scanf("%d", &indeks);
                
                printf("Eklenecek isim giriniz: ");
                scanf("%s", isim);
			
                printf("Eklenecek numarayi giriniz: ");
                scanf("%d", &numara);
                araya_ekle(numara,isim,indeks);
                break;
            
            case 5:
            	int numara;
            	printf("silinecek elemanýn numarasýný giriniz: ");
                scanf("%d", &numara);
                sil(numara);
                break;            	
            
            case 6:
                exit(0);
                break;
			
            default:
                printf("Hatali secim !!\n");
                break;
        }
    }    
    return 0;
}



