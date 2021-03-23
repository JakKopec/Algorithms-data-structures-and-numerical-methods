#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include <iomanip>
using namespace std;

int metoda_jacobiego (void)
	{
	fstream file;
    file.open("MetodaJacobiego.txt",ios::in);
    if(file.good()==false)
        {cout<<"Blad pliku tekstowego!\n";return -1;}
    string temp;
    int ilosc_rownan;
    file>>ilosc_rownan;
    getline(file,temp);
    double macierz[ilosc_rownan][ilosc_rownan]={0};
    double macierz_B[ilosc_rownan];
    int w=0;int k=0;int r=0;
    double doubletemp;
//wczytanie macierzy wejsciowej i rozwiazan
    cout<<"\n____________________________________________________________________________________________________\n";
    cout<<"\t\tMACIERZ WEJSCIOWA\n\n";
    while(w!=ilosc_rownan)
        {
        for(int a=ilosc_rownan;a>0;a--,k++)
            {
            file>>doubletemp;
            macierz[w][k]=doubletemp;
            if(k==ilosc_rownan)   {cout<<" |\t";}
            cout<<macierz[w][k]<<"\t";
            }
        file>>doubletemp;
        macierz_B[r]=doubletemp;
        cout<<"|\t"<<macierz_B[r]<<endl;
        w++;k=0;r++;
        getline(file,temp);
        }
    w--;k=0;
    int liczba_iteracji;
    file>>liczba_iteracji;
    cout<<"\nLiczba iteracji:"<<liczba_iteracji;
    file.close();
    cout<<"\n____________________________________________________________________________________________________\n\n";
    double macierz_L[ilosc_rownan][ilosc_rownan]={0};
    double macierz_D[ilosc_rownan][ilosc_rownan]={0};
    double macierz_U[ilosc_rownan][ilosc_rownan]={0};
//uzupelnienie macierz_U
    int licznik=1;
    //cout<<"\n\tMACIERZ U\n";
    for(w=0;w<ilosc_rownan-1;w++)
        {
        for(int a=0;a<licznik;a++)
            {
            cout<<"\t";
            }
        for(k=licznik;k<ilosc_rownan;k++)
            {
            macierz_L[w][k]=macierz[w][k];
            //cout<<macierz_L[w][k]<<"\t";
            }
        licznik++;
        //cout<<endl;
        }
//uzupelnienie macierz_D
    //cout<<"\n\tPRZEKATNA MACIERZY D\n";
    for(w=0,k=0;w<ilosc_rownan;w++,k++)
        {
        macierz_D[w][k]=macierz[w][k];
        if(macierz_D[w][k]==0)
            {cout<<"Wartosci na przekatnej musza byc rozne od 0!\n";return -1;}
        //cout<<macierz_D[w][k]<<"\t";
        }
//uzupelnienie macierz_L
    licznik=1;
    //cout<<"\n\n\tMACIERZ L\n";
    for(w=1;w<ilosc_rownan;w++)
        {
        for(k=0;k<licznik;k++)
            {
            macierz_L[w][k]=macierz[w][k];
            //cout<<macierz_L[w][k]<<"\t";
            }
            licznik++;
            //cout<<endl;
        }
//sprawdzenie macierzy
    string warunek="\nMacierz wejsciowa nie jest diagonalnie slabo dominujaca!";
    for(w=0,k=0;w<ilosc_rownan;w++)
        {
        for(k;k<ilosc_rownan;k++)
            {
            if(macierz[w][w]>macierz[w][k]){warunek="\n\tMacierz wejsciowa jest diagonalnie slabo dominujaca!";}
            }
        }
    cout<<"\n____________________________________________________________________________________________________\n"<<warunek<<"\n____________________________________________________________________________________________________\n";

//D^-1
    cout<<"\n\tMACIERZ D^-1\n";
    for(w=0;w<ilosc_rownan;w++)
        {

        for(k=0;k<ilosc_rownan;k++)
            {
                if(w==k){macierz_D[w][k]=1/macierz[w][w];}
                else{macierz_D[w][k]=0;}
                cout<<setprecision(2)<<macierz_D[w][k]<<"\t";}
        cout<<endl;
        }
//tworzenie L+U
    cout<<"\n\tMACIERZ L+U\n";
    double macierz_LplusU[ilosc_rownan][ilosc_rownan]={0};
    for(w=0;w<ilosc_rownan;w++)
        {
        for(k=0;k<ilosc_rownan;k++)
            {
            macierz_LplusU[w][k]=macierz[w][k];
            if(w==k){macierz_LplusU[w][k]=0;}
            cout<<macierz_LplusU[w][k]<<"\t";
            }
        cout<<endl;
        }
//-D^-1*(L+U)
    cout<<"\n\tMacierz -D^-1*(L+U)\n";
    double wyrazenie[ilosc_rownan][ilosc_rownan]={0};
    for(w=0;w<ilosc_rownan;++w)
        {
        for(int k=0;k<ilosc_rownan;++k)
            {
            for(int s=0;s<ilosc_rownan;++s)
                {wyrazenie[w][k] += macierz_D[w][s] * macierz_LplusU[s][k];}
            wyrazenie[w][k]=(-1)*wyrazenie[w][k];
            if(w==k){wyrazenie[w][k]=0;}
            cout<<setprecision(2)<<wyrazenie[w][k]<<" \t\t";
            }
            cout<<endl;
        }
    cout<<endl;
//liczenie przyblizen
    double wektor[ilosc_rownan]={0};
    double pr[ilosc_rownan]={0};
    double le[ilosc_rownan]={0};
    int iter=0;
    //R     d^-1*b
    for(w=0;w<ilosc_rownan;w++)
        {
        pr[w]=(macierz_D[w][w]*macierz_B[w]);
        //cout<<pr[w]<<"\t";
        }
    cout<<"\tITERACJE:\n";
    while(iter<liczba_iteracji)
        {
        //L     -D^-1*(L+U)*wektor
        for(w=0;w<ilosc_rownan;w++)
            {
            for(k=0;k<ilosc_rownan;k++)
                {
                le[w]+=(wyrazenie[w][k]*wektor[k]);
                }
            //cout<<le[w]<<"\t\t";
            }

        //suma l i r
        for(r=0;r<ilosc_rownan;r++)
            {
            wektor[r]=pr[r]+le[r];
            cout<<wektor[r]<<"\t";
            }
        for(int i=0;i<ilosc_rownan;i++)
            {le[i]=0;}
        cout<<endl;
        iter++;
        }
    cout<<"\n\tWYNIKI:\n";
    for(r=0;r<ilosc_rownan;r++)
        {
        cout<<wektor[r]<<"\t";
        }
    return 0;
	}

int main()
    {
  	return metoda_jacobiego();;
    }

