#include  <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include  <cstdlib>


using  namespace  std;

const long long MAX_SIZE = 4294967296;
void digitsOfNumber(long long num, vector<int> &digits);
void countSave(vector<int> digits);
void printRepeated(vector<int> dig, int numOfRepeatedDig);

int main() {
	cout << "Enter a digit:" << endl;
	long long number;
	cin >> number;

	if (number >= -MAX_SIZE && number <= MAX_SIZE)
	{
		number = abs(number);
		vector<int> digits;
		digitsOfNumber(number, digits);
		sort(digits.begin(), digits.end());
		countSave(digits);
	}
	else
	{
		cout << "-1" << endl;
	}
}
void digitsOfNumber(long long num, vector<int> &digits)
{
	int digit;
	while (num > 0)
	{
		digit = num % 10;
		digits.push_back(digit);
		num = num / 10;
	}
}
void countSave(vector<int> digits)
{
	int maxRepeatedDigit = 0;
	int counter = 1;
	bool add = false;
	vector<int> saveReapeatedDigits;

	for (int i = 0; i < digits.size() - 1; i++)
	{
		if (digits[i] == digits[i + 1])
		{
			counter++;
		}

		{
			if (counter > maxRepeatedDigit)
			{
				maxRepeatedDigit = counter;
			}
			counter = 1;
		}
	}
	if (counter > maxRepeatedDigit)
	{
		maxRepeatedDigit = counter;
	}
	printRepeated(digits, maxRepeatedDigit);
}
void printRepeated(vector<int> dig, int numOfRepeatedDig)
{
	int counter = 1;
	int i = 0;
	while (i < dig.size() - 1)
	{
		if (dig[i] == dig[i + 1])
		{
			counter = counter + 1;
		}
		if (counter == numOfRepeatedDig)
		{
			cout << dig[i] << "->" << numOfRepeatedDig << endl;
			counter = 1;
		}
		i++;
	}
}
