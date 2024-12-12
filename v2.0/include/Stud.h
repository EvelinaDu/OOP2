#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED

#include "Mylib.h"
#include "Studentas.h"


/**
 * @brief Funkcija, skirta studento duomenų įvedimui rankiniu būdu.
 * 
 * Ši funkcija leidžia vartotojui ranka įvesti studento namų darbų įvertinimus ir egzamino rezultatą.
 * 
 * @tparam Container Konteinerio tipas (pvz., std::vector arba std::list).
 * @param stud Konteineris, į kurį bus įvedami studentų duomenys.
 * @param vardas Studentų vardas.
 * @param pavarde Studentų pavardė.
 * 
 * @note Funkcija veikia tiek su vector<Studentas>, tiek su list<Studentas>.
 */
template <typename Container>
void Duom_ivedimas(Container &stud, string vardas, string pavarde);

/** 
 * @brief Surenkama bendra informacija apie studentų duomenis. Klausiama studentų vardų bei pavardžių, koks įvertinimų įvedimas (rankinis ar generavimas) ir pagal tai įvykdoma.
 * @tparam Container Konteinerio tipas (pvz., std::vector arba std::list).
 * @param stud Konteineris, į kurį bus įvedami studentų duomenys.
 * @param n Studentų skaičius, kurį vartotojas nori įtraukti.
 * 
 * @note Funkcija veikia tiek su vector<Studentas>, tiek su list<Studentas>.
*/
template <typename Container>
void Info_ivedimas_ranka(Container &stud, int n);

/** 
 * @brief Funkcija skirta nuskaityti studento įvertinimus iš failo.
 * @tparam Container Konteinerio tipas (pvz., std::vector arba std::list).
 * @param stud Konteineris, į kurį bus įvedami studentų duomenys.
 * 
 * @note Funkcija veikia tiek su vector<Studentas>, tiek su list<Studentas>.
*/
template <typename Container>
void Duom_is_failo(Container &stud);

/** 
 * @brief Funkcija, skirta sugeneruoti studentų duomenų failą su nurodytu įrašų kiekiu.
 * @param kiekis Failo įrašų kiekis.
*/
void Stud_failu_generavimas(int kiekis);

/**
 * @brief Funkcija, skirta atspausdinti antraštei pagal vartoto įvertinimo pasirinkimą.
 * @param pasirinkimas Pasirinkimas nurodantis pagal ką buvo skaičiuotas galutinis rezultatas (vidurkis ar mediana).
 * @param out Srautas, į kurį spausdinama (pvz., terminalas ar failas).
 * @param isvedimo_pasirinkimas Rezultatų išvedimo pasirinkimas (T - terminalas, F - failas).
 */
void Rez_antraste(string pasirinkimas, ostream &out, string isvedimo_pasirinkimas);

/** 
 * @brief Funkcija skirta studentų rūšiavimui.
 * @tparam Container Konteinerio tipas (pvz., std::vector arba std::list).
 * @param pasirinkimas Pasirinkimas nurodo, pagal ką studentų konteineris bus rūšiuojamas (pvz.: pagal vardą ir pavarde, pavardę ir vardą, galutinį įvertinimą mažėjančia tvarka, pagal galutinį įvertinimą didėjančia tvarka).
 * 
 * @note Funkcija veikia tiek su vector<Studentas>, tiek su list<Studentas>.
*/
template <typename Container>
void Studentu_rusiavimas(Container &stud, string pasirinkimas);

/**
 * @brief Funkcija skirta rezultatams atspausdinti į terminalą (vartotojui pasirinkus 'T') arba įrašyti į failą (vartotojui pasirinkus 'F').
 * @tparam Container Konteinerio tipas (pvz., std::vector arba std::list).
 * @param isvedimo_pasirinkimas Rezultatų išvedimo pasirinkimas (T - terminalas, F - failas).
 * @param rez_pasirinkimas Pasirinkimas pagal ką skaičiuotas galutinis rezultatas (vidurkis ar mediana).
 * @param rusiavimo_p Pasirinkimas nurodo, pagal ką studentų konteineris bus rūšiuojamas (pvz.: pagal vardą ir pavarde, pavardę ir vardą, galutinį įvertinimą mažėjančia tvarka, pagal galutinį įvertinimą didėjančia tvarka).
 * @param ivedimo_skaitymo_p Pasirinkimas, kuris tikrinamas ar lygus T - Testavimui, tuo atviju bendras visų studentų konteineris yra atspausdinimas į faila Rez.txt.
 * 
 * @note Funkcija veikia tiek su vector<Studentas>, tiek su list<Studentas>.
 */
template <typename Container>
void SpausdinimasRez(Container &stud, string isvedimo_pasirinkimas, string rez_pasirinkimas, string rusiavimo_p, string ivedimo_skaitymo_p);

