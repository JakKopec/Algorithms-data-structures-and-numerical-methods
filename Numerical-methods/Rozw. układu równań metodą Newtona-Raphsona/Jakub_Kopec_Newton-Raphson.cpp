#include<iostream>
#include<cmath>
using namespace std;

//KOPIA UKLADU ROWNAN Z PDFA
double F1(double x1,double x2)	//x1^3+2*x2^2
    {return x1*x1*x1+(2*x2*x2);}
double F2(double x1,double x2)	//4x1+sin(x2)
	{return 4*x1+sin(x2);}
double F1x1(double x1,double x2)
    {return 3*x1*x1;}
double F1x2(double x1,double x2)
    {return 4*x2;}
double F2x1(double x1,double x2)
    {return 4;}
double F2x2(double x1,double x2)
    {return cos(x2);}

double macierz[2][2]={0};
void Macierz_odwrotna(double x1,double x2)
    {
    double wyznacznik;
    macierz[0][0]=F2x2(x1,x2);
    macierz[0][1]=(-1)*F1x2(x1,x2);
    macierz[1][0]=(-1)*F2x1(x1,x2);
    macierz[1][1]=F1x1(x1,x2);
    wyznacznik=macierz[0][0]*macierz[1][1]-(macierz[1][0]*macierz[0][1]);
    macierz[0][0]=(1/wyznacznik)*macierz[0][0];
    macierz[0][1]=(1/wyznacznik)*macierz[0][1];
    macierz[1][0]=(1/wyznacznik)*macierz[1][0];
    macierz[1][1]=(1/wyznacznik)*macierz[1][1];
    }

void Metoda_newtona_raphsona()
    {
    cout<<"\tMETODA NEWTONA-RAPHSONA\n";
    double x1,x2,iteracje,dokladnosc;
    //cout<<"Podaj ilosc iteracji!\t";cin>>iteracje;
    cout<<"Podaj x1!\t";cin>>x1;
    cout<<"Podaj x2!\t";cin>>x2;
    cout<<"Podaj dokladnosc obliczen!\t";cin>>dokladnosc;cout<<endl;
    double kopia_x1=x1;
    double kopia_x2=x2;
    Macierz_odwrotna(x1,x2);
    double f1,f2,mnozenie1,mnozenie2;
    //(f1,f2) - (F1(x1,x2),F2(x1,x2))
    //mnozenie1 i 2 - wynik mnozenia macierzy J^-1 i macierzy   [F1(x1,x2)]
    //                                                          [F2(x1,x2)]
    //while(iteracje>0)
    while((F1(x1,x2)>dokladnosc) || (F2(x1,x2)>dokladnosc))
        {
        f1=F1(x1,x2);
        f2=F2(x1,x2);
        mnozenie1=macierz[0][0]*f1+macierz[0][1]*f2;
        mnozenie2=macierz[1][0]*f1+macierz[1][1]*f2;
        x1=x1-mnozenie1;
        x2=x2-mnozenie2;
        //iteracje--;
        iteracje++;
        }
    cout<<"Znaleziono rozwiazanie:\nx1= "<<x1<<"\t\tx2= "<<x2;
    cout<<"\n\nF1(x1,x2)= "<<F1(x1,x2);
    cout<<"\nF2(x1,x2)= "<<F2(x1,x2);

    cout<<"\n\nWartosci funkcji w punktach poczatkowych: \nF1: "<<F1(kopia_x1,kopia_x2)<<"\nF2: "<<F2(kopia_x1,kopia_x2);
    cout<<"\n\nIlosc iteracji: "<<iteracje<<endl;
    }

int main()
    {
    Metoda_newtona_raphsona();
    return 0;
  	}

