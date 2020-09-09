#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Hero
{
	friend ostream& operator<<(ostream& cout, const Hero& hero);
private:
	string m_name;
	int m_level;
	int m_maxlife; //最大生命值
	int m_currlife;//当前生命值
public:
	Hero(const string& name = "张三",int level = 1,int maxlife = 100,int currlife = 100);
	//Hero();
	const string& Getname() const { return m_name; }
	const int& Getlevel() const { return m_level; }
	 int Getmaxlife() const  { return m_maxlife; }
	 int Getcurrlife() const { return m_currlife; }
	void Setname(string& name)
	{
		m_name = name;
	}
	void Setlevel(int level)
	{
		m_level = level;
	}
	void Setmaxlife(int maxlife)
	{
		m_maxlife = maxlife;
	}
	void Setcurrlife(int currlife)
	{
		m_currlife = currlife;
	}

	virtual void Move();
};
class Warrior : public Hero
{
private:
	int m_attack;//物理攻击
public:
	Warrior(const string& name, int level, int maxlife, int currlife);
	void Baseattack(Hero& hero);//普通攻击
	void Move()override;
};
class Archmage :public Hero
{
private:
	int m_spellpower;//法强
public:
	void Skill();//释放技能
	void Move() override;
	Archmage(const string& name, int level, int maxlife, int currlife);
};
class GameCore
{
public:
	//注向量只能被向量初始化
	/*void RoleMove(vector<Warrior>& vecwarrior)
	{
		for (auto warr : vecwarrior)
		{
			warr.Move();
		}
	}*/
	void RoleMove(Hero* hero)
	{
		hero->Move();
	}
};

