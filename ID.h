#pragma once
#include <atomic>
#include <string>

using namespace std;

class ID
{
	struct _ID {
		struct Cell {
			char cId[2];
			void Set(char, char);
		};
		Cell cId[10];
		Cell& operator[](int i);
	};
	atomic<_ID> cId;
public:
	bool Set(string&&);
	string&& operator ++();
	string&& operator ++(int);
	string&& operator --();
	string&& operator --(int);
private:
	bool Add(_ID&,string::iterator&,int);
};

