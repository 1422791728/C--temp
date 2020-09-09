#include  <iostream>
#include <vector>
#include <algorithm>//算法
#include <ctime>
#include <array>
#include <iomanip>
#include <string>
#include <cstring>
#include <cmath>
#include "LandOwner.h"
#include "Mystring.h"
//#include "swap.h"
#include "MyVector.h"
#include "Class_Hero.h"
#include "Computer.h"
#include "BattleUnit.h"
#include "Array.hpp"
using namespace std;
#define Max 255
class ElementType
{
public:
	int id;
	string name;
};
class SquenList
{
public:
	ElementType datas[Max];
	int length;
	SquenList()
	{
		length = 0;
	}
	void InsertElement(ElementType elem, int index)
	{
		if (length + 1 > Max)
		{
			cout << "元素已满不能插入" << endl;
			return;
		}
		if (index < 0 || index > length)
		{
			cout << "不符合顺序表结构" << endl;
			return;
		}
		for (int i = length - 1; i >= index; i--)
		{
			datas[i + 1] = datas[i];
		}
		datas[index] = elem;
		this->length++;
	}
	void InitList(ElementType* elem, int length)
	{
		this->length = 0;
		if (this->length > Max)
		{
			cout << "8行越界了" << endl;
			return;
		}
		for (int i = 0; i < length; i++)
		{
			InsertElement(elem[i], i);
		}
	}
	void Show()
	{
		for (int i = 0; i < this->length; i++)
		{
			cout << datas[i].id << endl;
		}
	}
	ElementType* DeleteElement(int index)
	{
		if (index < 0 || index > length - 1)
		{
			cout << "该下标没有元素" << endl;
			return NULL;
		}
		ElementType* ele = new ElementType();
		*ele = *FightElement(index);
		for (int i = index; i < length - 1; i++)
		{
			datas[i] = datas[i + 1];
		}
		length--;
		return ele;
	}
	ElementType* FightElement(int index)
	{
		if (index < 0 || index > length - 1)
		{
			cout << "该下标没有元素" << endl;
			return NULL;
		}
		return &datas[index];
	}
	bool Empty()
	{
		return Size() == 0 ? true : false;
	}
	int Size()
	{
		return length;
	}
	void Clear()
	{
		length = 0;
	}
};



class SquenList_test :public SquenList
{
public:
	void InsertElement(ElementType elem, int index)
	{
		if (length + 1 > Max)
		{
			cout << "元素已满不能插入" << endl;
			return;
		}
		for (int i = length - 1; i >= index; i--)
		{
			datas[i + 1] = datas[i];
		}
		datas[index] = elem;
		this->length++;
	}
	void InitList(ElementType* elem, int length)
	{
		this->length = 0;
		for (int i = 0; i < length; i++)
		{
			InsertElement(elem[i], i + 1);
		}
	}
	void Show()
	{
		for (int i = 1; i <= this->length; i++)
		{
			cout << datas[i].id << endl;
		}
	}
	int SearchSeqList(int key)//平民版
	{
		for (int i = 1; i <= length; i++)
		{
			if (datas[i].id == key)
			{
				return i;
			}
		}
		return 0;
	}
	int SearchSeqList2(int key) //VIP版
	{
		datas[0].id = key;
		int i;
		for (i = length; datas[i].id != key; i--);
		return i;
	}
	void BublleSort()
	{
		for (int i = 0; i < length; i++)
		{
			for (int j = 1; j < length - i; j++)
			{
				if (datas[j].id > datas[j + 1].id)
				{
					int temp = datas[j].id;
					datas[j].id = datas[j + 1].id;
					datas[j + 1].id = temp;
				}
			}
		}
	}
	int SearchSeqList_Binary(int key)//二分法
	{
		int low = 1;
		int high = length;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (key == datas[mid].id)
			{
				return mid;
			}
			else if (key < datas[mid].id)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		return 0;
	}
	int SearchSeqList_BinaryRecursion(int key,int low,int high)//递归调用
	{
		if (low > high) return 0;
		int mid = (high + low) / 2;
		if (datas[mid].id == key)
		{
			return mid;
		}
		else if (key < datas[mid].id)
		{
			return SearchSeqList_BinaryRecursion(key, low, mid - 1);
		}
		else
		{
			return SearchSeqList_BinaryRecursion(key, mid + 1, high);
		}
	}
};
int main()
{ 
	ElementType elem[] = {
		{1,"太上老君"},
		{2,"太上老君"},
		{3,"太上老君"},
		{4,"王者农药"}
	};
	SquenList_test list;
	list.InitList(elem, 4);
	cout << list.SearchSeqList_BinaryRecursion(2,1,list.length) << endl;
}







