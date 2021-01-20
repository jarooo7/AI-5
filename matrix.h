#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include "convert.h"
#include "matrix.cpp"
 
//******************************************************************** 
 //funkcja zapisywania informacji z tablicy do pliku tekstowego;
inline void zapis(unsigned int rows , unsigned int cols , std::string **tablica,const char* str); 
//******************************************************************** 
 //funkcja zapisywania informacji z tablicy do pliku tekstowego;
inline void zapis_double(unsigned int rows , unsigned int cols , double **tablica,const char* str);

//******************************************************************** 
inline void wypisz_macierz_string(unsigned int rows , unsigned int cols , std::string **tablica);

//******************************************************************** 
inline void wypisz_macierz_int(unsigned int rows , unsigned int cols , int **tablica);

//******************************************************************** 
//funkcja wczytywania informacji z pliku tekstowego do tablicy;
void wczytywanie(unsigned int rows, unsigned int cols, std::string **tablica, const char* str);

//******************************************************************** 

//******************************************************************** 
//funkcja wczytywania informacji z pliku tekstowego do tablicy, nazwa wczytywanego pliku moze byc zmienna;
void wczytywanie2(unsigned int rows, unsigned int cols, std::string **tablica, const char* str);
//******************************************************************** 
//funkcja wczytywania informacji z pliku tekstowego do tablicy;
inline int num_cols_file(const char* str);

//******************************************************************** 
//funkcja wczytywania informacji z pliku tekstowego do tablicy;
inline int num_rows_file(const char* str);

//******************************************************************** 
 //funkcja wypelnia tablice ustalonym znakiem;
inline void wypelnianie_tablicy_znakiem(unsigned int rows, unsigned int cols,std::string **tablica,const char x);
//******************************************************************** 

