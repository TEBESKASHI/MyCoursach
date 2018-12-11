#include "Header.h"
List<Admin>adm;
int onlyint() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	unsigned char number;
	int all = 0;
	int k = 0;
	do
	{
		number = _getch();
		if (isdigit(number) != 0) {
			cout << number;
			int x = (int)number - 48;
			all = all * 10 + x;
			k++;
		}
		else if (number == 8 && k != 0) {
			cout << "\b \b";
			k--;
			all = (all - all % 10) / 10;
		}
		else if (number == '\n') { break; }
	} while (k<8 && number != 13);
	cout << endl;
	return all;
}
char* onlystring(int N) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	unsigned char number;
	char *str = new char[N];
	int k = 0;
	do
	{
		number = _getch();
		if (k < N) {
			if (isdigit(number) == 0 && number != 8 && number != 13) {
				cout << number;
				str[k] = number;
				k++;
			}
		}

		if (number == 8 && k != 0) {
			cout << "\b \b";
			str[k] = '\0';
			k--;
		}
		else if (number == '\n') { break; }
	} while (number != 13);
	cout << endl;
	str[k] = '\0';
	return str;
}
void userMenu(List<Admin> &adm) {
	Admin admin;
	while (1) {
		system("cls");
		cout << "1.Добавить пользователя" << endl;
		cout << "2.Список пользователей" << endl;
		cout << "3.Удалить пользователя" << endl;
		cout << "4.Назад" << endl;
		int x;
		x = onlyint();
		switch (x) {
		case 1: {
			system("cls");
			admin.set();
			adm.addLastElement(admin);
			system("pause");
			break; }
		case 2: {
			system("cls");
			adm.print();
			system("pause");
			break; }
		case 3: {
			system("cls");
			int del;
			cout << "Введите номер пользователя, которого желаете удалить: ";
			del = onlyint();
			del++;
			cout << "Вы удалили:" << endl;
			adm.deleteElement(del);
			system("pause");
			break; }
		case 4:system("cls"); return; break;
		default:system("cls"); cout << "Нет такого пункта меню" << endl; break;
		}
	}
}
int analiz(List<Company> &cmp,List<Bank> &bn,List<Credit> &cr) {
	Company company;
	Bank bank;
	Credit credit;
	while (1) {
		load("Меню анализа");
		cout << "\t\t\t\t\tМеню анализа" << endl;
		cout << "1.Анализ кредитоспособности" << endl;
		cout << "2.Взять кредит" << endl;
		cout << "3.Активные кредиты" << endl;
		cout << "0.Назад" << endl;
		int x;
		x = onlyint();
		switch (x) {
		case 1:
		{
			int rep = 0;
			company = cmp.perebor();
			float sum;
			float p=0;
			string s;
			sum=company.analis(&p,&s,&rep);
			if (sum < p) {
				cout << "\t\t\t\t\tПроанализировав компанию " << s << " было решено \n\t\t\t\t\tРазрешить выдачу кредита в размере не более чем " << p - sum << endl;
			}
			else {
				cout << "\t\t\t\t\tКомпания " << s << " не может взять кредит в настоящее время, \n\t\t\t\t\tПока не погасит все свои долги на сумму " << sum << " \n\t\t\t\t\tЛибо не повысит свой доход с " << p << " до " << sum + p << endl;
			}
			system("pause");
			break;
		}
		case 2: {
			int h = 0;
			float money;
			int times;
			int rep=0;
			company = cmp.perebor(&h);
			bank = bn.perebor();
			h=bank.creditPrint();
			float sum;
			float p = 0;
			string s;
			sum = company.analis(&p, &s, &rep);
			if (rep != 2) {
				system("cls");
				cout << "Эта компания не может взять кредит" << endl;
				system("pause");
				break;
			}
			while (true) {
				cout << "Сумма: ";
				money = onlyint();
				if (money < p - sum) {
					break;
				}
				else cout << "вы не можете взять в кредит больше, чем: " << p - sum << endl;
			}
			cout << "Введите срок: ";
			times = onlyint();
			system("cls");
			credit.takeCredit(company,bank,h,money,times);
			cr.addLastElement(credit);
			system("pause");
			break;
		}
		case 3: {
			system("cls");
			cr.print();
			system("pause");
			break;
		}
		case 0:return 0; break;
		}
	}
}
int editMenu(List<Company> &cmp, List<Bank> &bn) {
	Company company;
	Bank bank;
	while (1) {
		system("cls");
		load("Меню редактирования");
		cout << "1.Редактирование компаний" << endl;
		cout << "2.Редактирование банков" << endl;
		cout << "3.Назад" << endl;
		int x;
		x = onlyint();
		switch (x) {
		case 1: {
			system("cls");
			cmp.edit();
			system("pause");
			break; }
		case 2: {
			system("cls");
			bn.edit();
			system("pause");
			break;
		}
		case 3:system("cls"); return 0; break;
		default:system("cls"); cout << "Нет такого пункта меню"; break;
		}
	}
}
int searchMenu(List<Company> &cmp, List<Bank> &bn) {
	Company company;
	Bank bank;
	while (1) {
		system("cls");
		load("Меню поиска");
		cout << "1.Поиск компаний" << endl;
		cout << "2.Поиск банков" << endl;
		cout << "3.Назад" << endl;
		int x;
		x = onlyint();
		switch (x) {
		case 1: {
			system("cls");
			cmp.search();
			system("pause");
			break; }
		case 2: {
			system("cls");
			bn.search();
			system("pause");
			break;
		}
		case 3:system("cls"); return 0; break;
		default:system("cls"); cout << "Нет такого пункта меню"; break;
		}
	}
}
int delMenu(List<Company> &cmp, List<Bank> &bn) {
	while (1) {
		system("cls");
		load("Меню удаления");
		cout << "1.Удаление компаний" << endl;
		cout << "2.Удаление банков" << endl;
		cout << "3.Назад" << endl;
		int x;
		x = onlyint();
		switch (x) {
		case 1: {
			system("cls");
			int del;
			cout << "Введите номер компании, которую желаете удалить: ";
			del = onlyint();
			cout << "Вы удалили:" << endl;
			cmp.deleteElement(del);
			system("pause");
			break; }
		case 2: {
			system("cls"); 	int del;
			cout << "Введите номер банка, который желаете удалить: ";
			del = onlyint();
			cout << "Вы удалили:" << endl;
			bn.deleteElement(del); system("pause");
			break;
		}
		case 3:system("cls"); return 0; break;
		default:system("cls"); cout << "Нет такого пункта меню"; break;
		}
	}
}
int printMenu(List<Company> &cmp, List<Bank> &bn) {
	while (1) {
		system("cls");
		load("База данных");
		cout << "1.Просмотр компаний" << endl;
		cout << "2.Просмотр банков" << endl;
		cout << "4.Назад" << endl;
		int x;
		x = onlyint();
		switch (x) {
		case 1: {
			system("cls");
			cmp.print();
			system("pause");
			break; }
		case 2: {
			system("cls"); bn.print(); system("pause");
			break;
		}
		case 3: {
			break; }
		case 4:system("cls"); return 0; break;
		default:system("cls"); cout << "Нет такого пункта меню"; break;
		}
	}
}
int addMenu(List<Company> &cmp,List<Bank> &bn) {
	Company company;
	Bank bank;
	while (1) {
		system("cls");
		load("Меню добавления");
		cout << "1.Добавление компании" << endl;
		cout << "2.Добавление банка" << endl;
		cout << "3.Назад" << endl;
		int x;
		x = onlyint();
		switch (x) {
		case 1: {
			system("cls");
			company.set();
			cmp.addLastElement(company);
			system("pause");
			break; }
		case 2: {
			bank.set();
			bn.addLastElement(bank);
			bank.print(1);
			system("pause");
			break;
		}
		case 3:system("cls"); return 0; break;
		default:system("cls"); cout << "Нет такого пункта меню"; break;
		}
	}
}
int menu(List<Admin> &adm, List<Company> &cmp,List<Bank> &bn,List<Credit> &cr) {
	int a = 0;
	Admin admin;
	Company company;
	Bank bank;
	int x;
	while (1) {
		load("Меню администратора");
		cout << "1.Добавление" << endl;
		cout << "2.Удаление" << endl;
		cout << "3.Фильтрация" << endl;
		cout << "4.База данных(Показать)" << endl;
		cout << "5.Сохранить в файл" << endl;
		cout << "6.Поиск" << endl;
		cout << "7.Редактирование" << endl;
		cout << "8.Сортировка" << endl;
		cout << "9.Анализ кредитоспособности" << endl;
		cout << "10.Управление пользователями" << endl;
		cout << "0.Выход" << endl;
		x = onlyint();
		switch (x) {
		case 1:
		{
			addMenu(cmp,bn);
			break;
		}
		case 2:
		{
			delMenu(cmp,bn);
			break;
		}
		case 3: {
			cmp.filtr();
			break;
		}
		case 4:
		{
			printMenu(cmp,bn);
			break;
		}
		case 5:
		{
			a = 1;
			adm.saveA("Admin.txt");
			cmp.save("CompanyDatabase.txt");
			bn.save("BankDatabase.txt");
			break;
		}
		case 6: {
			searchMenu(cmp,bn);
			break;
		}
		case 7:editMenu(cmp,bn); break;
		case 8: {
			cmp.sort();
			break;
		}
		case 9: {analiz(cmp,bn,cr); break; }
		case 0:
		{
			system("cls");
			if (a == 0) {
				while (1) {
					cout << "Вы забыли сохранить изменения\nСделать это?" << endl;
					cout << "1.Да" << endl;
					cout << "2.Нет" << endl;
					int x;
					x = onlyint();
					switch (x) {
					case 1: {
						adm.saveA("Admin.txt");
						cmp.save("CompanyDatabase.txt");
						bn.save("BankDatabase.txt");
						return 0;
						break;
					}
					case 2:adm.saveA("Admin.txt"); return 0; break;
					default:system("cls"); cout << "Нет такого пункта меню" << endl; break;
					}
				}
			}
			return 0;
			break;
		}
		case 10:userMenu(adm); break;
		default:
		{
			cout << "Выберите существующих пункт меню" << endl; break;
		}
		}

	}
	system("pause");
	return 0;
}
void setcur(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};
void load(char *str) {
	system("cls");
	string st = "";
	st = str;
	string k = "";
	int i = 0;
	while (i < st.length()) {
		setcur(0, 0);
		Sleep(30);
		k += st[i];
		cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t" << k;
		i++;
	}
	system("cls");
}
BOOL WINAPI CtrlHandler(DWORD fdwCtrlType) {
	switch (fdwCtrlType)
	{
	case CTRL_CLOSE_EVENT:
		Beep(600, 200);
		adm.saveA("Admin.txt");
		system("cls");
		string str = "";
		while (str.length()< 35) {
			setcur(0, 0);
			Sleep(70);
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t" << str;
			str += "||";
		}
		return TRUE;
	}
}
int main() {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, BACKGROUND_GREEN | BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_INTENSITY);
	string str = "";
	while (str.length()< 35) {
		HANDLE kek = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(kek, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		setcur(0, 0);
		Sleep(70);
		cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t.................................";
		cout << "\n\t\t\t\t\t" << str;
		cout << "\n\t\t\t\t\t`````````````````````````````````";
		str += "||";
	}
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	system("color 0F");
	Admin admin;
	Company company;
	List<Company>cmp;
	Bank bank;
	List<Bank>bn;
	List<Credit>cr;
	Credit credit;
	SetConsoleCtrlHandler(CtrlHandler, TRUE);
	adm.downloadInfoA(admin,"Admin.txt");
	while (1) {
		cout << "1.Вход" << endl;
		cout << "2.Выход" << endl;
		int i;
		i = onlyint();
		switch (i) {
		case 1: {
			cout << "Введите логин: ";
			char log[10];
			strcpy(log,onlystring(10));
			cout << "Введите пароль: ";
			char pas[10];
			strcpy(pas, onlystring(10));
			int i = adm.compare(log, pas);
			if (i == 1) {
				system("cls");
				userMenu(adm);
			}
			else if (i == 2) {
				system("cls");
				menu(adm,cmp,bn,cr);
			}
			else { system("cls"); cout << "Проверьте правильность ввода данных" << endl; }
			break; }
		case 2:adm.saveA("Admin.txt"); exit(0); break;
		default:system("cls"); cout << "Нет такого  пункта меню" << endl; break;
		}
	}
	system("pause");
}