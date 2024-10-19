#include "Mylib.h"
#include "Stud.h"
#include "timer.h"

int main() {
    vector<Studentas> stud;
    vector<Studentas> stud_Vargsiukai, stud_Kietiakai;
    Studentas s;
    vector<int> kiekis;              // Skirtas saugoti generuojamų failų dydžius

    string eil;                      // Skirtas saugoti duomenu eilutei

    int n;                           // Skirtas išsaugoti studentų kiekį
    // string random_pasirinkimas;      // Skirtas išsaugoti vartotojo pasirinkimą dėl įvertinimų generavimo.

    ifstream failasIn;               //Skirtas failo nuskaitymui
    string f_pav;                    //Failo pavadinimas

    string rez_pasirinkimas;
    string rusiavimo_p;
    string isvedimo_pasirinkimas;

    string ivedimo_skaitymo_p = pasirinkimas_del_programos_vykdymo();

    if(ivedimo_skaitymo_p == "N" || ivedimo_skaitymo_p == "n"){
        Duom_is_failo(stud, s);
    }
    else if(ivedimo_skaitymo_p == "I" || ivedimo_skaitymo_p == "i"){
        Info_ivedimas_ranka(stud, s, n);
    }    
    else if(ivedimo_skaitymo_p == "S" || ivedimo_skaitymo_p == "s"){
        kiekis = {1000, 10000, 100000, 1000000, 10000000};
        cout << endl;
        for (int k: kiekis){
            Timer t;

            Stud_failu_generavimas(stud, k);

            cout << "Failo su "<< stud.size() << " įrašų generavimo laikas: " << t.elapsed() << " s.\n";
            stud.clear();
            cout << endl;
        }
    }
    else if(ivedimo_skaitymo_p == "T" || ivedimo_skaitymo_p == "t"){
        rez_pasirinkimas = pasirinkimas_del_galutinio();
        rusiavimo_p = pasirinkimas_del_rusiavimo();

        // system("dir /b *.txt");
        // system("dir *.txt /B");
        Duom_is_failo(stud, s);
        

        n = stud.size();
        Duom_tvarkymas(stud, stud_Vargsiukai, stud_Kietiakai, rez_pasirinkimas, rusiavimo_p, isvedimo_pasirinkimas, ivedimo_skaitymo_p, n);

    }
    

    if(ivedimo_skaitymo_p != "S" && ivedimo_skaitymo_p != "s" && ivedimo_skaitymo_p != "T" && ivedimo_skaitymo_p != "t"){
        rez_pasirinkimas = pasirinkimas_del_galutinio();
        rusiavimo_p = pasirinkimas_del_rusiavimo();
        isvedimo_pasirinkimas = pasirinkimas_isvedimo();
        n = stud.size();
        SpausdinimasRez(stud, n, isvedimo_pasirinkimas, rez_pasirinkimas, rusiavimo_p, ivedimo_skaitymo_p);

    }

    return 0;
}