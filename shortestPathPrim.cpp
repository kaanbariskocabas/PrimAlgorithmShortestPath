#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

static int koordinatlar[20][20];
static int dugumsayisi=0;
static int uzakliklar[400];
static int dugummatris1[20][20];
static int primdugum[400];
static int adugum[20][20];
static int degermatris[20][20];
static int dugumkoordinatx[400];
static int dugumkoordinaty[400];

int adugumbosalt()
{
    for(int x=0;x<20;x++){

    for(int y=0;y<20;y++)
    {
        adugum[x][y]=100;
    }
    }
}
int dugumbosalt()
{

    for(int x=0;x<20;x++){

    for(int y=0;y<20;y++)
    {
        degermatris[x][y]=0;
        adugum[x][y]=100;
    }
    }

    for(int y=0;y<400;y++)
    {
        primdugum[y]=0;
        uzakliklar[y]=0;
        dugumkoordinatx[400]=0;
        dugumkoordinaty[400]=0;
    }primdugum[0]=1;
}
int koordinatlarbosalt()
{
    for(int x=0;x<20;x++)
    for(int y=0;y<20;y++)
    {

        koordinatlar[x][y]=0;
    }

}
int yeniciz()
{
    int sayacx=0;
    int sayacy=0;

    char arr[20];
    for(int i=65;i<=650;i+=30)
    {

         for(int j=65;j<=650;j+=30)
         {


             if(koordinatlar[sayacx][sayacy]==1)
             {

             setcolor(RED);
             setbkcolor(BLUE);
             rectangle(i,j,i+30,j+30);
             outtextxy(i,j,"        ");
             outtextxy(i,j+15,"        ");

                dugumsayisi++;
              for(int k=0;k<dugumsayisi;k++)
                    {
                        setbkcolor(BLUE);
                        setcolor(WHITE);
                        sprintf(arr,"D%d",k);
                        outtextxy(i+7,j+7,arr);

                    }
             }
            sayacy++;
            sayacy=sayacy%20;
         }
         sayacx++;
    }

}
int yolucizdir(int birx,int biry,int ikix,int ikiy)
{
    if(birx>=ikix&&biry>=ikiy)
    {
        for(int i = ikix;birx>=i;i++)
        {
            setbkcolor(BLUE);
            setcolor(BLUE);
            outtextxy((i*30)+65,(ikiy*30)+65,"        ");
            outtextxy((i*30)+65,(ikiy*30)+80,"        ");

        }
        for(int i = ikiy;biry>=i;i++)
        {
            setbkcolor(BLUE);
            setcolor(BLUE);
            outtextxy((birx*30)+65,(i*30)+65,"        ");
            outtextxy((birx*30)+65,(i*30)+80,"        ");


        }
    }
    if(birx<=ikix&&biry>=ikiy)
    {
        for(int i = birx;i<=ikix;i++)
        {
            setbkcolor(BLUE);
            setcolor(BLUE);
            outtextxy((i*30)+65,(biry*30)+65,"        ");
            outtextxy((i*30)+65,(biry*30)+80,"        ");


        }
        for(int i = ikiy;i<=biry;i++)
        {
            setbkcolor(BLUE);
            setcolor(BLUE);
            outtextxy((ikix*30)+65,(i*30)+65,"        ");
            outtextxy((ikix*30)+65,(i*30)+80,"        ");


        }
    }
    if(birx>=ikix&&biry<=ikiy)
    {
        for(int i = ikix;i<=birx;i++)
        {
            setbkcolor(BLUE);
            setcolor(BLUE);
            outtextxy((i*30)+65,(ikiy*30)+65,"        ");
            outtextxy((i*30)+65,(ikiy*30)+80,"        ");

        }
        for(int i = biry;i<=ikiy;i++)
        {
            setbkcolor(BLUE);
            setcolor(BLUE);
            outtextxy((birx*30)+65,(i*30)+65,"        ");
            outtextxy((birx*30)+65,(i*30)+80,"        ");

        }
    }
    if(birx<=ikix&&biry<=ikiy)
    {
        for(int i = birx;i<ikix;i++)
        {
            setbkcolor(BLUE);
            setcolor(BLUE);
            outtextxy((i*30)+65,(biry*30)+65,"        ");
            outtextxy((i*30)+65,(biry*30)+80,"        ");

        }
        for(int i = biry;i<ikiy;i++)
        {
            setbkcolor(BLUE);
            setcolor(BLUE);
            outtextxy((ikix*30)+65,(i*30)+65,"        ");
            outtextxy((ikix*30)+65,(i*30)+80,"        ");

        }
    }
    int sayackoordinat=0;
    char arr[20];
    for(int i=0;i<20;i++)
    {

         for(int j=0;j<20;j++)
         {



             if(koordinatlar[i][j]==1)
             {

             setcolor(RED);
             setbkcolor(BLUE);
             outtextxy(65+(30*i),(65+30*j),"        ");
             outtextxy(65+(30*i),(80+30*j),"        ");
             sayackoordinat++;
              for(int k=0;k<sayackoordinat;k++)
                    {

                        setcolor(WHITE);
                        sprintf(arr,"D%d",k);
                        outtextxy(72+(30*i),(72+30*j),arr);

                    }
             }

}

}delay(50);

}
int prim(){
yeniciz();
int i,j,k,l,x,y,uzaklikx,uzakliky,uzaklik,Toplam_maliyet=0,satir=0,tmpk=0,sayacyol=1;
int sayy=0,sayx=1,uzakliksayisi=0,temp=0,sayx1=0,sayy1=0,sayacx2=0,sayacy2=0,adugumsayac=0,sayackoordinat=0;
int tmpsatir=0,tmpsutun=0;
char arr[20],arr2[20],arr3[20],arr4[20],durdurmasayac=0;
dugumbosalt();
    //UZAKLIKLARI DUGUME ATAMA VE DUGUM KOORDINATLARINI MATRISE GIRDIRME
    for(x=0;x<20;x++){
    for(y=0;y<20;y++)
    {
    if(koordinatlar[x][y]==1)
    {
     dugumkoordinatx[sayackoordinat]=x;
     dugumkoordinaty[sayackoordinat]=y;
     sayackoordinat++;
        for(i=0;i<20;i++)
        {
        for(j=0;j<20;j++)
        {
        if(koordinatlar[i][j]==1)
        {
            uzaklikx=i-x;
            uzakliky=j-y;
            uzaklik=abs(i-x)+abs(j-y);
         if(uzaklik!=0)
            {uzakliksayisi++;
                    uzakliklar[uzakliksayisi]=uzaklik;
                    if(sayx1==sayy1)
                    {
                        sayy1++;
                        dugummatris1[sayx1][sayy1]=uzaklik;
                    }
                    else
                    {

                        if(sayy1==dugumsayisi-1)
                            {


                                sayx1++;
                                sayy1=0;
                                dugummatris1[sayx1][sayy1]=uzaklik;

                            }
                        else
                            {
                                sayy1++;

                            if(sayx1==sayy1){

                                sayy1++;
                            dugummatris1[sayx1][sayy1]=uzaklik;
                            }
                            else
                            dugummatris1[sayx1][sayy1]=uzaklik;

                            }

    }
    }
    }
    }
    }
    }
    }
    }

         int sutun=0,tmpr=0,sayacprim=1,satir_sifir=0,sayac_sifirla=0;
         int tmpsayac=0,m,sifir=0,sutun_sifir=0,satir0=0,sutun0=0,sayacyson=0;
          for(i=0;i<dugumsayisi;i++){
         for(j=0;j<dugumsayisi;j++){

             dugummatris1[i][i]=100;


             }}

       //KOMSULUK MATRISININ CIZIMI
        bar(730,20,770+(dugumsayisi+1)*30,60+(dugumsayisi+1)*30);
        for(x=0;x<=dugumsayisi;x++)
        for(y=0;y<=dugumsayisi;y++)
        {
            setcolor(BLUE);
            rectangle(750,40,780+(x*30),70+(y*30));}

            for(i=0;i<dugumsayisi;i++)
        {
            setbkcolor(WHITE);
            setcolor(BLACK);
            outtextxy(790+(i*30),80+(i*30),"---");
        }

        //MATRIS BARINDAKI YAZILAR
         for(j=1;j<=uzakliksayisi;j++)
           {
            setbkcolor(WHITE);
            setcolor(RED);
            sprintf(arr,"%d",uzakliklar[j]);
            outtextxy(790+(sayx*30),80+(30*sayy),arr);
            sayx++;
            if(sayx==sayy){
            sayx++;
            }
            if(j%(dugumsayisi-1)==0)
            {
                sayx=0;
                sayy++;

            }


            }
            //MATRIS BARI D0,D1,...
            for(i=0;i<dugumsayisi;i++)
            {
                setcolor(BLACK);

                sprintf(arr2,"D%d",i);
                outtextxy(785+(i*30),47,arr2);

                sprintf(arr3,"D%d",i);
                outtextxy(755,80+(i*30),arr3);

            }
            //PRIM ALGORITMASI
                 bas:
                 for(x=0;x<dugumsayisi;x++)
                  {


                      for(y=1;y<dugumsayisi;y++)
                      {

                          if(primdugum[x]==1&&primdugum[y]==0)
                          {

                              if(sayacprim==1)
                              {
                              if(dugummatris1[x][y]<dugummatris1[x][sutun])
                              {
                                  sutun=y;

                                  if(y==dugumsayisi-1){
                                  primdugum[sutun]=1;
                                  degermatris[x][sutun]=100;
                                  sayacprim++;
                                  goto bas;
                                  }

                              }
                              else if(dugummatris1[x][y]>=dugummatris1[x][sutun])
                              {
                                  if(y==dugumsayisi-1){

                                  primdugum[sutun]=1;
                                  degermatris[x][sutun]=100;
                                  sayacprim++;
                                  goto bas;
                                  }
                              }

                            }
                        if(sayacprim>1){sayacyson++;

                                      if(dugummatris1[x][y]<dugummatris1[sifir][sayac_sifirla])
                                      {
                                          sayac_sifirla=y;
                                          sifir=x;
                                          if(sayacyson==dugumsayisi-sayacprim){

                                          adugum[x][sayac_sifirla]=dugummatris1[x][sayac_sifirla];
                                          adugumsayac++;
                                          sifir=0;
                                          sayac_sifirla=0;
                                          sayacyson=0;
                                          }
                                      }
                                      else
                                      {
                                  if(sayacyson==dugumsayisi-sayacprim){

                                  adugum[x][sayac_sifirla]=dugummatris1[x][sayac_sifirla];
                                  adugumsayac++;
                                  sifir=0;
                                  sayac_sifirla=0;
                                  sayacyson=0;
                                  }
                                  }
                                  if(adugumsayac==sayacprim){
                                  for(k=0;k<dugumsayisi;k++)
                                                   {
                                            for(l=0;l<dugumsayisi;l++)
                                                {if(adugum[k][l]!=100){
                                                    durdurmasayac++;
                                                    if(adugum[k][l]<adugum[satir0][sutun0]){
                                                    tmpsatir=satir0;
                                                    tmpsutun=sutun0;
                                                    satir0=k;
                                                    sutun0=l;

                                                    if(durdurmasayac==sayacprim)
                                                    {

                                                    primdugum[sutun0]=1;
                                                    sayacprim++;
                                                    adugum[k][l]=100;
                                                    degermatris[satir0][sutun0]=100;
                                                    satir0=0;
                                                    sutun0=0;
                                                    adugumsayac=0;
                                                    durdurmasayac=0;
                                                    adugumbosalt();
                                                    goto bas;
                                                            }
                                                            }
                                                    else
                                                        {
                                                        if(durdurmasayac==sayacprim)
                                                        {
                                                        primdugum[sutun0]=1;
                                                        sayacprim++;
                                                        adugum[k][l]=100;
                                                        degermatris[satir0][sutun0]=100;
                                                        satir0=0;
                                                        sutun0=0;
                                                        adugumsayac=0;
                                                        durdurmasayac=0;
                                                        adugumbosalt();
                                                        goto bas;
                                                        }
                                                        }
                                        }
                                        }
                                        }

                                }
                                }
                                }

                          }
                      }
            //DUGUM MATRISINE SECILEN UZUNLUKLARIN ATANMASI
         for(i=0;i<dugumsayisi;i++){
         for(j=0;j<dugumsayisi;j++){

         if(degermatris[i][j]!=100){
             dugummatris1[i][j]=100;}
         if(degermatris[i][j]==100){

             yolucizdir(dugumkoordinatx[i],dugumkoordinaty[i],dugumkoordinatx[j],dugumkoordinaty[j]);
             }
             if(dugummatris1[i][j]!=100){
         Toplam_maliyet=Toplam_maliyet+dugummatris1[i][j];}
         }
         }
                sprintf(arr,"Toplam Agac Maliyeti : %d br",Toplam_maliyet+1);
                setbkcolor(WHITE);
                setcolor(BLACK);
                outtextxy(65,680,arr);

         }


