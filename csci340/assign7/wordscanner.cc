/*
Milo Zak
Z1917365
CSCI340-3

I certify that this is my own work and where appropriate an extension
of the starter code provided for the assignment.
*/

#include <bits/stdc++.h>

using namespace std;

//function prototypes
void get_words(map<string, int>&);
void print_words(const map<string, int>&);
void clean_entry(const string&, string&);

int total_word = 0;

int main()
{
    map <string, int> word;

    get_words(word);

    print_words(word);

    return 0;
}

/*
Func: void get_words(map<string, int>&)

Arg: it gets a word from the input stream and removes its punctuation marks

Ret: none
*/
void get_words(map<string, int>& m)
{
    string s;
    string clean_s;

    while(cin >> s)
    {
        clean_entry(s, clean_s); //clean word
        if(clean_s.length() > 0)
        {
            m[clean_s]++; //store
        }
        ++total_word;
    }
}

/*
Func: void print_words(const map<string, int>&)

Arg:  it prints the final list of words and their frequencies,
      it also prints the number of nonempty words and the number
      of distinct words in the input stream

Ret: none
*/
void print_words(const map<string, int>& m)
{
    int NO_ITEMS = 4;
    int ITEM_WORD_WIDTH = 14;
    int ITEM_COUNT_WIDTH = 3;
    int word_per_line = 0;

    for(auto iterator = m.begin(); iterator != m.end(); ++iterator)
    {
        cout << setw(ITEM_WORD_WIDTH) << left << iterator -> first;
        cout << ":";
        cout << setw(ITEM_COUNT_WIDTH) << left << iterator -> second;

        ++word_per_line;

        if(word_per_line == NO_ITEMS)
        {
            cout << "\n";
            word_per_line = 0;
        }
    }

    cout << endl << "number of words in input stream   :" << total_word;
    cout << endl << "number of words in output stream  :" << m.size();
    cout << endl;
}

/*
Func: void clean_entry(const string&, string&)

Arg: it cleans a word from its punctuation marks, the first
     argument is the original word in the input stream and
     the second argument contains the same word after cleaning

Ret: none
*/
void clean_entry(const string& s, string& clean_s)
{
    auto alpha = find_if(s.begin(), s.end(), [] (char character) //iterate 1
        { return isalnum(static_cast<unsigned char>(character)); });

    auto non_alpha = find_if(alpha, s.end(), [] (char non_character) //iterate 2
        { return !(isalnum(static_cast<unsigned char>(non_character))); });

    clean_s.assign(alpha, non_alpha);

    for_each(clean_s.begin(), clean_s.end(), [] (char & lowercase)
        { lowercase = tolower(lowercase); });
}
