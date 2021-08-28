#include <iostream>
#include <vector>

typedef std::vector<double> VektorRealnih;

bool testPerioda(VektorRealnih v, int p)
{
    bool jelJes = true;

    for(int i = 0; i + p < signed(v.size()); i++)
    {
        if(v[i] != v[i+p])
            jelJes = false;
    }




    return jelJes;
}

int odrediOsnoviPeriod(VektorRealnih v)
{
    int p = 0;
    for(int i = 1; i < signed(v.size()); i++)
    {
        if(testPerioda(v,i))
        {
            p = i;
            break;
        }
    }

    return p;

}

int main ()
{
    VektorRealnih vektor;
    std::cout<<"Unesite slijed brojeva (0 za kraj)";
    double broj;
    do
    {
        std::cin>>broj;
        vektor.push_back(broj);
    }while(broj != 0);

    vektor.pop_back();

    if(odrediOsnoviPeriod(vektor))
        std::cout<<"Slijed je periodican sa osnovnim periodom "<<odrediOsnoviPeriod(vektor);
    else
        std::cout<<"SLijed nije periodican";

    return 0;
}
