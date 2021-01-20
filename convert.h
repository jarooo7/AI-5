#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include "convert.cpp"
 
 //converts a string to a decimal intiger
 inline unsigned int string_to_int(const std::string& s);

inline int strlength(std::string hi);

 //converts a string to a double 
  inline double string_to_double(const std::string& s);
 
 //converts a decimal integer to a string 
   inline std::string int_to_string(const int liczba);
 
 
 //converts a float to a string 
    inline std::string float_to_string(const float liczba);
  
 //converts a double to a string 
     inline std::string double_to_string(const double liczba);

 //converts a decimal integer to a char
    inline char int_to_char(int liczba);
     
//absolute value of the difference between two numbers |x-y|
  inline float modul_roznicy(float x, float y);
 
 //converts a string to a float  
   inline float string_to_float(const std::string& s);

   inline std::string long_to_string(const long liczba);
