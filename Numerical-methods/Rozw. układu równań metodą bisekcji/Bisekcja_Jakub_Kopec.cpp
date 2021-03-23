#include<iostream>
#include<string>
#include<cmath>
using namespace std;

const int ilosc=10;

//2x^7+4x^2+2x-14=0
double rownanie_wielomian(double argument)
	{
	/*//alternatywna oraz przekombinowana wersja
	double wynik;
	double skladowe_rownania[ilosc]={0};
    skladowe_rownania[0]=2*pow(argument,7);
    skladowe_rownania[1]=4*pow(argument,3);
    skladowe_rownania[2]=2*argument;
    //zmiana rowniania wewnatrz logaytmu wiaze sie z dodaniem wyrazenia do tablicy skladowe_rownania
    for(int a=0;a<ilosc;a++)
        {wynik=wynik+skladowe_rownania[a];}
    cout<<"x="<<argument<<"\t\twartosc="<<wynik<<endl;
    return wynik;*/
    return 2*argument*argument*argument*argument*argument*argument*argument+4*argument*argument+2*argument-14;
	}
//ln(1.5x^2)=0
double rownanie_logarytm(double argument)
	{
	/*//alternatywna oraz przekombinowana wersja
	long double wynik;
	double skladowe_rownania[ilosc]={0};
    skladowe_rownania[0]=pow(argument,2);
    skladowe_rownania[1]=2*argument;
    //zmiana rowniania wewnatrz logaytmu wiaze sie z dodaniem wyrazenia do tablicy skladowe_rownania
    for(int a=0;a<ilosc;a++)
        {wynik=wynik+skladowe_rownania[a];}

    wynik=log(wynik);
    cout<<"x="<<argument<<"\t\twartosc="<<wynik<<endl;
    return wynik;*/
    return log(1.5*argument*argument);
	}
//-2x+cos(4x^3)=0
double rownanie_tryg(double argument)
	{
	/*//alternatywna oraz przekombinowana wersja
	double wynik;
	double skladowe_rownania[ilosc]={0};
    skladowe_rownania[0]=cos(4*pow(argument,3));
    skladowe_rownania[1]=2*argument;
    //zmiana rowniania wewnatrz logaytmu wiaze sie z dodaniem wyrazenia do tablicy skladowe_rownania
    for(int a=0;a<ilosc;a++)
        {wynik=wynik+skladowe_rownania[a];}
    cout<<"x="<<argument<<"\t\twartosc="<<wynik<<endl;
    return wynik;*/
    return cos(4*argument*argument*argument)-2*argument;
	}
//algorytm rozwiazywania rownan

int bisekcja(double precyzja,double poczatek_przedzialu,double koniec_przedzialu,string rodzaj)
    {
    double srodek;
    if(rodzaj=="wielomianowe")
        {
        if(rownanie_wielomian(koniec_przedzialu)*rownanie_wielomian(poczatek_przedzialu)>=0)
            {
            cout<<"Rownanie nie ma rozwiazan lub ma ich parzysta ilosc lub wprowadzono bledne dane!";return -1;
            }
        while((koniec_przedzialu-poczatek_przedzialu)>=precyzja)
            {
            srodek=(poczatek_przedzialu+koniec_przedzialu)/2;
            if(rownanie_wielomian(srodek)==0)
                {return srodek;}
            else if((rownanie_wielomian(srodek)*rownanie_wielomian(poczatek_przedzialu))<0)
                {koniec_przedzialu=srodek;}
            else
                {poczatek_przedzialu=srodek;}
            cout<<srodek<<"\t\t"<<rownanie_wielomian(srodek)<<endl;
            }
        cout<<"\nRozwiazanie:\tx="<<srodek<<"\t\ty="<<rownanie_wielomian(srodek)<<endl;return srodek;
        }
//_______________________________________________________________________________________
    else if(rodzaj=="logarytmiczne")
        {
        if(rownanie_logarytm(koniec_przedzialu)*rownanie_logarytm(poczatek_przedzialu)>=0)
            {
            cout<<"Rownanie nie ma rozwiazan lub ma ich parzysta ilosc!";return -1;
            }
        while((koniec_przedzialu-poczatek_przedzialu)>=precyzja )
            {
            srodek=(poczatek_przedzialu+koniec_przedzialu)/2;
            if(rownanie_logarytm(srodek)==0)
                {return srodek;}
            else if((rownanie_logarytm(srodek)*rownanie_logarytm(poczatek_przedzialu))<0)
                {koniec_przedzialu=srodek;}
            else
                {poczatek_przedzialu=srodek;}
            cout<<srodek<<"\t\t"<<rownanie_logarytm(srodek)<<endl;
            }
        cout<<"\nRozwiazanie:\tx="<<srodek<<"\t\ty="<<rownanie_logarytm(srodek)<<endl;return srodek;
        }
//____________________________________________________________________________________
    else if(rodzaj=="trygonometryczne")
        {
        if(rownanie_tryg(koniec_przedzialu)*rownanie_tryg(poczatek_przedzialu)>=0)
            {
            cout<<"Rownanie nie ma rozwiazan lub ma ich parzysta ilosc!";return -1;
            }
        while((koniec_przedzialu-poczatek_przedzialu)>=precyzja)
            {
            srodek=(poczatek_przedzialu+koniec_przedzialu)/2;
            if(rownanie_tryg(srodek)==0)
                {return srodek;}
            else if((rownanie_tryg(srodek)*rownanie_tryg(poczatek_przedzialu))<0)
                {koniec_przedzialu=srodek;}
            else
                {poczatek_przedzialu=srodek;}
            cout<<srodek<<"\t\t"<<rownanie_tryg(srodek)<<endl;
            }
        cout<<"\nRozwiazanie:\tx="<<srodek<<"\t\ty="<<rownanie_tryg(srodek)<<endl;return srodek;
        }
   }


int main()
    {
    double poczatek_przedzialu,koniec_przedzialu,precyzja;
    cout<<"Podaj dokladnosc obliczen!\t";cin>>precyzja;
    cout<<"\nPodaj poczatek przedzialu!\t";cin>>poczatek_przedzialu;
    cout<<"\nPodaj koniec przedzialu!\t";cin>>koniec_przedzialu;cout<<endl;
    cout<<"\nROWNANIE WIELOMIANOWE\n";
    bisekcja(precyzja,poczatek_przedzialu,koniec_przedzialu,"wielomianowe");
    cout<<"\nROWNANIE LOGARYTMICZNE\n";
    bisekcja(precyzja,poczatek_przedzialu,koniec_przedzialu,"logarytmiczne");
    cout<<"\nROWNANIE TRYGONOMETRYCZNE\n";
    bisekcja(precyzja,poczatek_przedzialu,koniec_przedzialu,"trygonometryczne");
    return 0;
  	}