/**
 * @brief Funkcija skirsto studentus į dvi grupes: "vargsiukus" ir "kietiakus".
 * 
 * Funkcija patikrina kiekvieno studento galutinį pažymį (getGalutinis()) ir priskiria jį į vieną iš dviejų grupių:
 * - stud_Vargsiukai – jei galutinis pažymys mažesnis už 5.0.
 * - stud_Kietiakai – jei galutinis pažymys lygus arba didesnis už 5.0.
 * 
 * @tparam Container Konteinerio tipas (pvz., std::vector arba std::list).
 * @param stud Pradinė studentų konteineris, kurį reikia suskirstyti.
 * @param stud_Vargsiukai konteineris, į kurią bus priskirti "vargsiukai".
 * @param stud_Kietiakai konteineris, į kurią bus priskirti "kietiakai".
 * 
 * @note Funkcija nekeičia pradinio stud konteinerio, o tik kopijuoja elementus į naujas grupes.
 * Funkcija veikia tiek su vector<Studentas>, tiek su list<Studentas>.
 */
template <typename Container>
void Kategorijos_Priskirimas1(Container &stud, Container &stud_Vargsiukai, Container &stud_Kietiakai);

/**
 * @brief Funkcija skirsto studentus į dvi grupes: "vargsiukus" ir likusius, pašalindama "vargsiukus" iš pradinio konteinerio.
 * 
 * Funkcija rūšiuoja studentų konteinerį mažėjančia tvarka pagal galutinį pažymį (getGalutinis()). 
 * Tada perkelia studentus, kurių galutinis pažymys mažesnis už 5.0, į "vargsiukų" konteinerį
 * (stud_Vargsiukai) ir pašalina juos iš pradinio konteinerio (stud).
 * 
 * @tparam Container Konteinerio tipas (pvz., std::vector arba std::list).
 * @param stud Pradinis studentų konteineris, kuri bus modifikuojama (iš jos pašalinami "vargsiukai").
 * @param stud_Vargsiukai Konteineris, į kurį bus perkelti "vargsiukai".
 * 
 * @note Pradinis konteineris stud bus modifikuota – joje liks tik studentai, kurių galutinis pažymys >= 5.0.
 * Funkcija veikia tiek su vector<Studentas>, tiek su list<Studentas>.
 */

template <typename Container>
void Kategorijos_Priskirimas2(Container &stud, Container &stud_Vargsiukai);

/**
 * @brief Skirsto studentus į dvi grupes: "vargsiukus" ir "kietiakus", naudojant std::stable_partition.
 * 
 * Ši funkcija naudoja std::stable_partition metodą, kad stabiliai atskirtų studentus 
 * su galutiniu švertinimu mažesniu nei 5.0 ("vargsiukai") nuo tų, kurių pažymys >= 5.0 ("kietiakai").
 * "Vargsiukai" perkelti į atskirą konteinerį, o pradinis konteineris modifikuojama, pašalinant "vargsiukus".
 * 
 * @tparam Container Konteinerio tipas (pvz., std::vector arba std::list).
 * @param stud Pradinis studentų konteineris, iš kurios bus pašalinti "vargsiukai".
 * @param stud_Vargsiukai Konteineris, į kurią bus perkelti "vargsiukai".
 * 
 * @note Pradinis konteineris `stud` modifikuojamas – iš jo pašalinami "vargsiukai".
 * "Vargsiukai" yra perkelti į `stud_Vargsiukai`, išsaugant jų pradines eiles.
 * Funkcija veikia tiek su vector<Studentas>, tiek su list<Studentas>.
 */
template <typename Container>
void Kategorijos_Priskirimas3(Container &stud, Container &stud_Vargsiukai);

/**
 * @brief Įrašo pateiktą studentų konteinerį į nurodytą failą.
 * 
 * Ši funkcija atidaro failą pagal nurodytą pavadinimą ir įrašo studentų duomenis iš pateikto konteinerio.
 * Taip pat antraštė generuojama naudojant funkciją Rez_antraste.
 * 
 * @tparam Container Konteinerio tipas (pvz., std::vector arba std::list).
 * @param studentai Studentų konteineris, kuris bus įrašytas į failą.
 * @param pasirinkimas Pasirinkimas nurodantis pagal ką buvo skaičiuotas galutinis rezultatas (vidurkis ar mediana). (Skirta antraštei)
 * @param isvedimo_pasirinkimas Rezultatų išvedimo pasirinkimas (T - terminalas, F - failas). (Skirta antraštei)
 * @param pav Failo pavadinimas, į kurį bus įrašomi duomenys.
 * 
 * @note Funkcija veikia tiek su vector<Studentas>, tiek su list<Studentas>.
 */
template <typename Container>
void FailasPgalKategorija(Container &studentai, string pasirinkimas, string isvedimo_pasirinkimas, string pav);

/**
 * @brief Leidžia vartotojui pasirinkti programos vykdymo režimą.
 * 
 * Funkcija pateikia vartotojui klausimą, kokį veikimo režimą pasirinkti, ir užtikrina,
 * kad įvestis būtų viena iš galimų reikšmių: I, N, S, T, arba D.
 * Jei įvestis netinkama, funkcija kartoja klausimą tol, kol gaunama tinkama reikšmė.
 * 
 * @return Pasirinktas veikimo režimas kaip string (I, N, S, T, arba D).
 */
