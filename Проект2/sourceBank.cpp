#include "Header.h"
void Bank::set() {
	int a = 0;
	cout << "�������� �����: ";
	cin >> this->nameofbank;
	cout << "������� �����: ";
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
		case 1:continue; break;
		case 2:a = 1; break;
		}
	}
}
void Bank::print() {
	cout << "�������� �����: " << this->nameofbank << endl;
	Credittype *credit = begin;
	while (credit != NULL) {
		cout << "�������� �������: " << credit->creditname << endl;
		cout << "�������: " << credit->percent << endl;
		credit = credit->next;
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
void Bank::search(int choice, char *input) {
	switch (choice) {
	case 1:
	{
		if (strcmp(this->nameofbank, input) == 0) {
			print();
		}
		break;
	}
	}
}

//����� �������� ��� ��������������
int Bank::selectEditCriteria() {
	int choice;
	cout << "��� ����� �������������?" << endl;
	cout << "1.�������� �����: " << endl;
	cin >> choice;
	return choice;
}
void Bank::edit(int choice) {
	switch (choice) {
	case 1:
	{
		cout << "������������� �������� �����: " << this->nameofbank << endl;
		cout << "����� �������� �����: ";
		cin >> this->nameofbank;
		break;
	}
	}
}
//int Bank::selectFiltrCriteria() {
//	int choice;
//	system("cls");
//	cout << "���� ����������" << endl;
//	cout << "1.���������� �� ���������" << endl;
//	cin >> choice;
//	return choice;
//}
//void Bank::filtr(int choice, int a, int minAge, int maxAge) {
//	switch (choice) {
//	case 1: {
//		if (a == 1) {
//			cout << "|`````````|" << "```````````|" << endl;
//			cout << "|   ���   |" << " ��������� |" << endl;
//		}
//		else if (a == 2) {
//			if (this->ProductCost > minAge && this->ProductCost < maxAge) {
//				cout << "|`````````|" << "```````````|" << endl;
//				cout << "|" << setw(9) << this->name << "|" << setw(11) << this->ProductCost << "|" << endl;
//			}
//		}
//		else {
//			if (this->ProductCost > minAge && this->ProductCost < maxAge) {
//				cout << "|`````````|" << "```````````|" << endl;
//				cout << "|" << setw(9) << this->name << "|" << setw(11) << this->ProductCost << "|" << endl;
//				cout << "``````````" << "`````````````" << endl;
//			}
//		}
//		break;
//	}
//	}
//}