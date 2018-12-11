#include "Header.h"
void Credit::takeCredit(Company &cmp, Bank &bn,int a,float money,int times) {
	Credittype *credittype = bn.begin;
	if (cmp.rep==1) {
		cout << "Компания не может взять кредит" << endl;
		system("pause");
		return;
	}
	int h = 0;
	a--;
	while (h<a) {
		credittype = credittype->next;
	}
	strcpy(this->credittype.creditname,credittype->creditname);
	this->credittype.percent= credittype->percent;
	strcpy(this->nameofbank,bn.nameofbank);
	strcpy(company.nameofcompany, cmp.nameofcompany);
	cout << "Компания " << company.nameofcompany << " успешно взяла кредит в банке " << this->nameofbank << endl;
	time_t result = time(nullptr);
	this->sum = money;
	this->times = times;
	strcpy(this->localTime, asctime(localtime(&result)));
	cout << "Кредит " << this->credittype.creditname << " с процентом " << this->credittype.percent << endl;
	cout << "Сумма: " << money << endl;
	cout << "Срок: " << times << endl;
	cout << "Заключен " << this->localTime << endl;
}
void Credit::print(int a) {
	if (a == 1) {
		cout << "|````````````|" << "````````````|" << "````````|" << "```````````|" << "``````|" << endl;
		cout << "|  Компания  |" << "    Банк    |" << "  Сумма |" << " К выплате |" << " Срок |" << endl;
		cout << "|````````````|" << "````````````|" << "````````|" << "```````````|" << "``````|" << endl;
	}
	if (a == 2) {
		cout << "|" << setw(12) << company.nameofcompany << "|" << setw(12) << this->nameofbank << "|" << setw(8) << this->sum << "|" << setw(11) << (this->sum) + (this->sum*this->credittype.percent / 100 * this->times) << "|" << setw(6) << this->times << "|" << endl;
		cout << "|````````````|" << "````````````|" << "````````|" << "```````````|" << "``````|" << endl;
	}
	if (a == 3) {
		cout << "|" << setw(12) << company.nameofcompany << "|" << setw(12) << this->nameofbank << "|" << setw(8) << this->sum << "|" << setw(11) << (this->sum) + (this->sum*this->credittype.percent / 100 * this->times) << "|" << setw(6) << this->times << "|" << endl;
		cout << "``````````````" << "`````````````" << "`````````" << "````````````" << "```````" << endl;
	}
}