#include <iostream>
#include <string>

using namespace std;

int countDays = 0;

bool IsDataValid(string data);
int daysInMonth(int month, int year);
int CalculateTheWeeks(int day, int month, int year);

int main()
{
	string data;
	cout << "Enter data in format DD.MM.YYYY: ";
	cin >> data;
	if (IsDataValid(data) == true)
	{
		// because of the format
		string d = data.substr(0, 2);// gets only the first two symbols - for the day
		int day = stoi(d);
		string m = data.substr(3, 2);
		int month = stoi(m);
		string y = data.substr(6, 4);
		int year = stoi(y);
		if ((day >= 1 && day <= 31) && (month >= 1 && month <= 12) && (year>=2000))// checks if the data is correct
		{
			if (month == 4 || month == 6 || month == 9 || month == 11)
			{
				if (day > 30)
				{
					cout << "Invalid number of days for this month!" << endl;
					return 0;
				}
			}
		cout << CalculateTheWeeks(day, month, year) << endl;
		}
		else
		{
			cout << "Invalid data!" << endl;
		}
	}
	else
	{
		cout << "There shouldn't be other symbols in the data! " << endl;
	}

	return 0;
}
int daysInMonth(int month, int year)
{
	int days = 0;
	switch (month)
	{
	case(1): days = 31; break;
	case(2):
	{
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		{
			days = 29;
		}
		else
		{
			days = 28;
		}
		break;
	}
	case(3): days = 31; break;
	case(4): days = 30; break;
	case(5): days = 31; break;
	case(6): days = 30; break;
	case(7): days = 31; break;
	case(8): days = 31; break;
	case(9): days = 30; break;
	case(10): days = 31; break;
	case(11): days = 30; break;
	case(12): days = 31; break;
	}
	return days;
}
bool IsDataValid(string data)
{
	bool correctData = false;
	for (int i = 0; i < data.length(); i++)
	{
		// checks if the symbols in the data or only numbers and '.'
		if ((data[i] >= 48 && data[i] <= 57) || (data[i] == '.'))
		{
			correctData = true;
		}
		else
		{
			correctData = false;
			break;
		}
	}
	if (correctData == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int CalculateTheWeeks(int day, int month, int year)
{
	for (int i = year - 1; i >= 2000; i--)
	{
		if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
	    {

			countDays = countDays + 366;
		}
		else
		{
			countDays = countDays + 365;
		}
	}
	for (int i = 1; i <= month - 1; i++)
	{
		countDays = countDays + daysInMonth(i, year);
	}
	countDays = countDays + day;

	int numberOfWeeks = countDays / 7;
	return numberOfWeeks;
}
