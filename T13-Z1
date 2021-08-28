#include <iostream>
#include <cmath>
#include <vector>

class Lik
{
public:

    virtual void IspisiSpecificnosti() = 0;

    virtual double DajObim() = 0;

    virtual double DajPovrsinu() = 0;

    void Ispisi()
    {

        IspisiSpecificnosti();
        std::cout<<"Obim: "<<DajObim()<<" Povrsina: "<<DajPovrsinu()<<std::endl;


    }





};

class Trougao : public Lik
{
private:

    double a,b,c;
public:

    Trougao(double a = 0, double b = 0, double c = 0)
    {
        if(a + b > c && b + c > a && a + c > b )
        {
            Trougao::a = a; Trougao::b = b; Trougao::c = c;
        }
    }

    double DajObim() override { return a + b + c;}

    double DajPovrsinu() override
    {
        double s = (a + b + c) / 2;
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }

    void IspisiSpecificnosti() override
    {
        std::cout<<"Trougao sa stranicama duzine "<<a<<", "<<b<<" i "<<c<<std::endl;
    }
};

class Pravougaonik : public Lik
{
private:

    double a,b;

public:

    Pravougaonik(double a, double b)
    {
        if(a > 0 && b > 0)
            Pravougaonik::a = a; Pravougaonik::b = b;
    }

    double DajObim() override { return 2 * (a  + b);}

    double DajPovrsinu() override { return a * b; }

    void IspisiSpecificnosti() override
    {
        std::cout << "Pravougaonik sa stranicama duzine "<<a<<" i "<<b<<std::endl;
    }
};

class Krug : public Lik
{
private:
    double poluprecnik;

public:


    Krug(double poluprecnik)
    {
        if( poluprecnik > 0) Krug::poluprecnik = poluprecnik;
    }

    double DajObim() override { return poluprecnik * 2 * 3.14;}

    double DajPovrsinu() override { return poluprecnik * poluprecnik * 3.14; }

    void IspisiSpecificnosti() override
    {
        std::cout << "Krug poluprecnika "<<poluprecnik<<std::endl;
    }

};

int main()
{

    std::cout<<"Kr \t − Krug radijusa r (npr. K5) \nPa,b \t − Pravougaonik sa stranicama a i b (npr. P3,2) \nTa,b,c \t − Trougao sa stranicama a, b i c (npr. T3,4,5)";

    int brojLikova;
    std::cout<<std::endl;
    std::cout<<"Koliko zelite likova: ";
    std::cin>>brojLikova;

    std::cout<<std::endl;

    int brPonavljanja = 0;
    char slovoLika;
    double par1,par2,par3;
    std::vector<Lik*> likovi;

    char zarezCin;

    while(brPonavljanja < brojLikova)
    {
        std::cout<<"Lik "<<brPonavljanja + 1<<": ";
        std::cin>>slovoLika;

        if(slovoLika == 'K')
        {
            std::cin>>par1;
            likovi.push_back(new Krug(par1));
        }

        else if(slovoLika == 'P')
        {
            std::cin>>par1>>zarezCin>>par2;
            likovi.push_back(new Pravougaonik(par1,par2));
        }

        else if(slovoLika == 'T')
        {
            std::cin>>par1>>zarezCin>>par2>>zarezCin>>par3;
            likovi.push_back(new Trougao(par1,par2,par3));
        }

        else
        {
            std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl;
            brPonavljanja--;
        }

        brPonavljanja++;
    }

    for(Lik* p : likovi)    (*p).Ispisi();






    return 0;
}
