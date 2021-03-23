#include<iostream>
#include<cmath>
#include<random>
#include<windows.h>
using namespace std;
//ROWNANIE
double F(double x)
//{return x*x+2;}                                       //wariant1
//{return sin(x) + 14 * x;}                            //wariant2       
{return log(x)+9*x-11;}                               //wariant3
void Calkowanie_geometryczne(double a, double b, int liczba_podzialow)
{
	//cout<<"\t\tFunkcja ma postac: x^2+2\n\n";             //wariant1
	//cout << "\t\tFunkcja ma postac: sin(x)+14*x\n\n";         //wariant2
	cout<<"\t\tFunkcja ma postac: log(x)+9*x-11\n\n";     //wariant3
	cout << "Calkowanie na przedziale: <" << a << ":" << b << ">\t\tIlosc przedzialow:" << liczba_podzialow << "\n\n";
	double rozpietosc = abs(b - a) / (liczba_podzialow);
	double suma_pr = 0;
	double suma_tr = 0;
	double pole_pr, pole_tr;
	while (liczba_podzialow > 0)
	{
		//metoda prostokatow
		pole_pr = F(a)*rozpietosc;
		if (pole_pr < 0) { pole_pr = abs(pole_pr); }
		suma_pr += pole_pr;
		//metoda trapezow
		pole_tr = 0.5*rozpietosc*(F(a) + F(a + rozpietosc));
		if (pole_tr < 0) { pole_tr = abs(pole_tr); }
		suma_tr += pole_tr;
		a += rozpietosc;
		liczba_podzialow--;
	}
	cout << "Metoda prostokatow-pole pod wykresem jest rowne:\t\t" << suma_pr << endl;
	cout << "\nMetoda trapezow-pole pod wykresem jest rowne:\t\t\t" << suma_tr << endl<<endl;
}

