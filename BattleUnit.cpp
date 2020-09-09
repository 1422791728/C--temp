#include "BattleUnit.h"
//ostream& operator<< (ostream& out, Point& p)
//{
//	out << "(" << p.m_x << "," << p.m_y << ")" << endl;
//	return out;
//}
 void V5::Move(const Point& p)
{
	m_position = p;
	cout << m_name << "�����ƶ���" << m_position << endl;
}
void V5::Fight(BattleUnit& other)
{
	cout << m_name << "��" << other.m_name << "�����" << m_attk << "���˺�" << endl;
}
void Vikin::Move(const Point& p)
{
	m_position = p;
	cout << m_name << "�����ƶ���" << m_position << endl;
}
void Vikin::Fight(BattleUnit& other)
{
	cout << m_name << "��" << other.m_name << "�����" << m_attk << "���˺�" << endl;
}
void Commander::Move(vector<BattleUnit*> vecs, const Point& p)
{
	for (auto vec:vecs)
	{
		vec->Move(p);
	}
}
void Commander::Fight(vector<BattleUnit*> vecs,BattleUnit & other)
{
	for (auto vec : vecs)
	{
		vec->Fight(other);
	}
}