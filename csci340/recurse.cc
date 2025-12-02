#include <bits/stdc++.h>

using namespace std;

void printback(vector <int> v) {
    if(v.size() > 0) {
        cout<<v.back()<<", ";
        v.pop_back();
        printback(v);
    }
}

int main() {
    vector <int> v = {2,4,6};
    cout<<"Before: ";
    for(auto i: v) {
        cout<< i <<", ";
    }
    cout<<endl;

    cout<<"after: ";
    for(auto i: v) {
        cout<< i<<", ";
    }
    printback(v);
    cout<<endl;
    return 0;
}

/*void countdown(int count) {

    cout<<"push "<<count<<endl;
    if(count > 0) {
        countdown(count - 1);
    }
}

int main() {
    countdown(5);
    return 0;
}
*/
