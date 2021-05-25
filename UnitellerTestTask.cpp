#include <iostream>
#include "ID.h"

int main()
{
	ID id;
	if (!id.Set("M2") && !id.Set("A0") && !id.Set("A1_B2"))
		cout << "Wrong format check ok" << endl;
	const string xxx = "Z9-Z9-Z9-Z9-z9-Z9-Z9-Z9-Z9-Z8";
	id.Set(xxx);
	cout<<*id<<endl;
	for (int i = 0; i < 10; ++i)
		cout << ++id << endl;
	cout << id++ << endl;
	cout << *id << endl;
	const char* yyy = "Z9-Z9";
	id.Set(yyy);
	cout << *id << endl;
	cout << ++id << endl;
	id.Set("A1");
	cout << *id << endl;
	for (int i = 0; i < 10; ++i) {
		cout << --id << endl;
	}
}

