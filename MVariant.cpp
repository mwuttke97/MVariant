/*
 * MVariant.cpp
 *
 *  Created on: 21.12.2014
 *      Author: Maximilian Wuttke (mwuttke97@gmail.com)
 */

#include <stdint.h>
#include <string>
#include <algorithm>
#include <iostream>

#include "MVariant.h"
#include "MVariant_private.h"

namespace MVariant{

template <typename T1>
class temp_Variant : public base_Variant
{
public:
	T1 m_value;
	typedef temp_Variant<T1> me;

public:
	temp_Variant() { };
	temp_Variant(T1 & value)		{ m_value = value;};
	char toChar()					{ return m_value; };
	unsigned char toUChar()			{ return m_value; };
	short toShort()					{ return m_value; };
	unsigned short toUShort()		{ return m_value; };
	int toInt()						{ return m_value; };
	unsigned int toUInt()			{ return m_value; };
	long toLong()					{ return m_value; };
	unsigned long toULong()			{ return m_value; };
	long long toLongLong()			{ return m_value; };
	unsigned long long toULongLong(){ return m_value; };
	float toFloat()					{ return m_value; };
	double toDouble()				{ return m_value; };
	long double toLDouble()			{ return m_value; };

public:
	base_Variant * clone(){
		return new me(m_value);
	}

public:
	void set(char value)				{ m_value = value; };
	void set(unsigned char value)		{ m_value = value; };
	void set(short value)				{ m_value = value; };
	void set(unsigned short value)		{ m_value = value; };
	void set(int value)					{ m_value = value; };
	void set(unsigned int value)		{ m_value = value; };
	void set(long value)				{ m_value = value; };
	void set(unsigned long value)		{ m_value = value; };
	void set(long long value)			{ m_value = value; };
	void set(unsigned long long value)	{ m_value = value; };
	void set(float value)				{ m_value = value; };
	void set(double value)				{ m_value = value; };
	void set(long double value)			{ m_value = value; };

public:
//	me operator++()		{ return me(m_value++); };
//	me operator++(int)	{ return me(++m_value); };
//	me operator--()		{ return me(m_value--); };
//	me operator--(int)	{ return me(--m_value); };
	template <typename T2> me operator+(T2 & val)	{ return me(m_value + val); };
	template <typename T2> me operator-(T2 & val)	{ return me(m_value - val); };
	template <typename T2> me operator*(T2 & val)	{ return me(m_value * val); };
	template <typename T2> me operator/(T2 & val)	{ return me(m_value / val); };
	template <typename T2> me operator+=(T2 & val)	{ return me(m_value += val); };
	template <typename T2> me operator-=(T2 & val)	{ return me(m_value -= val); };
	template <typename T2> me operator*=(T2 & val)	{ return me(m_value *= val); };
	template <typename T2> me operator/=(T2 & val)	{ return me(m_value /= val); };

public:
	std::istream & operator >>(std::istream & istream){
		istream >> m_value;
		return istream;
	}

