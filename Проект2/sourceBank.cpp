#include "Header.h"
void Bank::set() {
	int a = 1;
	cout << "Название банка: ";
	cin >> this->nameofbank;
	cout << "Кредиты банка: ";
	while (a ) {
		system("cls");
		cout << "Есть ли кредиты в банке?" << endl;
		cout << "1.Да" << endl;
		cout << "2.Нет" << endl;
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
		cout << "| Название кредите |" << " Процент |" << endl;
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
			cout << "Какой кредит вы выбираете?: ";
			x = onlyint();
			if (x <= h) {
				break;
			}
			else cout << "Нет кредита с таким номером" << endl;
		}
		return x;
	}
	else { cout << "В банке нет кредитов" << endl; 
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
		cout << "| Название банка |" << " Количество кредитов |" << endl;
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
	cout << "По чем ищем?" << endl;
	cout << "1.По названию банка" << endl;
	cin >> choice;
	return choice;
}

//функция поиска продукта
void Bank::search(int a,int choice, char *input) {
	Credittype *credittype = begin;
	int h = 0;
	while (credittype != NULL) {
		h++;
		credittype = credittype->next;
	}
	if (a == 1) {
		cout << "|````````````````|" << "`````````````````````|" << endl;
		cout << "| Название банка |" << " Количество кредитов |" << endl;
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

//выбор критерия для редактирования
int Bank::selectEditCriteria() {
	int choice;
	cout << "Что будем редактировать?" << endl;
	cout << "1.Название банка: " << endl;
	choice = onlyint();
	return choice;
}
void Bank::edit(int choice) {
	switch (choice) {
	case 1:
	{
		cout << "Редактируемый название банка: " << this->nameofbank << endl;
		cout << "Новое название банка: ";
		strcpy(this->nameofbank,onlystring(20));
		break;
	}
	}
}
int Bank::selectFiltrCriteria() {
	int choice;
	system("cls");
	cout << "Меню фильтрации" << endl;
	cout << "1.Фильтрация по количеству видов кредита" << endl;
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
			cout << "| Название банка |" << " Количество кредитов |" << endl;
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