string pasirinkimas_del_programos_vykdymo();

/**
 * @brief Leidžia vartotojui pasirinkti duomenų struktūrą.
 * 
 * Funkcija pateikia vartotojui klausimą, kokią duomenų struktūrą norima naudoti, 
 * ir užtikrina, kad įvestis būtų tinkama (V - vektorius, S - sąrašas).
 * 
 * @return Pasirinktas duomenų struktūros tipas kaip string (V arba S).
 */
string pasirinkimas_del_duom_strukturos();

/**
 * @brief Leidžia vartotojui pasirinkti galutinio įvertinimo skaičiavimo metodą.
 * 
 * Funkcija pateikia klausimą vartotojui, ar galutinį įvertinimą skaičiuoti pagal vidurkį, ar pagal medianą.
 * Užtikrina, kad įvestis būtų tinkama (V - vidurkis, M - mediana).
 * 
 * @return Pasirinktas galutinio įvertinimo metodas kaip string (V arba M).
 */
string pasirinkimas_del_galutinio();

/**
 * @brief Leidžia vartotojui pasirinkti rūšiavimo būdą.
 * 
 * Funkcija pateikia klausimą vartotojui, pagal ką reikia surūšiuoti studentus.
 * Užtikrina, kad įvestis būtų tinkama (VP, PV, GM, GD).
 * 
 * @return Pasirinktas rūšiavimo būdas kaip string (VP, PV, GM arba GD).
 */
string pasirinkimas_del_rusiavimo();

/**
 * @brief Leidžia vartotojui pasirinkti, kur nori matyti rezultatą: terminale ar faile.
 * 
 * Funkcija pateikia klausimą vartotojui, kur norėtų jis matyti rezultatą. Vartotojas gali pasirinkti:
 * - 'T' - terminale,
 * - 'F' - faile.
 * 
 * @return Pasirinktas rezultato pateikimo būdas kaip string ('T' arba 'F').
 */
string pasirinkimas_isvedimo();

/**
 * @brief Leidžia vartotojui pasirinkti strategiją studentų skirstymui į dvi grupes.
 * 
 * Funkcija pateikia klausimą vartotojui apie pasirenkamą strategiją. 
 * Galimos strategijos:
 * - '1' - Pirmoji strategija,
 * - '2' - Antroji strategija,
 * - '3' - Trečioji strategija.
 * 
 * @return Pasirinkta strategija kaip sveikasis skaičius (1, 2 arba 3).
 */
int pasirinkimas_del_strategijos();

/**
 * @brief Apdoroja studentų duomenis, skirsto į grupes ir išsaugo į failus.
 * 
 * Ši funkcija vykdo šiuos veiksmus:
 * 1. Spausdina pradinius studentų duomenis.
 * 2. Skirsto studentus į dvi grupes (vargsiukai ir kietiakai) pagal pasirinktą strategiją.
 * 3. Rūšiuoja studentų duomenis pagal vartotojo pasirinktą kriterijų.
 * 4. Įrašo rezultatus į atskirus failus (Vargsiukai.txt ir Kietiakai.txt).
 * 
 * @tparam Container Konteinerio tipas (pvz., std::vector arba std::list).
 * @param stud Pagrindinis konteineris, kuriame yra visi studentų duomenys.
 * @param stud_Vargsiukai Konteineris, kuriame bus saugomi studentai, nepasiekę nustatyto rezultato (vargsiukai).
 * @param stud_Kietiakai Konteineris, kuriame bus saugomi geriausi studentai (kietiakai).
 * @param rez_pasirinkimas Rezultatų išvedimo būdas (pvz., į failą ar terminalą).
 * @param rusiavimo_p  Pasirinkimas nurodo, pagal ką studentų konteineris bus rūšiuojamas 
 * (pvz.: pagal vardą ir pavarde, pavardę ir vardą, galutinį įvertinimą mažėjančia tvarka, pagal galutinį įvertinimą didėjančia tvarka).
 * @param isvedimo_pasirinkimas Rezultatų failo pavadinimas (pvz., Rezultatai.txt).
 * @param ivedimo_skaitymo_p Įvedimo failo pavadinimas.
 * @param kategorijos_strategija Pasirinkta strategija studentų skirstymui į grupes (1, 2 arba 3).
 * @param kiekis Studentų įrašų skaičius (naudojamas rezultatų laikui spausdinti).
 * 
 * @note Funkcija veikia tiek su vector<Studentas>, tiek su list<Studentas>.
 * 
 */
template <typename Container>
void Duom_tvarkymas(Container &stud, Container &stud_Vargsiukai, Container &stud_Kietiakai, string rez_pasirinkimas, string rusiavimo_p, string isvedimo_pasirinkimas, string ivedimo_skaitymo_p, int kategorijos_strategija, int kiekis);

#endif