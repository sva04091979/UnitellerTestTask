#include "ID.h"

bool ID::Set(string&& val) {
	auto length = val.length();
	if (length > 29 || (length + 1) % 3 != 0) return false;
	auto it = val.begin();
	int i = 0;
	_ID id;
	while (it != val.end()) {
		if (!Add(id,it,i++)) return false;
		++it;
	}
	cId = id;
}

bool ID::Add(_ID& id,string::iterator& it, int i) {
	char big = static_cast<char>(toupper(static_cast<unsigned char>(*it)));
	char small = *(++it);
	if (big < 'A' || big>'Z' || small < '1' || small > '9') return false;
	switch (big) {
	case 'D':
	case 'F':
	case 'G':
	case 'J':
	case 'M':
	case 'Q':
	case 'V':
		return false;
	}
	id[i].Set(big, small);
	return true;
}

string&& ID::operator ++() {
	Increase();
	_ID ret = cId;
	return ret.Text();
}

string&& ID::operator ++(int) {
	_ID ret = cId;
	Increase();
	return ret.Text();
}



ID::_ID::Cell& ID::_ID::operator[](int i) {
	return cId[i];
}

void ID::_ID::Cell::Set(char big, char small) {
	cId[0] = big;
	cId[1] = small;
}