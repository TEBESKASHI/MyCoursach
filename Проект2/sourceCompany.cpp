#include "Header.h"
void Company::set() {
	int a = 1;
	cout << "�������� ��������: ";
	strcpy(this->nameofcompany, onlystring(20));
	cout << "������������� ��������";
	strcpy(this->specialization, onlystring(20));
	cout << "�����: ";
	this->income = onlyint();
	cout << "�����: ";
	while (a) {
		system("cls");
		cout << "���� �� � �������� �����?" << endl;
		cout << "1.��" << endl;
		cout << "2.���" << endl;
		int x;
		x = onlyint();
		switch (x) {
		case 1: a = 0; break;
		case 2:return; break;
		default:cout << "�������� ��, ���� ���" << endl; break;
		}
	}
	while (a == 0) {
		if (this->begin == NULL) {
			Debt *debt = new Debt;
			cout << "���� ������: ";
			strcpy(debt->nameofdebt, onlystring(15));
			cout << "����� �����: ";
			debt->sumofdebt = onlyint();
			debt->next = NULL;
			begin = end = debt;
		}
		else {
			Debt *debt = new Debt;
			cout << "���� ������: ";
			cout << "���� ������: ";
			strcpy(debt->nameofdebt, onlystring(15));
			cout << "����� �����: ";
			debt->sumofdebt = onlyint();
			debt->next = NULL;
			end->next = debt;
			end = debt;
		}
		system("cls");
		cout << "����������?" << endl;
		cout << "1.��" << endl;
		cout << "2.���" << endl;
		int x;
		x = onlyint();
		switch (x) {
		case 1: break;
		case 2:a = 1; break;
		}
	}
}
void Company::print(int a) {
		Debt *debt = this->begin;
		float sum = 0;
		while (debt != NULL) {
			sum += debt->sumofdebt;
			debt = debt->next;
		}
		if (a == 1) {
			cout << "|```````````````````|" << "````````````````````````|" << "`````````````````|" << "`````````````````|" << endl;
			cout << "| �������� �������� |" << " ������������� �������� |" << " ������ �������� |" << " ������ �� ����� |" << endl;
			cout << "|```````````````````|" << "````````````````````````|" << "`````````````````|" << "`````````````````|" << endl;
		}
		if (a == 2) {
			cout << "|" << setw(19) << this->nameofcompany << "|" << setw(24) << this->specialization << "|" << setw(17) << this->income << "|" << setw(17) << sum << "|" << endl;
			cout << "|```````````````````|" << "````````````````````````|" << "`````````````````|" << "`````````````````|" << endl;
		}
		if (a == 3) {
			cout << "|" << setw(19) << this->nameofcompany << "|" << setw(24) << this->specialization << "|" << setw(17) << this->income << "|" << setw(17) << sum << "|" << endl;
			cout << "`````````````````````" << "`````````````````````````" << "``````````````````" << "``````````````````" << endl;
		}
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
	choice = onlyint();
	return choice;
}

//������� ������ ��������
void Company::search(int a,int choice, char *input) {
	if (begin != NULL) {
		Debt *debt = begin;
		float sum = 0;
		while (debt != NULL) {
			sum += debt->sumofdebt;
			debt = debt->next;
		}
		if (a == 1) {
			cout << "|```````````````````|" << "````````````````````````|" << "`````````````````|" << "`````````````````|" << endl;
			cout << "| �������� �������� |" << " ������������� �������� |" << " ������ �������� |" << " ������ �� ����� |" << endl;
			cout << "|```````````````````|" << "````````````````````````|" << "`````````````````|" << "`````````````````|" << endl;
		}
		if (a == 2) {
			switch (choice) {
			case 1:
			{
				if (strcmp(this->nameofcompany, input) == 0) {
					cout << "|" << setw(19) << this->nameofcompany << "|" << setw(24) << this->specialization << "|" << setw(17) << this->income << "|" << setw(17) << sum << "|" << endl;
					cout << "|```````````````````|" << "````````````````````````|" << "`````````````````|" << "`````````````````|" << endl;
				}
				break;
			}
			case 2:
			{
				if (strcmp(this->specialization, input) == 0) {
					cout << "|" << setw(19) << this->nameofcompany << "|" << setw(24) << this->specialization << "|" << setw(17) << this->income << "|" << setw(17) << sum << "|" << endl;
					cout << "|```````````````````|" << "````````````````````````|" << "`````````````````|" << "`````````````````|" << endl;
				}
				break;
			}
			case 3:
			{
				int inputInteger = atoi(input);
				if (this->income == inputInteger) {
					cout << "|" << setw(19) << this->nameofcompany << "|" << setw(24) << this->specialization << "|" << setw(17) << this->income << "|" << setw(17) << sum << "|" << endl;
					cout << "|```````````````````|" << "````````````````````````|" << "`````````````````|" << "`````````````````|" << endl;
				}
				break;
			}
			}
		}
		if (a == 3) {
			switch (choice) {
			case 1:
			{
				if (strcmp(this->nameofcompany, input) == 0) {
					cout << "|" << setw(19) << this->nameofcompany << "|" << setw(24) << this->specialization << "|" << setw(17) << this->income << "|" << setw(17) << sum << "|" << endl;
					cout << "`````````````````````" << "`````````````````````````" << "``````````````````" << "``````````````````" << endl;
				}
				break;
			}
			case 2:
			{
				if (strcmp(this->specialization, input) == 0) {
					cout << "|" << setw(19) << this->nameofcompany << "|" << setw(24) << this->specialization << "|" << setw(17) << this->income << "|" << setw(17) << sum << "|" << endl;
					cout << "`````````````````````" << "`````````````````````````" << "``````````````````" << "``````````````````" << endl;
				}
				break;
			}
			case 3:
			{
				int inputInteger = atoi(input);
				if (this->income == inputInteger) {
					cout << "|" << setw(19) << this->nameofcompany << "|" << setw(24) << this->specialization << "|" << setw(17) << this->income << "|" << setw(17) << sum << "|" << endl;
					cout << "`````````````````````" << "`````````````````````````" << "``````````````````" << "``````````````````" << endl;
				}
				break;
			}
			}
		}
	}
	else return;
}

