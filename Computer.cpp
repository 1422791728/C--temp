#include "Computer.h"
void Inter_Cpu::Calu()
{
	cout << "Inter的Cpu" << endl;
}
void Inter_Mb::Storage()
{
	cout << "Inter的Mb " << endl;
}
 void Inter_Vc::display()
{
	cout << "Inter的Vc" << endl;
}
 void Len_Cpu::Calu()
 {
	 cout << "Len的Cpu" << endl;
 }
 void Len_Mb::Storage()
 {
	 cout << "Len的Mb " << endl;
 }
 void Len_Vc::display()
 {
	 cout << "Len的Vc" << endl;
 }
 void Computer::Dowork()
 {
	 
		 m_cpu->Calu();
		 m_mb->Storage();
		 m_vc->display();
	
 }