#include <iostream>
#include <cmath>


class Vector3d
{
private:
    double koordinate[3]; //bolje koristiti vektor jer je niz u biti samo pokazivac u klasi
    mutable int brojIspisa;
public:

    Vector3d() : niz{0,0,0}, brojIspisa(0) {}

    Vector3d(double x, double y, double z) : koordinate{x,y,z}, brojIspisa(0) {}

    Vector3d(const Vector3d &v) : Vector3d(v.DajX(), v.DajY(), v.DajZ()) {}

    void Postavi(double x, double y, double z){
        PostaviX(x); PostaviY(y); PostaviZ(z);
    }

    void Ocitaj(double &x, double &y, double &z) const {
        x = DajX(); y = DajY(); z = DajZ();
    }

    void Ispisi() {
        std::cout<< "{" << DajX() << "," << DajY() << "," << DajZ() << "}"<<std::endl;
        brojIspisa++;
    }

    void PostaviX(double x) { Vector3d::koordinate[0] = x; }

    void PostaviY(double y) { Vector3d::koordinate[1] = y; }

    void PostaviZ(double z) { Vector3d::koordinate[2] = z; }

    double DajX() const { return koordinate[0]; }

    double DajY() const { return koordinate[1]; }

    double DajZ() const { return koordinate[2]; }

    double DajDuzinu() const { return sqrt( DajX() * DajX() + DajY() * DajY() + DajZ() * DajZ()); }

    int DajBrojIspisa() const {return brojIspisa;}

    Vector3d &PomnoziSaSkalarom (double s) {
        niz[0] *= s; niz[1] *= s; niz[2] *= s;
        return *this;
     }

    Vector3d &SaberiSa(const Vector3d &v) {
        niz[0] += v.niz[0]; niz[1] += v.niz[1]; niz[2] += v.niz[2];
        return *this;
     }

     friend Vector3d ZbirVektora (const Vector3d &v1, const Vector3d &v2);
};

Vector3d ZbirVektora(const Vector3d &v1, const Vector3d &v2) {

    Vector3d v3;

    v3.Postavi(v1.DajX() + v2.DajX(), v1.DajY() + v2.DajY(), v1.DajZ() + v2.DajZ());

    return v3;
}

int main ()
{

    Vector3d v;
    v.Postavi(3,4,5);
    v.PostaviZ(6);

    Vector3d v2 = v.PomnoziSaSkalarom(v.DajX() - 1);

    v.Ispisi();
    v2.Ispisi();
    v.Ispisi();
    v2.Ispisi();
    double x, y, z;

    v2.Ocitaj(x, y, z);

    std::cout<<x<<" "<<y<<" "<<z<<std::endl;

    Vector3d v3(ZbirVektora(v,v2));
    v3.Ispisi();

    std::cout<< v3.DajDuzinu() << std::endl;

    std::cout<< "Broj ispisa za svaki je " << v.DajBrojIspisa()<< " "<< v2.DajBrojIspisa() <<" "<< v3.DajBrojIspisa();









    return 0;
}
