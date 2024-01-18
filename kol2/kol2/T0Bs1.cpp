#include <exception>
#include <iostream>
#include <cstring>
using namespace std;

enum class Typ {
	turystyczna = 0,
	klasowa = 1,
	edukacyjna = 2,
};
struct Organizator {
	char nazwa[200];
};
struct Wycieczka
{
	char miesceDocelowe[100];
	double cena;
	Typ typ; // 0 - turystyczna, 1 - klasowa, 2 - edukacyjna
	Organizator* organizator;
};




Wycieczka wypelnijWycieczke(const char* miesceDocelowe, double cena, Typ typ, Organizator* organizator)
{
	Wycieczka temp{};

	strcpy_s(temp.miesceDocelowe, miesceDocelowe);
	temp.cena = cena;
	temp.typ = typ;
	temp.organizator = organizator;

	return temp;
}




ostream& operator<<(ostream& co, Organizator const& val) {
	co << val.nazwa << endl;
	return co;
}
ostream& operator<<(ostream& co, Typ const& val) {
	constexpr size_t enum_size = 3;
	constexpr char typ[enum_size][20] = { "turystyczna", "klasowa", "edukacyjna" };

	co << typ[(int)val] << endl;
	return co;
}
ostream& operator<<(ostream& co, Wycieczka const& val) {
	co << "miejsce:" << val.miesceDocelowe <<",";
	co << " cena:" << val.cena <<",";
	co << " typ:" << val.typ;
	co << " organizator:" << *val.organizator << endl;

	return co;
}




void wyswietlWycieczki(const Wycieczka *wycieczki, const int size) {
	for (int i = 0; i < size; i++) {
		cout << wycieczki[i];
	}
}




char* najtanszaTypu(Wycieczka* dane, Typ typ,size_t rozmiar)
// Funkcja ma przyjać tablicę wszytskich wycieczek i typ wycieczki
// a następnie znaleźć i zwrócić nazwę orgaizatora najtanszej
// wycieczki tego typu)
{
	int najtansza = dane[0].cena;
	char* organizator;
	for (int i = 0; i <= rozmiar; i++)
	{
		if (dane[i].typ == typ)
		{
			najtansza = dane[i].cena;
			organizator = dane[i].organizator->nazwa;//problem przy przypisaniu wartoci
		}
	}
	return organizator;
}




int main()
{
	Organizator organizatorzy[] = {
		{"A-Z Podroze"},
		{"Histora i Pamiec"},
		{"Szokla w plenerze"}
	};
	Wycieczka wycieczki[] =
	{
		{"Bieszczady",2000.0,(Typ)0,&organizatorzy[0]},
		{"Oswiecim",1000,(Typ)2,&organizatorzy[1]},
		{"Szczyrk",1500,(Typ)1,&organizatorzy[2]},
		// dodaj jeszcze prznajmniej 4 instancje
		{wypelnijWycieczke("Krakow", 1300.0, Typ::klasowa, &organizatorzy[0])},
		{wypelnijWycieczke("Katowice", 1300.0, Typ::edukacyjna, &organizatorzy[1])},
		{wypelnijWycieczke("Bytom", 1300.0, Typ::turystyczna, &organizatorzy[2])},
		{wypelnijWycieczke("Wroclaw", 1300.0, Typ::klasowa, &organizatorzy[0])},
	};
	
	wyswietlWycieczki(wycieczki, 7);
	cout << "najtansza: "<<endl;
	najtanszaTypu(wycieczki, Typ::edukacyjna, sizeof(wycieczki));
}