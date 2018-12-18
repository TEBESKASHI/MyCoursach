#include "Header.h"
List<Admin>adm;
void setcur(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};
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
			if (k < 6) {
				cout << number;
				int x = (int)number - 48;
				all = all * 10 + x;
				k++;
			}
		}
		else if (number == 8 && k != 0) {
			cout << "\b \b";
			k--;
			all = (all - all % 10) / 10;
		}
		else if (number == '\n') { break; }
	} while (number != 13);
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
void sortMenu(List<Bank> &bn,List<Company> &cmp) {
	while (1) {
		system("cls");
		cout << "1.���������� �� ���������" << endl;
		cout << "2.���������� �� ������" << endl;
		cout << "0.�����" << endl;
		int x;
		x = onlyint();
		switch (x) {
		case 1: {
			bn.sort();
			break;
		}
		case 2:cmp.sort(); break;
		case 0:return; break;
		default:cout << "��� ������ ������ ����" << endl; break;
		}
	}
}
void bankMenu(Bank &bank,List<Credit> &cr) {
	Admin admin;
	Credit credit;
	char str[20];
	strcpy(str, bank.bankname());
	while (1) {
		system("cls");
		load("���� ���������� ������");
		cout << "\t\t\t\t\t\t\t\t\t\t\t����: " <<str<< endl;
		cout << "1.���� �������� � �����" << endl;
		cout << "2.������ �������� ��������" << endl;
		cout << "3.������� ����� (������ �������)" << endl;
		cout << "0.�����" << endl;
		int x;
		x = onlyint();
		switch (x) {
		case 1: {
			system("cls");
			bank.creditPrint(0);
			system("pause");
			break; }
		case 2: {
			system("cls");
			cr.printSingle(bank.bankname());
			system("pause");
			break; }
		case 3: {
			system("cls");
			int sum;
			sum = cr.bisnesSingle(bank.bankname());
			cout << "������� �����: " << sum << endl;
			system("pause");
			break; }
		case 0:system("cls"); return; break;
		default:system("cls"); cout << "��� ������ ������ ����" << endl; break;
		}
	}
}
void userMenu(List<Admin> &adm) {
	Admin admin;
	while (1) {
		system("cls");
		cout << "1.�������� ������������" << endl;
		cout << "2.������ �������������" << endl;
		cout << "3.������� ������������" << endl;
		cout << "0.�����" << endl;
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
			cout << "������� ����� ������������, �������� ������� �������: ";
			del = onlyint();
			del++;
			cout << "�� �������:" << endl;
			adm.deleteElement(del);
			system("pause");
			break; }
		case 0:system("cls"); return; break;
		default:system("cls"); cout << "��� ������ ������ ����" << endl; break;
		}
	}
}
int analiz(List<Company> &cmp,List<Bank> &bn,List<Credit> &cr) {
	Company company;
	Bank bank;
	Credit credit;
	while (1) {
		system("color 0F");
		load("���� �������");
		cout << "\t\t\t\t\t���� �������" << endl;
		cout << "1.������ ������������������" << endl;
		cout << "2.����� ������" << endl;
		cout << "3.�������� �������" << endl;
		cout << "4.��������� ���� ������ (������ �������)" << endl;
		cout << "0.�����" << endl;
		int x;
		x = onlyint();
		switch (x) {
		case 1:
		{
			int size=cmp.getSize();
			if (size < 1) {
				system("cls");
				cout << "��� �������� ��� �������" << endl;
				system("pause");
				break;
			}
			int rep = 0;
			company = cmp.perebor();
			float sum;
			float p=0;
			string s;
			sum=company.analis(&p,&s,&rep);
			if (sum < p) {
				cout << "\t\t\t\t\t��������������� �������� " << s << " ���� ������ \n\t\t\t\t\t��������� ������ ������� � ������� �� ����� ��� " << p - sum << endl;
			}
			else {
				cout << "\t\t\t\t\t�������� " << s << " �� ����� ����� ������ � ��������� �����, \n\t\t\t\t\t���� �� ������� ��� ���� ����� �� ����� " << sum << " \n\t\t\t\t\t���� �� ������� ���� ����� � " << p << " �� " << sum + p << endl;
			}
			system("pause");
			break;
		}
		case 2: {
			int h = 0;
			float money;
			int times;
			int rep=0;
			int size = bn.getSize();
			if (size < 1) {
				system("cls");
				cout << "��� ������, ��� �� ������ ����� ������" << endl;
				system("pause");
				break;
			}
			bank = bn.perebor();
			h=bank.creditPrint(1);
			if (h == 0) {
				system("cls");
				cout << "� ����� ��� ��������" << endl;
				system("pause");
				continue;
			}
			float sum;
			float p = 0;
			int num = 0;
			string s;
			company = cmp.perebors(&num);
			sum = company.analis(&p, &s, &rep);
			if (rep != 2) {
				system("cls");
				cout << "��� �������� �� ����� ����� ������" << endl;
				system("pause");
				break;
			}
			company = cmp.needed(num);
			while (true) {
				cout << "�����: ";
				money = onlyint();
				if (money < p - sum) {
					break;
				}
				else cout << "�� �� ������ ����� � ������ ������, ���: " << p - sum << endl;
			}
			cout << "������� ����: ";
			times = onlyint();
			system("cls");
			credit.takeCredit(company,bank,h,money,times);
			cr.addLastElement(credit);
			break;
		}
		case 3: {
			system("cls");
			cr.print();
			system("pause");
			break;
		}
		case 4: {
			system("cls");
			int sum;
			sum = cr.bisnes();
			cout << "������� ������: " << sum << endl;
			system("pause");
			break; }
		case 0:return 0; break;
		}
	}
}
int editMenu(List<Company> &cmp, List<Bank> &bn) {
	Company company;
	Bank bank;
	while (1) {
		system("cls");
		load("���� ��������������");
		cout << "1.�������������� ��������" << endl;
		cout << "2.�������������� ������" << endl;
		cout << "0.�����" << endl;
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
		case 0:system("cls"); return 0; break;
		default:system("cls"); cout << "��� ������ ������ ����"; break;
		}
	}
}
int searchMenu(List<Company> &cmp, List<Bank> &bn) {
	Company company;
	Bank bank;
	while (1) {
		system("cls");
		load("���� ������");
		cout << "1.����� �� ���������" << endl;
		cout << "2.����� ������" << endl;
		cout << "0.�����" << endl;
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
		case 0:system("cls"); return 0; break;
		default:system("cls"); cout << "��� ������ ������ ����"; break;
		}
	}
}
int delMenu(List<Company> &cmp, List<Bank> &bn) {
	while (1) {
		system("cls");
		load("���� ��������");
		cout << "1.�������� ��������" << endl;
		cout << "2.�������� ������" << endl;
		cout << "0.�����" << endl;
		int x;
		x = onlyint();
		switch (x) {
		case 1: {
			system("cls");
			int del;
			cmp.print();
			cout << "������� ����� ��������, ������� ������� �������: ";
			del = onlyint();
			cout << "�� �������:" << endl;
			cmp.deleteElement(del);
			system("pause");
			break; }
		case 2: {
			system("cls"); 	int del;
			bn.print();
			cout << "������� ����� �����, ������� ������� �������: ";
			del = onlyint();
			cout << "�� �������:" << endl;
			bn.deleteElement(del); system("pause");
			break;
		}
		case 0:system("cls"); return 0; break;
		default:system("cls"); cout << "��� ������ ������ ����"; break;
		}
	}
}
int printMenu(List<Company> &cmp, List<Bank> &bn) {
	while (1) {
		system("cls");
		load("���� ������");
		cout << "1.�������� ��������" << endl;
		cout << "2.�������� ������" << endl;
		cout << "0.�����" << endl;
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
		case 0:system("cls"); return 0; break;
		default:system("cls"); cout << "��� ������ ������ ����"; break;
		}
	}
}
int addMenu(List<Company> &cmp,List<Bank> &bn) {
	while (1) {
		Bank bank;
		Company company;
		system("cls");
		load("���� ����������");
		cout << "1.���������� ��������" << endl;
		cout << "2.���������� �����" << endl;
		cout << "0.�����" << endl;
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
			system("pause");
			break;
		}
		case 0:system("cls"); return 0; break;
		default:system("cls"); cout << "��� ������ ������ ����"; break;
		}
	}
}
void user(List<Company> &cmp, List<Bank> &bn, List<Credit> &cr) {
	while (1) {
		load("���� ������������");
		cout << "1.��������" << endl;
		cout << "2.�����" << endl;
		cout << "3.����������" << endl;
		cout << "4.�������� �������" << endl;
		cout << "5.��������� ����� (������ �������)" << endl;
		cout << "0.�����" << endl;
		int x;
		x = onlyint();
		switch (x) {
		case 1: {
			system("cls");
			printMenu(cmp, bn);
			system("pause");
			break;
		}
		case 2: {
			system("cls");
			searchMenu(cmp, bn);
			system("pause");
			break;
		}
		case 3: {
			system("cls");
			cmp.filtr();
			system("pause");
			break;
		}
		case 4: {
			system("cls");
			cr.print();
			system("pause");
			break;
		}
		case 5: {
			system("cls");
			int sum;
			sum = cr.bisnes();
			cout << "������� ������: " << sum << endl;
			system("pause");
			break; }
		case 0:return; break;
		default:system("cls"); cout << "��� ������ ������ ����" << endl; break;
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
		load("���� ��������������");
		cout << "1.����������" << endl;
		cout << "2.��������" << endl;
		cout << "3.��������������" << endl;
		cout << "4.��������" << endl;
		cout << "5.������ ������������������" << endl;
		cout << "6.�����" << endl;
		cout << "7.����������" << endl;
		cout << "8.����������" << endl;
		cout << "9.��������� � ����" << endl;
		cout << "10.���������� ��������������" << endl;
		cout << "0.�����" << endl;
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
		case 7: {
			cmp.filtr();
			break;
		}
		case 4:
		{
			printMenu(cmp,bn);
			break;
		}
		case 9:
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
		case 3:editMenu(cmp,bn); break;
		case 8: {
			sortMenu(bn,cmp);
			break;
		}
		case 5: {analiz(cmp,bn,cr); break; }
		case 0:
		{
			system("cls");
			if (a == 0) {
				while (1) {
					cout << "�� ������ ��������� ���������\n������� ���?" << endl;
					cout << "1.��" << endl;
					cout << "2.���" << endl;
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
					default:system("cls"); cout << "��� ������ ������ ����" << endl; break;
					}
				}
			}
			return 0;
			break;
		}
		case 10:userMenu(adm); break;
		default:
		{
			cout << "�������� ������������ ����� ����" << endl; break;
		}
		}

	}
	system("pause");
	return 0;
}
void load(char *str) {
	system("cls");
	string st = "";
	st = str;
	string k = "";
	int i = 0;
	while (i < st.length()) {
		setcur(0, 0);
		Sleep(50);
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
		system("cls");
		adm.saveA("Admin.txt");
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdOut, BACKGROUND_GREEN | BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_INTENSITY);
		string str = "";
		Beep(600, 200);
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
	bn.downloadInfo(bank,"BankDatabase.txt");
	cmp.downloadInfo(company,"CompanyDatabase.txt");
	cr.downloadInfo(credit,"CreditDatabase.txt");
	SetConsoleCtrlHandler(CtrlHandler, TRUE);
	adm.downloadInfoA(admin,"Admin.txt");
	adm.print();
	while (1) {
		cout << "1.����" << endl;
		cout << "2.�����" << endl;
		int i;
		i = onlyint();
		switch (i) {
		case 1: {
			cout << "������� �����: ";
			char log[20];
			strcpy(log,onlystring(20));
			cout << "������� ������: ";
			char pas[20];
			strcpy(pas, onlystring(20));
			int i = adm.compare(log, pas);
			if (i == 1) {
				system("cls");
				user(cmp,bn,cr);
			}
			else if (i == 2) {
				system("cls");
				menu(adm,cmp,bn,cr);
			}
			else {
				int k = 0;
				bank = bn.compare(log, pas, &k);
				if (k == 5) {
					bankMenu(bank,cr);
				}
				else {
					system("cls"); cout << "��������� ������������ ����� ������" << endl;
				}
			}
			break; }
		case 2:adm.saveA("Admin.txt"); exit(0); break;
		default:system("cls"); cout << "��� ������  ������ ����" << endl; break;
		}
	}
	system("pause");
}