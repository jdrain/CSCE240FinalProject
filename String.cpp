/* 
 * Title: Assignment 6
 * Author: Victoria McQuinn
 * Function: Creates a String object with functions listed in the provided
 *           String.h file.
 * Input: None, testing done with multiple main.cpp files.
 * Output: Output depends on what functions used along with String object.
 *
 * Created October 31, 2016
 * Last modified on October 31, 2016, by Victoria McQuinn
 * Copyright protection information
 */

#include "String.h"
#include <iostream>

// Constructors

/* Default Constructor */
String::String()
{
	data = new char[0];	
	_length = 0;
}

/* Pass char array Constructor */
String::String(char str[])
{
	_length = getCharArraySize(str);
	data = new char[_length];
	for(int i = 0; i < _length; i++)
	{	
		data[i] = str[i];
	}
}

/* Copy Constructor */
String::String(const String &two)
{
	_length = two._length;
	data = new char[_length];

	for(int i = 0; i < _length; i++)
	{
		data[i] = two.data[i];
	}

}
/* Deconstructor for String class */
String::~String()
{
	delete [] data;
}

// Private Functions

/*
 * GetCharArraySize:
 * Counts the entries in data array up to the terminal character and returns
 * the size of the the char array.
 */
int String::getCharArraySize(char arr[]) 
{	
	int size(0);
	int i(0);

	while(arr[i] != '\0') 
	{
		size++;
		i++;
	}

	return size;
}


// Public Functions


char* String::getData()
{
	return data;
}

void String::setData(char c[], int size)
{
	_length = size;
	data = new char[size];

	for(int i = 0; i < size; i++)
	{
		data[i] = c[i];
	}
}
	
void String::setDataP(char* c, int size)
{
	_length = size;
	data = new char[size];

	for(int i = 0; i < size; i++)
	{
		data[i] = c[i];
	}
}

/*
 * Print:
 * prints each character in the data array. If the length of the String is 0
 * we print "null".
 */
void String::print() const
{

	if(_length != 0)
	{
		for(int i = 0; i < _length; i++)
		{
			cout << data[i];
		}
		cout << endl;
	}

	else
	{
		cout << "null" << endl;
	}
}

/*
 * Length:
 * Returns the length of the String object
 */
int String::length()
{
	return _length;
}

/*
 * Clear:
 * Sets length of String object to 0, and replaces all chars with '\0'.
 */
void String::clear()
{
	_length = 0;
	data = new char[0];
}

/*
 * =:
 * Sets the current object to the passed object.
 */
String String::operator=(const String &rhs)
{
	delete [] data;
	_length = rhs._length;
	data = new char[_length];

	for(int i = 0; i < _length; i++)
	{
		data[i] = rhs.data[i];
	}

	return *this;
}

/*
 * Empty:
 * Checks the length of String obj and if its 0 returns true, otherwise returns
 * false.
 */
bool String::empty()
{
	if(_length == 0)
	{
		return true;
	}

	return false;
}

/*
 * []:
 * returns the character at a specified index, routes to 'at' function.
 */
char String::operator[](int index)
{
	if(index >= _length){
		exit(0);
	}

	return data[index];
}

/*
 * Find:
 * Starting at a specific index, tries to find a substring in the String object
 */
int String::find(char substr[], int startIndex)
{
	int subStart(0);
	int strStart(startIndex);

	bool notFound = true;

	while(notFound)
	{	
		if(strStart > _length)
		{
			notFound = false;
			return -1;
		}
		else if(substr[subStart] == data[strStart])
		{
			if(subStart == getCharArraySize(substr) - 1)
			{	
				notFound = false;
				return startIndex;
			}
			subStart++;
			strStart++;
		}
		else
		{
			startIndex++;
			strStart = startIndex;
			subStart = 0;
		}
	}
	return startIndex;
}

/*
 * ==:
 * Checks if the strings are the same length and if they contain the same data.
 * returns true or false.
 */
bool String::operator==(const String &two)
{
	if(two._length != _length)
	{
		return false;
	}
	
	for(int i = 0; i < two._length; i++)
	{
		if(two.data[i] != data[i])
		{
			return false;
		}
	}

	return true;
}

/*
 * +:
 * Adds a string at the end of another string.
 */
String String::operator+(const String &two)
{
	char temp [_length + two._length + 1];

	for(int i = 0; i < _length; i++)
	{
		temp[i] = data[i];
	}

	for(int i = _length; i < _length + two._length; i++)
	{
		temp[i] = two.data[i - _length];
	}

	temp[_length + two._length] = '\0';

	String temps(temp);

	return temps;
}

String String::subString(int startIndex, int length) {
	if (length+startIndex > _length) {
		String b;
		return b;
	}
	
	char temp [length+1];
	for(int i=startIndex; i < startIndex+length; i++){
		temp[i-startIndex]=data[i];
	}
	temp[length] = '\0';
	return String(temp);
}
/*
 * <<:
 *  Prints a string
 */
ostream & operator<<(ostream &outStream, const String &two)
{
	for (int i = 0; i < two._length; i++)
	{
		outStream << two.data[i];
	}

	return outStream;
}
