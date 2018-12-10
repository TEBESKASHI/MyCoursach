#include "Header.h"
//void userMenu(List<Admin> &adm) {
//	Admin admin;
//	while (1) {
//		system("cls");
//		cout << "1.�������� ������������" << endl;
//		cout << "2.������ �������������" << endl;
//		cout << "3.������� ������������" << endl;
//		cout << "4.�����" << endl;
//		int x;
//		cin >> x;
//		switch (x) {
//		case 1: {
//			system("cls");
//			admin.set();
//			adm.addLastElement(admin);
//			system("pause");
//			break; }
//		case 2: {
//			system("cls");
//			adm.print();
//			system("pause");
//			break; }
//		case 3: {
//			system("cls");
//			int del;
//			cout << "������� ����� ������������, �������� ������� �������: ";
//			cin >> del;
//			del++;
//			cout << "�� �������:" << endl;
//			adm.deleteElement(del);
//			system("pause");
//			break; }
//		case 4:system("cls"); return; break;
//		default:system("cls"); cout << "��� ������ ������ ����" << endl; break;
//		}
//	}
//}
int analiz(List<Company> &cmp,List<Bank> &bn,List<Credit> &cr) {
	Company company;
	Bank bank;
	Credit credit;
	while (1) {
		cout << "\t\t\t\t\t���� �������" << endl;
		cout << "1.������ ������������������" << endl;
		cout << "2.����� ������" << endl;
		cout << "0.�����" << endl;
		int x;
		x = onlyint();
		switch (x) {
		case 1:
		{
			company = cmp.perebor();
			float sum;
			float p=0;
			string s;
			sum=company.analis(&p,&s);
			if (sum < p) {
				cout << "\t\t\t\t\t��������������� �������� " << s << " ���� ������ \n\t\t\t\t\t��������� ������ ������� � ������� �� ����� ��� " << p - sum << endl;
			}
			else {
				cout << "\t\t\t\t\t�������� " << s << " �� ����� ����� ������ � ��������� �����, \n\t\t\t\t\t���� �� ������� ��� ���� ����� �� ����� " << sum << " \n\t\t\t\t\t���� �� ������� ���� ����� � " << p << " �� " << sum + p << endl;
			}
			break;
		}
		case 2: {
			int h = 0;
			company = cmp.perebor(&h);
			bank = bn.perebor();
			credit.takeCredit(company,bank,1);
			cr.addLastElement(credit);
			cr.print();
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
		cout << "1.�������������� ��������" << endl;
		cout << "2.�������������� ������" << endl;
		cout << "3.�����" << endl;
		int x;
		cin >> x;
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
		default:system("cls"); cout << "��� ������ ������ ����"; break;
		}
	}
}
int searchMenu(List<Company> &cmp, List<Bank> &bn) {
	Company company;
	Bank bank;
	while (1) {
		system("cls");
		cout << "1.����� ��������" << endl;
		cout << "2.����� ������" << endl;
		cout << "3.�����" << endl;
		int x;
		cin >> x;
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
		default:system("cls"); cout << "��� ������ ������ ����"; break;
		}
	}
}
int delMenu(List<Company> &cmp, List<Bank> &bn) {
	while (1) {
		system("cls");
		cout << "1.�������� ��������" << endl;
		cout << "2.�������� ������" << endl;
		cout << "3.�����" << endl;
		int x;
		cin >> x;
		switch (x) {
		case 1: {
			system("cls");
			int del;
			cout << "������� ����� ��������, ������� ������� �������: ";
			cin >> del;
			cout << "�� �������:" << endl;
			cmp.deleteElement(del);
			system("pause");
			break; }
		case 2: {
			system("cls"); 	int del;
			cout << "������� ����� �����, ������� ������� �������: ";
			cin >> del;
			cout << "�� �������:" << endl;
			bn.deleteElement(del); system("pause");
			break;
		}
		case 3:system("cls"); return 0; break;
		default:system("cls"); cout << "��� ������ ������ ����"; break;
		}
	}
}
int printMenu(List<Company> &cmp, List<Bank> &bn) {
	while (1) {
		system("cls");
		cout << "1.�������� ��������" << endl;
		cout << "2.�������� ������" << endl;
		cout << "3.�������� ��������" << endl;
		cout << "4.�����" << endl;
		int x;
		cin >> x;
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
		default:system("cls"); cout << "��� ������ ������ ����"; break;
		}
	}
}
int addMenu(List<Company> &cmp,List<Bank> &bn) {
	Company company;
	Bank bank;
	while (1) {
		system("cls");
		cout << "1.���������� ��������" << endl;
		cout << "2.���������� �����" << endl;
		cout << "3.�����" << endl;
		int x;
		cin >> x;
		switch (x) {
		case 1: {
			system("cls");
			company.set();
			cmp.addLastElement(company);
			company.print();
			system("pause");
			break; }
		case 2: {
			bank.set();
			bn.addLastElement(bank);
			bank.print();
			system("pause");
			break;
		}
		case 3:system("cls"); return 0; break;
		default:system("cls"); cout << "��� ������ ������ ����"; break;
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
		cout << "1.����������" << endl;
		cout << "2.��������" << endl;
		cout << "3.����������" << endl;
		cout << "4.���� ������(��������)" << endl;
		cout << "5.��������� � ����" << endl;
		cout << "6.�����" << endl;
		cout << "7.��������������" << endl;
		cout << "8.����������" << endl;
		cout << "9.������ ������������������" << endl;
		cout << "10.���������� ��������������" << endl;
		cout << "0.�����" << endl;
		cin >> x;
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
					cout << "�� ������ ��������� ���������\n������� ���?" << endl;
					cout << "1.��" << endl;
					cout << "2.���" << endl;
					int x;
					cin >> x;
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
		//case 10:userMenu(adm); break;
		//default:
		//{
		//	cout << "�������� ������������ ����� ����" << endl; break;
		//}
		}

	}
	system("pause");
	return 0;
}
int onlyint() {
	char number;
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
		else if (number == 8 && k!=0) {
			cout << "\b \b";
			k--;
			all = (all - all % 10) / 10;
		}
		else if (number == '\n') { break; }
	} while (k<15 && number != 13);
	cout << endl;
	return all;
}
void setcur(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};
BOOL WINAPI CtrlHandler(DWORD fdwCtrlType) {
	switch (fdwCtrlType)
	{
	case CTRL_CLOSE_EVENT:
		Beep(600, 200);
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
	string str = "";
	while (str.length()< 35) {
		setcur(0, 0);
		Sleep(70);
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t" << str;
		str += "||";
	}
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	system("color 0F");
	Admin admin;
	List<Admin>adm;
	Company company;
	List<Company>cmp;
	Bank bank;
	List<Bank>bn;
	List<Credit>cr;
	SetConsoleCtrlHandler(CtrlHandler, TRUE);
	admin.set();
	adm.addLastElement(admin);
	adm.print();
	bn.print();
	cmp.print();
	while (1) {
		cout << "1.����" << endl;
		cout << "2.�����" << endl;
		int i;
		i = onlyint();
		switch (i) {
		case 1: {
			cout << "������� �����: ";
			char log[30];
			cin >> log;
			cout << "������� ������: ";
			char pas[30];
			cin >> pas;
			int i = adm.compare(log, pas);
			if (i == 1) {
				system("cls");
				cout << "�� �� �����, ����� ��``�,����������" << endl;
			}
			else if (i == 2) {
				system("cls");
				cout << "����������, �������������" << endl;
				menu(adm,cmp,bn,cr);
			}
			else { system("cls"); cout << "��������� ������������ ����� ������" << endl; }
			break; }
		case 2:adm.saveA("Admin.txt"); exit(0); break;
		default:system("cls"); cout << "��� ������  ������ ����" << endl; break;
		}
	}
	system("pause");
}