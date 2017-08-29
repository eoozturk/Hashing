/*1_40_150201214_150201206_130201046*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct info{
    int data;
    char ad[10];
    struct info *next;
};

typedef struct info node;
node *head,*p,*yeni,*q,*temp;

struct bilgi{
    int id;
    char *isim;
};
struct bilgi liste[800],liste2[800],liste3[800],liste4[800],liste5[800],liste6[800],gecici[500],gecici1[500],gecici2[500];

void createlist()
 {
     int i;
     for(i=0;i<500;i++)
     {
         if(i==0)
         {
             head=(node*)malloc(sizeof(node));
             p=head;
         }
         else
         {
            p->next=(node*)malloc(sizeof(node));
            p=p->next;
         }

     }

     p->next=NULL;
 }

void benzersiz_id()
{
    int j,i,x;
    p=head;
    for(i=0;i<500;i++)
    {
       x=110201000 + rand()% 40000300;
       p->data=x;
       p=p->next;
    }
    temp=head;
    p=head;
    flag:
    for(i=0;i<500;i++)
    {
        for(j=0;j<500;j++)
        {
            if(i!=j)
            {
                if(temp->data==p->data)
                {
                    p->data=110201000+rand()%40000300;
                        temp=head;
                        p=head;
                    goto flag;
                }
            }
            p=p->next;
        }
        temp=temp->next;
        p=head;
    }
}

void string_random() {
    p=head;
    static const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int i,j;
  for(j=0;j<500;j++)
    {
          for (i = 0; i < 10; i++)
          {
             p->ad[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
          }
          p=p->next;
   }
}

void dosyaya_yaz()
{
    srand(time(NULL));
    FILE *info,*bolenkalantasma,*bolenkalanlineer,*katlamalineer,*katlamatasma,*kareortasilineer,*kareortasitasma;
    p=head;
    int   j,i=0,n,k=500,c=0;
    struct son{
        int sonid;
        char *sonad;
    };
    struct son sonliste[7];

    info = fopen("info.txt", "w+");
    bolenkalantasma = fopen("bolenkalantasma.txt", "w");
    bolenkalanlineer = fopen("bolenkalanlineer.txt", "w");
    katlamalineer = fopen("katlamalineer.txt", "w");
    katlamatasma = fopen("katlamatasma.txt", "w");
    kareortasilineer = fopen("kareortasilineer.txt", "w");
    kareortasitasma = fopen("kareortasitasma.txt", "w");

    if(info==NULL )
      puts("info.txt dosyasi acilmadi. !\n"), exit(1);
      createlist();
      string_random();
      benzersiz_id();

    for(i=0;i<500;i++)
    {
        fprintf(info,"%d. %5d %10s\n",i,p->data,p->ad);
        p=p->next;
    }
    //bolen kalan ayrık taşma
    if(bolenkalantasma==NULL )
    puts("bolenkalantasma.txt dosyasi acilmadi. !\n"), exit(1);
    int kayitsayac1=0;
    int bolendizi[800];
    p=head;
    for(i=0;i<500;i++)
     {
       n=p->data %500;
       kayitsayac1=kayitsayac1+2;
       if(liste[n].id==0)
       {
         liste[n].id=p->data;
         liste[n].isim=p->ad;
         kayitsayac1=kayitsayac1+3;
         bolendizi[n]=p->data;
       }
       else
       {
         liste[k].id=p->data;
         liste[k].isim=p->ad;
         k++;
         kayitsayac1=kayitsayac1+4;
         bolendizi[k]=p->data;
       }
       p=p->next;
     }
     kayitsayac1=kayitsayac1+1002;
      for(i=0;i<k;i++){fprintf(bolenkalantasma,"%d. %5d %10s\n",i,liste[i].id,liste[i].isim);}
        //Arama islemi
        int gg=0,nmod;
        for(i=0;i<k;i++)
        {
            nmod=bolendizi[i]%500;
            for(j=nmod;j<k;j++)
            {
                if(liste[nmod].id==liste[j].id)
                gg=gg+1;
                else
                gg=gg+1;
            }
        }
        kayitsayac1=kayitsayac1+gg;


        sonliste[0].sonid=kayitsayac1;
        sonliste[0].sonad="Bolen kalan ayrik tasma";

        printf("****BOLEN KALAN AYRIK TASMA YONTEMIYLE SIRALANMIS KAYITLAR****\n\n");
          for(i=0;i<k;i++)
        {
            if(liste[i].id==0)
                printf("");
            else
            printf("%d. %d-->%s\n",i,liste[i].id,liste[i].isim);
        }

    //bolenkalan ayrık taşma********

    //bolenkalan lineer yoklama********
    if(bolenkalanlineer==NULL )
    puts("bolenkalanlineer.txt dosyasi acilmadi. !\n"), exit(1);
    int kayitsayac2=0;
    k=500;
    p=head;
    for(i=0;i<500;i++)
    {
      n=p->data %500;
      kayitsayac2=kayitsayac2+2;
      if(liste2[n].id==0)
       {
         liste2[n].id=p->data;
         liste2[n].isim=p->ad;
         kayitsayac2=kayitsayac2+3;
       }
       else
       {
         gecici[k].id=p->data;
         gecici[k].isim=p->ad;
         k++;
         kayitsayac2=kayitsayac2+4;
       }
       p=p->next;
    }
    kayitsayac2=kayitsayac2+1002;
    k=500;
    for(i=0;i<500;i++)
    {
        if(liste2[i].id==0)
        {
         liste2[i].id=gecici[k].id;
         liste2[i].isim=gecici[k].isim;
         k++;
         kayitsayac2=kayitsayac2+4;
        }
    }
    kayitsayac2=kayitsayac2+1002;

while(liste2[c].id!=0)
{
    c++;
}
     for(i=0;i<c;i++){fprintf(bolenkalanlineer,"%d. %5d %10s\n",i,liste2[i].id,liste2[i].isim);}

    //Arama islemi
         p=head;
         gg=0;
        for(i=0;i<500;i++)
        {
            nmod=p->data%500;
            for(j=0;j<500;j++)
            {
                if(liste2[nmod].id==liste2[j].id)
                gg=gg+j;
            }
            p=p->next;
        }

        kayitsayac2=kayitsayac2+gg;
        sonliste[1].sonid=kayitsayac2;
        sonliste[1].sonad="Bolen kalan lineer yoklama";

        printf("\n\n****BOLEN KALAN LINEER YOKLAMA YONTEMIYLE SIRALANMIS KAYITLAR****\n\n");
        for(i=0;i<c;i++){
            printf("%d. %d-->%s\n",i,liste2[i].id,liste2[i].isim);
        }
    //bolenkalan lineer yoklama

    //katlama lineer yoklama
     if(katlamalineer==NULL )
     puts("katlamalineer.txt dosyasi acilmadi. !\n"), exit(1);

    int sayi1,sayi2,sayi3,veri,n2dizi[500];
    int toplam=0;
    p=head;
    k=500;
    int kayitsayac3=0;
    for(i=0;i<500;i++)
    {
        veri=p->data;
        sayi1=veri/1000000;
        veri=veri%1000000;
        sayi2=veri/1000;
        veri=veri%1000;
        sayi3=veri/1;
        toplam = sayi1 + sayi2 + sayi3;
        n2dizi[i]=toplam;
        n=toplam%500;
    kayitsayac3=kayitsayac3+16;
     if(liste3[n].id==0)
       {
         liste3[n].id=p->data;
         liste3[n].isim=p->ad;
         kayitsayac3=kayitsayac3+3;
       }
       else
       {
         gecici1[k].id=p->data;
         gecici1[k].isim=p->ad;
         k++;
         kayitsayac3=kayitsayac3+4;
       }
       p=p->next;
    }
    kayitsayac3=kayitsayac3+1002;
    k=500;
    for(i=0;i<500;i++)
    {
        if(liste3[i].id==0)
        {
         liste3[i].id=gecici1[k].id;
         liste3[i].isim=gecici1[k].isim;
         k++;
         kayitsayac3=kayitsayac3+4;
        }
    }
    kayitsayac3=kayitsayac3+1002;
    c=0;
while(liste3[c].id!=0)
{
    c++;
}
     for(i=0;i<c;i++){fprintf(katlamalineer,"%d. %5d %10s\n",i,liste3[i].id,liste3[i].isim);}

        //Arama islemi
        gg=0;
        for(i=0;i<500;i++)
        {
            nmod=n2dizi[i]%500;
            for(j=0;j<500;j++)
            {
                if(liste3[nmod].id==liste3[j].id)
                gg=gg+j;
            }
        }
        kayitsayac3=kayitsayac3+gg;

        sonliste[2].sonid=kayitsayac3;
        sonliste[2].sonad="Katlama lineer yoklama";

        printf("\n\n****KATLAMA LINEER YOKLAMA YONTEMIYLE SIRALANMIS KAYITLAR****\n\n");
          for(i=0;i<c;i++){
            printf("%d. %d-->%s\n",i,liste3[i].id,liste3[i].isim);
        }
    //katlama lineer yoklama

    //katlama ayrık taşma
     if(katlamatasma==NULL )
     puts("katlamatasma.txt dosyasi acilmadi. !\n"), exit(1);
    int kayitsayac4=0;
    int ndizi[800];
    p=head;
    k=500;
    for(i=0;i<500;i++){
        veri=p->data;
        sayi1=veri/1000000;
        veri=veri%1000000;
        sayi2=veri/1000;
        veri=veri%1000;
        sayi3=veri/1;
        toplam = sayi1 + sayi2 + sayi3;
        n=toplam%500;

        kayitsayac4=kayitsayac4+16;
       if(liste4[n].id==0)
       {
         liste4[n].id=p->data;
         liste4[n].isim=p->ad;
         kayitsayac4=kayitsayac4+3;
         ndizi[n]=toplam;
       }
       else
       {
         liste4[k].id=p->data;
         liste4[k].isim=p->ad;
         k++;
         kayitsayac4=kayitsayac4+4;
         ndizi[k]=toplam;
       }
       p=p->next;
     }
        kayitsayac4=kayitsayac4+1002;
      for(i=0;i<k;i++){fprintf(katlamatasma,"%d. %5d %10s\n",i,liste4[i].id,liste4[i].isim);}

        //Arama İslemi
        gg=0;
        for(i=0;i<k;i++){
            nmod=ndizi[i]%500;
            for(j=nmod;j<k;j++)
            {
                if(liste4[nmod].id==liste4[j].id)
                gg=gg+1;
                else
                gg=gg+1;
            }
        }

        kayitsayac4=kayitsayac4+gg;
        sonliste[3].sonid=kayitsayac4;
        sonliste[3].sonad="Katlama ayrik tasma";

       printf("\n\n****KATLAMA AYRIK TASMA YONTEMIYLE SIRALANMIS KAYITLAR****\n\n");
          for(i=0;i<k;i++){
            if(liste4[i].id==0)
                printf("");
            else
            printf("%d. %d-->%s\n",i,liste4[i].id,liste4[i].isim);
        }
    //katlama ayrık taşma

    //kareortası tasma
    if(kareortasitasma==NULL )
    puts("kareortasitasma.txt dosyasi acilmadi. !\n"), exit(1);

    p=head;
    k=500;
    int t;
    long long karesi,sayi;
    int bas1,bas2,bas3;
    long long a=1;
    int ortmod;
    int basamak[17];
    int gecici;
    int kayitsayac5=0;
    int ortdizi[500];
    for(i=0;i<500;i++){
        sayi=p->data;
        karesi=sayi*sayi;
        a=1;

        for (j=1; j<17; j++)
                {
                    a = a * 10;
                }

         gecici=0;
         for (t=0; t< 17; t++)
                {
                    gecici = karesi / a;
                    basamak[t] = gecici;
                    karesi = karesi % a;
                    a = a / 10;
                }


         bas1 = basamak[7];
         bas2 = basamak[8];
         bas3 =basamak[9];
         ortmod=bas1*100+bas2*10+bas3;
         n=ortmod%500;
        kayitsayac5=kayitsayac5+166;

     if(liste5[n].id==0)
       {
         liste5[n].id=p->data;
         liste5[n].isim=p->ad;
         kayitsayac5=kayitsayac5+3;
         ortdizi[n]=ortmod;
       }
       else
       {
         liste5[k].id=p->data;
         liste5[k].isim=p->ad;
         k++;
         kayitsayac5=kayitsayac5+4;
         ortdizi[k]=ortmod;
       }
       p=p->next;
     }
             kayitsayac5=kayitsayac5+1002;

      for(i=0;i<k;i++){fprintf(kareortasitasma,"%d. %5d %10s\n",i,liste5[i].id,liste5[i].isim);}
        //Arama islemi
        gg=0;
        for(i=0;i<k;i++)
        {
            nmod=ortdizi[i]%500;
            for(j=nmod;j<k;j++)
            {
                if(liste5[nmod].id==liste5[j].id)
                gg=gg+1;
                else
                gg=gg+1;
            }
        }
        kayitsayac5=kayitsayac5+gg;

        sonliste[4].sonid=kayitsayac5;
        sonliste[4].sonad="Kare ortasi ayrik tasma";

       printf("\n\n****KARE ORTASI AYRIK TASMA YONTEMIYLE SIRALANMIS KAYITLAR****\n\n");
          for(i=0;i<k;i++){
            if(liste5[i].id==0)
                printf("");
            else
            printf("%d. %d-->%s\n",i,liste5[i].id,liste5[i].isim);
        }
    //kareortası tasma

    //kareortasi lineer
    if(kareortasilineer==NULL )
    puts("kareortasilineer.txt dosyasi acilmadi. !\n"), exit(1);
    int kayitsayac6=0;
    int ort2dizi[500];
    p=head;
    k=500;

    for(i=0;i<500;i++){
        sayi=p->data;
        karesi=sayi*sayi;
        a=1;
        for (j=1; j<17; j++)
                {
                    a = a * 10;
                }

                 gecici=0;
         for (t=0; t< 17; t++)
                {
                    gecici = karesi / a;
                    basamak[t] = gecici;
                    karesi = karesi % a;
                    a = a / 10;
                }
         bas1 = basamak[7];
         bas2 = basamak[8];
         bas3 =basamak[9];
         ortmod=bas1*100+bas2*10+bas3;
         ort2dizi[i]=ortmod;
         n=ortmod%500;
        kayitsayac6=kayitsayac6+166;
     if(liste6[n].id==0)
       {
         liste6[n].id=p->data;
         liste6[n].isim=p->ad;
         kayitsayac6=kayitsayac6+3;
       }
       else
       {
         gecici2[k].id=p->data;
         gecici2[k].isim=p->ad;
         k++;
         kayitsayac6=kayitsayac6+4;
       }
       p=p->next;
    }
     kayitsayac6=kayitsayac6+1002;
    k=500;
    for(i=0;i<500;i++)
    {
        if(liste6[i].id==0)
        {
         liste6[i].id=gecici2[k].id;
         liste6[i].isim=gecici2[k].isim;
         k++;
         kayitsayac6=kayitsayac6+5;
        }
    }
    kayitsayac6=kayitsayac6+1002;
    c=0;
while(liste6[c].id!=0)
{
    c++;
}
     for(i=0;i<c;i++){fprintf(kareortasilineer,"%d. %5d %10s\n",i,liste6[i].id,liste6[i].isim);}

        //Arama islemi
        gg=0;
        for(i=0;i<500;i++)
        {
            nmod=ort2dizi[i]%500;
            for(j=0;j<500;j++)
            {
                if(liste6[nmod].id==liste6[j].id)
                gg=gg+j;
            }
        }

        kayitsayac6=kayitsayac6+gg;

        sonliste[5].sonid=kayitsayac6;
        sonliste[5].sonad="Kare ortasi lineer yoklama";

        printf("\n\n****KARE ORTASI LINEER YOKLAMA YONTEMIYLE SIRALANMIS KAYITLAR****\n\n");
          for(i=0;i<c;i++)
        {
            printf("%d. %d-->%s\n",i,liste6[i].id,liste6[i].isim);
        }
    //kareortasi lineer

    //lineer arama kayıt işlemi
        n=500;
        int lineersonuc;
        lineersonuc=n*(n+1)/2;
        sonliste[6].sonid=lineersonuc;
        sonliste[6].sonad="Lineer arama islemi";
    //lineer arama kayıt işlemi

    /* dosyayi kapat */
    fclose(info);
    fclose(bolenkalantasma);
    fclose(bolenkalanlineer);
    fclose(katlamalineer);
    fclose(kareortasilineer);
    fclose(kareortasitasma);

    int max;
    char *sonisim;
    printf("\n\n%s : %d \n",sonliste[6].sonad,sonliste[6].sonid);
    printf("\nHash yontemlerinin islem uzunluklari:\n\n");
     for(i=0;i<6;i++)
    {
        printf("%d. %s : %d\n",i+1,sonliste[i].sonad,sonliste[i].sonid);
    }

    max=sonliste[0].sonid;

    for(i=0;i<6;i++)
    {
        if(sonliste[i].sonid<max)
        {
         max=sonliste[i].sonid;
        }
    }
    for(i=0;i<6;i++)
    {
        if(max==sonliste[i].sonid)
        sonisim=sonliste[i].sonad;
    }
    printf("\n\nEn iyi hash yontemi: %d ---- %s\n\n",max,sonisim);

   /*
    max=sonliste[0].sonid;
  for(i=0;i<7;i++)
    {
        if(sonliste[i].sonid<max)
        {
         max=sonliste[i].sonid;
        }
    }
    for(i=0;i<7;i++)
    {
        if(max==sonliste[i].sonid)
        sonisim=sonliste[i].sonad;
    }
    printf("\nEn iyi arama yontemi : %d ----- %s ",max,sonisim);*/
}


int main()
{
   dosyaya_yaz();
    return 0;
}

