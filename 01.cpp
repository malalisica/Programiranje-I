#include<iostream>
#include<cmath>
using namespace std;

struct Student
{
    char* ID;
    char* ImePrezime;
    float* Prosjek;

    Student() {                                     // Konstruktor:inicijalizira pointere strukture kao dinamicke varijable/niz
        ID = new char[20];
        ImePrezime = new char[40];
        Prosjek = new float;
    }
    ~Student() {                                   // Destruktor:dealocira sve dinamicke varijable/niz i nullpointuje pointere
        delete[] ID;
        ID = nullptr;
        delete[] ImePrezime;
        ImePrezime = nullptr;
        delete Prosjek;
        Prosjek = nullptr;
    }
};


void unos(Student**, int, int);                        //Funkcija za unos elemenata
void ispis(Student**, int, int);                       //Funckija za ispis elemenata
void najboljiProsjek(Student**, int, int);             //Izracunava prosjek najboljeg fakulteta
void najboljiStudent(Student**, int, int);             //Ova funkcija sluzi za pronalazak najboljeg studenta
void dealokacija(Student** &, int);                    //Sluzi za dealociranje niza

int main() {
    int red, kolona;
    cout << "Unesite broj redova" << endl;
    cin >> red;
    cout << "Unesite broj kolona" << endl;
    cin >> kolona;
    
    //Kreiranje matrice
    Student** niz = new Student * [red];
    for (int i = 0; i < red; i++) {
        *(niz + i) = new Student[kolona];
    }

    unos(niz, red, kolona);
    ispis(niz, red, kolona);
    cout << endl;
    najboljiProsjek(niz, red, kolona);
    najboljiStudent(niz, red, kolona);
    dealokacija(niz, red);

    cin.get();
    return 0;
}


void unos(Student** niz, int red, int kolona) {

    for (int i = 0; i < red; i++) {
        for (int j = 0; j < kolona; j++) {

            cin.ignore();
            cout << "Unesite ID studenta" << endl;
            cin.getline((*(niz + i) + j)->ID, 20);
            cout << "Unesite ime i prezime studenta" << endl;
            cin.getline((*(niz + i) + j)->ImePrezime, 40);
            cout << "Unesite prosjek studenta" << endl;
            cin >> *(*(niz + i) + j)->Prosjek;
        }
    }
}


void ispis(Student** niz, int red, int kolona) {
    cout << endl;
    for (int i = 0; i < red; i++) {
        for (int j = 0; j < kolona; j++) {

            cout << "ID studenta: " << ((*(niz + i) + j)->ID) << endl;     //Pointer na char niz se ne dereferencira prilikom ispisa
            cout << "Ime i prezime: " << ((*(niz + i) + j)->ImePrezime) << endl;
            cout << "Prosjek studenta: " << *((*(niz + i) + j)->Prosjek) << endl;
        }
     
           cout << endl;  
    }

}


void najboljiProsjek(Student** niz, int red, int kolona) {

    float* pomocni = new float [red] {};  //Trazi se najbolji fakultet tj. najbolji red
    for (int i = 0; i < red; i++) {
        for (int j = 0; j < kolona; j++) {
            *(pomocni + i) += *(*(niz + i) + j)->Prosjek;
        }
        *(pomocni + i) /= red * kolona;
    }


    int najveci = 0;

    for (int i = 0; i < red; i++) {
        if (*(pomocni + najveci) < *(pomocni + i)) {
            najveci = i;
        }

    }

    cout << "Fakultet(red) sa najvecim prosjekom je fakultet sa indeksom   " << najveci << endl;

    cout << endl;
    delete[] pomocni;                                           //Pomocni niz je dinamicki, pa se mora dealocirati
    pomocni = nullptr;

}

void najboljiStudent(Student** niz, int red, int kolona) {

    {
        int najboljiRed = 0, najboljaKolona = 0;
        for (int i = 0; i < red; i++)
        {
            for (int j = 0; j < kolona; j++)
            {
                if ((*(*(niz + najboljiRed) + najboljaKolona)->Prosjek) < (*(*(niz + i) + j)->Prosjek)) //Uporedjuju se elementi dinamickog niza
                {
                    najboljiRed = i;
                    najboljaKolona = j;
                }
            }
        }
        cout << "Najbolji student je : " <<*(*(*(niz + najboljiRed) + najboljaKolona)).ID << endl;
    }
}


void dealokacija(Student**& niz, int red) {
    for (int i = 0; i < red; i++)
    {
        delete[] * (niz + i); 
        *(niz + i) = nullptr;
    }
    delete[]niz;         
    niz = nullptr;      
}