//template<class T = string>
//class Person
//{
//public:
//	Person(T name);
//	void Show();
//	T name;
//};
//template<class T>
//Person<T>::Person(T name)
//{
//	this->name = name;
//}
//template<class T>
//void Person<T>::Show()
//{
//
//}
//int main()
//{
//	Person<> p("孙悟空");
//	cout << p.name;
//}
//class Person {
//public:
//	int id;
//	Person(int id)
//	{
//		this->id = id;
//	}
//};
//template <typename T >
//void Compare(T& a, T& b)
//{
//	if (a == b)
//	{
//		cout << "一样" << endl;
//	}
//	else
//	{
//		cout << "错误" << endl;
//	}
//}
//template<> void Compare(Person& a, Person& b)
//{
//	if (a.id == b.id)
//	{
//		cout << "一样" << endl;
//	}
//	else
//	{
//		cout << "错误" << endl;
//	}
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	Compare(a, b);
//}
//int main()
//{
//	char ch[99][99] = {0};// 由？和 *组成的矩阵 全部初始化为0 好算
//	int num[97][97] = {0};//扫雷成功的矩阵 比上面少两阶是因为上面把第一行第一列和最后1行和列留出来 全部初始化为0 好算
//	int stairs;//为几阶的矩阵
//	cout << "该矩阵为几阶矩阵" << endl;
//	cin >> stairs;
//	//录入矩阵
//	cout << "请录入该矩阵" << endl;
//	for (int i = 1; i <= stairs; i++)//从1开始是为了把第一行和最后一行留出来
//	{
//		for (int j = 1; j <= stairs; j++)
//		{
//			cin >> ch[i][j];
//
//		}
//	}
//	//找地雷了
//	for (int i = 1; i <= stairs; i++)
//	{
//		for (int j = 1; j <= stairs;j++)
//		{
//			if (ch[i][j] == '?')//说明为此地为空开始遍历
//			{
//				for (int y = i - 1; y <= i + 1; y++)// 从他的上一行开始从他的下一行结束
//				{
//					for (int x = j - 1; x <= i + 1; x++)// 从他的前一列开始从他的下一列结束
//					{
//						if (ch[y][x] == '?')
//						{
//							num[i - 1][j - 1]++;//因为之前把第一行和列空出来了所以这里要-1
//						}
//						
//					}
//				}
//			}
//			else//有雷
//			{
//				num[i - 1][j - 1] = ch[i][j];//直接复制过去
//			}
//		}
//	}
//	cout << "扫完雷的结果是" << endl;
//	//输出扫完的矩阵
//	for (int i = 0; i < stairs; i++)
//	{
//		for (int j = 0; j < stairs; j++)
//		{
//			if (num[i][j] == 42)//因为 char转换成int时候 * 为42所以打印打印出*
//			{
//				cout << "* ";
//				
//			}
//			else
//			{
//				cout << num[i][j] << " ";
//			}
//		}
//		cout << endl;
//	}
//}
//class Student {
//public:
//	int id;		// 学生ID
//	int scores; //学生成绩
//};
//void max(Student* ptr_max, int length) //length代表学生个数
//{
//	int max_score = ptr_max->scores;
//	for (int i = 0; i < length; i++)
//	{
//		if (max_score < (ptr_max + i)->scores)
//		{
//			max_score = ptr_max->scores;
//		}
//	}
//	cout << "学生最大成绩" << max_score << endl;
//}
//int main()
//{
//	Student stu[5] = {
//	{1,100},
//	{2,99},
//	{3,90},
//	{4,60},
//	{5,0}
//	};
//	Student* ptr_stu = stu;
//	max(stu, sizeof(stu) / sizeof(Student));
//}

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
//	commander.Move(team,Point (100,100));
//	commander.Fight(team, vikin2);
//}

	//Point p(100, 100);
	//BattleUnit v4("火箭", Point (100,100));
	//cout << v4.m_position << endl;
	/*Warrior war("张三", 1, 1, 1);
	Archmage he("李四", 1, 1, 1);
	Hero& hero = he;
	Warrior& warr = (Warrior&)hero;*/


	//动态多态

	////向量法 静态多态
	//Warrior warr1("张三", 1, 1, 1);
	//Warrior warr2("李四", 1, 1, 1);
	//Warrior warr3("王五", 1, 1, 1);
	//
	//vector<Warrior*> war;
	//war.push_back(&warr1);
	//war.push_back(warr2);
	//war.push_back(warr3);
	//GameCore game;
	//game.RoleMove(war);
	


