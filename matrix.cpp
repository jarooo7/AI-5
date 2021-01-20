//******************************************************************** 
 //funkcja zapisywania informacji z tablicy do pliku tekstowego;
inline void zapis(unsigned int rows , unsigned int cols , std::string **tablica,const char* str)
{
//cout <<"\nZapisywanie macierzy Ga do pliku";
 std::string __str(str);
// __str += ".tab";
      std::ofstream plik2(__str.c_str());
      
      for (unsigned int i=1; i<rows+1; i++) 
      {  
           for(unsigned int j=1; j<cols+1; j++) 
           {
               plik2 << tablica[i][j];
               
               if(j<cols)
                 {   
                  plik2 << " ";
                 }
           }
       if(i<=rows)
         {    
          plik2 <<std::endl; 
         }
      }
//cout <<"... zapisano jako "<<__str<<"\n\n";
plik2.close();
}
 
//******************************************************************** 
 //funkcja zapisywania informacji z tablicy do pliku tekstowego;
inline void zapis_double(unsigned int rows , unsigned int cols , double **tablica,const char* str)
{
//cout <<"\nZapisywanie macierzy Ga do pliku";
 std::string __str(str);
 __str += ".txt";
      std::ofstream plik2(__str.c_str());
      
      for (unsigned int i=1; i<rows+1; i++) 
      {  
           for(unsigned int j=1; j<cols+1; j++) 
           {
               plik2 << tablica[i][j]<<" ";
           }
       plik2 <<std::endl; 
      }
//cout <<"... zapisano jako "<<__str<<"\n\n";
plik2.close();
}

//******************************************************************** 
inline void wypisz_macierz_string(unsigned int rows , unsigned int cols , std::string **tablica)
{   
    std::cout<<"\n";  
      for (unsigned int i=1; i<rows+1; i++) 
      {  
          //std::cout<<i<<" ";
           for(unsigned int j=1; j<cols+1; j++) 
           {
               std::cout <<" "<< tablica[i][j];
           }
           std::cout<<"\n";
      }
getchar();
}

//******************************************************************** 
inline void wypisz_macierz_int(unsigned int rows , unsigned int cols , int **tablica)
{     
      for (unsigned int i=1; i<rows+1; i++) 
      {  
           for(unsigned int j=1; j<cols+1; j++) 
           {
               //std::cout <<" "<< tablica[i][j];
           }
           //std::cout<<"\n";
      }
////getchar();
}

//******************************************************************** 
//funkcja wczytywania informacji z pliku tekstowego do tablicy;
void wczytywanie(unsigned int rows, unsigned int cols, std::string **tablica, const char* str)
{
 std::string __str(str);
    std::ifstream plik(__str.c_str());
   
   //sprawdzanie czy otwierany plik istnieje
   if (!plik) {
        std::cerr << "Nie udalo sie otworzyc pliku do odczytu ";
              //std::cout <<""<<wsk;
              //getchar();   
    }
    //koniec sprawdzania czy otwierany plik istnieje;

    if (!plik.is_open())
    throw-1;   
//cout <<'\n'<<"Otwieranie pliku o nazwie "<<wsk<<"\n";
//cout <<"\npo nacisnieciu entera\n";
////getchar();
//cout << "Wczytuje:\n";
for ( unsigned int j=1;j<rows+1;j++)    
  {
//cout <<"\nx"<<j<<" = ";                      
    for ( unsigned int i=1;i<cols+1;i++) 
    {
         plik >> tablica[j][i];
         //std::cout <<" "<< tablica[j][i];
    }
//std::cout <<"\n";
  }  
//std::cout <<'\n'<<'\n';
plik.close();
}

//******************************************************************** 

