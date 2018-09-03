#include  <iostream>
#include  <cstdlib>
#include <vector>
#include <iomanip>
#include <string.h>

using namespace std;

const int MAX_SIZE = 50;// for the length of the input

char *subSeq(char*, int, int);
void find_the_palindrome(char *input);
void save(char*, int, vector<char> &word);
bool is_equal(vector<char> &ind, int begin_ind, int begin_ind2, int last_ind);
void check(vector<char> &ind, vector<char> &words, vector<char> &copy_ind);
void print(vector<char> &word, int begin_ind, int length);

int main()
{
    cout<<"Enter your input here:"<<endl;
	char str[MAX_SIZE];
	cin.get(str, MAX_SIZE);
	find_the_palindrome(str);
}
char *subSeq(char* mainSen, int start, int finish)
{
   char *newStr = new char[finish - start + 1];
  int i=0;
  while(i<finish-start)
  {
		newStr[i] = mainSen[i + start];
		i++;
  }
	newStr[finish- start] = '\0';
	return newStr;
}
void find_the_palindrome(char *input){
	vector<char> palindrome;
	vector<char> index;
	vector<char> copy_index;
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

	int length_of_sentence = strlen(input);
	if (length_of_sentence % 2 == 1)
	{
	   //odd palindromes
		for (int i = 1; i < length_of_sentence - 1; i++)
		{
			for (int j = i - 1, m = i + 1; j >= 0 && m < length_of_sentence; j--, m++)
			{
				if (input[j] == input[m])
				{
					char *subS = subSeq(input, j, m + 1);
					int length = strlen(subS);
					// save palindromes in vector and save their length
					save(subS, length, palindrome);
					index.push_back(length);
					delete subS;
				}

				else{ break; }
			}
		}
		copy_index = index;
		check(index, palindrome, copy_index);
	}
	else
	{
        //even palindromes
		for (int i = 1; i < length_of_sentence - 1; i++)

		{
			for (int j = i, m = i + 1; j >= 0 && m < length_of_sentence; j--, m++)
			{
				if (input[j] == input[m])
				{
					char *subS = subSeq(input, j, m + 1);
					int len = strlen(subS);
					save(subS, len, palindrome);//save palindromes in vector
					index.push_back(len);//save the length
					delete subS;
				}
				else break;
			}
		}
		copy_index= index;
		check(index, palindrome, copy_index);
	}
}
void save(char *subS, int length, vector<char> &word)
{
   int i=0;
   while(i<length)
   {
		word.push_back(subS[i]);
		i++;
   }
	word.push_back(' ');
}
void check(vector<char> &ind, vector<char> &words, vector<char> &copy_ind){
	int counter = 1;
	int sum1 = 0;//variable for the next palindromes
	int sum2 = 0;//variable for the current palindrome
	int length;
	int sum = 0;//variable where the the length of the palindromes will be saved

	for (int i = 0; i < ind.size(); i++)
	{
		sum += ind[i];
		length = ind[i];
		sum2 += sum + i;
		sum1 += sum;
		//if the palindrome is not print then compare it
		//with the other palindromes and print current palindrome how many times is found
		if (copy_ind[i] != 0)
		{
			for (int j = i + 1; j <= ind.size() - 1; j++)
			{
				sum1 += ind[j];
				//if the palindrome is print then the length of the copy_ind becomes 0
				if (copy_ind[j] != 0)
				{
					if (ind[i] == ind[j])
					{
						if (is_equal(words, sum2 - 1, j + sum1 - 1, length) == true)
						{
							counter += 1;
							copy_ind[j] = 0;
						}
					}
				}
			}
			if (counter == 1)
			{
				print(words, sum2 - 1, length);
				cout << " -> " << counter << endl;;
			}
			else{
				print(words, sum2- 1, length);
				cout << " -> " << counter  << endl;;
			}
			counter = 1;
			sum1 = 0;
			sum2 = 0;
		}
	}
}
void print(vector<char> &word, int begin_ind, int len){
	int counter = 0;

while (counter < len && begin_ind < word.size())
	{
		cout << word[begin_ind];
		begin_ind = begin_ind - 1;
		counter += 1;
	}
}
bool is_equal(vector<char> &ind, int begin_ind, int begin_ind2, int last_ind){
	int counter = 0;
	do
	{
		if (ind[begin_ind] != ind[begin_ind2])
        return false;
		begin_ind = begin_ind - 1;
		begin_ind2 = begin_ind2 - 1;
		counter = counter + 1;
	}
	while (counter < last_ind);

	return true;
}
