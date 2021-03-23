#include<iostream>
#include<cmath>
#include<random>
#include<windows.h>
using namespace std;
//ROWNANIE
double F(double x,double y) 
{
	return x * x + y;
}


void Metoda_Eulera(double x,size_t n, double x0, double y0)
{
	cout << "\tMedoda Eulera\n";
	double h = x / n;
	cout << "\nPunkt dla ktorego nalezy obliczyc wartosc rozwiazania: " << x;
	cout << "\nIlosc krokow: " << n;
	cout << "\nh=" << h;
	cout << "\nWarunek poczatkowy: f(" << x0 << ")=" << y0 << endl;
	double* tabx = new double[2] { 0 };
	double* taby = new double[2] { 0 };
	tabx[0] = x0; taby[0] = y0;
	
	for (int kroki = 0; kroki < n;kroki++)
	{
		tabx[1] = tabx[0]+h;
		taby[1] = taby[0] + (h*F(tabx[0],taby[0]));
		tabx[0] = tabx[1]; taby[0] = taby[1];
		//wynik kolejnej iteracji
		cout << "Krok "<<kroki+1 << ":\t" << "x="<<tabx[1] << ",\ty=" << taby[1]<<endl;
	}
}
void Metoda_RK2(double x, size_t n, double x0, double y0)
{
	cout << "\n\tMetoda RK2\n";
	double h = x / n;
	cout << "\nPunkt dla ktorego nalezy obliczyc wartosc rozwiazania: " << x;
	cout << "\nIlosc krokow: " << n;
	cout << "\nh=" << h;
	cout << "\nWarunek poczatkowy: f(" << x0 << ")=" << y0 << endl;
	double* tabx = new double[2]{ 0 };
	double* taby = new double[2]{ 0 };
	double k1, k2 = 0;
	tabx[0] = x0; taby[0] = y0;
	double o=0;
	for (int kroki = 0; kroki < n; kroki++)
	{
		k1 = F(tabx[0], taby[0]);
		k2 = F(tabx[0] + h, taby[0] + h * k1);
		o = 0.5*(k1 + k2);
		tabx[1] = tabx[0] + h;
		taby[1] = taby[0] + (h*o);
		
		tabx[0] = tabx[1]; taby[0] = taby[1];
		//wynik kolejnej iteracji
		cout << "Krok " << kroki+1 << ":\t" << "x=" << tabx[1] << ",\ty=" << taby[1] << endl;
	}
}

void Metoda_RK4(double x, size_t n, double x0, double y0)
{
	cout << "\n\tMetoda RK4\n";
	double h = x / n;
	cout << "\nPunkt dla ktorego nalezy obliczyc wartosc rozwiazania: " << x;
	cout << "\nIlosc krokow: " << n;
	cout << "\nh=" << h;
	cout << "\nWarunek poczatkowy: f(" << x0 << ")=" << y0 << endl;
	double* tabx = new double[2]{ 0 };
	double* taby = new double[2]{ 0 };
	double k1, k2, k3, k4 = 0;
	tabx[0] = x0; taby[0] = y0;
	double o = 0;
	for (int kroki = 0; kroki < n; kroki++)
	{
		k1 = F(tabx[0], taby[0]);
		k2 = F(tabx[0] + 0.5 * h, taby[0] + 0.5 * h * k1);
		k3 = F(tabx[0] + 0.5 * h, taby[0] + 0.5 * h * k2);
		k4 = F(tabx[0] + h, taby[0] + h * k3);
		o = (k1 + 2*k2 + 2*k3 + k4)/6;
		tabx[1] = tabx[0] + h;
		taby[1] = taby[0] + (h*o);

		tabx[0] = tabx[1]; taby[0] = taby[1];
		//wynik kolejnej iteracji
		cout << "Krok " << kroki+1 << ":\t" << "x=" << tabx[1] << ",\ty=" << taby[1] << endl;
	}
}

int main()
{
	cout << "Rownanie ma postac: f(x,y)=x * x + y";
	double punkt;
	cout << "\nPodaj punkt dla ktorego nalezy obliczyc wartosc rozwiazania!\t"; cin >> punkt;
	size_t kroki;
	cout << "Podaj ilosc krokow!\t"; cin >> kroki;
	double x0, y0;
	cout << "Podaj x warunku poczatkowego!\t"; cin >> x0;
	cout << "Podaj y warunku poczatkowego!\t"; cin >> y0;
	cout << endl;
	Metoda_Eulera(punkt, kroki, x0, y0);
	Metoda_RK2(punkt, kroki, x0, y0);
	Metoda_RK4(punkt, kroki, x0, y0);
	return 0;
}

