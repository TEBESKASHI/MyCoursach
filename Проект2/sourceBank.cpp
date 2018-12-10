#include "Header.h"
void Bank::set() {
	int a = 0;
	cout << "Название банка: ";
	cin >> this->nameofbank;
	cout << "Кредиты банка: ";
	while (a == 0) {
		if (this->begin == NULL) {
			Credittype *credit = new Credittype;
			cout << "Введите название кредита: ";
			cin >> credit->creditname;
			cout << "Процент: ";
			cin >> credit->percent;
			credit->next = NULL;
			begin = end = credit;
		}
		else {
			Credittype *credit = new Credittype;
			cout << "Введите название кредита: ";
			cin >> credit->creditname;
			cout << "Процент: ";
			cin >> credit->percent;
			credit->next = NULL;
			end->next = credit;
			end = credit;
		}
		system("cls");
		cout << "Продолжить?" << endl;
		cout << "1.Да" << endl;
		cout << "2.Нет" << endl;
		int x;
		cin >> x;
		switch (x) {
		case 1:continue; break;
		case 2:a = 1; break;
		}
	}
}
void Bank::print() {
	cout << "Название банка: " << this->nameofbank << endl;
	Credittype *credit = begin;
	while (credit != NULL) {
		cout << "Название кредита: " << credit->creditname << endl;
		cout << "Процент: " << credit->percent << endl;
		credit = credit->next;
	}
}
int Bank::selectSearchCriteria() {
	int choice;
	cout << "По чем ищем?" << endl;
	cout << "1.По названию банка" << endl;
	cin >> choice;
	return choice;
}

//функция поиска продукта
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

//выбор критерия для редактирования
int Bank::selectEditCriteria() {
	int choice;
	cout << "Что будем редактировать?" << endl;
	cout << "1.Название банка: " << endl;
	cin >> choice;
	return choice;
}
void Bank::edit(int choice) {
	switch (choice) {
	case 1:
	{
		cout << "Редактируемый название банка: " << this->nameofbank << endl;
		cout << "Новое название банка: ";
		cin >> this->nameofbank;
		break;
	}
	}
}
//int Bank::selectFiltrCriteria() {
//	int choice;
//	system("cls");
//	cout << "Меню фильтрации" << endl;
//	cout << "1.Фильтрация по стоимости" << endl;
//	cin >> choice;
//	return choice;
//}
//void Bank::filtr(int choice, int a, int minAge, int maxAge) {
//	switch (choice) {
//	case 1: {
//		if (a == 1) {
//			cout << "|`````````|" << "```````````|" << endl;
//			cout << "|   Имя   |" << " Стоимость |" << endl;
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