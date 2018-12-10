#include "Header.h"
int Debt::set() {
	cout << "Введите название долга: ";
	cin >> this->nameofdebt;
	cout << "Сумма долга: ";
	cin >> this->sumofdebt;
	while (1) {
		system("cls");
		cout << "Продолжить?" << endl;
		cout << "1.Да" << endl;
		cout << "2.Нет" << endl;
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
	cout << "Название долга: " << this->nameofdebt << endl;
	cout << "Сумма долга: " << this->sumofdebt << endl;
}