#include "Computer.h"
void Inter_Cpu::Calu()
{
	cout << "Inter��Cpu" << endl;
}
void Inter_Mb::Storage()
{
	cout << "Inter��Mb " << endl;
}
 void Inter_Vc::display()
{
	cout << "Inter��Vc" << endl;
}
 void Len_Cpu::Calu()
 {
	 cout << "Len��Cpu" << endl;
 }
 void Len_Mb::Storage()
 {
	 cout << "Len��Mb " << endl;
 }
 void Len_Vc::display()
 {
	 cout << "Len��Vc" << endl;
 }
 void Computer::Dowork()
 {
	 
		 m_cpu->Calu();
		 m_mb->Storage();
		 m_vc->display();
	
 }