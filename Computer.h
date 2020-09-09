#pragma once
#include <iostream>
using namespace std;
class Cpu
{
public:
	virtual void Calu() = 0;
};
class Mb //内存条
{
public:
	virtual void Storage() = 0;
};
class Vc //显卡
{
public:
	virtual void display() = 0;
};
class Inter_Cpu : public Cpu
{
	virtual void Calu();
};
class Inter_Mb :public Mb
{
public:
	virtual void Storage();
};
class Inter_Vc :public Vc
{
public:
	virtual void display();

};
class Len_Cpu : public Cpu
{
	virtual void Calu();
};
class Len_Mb :public Mb
{
public:
	virtual void Storage();
};
class Len_Vc :public Vc
{
public:
	virtual void display();
};
class Computer
{
private:
	Cpu* m_cpu;
	Mb *m_mb;
	Vc *m_vc;
public:
	Computer(Cpu *cpu,Mb * mb, Vc * vc)// : m_cpu(&cpu),m_mb(&mb),m_vc(&vc)
	{
		m_cpu = cpu;
		m_mb = mb;
		m_vc = vc;
	}
	void Dowork();
	Computer(int a)
	{
		cout << "调用";
	}
	~Computer()// : m_cpu(&cpu),m_mb(&mb),m_vc(&vc)
	{
		delete m_cpu;
		m_cpu = nullptr;
		delete m_mb;
		m_mb = nullptr;
		delete m_vc;
		m_vc = nullptr;
	}
	
};
