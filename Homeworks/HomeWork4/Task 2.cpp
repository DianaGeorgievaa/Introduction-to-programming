#include <iostream>
#include <string>

using namespace std;

int countLetters = 0;

const string THOUSAND = "thousand";
const string HUNDRED = "hundred";
const string ONE_DIGIT[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
const string TWO_DIGITS[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
const string TWO_DIGITS_SPECIAL[] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

void numbersWithTwoDigits(int number);
int numberOfDigits(int number);

int main()
{
	int number;
	cout << "Enter number: ";
	cin >> number;

	if (number >= 1 && number <= 10000) // if the number is valid
	{
		int digits = numberOfDigits(number);
		switch (digits)
		{
		case 1: // if the entered number is with one digit
		{

			countLetters = countLetters + ONE_DIGIT[number - 1].length();//number-1 because our array begins with 1 not 0
			break;
		}
		case 2:
		{
			numbersWithTwoDigits(number);
			break;
		}
		case 3:
		{
			countLetters = countLetters + ONE_DIGIT[(number / 100) - 1].length() + HUNDRED.length();//+ length of the hundreds
			int newNumber = number % 100;
			if (newNumber != 0)
			{
				int len = numberOfDigits(newNumber);
				if (len == 2)
				{
					numbersWithTwoDigits(newNumber);
				}
				else
				{
					countLetters = countLetters + ONE_DIGIT[newNumber - 1].length();
				}
			}
			break;
		}
		case 4:
		{
			countLetters = countLetters + ONE_DIGIT[(number / 1000) - 1].length() + THOUSAND.length();//+length of the thousands
			int newNumber = number % 1000;
			int len = numberOfDigits(newNumber);
			if (len == 3 && newNumber != 0)
			{
				countLetters = countLetters + ONE_DIGIT[(newNumber / 100) - 1].length() + HUNDRED.length();//+ length of hundreds
				numbersWithTwoDigits(newNumber % 100);// number with two digits
			}
			else if (len == 2 && newNumber != 0)
			{
				numbersWithTwoDigits(newNumber); // number with two digits
			}
			else if (len == 1 && newNumber != 0)
			{
				countLetters = countLetters + ONE_DIGIT[newNumber - 1].length();
			}
			break;
		}
		case 5: // only for 10 000
		{
			int newNumber = number / 1000;
			countLetters = countLetters + TWO_DIGITS[newNumber - 10].length() + THOUSAND.length();
			break;
		}
		}
		cout << countLetters << endl;
	}
	else
	{
		cout << "The number is invalid!" << endl;
	}

	return 0;
}

int numberOfDigits(int number)// finds the number of the digits
{
	int counter = 0;
	while (number != 0)
	{
		number = number / 10;
		counter++;
	}
	return counter;
}
void numbersWithTwoDigits(int number)
{
	if (number >= 10 && number <= 19)
	{
		countLetters = countLetters + TWO_DIGITS[number - 10].length();//number- 10 because the array begins with 10 not 0
	}
	else if (number % 10 == 0) // checks if the number ends with 0
	{
		countLetters = countLetters + TWO_DIGITS_SPECIAL[number / 10 - 2].length();// number/10-2 we get the index in the array
	}
	else
	{
		int firstDigit = number / 10;
		int secondDigit = number % 10;
		countLetters = countLetters + TWO_DIGITS_SPECIAL[firstDigit - 2].length() + ONE_DIGIT[secondDigit - 1].length();
	}
}
