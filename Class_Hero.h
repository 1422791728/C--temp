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
	int m_maxlife; //�������ֵ
	int m_currlife;//��ǰ����ֵ
public:
	Hero(const string& name = "����",int level = 1,int maxlife = 100,int currlife = 100);
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
	int m_attack;//������
public:
	Warrior(const string& name, int level, int maxlife, int currlife);
	void Baseattack(Hero& hero);//��ͨ����
	void Move()override;
};
class Archmage :public Hero
{
private:
	int m_spellpower;//��ǿ
public:
	void Skill();//�ͷż���
	void Move() override;
	Archmage(const string& name, int level, int maxlife, int currlife);
};
class GameCore
{
public:
	//ע����ֻ�ܱ�������ʼ��
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

