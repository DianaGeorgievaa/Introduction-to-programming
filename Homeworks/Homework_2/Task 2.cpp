#include  <iostream>
#include  <cstdlib>
#include <iomanip>
#include <string.h>
#include <vector>

using namespace std;

const int LENGTH_OF_SPECIAL_SIGNS = 5;
const int MAX_LEN_OF_SEN = 100;

char signs[LENGTH_OF_SPECIAL_SIGNS] = { ',', '.', '!', '?' };
void removeSigns(char *str, int l);
void replaceTab(char *str, int l);
int findTheLongestWord(const char *s, int l);
void print(const char *str, int maxLen, int lenghtOfSen);
void printDash(int size);
void printHorizontalLine();

int main() {
	cout << "Write your sentence here:" << endl;
	char sentence[MAX_LEN_OF_SEN];
	cin.get(sentence, MAX_LEN_OF_SEN);
	int length = strlen(sentence);

	removeSigns(sentence, length);
	replaceTab(sentence, length);
	int maxLengthOfWord = findTheLongestWord(sentence, length);
	print(sentence, maxLengthOfWord, length);
}
void removeSigns(char *str, int l) {
	int ind = 0;
	for (int i = 0; i < LENGTH_OF_SPECIAL_SIGNS; i++)
	{
		while (ind < l)
		{
			if (str[ind] == signs[i])
			{
				str[ind] = ' ';
			}
			ind += 1;
		}
		ind = 0;
	}
}
void replaceTab(char *str, int l)
{
	int i = 0;
	while (i < l)
	{
		if (str[i] == '\t')
		{
			str[i] = ' ';
		}
		i++;
	}
}
int findTheLongestWord(const char *s, int l)
{
	int maxLength = 0;
	int lengthOfWord = 0;
	int i = 0;
	while (i < l)
	{
		if (s[i] != ' ')
		{
			lengthOfWord++;
		}
		else
		{
			if (lengthOfWord > maxLength)
			{
				maxLength = lengthOfWord;
			}
			lengthOfWord = 0;
		}
		i++;
	}
	if (lengthOfWord > maxLength)
	{
		maxLength = l;
	}
	return maxLength;
}
void print(const char *str, int maxLen, int lenghtOfSen)
{
	printDash(maxLen + 2);
	cout << endl;
	printHorizontalLine();
	int length = 0;
	bool isPrinted = false;
	for (int i = 0; i < lenghtOfSen; i++)
	{
		if (str[i] != ' ')
		{
			cout << str[i];
			length++;
			if (i == lenghtOfSen - 1)
			{
				cout << setw(maxLen - length + 1);
				printHorizontalLine();
			}
			isPrinted = false;
		}
		else {

			if (i == lenghtOfSen - 1)
			{
				cout << setw(maxLen - length + 1);
				printHorizontalLine();
			}
			else {
				if (isPrinted == false)
				{
					cout << setw(maxLen - length + 1);
					printHorizontalLine();
					cout << endl;
					printHorizontalLine();
					length = 0;
					isPrinted = true;
				}
			}
		}
	}
	cout << endl;
	printDash(maxLen + 2);
	cout << endl;
}
void printHorizontalLine()
{
	cout << '|';
}

void printDash(int size)
{
	int i = 0;

	while (i < size)
	{
		cout << '-';
		i++;
	}
}

