#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include <iomanip>
using namespace std;



int eliminacja_gaussa(void)
	{
	fstream file;
    file.open("EliminacjaGaussa.txt",ios::in);
    if(file.good()==false)
        {cout<<"Blad pliku tekstowego!\n";return -1;}
    string temp;
    int ilosc_niewiadomych;
    file>>ilosc_niewiadomych;
    //ilosc_wezlow=atoi(temp.c_str());
    //pierwsza linia z pliku - ilosc niewiadomych i jedna linia odstepu
    getline(file,temp);
    getline(file,temp);
    //kolejne linie - wspoczynnik x,y,z... rownania , przerwa x,y,z... , przerwa
    double macierz[ilosc_niewiadomych][ilosc_niewiadomych+1]={0};
    double macierz_rozwiazan[ilosc_niewiadomych];
    int w=0;int k=0;
    double doubletemp;
    cout<<"\t\tMACIERZ WEJSCIOWA\n\n";
    while(w!=ilosc_niewiadomych)
        {
        for(int a=ilosc_niewiadomych;a>=0;a--,k++)
            {
            file>>doubletemp;
            macierz[w][k]=doubletemp;
            getline(file,temp);
            //macierz[w][k]=atoi(temp.c_str());
            if(k==ilosc_niewiadomych)   {cout<<" |\t";}
            cout<<macierz[w][k]<<"\t";
            }
        w++;k=0;
        getline(file,temp);
        cout<<endl;
        if(temp!="_")   {cout<<"Blad danych w pliku tekstowym!\n";return -1;}
        }
    w=0;k=0;
    file.close();
    //pivoting
    //zlozonosc obliczeniowa lezy i kwiczy ale przynajmniej dziala
    cout<<"\n\t\tZAMIANA WIERSZY:\n\n";
    for(int a=0;a<ilosc_niewiadomych;a++)
        {
        for(int b=a+1;b<ilosc_niewiadomych;b++)
            {
            if(macierz[a][a]<macierz[b][a])
                {

                for(int c=0;c<=ilosc_niewiadomych;c++)//przestawienie macierzy
                    {swap(macierz[a][c],macierz[b][c]);}

                for(int a=0;a<ilosc_niewiadomych;a++)//wyswietlenie macierzy
                    {
                    for(int b=0;b<ilosc_niewiadomych+1;b++)
                        {
                        cout<<setprecision(3)<<macierz[a][b]<<"\t";
                        if(b==ilosc_niewiadomych-1){cout<<" |\t";}
                        }
                    cout<<endl;
                    }
                    cout<<endl;
                }
            }
        }
    //eliminacja
    cout<<"\n\t\tELIMINACJA:\n\n";
    double iloraz;
    for(int a=0;a<=ilosc_niewiadomych;a++)
        {
        for(int b=a+1;b<ilosc_niewiadomych;b++)
            {
            iloraz=macierz[b][a]/macierz[a][a];
            for(int c=0;c<=ilosc_niewiadomych;c++)//likwidowanie elementow ponizej glownej przekatnej
                {macierz[b][c]=macierz[b][c]-(iloraz*macierz[a][c]);}
            for(int y=0;y<ilosc_niewiadomych;y++)//wyswietlenie macierzy
                {
                for(int z=0;z<ilosc_niewiadomych+1;z++)
                    {
                    cout<<setprecision(3)<<macierz[y][z]<<"\t";
                    if(z==ilosc_niewiadomych-1){cout<<" |\t";}
                    }
                cout<<endl;
                }
            cout<<endl;
            }
        }

    for(int a=0;a<ilosc_niewiadomych;a++)//wyswietlenie macierzy
        {
        for(int b=0;b<ilosc_niewiadomych+1;b++)
            {
            cout<<setprecision(3)<<macierz[a][b]<<"\t";
            if(b==ilosc_niewiadomych-1){cout<<" |\t";}
            }
        cout<<endl;
        }

    for(int a=ilosc_niewiadomych-1;a>=0;a--)
        {
        macierz_rozwiazan[a]=macierz[a][ilosc_niewiadomych];
        for(int b=a+1;b<ilosc_niewiadomych;b++)
            {
            if(a!=b)//natrafienie na wiersz z jedna niewiadoma-wykona sie najpierw w ostatnim wierszu potem ostatnim-1....
                {macierz_rozwiazan[a]=macierz_rozwiazan[a]-(macierz_rozwiazan[b]*macierz[a][b]);}
            }
            macierz_rozwiazan[a]=macierz_rozwiazan[a]/macierz[a][a];
        }

    for(int a=0;a<ilosc_niewiadomych;a++)//wyswietlenie rozwiazan
        {
cout<<"Niewiadoma nr "<<a<<" :"<<setprecision(3)<<macierz_rozwiazan[a]<<endl;}

    return 0;
	}




int main()
    {
    int ret=eliminacja_gaussa();
  	return ret;
    }

