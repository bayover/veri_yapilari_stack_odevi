#include<stdio.h> //c kutuphanesi
#define size 9    //diziler icin max eleman degeri

int ust=-1,eleman,stack[size]; //degiskenler ve diziler
int i;                         //sayac degiskenleri
char key;                      //karakter degiskenleri

char menu();                   //menu fonksiyonu tanýmý

main() //ana fonksiyon
{
	char secim;  //secimle icin kullanilan degisken
	do   //kosul saglandigi surece yapmasi icin do fonksiyonu
	{
		secim=menu();   //secim'i menuden donen degere esitle
		switch(secim)   //secime gore degerlendir
		{
			case '1': ekle(); goster(); getch(); temizle(); break;
			case '2': cikar(); goster(); getch(); temizle(); break;
			case '3': goster(); getch(); temizle(); break;
		}
	}while(secim<='3'&&secim>='1');    //do icin kosul
	getch(); temizle(); return main(); //kosul saglanmazsa uygula
}

char menu() //menu fonksiyonu
{
	printf("1-Eleman Ekle\n2-Eleman Cikar(En Ustteki Eleman)\n3-Goster\n\n\n"); //menu
	key=getch();  //direkt tek karakter olarak bellege al
	return key;   //degeri disariya dondur
}

void ekle()//push
{
	printf("Eleman giriniz: "); scanf("%d",&eleman); //kullanicidan eleman al ve bellege kaydet
	if(ust+1==size)                //stack'in son degeri(top)'nin bir fazlasi max karakter degerine esitse
	{
		printf("STACK DOLU!!\n");  //stack'in dolu oldugunu soyle
	}
	else                          //yukaridaki kosul disinda
	{
		ust++;                   //ust degiskenini 1 artýr
		stack[ust]=eleman;       //stack dizisinin ust. indeksini eleman degerine esitle
		printf("\n%d EKLENDI\n\n",eleman); //bu degeri yazdir
	}
}

void cikar()//pop
{
	if(ust==-1)          //ust degiskeni ilk degerinde ise yani -1 ise
	{
		printf("STACK BOS!!"); getch(); temizle(); return main(); //stack'in bos oldugunu soyle		
	}
	else                //stack bos degilse
	{
		goster(); printf("\n");  //once stack'i goster ve bir alta in
		printf("Cikarilan Eleman-->%d\n",stack[ust]);  //sonra stack'in top elemanini goster
		ust--;            //sonra da stack'in top elemanini azalt(sil)
	}
}

void goster()   //stack'i gosteren fonksiyon
{
	for(i=0;i<ust+1;i++)         //stack'in eleman sayisi kadar donecek bir dongu
	{
		printf("%d ",stack[i]);  //stack'in i. indexini bastir
	}
	printf("<--En ust eleman");  //en ust elemani gostermek adina
}

void temizle() //temizleme fonksiyonu
{
	system("cls");   //gerektigi yerlerde terminali temizlemek icin
}
