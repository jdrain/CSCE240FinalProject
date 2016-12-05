/**************************************************************************
 * File: String.h
 * Author: Casey Cole
 * Modified by: Victoria McQuinn
 * Function: 
 * Input: 
 * Output:                                                                        *
 ***************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

class String 
{
	friend ostream & operator<<(ostream &, const String &);

	private:
		
		int _length;
		char *data;
		int getCharArraySize(char arr[]);
    
	public:
	
		String();
		String(char str[]);
		String(const String &);
		virtual ~String(); //Destructor should delete your data pointer.
    
		int length();
		void clear(); 
		bool empty();
		int find(char substr[], int startIndex);
		char* getData();
		void setData(char c[], int size);
		void setDataP(char* c, int size);
		void print() const;
		bool operator==(const String &);  
		String operator+(const String& two);  
		String operator=(const String &);  
		char operator[](int index);
		String subString(int startIndex, int length);
};
