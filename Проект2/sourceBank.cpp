#include "Header.h"
void Bank::set() {
	int a = 1;
	cout << "�������� �����: ";
	cin >> this->nameofbank;
	cout << "������� �����: ";
	while (a ) {
		system("cls");
		cout << "���� �� ������� � �����?" << endl;
		cout << "1.��" << endl;
		cout << "2.���" << endl;
		int x;
		x = onlyint();
		switch (x) {
		case 1:a = 0; break;
		case 2:return; break;
		}
	}
	while (a == 0) {
		if (this->begin == NULL) {
			Credittype *credit = new Credittype;
			cout << "������� �������� �������: ";
			cin >> credit->creditname;
			cout << "�������: ";
			cin >> credit->percent;
			credit->next = NULL;
			begin = end = credit;
		}
		else {
			Credittype *credit = new Credittype;
			cout << "������� �������� �������: ";
			cin >> credit->creditname;
			cout << "�������: ";
			cin >> credit->percent;
			credit->next = NULL;
			end->next = credit;
			end = credit;
		}
		system("cls");
		cout << "����������?" << endl;
		cout << "1.��" << endl;
		cout << "2.���" << endl;
		int x;
		cin >> x;
		switch (x) {
		case 1: break;
		case 2:a = 1; break;
		}
	}
}
int Bank::creditPrint() {
	Credittype *credittype = this->begin;
	int h = 0;
	if (this->begin != NULL) {
		cout << "|``````````````````|" << "`````````|" << endl;
		cout << "| �������� ������� |" << " ������� |" << endl;
		cout << "|``````````````````|" << "`````````|" << endl;
		while (credittype->next!= NULL) {
			cout << "|" << setw(18) << credittype->creditname << "|" << setw(9) << credittype->percent << "|" << endl;
			cout << "|``````````````````|" << "`````````|" << endl;
			credittype = credittype->next;
			h++;
		}
		cout << "|" << setw(18) << credittype->creditname << "|" << setw(9) << credittype->percent << "|" << endl;
		cout << "````````````````````" << "``````````" << endl;
		h++;
		int x;
		while (true) {
			cout << "����� ������ �� ���������?: ";
			x = onlyint();
			if (x <= h) {
				break;
			}
			else cout << "��� ������� � ����� �������" << endl;
		}
		return x;
	}
	else { cout << "� ����� ��� ��������" << endl; 
	return 0;
	}
}
void Bank::print(int a) {
	Credittype *credittype = this->begin;
	int h = 0;
	while (credittype != NULL) {
		h++;
		credittype = credittype->next;
	}
	if (a == 1) {
		cout << "|````````````````|" << "`````````````````````|" << endl;
		cout << "| �������� ����� |" << " ���������� �������� |" << endl;
		cout << "|````````````````|" << "`````````````````````|" << endl;
	}
	if (a == 2) {
		cout << "|" << setw(16) << this->nameofbank << "|" << setw(21) << h << "|" << endl;
		cout << "|````````````````|" << "`````````````````````|" << endl;
	}
	if (a == 3) {
		cout << "|" << setw(16) << this->nameofbank << "|" << setw(21) << h << "|" << endl;
		cout << "``````````````````" << "``````````````````````" << endl;
	}
}
int Bank::selectSearchCriteria() {
	int choice;
	cout << "�� ��� ����?" << endl;
	cout << "1.�� �������� �����" << endl;
	cin >> choice;
	return choice;
}

//������� ������ ��������
void Bank::search(int a,int choice, char *input) {
	Credittype *credittype = begin;
	int h = 0;
	while (credittype != NULL) {
		h++;
		credittype = credittype->next;
	}
	if (a == 1) {
		cout << "|````````````````|" << "`````````````````````|" << endl;
		cout << "| �������� ����� |" << " ���������� �������� |" << endl;
		cout << "|````````````````|" << "`````````````````````|" << endl;
	}
	if (a == 2) {

		switch (choice) {
		case 1:
		{
			if (strcmp(this->nameofbank, input) == 0) {
				cout << "|" << setw(16) << this->nameofbank << "|" << setw(21) << h << "|" << endl;
				cout << "|````````````````|" << "`````````````````````|" << endl;
			}
			break;
		}
		}
	}
	if (a == 3) {
		switch (choice) {
		case 1:
		{
			if (strcmp(this->nameofbank, input) == 0) {
				cout << "|" << setw(16) << this->nameofbank << "|" << setw(21) << h << "|" << endl;
				cout << "``````````````````" << "``````````````````````" << endl;
			}
			break;
		}
		}
	}
}

//����� �������� ��� ��������������
int Bank::selectEditCriteria() {
	int choice;
	cout << "��� ����� �������������?" << endl;
	cout << "1.�������� �����: " << endl;
	choice = onlyint();
	return choice;
}
void Bank::edit(int choice) {
	switch (choice) {
	case 1:
	{
		cout << "������������� �������� �����: " << this->nameofbank << endl;
		cout << "����� �������� �����: ";
		strcpy(this->nameofbank,onlystring(20));
		break;
	}
	}
}
int Bank::selectFiltrCriteria() {
	int choice;
	system("cls");
	cout << "���� ����������" << endl;
	cout << "1.���������� �� ���������� ����� �������" << endl;
	choice = onlyint();
	return choice;
}
void Bank::filtr(int choice, int a, int minAge, int maxAge) {
	Credittype *credittype = begin;
	int h = 0;
	while (credittype != NULL) {
		h++;
		credittype = credittype->next;
	}
	switch (choice) {
	case 1: {
		if (a == 1) {
			cout << "|````````````````|" << "`````````````````````|" << endl;
			cout << "| �������� ����� |" << " ���������� �������� |" << endl;
			cout << "|````````````````|" << "`````````````````````|" << endl;
		}
		else if (a == 2) {
			if (h > minAge && h < maxAge) {
				cout << "|" << setw(16) << this->nameofbank << "|" << setw(21) << h << "|" << endl;
				cout << "|````````````````|" << "`````````````````````|" << endl;
			}
		}
		else {
			if (h > minAge && h < maxAge) {
				cout << "|" << setw(16) << this->nameofbank << "|" << setw(21) << h << "|" << endl;
				cout << "``````````````````" << "``````````````````````" << endl;
			}
		}
		break;
	}
	}
}