#include <iostream>
#include <complex>
#include <cmath>

int main ()
{
    int brEl = 0;
    std::cout<<"Unesite broj elemenata";
    std::cin>>brEl;
    std::cout<<std::endl;

    std::complex<double> z (0,0);
    for(int i = 0; i < brEl; i++)
    {
        double re,im;
        char karakter;
        std::cout<<"R"<<i+1;
        std::cin>>re;
        std::cout<<"X"<<i+1;
        std::cin>>im;

        std::complex<double> kompl(re,im);
        z += pow(kompl,-1);
    }



    z = pow(z,-1);

    std::cout<<std::endl;

    std::cout<<"Paralelna veza ovih elemenata ima r = "<<z.real()<<" i X = "<<z.imag()<<".";










    return 0;
}
