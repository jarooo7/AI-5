//program demonstracyjny, kompilowany w Dev C++,
//na pocz¹tku programu za³¹czamy biblioteki i pliki naglowkowe ze zdefiniowanymi funkcjami
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
//Pliki z rozszerzeniem .h zawieraja tylko prototypy funkcji, kody znajduja
//sie w plikach o tych samych nazwach lecz z rozszerzeniem .cpp
#include "matrix.h"

//deklarujemy u¿ywanie przestrzeni nazw std, zawieraj¹cej wiele przydatnych komend,
//je¿eli nie zdeklarowalibyœmy przestrzeni nazw std, przed komendami tej przestrzeni nale¿a³oby u¿yæ zapisu std::
// np. std::cout<<"tekst";         
using namespace std;
double entropy(int* t, int m);
double* entropy2(int t[6][6], int m, int q);
struct klasy
{
	string nazwa[6];
	int liczebnosc[6];
	int ile;
};
struct dane
{
	string nazwa[6];
	int liczebnosc[6][6];
	int ile;
};

//w funkcji main mamy nasz g³ówny program,
int main (void) {
cout<<"Program pomocniczy do cw1\n";

//definiujemy nazwe pliku, musi istnieæ w katalogu programu
string nazwap="SystemDecyzyjny.txt";

//korzystamy z funkcji umieszczonych w pliku matrix.h
// w celu znalezienia rozmiaru wczytywanego pliku,
//plik powinien byc w formacie
//6 2 5 6 1
//5 8 9 2 0
int wym2=num_rows_file(nazwap.c_str());
int wym1=num_cols_file(nazwap.c_str());

//teraz deklarujemy dynamicznie tablice do, której wczytamy nasz plik,
int rows = wym2+1;
std::string **G;
G = new std::string*[rows];
while(rows--) G[rows] = new std::string[wym1+1];

////wczytujemy tablice w postaci string, czyli jej elementy traktujemy jako stringi(ci¹gi znaków)
//wym2 to liczba wierszy
//wym1 to liczba kolumn
//G nasza tablica stringów
//nazwap.c_str() podajemy nazwe wczytywanego pliku w odpowiednim formacie do funkcji.
cout<<"\n\nNacisnij ENTER aby wczytac tablice o nazwie "<< nazwap;
getchar();
wczytywanie(wym2,wym1,G,nazwap.c_str());
//wypisujemy wczytan¹ tablicê na ekran
cout<<"\nWypisujemy na ekran wczytana tablice\n\n";
for(int i=1;i<wym2+1;i++){
  for(int j=1;j<wym1+1;j++){
    cout<<" "<<G[i][j];
  }
  cout<<"\n";
} 


//******************************************************
//MIEJSCE NA ROZWIAZANIE 
klasy k;
bool a;
string drzewo[15][15];
int liczD[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int poziom=0;
int ilelisci[14][15];
k.ile=0;
for(int i=1;i<wym2+1;i++){
	a=true;
	for(int j=0;j<k.ile;j++){
	
		if(G[i][wym1]==k.nazwa[j])
		{
			k.liczebnosc[j]++;
			a=false;
		}
	}
	if(a)
	{
		k.nazwa[k.ile]=G[i][wym1];
		k.liczebnosc[k.ile]=1;
		k.ile++;	
	}
}
double w=entropy(k.liczebnosc, k.ile);
dane kol[wym1];
string nazwaK[wym1]={"","","Pogoda","Temperatura","Wilgotnosc","Wiatr"};
for(int i=2;i<wym1;i++){
	kol[i].ile=0;
	for(int m=0;m<6;m++)
	for(int n=0;n<6;n++)
		kol[i].liczebnosc[m][n]=0;
		
	for(int m=0;m<k.ile;m++)
	{
		for(int z=1;z<wym2+1;z++)
		{	
			a=true;
			if(G[z][wym1]==k.nazwa[m])
			{
			for(int n=0;n<kol[i].ile;n++)
			{
					if(G[z][i]==kol[i].nazwa[n])
					{
						kol[i].liczebnosc[m][n]++;
						a=false;
					}
				
			}
			if(a)
			{ 				
				kol[i].liczebnosc[m][kol[i].ile]++;
				kol[i].nazwa[kol[i].ile]=G[z][i];	
				kol[i].ile++;
			}
		}
		}
	}
}
double** wynik;
wynik= new double* [wym1];
for(int i=2;i<wym1;i++)
{
	wynik[i]=new double [kol[i].ile];
	wynik[i]=entropy2(kol[i].liczebnosc, kol[i].ile, k.ile);
}
double wynikkol[wym1];
int temp;
for(int i=2;i<wym1;i++)
{
	wynikkol[i]=w;
for(int j=0;j<kol[i].ile;j++)
 	{
 		temp=0;
 		for(int x=0;x<k.ile;x++)
 		{	
 			temp+=kol[i].liczebnosc[x][j];
 		}
	wynikkol[i]-=((double)(temp)/wym2*wynik[i][j]);
	}
}
double wynikkol2[10][wym1];
 double max=wynikkol[2];
 int idmax=2;
 string Testowe[10][wym2+1][wym1+1];
 int ileq[10];
 int iletest=0;
 dane kol2[10][wym1];
 double*** wynik2;
wynik2= new double** [10];
for(int j=0;j<10;j++){
wynik2[j]=new double* [wym1];
}
int idmax2[10];
double max2[10];
 for(int i=2;i<wym1;i++)
{
	if(max<wynikkol[i])
		{
			max=wynikkol[i];
			idmax=i;	
		}
	}
		
	drzewo[poziom][liczD[poziom]]=nazwaK[idmax];
	ilelisci[poziom][liczD[poziom]]=0;
	liczD[poziom]++;
	poziom++;
	bool czyZERO;
	int idNZERO;
	 for(int i=0;i<kol[idmax].ile;i++)
	{
			ilelisci[poziom-1][liczD[poziom-1]-1]++;
			drzewo[poziom][liczD[poziom]]=kol[idmax].nazwa[i];
			liczD[poziom]++;
	}
	poziom++;
	liczD[poziom+1]=0;
	for(int i=0;i<kol[idmax].ile;i++)
	{ 	
		ilelisci[poziom-1][i]=0;
		czyZERO=false;
		for(int j=0;j<k.ile;j++){
			if(kol[idmax].liczebnosc[j][i]==0)
			{
				czyZERO=true;
			}
			}
			if(czyZERO)
			{
				for(int j=0;j<k.ile;j++)
				{
					if(kol[idmax].liczebnosc[j][i]!=0)
					{
						ilelisci[poziom-1][i]++;
						drzewo[poziom][liczD[poziom]]=k.nazwa[j];
						liczD[poziom]++;
						ilelisci[poziom][i]=0;
					}
				}
			}
			else
			{
				ileq[i]=0;
				iletest++;
				for(int qw=1;qw<=wym2;qw++)
				{
					if(G[qw][idmax]==kol[idmax].nazwa[i]){
					for(int qk=1;qk<=wym1;qk++)
					Testowe[i][ileq[i]][qk]=G[qw][qk];
					ileq[i]++;}
					
			}
				
					
	for(int i2=2;i2<wym1;i2++){
		
	kol2[i][i2].ile=0;
	for(int m=0;m<6;m++)
	for(int n=0;n<6;n++)
		kol2[i][i2].liczebnosc[m][n]=0;
		
	for(int m=0;m<k.ile;m++)
	{
		for(int z=0;z<ileq[i];z++)
		{	
			a=true;
			if(Testowe[i][z][wym1]==k.nazwa[m])
			{
			for(int n=0;n<kol2[i][i2].ile;n++)
			{
					if(Testowe[i][z][i2]==kol2[i][i2].nazwa[n])
					{
						kol2[i][i2].liczebnosc[m][n]++;
						a=false;
						
					}
					
				
			}
			if(a)
			{ 				
				kol2[i][i2].liczebnosc[m][kol2[i][i2].ile]++;
				kol2[i][i2].nazwa[kol2[i][i2].ile]=Testowe[i][z][i2];	
				kol2[i][i2].ile++;
			}
		}
		}
	}

					
	}
				
			for(int qk=2;qk<wym1;qk++){
			
				wynik2[i][qk]=new double [kol2[i][qk].ile];
				wynik2[i][qk]=entropy2(kol2[i][qk].liczebnosc, kol2[i][qk].ile, k.ile);
				
			}	
			
			for(int qk=2;qk<wym1;qk++){
			
				wynikkol2[i][qk]=wynik2[i][idmax][0];
				if(qk!=idmax)
				for(int j=0;j<kol2[i][qk].ile;j++)
 				{
 					temp=0;
 					for(int x=0;x<k.ile;x++)
 					{	
 						temp+=kol2[i][qk].liczebnosc[x][j];
 					}
					wynikkol2[i][qk]-=((double)(temp)/ileq[i]*wynik2[i][qk][j]);
				}
			
			}
			temp=2;
			do{
				idmax2[i]=temp;
				max2[i]=wynikkol2[i][temp];
				temp++;
			}while(temp-1==idmax);
			 for(int i3=2;i3<wym1;i3++)
{
	
	if(max2[i]<wynikkol2[i][i3]&&i3!=idmax)
		{
			max2[i]=wynikkol2[i][i3];
			idmax2[i]=i3;	
		}
	}
			
				ilelisci[poziom-1][i]++;
						drzewo[poziom][liczD[poziom]]=nazwaK[idmax2[i]];
						liczD[poziom]++;
				ilelisci[poziom][i]=0;
				
				for(int j=0;j<kol2[i][idmax2[i]].ile;j++)
				{
					ilelisci[poziom][i]++;
						drzewo[poziom+1][liczD[poziom+1]]=kol2[i][idmax2[i]].nazwa[j];
						ilelisci[poziom+1][liczD[poziom+1]]=0;
						liczD[poziom+1]++;
						
						czyZERO=false;
						for(int w=0;w<k.ile;w++){
						if(kol2[i][idmax2[i]].liczebnosc[w][j]==0)
						{
							czyZERO=true;
						}
						}
						if(czyZERO)
				{
				for(int w=0;w<k.ile;w++)
				{
					if(kol2[i][idmax2[i]].liczebnosc[w][j]!=0)
					{
						ilelisci[poziom+1][liczD[poziom+1]-1]++;
						drzewo[poziom+2][liczD[poziom+2]]=k.nazwa[w];
						liczD[poziom+2]++;
					
					}
				}
			}		
		}
		}
	}
	
			
	
	/*
for(int o=0;o<iletest;o++)
	{	
	for(int i=2;i<wym1;i++)
{
  cout<<"////////////////////"<<endl;
 	for(int j=0;j<kol2[o][i].ile;j++)
 	{
 	
 		cout<<kol2[o][i].nazwa[j];
 		for(int z=0;z<k.ile;z++)
 		cout<<kol2[o][i].liczebnosc[z][j];
 		cout<<endl;
	}
	cout<<endl;
}
cout<<endl;
}*/
cout<<endl;
cout<<"Entropy(S) = "<<w<<endl;
cout<<endl;
for(int i=2;i<wym1;i++)
{
	cout<<endl<<nazwaK[i]<<" = "<<wynikkol[i]<<endl<<"{\n";
	for(int j=0;j<kol[i].ile;j++)
	{
		cout<<kol[i].nazwa[j]<<" = "<<wynik[i][j]<<endl;
	}
	cout<<"}"<<endl;
}
for(int h=0;h<kol[idmax].ile;h++)
{
	if(wynik[idmax][h]!=0){
	
	cout<<endl;
cout<<"Entropy ("<<kol[idmax].nazwa[h]<<") = "<<w<<endl;
cout<<endl;
	
for(int i=2;i<wym1;i++)
{	
	
	if(i!=idmax){
	
	cout<<endl<<nazwaK[i]<<" = "<<wynikkol2[h][i]<<endl<<"{\n";
	for(int j=0;j<kol2[h][i].ile;j++)
	{
		cout<<kol2[h][i].nazwa[j]<<" = "<<wynik2[h][i][j]<<endl;
	}
	cout<<"}"<<endl;}
}
}}





int temp2;
int temp3;
int temp4;
int temp5;
int temp6=0;
temp4=0;
	cout<<"\n\n////////////////////\nDrzewo decyzyjne\n////////////////////\n\n"<<drzewo[0][0]<<"\n|\n";
		temp =0;
		temp2=0;
		for(int j=0;j<liczD[1];j++)
		{
			cout<<"|\n|__\n|  |\n|  "<<drzewo[1][j]<<"\n";
			
			temp3=temp4;
			for(int k=temp;k<temp+ilelisci[1][j];k++)
			{
			
				cout<<"|   |\n|   |_____\n|	 |\n|	 |\n|	"<<drzewo[2][k]<<"\n|	   |\n";
				temp2++;
				temp5=temp6;
					for(int l=temp3;l<temp3+ilelisci[2][k];l++)
					{
						
						cout<<"|	   |\n|	   |_______\n|	   |	   |\n|	   |	 "<<drzewo[3][l]<<"\n|	   |	   |\n";
						temp4++;
						for(int fl=temp5;fl<temp5+ilelisci[3][l];fl++)
						{
							cout<<"|	   |	   |\n|	   |	   |_______\n|	   |	   |	   |\n|	   |	   |	  "<<drzewo[4][fl]<<"\n|	   |	   	   \n";
							temp6++;
						}
						temp5=temp6;
					}
					temp3=temp4;
			}
			temp=temp2;
		}
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;

		

//KONIEC MIEJSCA NA ROZWIAZANIE  
//******************************************************


//funkcja zapisuje tablice stringów do pliku, podajemy
string nazwap2="plik_do zapisu.txt";
cout<<"\n\nNacisnij ENTER aby wykonac demonstracyjny zapis pliku o nazwie "<<nazwap2;
getchar();
zapis(wym2,wym1,G,nazwap2.c_str());

//na koniec czyœcimy pamiêæ po naszej tablicy
for(int i=0;i<wym2+1;i++)
{delete[] G[i];}//czyscimy wiersze
delete[] G;//zwalniamy tablice wskaznikow do wierszy

cout<<"\n\nNacisnij ENTER aby zakonczyc";
getchar();

//na koniec nasza funkcja zwraca wartoœæ 0 i program siê koñczy
return 0;
}

double entropy(int* t, int m)
{
	int s=0;
	for(int i=0;i<m;i++)
	s+=t[i];
	double a=0;
	for(int i=0;i<m;i++)
	a-=((double)(t[i])/s)*(log(((double)(t[i])/s))/log(2));
	return a;
}
double* entropy2(int t[6][6], int m, int q)
{
	int s;
	double *an;
	an=new double [q];
	for(int n=0;n<m;n++)
	{
		an[n]=0;
		s=0;
		for(int z=0;z<q;z++)
		{
			s+=t[z][n];	
	
		}
		
		for(int z=0;z<q;z++)
		{
			if(t[z][n]!=0)
			{
			an[n]-=((double)(t[z][n])/s)*(log(((double)(t[z][n])/s))/log(2));
			}
		}
	}
	return an;
}
