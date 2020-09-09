#include "Class_Hero.h"
Hero::Hero(const string& name, int level, int maxlife, int currlife) : m_currlife(currlife),m_maxlife(maxlife),m_name(name),m_level(level)
{
	
}
//Hero::Hero() : Hero("����", 1, 100, 100)//�൱�ھ͵�����Hero�ĸ��������вι���
//{
//
//}
void Hero::Move()
{
	cout << m_name << "  " << endl;
}
ostream& operator<< (ostream& cout, const Hero& hero) 
{
	cout << "����" << hero.Getname() << endl;
	cout << "����" << hero.Getlevel() << endl;
	cout << "����" << hero.Getmaxlife() << endl;
	cout << "����" << hero.Getcurrlife()<< endl;
	return cout;
}
Warrior::Warrior(const string& name, int level, int maxlife, int currlife):Hero(name,level,maxlife,currlife)					//�൱�ڵ����˸���̳й�����Ĭ�Ϲ���
{
}
void Warrior::Move()
{
	cout << Getname() << "������������·��" << endl;
}
Archmage::Archmage(const string& name, int level, int maxlife, int currlife) : Hero(name, level, maxlife, currlife)
{
	
}
void Archmage::Move()
{
	cout << Getname() << "���й�����·��" << endl;
}
void Warrior::Baseattack(Hero& hero)
{
	hero.Getname();
}