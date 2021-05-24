#include <iostream>
#include "ID.h"

int main()
{
	ID id;
	cout<<id.Set("Z9-Z9-Z9-Z9-Z9-Z9-Z9-z9-Z9-Z8")<<endl;
	cout<<++id<<endl;
	int i = 0;
	while(i++<10) {
		string it = ++id;
		cout << it << endl;
		if (it == MAX_INDEX) break;
	}
	cout << ++id << endl;
}

