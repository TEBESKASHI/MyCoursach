template <typename T>
class List {
public:
	List();
	~List();
	void addFirstElement(T data);
	void addLastElement(T data);
	void deleteFirstElement();
	void insertElement(T data, int index);
	void deleteElement(int index);
	void deleteLastElement();
	void clearList();
	void saveA(char *path);
	void encryption();
	void downloadInfoA(T data, char *path);
	void decrypt();
	int getSize() { return size; }
	void downloadInfo(T data, char *path);
	void save(char *path);
	void print();
	void sort();
	void search();
	void edit();
	void filtr();
	int analis();
	void printC();
	int compare(char *log, char *pas);
	T perebor() {
		Node<T> *p = first;
		print();
		int number;
		int a = 0;
		int k = getSize();
		cout << "������� �����: ";
		cin >> number;
		number--;
		cout << endl;
		while (number >= k) {
			cout << "��� ������ ������, ��������� ����: ";
			cin >> number;
			number--;
			system("cls");
		}
		while (a != number) {
			p = p->pNext;
			a++;
		}
		return p->data;
	}
	T perebor(int *delelem) {
		Node<T> *p = first;
		printC();
		int number;
		int a = 0;
		int k = getSize();
		cin >> number;
		(*delelem) = number;
		number--;
		cout << endl;
		while (number >= k) {
			cout << "��� ������ ������, ��������� ����: ";
			cin >> number;
			number--;
			system("cls");
		}
		while (a != number) {
			p = p->pNext;
			a++;
		}
		return p->data;
	}
private:
	template<typename T>
	class Node {
	public:
		Node *pNext;
		T data;
		Node(T data = T(), Node *pNext = NULL) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int size; //���������� ��������� � ����������� ������
	Node<T> *first;
};
template<typename T>
int List<T>::compare(char *log, char *pas) {
	int i = 0;
	{
		Node<T> *p = first;
		while (p != NULL)
		{
			i = p->data.compare(log, pas);
			if (i != NULL) {
				break;
			}
			p = p->pNext;
		}
	}
	return i;
}
template<typename T>
int List<T>::analis() {
	float i = 0;
	{
		Node<T> *p = first;
		while (p != NULL)
		{
			i += p->data.sumdobt();
			p = p->pNext;
		}
	}
	return i;
}
//�������� �� �����
template<typename T>
void List<T>::downloadInfoA(T data, char *path) {
	decrypt();
	ifstream fin;
	fin.open(path);
	if (!fin.is_open()) {
		cout << "Openning Error" << endl;
	}
	else {
		clearList();
		while (fin.read((char*)&data, sizeof(T))) {
			addLastElement(data);
		}
	}
	fin.close();
}

//���������� � ����
template<typename T>
void List<T>::saveA(char *path) {
	ofstream fout;
	Node<T> *p = first;
	fout.open(path, ios_base::out | ios_base::trunc);
	if (!fout.is_open()) {
		cout << "Openning Error" << endl;
	}
	else {
		while (p != NULL) {
			fout.write((char*)&p->data, sizeof(T));
			p = p->pNext;
		}
	}
	fout.close();
	encryption();
}

//����������
template<typename T>
void List<T>::encryption() {
	string result = ""; //������ - ���������
	string key = "key"; //������ - ���� 
	string key_on_s = "";
	bool flag;
	int x = 0, y = 0; //���������� ������ ������� �� ������� ��������
	int registr = 0; //������� �������
	char dublicat; //�������� ��������� �����
				   //������������ ������� �������� �� �������� ��������
	int shift = 0;
	char **tabula_recta = new char *[26]; //������� ��������
	for (int i = 0; i < 26; i++)
		tabula_recta[i] = new char[26];
	string alfabet = "abcdefghijklmnopqrstuvwxyz"; //������� ��������
												   //������������ �������
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
		{
			shift = j + i;
			if (shift >= 26) shift = shift % 26;
			tabula_recta[i][j] = alfabet[shift];
		}
	setlocale(LC_ALL, "Russian");//������ �����
	string s;
	ifstream in("Admin.txt");
	while (in) {
		std::getline(in, s);
	}
	in.close();
	for (int i = 0; i < s.length(); i++)
	{
		key_on_s += key[i % key.length()];
	}
	//���������� ��� ������ �������
	for (int i = 0; i < s.length(); i++)
	{
		//���� ����������� ������
		if (((int)(s[i]) < 65) || ((int)(s[i]) > 122))
			result += s[i];
		else
		{
			//����� � ������ ������� ������, ������������ � ������� �����
			int l = 0;
			flag = false;
			//���� �� ������ ������
			while ((l < 26) && (flag == false))
			{
				//���� ������ ������
				if (key_on_s[i] == tabula_recta[l][0])
				{
					//���������� � � ����� ������
					x = l;
					flag = true;
				}
				l++;
			}
			//��������� �������� ������� ��������� �����
			if (((int)(s[i]) <= 90) && ((int)(s[i]) >= 65))
			{
				dublicat = (char)((int)(s[i]) + 32);
				registr = 1;
			}
			else
			{
				registr = 0;
				dublicat = s[i];
			}
			l = 0;
			flag = false;
			//���� �� ������ ������� � ������ ������ � �������� ������
			while ((l < 26) && (flag == false))
			{
				if (dublicat == tabula_recta[0][l])
				{
					//���������� ����� �������
					y = l;
					flag = true;
				}
				l++;
			}
			//����������� ������� ����� �� ���������
			if (registr == 1)
			{
				//�������� ������ �� �������������� �������
				dublicat = char((int)(tabula_recta[x][y]) - 32);
				result += dublicat;
			}
			else
				result += tabula_recta[x][y];
		}
	}
	ofstream fout;
	fout.open("Admin.txt", ios_base::out | ios_base::trunc);
	fout << result;
	fout.close();
}

//����������
template<typename T>
void List<T>::decrypt()
{
	string result = ""; //������ - ���������
	string key = "key"; //������ - ���� 
	string key_on_s = "";
	bool flag;
	int x = 0, y = 0; //���������� ������ ������� �� ������� ��������
	int registr = 0; //������� �������
	char dublicat; //�������� ��������� �����
				   //������������ ������� �������� �� �������� ��������
	int shift = 0;
	char **tabula_recta = new char *[26]; //������� ��������
	for (int i = 0; i < 26; i++)
		tabula_recta[i] = new char[26];
	string alfabet = "abcdefghijklmnopqrstuvwxyz"; //������� ��������
												   //������������ �������
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
		{
			shift = j + i;
			if (shift >= 26) shift = shift % 26;
			tabula_recta[i][j] = alfabet[shift];
		}
	setlocale(LC_ALL, "Russian");
	string s;
	ifstream in("Admin.txt");
	getline(in, s);
	in.close();
	//������������ ������, ������ �����������, ��������� �� ���������� �����
	for (int i = 0; i < s.length(); i++)
	{
		key_on_s += key[i % key.length()];
	}
	//������������ ��� ������ �������
	for (int i = 0; i < s.length(); i++)
	{
		//���� ������������� ������
		if (((int)(s[i]) < 65) || ((int)(s[i]) > 122))
			result += s[i];
		else
		{
			//����� � ������ ������� ������, ������������ � ������� �����
			int l = 0;
			flag = false;
			//���� �� ������ ������
			while ((l < 26) && (flag == false))
			{
				//���� ������ ������
				if (key_on_s[i] == tabula_recta[l][0])
				{
					//���������� � � ����� ������
					x = l;
					flag = true;
				}
				l++;
			}
			//��������� �������� ������� ��������� �����
			if (((int)(s[i]) <= 90) && ((int)(s[i]) >= 65))
			{
				dublicat = (char)((int)(s[i]) + 32);
				registr = 1;
			}
			else
			{
				registr = 0;
				dublicat = s[i];
			}
			l = 0;
			flag = false;
			//���� �� ������ ������� � x ������ � �������� ������
			while ((l < 26) && (flag == false))
			{
				if (dublicat == tabula_recta[x][l])
				{
					//���������� ����� �������
					y = l;
					flag = true;
				}
				l++;
			}
			//����������� ������� ����� �� ���������
			if (registr == 1)
			{
				//�������� ������ �� �������������� �������
				dublicat = char((int)(tabula_recta[0][y]) - 32);
				result += dublicat;
			}
			else
				result += tabula_recta[0][y];
		}
	}
	ofstream fout;
	fout.open("Admin.txt", ios_base::out | ios_base::trunc);
	fout << result;
}

template<typename T>
List<T>::List() {
	size = 0;
	first = NULL;
}

template<typename T>
List<T>::~List() {
	clearList();
}

//�������� � ����� ������
template<typename T>
void List<T>::addLastElement(T data) {
	if (first == nullptr) {
		first = new Node<T>(data, first);
	}
	else {
		Node<T> *current = this->first;
		while (current->pNext != NULL) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	size++;
}

//����� �� �����
template<typename T>
void List<T>::print() {
	{
		Node<T> *p = first;
		while (p != NULL)
		{
			p->data.print();
			p = p->pNext;
		}
	}
}
template<typename T>
void List<T>::printC() {
	{
		int k = 0;
		int a;
		Node<T> *p = first;
		while (p != NULL)
		{
			a=p->data.printC(k);
			p = p->pNext;
			k++;
		}
	}
}
//����������
template<typename T>
void List<T>::sort() {
	{
		if (first != NULL) {
			Node<T> *p = first;
			Node<T> *pn = first;
			while (p->pNext != NULL)
			{
				pn = p->pNext;
				while (pn != NULL) {
					p->data.sort(p->data, pn->data);
					pn = pn->pNext;
				}
				p = p->pNext;
			}
		}
		else cout << "������ �����������" << endl;
	}
}

//����������
template<typename T>
void List<T>::filtr() {
	{
		Node<T> *p = first;
		int choice = p->data.selectFiltrCriteria();
		cout << "������� �������" << endl;
		int minAge;
		int maxAge;
		cout << "��: ";
		cin >> minAge;
		cout << "��: ";
		cin >> maxAge;
		if (minAge > maxAge) {
			int temp;
			temp = minAge;
			minAge = maxAge;
			maxAge = temp;
		}
		p->data.filtr(choice, 1, minAge, maxAge);
		while (p->pNext != NULL)
		{
			p->data.filtr(choice, 2, minAge, maxAge);
			p = p->pNext;
		}
		p->data.filtr(choice, 3, minAge, maxAge);
	}
}

//��������������
template<typename T>
void List<T>::edit() {
	{
		Node<T> *p = first;
		/*p->data.print();*/
		int choice = p->data.selectEditCriteria();
		cout << "���� ������ ��������?: ";
		int number;
		int h = 0;
		cin >> number;
		number--;
		while (h != number)
		{
			p = p->pNext;
			h++;
		}
		p->data.edit(choice);
	}
}

//�����
template<typename T>
void List<T>::search() {
	{
		Node<T> *p = first;
		int choice;
		choice = p->data.selectSearchCriteria();
		char input[30];
		cout << "������� ������ ��� ������: ";
		cin >> input;
		while (p != NULL)
		{
			p->data.search(choice, input);
			p = p->pNext;
		}
	}
}
//�������� ������� ��������� ������
template<typename T>
void List<T>::deleteFirstElement() {
	Node<T> *temp = first;
	if (temp->pNext != NULL) {
		first = first->pNext;
		delete temp;
		size--;
	}
	else {
		delete temp;
		first = NULL;
		size = 0;
	}
}

//������ ������� ������
template<typename T>
void List<T>::clearList() {
	while (size!=0) {
		deleteFirstElement();
	}
}

//���������� � ������ ������
template<typename T>
void List<T>::addFirstElement(T data) {
	first = new Node<T>(data, first);
	size++;
}

//������� �������� � ������
template<typename T>
void List<T>::insertElement(T data, int index) {
	if (index == 0) {
		cout << "������������ ����" << endl;
	}
	else if (index == 1) {
		addFirstElement(data);
	}
	else {
		Node<T> *prevElem = this->first;
		//������� �������������� � ������ ������� ����� �����
		for (int i = 1; i < index - 1; i++) {
			prevElem = prevElem->pNext;
		}
		Node<T> *newNode = new Node<T>(data, prevElem->pNext);
		prevElem->pNext = newNode;
		size++;
	}
}
//�������� �������� �� �������
template<typename T>
void List<T>::deleteElement(int index) {
	index--;
	if (index < 0) {
		cout << "������������ ����" << endl;
	}
	else if (index == 0) {
		first->data.print();
		deleteFirstElement();
	}
	else {
		int i = getSize();
		i--;
		if (i < index) {
			system("cls");
			cout << "���������� ������� ��, ���� ���" << endl;
			return;
		}
		Node<T> *prevElem = this->first;
		//������� �������������� � ������ ��������� �� ��������� ��.
		for (int i = 1; i < index - 1; i++) {
			prevElem = prevElem->pNext;
		}
		Node<T> *toDelete = prevElem->pNext;
		prevElem->pNext = toDelete->pNext;
		toDelete->data.print();
		delete toDelete;
		size--;
	}
}

//������� ��������� ������� ������
template<typename T>
void List<T>::deleteLastElement() {
	deleteElement(size);
}

//�������� �� �����
template<typename T>
void List<T>::downloadInfo(T data, char *path) {
	ifstream fin;
	fin.open(path);
	if (!fin.is_open()) {
		cout << "Openning Error" << endl;
	}
	else {
		clearList();
		while (fin.read((char*)&data, sizeof(T))) {
			addLastElement(data);
		}
	}
	fin.close();
}

//���������� � ����
template<typename T>
void List<T>::save(char *path) {
	ofstream fout;
	Node<T> *p = first;
	fout.open(path, ios_base::out | ios_base::trunc);
	if (!fout.is_open()) {
		cout << "Openning Error" << endl;
	}
	else {
		while (p != NULL) {
			fout.write((char*)&p->data, sizeof(T));
			p = p->pNext;
		}
	}
	fout.close();
}