void Metoda_Simpsona(double a, double b, int liczba_podzialow)
{
	//cout<<"\t\tFunkcja ma postac: x^2+2\n\n";             //wariant1
	//cout << "\t\tFunkcja ma postac: sin(x)+14*x\n\n";         //wariant2
	cout<<"\t\tFunkcja ma postac: log(x)+9*x-11\n\n";     //wariant3
	cout << "Calkowanie na przedziale: <" << a << ":" << b << ">\t\tIlosc przedzialow:" << liczba_podzialow << "\n\n";
	double rozpietosc = abs(b - a) / (liczba_podzialow);
	double suma = 0;
	double pole = 0;
	while (liczba_podzialow > 0)
	{
		if (pole < 0) { pole = abs(pole); }
		pole = (rozpietosc / 6)*(F(a) + 4 * F(0.5*(a + a+rozpietosc)) + F(a+rozpietosc));
		suma += pole;
		a += rozpietosc;
		liczba_podzialow--;
	}
	cout << "Metoda Simpsona-pole pod wykresem jest rowne:\t\t\t" << suma << endl<<endl;
}
void Metoda_Monte_Carlo(double a, double b, int liczba_podzialow)
{
	//cout<<"\t\tFunkcja ma postac: x^2+2\n\n";             //wariant1
	//cout << "\t\tFunkcja ma postac: sin(x)+14*x\n\n";         //wariant2
	cout<<"\t\tFunkcja ma postac: log(x)+9*x-11\n\n";     //wariant3
	cout << "Calkowanie na przedziale: <" << a << ":" << b << ">\t\tIlosc przedzialow:" << liczba_podzialow << "\n\n";
	double rozpietosc = abs(b - a) / (liczba_podzialow);
	double suma = 0;
	double pole = 0;
	double losowana_1,losowana_2,losowana_3,srednia = 0;

	while (liczba_podzialow > 0)
	{
		//generowanie 3 liczb losowych z przedzialu <a;a+rozpietosc>
		std::uniform_real_distribution<double> unif(a, a + rozpietosc);
		std::default_random_engine re;
		losowana_1 = unif(re);
		losowana_2 = unif(re);
		losowana_3 = unif(re);

		srednia = (F(losowana_1) + F(losowana_2) + F(losowana_3))/3;
		pole = rozpietosc * srednia;
		if (pole < 0) { pole = abs(pole); }
		
		suma += pole;
		a += rozpietosc;
		liczba_podzialow--;
	}
	cout << "Metoda Monte Carlo-pole pod wykresem jest rowne:\t\t" << suma << endl << endl;;
}
void Metoda_kwadratur_dwuwezlowych(double a, double b, int liczba_podzialow)
{
	//cout<<"\t\tFunkcja ma postac: x^2+2\n\n";             //wariant1
	//cout << "\t\tFunkcja ma postac: sin(x)+14*x\n\n";         //wariant2
	cout<<"\t\tFunkcja ma postac: log(x)+9*x-11\n\n";     //wariant3
	cout << "Calkowanie na przedziale: <" << a << ":" << b << ">\t\tIlosc przedzialow:" << liczba_podzialow << "\n\n";
	double suma = 0;
	double pole = 0;
	double wezel1 = -0.57735; double waga1 = 1;
	double wezel2 = 0.57735; double waga2 = 1;
	double t1, t2 = 0;
	double rozpietosc = abs(a - b) / (liczba_podzialow);

	while (liczba_podzialow > 0)
	{
		t1= 0.5*(a + a+ rozpietosc) + (0.5*rozpietosc*wezel1);
		t2= 0.5*(a + a+ rozpietosc) + (0.5*rozpietosc*wezel2);
		
		pole = 0.5*rozpietosc*(F(t1)*waga1+F(t2)*waga2);
		if (pole < 0) { pole = abs(pole); }

		suma += pole;
		a += rozpietosc;
		liczba_podzialow--;
	}
	cout << "Metoda kwadratury dwuwezlowej-pole pod wykresem jest rowne:\t" << suma << endl << endl;;
}
void Metoda_kwadratur_czterowezlowych(double a, double b, int liczba_podzialow)
{
	//cout<<"\t\tFunkcja ma postac: x^2+2\n\n";             //wariant1
	//cout << "\t\tFunkcja ma postac: sin(x)+14*x\n\n";         //wariant2
	cout<<"\t\tFunkcja ma postac: log(x)+9*x-11\n\n";     //wariant3
	cout << "Calkowanie na przedziale: <" << a << ":" << b << ">\t\tIlosc przedzialow:" << liczba_podzialow << "\n\n";
	double suma = 0;
	double pole = 0;
	double wezel1 = -0.86114; double waga1 = 0.34785;
	double wezel2 = -0.33998; double waga2 = 0.65214;
	double wezel3 = 0.33998; double waga3 = 0.65214;
	double wezel4 = 0.86114; double waga4 = 0.34785;
	double t1, t2, t3, t4 = 0;
	double rozpietosc = abs(a - b) / (liczba_podzialow);

	while (liczba_podzialow > 0)
	{
		t1 = 0.5*(a + a + rozpietosc) + (0.5*rozpietosc*wezel1);
		t2 = 0.5*(a + a + rozpietosc) + (0.5*rozpietosc*wezel2);
		t3 = 0.5*(a + a + rozpietosc) + (0.5*rozpietosc*wezel3);
		t4 = 0.5*(a + a + rozpietosc) + (0.5*rozpietosc*wezel4);

		pole = 0.5*rozpietosc*(F(t1)*waga1 + F(t2)*waga2+F(t3)*waga3+F(t4)*waga4);
		if (pole < 0) { pole = abs(pole); }

		suma += pole;
		a += rozpietosc;
		liczba_podzialow--;
	}
	cout << "Metoda kwadratury czterowezlowej-pole pod wykresem jest rowne:\t" << suma << endl << endl;;
}


int main()
{
	cout << "\tCalkowanie geometryczne\n";
	double a;
	cout << "\nPodaj poczatek przedzialu calkowania!\t"; cin >> a;
	double b;
	cout << "\nPodaj koniec przedzialu calkowania!\t"; cin >> b;
	int liczba_podzialow;
	cout << "\nPodaj liczbe podzialow przedzialu poczatkowego!\t"; cin >> liczba_podzialow; cout << endl;
	Calkowanie_geometryczne(a, b, liczba_podzialow);
	Metoda_Simpsona(a, b, liczba_podzialow);
	Metoda_Monte_Carlo(a, b, liczba_podzialow);
	Metoda_kwadratur_dwuwezlowych(a, b, liczba_podzialow);
	Metoda_kwadratur_czterowezlowych(a, b, liczba_podzialow);
	return 0;
}

