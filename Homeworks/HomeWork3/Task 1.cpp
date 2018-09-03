#include  <iostream>
#include  <cstdlib>

using  namespace  std;

int check_brackets(string s, int counter);
int parent_close;
int parent_open;

int main()
{
  string input;
  // variable that will count the number of the brackets
  int count_brackets=0;
  cout<<"Enter your input here:"<<endl;
  getline(cin,input);
  if(check_brackets(input, count_brackets)== 0)
  {
    cout<<"correct"<<endl;
  }
  else
  {
    cout<<"incorrect"<<endl;
  }
}
int check_brackets(string s, int counter)
{   // if the number of the open and close parent is <0
    if(parent_close < 0 & parent_open < 0)
    {
        return counter;
    }
    // search for "("
    parent_open=s.find('(');
    // if there is not "("
    if (parent_open!=-1)
    {   // if there is "("
        counter++;
        s.replace(parent_open,1," ");
    }
    // search for ")"
    parent_close=s.find(')');
    // check if it starts with ")"
    if (parent_close < parent_open)
    {
         return -1;
    }

    if(parent_close!=-1)
    {   //if there is ")"
        counter--;
        s.replace(parent_close,1," ");
    }

    return check_brackets(s, counter);
}
