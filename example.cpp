/*
 * main.cpp
 *
 *  Created on: 21.12.2014
 *      Author: maxi
 */

#include "MVariant.h"
#include <iostream>
#include <ostream>
#include <string>
#include <typeinfo>
#include <limits>

namespace MVariant{
using namespace std;

#ifdef __gnu_linux__
// Demangler for gcc
#include <cxxabi.h>
#endif

template <typename T>
string getType(T t){
#ifdef __gnu_linux__
	int     status;
	return string(abi::__cxa_demangle(typeid(t).name(), 0, 0, &status));
#else
	return string(typeid(t).name());
#endif
}

void test(){
	Variant x = Variant(3.14);
	cout << "Value of x is " << x << " (" << x.getTypeString() << ")" << endl;
	cout << "getType(x) is " << getType(x) << endl << endl;
	cout << "x = x + 4" << endl;

	x = x + 4;
	cout << "Value of x is " << x << " (" << x.getTypeString() << ")" << endl;
	cout << "getType(x) is " << getType(x) << endl << endl;
	cout << "x = x * 2" << endl;
	x = x * 2;
	cout << "Value of x is " << x << " (" << x.getTypeString() << ")" << endl;
	cout << "getType(x) is " << getType(x) << endl << endl;

	string str_newType_x;
	VARIANT_TYPE type = VT_NONE;
	while (type == VT_NONE){
		cout << "Enter new type for x:\t";
		cin >> str_newType_x;
		type = variant_string(str_newType_x);
	}
	cout << "x = x.clone(type);" << endl;
	x = x.clone(type);

	cout << "Value of x is " << x << " (" << x.getTypeString() << ")" << endl;
	cout << "getType(x) is " << getType(x) << endl << endl;

	cout << "Enter new value of x (" << x.getTypeString() << ")\t";
	cin >> x;
    if (cin.fail()){
    	cin.clear();
    	cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    }

    cout << "Value of x is " << x << " (" << x.getTypeString() << ")" << endl;
	cout << "getType(x) is " << getType(x) << endl << endl;

	cout << "Variant y = x.clone() * 42;" << endl;
	Variant y = x.clone() * 42;
	cout << "Value of y is " << y << " (" << y.getTypeString() << ")" << endl;
	cout << "getType(y) is still " << getType(y) << "!" << endl << endl;

	cout << "Variant z = 100 * x.toFloat() / y;" << endl;
	Variant z = 100 / x;
	cout << "Value of z is " << z << " (" << z.getTypeString() << ")" << endl;
	cout << "getType(z) is still" << getType(z) << "!" << endl << endl;

	string str_newType_z;
	type = VT_NONE;
	while (type == VT_NONE){
		cout << "Enter new type for z:\t";
		cin >> str_newType_z;
		type = variant_string(str_newType_z);
	}
	cout << "z = z.clone(type);" << endl;
	z = z.clone(type);
	cout << "Value of z is " << z << " (" << z.getTypeString() << ")" << endl;
	cout << "getType(z) is still" << getType(z) << "!" << endl;
}
}

using namespace MVariant;


int main(int argc, const char *argv[]){
	test();
	return 0;
}
