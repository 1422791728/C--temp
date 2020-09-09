#include "LandOwner.h"
LandOwner::LandOwner()
{
	Setname("����");
	Setgold(0);
	Setsex("��");
	Setscore(0);
	cout << "����LandOwner()" << endl;
}
LandOwner ::LandOwner(string name, string sex, int gold , long score) :m_name(name),m_sex(sex),m_gold(gold),m_score(score)
{
	cout << "����LandOwner(string name, string sex, int gold , long score)" << endl;
	ShowInfo();
}
LandOwner::~LandOwner()
{
	cout << m_name << "�������" << endl;
}
void LandOwner::ShowInfo() {
	cout << m_name << "   ӵ�н��" << m_gold << endl;
	cout << "�Ա�   " << m_sex << "   ����" << m_score << endl;
	Init();
}
void LandOwner::Init()
{
	for (int i = 0; i < 54; i++)
	{
		pile.push_back(i + 1);
		draw_deck.push_back(pile.at(i));
	}
	SDI.clear();
}
void LandOwner::Showpile(const vector<int> & ve)
{
	/*for (auto it = ve.begin(); it != ve.end(); it++)
	{
		cout << *it << ',';

	}
	cout << endl;*/
	/*copy(ve.begin(), ve.end(), ostream_iterator<int>(cout, ","));
	cout << endl;*/
	for (int i = 0; i < ve.size(); i++)
	{
		string name = getColor(ve.at(i));
		name += getNum(ve.at(i));
		cout << name << ',';
	}
	cout << endl;

}
void LandOwner::Touchcards(int cardcount)
{
	srand(time(NULL));
	for (int i = 0; i < cardcount; i++)
	{
		int randIndex = rand() % 54;//�Ƶ��±�
		if (isContain(draw_deck, pile[randIndex]))//��˵��������û�д���
		{
			SDI.push_back(pile[randIndex]);
			deletecard(pile[randIndex]);
		}
		else
		{
			i--;
		}

	}
	cout << "�����ƺ�" << endl;
	Showpile(SDI);
	cout << "ʣ���ƶ�" << endl;
	Showpile(draw_deck);
	
}
bool LandOwner::isContain(vector<int>& ve_draw_deck, int num)
{
	vector<int> ::iterator it =  find(ve_draw_deck.begin(), ve_draw_deck.end(), num);
	/*if (it == ve_draw_deck.end())
	{
		return true;
	}
	else
	{
		return false;
	}*/
	return it != ve_draw_deck.end();
}
void LandOwner::deletecard(int num)
{
	/*for (vector<int> ::iterator it = draw_deck.begin(); it != draw_deck.end();)
	{
		if (*it == num)
		{
			draw_deck.erase(it);
		}
		else
		{
			++it;
		}
	}*/
	vector<int> ::iterator it = find(draw_deck.begin(), draw_deck.end(), num);
	if (it != draw_deck.end())
	{
		draw_deck.erase(it);
	}
}
string LandOwner::getColor(int card)
{
	string Color[] = { "����","����","��Ƭ","÷��" };
	if (card == 54)
	{
		return "Red";
	}
	else if (card == 53)
	{
		return "Black";
	}
	else {
		return Color[(card - 1) / 13];
	}
}
string LandOwner::getNum(int card)
{
	string num[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
	if (card == 54 || card == 53)
	{
		return "��";
	}
	else
	{
		return num[(card - 1) % 13];
	}
}
