/*
VAIHTOEHTOINEN Harjoitus 22 (Palautus vko 49)  VENTTI
Tee ohjelma, joka voit k‰ytt‰‰ jaettavien korttien tallettamisen(max 10 korttia).
Ohjelma antaa k‰ytt‰j‰lle seuraavan valikon :

VALIKKO
0 Lopeta
1 Ota uusi kortti
2 Nayta kaikki kortit
3 Laske ja n‰yt‰ korttien summa



Tee lueteltu tyyppi
enum MAA { PA = 0, HE, RI, RU };

Tallenna korttien tiedot tietuetaulukkoon.
Tallennettavia tietoja ovat
maa(lueteltu tyyppi MAA)
kortin numero(kokonaisluku1 - 13)
assa(0 = ei ‰ss‰, 1 = ‰ss‰)

Toteuta ensin koko ohjelma p‰‰ohjelmana.

T‰m‰n j‰lkeen lis‰‰ seuraavat aliohjelmat :
a) int Valikko(void);
b) void TulostaKortti(KORTTI yksiKortti);
c) void TulostaKaikkiKortit(KORTTI kasi[], int korttienLkm);
d) void UusiKortti(KORTTI kasi[], int *korttienLkm);
e) tee  LaskeJaNaytaSumma(Ö) aliohjelma

Juho Nissi
19.11.2014
Versio 1.0
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

enum SUIT{ SPADES = 0, HEARTS, CLUBS, DIAMOND };
enum RANK {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

struct Card{
	SUIT suit;
	RANK rank;
	bool Ace;
	//Card(SUIT s, RANK r);
};

const int MAX_HAND = 10;
const int MAX_DECK = 52;


int AskWhatToDo();
void CreateDeck(std::vector<Card>*);
void DrawACrad();
void PrintCard();
int main(){
	std::vector<Card> Deck; 
	
	int choice;

	do{

		choice = AskWhatToDo();
		switch (choice)
		{
		case 0: exit(0);
		case 1:	cout << "\nYou got card: " << endl;
			break;
		case 2: cout << "\nCards: " << endl;
			break;
		case 3: cout << "\nYou got : " << endl;
		}
	} while (choice = !0);
}




int AskWhatToDo(void)
{
	int choice;
	cout << "Menu";
	cout << "\n\n0 End Game";
	cout << "\n1 Take a card ";
	cout << "\n2 Show all cards ";
	cout << "\n3 Calculate and show card ";
	cin >> ws >> choice;
	return choice;
}


void CreateDeck(std::vector<Card>*arg1){
	for (int i = 1; i <= 13; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			(*arg1).push_back({ SUIT(j), i, false });
			if ((*arg1)[i - 1].rank == 1){ (*arg1)[i - 1].Ace = true; }
		}
	}
	srand(time(NULL));
	std::random_shuffle((*arg1).begin(), (*arg1).end());
}


void DrawACard(){

}
