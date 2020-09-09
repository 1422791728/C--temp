#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
class LandOwner
{
private:
	string m_name;
	string m_sex;
	int m_gold;
	long m_score;
	vector<int> pile;//≈∆∂—
	vector<int> draw_deck;//≈∆∂— £”‡µƒ≈∆
	vector<int> SDI;// ÷≈∆
	bool isContain(vector<int>&, int);
	void deletecard(int);
	string getColor(int);
	string getNum(int);

public:
	LandOwner();
	LandOwner(string,string,int,long);
	~LandOwner();
	void ShowInfo();
	void Touchcards(int);
	//bool isContain(vector<int>&, int);
	void Setname(string name) {
		m_name = name;
	}
	string Getname() {
		return m_name;
	}
	void Setsex(string sex)
	{
		m_sex = sex;
	}
	string Getsex() {
		return m_sex;
	}
	void Setgold(int gold) {
		m_gold = gold;
	}
	int Getgold() {
		return m_gold;
	}
	void Setscore(int score)
	{
		m_score = score;
	}
	long Getscore()
	{
		return m_score;
	}
	void Init();//≈∆∂—≥ı ºªØ
	void Showpile(const vector<int>&);//’π æ≈∆∂—

};

