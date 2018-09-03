#include  <iostream>
#include  <cstdlib>
#include <iomanip>
#include <string.h>
#include <vector>

using namespace std;

const int LENGTH_OF_SPECIAL_SIGNS = 5;
const int MAX_LEN_OF_SEN = 100;

char signs[LENGTH_OF_SPECIAL_SIGNS] = { ',', '.', '!', '?' };  // array with the special signs
void remove_signs(char *str, int l);
void replace_tab(char *str, int l);
int find_the_longest_word(const char *s, int l);
void print(const char *str, int max_len, int lenght_of_sen);
void print_dash(int size);
void print_horizontal_line();

int main(){
    cout<<"Write your sentence here:"<<endl;
	char sentence[MAX_LEN_OF_SEN];
	cin.get(sentence, MAX_LEN_OF_SEN);
	int length = strlen(sentence);

	remove_signs(sentence, length);
	replace_tab(sentence, length);
	int max_length_of_word = find_the_longest_word(sentence, length);
	print(sentence, max_length_of_word, length);
}
void remove_signs(char *str, int l){
	int ind = 0;
	for (int i = 0; i < LENGTH_OF_SPECIAL_SIGNS; i++)
	{
		while (ind < l)
		{// if there is a special sign
			if (str[ind] == signs[i])
			{  // replace the special sign with space
				str[ind] = ' ';
			}
			ind += 1;
		}
		ind = 0;
	}
}
void replace_tab(char *str, int l)
{
    int i=0;
    while(i<l)
	{
	    // if there is a tab
		if (str[i] == '\t')
		{
		    // replace the tab with space
			str[i] = ' ';
		}
		i++;
	}
}
int find_the_longest_word(const char *s, int l)
{
	int max_length = 0;
	int length_of_word = 0;
	int i=0;
	while(i<l)
	{
		if (s[i] != ' ')
		{
			length_of_word++;
		}
		else
		{
			if (length_of_word > max_length)
			{
				max_length = length_of_word;
			}
			length_of_word = 0;
		}
		i++;
	}
	if (length_of_word > max_length)
	{
		max_length = l;
	}
	return max_length;
}
void print(const char *str, int max_len, int lenght_of_sen)
{
	print_dash(max_len + 2);
	cout << endl;
	print_horizontal_line();
	int length = 0;
	bool is_printed = false;
	for (int i = 0; i < lenght_of_sen; i++)
	{
		if (str[i] != ' ')
		{
			cout << str[i];
			length++;
			if (i == lenght_of_sen - 1)
			{
			    // print the horizontal lines on the right positions
				cout << setw(max_len - length + 1);
				print_horizontal_line();
			}
			is_printed = false;
		}
		else{

			if (i == lenght_of_sen - 1)
			{
				cout << setw(max_len - length + 1);
				print_horizontal_line();
			}
			else{
				if (is_printed == false)
				{  // print lines
					cout << setw(max_len - length + 1);
					print_horizontal_line();
					cout << endl;
					print_horizontal_line();
					length = 0;
					is_printed= true;
				}
			}
		}
	}
	cout << endl;
	// print dashes which number is the world length +2
	print_dash(max_len + 2);
	cout << endl;
}
// print the horizontal lines before and after the word on each line
void print_horizontal_line()
{
	cout << '|';
}

void print_dash(int size)
{
     int i=0;

 while(i<size)
	{
	    // print dashes in the beginning and in the end
		cout << '-';
		i++;
	}
}

