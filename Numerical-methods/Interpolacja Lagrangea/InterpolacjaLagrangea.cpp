#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;

void interpolacja_lagrangea(void)
	{
	fstream file;
    file.open("InterpolacjaLagrangea.txt",ios::in);
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
        //wezly[a]=atol(temp);
        getline(file,temp);
        wartosci_funkcji[a]=atoi(temp.c_str());
        //wartosci_funkcji[a]=atol(temp);
        }
    file.close();

    double argument;
    cout<<"Podaj punkt dla ktorego trzeba obliczyc wartosc wielomianu interpolacyjnego ";cin>>argument;cout<<endl;

	for(int e=0;e<ilosc_wezlow;e++)
		{cout<<wezly[e]<<"\t\t"<<wartosci_funkcji[e]<<endl;}

	for(int b=0;b<ilosc_wezlow;b++)
		{
		obliczenia[b]=wartosci_funkcji[b];
		//licznik ze wzoru na L(x)
		for(int c=0;c<ilosc_wezlow;c++)
			{
			if(wezly[b]!=wezly[c])
				{obliczenia[b]=obliczenia[b]*(argument-wezly[c]);}
			}
		//mianownik	ze wzoru na L(x)
		for(int c=0;c<ilosc_wezlow;c++)
			{
			if(wezly[b]!=wezly[c])
				{obliczenia[b]=(obliczenia[b]/(wezly[b]-wezly[c]));}
			}
		}

	double suma_tablicy_obliczenia=0;
	for(int d=0;d<ilosc_wezlow;d++)
		{//liczenie Ln(x)
		suma_tablicy_obliczenia=suma_tablicy_obliczenia+obliczenia[d];
		}
	cout<<"\nDla argumentu x="<<argument<<" wielomian interpolacyjny przyjmuje wartosc "<<suma_tablicy_obliczenia<<endl;
	}


int main()
{
	interpolacja_lagrangea();
  	return 0;
}

