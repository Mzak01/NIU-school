/*
    Milo Zak
	Z1917365
	CSCI340-3

	I certify that this is my own work and where appropriate an extension
	of the starter code provided for the assignment.
*/

#include "htable.h"

#define N1 10  // num of decimal digits
#define N2 26  // num of upper-case letters

// Hash function, you may NOT modify this function
int HT::hash(const string &s) {
  int n = (N2 * N1) * (s[0] - 'A') + N1 * (s[1] - 'A') + (s[2] - '0');

  return n % hsize;
}

//predicate for insert find_if
struct compare
{
    string what;
    compare(const string &x) : what(x){}
    bool operator()(const Entry &e)
    {
        return what == e.key;
    }
};

/*
Func: HT::HT(const unsigned &hs)

Arg: The hash table, which is a vector of list containers,
     can be created dynamically for a given fixed size hs
     by its constructor

Ret: noen
*/
HT::HT(const unsigned &hs)
{
    hsize = hs;
    hTable.resize(hs);
}

/*
Func: HT::~HT()

Arg: the destructor of the hash table first frees the memory
     for all list containers and then frees the memory for
     the vector containers for the tables

Ret: none
*/
HT::~HT()
{
    hTable.clear();
    pTable.clear();
}

/*
Func: void HT::insert(const Entry &e)

Arg: This public function inserts the record of the item
     e:(key, desc, num) in the hash table.

Ret: none
*/
void HT::insert(const Entry &e)
{
    int record = hash(e.key);
    list<Entry> &l_check = hTable[record];

    if(find_if(l_check.begin(), l_check.end(), compare(e.key)) == l_check.cend())
    {
        l_check.push_front(e);
        pTable.push_back(&l_check.front());
        cout << " entry =  " << left << setw(4) << record << endl;
    }
    else
    {
        cout << " not inserted - duplicate key!!!\n";
        return;
    }
}

/*
Func: void HT::search(const string &s)

Arg: This public function searches the hash table for a record
     with key.

Ret: none
*/
void HT::search(const string &s)
{
    int record =  hash(s);
    list<Entry> &l_check = hTable[record];

    auto it = find_if(l_check.begin(), l_check.end(), [s](Entry e) {return s == e.key; });
    if(it != l_check.cend())
    {
        cout << " ==> number: " << right << setw(4) << it->num << " - item:";
        cout << left << setw(24) << it->desc << endl;
    }
    else
    {
        cout << " not in table!" << endl;
    }
}

/*
Func: void HT::hTable_print()

Arg: This public function prints the subscript and the content
     of all (and only) the active records in the hash table.

Ret: none
*/
void HT::hTable_print()
{
    cout<<endl;
    for(unsigned total = 0; total < hTable.size(); ++total)
    {
        list<Entry> &l_check = hTable[total];

        for(auto it = l_check.begin(); it != l_check.end(); ++it)
        {
            cout << left << setw(4) << total << ":" << setw(7) << it->key << "- " << setw(7) << it->num;
            cout << "-  " << setw(24) << it->desc;
            cout << endl;
        }
    }
    cout<<endl;
}

/*
Func: void HT::pTable_print()

Arg: This public function prints the contents of all (and only)
     the active records in the hash table.

Ret: none
*/
void HT::pTable_print()
{
    sort(pTable.begin(), pTable.end(), [](Entry *p, Entry *q) {return q->key > p -> key; });

    for(auto it = pTable.begin(); it != pTable.end(); ++it)
    {
        cout << right << setw(6) << (*it)->key << "  - " << setw(4) << (*it) -> num << "  -  ";
        cout << left << (*it) -> desc << endl;
    }
}
