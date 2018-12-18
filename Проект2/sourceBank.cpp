#include "Header.h"
void reverseStr(string& str)
{
	int n = str.length();
	for (int i = 0; i < n / 2; i++)
		swap(str[i], str[n - i - 1]);
}
char* Bank::bankname() {
	return this->nameofbank;
}
void Bank::set() {
	int a = 1;
	cout << "�������� �����: ";
	strcpy(this->nameofbank, onlystring(18));
	strcpy(this->login,this->nameofbank);
	string s;
	s = this->login;
	reverseStr(s);
	char *cstr = new char[s.length() + 1];
	strcpy(cstr, s.c_str());
	strcpy(this->password,cstr);
	delete[] cstr;
	this->root = 5;
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
			strcpy(credit->creditname, onlystring(15));
			cout << "�������: ";
			credit->percent = onlyint();
			credit->next = NULL;
			begin = end = credit;
		}
		else {
			Credittype *credit = new Credittype;
			cout << "������� �������� �������: ";
			strcpy(credit->creditname, onlystring(15));
			cout << "�������: ";
			credit->percent = onlyint();
			credit->next = NULL;
			end->next = credit;
			end = credit;
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
bool nameb(char left[30], char right[30]) {
	return strcmp(left, right) > 0;
}
int Bank::SelectSortCriteria() {
	cout << "1.����������� �� �������� �����" << endl;
	cout << "0.�����" << endl;
	int choice;
	choice = onlyint();
	return choice;
}
void Bank::sort(Bank &obj, Bank &obj1, int choice) {
	switch (choice) {
	case 1: {
		if (nameb(obj.nameofbank, obj1.nameofbank)) {
			std::swap(obj, obj1);
		}
		break;
	case 0:return; break;
	}
	}
}
int Bank::creditPrint(int type) {
	Credittype *credittype = this->begin;
	int h = 0;
	if (this->begin != NULL) {
		cout << "|````````````````````|" << "`````````|" << endl;
		cout << "|  �������� �������  |" << " ������� |" << endl;
		cout << "|````````````````````|" << "`````````|" << endl;
		while (credittype->next != NULL) {
			cout << "|" << setw(20) << credittype->creditname << "|" << setw(9) << credittype->percent << "|" << endl;
			cout << "|````````````````````|" << "`````````|" << endl;
			credittype = credittype->next;
			h++;
		}
		cout << "|" << setw(20) << credittype->creditname << "|" << setw(9) << credittype->percent << "|" << endl;
		cout << "``````````````````````" << "```````````" << endl;
		h++;
		if (type == 1) {
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
	}
	else {
		cout << "� ����� ��� ��������" << endl;
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
		cout << "|```````````````````|" << "`````````````````````|" << endl;
		cout << "|   �������� �����  |" << " ���������� �������� |" << endl;
		cout << "|```````````````````|" << "`````````````````````|" << endl;
	}
	if (a == 2) {
		cout << "|" << setw(19) << this->nameofbank << "|" << setw(21) << h << "|" << endl;
		cout << "|```````````````````|" << "`````````````````````|" << endl;
	}
	if (a == 3) {
		cout << "|" << setw(19) << this->nameofbank << "|" << setw(21) << h << "|" << endl;
		cout << "`````````````````````" << "``````````````````````" << endl;
	}
}
int Bank::selectSearchCriteria() {
	int choice;
	cout << "�� ��� ����?" << endl;
	cout << "1.�� �������� �����" << endl;
	choice = onlyint();
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
		cout << "|```````````````````|" << "`````````````````````|" << endl;
		cout << "|   �������� �����  |" << " ���������� �������� |" << endl;
		cout << "|```````````````````|" << "`````````````````````|" << endl;
	}
	if (a == 2) {

		switch (choice) {
		case 1:
		{
			if (strcmp(this->nameofbank, input) == 0) {
				cout << "|" << setw(19) << this->nameofbank << "|" << setw(21) << h << "|" << endl;
				cout << "|```````````````````|" << "`````````````````````|" << endl;
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
				cout << "|" << setw(19) << this->nameofbank << "|" << setw(21) << h << "|" << endl;
				cout << "|```````````````````|" << "`````````````````````|" << endl;
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
			cout << "|```````````````````|" << "`````````````````````|" << endl;
			cout << "|   �������� �����  |" << " ���������� �������� |" << endl;
			cout << "|```````````````````|" << "`````````````````````|" << endl;
		}
		else if (a == 2) {
			if (h > minAge && h < maxAge) {
				cout << "|" << setw(19) << this->nameofbank << "|" << setw(21) << h << "|" << endl;
				cout << "|```````````````````|" << "`````````````````````|" << endl;
			}
		}
		else {
			if (h > minAge && h < maxAge) {
				cout << "|" << setw(19) << this->nameofbank << "|" << setw(21) << h << "|" << endl;
				cout << "|```````````````````|" << "`````````````````````|" << endl;
			}
		}
		break;
	}
	}
}