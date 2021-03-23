#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;

void interpolacja_newtona(void)
	{
	fstream file;
    file.open("InterpolacjaNewtona.txt",ios::in);
    if(file.good()==false)
        {cout<<"Blad pliku tekstowego!\n";}
    string temp;
    int ilosc_wezlow;
    file>>ilosc_wezlow;
    //ilosc_wezlow=atoi(temp.c_str());
    //pierwsza linia z pliku - ilosc punktow i jedna linia odstepu
    getline(file,temp);
    getline(file,temp);
    //kolejne linie - wezel,wartosc funkcji,wezel...
    double wezly[ilosc_wezlow];
    double wartosci_funkcji[ilosc_wezlow];
    double obliczenia[ilosc_wezlow];
    for(int a=0;a<ilosc_wezlow;a++)
        {
        getline(file,temp);
        wezly[a]=atoi(temp.c_str());
        getline(file,temp);
        wartosci_funkcji[a]=atoi(temp.c_str());
        }
    file.close();

	double ilorazy_roznicowe[2*ilosc_wezlow-1][ilosc_wezlow-1];
    int kolumna=0;
    int wiersz_gorny=1;
    int wiersz_dolny=(2*ilosc_wezlow)-2;
    int wiersz_przesuwany=wiersz_gorny;
    int indeks_wartosci=0;
    int ostatnia_kolumna=ilosc_wezlow-1;
	double L,M;

	//kolumna 0
    while(wiersz_przesuwany<=wiersz_dolny)
        {
		//cout<<"\nPrzesuwany\t"<<wiersz_przesuwany;
		//cout<<"\nDolny\t\t"<<wiersz_dolny;
    	L=wartosci_funkcji[indeks_wartosci+1]-wartosci_funkcji[indeks_wartosci];
        M=wezly[indeks_wartosci+1]-wezly[indeks_wartosci];
        ilorazy_roznicowe[wiersz_przesuwany][kolumna]=L/M;
        indeks_wartosci++;
        //WYPISYWANIE WYNIKU
        //cout<<ilorazy_roznicowe[wiersz_przesuwany][kolumna]<<endl;
        wiersz_przesuwany=wiersz_przesuwany+2;
        }
    kolumna++;
    wiersz_gorny++;
    wiersz_dolny--;
    wiersz_przesuwany=wiersz_gorny;
    //cout<<endl;

    //kolejne kolumny
    while(kolumna!=(ilosc_wezlow-1))
	{
	int licznik=0;
	int licznik2=0;
    while(wiersz_przesuwany<=wiersz_dolny)
        {
	    if(kolumna%2==1)
	        {//powinno byc ok dla nieparzystych kolumn
	        //cout<<"\nGorny\t\t"<<wiersz_gorny;
	        //cout<<"\nPrzesuwany\t"<<wiersz_przesuwany;
			//cout<<"\nDolny\t\t"<<wiersz_dolny;
	        L=ilorazy_roznicowe[wiersz_przesuwany+1][kolumna-1]-ilorazy_roznicowe[wiersz_przesuwany-1][kolumna-1];
	        M=wezly[kolumna+1+licznik]-wezly[kolumna-1+licznik];
	        //cout<<"\nL="<<L<<endl;
	        //cout<<"M="<<M<<endl;
	        ilorazy_roznicowe[wiersz_przesuwany][kolumna]=L/M;
	        //WYPISYWANIE WYNIKU
	        //cout<<ilorazy_roznicowe[wiersz_przesuwany][kolumna]<<endl;
	        wiersz_przesuwany=wiersz_przesuwany+2;
	        licznik++;
	        }
	    else
	        {
	        //cout<<"\nGorny\t\t"<<wiersz_gorny;
	        //cout<<"\nPrzesuwany\t"<<wiersz_przesuwany;
			//cout<<"\nDolny\t\t"<<wiersz_dolny;
	        L=ilorazy_roznicowe[wiersz_przesuwany+1][kolumna-1]-ilorazy_roznicowe[wiersz_przesuwany-1][kolumna-1];
	        M=wezly[kolumna+licznik2+1]-wezly[0+licznik2];
	        licznik2++;
	        //cout<<"\nL="<<L<<endl;
	        //cout<<"M="<<M<<endl;
	        ilorazy_roznicowe[wiersz_przesuwany][kolumna]=L/M;
	        //WYPISYWANIE WYNIKU
            //cout<<ilorazy_roznicowe[wiersz_przesuwany][kolumna]<<endl;
	        wiersz_przesuwany=wiersz_przesuwany+2;
	        licznik++;
	        }
        }
	    kolumna++;
	    wiersz_gorny++;
	    wiersz_dolny--;
	    wiersz_przesuwany=wiersz_gorny;
	    ostatnia_kolumna=kolumna;
	    //cout<<endl;
		}
	kolumna=0;
	wiersz_gorny=kolumna+1;
	int temp2=1;
    cout<<"Dla danych z pliku tekstowego wielomian interpolacyjny ma postac:\t Wn(x)=0+";
    for(int a=0;a<ilosc_wezlow-1;a++)
        {
        cout<<ilorazy_roznicowe[1+a][a];
        for(int b=0;b!=temp2;b++)
            {
            cout<<"(x-"<<wezly[b]<<")";
            }
        cout<<"+";
        temp2++;
        }
    //cout<<endl;

    /*for(int c=0;c<2*ilosc_wezlow-1;c++)
        {
        for(int d=0;d<ilosc_wezlow-1;d++)
            {cout<<ilorazy_roznicowe[c][d]<<"\t\t\t";}
        cout<<endl;
        }*/

    double punkt;
    double wartosc=0;
    temp2=1;
    string warunek="y";
    double segmenty[ilosc_wezlow-1];

    while(warunek=="y")
        {
        cout<<"\nPodaj punkt dla ktorego ma zostac obliczona wartosc     wielomianu:\t ";cin>>punkt;
        for(int a=0;a<ilosc_wezlow-1;a++)
            {
            segmenty[a]=ilorazy_roznicowe[1+a][a];
            for(int b=0;b!=temp2;b++)
                {
                segmenty[a]=segmenty[a]*(punkt-wezly[b]);
                }
            temp2++;
            wartosc+=segmenty[a];
            cout<<"Wspolczynnik "<<a+1<<":"<<segmenty[a]<<endl;
            }
        cout<<"Wartosc wielomianu dla punktu: "<<punkt<<"="<<wartosc<<endl;
        for(int a=0;a<ilosc_wezlow-1;a++)
            {
            segmenty[a]=0;
            wartosc=0;
            temp2=1;
            }
        cout<<"Obliczyc wartosc dla kolejnego punktu? y -> tak, dowolny klawisz+enter -> nie\t";cin>>warunek;
        }
    }

int main()
{
	interpolacja_newtona();
  	return 0;
}
