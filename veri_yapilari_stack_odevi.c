#include<stdio.h> //c kutuphanesi
#define size 40   //diziler icin max eleman degeri

struct node      //node ismindeki yapi
{
	char eleman[size];  //elemanlari saklayan dizi
	struct node *next;  //bagli listenin bir sonraki dugumlari icin bir pointer
};

struct node *push(); 
struct node *getNode();
struct node *baslangic=NULL;   //yapimiza ait degisken pointerlar
struct node *temp;           
struct node *silinecek;           
struct node *onceki;           
struct node *veri; 

int i;

char key;
char menu();                   //menu fonksiyonu tanimi

main() //ana fonksiyon
{
	char secim;  //secimle icin kullanilan degisken
	do   //kosul saglandigi surece yapmasi icin do fonksiyonu
	{
		secim=menu();   //secim'i menuden donen degere esitle
		switch(secim)   //secime gore degerlendir
		{
			case '1': push(); getch(); temizle(); break;
			case '2': pop(); getch(); temizle(); break;
			case '3': goster(); getch(); temizle(); break;
		}
	}while(secim<='3'&&secim>='1');    //do icin kosul
	getch(); temizle(); return main(); //kosul saglanmazsa uygula
}

char menu() //menu fonksiyonu
{
	printf("1-Eleman Ekle\n2-Eleman Cikar\n3-Goster\n\n\n"); //menu
	key=getch();  //direkt tek karakter olarak bellege al
	return key;   //degeri disariya dondur
}

struct node *getNode()    //istenilen veri icin bellekten yer ayirdigim fonksiyon
{
    return((struct node *)malloc(sizeof(struct node)));    
}

struct node *push()//push(ekleme) fonksiyonu
{
	while(baslangic!=NULL)    //zaten stackte bir veri varsa
	{
		veri=getNode();       //veri icin bellekten yer al
		temp=baslangic;       //gecici degiskene baslangic degerini tanimla
		while(temp->next!=NULL) //gecici degiskenin bir sonraki degeri NULL degilse
		{
			temp=temp->next;   //gecici degiskeni, gecici degiskenin bir sonraki degerine ata
		}
		printf("Eleman giriniz: "); scanf("%s",&veri->eleman);  //kullanicidan eleman iste ve bunu bellege al
		printf("\n%s EKLENDI\n\n",veri->eleman);                //alinan bellegi kullaniciya goster
		temp->next=veri;   //gecici degiskenden sonraki degeri veri degerine esitle
		veri->next=NULL;   //verinin bir sonraki degerini NULL yap. Siradaki deger icin
		return goster();   //goster fonksiyonunu dondur
	}
	//stackte bir veri yoksa
	veri=getNode();    //veri icin bellekten yer al
	baslangic=veri;    //baslangic degerini veriye esitle. Cunku ortada daha bir veri yok
	temp=baslangic;    //gecici degiskene baslangic degerini tanimla
	printf("Eleman giriniz: "); scanf("%s",&veri->eleman); //kullanicidan eleman iste ve bunu bellege al
	printf("\n%s EKLENDI\n\n",veri->eleman);               //alinan bellegi kullaniciya goster
	veri->next=NULL;          //verinin bir sonraki degerini NULL yap. Siradaki deger icin
	goster();                 //goster fonksiyonunu calistir
}

void pop()//pop
{
	if(baslangic==NULL)  //baslangic degeri NULL ise yani stack bossa
	{
		printf("STACK ZATEN BOS");  //stack'in bos oldugun soyle
	}
	else
	{
		goster(); printf("\n");  //once stack'i goster ve bir alta in
		temp=baslangic;
		silinecek=baslangic;     //silinecek gecici degerine baslangic degerini ata
		onceki=baslangic;        //onceki gecici degerine baslangic degerini ata
		while(silinecek->next!=NULL)//silinecek degerin bir sonraki degeri NULL degilse yani sonda degilse
		{
			onceki=silinecek;       //onceki degeri silinecek degerine ata
			silinecek=silinecek->next; //silinecek degeri bir sonraki degere esitle (dongu silinecek deger son degere gelmek sartiyla donecek yani)
		}
		if(silinecek==baslangic)//silinecek deger baslangic degerine esitse(bir tane eleman varsa gibi)
		{
			baslangic=NULL;  //baslangic degerini NULL yap. (Siliyor direkt her seyi)
		}
		else
		{
			onceki->next=NULL;   //silinecek deger baska bir seye esitse onceki degerin bir sonraki degerine NULL ata.
		}
		printf("\nCikarilan Eleman-->%s\n\n",silinecek);  //sonra stack'in top elemanini goster
		free(silinecek);  //silinecek degerin bellekteki yerini sil
		goster();         //elemanlari goster
	}
}

void goster()   //stack'i gosteren fonksiyon
{
	if(baslangic==NULL)  //baslangic NULL ise yani stack bos ise
	{
		printf("STACK BOS!!");  //stack'in bos oldugunu soyle
	}
	else                       //yukaridaki kosul disinda
	{
		temp=baslangic;       //gecici degiskeni baslangic'a ata
		while(temp!=NULL)     //gecici degisken NULL olmadigi surece don
		{
			for(i=1;i<temp;i++)  //1 den baslayip temp degeri kadar don
			{
				printf("%s ",temp->eleman); //elemanlari goster
				temp=temp->next;            //her seferinde bir sonraki eleamana gec
			}
				printf("<--En ust eleman"); 
		}
	}
}

void temizle() //temizleme fonksiyonu
{
	system("cls");   //gerektigi yerlerde terminali temizlemek icin
}
