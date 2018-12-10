#include "Header.h"
void Company::set() {
	Debt deb;
	int a=0;
	cout << "Введите название компании: ";
	cin >> this->nameofcompany;
	cout << "Введите специализацию компании: ";
	cin >> this->specialization;
	cout << "Введите доходы компании: ";
	cin >> this->income;
	cout << "Есть долги у компании?" << endl;
	cout << "1.Да" << endl;
	cout << "2.Нет" << endl;
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
	cout << "Название компании: " << this->nameofcompany << endl;
	cout << "Специализацию компании: " << this->specialization << endl;
	cout << "Доходы компании: " << this->income << endl;
	debt.print();
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
	cin >> choice;
	return choice;
}

//функция поиска продукта
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

//выбор критерия для редактирования
int Company::selectEditCriteria() {
	int choice;
	cout << "Что будем редактировать?" << endl;
	cout << "1.Название компании" << endl;
	cout << "2.Специализацию компании" << endl;
	cout << "3.Доход компании" << endl;
	cout << "4.Вcе" << endl;
	cin >> choice;
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
			cout << "| Название|" << "   Доходы  |" << endl;
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