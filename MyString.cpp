#include"Mystring.h"

String::String(const char* ch)
{
	m_length = strlen(ch);
	m_ch = new char[m_length + 1];
	strcpy_s(m_ch,m_length+1,ch);
}
String::String(const String& str)
{
	m_length = str.m_length;
	m_ch = new char[m_length + 1];
	strcpy_s(m_ch, m_length + 1, str.m_ch);
}
String::~String()
{
	delete[] m_ch;
}
String& String::operator= (String& str)
{
	delete[] m_ch;
	m_length = str.m_length;
	m_ch = new char [m_length + 1];
	strcpy_s(m_ch, m_length + 1, str.m_ch);
	return *this;

}
ostream&  operator<<(ostream& out,const String& str)
{
	out << str.m_ch<<endl;
	printf("%p",str.m_ch);
	return out;
}