	std::ostream & operator <<(std::ostream & ostream){
		ostream << m_value;
		return ostream;
	}
};

std::ostream& operator <<(std::ostream& ostream, Variant & var) {
	return var <<(ostream);
}

std::istream& operator >>(std::istream& istream, Variant & var) {
	return var >>(istream);
}

std::ostream & operator <<(std::ostream & ostream, base_Variant * var){
	return var->operator <<(ostream);
}

std::istream & operator >>(std::istream & istream, base_Variant * var){
	return var->operator >>(istream);
}

std::ostream& Variant::operator <<(std::ostream& ostream) {
	if (m_variant){
		return ostream << m_variant;
	}
	return ostream;
}

std::istream& Variant::operator >>(std::istream& istream) {
	if (m_variant){
		return m_variant->operator >>(istream);
	}
	return istream;
}

base_Variant* makeVariant(char value) {
	return new temp_Variant<char>(value);
}

base_Variant* makeVariant(unsigned char value) {
	return new temp_Variant<unsigned char>(value);
}

base_Variant* makeVariant(short value) {
	return new temp_Variant<short>(value);
}

base_Variant* makeVariant(unsigned short value) {
	return new temp_Variant<unsigned short>(value);
}

base_Variant* makeVariant(int value) {
	return new temp_Variant<int>(value);
}

base_Variant* makeVariant(unsigned int value) {
	return new temp_Variant<unsigned int>(value);
}

base_Variant* makeVariant(long value) {
	return new temp_Variant<long>(value);
}

base_Variant* makeVariant(unsigned long value) {
	return new temp_Variant<unsigned long>(value);
}

base_Variant* makeVariant(long long value) {
	return new temp_Variant<long long>(value);
}

base_Variant* makeVariant(unsigned long long value) {
	return new temp_Variant<unsigned long long>(value);
}

base_Variant* makeVariant(float value) {
	return new temp_Variant<float>(value);
}

base_Variant* makeVariant(double value) {
	return new temp_Variant<double>(value);
}

base_Variant* makeVariant(long double value) {
	return new temp_Variant<long double>(value);
}

VARIANT_TYPE Variant::getType() const {
	return m_type;
}

Variant Variant::operator ++(int) {
	switch (m_type){
		case VT_CHAR:
			return Variant(reinterpret_cast<Variant_Char*>(m_variant)->m_value++);
		case VT_UCHAR:
			return Variant(reinterpret_cast<Variant_UChar*>(m_variant)->m_value++);
		case VT_SHORT:
			return Variant(reinterpret_cast<Variant_Short*>(m_variant)->m_value++);
		case VT_USHORT:
			return Variant(reinterpret_cast<Variant_UShort*>(m_variant)->m_value++);
		case VT_INT:
			return Variant(reinterpret_cast<Variant_Int*>(m_variant)->m_value++);
		case VT_UINT:
			return Variant(reinterpret_cast<Variant_UInt*>(m_variant)->m_value++);
		case VT_LONG:
			return Variant(reinterpret_cast<Variant_Long*>(m_variant)->m_value++);
		case VT_ULONG:
			return Variant(reinterpret_cast<Variant_ULong*>(m_variant)->m_value++);
		case VT_LONGLONG:
			return Variant(reinterpret_cast<Variant_LLong*>(m_variant)->m_value++);
		case VT_ULONGLONG:
			return Variant(reinterpret_cast<Variant_ULLong*>(m_variant)->m_value++);
		case VT_FLOAT:
			return Variant(reinterpret_cast<Variant_Float*>(m_variant)->m_value++);
		case VT_DOUBLE:
			return Variant(reinterpret_cast<Variant_Double*>(m_variant)->m_value++);
		case VT_LONGDOUBLE:
			return Variant(reinterpret_cast<Variant_LDouble*>(m_variant)->m_value++);
		default:
			return Variant(0);
	}
}

Variant Variant::operator ++() {
	switch (m_type){
		case VT_CHAR:
			return Variant(++reinterpret_cast<Variant_Char*>(m_variant)->m_value);
		case VT_UCHAR:
			return Variant(++reinterpret_cast<Variant_UChar*>(m_variant)->m_value);
		case VT_SHORT:
			return Variant(++reinterpret_cast<Variant_Short*>(m_variant)->m_value);
		case VT_USHORT:
			return Variant(++reinterpret_cast<Variant_UShort*>(m_variant)->m_value);
		case VT_INT:
			return Variant(++reinterpret_cast<Variant_Int*>(m_variant)->m_value);
		case VT_UINT:
			return Variant(++reinterpret_cast<Variant_UInt*>(m_variant)->m_value);
		case VT_LONG:
			return Variant(++reinterpret_cast<Variant_Long*>(m_variant)->m_value);
		case VT_ULONG:
			return Variant(++reinterpret_cast<Variant_ULong*>(m_variant)->m_value);
		case VT_LONGLONG:
			return Variant(++reinterpret_cast<Variant_LLong*>(m_variant)->m_value);
		case VT_ULONGLONG:
			return Variant(++reinterpret_cast<Variant_ULLong*>(m_variant)->m_value);
		case VT_FLOAT:
			return Variant(++reinterpret_cast<Variant_Float*>(m_variant)->m_value);
		case VT_DOUBLE:
			return Variant(++reinterpret_cast<Variant_Double*>(m_variant)->m_value);
		case VT_LONGDOUBLE:
			return Variant(++reinterpret_cast<Variant_LDouble*>(m_variant)->m_value);
		default:
			return Variant(0);
	}
}

Variant Variant::operator --(int) {
	switch (m_type){
		case VT_CHAR:
			return Variant(reinterpret_cast<Variant_Char*>(m_variant)->m_value--);
		case VT_UCHAR:
			return Variant(reinterpret_cast<Variant_UChar*>(m_variant)->m_value--);
		case VT_SHORT:
			return Variant(reinterpret_cast<Variant_Short*>(m_variant)->m_value--);
		case VT_USHORT:
			return Variant(reinterpret_cast<Variant_UShort*>(m_variant)->m_value--);
		case VT_INT:
			return Variant(reinterpret_cast<Variant_Int*>(m_variant)->m_value--);
		case VT_UINT:
			return Variant(reinterpret_cast<Variant_UInt*>(m_variant)->m_value--);
		case VT_LONG:
			return Variant(reinterpret_cast<Variant_Long*>(m_variant)->m_value--);
		case VT_ULONG:
			return Variant(reinterpret_cast<Variant_ULong*>(m_variant)->m_value--);
		case VT_LONGLONG:
			return Variant(reinterpret_cast<Variant_LLong*>(m_variant)->m_value--);
		case VT_ULONGLONG:
			return Variant(reinterpret_cast<Variant_ULLong*>(m_variant)->m_value--);
		case VT_FLOAT:
			return Variant(reinterpret_cast<Variant_Float*>(m_variant)->m_value--);
		case VT_DOUBLE:
			return Variant(reinterpret_cast<Variant_Double*>(m_variant)->m_value--);
		case VT_LONGDOUBLE:
			return Variant(reinterpret_cast<Variant_LDouble*>(m_variant)->m_value--);
		default:
			return Variant(0);
	}
}

Variant Variant::operator --() {
	switch (m_type){
		case VT_CHAR:
			return Variant(--reinterpret_cast<Variant_Char*>(m_variant)->m_value);
		case VT_UCHAR:
			return Variant(--reinterpret_cast<Variant_UChar*>(m_variant)->m_value);
		case VT_SHORT:
			return Variant(--reinterpret_cast<Variant_Short*>(m_variant)->m_value);
		case VT_USHORT:
			return Variant(--reinterpret_cast<Variant_UShort*>(m_variant)->m_value);
		case VT_INT:
			return Variant(--reinterpret_cast<Variant_Int*>(m_variant)->m_value);
		case VT_UINT:
			return Variant(--reinterpret_cast<Variant_UInt*>(m_variant)->m_value);
		case VT_LONG:
			return Variant(--reinterpret_cast<Variant_Long*>(m_variant)->m_value);
		case VT_ULONG:
			return Variant(--reinterpret_cast<Variant_ULong*>(m_variant)->m_value);
		case VT_LONGLONG:
			return Variant(--reinterpret_cast<Variant_LLong*>(m_variant)->m_value);
		case VT_ULONGLONG:
			return Variant(--reinterpret_cast<Variant_ULLong*>(m_variant)->m_value);
		case VT_FLOAT:
			return Variant(--reinterpret_cast<Variant_Float*>(m_variant)->m_value);
		case VT_DOUBLE:
			return Variant(--reinterpret_cast<Variant_Double*>(m_variant)->m_value);
		case VT_LONGDOUBLE:
			return Variant(--reinterpret_cast<Variant_LDouble*>(m_variant)->m_value);
		default:
			return Variant(0);
	}
}

template<typename T> Variant operator+ (Variant var, T t){
	switch (var.getType()){
		case VT_CHAR:
			return Variant(reinterpret_cast<Variant_Char*>(var.getVariant())->m_value + t);
		case VT_UCHAR:
			return Variant(reinterpret_cast<Variant_UChar*>(var.getVariant())->m_value + t);
		case VT_SHORT:
			return Variant(reinterpret_cast<Variant_Short*>(var.getVariant())->m_value + t);
		case VT_USHORT:
			return Variant(reinterpret_cast<Variant_UShort*>(var.getVariant())->m_value + t);
		case VT_INT:
			return Variant(reinterpret_cast<Variant_Int*>(var.getVariant())->m_value + t);
		case VT_UINT:
			return Variant(reinterpret_cast<Variant_UInt*>(var.getVariant())->m_value + t);
		case VT_LONG:
			return Variant(reinterpret_cast<Variant_Long*>(var.getVariant())->m_value + t);
		case VT_ULONG:
			return Variant(reinterpret_cast<Variant_ULong*>(var.getVariant())->m_value + t);
		case VT_LONGLONG:
			return Variant(reinterpret_cast<Variant_LLong*>(var.getVariant())->m_value + t);
		case VT_ULONGLONG:
			return Variant(reinterpret_cast<Variant_ULLong*>(var.getVariant())->m_value + t);
		case VT_FLOAT:
			return Variant(reinterpret_cast<Variant_Float*>(var.getVariant())->m_value + t);
		case VT_DOUBLE:
			return Variant(reinterpret_cast<Variant_Double*>(var.getVariant())->m_value + t);
		case VT_LONGDOUBLE:
			return Variant(reinterpret_cast<Variant_LDouble*>(var.getVariant())->m_value + t);
		default:
			return Variant(t);
	}
}

Variant operator+ (Variant var1, Variant var2) {
	switch (var2.getType()){
		case VT_CHAR:
			return Variant(var1 + reinterpret_cast<Variant_Char*>(var2.getVariant())->m_value);
		case VT_UCHAR:
			return Variant(var1 + reinterpret_cast<Variant_UChar*>(var2.getVariant())->m_value);
		case VT_SHORT:
			return Variant(var1 + reinterpret_cast<Variant_Short*>(var2.getVariant())->m_value);
		case VT_USHORT:
			return Variant(var1 + reinterpret_cast<Variant_UShort*>(var2.getVariant())->m_value);
		case VT_INT:
			return Variant(var1 + reinterpret_cast<Variant_Int*>(var2.getVariant())->m_value);
		case VT_UINT:
			return Variant(var1 + reinterpret_cast<Variant_UInt*>(var2.getVariant())->m_value);
		case VT_LONG:
			return Variant(var1 + reinterpret_cast<Variant_Long*>(var2.getVariant())->m_value);
		case VT_ULONG:
			return Variant(var1 + reinterpret_cast<Variant_ULong*>(var2.getVariant())->m_value);
		case VT_LONGLONG:
			return Variant(var1 + reinterpret_cast<Variant_LLong*>(var2.getVariant())->m_value);
		case VT_ULONGLONG:
			return Variant(var1 + reinterpret_cast<Variant_ULLong*>(var2.getVariant())->m_value);
		case VT_FLOAT:
			return Variant(var1 + reinterpret_cast<Variant_Float*>(var2.getVariant())->m_value);
		case VT_DOUBLE:
			return Variant(var1 + reinterpret_cast<Variant_Double*>(var2.getVariant())->m_value);
		case VT_LONGDOUBLE:
			return Variant(var1 + reinterpret_cast<Variant_LDouble*>(var2.getVariant())->m_value);
		default:
			return var2;
	}
}
template<typename T> Variant operator- (Variant var, T t){
	switch (var.getType()){
		case VT_CHAR:
			return Variant(reinterpret_cast<Variant_Char*>(var.getVariant())->m_value - t);
		case VT_UCHAR:
			return Variant(reinterpret_cast<Variant_UChar*>(var.getVariant())->m_value - t);
		case VT_SHORT:
			return Variant(reinterpret_cast<Variant_Short*>(var.getVariant())->m_value - t);
		case VT_USHORT:
			return Variant(reinterpret_cast<Variant_UShort*>(var.getVariant())->m_value - t);
		case VT_INT:
			return Variant(reinterpret_cast<Variant_Int*>(var.getVariant())->m_value - t);
		case VT_UINT:
			return Variant(reinterpret_cast<Variant_UInt*>(var.getVariant())->m_value - t);
		case VT_LONG:
			return Variant(reinterpret_cast<Variant_Long*>(var.getVariant())->m_value - t);
		case VT_ULONG:
			return Variant(reinterpret_cast<Variant_ULong*>(var.getVariant())->m_value - t);
		case VT_LONGLONG:
			return Variant(reinterpret_cast<Variant_LLong*>(var.getVariant())->m_value - t);
		case VT_ULONGLONG:
			return Variant(reinterpret_cast<Variant_ULLong*>(var.getVariant())->m_value - t);
		case VT_FLOAT:
			return Variant(reinterpret_cast<Variant_Float*>(var.getVariant())->m_value - t);
		case VT_DOUBLE:
			return Variant(reinterpret_cast<Variant_Double*>(var.getVariant())->m_value - t);
		case VT_LONGDOUBLE:
			return Variant(reinterpret_cast<Variant_LDouble*>(var.getVariant())->m_value - t);
		default:
			return Variant(t);
	}
}

Variant operator- (Variant var1, Variant var2) {
	switch (var2.getType()){
		case VT_CHAR:
			return Variant(var1 - reinterpret_cast<Variant_Char*>(var2.getVariant())->m_value);
		case VT_UCHAR:
			return Variant(var1 - reinterpret_cast<Variant_UChar*>(var2.getVariant())->m_value);
		case VT_SHORT:
			return Variant(var1 - reinterpret_cast<Variant_Short*>(var2.getVariant())->m_value);
		case VT_USHORT:
			return Variant(var1 - reinterpret_cast<Variant_UShort*>(var2.getVariant())->m_value);
		case VT_INT:
			return Variant(var1 - reinterpret_cast<Variant_Int*>(var2.getVariant())->m_value);
		case VT_UINT:
			return Variant(var1 - reinterpret_cast<Variant_UInt*>(var2.getVariant())->m_value);
		case VT_LONG:
			return Variant(var1 - reinterpret_cast<Variant_Long*>(var2.getVariant())->m_value);
		case VT_ULONG:
			return Variant(var1 - reinterpret_cast<Variant_ULong*>(var2.getVariant())->m_value);
		case VT_LONGLONG:
			return Variant(var1 - reinterpret_cast<Variant_LLong*>(var2.getVariant())->m_value);
		case VT_ULONGLONG:
			return Variant(var1 - reinterpret_cast<Variant_ULLong*>(var2.getVariant())->m_value);
		case VT_FLOAT:
			return Variant(var1 - reinterpret_cast<Variant_Float*>(var2.getVariant())->m_value);
		case VT_DOUBLE:
			return Variant(var1 - reinterpret_cast<Variant_Double*>(var2.getVariant())->m_value);
		case VT_LONGDOUBLE:
			return Variant(var1 - reinterpret_cast<Variant_LDouble*>(var2.getVariant())->m_value);
		default:
			return var2;
	}
}

template<typename T> Variant operator* (Variant var, T t){
	switch (var.getType()){
		case VT_CHAR:
			return Variant(reinterpret_cast<Variant_Char*>(var.getVariant())->m_value * t);
		case VT_UCHAR:
			return Variant(reinterpret_cast<Variant_UChar*>(var.getVariant())->m_value * t);
		case VT_SHORT:
			return Variant(reinterpret_cast<Variant_Short*>(var.getVariant())->m_value * t);
		case VT_USHORT:
			return Variant(reinterpret_cast<Variant_UShort*>(var.getVariant())->m_value * t);
		case VT_INT:
			return Variant(reinterpret_cast<Variant_Int*>(var.getVariant())->m_value * t);
		case VT_UINT:
			return Variant(reinterpret_cast<Variant_UInt*>(var.getVariant())->m_value * t);
		case VT_LONG:
			return Variant(reinterpret_cast<Variant_Long*>(var.getVariant())->m_value * t);
		case VT_ULONG:
			return Variant(reinterpret_cast<Variant_ULong*>(var.getVariant())->m_value * t);
		case VT_LONGLONG:
			return Variant(reinterpret_cast<Variant_LLong*>(var.getVariant())->m_value * t);
		case VT_ULONGLONG:
			return Variant(reinterpret_cast<Variant_ULLong*>(var.getVariant())->m_value * t);
		case VT_FLOAT:
			return Variant(reinterpret_cast<Variant_Float*>(var.getVariant())->m_value * t);
		case VT_DOUBLE:
			return Variant(reinterpret_cast<Variant_Double*>(var.getVariant())->m_value * t);
		case VT_LONGDOUBLE:
			return Variant(reinterpret_cast<Variant_LDouble*>(var.getVariant())->m_value * t);
		default:
			return Variant(t);
	}
}

Variant operator* (Variant var1, Variant var2) {
	switch (var2.getType()){
		case VT_CHAR:
			return Variant(var1 * reinterpret_cast<Variant_Char*>(var2.getVariant())->m_value);
		case VT_UCHAR:
			return Variant(var1 * reinterpret_cast<Variant_UChar*>(var2.getVariant())->m_value);
		case VT_SHORT:
			return Variant(var1 * reinterpret_cast<Variant_Short*>(var2.getVariant())->m_value);
		case VT_USHORT:
			return Variant(var1 * reinterpret_cast<Variant_UShort*>(var2.getVariant())->m_value);
		case VT_INT:
			return Variant(var1 * reinterpret_cast<Variant_Int*>(var2.getVariant())->m_value);
		case VT_UINT:
			return Variant(var1 * reinterpret_cast<Variant_UInt*>(var2.getVariant())->m_value);
		case VT_LONG:
			return Variant(var1 * reinterpret_cast<Variant_Long*>(var2.getVariant())->m_value);
		case VT_ULONG:
			return Variant(var1 * reinterpret_cast<Variant_ULong*>(var2.getVariant())->m_value);
		case VT_LONGLONG:
			return Variant(var1 * reinterpret_cast<Variant_LLong*>(var2.getVariant())->m_value);
		case VT_ULONGLONG:
			return Variant(var1 * reinterpret_cast<Variant_ULLong*>(var2.getVariant())->m_value);
		case VT_FLOAT:
			return Variant(var1 * reinterpret_cast<Variant_Float*>(var2.getVariant())->m_value);
		case VT_DOUBLE:
			return Variant(var1 * reinterpret_cast<Variant_Double*>(var2.getVariant())->m_value);
		case VT_LONGDOUBLE:
			return Variant(var1 * reinterpret_cast<Variant_LDouble*>(var2.getVariant())->m_value);
		default:
			return var2;
	}
}

template<typename T> Variant operator/ (Variant var, T t){
	switch (var.getType()){
		case VT_CHAR:
			return Variant(reinterpret_cast<Variant_Char*>(var.getVariant())->m_value / t);
		case VT_UCHAR:
			return Variant(reinterpret_cast<Variant_UChar*>(var.getVariant())->m_value / t);
		case VT_SHORT:
			return Variant(reinterpret_cast<Variant_Short*>(var.getVariant())->m_value / t);
		case VT_USHORT:
			return Variant(reinterpret_cast<Variant_UShort*>(var.getVariant())->m_value / t);
		case VT_INT:
			return Variant(reinterpret_cast<Variant_Int*>(var.getVariant())->m_value / t);
		case VT_UINT:
			return Variant(reinterpret_cast<Variant_UInt*>(var.getVariant())->m_value / t);
		case VT_LONG:
			return Variant(reinterpret_cast<Variant_Long*>(var.getVariant())->m_value / t);
		case VT_ULONG:
			return Variant(reinterpret_cast<Variant_ULong*>(var.getVariant())->m_value / t);
		case VT_LONGLONG:
			return Variant(reinterpret_cast<Variant_LLong*>(var.getVariant())->m_value / t);
		case VT_ULONGLONG:
			return Variant(reinterpret_cast<Variant_ULLong*>(var.getVariant())->m_value / t);
		case VT_FLOAT:
			return Variant(reinterpret_cast<Variant_Float*>(var.getVariant())->m_value / t);
		case VT_DOUBLE:
			return Variant(reinterpret_cast<Variant_Double*>(var.getVariant())->m_value / t);
		case VT_LONGDOUBLE:
			return Variant(reinterpret_cast<Variant_LDouble*>(var.getVariant())->m_value / t);
		default:
			return Variant(t);
	}
}

Variant operator/ (Variant var1, Variant var2) {
	switch (var2.getType()){
		case VT_CHAR:
			return Variant(var1 / reinterpret_cast<Variant_Char*>(var2.getVariant())->m_value);
		case VT_UCHAR:
			return Variant(var1 / reinterpret_cast<Variant_UChar*>(var2.getVariant())->m_value);
		case VT_SHORT:
			return Variant(var1 / reinterpret_cast<Variant_Short*>(var2.getVariant())->m_value);
		case VT_USHORT:
			return Variant(var1 / reinterpret_cast<Variant_UShort*>(var2.getVariant())->m_value);
		case VT_INT:
			return Variant(var1 / reinterpret_cast<Variant_Int*>(var2.getVariant())->m_value);
		case VT_UINT:
			return Variant(var1 / reinterpret_cast<Variant_UInt*>(var2.getVariant())->m_value);
		case VT_LONG:
			return Variant(var1 / reinterpret_cast<Variant_Long*>(var2.getVariant())->m_value);
		case VT_ULONG:
			return Variant(var1 / reinterpret_cast<Variant_ULong*>(var2.getVariant())->m_value);
		case VT_LONGLONG:
			return Variant(var1 / reinterpret_cast<Variant_LLong*>(var2.getVariant())->m_value);
		case VT_ULONGLONG:
			return Variant(var1 / reinterpret_cast<Variant_ULLong*>(var2.getVariant())->m_value);
		case VT_FLOAT:
			return Variant(var1 / reinterpret_cast<Variant_Float*>(var2.getVariant())->m_value);
		case VT_DOUBLE:
			return Variant(var1 / reinterpret_cast<Variant_Double*>(var2.getVariant())->m_value);
		case VT_LONGDOUBLE:
			return Variant(var1 / reinterpret_cast<Variant_LDouble*>(var2.getVariant())->m_value);
		default:
			return var2;
	}
}

template<typename T> bool operator== (Variant var, T t){
	switch (var.getType()){
		case VT_CHAR:
			return reinterpret_cast<Variant_Char*>(var.getVariant())->m_value == t;
		case VT_UCHAR:
			return reinterpret_cast<Variant_UChar*>(var.getVariant())->m_value == t;
		case VT_SHORT:
			return reinterpret_cast<Variant_Short*>(var.getVariant())->m_value == t;
		case VT_USHORT:
			return reinterpret_cast<Variant_UShort*>(var.getVariant())->m_value == t;
		case VT_INT:
			return reinterpret_cast<Variant_Int*>(var.getVariant())->m_value == t;
		case VT_UINT:
			return reinterpret_cast<Variant_UInt*>(var.getVariant())->m_value == t;
		case VT_LONG:
			return reinterpret_cast<Variant_Long*>(var.getVariant())->m_value == t;
		case VT_ULONG:
			return reinterpret_cast<Variant_ULong*>(var.getVariant())->m_value == t;
		case VT_LONGLONG:
			return reinterpret_cast<Variant_LLong*>(var.getVariant())->m_value == t;
		case VT_ULONGLONG:
			return reinterpret_cast<Variant_ULLong*>(var.getVariant())->m_value == t;
		case VT_FLOAT:
			return reinterpret_cast<Variant_Float*>(var.getVariant())->m_value == t;
		case VT_DOUBLE:
			return reinterpret_cast<Variant_Double*>(var.getVariant())->m_value == t;
		case VT_LONGDOUBLE:
			return reinterpret_cast<Variant_LDouble*>(var.getVariant())->m_value == t;
		default:
			return false;
	}
}

bool operator== (Variant var1, Variant var2) {
	switch (var2.getType()){
		case VT_CHAR:
			return var1 == reinterpret_cast<Variant_Char*>(var2.getVariant())->m_value;
		case VT_UCHAR:
			return var1 == reinterpret_cast<Variant_UChar*>(var2.getVariant())->m_value;
		case VT_SHORT:
			return var1 == reinterpret_cast<Variant_Short*>(var2.getVariant())->m_value;
		case VT_USHORT:
			return var1 == reinterpret_cast<Variant_UShort*>(var2.getVariant())->m_value;
		case VT_INT:
			return var1 == reinterpret_cast<Variant_Int*>(var2.getVariant())->m_value;
		case VT_UINT:
			return var1 == reinterpret_cast<Variant_UInt*>(var2.getVariant())->m_value;
		case VT_LONG:
			return var1 == reinterpret_cast<Variant_Long*>(var2.getVariant())->m_value;
		case VT_ULONG:
			return var1 == reinterpret_cast<Variant_ULong*>(var2.getVariant())->m_value;
		case VT_LONGLONG:
			return var1 == reinterpret_cast<Variant_LLong*>(var2.getVariant())->m_value;
		case VT_ULONGLONG:
			return var1 == reinterpret_cast<Variant_ULLong*>(var2.getVariant())->m_value;
		case VT_FLOAT:
			return var1 == reinterpret_cast<Variant_Float*>(var2.getVariant())->m_value;
		case VT_DOUBLE:
			return var1 == reinterpret_cast<Variant_Double*>(var2.getVariant())->m_value;
		case VT_LONGDOUBLE:
			return var1 == reinterpret_cast<Variant_LDouble*>(var2.getVariant())->m_value;
		default:
			return false;
	}
}

bool operator!= (Variant var1, Variant var2) {
	return !(var1 == var2);
}

base_Variant* Variant::getVariant() {
	return m_variant;
}

Variant Variant::operator +=(Variant var) {
	return *this = var + *this;
}

Variant Variant::operator -=(Variant var) {
	return *this = var - *this;
}

Variant Variant::operator *=(Variant var) {
	return *this = var * *this;
}

Variant Variant::operator /=(Variant var) {
	return *this = *this / var ;
}

Variant::Variant(char value) {
	m_variant = makeVariant(value);
	m_type = VT_CHAR;
}

Variant::Variant(unsigned char value) {
	m_variant = makeVariant(value);
	m_type = VT_UCHAR;
}

Variant::Variant(int value) {
	m_variant = makeVariant(value);
	m_type = VT_INT;
}

Variant::Variant(unsigned int value) {
	m_variant = makeVariant(value);
	m_type = VT_UINT;
}

Variant::Variant(short value) {
	m_variant = makeVariant(value);
	m_type = VT_SHORT;
}

Variant::Variant(unsigned short value) {
	m_variant = makeVariant(value);
	m_type = VT_USHORT;
}

Variant::Variant(long value) {
	m_variant = makeVariant(value);
	m_type = VT_LONG;
}

Variant::Variant(unsigned long value) {
	m_variant = makeVariant(value);
	m_type = VT_ULONG;
}

Variant::Variant(long long value) {
	m_variant = makeVariant(value);
	m_type = VT_LONGLONG;
}

Variant::Variant(unsigned long long value) {
	m_variant = makeVariant(value);
	m_type = VT_ULONGLONG;
}

Variant::Variant(float value) {
	m_variant = makeVariant(value);
	m_type = VT_FLOAT;
}

Variant::Variant(double value) {
	m_variant = makeVariant(value);
	m_type = VT_DOUBLE;
}

Variant::Variant(long double value) {
	m_variant = makeVariant(value);
	m_type = VT_LONGDOUBLE;
}

Variant::Variant(const Variant& variant) :
		m_type(variant.m_type) {
	m_variant = variant.m_variant->clone();
}

Variant::Variant(VARIANT_TYPE type) {
	m_type = type;
	m_variant = makeVariant(type);
}

Variant Variant::toChar() {
	return Variant(m_variant->toChar());
}

Variant Variant::toUChar() {
	return Variant(m_variant->toUChar());
}

Variant Variant::toShort() {
	return Variant(m_variant->toShort());
}

Variant Variant::toUShort() {
	return Variant(m_variant->toUShort());
}

Variant Variant::toInt() {
	return Variant(m_variant->toInt());
}

Variant Variant::toUInt() {
	return Variant(m_variant->toUInt());
}

Variant Variant::toLong() {
	return Variant(m_variant->toLong());
}

Variant Variant::toULong() {
	return Variant(m_variant->toULong());
}

Variant Variant::toLongLong() {
	return Variant(m_variant->toLongLong());
}

Variant Variant::toULongLong() {
	return Variant(m_variant->toULongLong());
}

Variant Variant::toFloat() {
	return Variant(m_variant->toFloat());
}

Variant Variant::toDouble() {
	return Variant(m_variant->toDouble());
}

Variant Variant::toLongDouble() {
	return Variant(m_variant->toLDouble());
}

Variant Variant::clone(VARIANT_TYPE t) {
	switch (t){
		case VT_CHAR:
			return toChar();
		case VT_UCHAR:
			return toUChar();
		case VT_SHORT:
			return toShort();
		case VT_USHORT:
			return toUShort();
		case VT_INT:
			return toInt();
		case VT_UINT:
			return toUInt();
		case VT_LONG:
			return toLong();
		case VT_ULONG:
			return toULong();
		case VT_LONGLONG:
			return toLongLong();
		case VT_ULONGLONG:
			return toULongLong();
		case VT_FLOAT:
			return toFloat();
		case VT_DOUBLE:
			return toDouble();
		case VT_LONGDOUBLE:
			return toLongDouble();
		case VT_NONE:
		default:
			return *this;
	}
}

Variant::~Variant() {
	if (m_variant)
		delete m_variant;
}

Variant& Variant::operator =(Variant& val) {
	if (m_variant)
		delete m_variant;

	m_variant = val.m_variant->clone();
	m_type = val.m_type;
	return *this;
}

Variant& Variant::operator =(Variant val) {
	if (m_variant)
		delete m_variant;

	m_variant = val.m_variant->clone();
	m_type = val.m_type;
	return *this;
}

base_Variant* makeVariant(VARIANT_TYPE type) {
	switch (type){
	case VT_CHAR:
			return new Variant_Char();
		case VT_UCHAR:
			return new Variant_UChar();
		case VT_SHORT:
			return new Variant_Short();
		case VT_USHORT:
			return new Variant_UShort();
		case VT_INT:
			return new Variant_Int();
		case VT_UINT:
			return new Variant_UInt();
		case VT_LONG:
			return new Variant_Long();
		case VT_ULONG:
			return new Variant_ULong();
		case VT_LONGLONG:
			return new Variant_LLong();
		case VT_ULONGLONG:
			return new Variant_ULLong();
		case VT_FLOAT:
			return new Variant_Float();
		case VT_DOUBLE:
			return new Variant_Double();
		case VT_LONGDOUBLE:
			return new Variant_LDouble();
		case VT_NONE:
		default:
			return 0;
	}
}

Variant::Variant(std::string str_name) {
	m_type = variant_string(str_name);
	m_variant = makeVariant(m_type);
}

std::string Variant::getTypeString() {
	return variant_string(m_type);
}

VARIANT_TYPE variant_string(std::string string) {
	std::transform(string.begin(), string.end(), string.begin(), toupper);
	if (string == "CHAR")
		return VT_CHAR;
	if (string == "UCHAR")
		return VT_UCHAR;
	if (string == "SHORT")
		return VT_SHORT;
	if (string == "USHORT")
		return VT_USHORT;
	if (string == "INT")
		return VT_INT;
	if (string == "UINT")
		return VT_UINT;
	if (string == "LONG")
		return VT_LONG;
	if (string == "ULONG")
		return VT_ULONG;
	if (string == "LONGLONG")
		return VT_LONGLONG;
	if (string == "ULONGLONG")
		return VT_ULONGLONG;
	if (string == "FLOAT")
		return VT_FLOAT;
	if (string == "DOUBLE")
		return VT_DOUBLE;
	if (string == "LONGDOUBLE")
		return  VT_LONGDOUBLE;
	return VT_NONE;
}

std::string variant_string(VARIANT_TYPE type){
	switch(type){
		case VT_CHAR:
			return "CHAR";
		case VT_UCHAR:
			return "UCHAR";
		case VT_SHORT:
			return "SHORT";
		case VT_USHORT:
			return "USHORT";
		case VT_INT:
			return "INT";
		case VT_UINT:
			return "UINT";
		case VT_LONG:
			return "LONG";
		case VT_ULONG:
			return "ULONG";
		case VT_LONGLONG:
			return "LONGLONG";
		case VT_ULONGLONG:
			return "ULONGLONG";
		case VT_FLOAT:
			return "FLOAT";
		case VT_DOUBLE:
			return "DOUBLE";
		case VT_LONGDOUBLE:
			return "LONGDOUBLE";
		case VT_NONE:
		default:
			return "NONE";
	}
}

}