//����� �������� ��� ��������������
int Company::selectEditCriteria() {
	int choice;
	cout << "��� ����� �������������?" << endl;
	cout << "1.�������� ��������" << endl;
	cout << "2.������������� ��������" << endl;
	cout << "3.����� ��������" << endl;
	cout << "4.�c�" << endl;
	choice = onlyint();
	return choice;
}

//������� �������������� ������
void Company::edit(int choice) {
	switch (choice) {
	case 1:
	{
		cout << "������������� �������� ��������: " << this->nameofcompany << endl;
		cout << "����� �������� ��������: ";
		strcpy(this->nameofcompany, onlystring(20));
		break;
	}
	case 2:
	{
		cout << "������������� ������������� ��������: " << this->specialization << endl;
		cout << "����� ������������� ��������: ";
		strcpy(this->specialization, onlystring(20));
		break;
	}
	case 3:
	{
		cout << "������������� ����� ��������: " << this->income << endl;
		cout << "����� ����� ��������: ";
		this->income = onlyint();
		break;
	}
	case 4:
	{
		cout << "������������� �������� ��������: " << this->nameofcompany << endl;
		cout << "����� �������� ��������: ";
		strcpy(this->nameofcompany, onlystring(20));
		cout << "������������� ������������� ��������: " << this->specialization << endl;
		cout << "����� ������������� ��������: ";
		strcpy(this->specialization, onlystring(20));
		cout << "������������� ����� ��������: " << this->income << endl;
		cout << "����� ����� ��������: ";
		this->income = onlyint();
		break;
	}
	}
}
int Company::selectFiltrCriteria() {
	int choice;
	system("cls");
	cout << "���� ����������" << endl;
	cout << "1.���������� �� �������" << endl;
	choice = onlyint();
	return choice;
}
bool names(char left[30], char right[30]) {
	return strcmp(left, right) > 0;
}
void Company::sort(Company &obj, Company &obj1) {
	if (names(obj.nameofcompany, obj1.nameofcompany)) {
		std::swap(obj,obj1);
	}
}
float Company::analis(float *p,string *s,int *rep) {
	if (begin != NULL) {
		Debt *debt = begin;
		float sum = 0;
		while (debt != NULL) {
			sum += debt->sumofdebt;
			debt = debt->next;
		}
		(*p) = this->income;
		(*s) = this->nameofcompany;
		this->outcome = sum;
		if ((*p) > sum) {
			this->rep = 2;
		}
		else {
			this->rep = 1;
		}
		(*rep) = this->rep;
		return sum;
	}
	else return 0;
}
void Company::filtr(int choice,  int a, int minAge, int maxAge) {
	if (begin != NULL) {
		Debt *debt = begin;
		float sum = 0;
		while (debt != NULL) {
			sum += debt->sumofdebt;
			debt = debt->next;
		}
		switch (choice) {
		case 1: {
			if (a == 1) {
				cout << "|```````````````````|" << "````````````````````````|" << "`````````````````|" << "`````````````````|" << endl;
				cout << "| �������� �������� |" << " ������������� �������� |" << " ������ �������� |" << " ������ �� ����� |" << endl;
				cout << "|```````````````````|" << "````````````````````````|" << "`````````````````|" << "`````````````````|" << endl;
			}
			else if (a == 2) {
				if (this->income > minAge && this->income < maxAge) {
					cout << "|" << setw(19) << this->nameofcompany << "|" << setw(24) << this->specialization << "|" << setw(17) << this->income << "|" << setw(17) << sum << "|" << endl;
					cout << "|```````````````````|" << "````````````````````````|" << "`````````````````|" << "`````````````````|" << endl;
				}
			}
			else {
				if (this->income > minAge && this->income < maxAge) {
					cout << "|" << setw(19) << this->nameofcompany << "|" << setw(24) << this->specialization << "|" << setw(17) << this->income << "|" << setw(17) << sum << "|" << endl;
					cout << "`````````````````````" << "`````````````````````````" << "``````````````````" << "``````````````````" << endl;
				}
			}
			break;
		}
		}
	}
	else return;
}