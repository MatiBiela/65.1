#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

class file
{
		int licznik[1000];
		int mianownik[1000];
		float minLicznik;
		float minMianownik;
        ifstream inFile;
       
        public:
                file();
                ~file();
                void loop();
				void min(); 
				bool rownyMianownik(long licznik1, long mianownik1, long licznik2, long mianownik2);
				bool mniejszyMianownik(long licznik1, long mianownik1, long licznik2, long mianownik2);
				void wynik();
};


file::file()
{
        inFile.open("dane_ulamki.txt"); 
        if (!inFile.good())
        {
                cerr << "Blad - pliku nie da sie otworzyc!\n";
                exit(1);
        }
}

file::~file()
{
        inFile.close();
}


void file::loop()
{
        while (!inFile.eof()) 
        {
                for(int i=0; i<1000; i++) {
                	inFile >> licznik[i] >> mianownik[i]; 
				}
                
        }
}

bool  file::mniejszyMianownik(long licznik1, long mianownik1, long licznik2, long mianownik2) {
		return (licznik1*mianownik2<licznik2*mianownik1);
	}
		
bool file::rownyMianownik(long licznik1, long mianownik1, long licznik2, long mianownik2) {
		return (licznik1*mianownik2==licznik2*mianownik1);
	}	

		
void file::wynik() {
	minLicznik = 0;
	minMianownik = 0;
	
	for(int i=0; i<1000; i++) {
		if(licznik[i], mianownik[i], minLicznik, minMianownik) {
			minLicznik = licznik[i];
			minMianownik = mianownik[i];
		}
		
	}
	cout << "licznik: " << licznik[i] << "mianownik: " << mianownik[i] << endl;

}
int main() {
	file f;
	f.loop();
	f.min();
	
	return 0;
}
