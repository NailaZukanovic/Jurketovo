#include <iostream>
#include <vector>

typedef std::vector<int> VektorInt;

bool daLiJeProst (int n)
{
    bool jelJes = true;

    for(int i = 2; i < n; i++)
        if ( n%i == 0)
            jelJes = false;

    return jelJes;
}

VektorInt prostiBrojeviUOpsegu (int a, int b)
{
    VektorInt v(b-a);
    int kolikoImaEl = 0;
    for( int i = a; i <= b; i++)
    {
        if(daLiJeProst(i))
        {
            kolikoImaEl++;
            std::cout<<i<<std::endl;
            v.push_back(i);
        }

    }
    v.resize(kolikoImaEl);
    return v;
}
int main ()
{
    VektorInt vektor;

    int a, b;
    std::cout<<"Unesite pocetnu i krajnju vrijednost"<<std::endl;
    std::cin>>a>>b;

    vektor = prostiBrojeviUOpsegu(a,b);
    if(vektor.size())
    {
        std::cout<<"Prosti brojevi u rasponu od 15 do 30 su:";
        for(int i : vektor)
            std::cout<<i<<", ";
    }
    else
        std::cout<<"Nema prostih vrojeva u rasponu od "<<a<<" do "<<b<<"!"<<std::endl;







    return 0;
}
