#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include "../include/Zmogus.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using std::endl;
using std::cout;
using std::cin;

using std::string;
using std::vector;

/**
 * @class Studentas
 * @brief Žmogaus išvestinė klasė, skirta studentų duomenims saugoti tvarkyti.
 * 
 * Klasė apibrėžia pagrindinius atributus: vardas, pavarde, namų darbų įvertinimai, galutinis įvertinimas.
 */

class Studentas : public Zmogus{
  private:
  vector <double> nd_;  /**< Namų darbų įvertinimų vektorius */
  double egz_;          /**< Egzamino įvertinimas */
  double galutinis_;    /**< Egzamino įvertinimas */

  public:

  /**
   * @brief Numatytasis konstruktorius.
   * Sukuria tuščią Studento klasės objektą.
   */
  Studentas(){};

  /**
   * @brief Konstruktorius su parametrais.
   * @param vardas Studento vardas.
   * @param pavarde Studento pavardė.
   * @param nd Namų darbų įvertinimų vektorius.
   * @param egz Egzamino įvertinimas.
   */
  Studentas(const string& vardas, const string& pavarde, const vector <double>& nd, double egz);

  /**
   * @brief Konstruktorius su generuojamu namų darbų įvertinimų kiekiu.
   * Sukuria objektą su atsitiktiniais įvertinimais.
   * 
   * @param vardas Studento vardas.
   * @param pavarde Studento pavardė.
   * @param kiekis Kiek namų darbų įvertinimų sugeneruoti.
   */
  Studentas(const string& vardas, const string& pavarde, int kiekis);

  /**
   * @brief Kopijavimo konstruktorius.
   * Leidžia sukurti naują Studentas objektą, kopijuojant duomenis iš kito objekto.
   * @param saltinis Kitas Studento klasės objektas, kurio duomenys kopijuojami.
   */
  Studentas(const Studentas& saltinis);
  
  /**
   * @brief Destruktorius.
   * 
   * Atsakingas už išteklių atlaisvinimą, iškviečiamas automatiškai.
   */
  ~Studentas();

  /**
   * @brief Kopijavimo priskyrimo operatorius.
   * Leidžia priskirti vieno Studento duomenis kitam Studento klasės objektui.
   * 
   * @param saltinis Kitas Studento klasės objektas, kurio duomenys priskiriami.
   * @return Nuoroda į šį objektą.
   */
  Studentas& operator=(const Studentas& saltinis);

  /**
   * @brief Išvesties operatorius. 
   * 
   * Operatorius naudojamas tiek išvedimui į terminalą `std::cout`, tiek rašymui į failą `std::ofstream`.
   * Išveda studento informaciją (vardą, pavardę, galutinį balą) į išvesties srautą.
   * 
   * @param os Išvesties srautas.
   * @param s Studento klasės objektas, kurio duomenys spausdinami.
   * @return Modifikuotas išvesties srautas.
   */
  friend std::ostream& operator<<(std::ostream& os, const Studentas& s);

  /**
   * @brief Įvesties operatorius, skirtas studento duomenims įvesti.
   * 
   * Naudojamas perdengtas operatorius `istream& operator>>(std::istream& is, Studentas& s)`, kuris leidžia įvesti duomenis dviem būdais: 
        1. Rankinis įvedimas iš terminalo, naudojant `std::cin`. Vartotojas turi pateikti studentų vardus bei pavardes,
        įvertinimai gali būti įvesti vartotojo rankiniu būdu arba sugeneruojami atsitiktinai pagal vartotojo pasirinkimą.
        2. Duomenų nuskaitymas iš teksto srauto (pvz.: `std::stringstream`).
   * Ši funkcija leidžia įvesti studento vardą, pavardę, namų darbų balus ir egzamino balą.
   * @param is Įvesties srautas (std::cin arba failo srautas).
   * @param s Studento klasės objektas, į kurį įrašomi ir saugomi duomenys: vardas, pavardė, namų darbai, egzamino įvertinimas.
   * @return Modifikuotas įvesties srautas.
   */
  friend std::istream& operator>>(std::istream& is, Studentas& s);

  /**
   * @brief Nustato studento vardą.
   * @param vardas Naujas vardas.
   */
  void setVardas(const string& vardas) {vardas_ = vardas; }

  /**
   * @brief Nustato studento pavardę.
   * @param pavarde Nauja pavardė.
   */
  void setPavarde(const string& pavarde) {pavarde_ = pavarde; }

  /**
   * @brief Nustato namų darbų įvertinimus.
   * @param nd Naujas namų darbų įvertinimų vektorius.
   */
  void setNd(const vector<double>& nd) {nd_ = nd; }

  /**
   * @brief Nustato egzamino įvertinimą.
   * @param egz Naujas egzamino įvertinimas.
   */
  void setEgz(const double& egz) {egz_ = egz; }

  /**
   * @brief Nustato galutinį įvertinimą.
   * @param ivertinimas Naujas galutinis įvertinimas.
   */
  void setGalutinis(const double& ivertinimas){galutinis_ = ivertinimas; }


  /**
   * @brief Gauti studento vardą.
   * @return Studentas vardas.
   */
  string getVardas() const override { return vardas_; }

  /**
   * @brief Gauti studento pavardę.
   * @return Studentas pavarde.
   */
  string getPavarde() const override { return pavarde_; }

  /**
   * @brief Gauti egzamino įvertinimą.
   * @return Egzamino įvertinimą.
   */
  inline double getEgz() const {return egz_; }

  /**
   * @brief Gauti namų darbų įvertinimų vektorių.
   * @return Namų darbų įvertinimų vektorius.
   */
  inline vector<double> getNd() const { return nd_; }

  /**
   * @brief Gauti galutinį įvertinimą.
   * @return Galutinis įvertinimas.
   */
  inline double getGalutinis() const { return galutinis_; }

  
  /**
   * @brief Apskaičiuoja galutinį pažymį pagal vidurkį.
   * 
   * @details Naudoja namų darbų įvertinimų vidurkį ir egzamino įvertinimą pagal formulę:
   * Galutinis = 0.4 * NamųDarbųVidurkis + 0.6 * Egzaminas.
   */
  void Ivertinimas_vid();

  /**
   * @brief Apskaičiuoja galutinį pažymį pagal medianą.
   * 
   * @details Naudoja namų darbų įvertinimų medianą ir egzamino įvertinimą pagal formulę:
   * Galutinis = 0.4 * NamųDarbųMediana + 0.6 * Egzaminas.
   */
  void Ivertinimas_med();

  

};

#endif