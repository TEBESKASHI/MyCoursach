#include "Header.h"
void Credit::takeCredit(Company &company, Bank &bank,int a) {
	strcpy(this->nameofbank,bank.nameofbank);
	strcpy(this->nameofcompany, company.nameofcompany);
	cout << "�������� " << this->nameofcompany << " ������� ����� ������ � ����� " << this->nameofbank << endl;
	Credittype *p =bank.begin;
	while (a) {
		p = p->next;
		a--;
	}
	time_t result = time(nullptr);
	strcpy(this->localTime, asctime(localtime(&result)));
	cout << "������ " << p->creditname << " � ��������� " << p->percent << endl;
	cout << "�������� " << this->localTime << endl;
}
void Credit::print() {
	cout << "��������: " << this->nameofcompany << endl;
	cout << "��� �����: " << this->nameofbank << endl;
	cout << "�������� " << this->localTime << endl;
}