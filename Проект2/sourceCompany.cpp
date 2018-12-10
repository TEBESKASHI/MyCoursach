#include "Header.h"
void Company::set() {
	Debt deb;
	int a=0;
	cout << "������� �������� ��������: ";
	cin >> this->nameofcompany;
	cout << "������� ������������� ��������: ";
	cin >> this->specialization;
	cout << "������� ������ ��������: ";
	cin >> this->income;
	cout << "���� ����� � ��������?" << endl;
	cout << "1.��" << endl;
	cout << "2.���" << endl;
	int x;
	cin >> x;
	switch (x) {
	case 1: {
		while (true) {
			int a = deb.set();
			debt.addLastElement(deb);
			debt.print();
			if (a == 0) {
				break;
			}
		}
		break; }
	case 2:return; break;
	}

}
void Company::print() {
	cout << "�������� ��������: " << this->nameofcompany << endl;
	cout << "������������� ��������: " << this->specialization << endl;
	cout << "������ ��������: " << this->income << endl;
	debt.print();
}
int Company::printC(int a) {
	if (a == 0) {
		cout << "\t\t\t����� ��������� ��������, ��������� ������" << endl;
	}
	if (this->rep == 2) {
		cout << "�������� ��������: " << this->nameofcompany << endl;
		cout << "������������� ��������: " << this->specialization << endl;
		cout << "������ ��������: " << this->income << endl;
		return 1;
	}
	else return 0;
}
int Company::selectSearchCriteria() {
	int choice;
	cout << "�� ��� ����?" << endl;
	cout << "1.�� �������� ��������" << endl;
	cout << "2.�� ������������� ��������" << endl;
	cout << "3.�� ������� ��������" << endl;
	cin >> choice;
	return choice;
}

//������� ������ ��������
void Company::search(int choice, char *input) {
	switch (choice) {
	case 1:
	{
		if (strcmp(this->nameofcompany, input) == 0) {
			print();
		}
		break;
	}
	case 2:
	{
		if (strcmp(this->specialization, input) == 0) {
			print();
		}
		break;
	}
	case 3:
	{
		int inputInteger = atoi(input);
		if (this->income== inputInteger) {
			print();
		}
		break;
	}
	}
}

//����� �������� ��� ��������������
int Company::selectEditCriteria() {
	int choice;
	cout << "��� ����� �������������?" << endl;
	cout << "1.�������� ��������" << endl;
	cout << "2.������������� ��������" << endl;
	cout << "3.����� ��������" << endl;
	cout << "4.�c�" << endl;
	cin >> choice;
	return choice;
}

//������� �������������� ������
void Company::edit(int choice) {
	switch (choice) {
	case 1:
	{
		cout << "������������� �������� ��������: " << this->nameofcompany << endl;
		cout << "����� �������� ��������: ";
		cin >> this->nameofcompany;
		break;
	}
	case 2:
	{
		cout << "������������� ������������� ��������: " << this->specialization << endl;
		cout << "����� ������������� ��������: ";
		cin >> this->specialization;
		break;
	}
	case 3:
	{
		cout << "������������� ����� ��������: " << this->income << endl;
		cout << "����� ����� ��������: ";
		cin >> this->income;
		break;
	}
	case 4:
	{
		cout << "������������� �������� ��������: " << this->nameofcompany << endl;
		cout << "����� �������� ��������: ";
		cin >> this->nameofcompany;
		cout << "������������� ������������� ��������: " << this->specialization << endl;
		cout << "����� ������������� ��������: ";
		cin >> this->specialization;
		cout << "������������� ����� ��������: " << this->income << endl;
		cout << "����� ����� ��������: ";
		cin >> this->income;
		break;
	}
	}
}
int Company::selectFiltrCriteria() {
	int choice;
	system("cls");
	cout << "���� ����������" << endl;
	cout << "1.���������� �� �������" << endl;
	cin >> choice;
	return choice;
}
float Debt::sumdobt() {
	return this->sumofdebt;
}
bool names(char left[30], char right[30]) {
	return strcmp(left, right) > 0;
}
void Company::sort(Company &obj, Company &obj1) {
	if (names(obj.nameofcompany, obj1.nameofcompany)) {
		std::swap(obj.nameofcompany, obj1.nameofcompany);
		std::swap(obj.income, obj1.income);
		std::swap(obj.rep, obj1.rep);
		std::swap(obj.outcome, obj1.outcome);
	}
}
int Company::analis(float *p,string *s) {
	float sum;
	sum = debt.analis();
	(*p) = this->income;
	(*s) = this->nameofcompany;
	this->outcome = sum;
	if ((*p) > sum) {
		this->rep = 2;
	}
	return sum;
}
void Company::filtr(int choice,  int a, int minAge, int maxAge) {
	switch (choice) {
	case 1: {
		if (a == 1) {
			cout << "|`````````|" << "```````````|" << endl;
			cout << "| ��������|" << "   ������  |" << endl;
		}
		else if (a == 2) {
			if (this->income > minAge && this->income < maxAge) {
				cout << "|`````````|" << "```````````|" << endl;
				cout << "|" << setw(9) << this->nameofcompany << "|" << setw(11) << this->income << "|" << endl;
			}
		}
		else {
			if (this->income > minAge && this->income < maxAge) {
				cout << "|`````````|" << "```````````|" << endl;
				cout << "|" << setw(9) << this->nameofcompany << "|" << setw(11) << this->income << "|" << endl;
				cout << "``````````" << "`````````````" << endl;
			}
		}
		break;
	}
	}
}