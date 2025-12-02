#include <bits/stdc++.h>

using namespace std;

template <class CONTAINER>
void print_container(CONTAINER &c){
	for(auto i = c.begin(); i !=c.end(); ++i)
	{
		cout<<*i<<' ';
	}
	cout<<endl;
}

template<class ITERATOR>
void print_Container(ITERATOR &t) {
	for(auto i = t.begin(); i != t.end(); ++i)
	{
		cout<<*i<<' ';
	}
	cout<<endl;
}

int main(){

/*
//equal ranger	
	typedef list<int> cont;
	cont v = {1,2,3,4,5,5,5,9,8};
	cont v1 = {1,2,3,4,5};

	auto where = equal_range(v.begin(), v.end(), 5);
	print_container(where.first, where.second);

*/

/*
//MISMATCH EXAMPLE
	typedef list<int> cont;
	cont v = {1, 2, 3, 4, 5};
	cont v1 = {1, 2, 3, 4, 5};

	auto loc = mismatch(v.begin(), v.end(), v1.begin());

	cout<< (loc.first == v.end()) << endl;
	cout<< (loc.second == v.end()) << endl;

	cout<<"first in val: "<<*(loc.first)<<endl;
	cout<<"val in second: "<<*(loc.second)<<endl;

*/

//inserter is aware of the vectors size and will adjust as necessary

/*
//Copy iterator
	typedef std::vector<int> cont;
	
	cont v = {1, 2, 3};
	cont v1 = {3, 0};

	cout << "v =";
	print_container(v);

	cout<<"v1 =";
	print_container(v1);

	//copy can be dangerous because it doesn't change the size
	std::copy(v.begin(), v.end(), v1.begin()+1);

	cout<<"v1 =";
	print_container(v1);
*/
}
