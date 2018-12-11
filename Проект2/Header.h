#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <clocale>
#include <Windows.h>
#include <fstream>
#include <string>
#include <ctime>
#include <conio.h>
#include <sstream>
#include <stdlib.h>
#include "Listh.h"
#include <iomanip>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h> 
#include <typeinfo>
using namespace std;
class Admin {
protected:
	char password[30];
	char login[30];
	int root;
public:
	void set() {
		cout << "Введите логин: ";
		cin >> this->login;
		cout << "Введите пароль: ";
		cin >> this->password;
		cin >> this->root;
	}
	void print(int a) {
		if (strcmp(this->login, "admin") == 0 && strcmp(this->password, "admin") == 0) { return; }
		cout << "Логин пользователя: " << this->login << endl;
		cout << "Пароль пользователя: " << this->password << endl;
	}
	Admin() {
		this->root = 1;
	}
	int compare(char *log, char *pas) {
		if (strcmp(this->login, log) == 0 && strcmp(this->password, pas) == 0) {
			return this->root;
		}
		else cout << "Kek";
		return 0;
	}
};
class Bank {
protected:
	char nameofbank[30];
public:
	void set();
	void print(int a);
	Bank() {
		this->begin = NULL;
		this->end = NULL;
	}
	int selectSearchCriteria();
	void search(int a, int choice, char *input);
	int selectEditCriteria();
	void edit(int choice);
	int selectFiltrCriteria();
	void filtr(int choice, int a, int minAge, int maxAge);
	int creditPrint();
	//int selectFiltrCriteria();
	//void filtr(int choice, int a, int minAge, int maxAge);

private:
	friend class Credit;
	class Credittype {
	public:
		friend class Credit;
		char creditname[30];
		float percent;
		Credittype *next;
		Credittype() {
			this->percent = NULL;
		}
	};
	Credittype *end;
	Credittype *begin;
};
class Company {
protected:
	friend class Credit;
	char nameofcompany[30];
	char specialization[30];
	float income;
	float outcome;
	int rep;
public:
	Company() {
		this->outcome = NULL;
		this->rep = NULL;
		this->income = NULL;
		this->begin = NULL;
		this->end = NULL;
	}
	void set();
	void print(int a);
	int selectSearchCriteria();
	void search(int a, int choice, char *input);
	int selectEditCriteria();
	void edit(int choice);
	int selectFiltrCriteria();
	void filtr(int choice, int a, int minAge, int maxAge);
	float analis(float *p,string *s);
	void sort(Company &obj, Company &obj1);
	int printC(int a);
private:
	class Debt {
	public:
		friend class Credit;
		char nameofdebt[30];
		float sumofdebt;
		Debt *next;
	public:
		Debt() {
			this->sumofdebt = NULL;
		}
	};
	Debt *begin;
	Debt *end;
};
class Credit :public Bank{
	protected:
		Company company;
		Credittype credittype;
		float sum;
		int times;
		char purpose[30];
		char localTime[30];
	public:
		Credit() {
			this->sum = NULL;
			this->times = NULL;
		}
		void takeCredit(Company &company, Bank &bank,int a,float money,int times);
		void print(int a);
};
int onlyint();
char* onlystring(int N);
void load(char *str);