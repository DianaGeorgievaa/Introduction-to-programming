#include  <iostream>
#include  <cstdlib>

using  namespace  std;

int checkBrackets(string s, int counter);
int parentClose;
int parentOpen;
int parentOpen;

int main()
{
	string input;
	int countBrackets = 0;
	cout << "Enter your input here:" << endl;
	getline(cin, input);
	if (check_brackets(input, countBrackets) == 0)
	{
		cout << "correct" << endl;
	}
	else
	{
		cout << "incorrect" << endl;
	}
}
int check_brackets(string s, int counter)
{  
	if (parentClose < 0 & parentOpen < 0)
	{
		return counter;
	}
	parentOpen = s.find('(');
	if (parentOpen != -1)
	{   
		counter++;
		s.replace(parentOpen, 1, " ");
	}
	parentClose = s.find(')');
	if (parentClose < parentOpen)
	{
		return -1;
	}

	if (parentClose != -1)
	{   
		counter--;
		s.replace(parentClose, 1, " ");
	}

	return checkBrackets(s, counter);
}