//******************************************************************** 
//funkcja wczytywania informacji z pliku tekstowego do tablicy, nazwa wczytywanego pliku moze byc zmienna;
void wczytywanie2(unsigned int rows, unsigned int cols, std::string **tablica, const char* str)
{

 std::string __str(str);
 __str += ".txt";
      std::ifstream plik21(__str.c_str());
   
   //sprawdzanie czy otwierany plik istnieje
   if (!plik21) {
        std::cerr << "Nie udalo sie otworzyc pliku do odczytu ";
              //std::cout <<""<<__str.c_str();
              ////getchar();   
    }
    //koniec sprawdzania czy otwierany plik istnieje;

    if (!plik21.is_open())
    throw-1;   
//cout <<'\n'<<"Otwieranie pliku o nazwie "<<wsk<<"\n";
//cout <<"\npo nacisnieciu entera\n";
//////getchar();
//cout << "Wczytuje:\n";
for ( unsigned int j=1;j<rows+1;j++)    
  {
//cout <<"\nx"<<j<<" = ";                      
    for ( unsigned int i=1;i<cols+1;i++) 
    {
         plik21 >> tablica[j][i];
         std::cout <<" "<< tablica[j][i];
    }
    std::cout <<"\n";
  }  
std::cout <<'\n'<<'\n';
plik21.close();
}
//******************************************************************** 

//******************************************************************** 
//funkcja wczytywania informacji z pliku tekstowego do tablicy;
inline int num_cols_file(const char* str)
{
 std::cout<<"\n\nWykrywam liczbe atrybutow w pliku "<<str<<"\n";     
 std::string __str(str);
    std::ifstream plik(__str.c_str());

int rows,cols;

    //sprawdzanie czy otwierany plik istnieje
   if (!plik) {
        std::cerr << "\n\nNie udalo sie otworzyc pliku o nazwie " <<str;
    }
    //koniec sprawdzania czy otwierany plik istnieje;

    rows=0;
    cols=0;
    int cols_error=0;     
    std::string tab;      
    char znak;
    int k=0;
    while(plik.good())
    {
                      plik >> tab;
                      znak=plik.get();
                      cols++;   
                      cols_error++;                   
                      if(znak=='\n')
                      {                           
                       cols_error=0;
                       rows++;
                       break;
                      }
    } 

    while(plik.good())
    {
                      plik >> tab;
                      znak=plik.get();
                      cols_error++;                                       
                      if(znak=='\n' or cols_error==cols)
                      {                        
                       rows++;
                       if(cols_error!=cols)
                        {
                        std::cout<<"\n\nLinia numer "<<rows<<" jest nieprawidlowa";
                        std::cout<<"\nzawiera "<<cols_error<<" wartosci";
                        }             
                       cols_error=0;
                       continue;
                      }
    } 
plik.close();

return cols;
}
//******************************************************************** 


//******************************************************************** 
//funkcja wczytywania informacji z pliku tekstowego do tablicy;
inline int num_rows_file(const char* str)
{
 std::cout<<"\n\nWykrywam liczbe obiektow w pliku "<<str<<"\n";     
 std::string __str(str);
    std::ifstream plik(__str.c_str());

int rows,cols;

    //sprawdzanie czy otwierany plik istnieje
   if (!plik) {
        std::cerr << "\n\nNie udalo sie otworzyc pliku o nazwie " <<str;
    }
    //koniec sprawdzania czy otwierany plik istnieje;

    rows=0;
    cols=0;
    int cols_error=0;     
    std::string tab;      
    char znak;
    int k=0;
    while(plik.good())
    {
                      plik >> tab;
                      znak=plik.get();
                      cols++;   
                      cols_error++;                   
                      if(znak=='\n')
                      {                           
                       cols_error=0;
                       rows++;
                       break;
                      }
    } 

    while(plik.good())
    {
                      plik >> tab;
                      znak=plik.get();
                      cols_error++;                                       
                      if(znak=='\n' or cols_error==cols)
                      {                        
                       rows++;
                       if(cols_error!=cols)
                        {
                        std::cout<<"\n\nLinia numer "<<rows<<" jest nieprawidlowa";
                        std::cout<<"\nzawiera "<<cols_error<<" wartosci";
                        }             
                       cols_error=0;
                       continue;
                      }
    } 
plik.close();

return rows;
}
//******************************************************************** 

//******************************************************************** 
 //funkcja wypelnia tablice ustalonym znakiem;
inline void wypelnianie_tablicy_znakiem(unsigned int rows, unsigned int cols,std::string **tablica,const char x)
{
   //zaznaczanie tabl_reg
for(int i=1;i<rows;i++)
  {
   for(int j=1;j<cols;j++)
     {
     tablica[i][j]=x;              
     } 
   }  
}
//******************************************************************** 

