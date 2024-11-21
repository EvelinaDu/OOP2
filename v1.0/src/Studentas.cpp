#include "../include/Studentas.h"
#include "../include/Mylib.h"

Studentas :: Studentas(const string& vardas, const string& pavarde, const vector <double>& nd, double egz){
    vardas_ = vardas;
    pavarde_ = pavarde;
    nd_ = nd;
    egz_ = egz;
    galutinis_vid_ = 0;
    galutinis_med_ = 0;
}

Studentas :: Studentas(const string& vardas, const string& pavarde, int nd_kiekis){
    const int min_rezult = 1;
    const int max_result = 10;
    //Atsitiktiniu skaičiu generatorius
    random_device rd_genrator;  
    // Intervalas atsitiktinei reikšmei
    uniform_int_distribution<int> Ivertinimas(min_rezult, max_result);
    vardas_ = vardas;
    pavarde_ = pavarde;

    for(int i = 0; i < nd_kiekis; i++){
        int nd_ivertinimas = Ivertinimas(rd_genrator);
        cout << setw(5) << left << nd_ivertinimas;
        nd_.push_back(nd_ivertinimas);
    }

    double egzoIvertinimas = Ivertinimas(rd_genrator);
    egz_ = egzoIvertinimas;
    cout << egzoIvertinimas << endl;
}

// Funkcija skirta galutiniam įvertinimui pagal vidurkį apskaičiuoti.
void Studentas :: Ivertinimas_vid(){
    double suma = 0;
    int nd_kiekis = nd_.size();

    // Pridedame kiekievieną namų darbų įvertinimą prie bendros sumos.
    for (int j = 0; j < nd_kiekis; j++){
         suma += nd_[j];
    }

    double ivertinimas;
    if (nd_kiekis > 0 ){
        galutinis_vid_ = 0.4 * suma/nd_kiekis + 0.6 * egz_;
    } else {
        galutinis_vid_ =  0.6 * egz_;
    }
}

// Funkcija skirta galutiniam įvertinimui pagal medianą apskaičiuoti.
void Studentas :: Ivertinimas_med(){
    int nd_kiekis = nd_.size();

    // Jei namų darbų nėra, tai galutinį įvertinimą nustatome pagal egzaminą.
    if (nd_kiekis == 0){
        galutinis_med_ = 0.6 * egz_;
        return;
    }
    
    sort(begin(nd_), end(nd_));


// Medianos ieškojimas
    double mediana = 0;
    int nr = nd_kiekis / 2;
    if (nd_kiekis % 2 == 0){
        mediana = (nd_[nr - 1] + nd_[nr]) / 2.0;
    } else {
        mediana = nd_[nr];
    }

// Ivertinimo apskaičiavimas naudojant medianą.
    galutinis_med_ = 0.4 * mediana + 0.6 * egz_;
    
}

Studentas :: ~Studentas(){};

