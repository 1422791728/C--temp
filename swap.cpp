#include "swap.h"
Student::Student()
{

	cout << "默认构造调用" << endl;
}
Student::Student(int age)
{
	m_age = new int (age);
	scores = new int[1];
	ScoreCount = 1;
	cout << "带参构造调用（int）" << endl;
}
void Student::AddScoer(int scores)
{
	this->scores[this->ScoreCount - 1] = scores;
	int* newscore = new int[ScoreCount + 1];
	memcpy(newscore,this->scores,ScoreCount * sizeof(int));
	delete[] this->scores;
	ScoreCount++;
	this->scores = newscore;
}
void Student::ShowScore()
{
	for (int i = 0; i < ScoreCount - 1; i++)
	{
		cout << scores[i] << endl;
	}
}
Student::Student(string name, string des) : m_name(name), m_des(des)
{
	/*m_name = name;
	m_des = des;*/
	cout << "带参构造调用（string,string）" << endl;
}
Student::~Student()
{
	if (m_age != nullptr)
	{
		delete m_age;
		m_age = nullptr;
	}
	cout << "析构构造调用" << endl;
}
Student::Student(const Student& st)
{
	m_age = new int(*st.m_age); 
	cout << "拷贝函数调用" << endl;
	
}
 Student Student::Compare(const Student& stu) const
{
	if (GetScores() > stu.GetScores())
	{
		return  *this;
	}
	else
	{
		return stu;
	}
}
int Student::GetScores()const
{
	int sum = 0;
	for (int i = 0; i < ScoreCount - 1; i++)
	{
		sum += this->scores[i];
	}
	return sum;
}