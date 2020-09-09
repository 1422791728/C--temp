#pragma once
#include <iostream>
#include <string>
#include <algorithm>//算法
#include <vector>
using namespace std;
class Point
{
private :
	int m_x;
	int m_y;
public :
	Point(int x, int y) : m_x(x),m_y(y)
	{

	}
	//Point(){}
	friend ostream& operator<< (ostream& out, Point& p)
	{
		out << "(" << p.m_x << "," << p.m_y << ")" << endl;
		return out;
	}
	/*void Setx(int x) { m_x = x; }
	void Sety(int y) { m_y = y; }*/
	int Getx() { return m_x; }
	int Gety() { return m_y; }
};
 
class BattleUnit
{
public:
	string m_name;
	Point m_position;
	int m_attk;
	int m_currlife;
public:
	BattleUnit(const string& name,const Point& p = Point(0,0),int attk = 100,int currlife = 100) :m_name(name),m_position(p) ,m_attk(attk),m_currlife(currlife)
	{

	}
	virtual void Move(const Point& p) = 0;
	virtual void Fight(BattleUnit & other) = 0;
};
class V5 :public BattleUnit
{
public:
	V5(const string& name, const Point& p = Point(0, 0)) : BattleUnit(name,p)
	{

	}
	virtual void Move(const Point& p)override;
	virtual void Fight(BattleUnit& other)override;
};
class Vikin : public BattleUnit
{
public :
	Vikin(const string& name, const Point& p = Point(0, 0)) : BattleUnit(name, p)
	{

	}
	virtual void Move(const Point& p)override;
	virtual void Fight(BattleUnit& other)override;
};
class Commander
{
public:
	void Move(vector<BattleUnit*> vecs, const Point& p);
	void Fight(vector<BattleUnit*> vecs, BattleUnit& other);
};
//int main()
//{
//	vector<BattleUnit*> team;
//	V5 v1("v1火箭");
//	V5 v2("v2火箭");
//	Vikin vikin1("维京战机1");
//	Vikin vikin2("维京战机2");
//	team.push_back(&v1);
//	team.push_back(&v2);
//	team.push_back(&vikin1);
//	Commander commander;
//	commander.Move(team, Point(100, 100));
//	commander.Fight(team, vikin2);
//}