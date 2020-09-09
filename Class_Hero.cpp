#include "Class_Hero.h"
Hero::Hero(const string& name, int level, int maxlife, int currlife) : m_currlife(currlife),m_maxlife(maxlife),m_name(name),m_level(level)
{
	
}
//Hero::Hero() : Hero("王五", 1, 100, 100)//相当于就调用了Hero四个参数的有参构造
//{
//
//}
void Hero::Move()
{
	cout << m_name << "  " << endl;
}
ostream& operator<< (ostream& cout, const Hero& hero) 
{
	cout << "名称" << hero.Getname() << endl;
	cout << "名称" << hero.Getlevel() << endl;
	cout << "名称" << hero.Getmaxlife() << endl;
	cout << "名称" << hero.Getcurrlife()<< endl;
	return cout;
}
Warrior::Warrior(const string& name, int level, int maxlife, int currlife):Hero(name,level,maxlife,currlife)					//相当于调用了父类继承过来的默认构造
{
}
void Warrior::Move()
{
	cout << Getname() << "正在骑马来的路上" << endl;
}
Archmage::Archmage(const string& name, int level, int maxlife, int currlife) : Hero(name, level, maxlife, currlife)
{
	
}
void Archmage::Move()
{
	cout << Getname() << "飞行过来的路上" << endl;
}
void Warrior::Baseattack(Hero& hero)
{
	hero.Getname();
}