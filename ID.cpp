#include "ID.h"
#include <algorithm>

bool ID::Set(string val) {
	//lock_guard<mutex> lock(cLock);
	Locker lock(cLock);
	if (!Check(val)) return false;
		cVal = val;
	return true;
}

bool ID::Check(string& id) {
	auto length = id.length();
	if (length > 29 || (length + 1) % 3 != 0) return false;
	auto it = id.begin();
	while (true) {
		*it = static_cast<char>(toupper(static_cast<unsigned char>(*it)));
		if (*it < 'A' || *it>'Z') return false;
		if (!CheckAlloed(*it)) return false;
		++it;
		if (*it < '1' || *it > '9') return false;
		if (++it == id.end()) break;
		if (*it != '-') return false;
		++it;
	}
	return true;
}

bool ID::CheckAlloed(char cell) {
	switch (cell) {
	case 'D':
	case 'F':
	case 'G':
	case 'J':
	case 'M':
	case 'Q':
	case 'V':
		return false;
	}
	return true;
}

string ID::operator ++() {
	//lock_guard<mutex> lock(cLock);
	Locker lock(cLock);
	Increase();
	return cVal;
}

string ID::operator ++(int) {
	//lock_guard<mutex> lock(cLock);
	Locker lock(cLock);
	string ret = cVal;
	Increase();
	return ret;
}

string ID::operator --() {
	//lock_guard<mutex> lock(cLock);
	Locker lock(cLock);
	Decrease();
	return cVal;
}

string ID::operator --(int) {
	//lock_guard<mutex> lock(cLock);
	Locker lock(cLock);
	string ret = cVal;
	Decrease();
	return ret;
}

void ID::Increase() {
	if (cVal.empty()||cVal==MAX_INDEX) cVal = "A1";
	else {
		auto it = cVal.rbegin();
		while (true) {
			++(*it);
			if (*it > '9') {
				*it = '1';
				if (++(*(++it)) > 'Z') {
					*it = 'A';
					if (++it == cVal.rend()) {
						cVal = "A1-" + cVal;
						break;
					}
					else ++it;
				}
				else {
					if (!CheckAlloed(*it)) ++(*it);
					break;
				}
			}
			else break;
		}
	}
}

void ID::Decrease() {
	if (cVal.empty() || cVal == "A1") cVal = MAX_INDEX;
	else {
		auto it = cVal.rbegin();
		while (true) {
			--(*it);
			if (*it < '1') {
				*it = '9';
				if (--(*(++it)) < 'A') {
					*it = 'Z';
					if (++it == cVal.rend()) {
						cVal = cVal.substr(3);
						break;
					}
					else ++it;
				}
				else {
					if (!CheckAlloed(*it)) --(*it);
					break;
				}
			}
			else break;
		}
	}
}

string ID::operator *() const {
	//lock_guard<mutex> lock(cLock);
	Locker lock(cLock);
	return cVal;
}