//int main()
//{
//	Cpu* cpu = new Inter_Cpu; 
//	Mb * mb = new Inter_Mb ; 
//	Vc * vc = new Inter_Vc;
//	//(cpu, mb, vc)		(Inter_Cpu cpu, Inter_Mb mb, Inter_Vc vc);
//	Computer* computer1 = new Computer(cpu, mb, vc);
//	//Computer com(int a = 10);
//	//com.Dowork;
//	computer1->Dowork();
//	delete computer1;
//	computer1 = NULL;
//	cpu = new Len_Cpu;
//	mb = new Len_Mb;
//	vc = new Len_Vc;
//	computer1 = new Computer(cpu, mb, vc);
//	computer1->Dowork();
//	delete computer1;
//	computer1 = NULL;
//	/*Computer computer2( cpu,  mb,  vc);
//	Computer computer3( cpu,  mb, vc);*/
//	
//}
//class Drink
//{
//public:
//
//	virtual void Boil()
//	{
//		cout << "烧水" << endl;
//	}
//	virtual void Brew() = 0;
//	virtual void Pour()
//	{
//		cout << "倒水" << endl;
//	}
//	virtual void Add() = 0;
//	void Finish()
//	{
//		 Boil();
//		 Brew();
//		 Pour();
//		 Add();
//	}
//};
//class Coffer:public Drink
//{
//public:
//	int m_a;
//	virtual void Brew()
//	{
//		cout << "咖啡" << endl;
//	}
//	
//	virtual void Add()
//	{
//		cout << "牛奶" << endl;
//	}
//};
//class Tea :public Drink
//{
//public:
//
//	virtual void Brew()
//	{
//		cout << "茶叶" << endl;
//	}
//
//	virtual void Add()
//	{
//		cout << "柠檬" << endl;
//	}
//};
//int main()
//{
//	//Coffer coffer;
//	Drink* drink = new Coffer();
//	drink->Finish();
//	//drink->m_a;
//	delete drink;
//	cout << endl;
//	drink = new Tea();
//	drink->Finish();
//	delete drink;
//}



