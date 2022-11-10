## [Zadatak 1](01.cpp)

Kreirati matricu (2D niz) čiji su elementi objekti tipa Student (Student je struktura čija su obilježja data u nastavku). 
Omogućiti korisniku da unese dimenzije niza.

```c++
struct Student
{
    char* ID;
    char* ImePrezime;
    float* Prosjek;
};
```

Kompletna matrica predstavlja univerzitet. Redovi dvodimenzionalnog niza predstavljaju različite fakultete, a kolone studente. Omogućiti korisniku unos svih 
podataka za sve studente, te napraviti funkciju koja će pronaći fakultet sa najvećim prosjekom. Zatim je potrebno ispisati koji je to redni broj fakulteta 
(index reda sa najvećim prosjekom). Nakon toga pronaći i ispisati ID studenta koji ima najveći prosjek na cijelom univerzitetu.

