#include  <iostream>
#include  <iomanip>
#include  <cstdlib>
#include  <vector>
#include  <ctype.h>
#include  <random>
#include  <ctime>
#include <cctype>
#include <algorithm>

using  namespace  std;

const int SHORT_WORDS = 14;
const int LONG_WORDS = 15;
const int MAXWORD = 29;

char *words[] = { "student", "smile", "friend", "family", "teacher", "world", "garden", "house", "paper", "girl", "game", "brother", "morning", "night", "school",
 "refrigerator", "unstoppable", "prosperity", "anonymous", "vocabulary", "happiness", "software" , "dictionary", "definition", "operation", "chronological","pronunciation", "combination", "unforgettable", "meaningless" };

int lengthOfWord(const char *w);
vector<char> originalWord(const char *w, int length);
vector<char> withDash(vector<char> w);
int countTheMissingWords(vector<char> words);
void show(vector<char> word);
bool check(vector<char> word, char letter);
void replaceWithDash(vector<char> originalWord, vector<char> &dashWord, char letter);
void start(int level);
bool enteredLettersCheck(char letter, vector<char> &enteredWords);

int main()
{
	srand(time(NULL));
	char level;
	int ranNum;
	cout << "Please, choose a level!" << endl;
	cout << endl;
	cout << "1.Easy" << endl << "2.Hard" << endl << endl;
	cout << "Enter 1 for EASY and 2 for HARD " << endl;
	cout << endl;
	cout << "Your choice is:" << endl;
	cin >> level;
	if (level == '1')
	{
		ranNum = rand() % (SHORT_WORDS + 1);
		start(ranNum);
	}
	else if (level == '2')
	{
		ranNum = LONG_WORDS + rand() % (MAXWORD - LONG_WORDS + 1);
		start(ranNum);
	}
	else
	{
		cout << "You have to choose only between 1 and 2!" << endl;
	}
}
int lengthOfWord(const char *w)
{
	int length = 0;
	while (*w != '\0')
	{
		length = length + 1;
		w = w + 1;
	}
	return length;
}
vector<char> originalWord(const char *w, int length)
{
	vector<char> origWord;
	int i = 0;
	while (i < length)

	{
		origWord.push_back(w[i]);
		i++;
	}
	return origWord;
}
vector<char> withDash(vector<char> w)
{
	char firstLett = w[0];
	char lastLett = w[w.size() - 1];
	vector<char> word;
	word.push_back(firstLett);
	for (int i = 1; i < w.size() - 1; i++)
	{

		if (w[i] == firstLett || w[i] == lastLett)
		{
			word.push_back(w[i]);
		}
		else
		{
			word.push_back('_');
		}

	}
	word.push_back(lastLett);
	return word;
}
int countTheMissingWords(vector<char> words)
{
	int countTheMissingLett = 0;
	int i = 0;
	while (i < words.size())
	{
		if (words[i] == '_')
		{
			countTheMissingLett++;
		}
		i++;
	}
	return countTheMissingLett;
}
void show(vector<char> word)
{
	int i = 0;
	while (i < word.size())
	{
		cout << word[i];
		i++;
	}
}
bool check(vector<char> word, char letter)
{
	int i = 0;
	while (i < word.size())
	{
		if (word[i] == letter)
		{
			return true;
		}
		i++;
	}
	return false;
}
void replaceWithDash(vector<char> originalWord, vector<char> &dashWord, char letter)
{
	int i = 0;
	while (i < originalWord.size() - 1)
	{
		if (originalWord[i] == letter)
		{
			dashWord[i] = originalWord[i];
		}
		i++;
	}
}
bool enteredLettersCheck(char letter, vector<char> &enteredWords)
{
	int i = 0;
	while (i < enteredWords.size())
	{
		if (enteredWords[i] == letter)
		{
			cout << "You have already entered this letter or the letter is already in the word." << endl;
			cout << "Please enter another one!" << endl;
			return false;
		}
		i++;
	}
	enteredWords.push_back(letter);
	return true;
}
void start(int level)
{
	vector<char> dashWord;
	vector<char> origWord;
	vector<char> enteredLetters;
	char letter;
	int countTheMissingLett;
	int numOfGuesses;
	bool haveLettInWord = false;
	char *word = words[level];
	int len = lengthOfWord(word);
	if (level <= SHORT_WORDS)
	{
		numOfGuesses = len;
	}
	else
	{
		numOfGuesses = len / 2;
	}
	origWord = originalWord(word, len);
	dashWord = withDash(origWord);
	show(dashWord);
	enteredLetters.push_back(origWord[0]);
	enteredLetters.push_back(origWord[len - 1]);
	cout << setw(25) << "You have " << numOfGuesses << " attempts left" << endl;
	while (numOfGuesses > 0)
	{
		cout << "Enter next letter:" << endl;
		cin >> letter;
		if (isalpha(letter))
		{
			letter = letter | 0x20;
			if ((enteredLettersCheck(letter, enteredLetters)) == true)
			{
				haveLettInWord = check(origWord, letter);
				if (haveLettInWord == true)
				{
					cout << "Success!" << endl;
					replaceWithDash(origWord, dashWord, letter);
					countTheMissingLett = countTheMissingWords(dashWord);
					if (countTheMissingLett == 0)
					{
						cout << endl;
						cout << "Congratulations! You win!" << endl;
						cout << "The word is: ";
						show(origWord);
						cout << endl;
						cout << endl;
						break;
					}
					else
					{
						show(dashWord);
						cout << setw(25) << "You have " << numOfGuesses << " attempts left" << endl;
					}

				}
				else
				{
					cout << "Error! Error!" << endl;
					numOfGuesses--;
					show(dashWord);
					cout << setw(25) << "You have " << numOfGuesses << " attempts left" << endl;
					if (numOfGuesses == 0)
					{
						cout << endl;
						cout << "Game over!" << endl;
						cout << "You lost" << endl;
						cout << endl;
					}
				}
			}
		}
		else
		{
			cout << "You should enter only letters!" << "Try again!";
			cout << endl;
		}
	}
}
