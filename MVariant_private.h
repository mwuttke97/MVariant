/*
 * MVariant_private.h
 *
 *  Created on: 22.12.2014
 *      Author: Maximilian Wuttke (mwuttke97@gmail.com)
 */

#ifndef MVARIANT_PRIVATE_H_
#define MVARIANT_PRIVATE_H_

namespace MVariant{

class base_Variant{
public:
	virtual ~base_Variant(){};

public:
	virtual char toChar() = 0;
	virtual unsigned char toUChar() = 0;
	virtual short toShort() = 0;
	virtual unsigned short toUShort() = 0;
	virtual int toInt() = 0;
	virtual unsigned int toUInt() = 0;
	virtual long toLong() = 0;
	virtual unsigned long toULong() = 0;
	virtual long long toLongLong() = 0;
	virtual unsigned long long toULongLong() = 0;
	virtual float toFloat() = 0;
	virtual double toDouble() = 0;
	virtual long double toLDouble() = 0;

public:
	virtual void set(char value) = 0;
	virtual void set(unsigned char value) = 0;
	virtual void set(short value) = 0;
	virtual void set(unsigned short value) = 0;
	virtual void set(int value) = 0;
	virtual void set(unsigned int value) = 0;
	virtual void set(long value) = 0;
	virtual void set(unsigned long value) = 0;
	virtual void set(long long value) = 0;
	virtual void set(unsigned long long value) = 0;
	virtual void set(float value) = 0;
	virtual void set(double value) = 0;
	virtual void set(long double value) = 0;

public:
	virtual base_Variant * clone() = 0;

public:
	virtual std::istream & operator >> (std::istream & istream) = 0;
	virtual std::ostream & operator << (std::ostream & ostream) = 0;
};

base_Variant * makeVariant (char 				value);
base_Variant * makeVariant (unsigned char 		value);
base_Variant * makeVariant (short				value);
base_Variant * makeVariant (unsigned short		value);
base_Variant * makeVariant (int					value);
base_Variant * makeVariant (unsigned int		value);
base_Variant * makeVariant (long				value);
base_Variant * makeVariant (unsigned long		value);
base_Variant * makeVariant (long long			value);
base_Variant * makeVariant (unsigned long long	value);
base_Variant * makeVariant (float				value);
base_Variant * makeVariant (double				value);
base_Variant * makeVariant (long double			value);
base_Variant * makeVariant (VARIANT_TYPE type);


template <typename T> class temp_Variant;
typedef temp_Variant<char> 					Variant_Char;
typedef temp_Variant<unsigned char> 		Variant_UChar;
typedef temp_Variant<short>					Variant_Short;
typedef temp_Variant<unsigned short>		Variant_UShort;
typedef temp_Variant<int>					Variant_Int;
typedef temp_Variant<unsigned int>			Variant_UInt;
typedef temp_Variant<long>					Variant_Long;
typedef temp_Variant<unsigned long>			Variant_ULong;
typedef temp_Variant<long long>				Variant_LLong;
typedef temp_Variant<unsigned long long>	Variant_ULLong;
typedef temp_Variant<float>					Variant_Float;
typedef temp_Variant<double>				Variant_Double;
typedef temp_Variant<long double>			Variant_LDouble;

}

#endif /* MVARIANT_PRIVATE_H_ */
