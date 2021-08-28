#include<iostream>

class Sat
{

    int sekunde;

public:

    static int Razmak(Sat s1,Sat s2) { return s1.DajSekunde() - s2.DajSekunde(); }

    static bool DaLiJeIspravno (int sekunde)
    {

        if( sekunde < 0) return false;
        return true;


    }

    int DajSekunde() const {return sekunde % 60;}

    int DajMinute() const {

        return ((sekunde - DajSekunde()) / 60) % 60;
    }

    int DajSate() const { return ((sekunde - DajSekunde() - DajMinute() * 60) / 60) % 24;}

    void Postavi( int sekunde)
    {

        if(DaLiJeIspravno(sekunde))
        {
            Sat::sekunde = sekunde;
        }
        else
            std::cout<<"Neispravno vrijeme"<<std::endl;

    }

    void PostaviNormalizirano (int sekunde)
    {

        if(DaLiJeIspravno(sekunde))
            Sat::sekunde = sekunde;

    }


    Sat& Sljedeci()
    {
        sekunde++;
        return *this;
    }

    Sat& Prethodni()
    {
        if(sekunde > 0) sekunde--;
        return *this;
    }

    void Ispisi() const { std::cout<<"\t"<<DajSate()<<":"<<DajMinute()<<":"<<DajSekunde()<<std::endl; }

    Sat& PomjeriZa(int pomeriZaSec)
    {
        if(pomeriZaSec)
        {

            for( int i = 0; i < pomeriZaSec; i++)
            {
                Sat::Sljedeci();
            }
        }
        else
        {

            for( int i = 0; i > pomeriZaSec; i--)
            {
                Sat::Prethodni();
            }
        }

        return *this;
    }

    friend int BrojSekundiIzmedju(Sat s1, Sat s2);

};


int BrojSekundiIzmedju(Sat s1, Sat s2)
{
    return s1.DajSekunde() - s2.DajSekunde();

}


int main()
{


    Sat s;
    s.Postavi(12015);

    Sat s2;
    s2.PostaviNormalizirano(3450);

    s.Sljedeci().Sljedeci();

    s2.Prethodni();

    s.Ispisi();

    s2.Ispisi();

    s.PomjeriZa(5);

    s.Ispisi();

    std::cout<<"Broj sekundi izmedju je " << BrojSekundiIzmedju(s,s2)<<std::endl;


    std::cout<<"Broj sekundi ali staticno je "<<Sat::Razmak(s,s2)<<std::endl;



    return 0;
}
