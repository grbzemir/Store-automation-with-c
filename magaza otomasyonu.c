#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 1
#define M 2
struct urun
{
    char referanskodu[20];
    float fiyat;
};
struct isci
{
    char soyisim[20];
    char isim[20];
    int yas;
};
struct magaza
{
    char isim[10];
    char sokakadi[20];
    char mahalle[12];
    char telefon[15];
    float satis;
    struct isci e1;
    struct isci e2;
    struct isci e3;
    struct urun p[M];
};
void urunuolustur(struct urun *pr)
{
    printf("Referans kodu girin\n : ");
    scanf("%s",pr->referanskodu);
    printf("Lutfen fiyati girin\n : ");
    scanf("%f",&pr->fiyat);
}
void isciyiolustur(struct isci *em)
{
    printf("Iscinin soyadini giriniz\n : ");
    scanf("%s",em->soyisim);
    printf("Iscinin adini giriniz:\n ");
    scanf("%s",em->isim);
    printf("Iscinin yasini giriniz:\n ");
    scanf("%d",&em->yas);
}
void magazayiolustur(struct magaza *m)
{
    int i;
    printf("Lutfen magazanin ismini girin \n: ");
    scanf("%s",m->isim);
    printf("Lutfen magazanin bulundugu sokak ismini girin\n : ");
    scanf("%s",m->sokakadi);
    printf("Magazanin bulundugu mahalle ismi girin \n: ");
    scanf("%s",m->mahalle);
    printf("Magazanin telefon numarasini girin \n: ");
    scanf("%s",m->telefon);
    printf("Satis rakamini girin : \n");
    scanf("%f",&m->satis);
    printf("Isci 1 : \n");
    isciyiolustur(&m->e1);
    printf("Isci 2 : \n");
    isciyiolustur(&m->e2);
    printf("Isci 3 : \n");
    isciyiolustur(&m->e3);
    for ( i = 0; i< M; i++)
    {
        printf("Urunleri giriniz %d : \n",i);
        urunuolustur(&m->p[i]);
    }
}
void urunubas(struct urun p)
{
    printf("\treference kodu : %s\n",p.referanskodu);
    printf("\tfiyat : %f\n",p.fiyat);
}
void isciyibas(struct isci e)
{
    printf("\tIsim : %s\n",e.isim);
    printf("\tSoyisim : %s\n",e.soyisim);
    printf("\tYas : %d\n",e.yas);
}
void magazayibas(struct magaza m)
{
    int i;
    printf("Magazanin ismi : %s\n",m.isim);
    printf("Magazananin bulundugu sokak: %s\n",m.sokakadi);
    printf(":Magazanin bulundugu mahalle %s\n",m.mahalle);
    printf("Magazanin telefon numarasi : %s\n",m.telefon);
    printf("Satis rakami : %f\n",m.satis);
    printf("Isci 1 :\n");
    isciyibas(m.e1);
    printf("Isci 2 :\n");
    isciyibas(m.e2);
    printf("Isci 3 :\n");
    isciyibas(m.e3);
    for ( i = 0; i< M; i++)
    {
        printf("Urun %d : \n",i);
        urunubas(m.p[i]);
        
    }
    
}
void enyasli(struct magaza m)
{
    struct isci yasli;
    if (m.e1.yas >yasli.yas)
        yasli = m.e1;
    if (m.e2.yas >yasli.yas)
        yasli = m.e2;
    if (m.e3.yas >yasli.yas)
        yasli = m.e3;
    printf("En yasli isci:\n");
    isciyibas(yasli);
}
void ortalamafiyat(struct magaza m[N])
{
    int i, j;
    float s;
    for ( i=0; i<N; i++)
    {
        for( j =0; j<M; j++)
        {
            s+=m[i].p[j].fiyat;
        }
        printf(" %s magazasinda yer alan urunlerin ortlama fiyati :   %f\n",m[i].isim,(float) s/M);
    }
}
void bulundugumahalle(struct magaza m[N], char q[12])
{
    int i;
    for ( i = 0; i<N; i++)
    {
        if(stricmp(m[i].mahalle,q)==0)
            printf("%s mahallesinde %s magazasi bulunur \n", m[i].mahalle, m[i].isim);
    }
}

int main()
{
    struct magaza m[N];
    int i;
    for(i=0; i<N; i++)
    {
        printf("Magaza %d :\n",i);
        magazayiolustur(&m[i]);
    }
    for(i=0; i<N; i++)
    {
        printf("magasin %d :\n",i);
        magazayibas(m[i]);
    }
    enyasli(m[0]);
    ortalamafiyat(m);
    bulundugumahalle(m, "nisantasi");

    return 0;
}