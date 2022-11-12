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


## [Zadatak 2](02.cpp)

Napisati program koji će omogućiti: Unos 2D niza od 5x5 elemanata vodeći računa da su svi elementi dvocifreni (ukoliko unos nekog elementa ne zadovoljava 
uslov, ponavljati unos tog elementa dok se ne zadovolji uslov). Koristiti funkciju unos. Izvršiti transpoziciju niza tako što će se zamjeniti redovi i kolone - 
Koristiti funkciju transpose, a zatim na osnovu izmijenjene matrice: Izračunati aritmetičku sredinu svih prostih brojeva ispod sporedne dijagonale - Koristiti
dvije funkcije: aritmeticka i prost_broj (pozivati će se iz funkcije aritmeticka).
Zatim napisati funkciju simpatican koja će provjeriti da li su brojevi iznad sporedne dijagonale simpatični*. Obavezno koristiti navedene funkcije, a parametre i eventualne povratne vrijednosti definisati prema potrebi. 
U main() funkciji napisati testni program koji će omogućiti izvršenje svih funkcija navedenim redoslijedom. 

```c++
[a][a][a][a][a]        [a][b][c][d][e]
[b][b][b][b][b]        [a][b][c][d][e]
[c][c][c][c][c]  --->  [a][b][c][d][e]
[d][d][d][d][d]        [a][b][c][d][e]
[e][e][e][e][e]        [a][b][c][d][e]
```

Broj je simpatičan ukoliko je zbir cifara njegovog kvadrata jednak kvadratu zbira njegovih cifara. Broj 21 je simpatičan jer je s(441) = s(21) * s(21) pri čemu je s(n) zbir cifara prirodnog broja n.

