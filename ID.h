#pragma once
#include <atomic>
#include <string>
#include <mutex>

using namespace std;

constexpr auto MAX_INDEX = "Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9";

class ID
{
	string cVal;
	mutex cLock;
public:
	bool Set(string&&);
	string operator ++();
	string&& operator ++(int);
	string operator --();
	string&& operator --(int);
private:
	bool Check(string&);
	bool CheckAlloed(char);
	void Increase();
	void Decrease();
};

