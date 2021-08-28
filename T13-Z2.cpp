
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class ApstraktniStudent
{
protected:
    std::string ime, prezime;
    int brIndeksa, brPol_ispita;
    double prosjecna_ocena;

public:

    ApstraktniStudent(std::string ime, std::string prezime, int brIndeksa ) : ime(ime), prezime(prezime),brIndeksa(brIndeksa), brPol_ispita(0), prosjecna_ocena(5)
    {
    }

    std::string DajIme() const {return ime;}

    std::string DajPrezime() const {return prezime;}

    int DajBrojIndeksa() const { return brIndeksa;}

    int DajBrojPolozenih() const { return brPol_ispita;}

    double DajProsjek() const { return prosjecna_ocena;}

    void RegistrirajIspit(double ocena)
    {
        if(ocena < 5 && ocena > 0)
        {
            brPol_ispita++;
            prosjecna_ocena += ocena/ brPol_ispita;
        }
    }

    void PonistiOcene()
    {
        brPol_ispita = 0;
        prosjecna_ocena = 5;
    }

    virtual void IspisiPodatke() = 0;

    virtual ApstraktniStudent* DajKopiju() const = 0;

};


class StudentBachelor : public ApstraktniStudent
{

public:

    StudentBachelor(std::string ime, std::string prezime, int brIndeksa ) : ApstraktniStudent(ime,prezime,brIndeksa ) {}

    void IspisiPodatke() override
    {
        std::cout<<"Student bachelor studija <"<<DajIme()<<"> <"<<DajPrezime()<<">, sa brojem indeksa <"<<DajBrojIndeksa()<<">, \nima prosek <"<<DajProsjek()<<">."<<std::endl;

    }

    ApstraktniStudent* DajKopiju() const override
    {
        return new StudentBachelor(*this);
    }

};

class StudentMaster : public ApstraktniStudent
{
    int godina;
public:

    StudentMaster(std::string ime, std::string prezime, int brIndeksa, int godina) : ApstraktniStudent(ime,prezime,brIndeksa), godina(godina) {}

    int DajGodinu() { return godina;}

    void IspisiPodatke() override
    {
        std::cout<<"Student master studija <"<<this->DajIme()<<"> <"<<this->DajPrezime()<<">, sa brojem indeksa <"<<this->DajBrojIndeksa()<<">, \nzavrsio bachelor studij godine <"<<this->DajGodinu()<<">, ima prosek <"<<this->DajProsjek()<<">."<<std::endl;
    }

    ApstraktniStudent* DajKopiju() const override
    {
        return new StudentMaster(*this);
    }

};


class Fakultet
{

std::vector<ApstraktniStudent*> studenti;

public:

    Fakultet() = default; //Jer je i vector klasa koja ima besparametarni konstruktor pa ovim pozivas i njegov konstruktor

    void UpisiStudenta(int brIndeksa, std::string ime, std:: string prezime)
    {
        StudentBachelor* student = new StudentBachelor(ime,prezime,brIndeksa);
        studenti.push_back(student);
    }

    void UpisiStudenta(int brIndeksa, std::string ime, std::string prezime, int godinaZavrsavanja)
    {
        StudentMaster* student = new StudentMaster(ime,prezime,brIndeksa, godinaZavrsavanja);
        studenti.push_back(student);
    }

    void ObrisiStudenta(int brIndeksa)
    {
        for(ApstraktniStudent* student : studenti )

            if( student->DajBrojIndeksa() == brIndeksa )

                std::remove(studenti.begin(), studenti.end(), student);

    }

    ApstraktniStudent* operator [] (int brojIndeksa) const
    {
        for(ApstraktniStudent* student : studenti )

            if( student->DajBrojIndeksa() == brojIndeksa ) return student;

    }

    void IspisiSveStudente()
    {
        for(int i = 0; i < studenti.size() - 1; i++ )
        {
            for(int j = i + 1; j < studenti.size(); j++)
                if(studenti[i]->DajProsjek() > studenti[j]->DajProsjek())
                {
                    std::swap(studenti[i], studenti[j]);
                }
                else if(studenti[i]->DajProsjek() == studenti[j]->DajProsjek())
                {
                    if(studenti[i]->DajBrojIndeksa() > studenti[j]->DajBrojIndeksa())
                    {
                        std::swap(studenti[i], studenti[j]);
                    }

                }
        }

        for(ApstraktniStudent* student: studenti)   student->IspisiPodatke();

    }


};


int main()
{


    StudentBachelor b = StudentBachelor("Neko","Nekic",3);

    StudentMaster m = StudentMaster("Master","Masteric",4,2010);


    b.RegistrirajIspit(4);


    b.IspisiPodatke();

    m.PonistiOcene();

    m.IspisiPodatke();

//    StudentMaster m1 = m.DajKopiju(); 

//    m1.IspisiPodatke();


    return 0;
}
