#include <iostream>

using namespace std;

const int MAX_LENGTH = 50;
const int NUMBERS_LEN = 10;
const int LETTERS_LEN = 26;
const int SIGNS_LEN = 18;

const char numbers[NUMBERS_LEN] = { '0','1','2','3','4','5','6','7','8','9' };
const char* morseNumbers[NUMBERS_LEN] = { "-----",".----","..---","...--","....-","......","-....","--...","---..","----." };
const char letters[LETTERS_LEN] = { 'a','b','c','d','e','f','g', 'h', 'i', 'j', 'k','l','m', 'n','o','p','q','r','s','t','u','v','w','x','y','z' };
const char*  morseLetters[LETTERS_LEN] = { ".-","-..","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
const char signs[SIGNS_LEN] = { '.',',','?', '\'','!','/','(',')','&',':',';','=','+', '-','_','"','$','@' };
const char*  morseSigns[SIGNS_LEN] = { ".-.-.-","--..--","..--..",".----.","-.-.--","-..-.","-.--.","-..-.-",".-...","---...", "-.-.-."," -...-",".-.-.","-....-","..--.-",".-..-.","...-..-",".--.-." };
int main()
{
	char expression[MAX_LENGTH];
	cout << "Enter the expression that you want to translate from English to Morse Code: ";
	cin.getline(expression, MAX_LENGTH);

	for (int i = 0; i < strlen(expression); i++)// for every sign in the expression
	{
		if (expression[i] >= 48 && expression[i] <= 57)// checks if the sign is a number
		{
			for (int j = 0; j < NUMBERS_LEN; j++)// if it is a number, checks which number it is
			{
				if (expression[i] == numbers[j])// when it finds the number, prints it in morse code
				{
					cout << morseNumbers[j] << "  ";
					break;
				}
			}
		}
		//if the sign is not a number, checks if it is a letter
		else if (((expression[i] | 0x20) >= 97) && ((expression[i] | 0x20) <= 122)) //97-122 code for the letters in ASCI table
		{
			for (int j = 0; j < LETTERS_LEN; j++)
			{
				if ((expression[i] | 0x20) == letters[j])
				{
					cout << morseLetters[j] << "  ";
					break;
				}
			}
		}
		else
		{
			bool canTranslate = false;
			for (int j = 0; j < SIGNS_LEN; j++)
			{
				if (expression[i] == signs[j])
				{
					cout << morseSigns[j] << "  ";
					canTranslate = true;
					break;
				}
			}
			//if the sign is invalid
			if (canTranslate == false)
			{
				cout << "Invalid sign!" << "  ";
			}
		}
	}
	cout << endl;

	return 0;
}
