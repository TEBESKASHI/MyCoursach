#include "Header.h"
void Credit::takeCredit(Company &company, Bank &bank,int a) {
	strcpy(this->nameofbank,bank.nameofbank);
	strcpy(this->nameofcompany, company.nameofcompany);
	cout << "Компания " << this->nameofcompany << " успешно взяла кредит в банке " << this->nameofbank << endl;
	Credittype *p =bank.begin;
	while (a) {
		p = p->next;
		a--;
	}
	time_t result = time(nullptr);
	strcpy(this->localTime, asctime(localtime(&result)));
	cout << "Кредит " << p->creditname << " с процентом " << p->percent << endl;
	cout << "Заключен " << this->localTime << endl;
}
void Credit::print() {
	cout << "Компания: " << this->nameofcompany << endl;
	cout << "Имя банка: " << this->nameofbank << endl;
	cout << "Заключен " << this->localTime << endl;
}