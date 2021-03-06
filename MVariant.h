/*
 * MVariant.h
 *
 *  Created on: 21.12.2014
 *      Author: Maximilian Wuttke (mwuttke97@gmail.com)
 */

#ifndef MVARIANT_H_
#define MVARIANT_H_

#include <iosfwd>
#include "MVariantType.h"

namespace MVariant{

class base_Variant;

// Complete variant class
class Variant{
private:
	base_Variant * m_variant;
	VARIANT_TYPE m_type;

public:
	Variant();
	Variant(char value);
	Variant(unsigned char value);
	Variant(int value);
	Variant(unsigned int value);
	Variant(short value);
	Variant(unsigned short value);
	Variant(long value);
	Variant(unsigned long value);
	Variant(long long value);
	Variant(unsigned long long value);
	Variant(float value);
	Variant(double value);
	Variant(long double value);
	Variant(const Variant& variant);
	Variant(VARIANT_TYPE type);
	~Variant();

public:
	std::string getTypeString();
	VARIANT_TYPE getType() const;
	base_Variant* getVariant();

public:
	Variant toChar();
	Variant toUChar();
	Variant toShort();
	Variant toUShort();
	Variant toInt();
	Variant toUInt();
	Variant toLong();
	Variant toULong();
	Variant toLongLong();
	Variant toULongLong();
	Variant toFloat();
	Variant toDouble();
	Variant toLongDouble();
	Variant clone(VARIANT_TYPE t = VT_NONE);

public:
	bool isValid() const;
	bool isInvalid() const;
	operator char() const;
	operator unsigned char() const;
	operator short() const;
	operator unsigned short() const;
	operator int() const;
	operator unsigned int() const;
	operator long() const;
	operator unsigned long() const;
	operator long long() const;
	operator unsigned long long() const;
	operator float() const;
	operator double() const;
	operator long double() const;

public:
	Variant operator ++ ();
	Variant operator ++ (int);
	Variant operator -- ();
	Variant operator -- (int);
	Variant operator += (Variant var);
	Variant operator -= (Variant var);
	Variant operator *= (Variant var);
	Variant operator /= (Variant var);
	Variant operator = (Variant val);

public:
	std::istream & operator >> (std::istream & istream);
	std::ostream & operator << (std::ostream & ostream);
};

Variant operator + (Variant, Variant);
Variant operator - (Variant, Variant);
Variant operator * (Variant, Variant);
Variant operator / (Variant, Variant);

bool operator== (Variant, Variant);
bool operator!= (Variant, Variant);

bool operator> (Variant, Variant);
bool operator< (Variant, Variant);
bool operator>= (Variant, Variant);
bool operator<= (Variant, Variant);


std::istream& operator>>(std::istream & istream, Variant & var);
std::ostream& operator<<(std::ostream & ostream, Variant var);

// Converts VARIANT_TYPE into std::string
std::string variant_string(VARIANT_TYPE type);

// Converts std::string into VARIANT_TYPE
VARIANT_TYPE variant_string(std::string string);
}

#endif /* MVARIANT_H_ */