//////计算器
//class Calculate
//{
//
//public:
//	int m_num1;
//	int m_num2;
//	virtual int Result()
//	{
//		return 0;
//	}
//};
//class Add:public Calculate
//{
//	virtual int Result()
//	{
//		return m_num1 + m_num2;
//	}
//};
//class Sub :public Calculate
//{
//	virtual int Result()
//	{
//		return m_num1 - m_num2;
//	}
//};
//int main()
//{
//	Calculate* result = new Add;
//	//new Add;
//	result->m_num1 = 1;
//	result->m_num2 = 2;
//	cout << result->Result() << endl;
//	delete result;
//	result = new Sub;
//	result->m_num1 = 1;
//	result->m_num2 = 2;
//	cout << result->Result() << endl;
//	delete result;
//}
//  多态入门
//class Animal
//{
//public:
//	virtual void Speak()
//	{
//		cout << "动物在说话" << endl;
//	}
//	void Tell()
//	{
//		cout << "动物在说话" << endl;
//	}
//};
//class Cat : public Animal
//{
//public:
//	void Tell()
//	{
//		cout << "猫在说话" << endl;
//	}
//	void Speak()
//	{
//		cout << "猫在说话" << endl;
//	}
//};
//class Dog : public Cat
//{
//public:
//	void Speak()
//	{
//		cout << "猫在说话" << endl;
//	}
//};



	
	/*Son1 son1;
	Person1& p1 = son1;
	son.add();
	p1.add();*/
	/*Cat cat;
	Animal an = cat;
	an = cat;
	an.Speak();*/

	/*Son son1;
	int a = 10;
	son1.son(a);
	Person p1;
	Person& fa = (Person&)son1;
	Person* fa1 = &(Person)son1;
	Son& son2 = (Son&)p1;*/

		
	
	//Warrior war1();
	///*Hero her1();
	//Hero *he = new Warrior();*/
	//Hero* ptr_her2 = &war1;
	//Hero& hero = war1;

	//cout << ad.Getname() << endl;

//class Circle
//{
//public:
//	Circle(int radius = 0) :m_radius(radius){ cout << "调用" << endl; }
//	void Show()
//	{
//		cout << m_radius << endl;
//	}
//	Circle& operator= (Circle& c1)
//	{
//		m_radius = c1.m_radius;
//		cout << "调用1" << endl;
//	}
//private:
//	int m_radius;
//};
//class Rectange
//{
//public:
//	Rectange(int width):m_width(width){}
//	operator Circle()
//	{
//		cout << "调用" << endl;
//		return Circle(m_width/2);
//	}
//	void Show()
//	{
//		cout << m_width << endl;
//	}
//private:
//	int m_width;
//};

//运算符重载
//class Person
//{
//	friend class Good;
//	friend ostream& operator<<(ostream& out, Person& p);
//	//friend iostream& operator>>(iostream& in, Person& p);
//	friend void A(Person&p);
//private:
//	string m_Room;
//public:
//	int m_a;
//	int m_b;
//	int *m_age;
//	string m_name;
//	Person& operator+(Person& p)
//	{
//		
//		m_a += p.m_a;
//		return *this;
//	}
//	
//	Person() :m_a(0),m_Room("卧室"){}
//	Person(string room)
//	{
//		m_Room = room;
//	}
//	Person(int a)
//	{
//		m_a=a;
//	}
//	~Person()
//	{
//		if (m_age != NULL)
//		{
//			delete m_age;
//			m_age = NULL;
//		}
//	}
//	Person& operator++()
//	{
//		m_a++;
//		return  *this;
//	}
//	Person operator++(int)
//	{
//		Person temp = *this;
//		m_a++;
//		return  temp;
//	}
//	Person& operator--()
//	{
//		m_a--;
//		return *this;
//	}
//	Person operator--(int)
//	{
//		Person temp = *this;
//		m_a--;
//		return temp;
//	}
//	Person& operator=(Person& p)
//	{
//		if (m_age != NULL)
//		{
//			delete m_age;
//			m_age = NULL;
//		}
//		m_age = new int(*p.m_age);
//		return *this;
//	}
//	bool operator==(Person& p)
//	{
//		if (p.m_a == m_a)
//		{
//			
//			return true;
//		}
//		else
//		{
//		
//		return false; 
//		}
//	}
//	void operator() (string str)
//	{
//		cout << str << endl;
//	}
//	
//};
//ostream& operator<<(ostream&out ,Person& p)
//{
//	out  << p.m_a<<p.m_b<<endl;
//	out << p.m_Room << endl;
//	return cout;
//}
//istream& operator>>(istream& in, Person& p)
//{
//	in >> p.m_a >> p.m_b;
//	return in;
//}
//int main()
//{
//	Person p("客厅");
//	Person temp(p);
//	
//	cout << temp << endl;
//}


