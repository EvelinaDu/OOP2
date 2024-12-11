#ifndef Zmogus_H_INCLUDED
#define Zmogus_H_INCLUDED


#include <string>
using std::string;
/**
 * @class Zmogus
 * @brief Abstrakti bazinė klasė, skirta žmonių duomenims valdyti. 
 * 
 * Klasė yra abstrakčioji, tai yra negalima sukurti žmogaus tipo objektų, o tik objektus iš jos išvestinių klasių.
 * 
 * Klasė apibrėžia pagrindinius atributus (vardas, pavardė) ir funkcijas, kurios turi būti 
 * įgyvendintos paveldėtose klasėse.
 */
class Zmogus{
  protected:
  string vardas_;   /**< Žmogaus vardas. Paveldimos klasės gali tiesiogiai naudoti šį narį. */
  string pavarde_;  /**< Žmogaus pavardė. Paveldimos klasės gali tiesiogiai naudoti šį narį. */

  /**
   * @brief Numatytasis konstruktorius.
   * 
   * Inicijuoja tuščią `Zmogus` objektą. Naudojamas paveldėtos klasės konstruktoriuose.
   */
  Zmogus(){};

  /**
   * @brief Konstruktorius su parametrais.
   * @param vardas Žmogaus vardas.
   * @param pavarde Žmogaus pavardė.
   */
  Zmogus(const string& vardas, const string& pavarde) 
    : vardas_(vardas), pavarde_(pavarde) {};

  public:

  /**
   * @brief Gauti žmogaus vardą.
   * 
   * Šis metodas turi būti įgyvendintas paveldėtose klasėse, kurios apibrėžia konkretų vardų tvarkymą.
   * 
   * @return Žmogaus vardas.
   */
  virtual string getVardas() const = 0;

  /**
   * 
   * @brief Gauti žmogaus pavardę.
   * 
   * Šis metodas turi būti įgyvendintas paveldėtose klasėse, kurios apibrėžia konkretų pavardžių tvarkymą.
   * 
   * @return Žmogaus pavardė.
   */
  virtual string getPavarde() const = 0;

  /**
   * @brief Virtualus destruktorius.
   * 
   * Naudojamas išteklių atlaisvinimui paveldėtose klasėse.
   */
  virtual ~Zmogus(){};

};

#endif