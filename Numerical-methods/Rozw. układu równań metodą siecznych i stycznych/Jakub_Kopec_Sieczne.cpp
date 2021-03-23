#include<iostream>
#include<cmath>
using namespace std;

double rownanie(double x)
	{
	//2x^2-7x+1.5
    return 2*x*x-7*x+1.5;
    //return pow(x, 3) + x - 1;
	}
double pochodna(double x)
    {
    //4x-7
    return 4*x-7;
    }

int metoda_newtona()
    {
    cout<<"\tMETODA NEWTONA\n";
    double poczatek_przedzialu,koniec_przedzialu,precyzja;
    cout<<"Podaj dokladnosc obliczen!\t";cin>>precyzja;
    cout<<"Podaj poczatek przedzialu!\t";cin>>poczatek_przedzialu;
    cout<<"Podaj koniec przedzialu!\t";cin>>koniec_przedzialu;cout<<endl;
    double roznica=1000000000,kroki=0;
    double x=poczatek_przedzialu;
    if(rownanie(koniec_przedzialu)*rownanie(poczatek_przedzialu)>=0)
        {
        cout<<"Rownanie nie ma rozwiazan lub ma ich parzysta ilosc lub wprowadzono bledne dane!";return -1;
        }
    double punkt_startowy;
    cout<<"Podaj punkt startowy: ";cin>>punkt_startowy;
    while(punkt_startowy<poczatek_przedzialu||punkt_startowy>koniec_przedzialu)
        {cout<<"Podaj punkt startowy: ";cin>>punkt_startowy;}
    while(abs(roznica)>=precyzja)
        {
        roznica=rownanie(x)/pochodna(x);
        x=x-roznica;
        kroki++;
        cout<<x<<"\t"<<rownanie(x)<<endl;
        }
    cout<<"Znaleziono rozwiazanie: x= "<<x<<"\ty= "<<rownanie(x)<<"\nIlosc krokow: "<<kroki;
    return 0;
    }

int metoda_siecznych()
    {
    cout<<"\tMETODA SIECZNYCH\n";
    double x0,x1,x2,x3,precyzja;
    cout<<"Podaj dokladnosc obliczen!\t";cin>>precyzja;
    cout<<"Podaj pierwszy punkt startowy!\t";cin>>x1;
    cout<<"Podaj drugi punkt startowy!\t";cin>>x2;cout<<endl;
    double iloraz,kroki=0;
    double x;
    double zero;
    do//konieczna byla zmiana typu petli z powodu pierwszego wykonania - zwykly while nie zapewnilby pierwszej iteracji algorymtu
        {
        x=x2-(rownanie(x2)*(x2-x1))/(rownanie(x2)-rownanie(x1));
        zero=rownanie(x0)*rownanie(x1);
        x1=x2;
        x2=x;
        kroki++;
        if(rownanie(zero)==0)
            {cout<<"\nIF\n\n";break;}
        //zmiana x1,x2 wiec zmiana wartosci wyrazenia
        x3=x2-(rownanie(x2)*(x2-x1))/(rownanie(x2)-rownanie(x1));
        cout<<x<<"\t"<<rownanie(x)<<endl;
        }
    while(fabs(rownanie(x))>=precyzja);
    cout<<"Znaleziono rozwiazanie: x= "<<x<<"\ty= "<<rownanie(x)<<"\nIlosc krokow: "<<kroki;
    return 0;
    }


int main()
    {

    metoda_newtona();
    cout<<"\n\n\n\n\n";
    metoda_siecznych();
    cout<<"\n\n\n";
    return 0;
  	}

