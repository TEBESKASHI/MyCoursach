#include "Header.h"
int Debt::set() {
	cout << "������� �������� �����: ";
	cin >> this->nameofdebt;
	cout << "����� �����: ";
	cin >> this->sumofdebt;
	while (1) {
		system("cls");
		cout << "����������?" << endl;
		cout << "1.��" << endl;
		cout << "2.���" << endl;
		int x;
		cin >> x;
		switch (x) {
		case 1:return 1; break;
		case 2:return 0; break;
		default:break;
		}
	}
}
void Debt::print() {
	cout << "�������� �����: " << this->nameofdebt << endl;
	cout << "����� �����: " << this->sumofdebt << endl;
}