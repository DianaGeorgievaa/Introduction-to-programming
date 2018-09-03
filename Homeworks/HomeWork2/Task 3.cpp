#include  <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include  <cstdlib>


using  namespace  std;

const long long MAX_SIZE = 4294967296; // for the largest possible number in the program
void digits_of_number(long long num, vector<int> &digits);
void count_save(vector<int> digits);
void print_repeated(vector<int> dig, int num_of_repeated_dig);

int main(){
    cout<<"Enter a digit:"<<endl;
    long long number;
    cin>>number;
    //checks if the number is right
    if(number >= -MAX_SIZE && number <= MAX_SIZE)
    {   // if the number is not positive
        number = abs(number);
        vector<int> digits;
        digits_of_number(number,digits);
        sort(digits.begin(),digits.end());
        count_save(digits);
    }
    // if the number is bigger
     else
    {
        cout<<"-1"<<endl;
    }
}
//finds the number of the digits
void digits_of_number(long long num, vector<int> &digits)
{
    int digit;
    while(num > 0)
    {
        digit = num % 10;
        digits.push_back(digit);
        num = num / 10;
    }
}
void count_save(vector<int> digits)
{
    int max_repeat_digit = 0;
    int counter = 1;
    bool add = false;
    vector<int> save_reapeat_digits;

    // count repeat digits

    for(int i = 0; i < digits.size() - 1; i++)
    {
        if(digits[i] == digits[i + 1])
        {
            counter = counter + 1;
        }
        else
        {
            if(counter > max_repeat_digit)
            {
                max_repeat_digit = counter;
            }
             counter = 1;
        }
    }
    if(counter > max_repeat_digit)
    {
        max_repeat_digit = counter;
    }
    print_repeated(digits, max_repeat_digit);
}
void print_repeated(vector<int> dig, int num_of_repeated_dig)
{
    int counter = 1;
    int i = 0;
    while(i < dig.size() - 1)
    {
        // checks if first and the next digits are the same
        if (dig[i] == dig[i + 1])
        {
          counter = counter + 1;
        }
        if(counter == num_of_repeated_dig)
        {   // print the repeated digit and the number of the repetitions
            cout<< dig[i] << "->" << num_of_repeated_dig <<endl;
            counter = 1;
        }
        i++;
    }
}
