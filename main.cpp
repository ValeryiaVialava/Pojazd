#include "bibl.h"
int main()
{
    Parking p (5, 10);
    Pojazd* s1 = new Samochod;
    Pojazd* s2 = new Samochod;
    Pojazd* b1 = new Bus;
    Pojazd* m1 = new Motocykl;

    p.zaparkuj(0,0,s1);
    p.zaparkuj(4,2,s2);
    p.zaparkuj(1,1,b1);
    p.zaparkuj(3,4,new Bus);
    p.zaparkuj(2,2,m1);
    cout << "Przed operacja -=: " << endl;

    cout << p;

    p -= 'B';
    cout << endl << "Po operacji -= 'B'" << endl;
    cout << p;
    p -= 'M';
    cout << endl << "Po operacji -= 'M'" << endl;
    cout << p;

    int LiczbaSamochodow = p;
    cout << "Liczba Samochodów: " << LiczbaSamochodow << endl;

    delete s1;
    delete s2;
    delete b1;
    delete m1;

    MyTP<Pojazd> korek;
    korek.dodaj(new Samochod);
    korek.dodaj(new Samochod);
    korek.dodaj(new Bus);
    korek.drukuj();

    return 0;
}