int mousesec()
{

    koordinatlarbosalt();

    while(true)
    if(ismouseclick(WM_LBUTTONDOWN))
{
    int x = mousex();
    int y = mousey();
    int sayacx=0;
    int sayacy=0;
	for(int i=65;i<=650;i+=30)
    {

         for(int j=65;j<=650;j+=30)
         {


             if(x>i&&x<i+30&&y>j&&y<j+30)
             {
             setcolor(RED);
             setbkcolor(RED);
             koordinatlar[sayacx][sayacy]=1;
             rectangle(i,j,i+30,j+30);
             outtextxy(i,j,"        ");
             outtextxy(i,j+15,"        ");
             }
            sayacy++;
            sayacy=sayacy%20;
         }
         sayacx++;
    }

    bar(800,600,900,650);
    setcolor(BLUE);
    rectangle(800,600,900,650);
    rectangle(805,605,895,645);
    setcolor(RED);
    setbkcolor(WHITE);
    outtextxy(830,616,"BITIR");
    if(x>800&&x<900&&y>600&&y<650)
    {
        setcolor(RED);
        rectangle(800,600,900,650);
        rectangle(805,605,895,645);
        setcolor(BLUE);
        setbkcolor(WHITE);
        outtextxy(830,616,"BITIR");
        prim();
        getch();
        return 0;
    }





clearmouseclick(WM_LBUTTONDOWN);
}

 return 0;
   }
int cizdirbos()
{
    int sayac=1;
    char arr[20];
    bar(20,20,700,700);

    for(int i=80;i<=650;i+=30)
    {sprintf(arr,"%d",sayac);
             setbkcolor(WHITE);
             setcolor(BLACK);
             outtextxy(38,i-3,arr);
             outtextxy(i-6,43,arr);
           sayac++;

         for(int j=80;j<=650;j+=30)
         {
             setcolor(BLUE);
             circle(i,j,10);
             setcolor(BLACK);
             rectangle(i-45,j-45,i+15,j+15);


         }
    }
    setcolor(WHITE);
    rectangle(35,35,670,670);
    setbkcolor(WHITE);


    setcolor(BLACK);
    outtextxy(40,45,"y");
    outtextxy(50,30,"x");
    line(35,35,65,65);



    mousesec();
    return 0;
}

int main()
{
    initwindow(1280,760);
    cizdirbos();
}

