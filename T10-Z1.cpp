class StedniRacun
{
private:

    double racun;


public:

    StedniRacun() { StedniRacun:: racun = 0; }

    StedniRacun(double racun)
    {
        if ( racun > 0) StedniRacun:: racun = racun;
    }

    void Ulozi(double iznos)
    {
            StedniRacun::racun += iznos;
    }

    void Podigni ( double iznos)
    {
        if( iznos <= racun ) StedniRacun::racun -= iznos;
    }

    double DajStanje() const { return racun;}

    double ObracunajKamatu(double kamatnaStopa) const
    {
        if( kamatnaStopa > 0) return racun * (1. + kamatnaStopa);
    }
};


int main()
{

    StedniRacun r1 = StedniRacun();

    StedniRacun r2(250);


    r1.Ulozi(150);

    r2.Podigni(50);



    std::cout<<r1.ObracunajKamatu(1.)<<" "<<r2.ObracunajKamatu(0.5)<<std::endl;






    return 0;
}