//int main()
//{
//	
//	
//	//这里person p = doWork2()不会调用拷贝方法，
//	//因为编译器优化，会直接用对象p存放dowork2()的返回值。这个问题在维基百科上叫做copy ellision。中文叫复制省略
//	////LandOwner* landOwner1 = new LandOwner;///土鳖
//	//LandOwner* landOwner2 = new LandOwner("刘能","男",2000,0);//土豪
//	////landOwner1->ShowInfo();
//	//landOwner2->Touchcards(20);
//	//
//	////delete landOwner1;
//	//delete landOwner2;
//
//}

/*
class Point
{
public:
	void SetX(int x)
	{
		m_x = x;
	}
	int GetX()
	{
		return m_x;
	}
	void SetY(int y)
	{
		m_y = y;
	}
	int GetY()
	{
		return m_y;
	}
private:
	int m_x;
	int m_y;
};
class Circle
{
public:
	void SetR(int r)
	{
		m_r = r;
	}
	int GetR()
	{
		return m_r;
	}
	void SetO(Point o)
	{
		m_o = o;
	}
	Point GetO()
	{
		return m_o;
	}
public:
	int m_r;
	Point m_o;
};
int main()
{
	Circle C;
	Point P,O;
	O.SetX(0);
	O.SetY(0);
	C.SetO(O);
	P.SetX(10);
	P.SetY(10);
	cout << C.GetO().GetX();

}
/*
class Point {
private:
	int m_x2;
	int m_y2;
public:
	void setX2(int);
	void setY2(int);
	int getX2();
	int getY2();
};
class Circle
{
private:
	int m_x1;
	int m_y1;
	int m_r;
public:
	void setX1(int);
	void setY1(int);
	void setR(int r)
	{
		m_r = r;
	}
	int getR()
	{
		return m_r;
	}
	double Cal_distance(Point& p)
	{
		double ret =  (double)sqrt(pow((m_x1 - p.getX2()), 2) + pow((m_y1 - p.getY2()), 2));
		return ret;
	}
	int getX1();
	int getY1();

};

int main()
{
	Circle C1;
	C1.setX1(0);
	C1.setY1(0);
	C1.setR(10);
	Point p;
	p.setX2(0);
	p.setY2(8);
	
	if (C1.Cal_distance(p) > C1.getR())
	{
		cout << "在园外" << endl;
	}
	else if (C1.Cal_distance(p) < C1.getR())
	{
		cout << "在园内" << endl;
	}
	else
	{
		cout << "在园上" << endl;
	}
	return 0;
}
void Circle::setX1(int x1)
{
	m_x1 = x1;
}
void Circle::setY1(int y1)
{
	m_y1 = y1;
}
int Circle::getX1()
{
	return m_x1;
}
int Circle::getY1()
{
	return m_y1;
}
void Point::setX2(int x2)
{ 
	m_x2 = x2;
}
void Point::setY2(int y2)
{
	m_y2 = y2;
}
int Point::getX2()
{
	return m_x2;
}
int Point::getY2()
{
	return m_y2;
}
/*
class Cube
{
private :
	int _L;//长
	int _H;//高
	int _W;//宽

public:
	void SetL(int);//录入长
	void SetH(int);//录入高
	void SetW(int);//录入宽
	int Getl();//读取长
	int GetW();//读取宽
	int GetH();//读取高
	void Judge1(Cube&);//判断是否相等
	int Cal_V()
	{
		return (_L * _W * _L);
	}
	int Cal_S()
	{
		return (_L * _W + _W * _H + _L * _H) * 2;
	 }

};
void Judge2(Cube&, Cube&);//判断是否相等
int main()
{
	Cube c1, c2;
	c1.SetL(1);
	c1.SetW(1);
	c1.SetH(1);
	c2.SetL(1);
	c2.SetW(1);
	c2.SetH(5);
	cout << "C1的表面积为" << c1.Cal_S() << endl;
	cout << "C1的体积" << c1.Cal_V() << endl;
	cout << "C2的表面积为" << c2.Cal_S() << endl;
	cout << "C2的体积" << c2.Cal_V() << endl;
	c1.Judge1(c2);
	
}
void Cube::SetL(int len)//录入长
{
	_L = len;
}
void Cube::SetH(int high)//录入高
{
	_H = high;
}
void Cube::SetW(int width)//录入宽
{
	_W = width;
}
int Cube::Getl()//读取长
{
	return _L;
}
int Cube::GetW()//读取宽
{
	return _W;
}
int Cube::GetH()//读取高
{
	return _H;
}
void Cube::Judge1(Cube& c2)
{
	if(((_L == c2.Getl()) + (_W == c2.GetW()) + (_H == c2.GetH())) == 3)
	{
		cout << "两个立方体相等" << endl;
	}
	else
	{
	cout << "两个立方体不相等" << endl;
	}
}
void Judge2(Cube& c1, Cube&c2)
{
	if (((c1.Getl() == c2.Getl()) + (c1.GetW() == c2.GetW()) + (c1.GetH() == c2.GetH())) == 3)
	{
		cout << "两个立方体相等" << endl;
	}
	else
	{
		cout << "两个立方体不相等" << endl;
	}
}
/*
 struct Student {
	string name;
	int score;
};
 struct Teacher
 {
	 string name;
	 struct Student stu[5];
 };
 void Input(Teacher[]);
 void Show(Teacher[]);

int main()
{
	srand(time(NULL));
	Teacher tarray[3];
	Input(tarray);
	Show(tarray);
	return 0;
}
void Input(Teacher tarray[])
{
	
	string tseed = "ABC";
	string sSeed = "ABCDEFGHIMLNOPQRSTuvwxyz";
	int z = 0;
	for (int i = 0; i < 3; i++)
	{
		tarray[i].name = "teacher_";
		tarray[i].name += tseed[i];
		for (int j = 0; j < 5; j++)
		{
			int randdom = rand() % 100 + 1;
			tarray[i].stu[j].name = "student_";
			tarray[i].stu[j].name += sSeed[z];
			tarray[i].stu[j].score = randdom;
			z++;
		}
	}
}
void Show(Teacher tarray[])
{
	for (int i = 0; i < 3; i++)
	{
		cout << tarray[i].name << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << tarray[i].stu[j].name <<'\t'<< tarray[i].stu[j].score << endl;
		}
	}
}
/*int show(int, int);
int main()
{
	int (*ptr_show)(int, int);
	ptr_show = show;
	cout << (*ptr_show)(3,1);
}
int show(int num1, int num2)
{
	int result = num1 * num2;
	return result;
}
/*
void Input(int(*)[3], int);
int main()
{
	
	int b[3][3] = {1,2,3,4,5,6,7,8,9};
	//int* ptr_b = b;
	Input(b,3);
}
void Input(int (*arr)[3], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j]<<' ';
		}
		cout << endl;
	}
	

}
/*
using namespace std;
void sw(int x,int y, int i, int j);
int n, m, k;
int total = 0;
char map[1001][1001];
int main()
{

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	for ( int i = 0; i <= n - k; i++)
	{
		for ( int j = 0; j <= m - k; j++)
		{
			for (int y = i; y < i + k; y++)
			{
				for (int x = j; x < j + k; x++)
				{
					if (map[y][x] == '1')
					{
						total++;
						goto FLAG;
					}
				}
			}
		FLAG:
			j++;
			j--;
		}
	}
	cout << total;
}









/*
template<class T>inline void read(T& res)
{
	char c; T flag = 1;
	while ((c = getchar()) < '0' || c > '9')if (c == '-')flag = -1; res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')res = res * 10 + c - '0'; res *= flag;
}
int main()
{
	int m, n;//行列
	cin >> m >> n;
	int Map[3000][3000];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			read(Map[i][j]);
		}
		//起始点
		int x = 0;
		int y = m - 1;
		int total = 0;
		while (1)
		{
			if (x == n - 1 && y == 0)
			{
				//说明到出口了
				break;
			}
			if (Map[y][x] == 1)
			{
				break;
			}

		}
	}
}
/*
int main()            
{
	int m, n;//行列
	cin >> m >> n;
	int Map[3000][3000];
	int index = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			read(Map[i][j]);
		}
	}
	while (1)
	{
		int x = 0;
		int y = m - 1;
		
		if (Map[y][x] == 1)
		{
			break;
		}
			
		
	}

}
*/
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
