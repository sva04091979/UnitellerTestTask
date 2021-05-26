#pragma once
#include <atomic>
#include <string>

using namespace std;

constexpr auto MAX_INDEX = "Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9";

class ID
{
	class Locker {
		atomic_flag* cLock;
		Locker(atomic_flag& lock) { 
			cLock = &lock; 
			while (cLock->test_and_set());
		}
		~Locker() { cLock->clear(); }
		friend ID;
	};
	string cVal;
	mutable atomic_flag cLock=ATOMIC_FLAG_INIT;
public:
	bool Set(string);
	string operator ++();
	string operator ++(int);
	string operator --();
	string operator --(int);
	string operator *() const;
private:
	bool Check(string&);
	bool CheckAlloed(char);
	void Increase();
	void Decrease();
};

