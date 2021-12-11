//
// Created by goddino on 12/11/21.
//

#include "stringUtils.h"
#include <string>
using namespace std;

string stringUtils::lowercase(string str) {
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}
