#include <iostream> //std::cout + std::cin
#include <algorithm> //std::random_shuffle
#include <vector> //std::vector
#include <ctime>
enum suit { SPADE, HEART, CLUB, DIAMOND };
enum menu { EXIT, DRAWCARD, SHOWHAND, COUNT };
struct card{
	suit suit;
	int value;
	bool ace;
};
const int MAX_HAND = 10;
const int MAX_DECK = 52;
const int MAGIC_NUMBER = 48;
int Menu(void);
int CardValue(card);
int HandValue(std::vector<card>*);
void CompareHands(int, int);
void PrintCard(card);
void PrintCards(std::vector<card>*);
void NewCard(std::vector<card>*, std::vector<card>*, int);
void createDeck(std::vector<card>*);
int main(){
	std::vector<card> deck; deck.reserve(MAX_DECK);
	std::vector<card> hand; hand.reserve(MAX_HAND);
	std::vector<card> dealer;
	int handvalue = 0;
	int dealervalue = 0;
	int choice = 0;
	createDeck(&deck);
	NewCard(&dealer, &deck, 2);
	while (true){
		choice = Menu();
		//system("cls");
		switch (choice){
		case EXIT:
			return EXIT_SUCCESS;
		case DRAWCARD:
			NewCard(&hand, &deck, 1);
			PrintCard(hand.back());
			std::cout << std::endl << std::endl;
			break;
		case SHOWHAND:
			std::cout << " Cards in hand: ";
			PrintCards(&hand);
			std::cout << "\nTotal value: " << handvalue << std::endl;
			break;
		case COUNT:
			if (dealervalue < handvalue){ CompareHands(handvalue, dealervalue); }
			else { CompareHands(handvalue, dealervalue); }
			break;
		default:
			handvalue = HandValue(&hand);
			dealervalue = HandValue(&dealer);
			if (dealervalue > 21){ std::cout << "Dealer's hand value exceeds 21. You have won the game!\n"; }
			else if (dealervalue == 21){ std::cout << "Dealer's hand value is 21. You have lost the game!\n"; }
			else if (handvalue == 21 && dealervalue != 21){ std::cout << "Your hand value is 21. You have won the game!\n"; }
			else if (handvalue > 21){ std::cout << "Your hand value exceeds 21. You have lost the game!\n"; }
		}
	}
	return EXIT_SUCCESS;
}
void createDeck(std::vector<card> *arg1){
	for (int i = 1; i <= 13; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			(*arg1).push_back({ suit(j), i, false });
			if ((*arg1)[i - 1].value == 1){ (*arg1)[i - 1].ace = true; }
		}
	}
	srand(time(NULL));
	std::random_shuffle((*arg1).begin(), (*arg1).end());
}
int Menu(void){
	std::cout << "MENU\n" << "0 Exit\n" << "1 Buy a card\n" << "2 Cards in hand\n" << "3 Stick\n";
	return std::cin.get() - MAGIC_NUMBER;
}
void PrintCard(card arg){
	char c = arg.suit;
	if (c == SPADE){ c = 6; }
	if (c == CLUB){ c = 5; }
	if (c == DIAMOND){ c = 4; }
	if (c == HEART){ c = 3; }
	std::cout << c << arg.value << " ";
}
void PrintCards(std::vector<card> *arg1){
	int value = 0;
	for (int i = 0; i < (*arg1).size(); i++)
	{
		PrintCard((*arg1)[i]);
	};
}
void NewCard(std::vector<card> *arg1, std::vector<card> *arg2, int arg3){
	for (int i = 0; i < arg3; i++){
		(*arg1).push_back((*arg2).back());
		(*arg2).pop_back();
	}
}
int CardValue(card arg){
	return arg.value;
}
int HandValue(std::vector<card> *arg1){
	int value = 0;
	for (int i = 0; i < (*arg1).size(); i++)
	{
		value += CardValue((*arg1)[i]);
	}
	return value;
}
void CompareHands(int arg1, int arg2){
	if (arg1 - arg2 > 0){
		std::cout << "You have won the game!\n";
	}
	else {
		std::cout << "You have lost the game!\n";
	}
	std::cout << "Your hand value is " << arg1 << "\nAnd dealer's is " << arg2 << std::endl;
}