#include "Header.h"
void Company::set() {
	int a = 1;
	cout << "Название компании: ";
	cin >> this->nameofcompany;
	cout << "Специализация компании";
	cin >> this->specialization;
	cout << "Доход: ";
	cin >> this->income;
	cout << "Долги: ";
	while (a) {
		system("cls");
		cout << "Есть ли у компании долги?" << endl;
		cout << "1.Да" << endl;
		cout << "2.Нет" << endl;
		int x;
		cin >> x;
		switch (x) {
		case 1: a = 0; break;
		case 2:return; break;
		default:cout << "Выберите да, либо нет" << endl; break;
		}
	}
	while (a == 0) {
		if (this->begin == NULL) {
			Debt *debt = new Debt;
			cout << "Кому должна: ";
			cin >> debt->nameofdebt;
			cout << "Сумма долга: ";
			cin >> debt->sumofdebt;
			debt->next = NULL;
			begin = end = debt;
		}
		else {
			Debt *debt = new Debt;
			cout << "Кому должна: ";
			cin >> debt->nameofdebt;
			cout << "Сумма долга: ";
			cin >> debt->sumofdebt;
			debt->next = NULL;
			end->next = debt;
			end = debt;
		}
		system("cls");
		cout << "Продолжить?" << endl;
		cout << "1.Да" << endl;
		cout << "2.Нет" << endl;
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
			cout << "| Название компании |" << " Специализация компании |" << " Доходы компании |" << " Долгов на сумму |" << endl;
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
		cout << "\t\t\tЗдесь выводятся компании, прошедшие анализ" << endl;
	}
	if (this->rep == 2) {
		cout << "Название компании: " << this->nameofcompany << endl;
		cout << "Специализацию компании: " << this->specialization << endl;
		cout << "Доходы компании: " << this->income << endl;
		return 1;
	}
	else return 0;
}
int Company::selectSearchCriteria() {
	int choice;
	cout << "По чем ищем?" << endl;
	cout << "1.По названию компании" << endl;
	cout << "2.По специализации компании" << endl;
	cout << "3.По доходам компании" << endl;
	choice = onlyint();
	return choice;
}

//функция поиска продукта
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
			cout << "| Название компании |" << " Специализация компании |" << " Доходы компании |" << " Долгов на сумму |" << endl;
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

//выбор критерия для редактирования
int Company::selectEditCriteria() {
	int choice;
	cout << "Что будем редактировать?" << endl;
	cout << "1.Название компании" << endl;
	cout << "2.Специализацию компании" << endl;
	cout << "3.Доход компании" << endl;
	cout << "4.Вcе" << endl;
	choice = onlyint();
	return choice;
}

//функция редактирования данных
void Company::edit(int choice) {
	switch (choice) {
	case 1:
	{
		cout << "Редактируемое Название компании: " << this->nameofcompany << endl;
		cout << "Новое Название компании: ";
		cin >> this->nameofcompany;
		break;
	}
	case 2:
	{
		cout << "Редактируемая Специализация компании: " << this->specialization << endl;
		cout << "Новая Специализация компании: ";
		cin >> this->specialization;
		break;
	}
	case 3:
	{
		cout << "Редактируемый доход компании: " << this->income << endl;
		cout << "Новое доход компании: ";
		cin >> this->income;
		break;
	}
	case 4:
	{
		cout << "Редактируемое Название компании: " << this->nameofcompany << endl;
		cout << "Новое Название компании: ";
		cin >> this->nameofcompany;
		cout << "Редактируемая Специализация компании: " << this->specialization << endl;
		cout << "Новая Специализация компании: ";
		cin >> this->specialization;
		cout << "Редактируемый доход компании: " << this->income << endl;
		cout << "Новое доход компании: ";
		cin >> this->income;
		break;
	}
	}
}
int Company::selectFiltrCriteria() {
	int choice;
	system("cls");
	cout << "Меню фильтрации" << endl;
	cout << "1.Фильтрация по доходам" << endl;
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
float Company::analis(float *p,string *s) {
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
				cout << "| Название компании |" << " Специализация компании |" << " Доходы компании |" << " Долгов на сумму |" << endl;
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