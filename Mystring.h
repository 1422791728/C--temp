#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class String {
	friend ostream&  operator<<(ostream& out,const String& str);
public:
	int m_length;
	char* m_ch;
public:
	String(const char* );
	String(const String&);
	~String();
	String& operator= (String&);


};