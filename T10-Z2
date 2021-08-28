#include<iostream>

#include <cmath>

class Krug
{
private:

    double poluprecnik;

public:

    explicit Krug(double r)
    {
        if(r > 0) Krug::poluprecnik = r;
    }

    void Postavi(double r) { if(r > 0) Krug::poluprecnik = r;}

    double DajPoluprecnik() const { return poluprecnik;}

    double DajPovrsinu() const { return poluprecnik * poluprecnik * 4 * std::atan(1); }

    double DajObim() const { return 2 *  poluprecnik * 4 * std::atan(1); }

    void Skaliraj( double s ) { Krug::poluprecnik *= s; }

    void Ispisi()
    {
        std::cout<<"R="<<DajPoluprecnik()<<"P="<<DajPovrsinu()<<"O="<<DajObim()<<std::endl;
    }


};


class Valjak
{
private:
    double visina;
    Krug osnova;

public:


    Valjak (double visina, Krug osnova) : osnova(osnova)
    {
        if(visina > 0)
        {
            Valjak::visina = visina;
        }
    }

    void Postavi (double visina, Krug osnova)
    {
        if(visina > 0)
        {
            Valjak::visina = visina;
            Valjak::osnova = osnova;
        }
    }

    double DajBazu() const { return Valjak::osnova.DajPovrsinu(); }

    double DajVisinu() const { return Valjak::visina;}

    double DajPovrsinu() const { return osnova.DajPovrsinu() * 2 + osnova.DajObim() * visina; }

    double DajZapreminu() const { return osnova.DajPovrsinu() * visina; }

    void Skaliraj(double s)
    {
        if(s > 0)
        {
            Valjak::osnova.Skaliraj(s);
            visina *= s;
        }
    }

    void Ispisi() const { std::cout<<"R="<<osnova.DajPoluprecnik()<<"H="<<DajVisinu()<<"P="<<DajPovrsinu()<<"V="<<DajZapreminu()<<std::endl;}
};


int main()
{
    Krug k = Krug(3);

    Valjak v = Valjak(6,k);

    k.Ispisi();

    v.Ispisi();

    k.Skaliraj(2);

    v.Skaliraj(2);

    k.Ispisi();

    v.Ispisi();

    k.Postavi(2);

    v.Postavi(7,k);

    k.Ispisi();

    v.Ispisi();
}
