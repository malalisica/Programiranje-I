#include <iostream>
using  namespace std;
const int x = 5, y = 5; //deklaracija konstante za dimenzije matrice u kojoj je x red a y kolona

int main() {
  
	int niz[x][y];
  
	unos(niz);
	ispis(niz);
	transpose(niz);  
	cout << endl;
	cout << "Aritmeticka sredina svih prostih brojeva ispod sporedne dijagonale je: " << aritmeticka(niz) << endl;
	cout << endl;
	simpatican(niz);


	cin.get();
	return 0;
}


int brojCifri(int broj) {
	int br = 0;
	while (broj > 0) {
		broj /= 10;
		br++;
	}
	return br;
}


void unos(int niz[][y]) {
	int temp;
	cout << "Unesite 25 elemenata niza : " << endl;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			do {
				cin >> temp;
				niz[i][j] = temp;
				if (brojCifri(temp) < 2 || brojCifri(temp) > 2)
					cout << "Niste unijeli dvocifren broj!" << endl;
				break;
			} while (brojCifri(temp) < 2 || brojCifri(temp) > 2);               //Provjera da li je uneseni broj dvocifren ili ne
		}
	}
}


void ispis(int niz[][y]) {
	cout << endl;
	cout << "Elementi niza su: " << endl;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << " [ " << niz[i][j] << " ] ";
		}
		cout << endl;
	}
}


void transpose(int niz[][y]) {
	int niz2[x][y] = { 0 };
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			niz2[i][j] = niz[j][i];   //stavljamo elemente niza u pomocni niz tako da u njemu su obrnute kolone i redovi u odnosu na prvobitni niz
		}
	}

	cout << endl;

	cout << "Niz nakon zamjenjenih redova i kolona : " << endl;

	cout << endl; 

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << " [ " << niz2 [i][j] << " ] ";
		}
		cout << endl;
	}
}


bool prost_broj(int broj) {
	if (broj == 1)       //1 nije prost broj
		return false;
	for (int i = 2; i <= broj / 2; i++)
	{
		if (broj % i == 0)
			return false;
	}
	return true;
}


float aritmeticka(int niz[][y]) {
	float aritmeticka = 0.0;
	int brojac = 0;
  
  /*
	sporedna dijagonala:
	*	*	*	*	/
	*	*	*	/	*
	*	*	/	*	*
	*	/	*	*	*
	/	*	*	*	*
	*/
  
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if ((i + j) > x - 1) {
				if (prost_broj(niz[i][j])) {
					aritmeticka += niz[i][j];
					brojac++;
				}
			}
		}
	}
	if (brojac != 0)
		aritmeticka /= float(brojac);
	return aritmeticka;
}


int zbirCifri(int broj) {
	int zbir = 0;
	while (broj > 0) {
		zbir += broj % 10;
		broj /= 10;
	}
	return zbir;
}


void simpatican(int niz[][y]) {
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if ((i + j) < x - 1) {
				if (zbirCifri(niz[i][j] * niz[i][j]) == zbirCifri(niz[i][j]) * zbirCifri(niz[i][j])) {
					cout << "Broj " << niz[i][j] << " je simpatican!" << endl;
				}
				else {
					cout << "Broj " << niz[i][j] << " nije simpatican!" << endl;
				}
			}
		}
	}
}
