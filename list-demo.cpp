#include <iostream>
#include <sstream>
#include <list>

using namespace std;

template <typename T>
ostream &operator <<(ostream &os, list<T> &l) {
	os << "[";
	for(typename list<T>::iterator iter = l.begin(); iter != l.end(); iter++)
	os << *iter << (!l.empty() ? ", " : "");
	os << "]";
	return os;
}

template <typename T>
bool contains(list<T> &l, T val) {

	bool flag=false;

	for(typename list<T>::iterator iter = l.begin(); iter != l.end(); iter++)
	if (*iter == val){
	 flag = true;
	 break;}

	if(flag == true)
	return true;
	else
	return false;
}


int main() {
	cout << boolalpha;

	list<int> li;

	for (int i = 10; i >= 0; i--)
		li.push_front(i);
	for (int i = 11; i < 20; i++)
		li.push_back(i);
		cout << li << endl;	

	cout << "li contains 15: " << contains(li, 15) << endl;
	cout << "li contains 23: " << contains(li, 23) << endl << endl;
	
	cout << "li from end to start: ";
	 list<int>::reverse_iterator iter = li.rbegin();
	while (iter != li.rend()) {
		cout << *iter << endl;
		iter++;
	}

	const int ARR_SIZE = 4;
	string arr[ARR_SIZE] = {"cat", "dog", "cow", "elephant"};

	cout << endl;

	list<string> ls;

	for (int i = 0; i < ARR_SIZE; i++)
		ls.push_back(arr[i]);

	cout << ls << endl;

	cout << "ls contains \"dog\": " << contains(ls, string("dog")) << endl;
	cout << "ls contains \"muskrat\": " << contains(ls, string("muskrat")) << endl;

	cout << endl << endl;

	list<string> ls2;

	for (int i = 5; i >= 0; i--) {
		ostringstream oss;
		oss << "String-" << i;
		ls2.push_front(oss.str());
	}
	
	for (int i = 6; i < 11; i++) {
		ostringstream oss;
		oss << "String-" << i;
		ls2.push_back(oss.str());
	}
	
	
	cout << "front: " << ls2.front() << endl;
	cout << "back: " << ls2.back() << endl;
	cout << ls2 << endl;

	cout << "\nls2 contains \"String-1\": " << contains(ls2, string("String-1")) << endl;
	cout << "ls2 contains \"String-15\": " << contains(ls2, string("String-15")) << endl;
	
	ls2.clear();
	cout << ls2 << endl;
	return 0;
}
