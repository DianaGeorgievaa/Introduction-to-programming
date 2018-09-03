#include  <iostream>
#include  <iomanip>
#include  <cstdlib>
#include  <vector>
#include  <ctype.h>
#include  <random>
#include  <ctime>
#include <cctype>
#include <algorithm>

using  namespace  std;

const int SHORT_WORDS = 14; //words for level 1
const int LONG_WORDS = 15; // words for level 2
const int MAXWORD = 29;

// Array with the words that will be used in the game
char *words[]={"student", "smile", "friend", "family", "teacher", "world", "garden", "house", "paper", "girl", "game", "brother", "morning", "night", "school",
 "refrigerator", "unstoppable", "prosperity", "anonymous", "vocabulary", "happiness", "software" , "dictionary", "definition", "operation", "chronological","pronunciation", "combination", "unforgettable", "meaningless"};

int length_of_word(const char *w);
vector<char> original_word(const char *w, int length);
vector<char> with_dash(vector<char> w);
int count_the_missing_words(vector<char> words);
void show(vector<char> word);
bool check(vector<char> word, char letter);
void replace_with_dash(vector<char> original_word,vector<char> &dash_word, char letter);
void start(int level);
bool entered_letters_check(char letter, vector<char> &entered_words);

int main()
{
    srand(time(NULL));
    char level;
    int ranNum;
    // Gives information about the levels
    cout<<"Please, choose a level!"<<endl;
    cout<<endl;
    cout<<"1.Easy"<<endl<<"2.Hard"<<endl<<endl;
    cout<<"Enter 1 for EASY and 2 for HARD "<<endl;
    cout<<endl;
    cout<<"Your choice is:"<<endl;
    cin>>level;
    // Easy level
    if (level == '1')
    {   // Choose random word
        ranNum = rand()% (SHORT_WORDS + 1);
        start(ranNum);
    }
    // Hard level
    else if (level == '2')
    {
         // Choose random hard word
        ranNum = LONG_WORDS + rand()% (MAXWORD - LONG_WORDS + 1);
        start(ranNum);
    }
    else
    {
        cout<<"You have to choose only between 1 and 2!"<<endl;
    }
}
//Finds the length of the word
int length_of_word(const char *w)
{
    int length = 0;
    while(*w != '\0')
    {
        length = length + 1;
        w = w + 1;
    }
    return length;
}
// for the original word (with letters)
vector<char> original_word(const char *w, int length)
{
    vector<char> orig_word;
    int i=0;
    while(i<length)

    {
        orig_word.push_back(w[i]);
        i++;
    }
    return orig_word;
}
//for the word written with dashes
vector<char> with_dash(vector<char> w)
{
    char first_lett = w[0];
    char last_lett = w[w.size() - 1];
     vector<char> word;
     word.push_back(first_lett);
    for (int i=1; i < w.size() - 1; i++)
    {
         // shows the first and the last letter of the word
         if (w[i] == first_lett || w[i ]== last_lett)
         {
             word.push_back(w[i]);
         }
         else
         // to show dashes on the other places
         {
             word.push_back('_');
         }

    }
     word.push_back(last_lett);
     return word;
}
int count_the_missing_words(vector<char> words)
{
    int count_the_missing_lett = 0;
    int i=0;
    while(i<words.size())
    {
        if (words[i] == '_')
        {   // the missing letters are the number of the dashes in the word
            count_the_missing_lett = count_the_missing_lett + 1;
        }
        i++;
    }
    return count_the_missing_lett;
}
void show(vector<char> word)
{
    int i=0;
    while(i<word.size())
    {
        cout<<word[i];
        i++;
    }
}
bool check(vector<char> word, char letter)
{
    int i = 0;
    while(i < word.size())
    {
        if (word[i] == letter)
        {
            return true;
        }
        i++;
    }
    return false;
}
void replace_with_dash(vector<char> original_word,vector<char> &dash_word, char letter)
{
    int i = 0;
    while(i < original_word.size()-1)
    {
        if (original_word[i] == letter)
        {
            dash_word[i] = original_word[i];
        }
        i++;
    }
}

// check if the letter is already entered
bool entered_letters_check(char letter, vector<char> &entered_words)
{
    int i = 0;
    while(i < entered_words.size())
    {
        if(entered_words[i] == letter)
        {   // if the letter is already entered show the massage
            cout<<"You have already entered this letter or the letter is already in the word."<<endl;
            cout<<"Please enter another one!"<<endl;
            return false;
        }
        i++;
    }
    entered_words.push_back(letter);
    return true;
}
void start(int level)
{
    vector<char> dash_word;
    vector<char> orig_word;
    vector<char> entered_letters;
    char letter;
    int count_the_missing_lett;
    int num_of_guesses;
    bool have_lett_in_word = false;
    // get word from the array
    char *word = words[level];
    int len = length_of_word(word);
    if(level <= SHORT_WORDS)
    {
        // for level 1
        num_of_guesses = len;
    }
    else
    {
        //for level 2
        num_of_guesses= len / 2;
    }
    orig_word = original_word(word,len);
    dash_word = with_dash(orig_word);
    show(dash_word);
    entered_letters.push_back(orig_word[0]); // add the first shown letter
    entered_letters.push_back(orig_word[len - 1]);// add the last shown letter
    cout<<setw(25)<<"You have "<< num_of_guesses<< " attempts left"<<endl;
    while(num_of_guesses > 0)
    {
        cout<<"Enter next letter:"<<endl;
        cin>>letter;
        if (isalpha(letter))
        {
            letter = letter | 0x20;
            // check if the entered letter is in the word
            if((entered_letters_check(letter, entered_letters)) == true)
            {
                have_lett_in_word = check(orig_word, letter);
                //if the entered letter is in the word
                if(have_lett_in_word == true)
                {   // show the massage
                    cout<<"Success!"<<endl;
                    replace_with_dash(orig_word,dash_word, letter);
                    count_the_missing_lett = count_the_missing_words(dash_word);
                    // checks if there are any missing letters
                    if(count_the_missing_lett == 0)
                    {  // if there are no missing letters show the massage
                        cout<<endl;
                        cout<<"Congratulations! You win!"<<endl;
                        cout<<"The word is: ";
                        show(orig_word);
                        cout<<endl;
                         cout<<endl;
                        // end of the game
                        break;
                    }
                    // case if there are some missing letters
                    else
                    {  // show the word with dashes
                    show(dash_word);
                  // show the number of attempts left
                    cout<<setw(25)<<"You have "<<num_of_guesses<<" attempts left"<<endl;
                    }

                }
                else
                {
                     // massage when the guess is wrong
                    cout<<"Error! Error!"<<endl;
                    // number of attempts changes
                    num_of_guesses = num_of_guesses- 1;
                    show(dash_word);
                    //show number of attempts left
                    cout<<setw(25)<<"You have "<<num_of_guesses<<" attempts left"<<endl;
                    // checks if there are any attempts left
                    if(num_of_guesses == 0)
                    {
                        // when there are no more attempts end of the game
                        cout<<endl;
                        cout<<"Game over!"<<endl;
                        cout<<"You lost"<<endl;
                        cout<<endl;
                    }
                }
            }
        }
        // if the player enter something else
        else
        {
            cout<<"You should enter only letters!"<<"Try again!";
            cout<<endl;
        }
    }
}
