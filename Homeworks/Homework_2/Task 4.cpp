#include  <iostream>
#include  <cstdlib>
#include <vector>
#include <iomanip>
#include <string.h>

using namespace std;

const int MAX_SIZE = 50;

char *subSeq(char*, int, int);
void findThePalindrome(char *input);
void save(char*, int, vector<char> &word);
bool isEqual(vector<char> &ind, int beginInd, int beginInd2, int lastInd);
void check(vector<char> &ind, vector<char> &words, vector<char> &copyInd);
void print(vector<char> &word, int beginInd, int length);

int main()
{
	cout << "Enter your input here:" << endl;
	char str[MAX_SIZE];
	cin.get(str, MAX_SIZE);
	findThePalindrome(str);
}
char *subSeq(char* mainSen, int start, int finish)
{
	char *newStr = new char[finish - start + 1];
	int i = 0;
	while (i < finish - start)
	{
		newStr[i] = mainSen[i + start];
		i++;
	}
	newStr[finish - start] = '\0';
	return newStr;
}
void findThePalindrome(char *input) {
	vector<char> palindrome;
	vector<char> index;
	vector<char> copyIndex;
	if (!input)
	{
		cout << "Error! Error!" << endl;
		return;
	}
	if (strlen(input) <= 2)
	{
		cout << "You should enter more than two symbols!" << endl;
		return;
	}

	int lengthOfSentence = strlen(input);
	if (lengthOfSentence % 2 == 1)
	{
		for (int i = 1; i < lengthOfSentence - 1; i++)
		{
			for (int j = i - 1, m = i + 1; j >= 0 && m < lengthOfSentence; j--, m++)
			{
				if (input[j] == input[m])
				{
					char *subS = subSeq(input, j, m + 1);
					int length = strlen(subS);
					save(subS, length, palindrome);
					index.push_back(length);
					delete subS;
				}

				else { break; }
			}
		}
		copyIndex = index;
		check(index, palindrome, copyIndex);
	}
	else
	{
		
		for (int i = 1; i < lengthOfSentence - 1; i++)

		{
			for (int j = i, m = i + 1; j >= 0 && m < lengthOfSentence; j--, m++)
			{
				if (input[j] == input[m])
				{
					char *subS = subSeq(input, j, m + 1);
					int len = strlen(subS);
					save(subS, len, palindrome);
					index.push_back(len);
					delete subS;
				}
				else break;
			}
		}
		copyIndex = index;
		check(index, palindrome, copyIndex);
	}
}
void save(char *subS, int length, vector<char> &word)
{
	int i = 0;
	while (i < length)
	{
		word.push_back(subS[i]);
		i++;
	}
	word.push_back(' ');
}
void check(vector<char> &ind, vector<char> &words, vector<char> &copyInd) {
	int counter = 1;
	int sum1 = 0;//variable for the next palindromes
	int sum2 = 0;//variable for the current palindrome
	int sum = 0;//variable where the the length of the palindromes will be saved
	int length;

	for (int i = 0; i < ind.size(); i++)
	{
		sum += ind[i];
		length = ind[i];
		sum2 += sum + i;
		sum1 += sum;
		if (copyInd[i] != 0)
		{
			for (int j = i + 1; j <= ind.size() - 1; j++)
			{
				sum1 += ind[j];
				if (copyInd[j] != 0)
				{
					if (ind[i] == ind[j])
					{
						if (isEqual(words, sum2 - 1, j + sum1 - 1, length) == true)
						{
							counter += 1;
							copyInd[j] = 0;
						}
					}
				}
			}
			if (counter == 1)
			{
				print(words, sum2 - 1, length);
				cout << " -> " << counter << endl;;
			}
			else {
				print(words, sum2 - 1, length);
				cout << " -> " << counter << endl;;
			}
			counter = 1;
			sum1 = 0;
			sum2 = 0;
		}
	}
}
void print(vector<char> &word, int beginInd, int len) {
	int counter = 0;

	while (counter < len && beginInd < word.size())
	{
		cout << word[beginInd];
		beginInd--;
		counter += 1;
	}
}
bool isEqual(vector<char> &ind, int beginInd, int beginInd2, int lastInd) {
	int counter = 0;
	do
	{
		if (ind[beginInd] != ind[beginInd2])
			return false;
		beginInd--;
		beginInd2--;
		counter = counter + 1;
	} while (counter < lastInd);

	return true;
}

