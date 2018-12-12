//шаблон List
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
	int bisnes();
	int getSize() { return size; }
	//для перехода по добавленным элементам
	//index- номер возвращаемого элемента
	T & operator[](const int index);
	void downloadInfo(T data, char *path);
	void save(char *path);
	void print();
	void sort();
	void search();
	void edit();
	void filtr();
	void check();
	int analis();
	int compare(char *log, char *pas);
	T perebor() {
		Node<T> *p = first;
		print();
		int number;
		int a = 0;
		int k = getSize();
		number = onlyint();
		number--;
		cout << endl;
		while (number >= k || number <0) {
			cout << "Нет такого номера, повторите ввод: ";
			number = onlyint();
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
		print();
		int number;
		int a = 0;
		int k = getSize();
		number = onlyint();
		(*delelem) = number;
		number--;
		cout << endl;
		while (number >= k || number<0) {
			cout << "Нет такого номера, повторите ввод: ";
			number = onlyint();
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
		Node * pNext;
		T data;
		Node(T data = T(), Node *pNext = NULL) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int size; //количество элементов в односвязном списке
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

//загрукза из файла
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

//сохранение в файл
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

//шифрование
template<typename T>
void List<T>::encryption() {
	string result = ""; //Строка - результат
	string key = "key"; //Строка - ключ 
	string key_on_s = "";
	bool flag;
	int x = 0, y = 0; //Координаты нового символа из таблицы Виженера
	int registr = 0; //Регистр символа
	char dublicat; //Дубликат прописной буквы
				   //Формирование таблицы Виженера на алфавите латиницы
	int shift = 0;
	char **tabula_recta = new char *[26]; //Таблица Виженера
	for (int i = 0; i < 26; i++)
		tabula_recta[i] = new char[26];
	string alfabet = "abcdefghijklmnopqrstuvwxyz"; //Алфавит латиницы
												   //Формирование таблицы
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
		{
			shift = j + i;
			if (shift >= 26) shift = shift % 26;
			tabula_recta[i][j] = alfabet[shift];
		}
	setlocale(LC_ALL, "Russian");//Чтение файла
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
	//Шифрование при помощи таблицы
	for (int i = 0; i < s.length(); i++)
	{
		//Если нешифруемый символ
		if (((int)(s[i]) < 65) || ((int)(s[i]) > 122))
			result += s[i];
		else
		{
			//Поиск в первом столбце строки, начинающейся с символа ключа
			int l = 0;
			flag = false;
			//Пока не найден символ
			while ((l < 26) && (flag == false))
			{
				//Если символ найден
				if (key_on_s[i] == tabula_recta[l][0])
				{
					//Запоминаем в х номер строки
					x = l;
					flag = true;
				}
				l++;
			}
			//Уменьшаем временно регистр прописной буквы
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
			//Пока не найден столбец в первой строке с символом строки
			while ((l < 26) && (flag == false))
			{
				if (dublicat == tabula_recta[0][l])
				{
					//Запоминаем номер столбца
					y = l;
					flag = true;
				}
				l++;
			}
			//Увеличиваем регистр буквы до прописной
			if (registr == 1)
			{
				//Изменяем символ на первоначальный регистр
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

//дешифровка
template<typename T>
void List<T>::decrypt()
{
	string result = ""; //Строка - результат
	string key = "key"; //Строка - ключ 
	string key_on_s = "";
	bool flag;
	int x = 0, y = 0; //Координаты нового символа из таблицы Виженера
	int registr = 0; //Регистр символа
	char dublicat; //Дубликат прописной буквы
				   //Формирование таблицы Виженера на алфавите латиницы
	int shift = 0;
	char **tabula_recta = new char *[26]; //Таблица Виженера
	for (int i = 0; i < 26; i++)
		tabula_recta[i] = new char[26];
	string alfabet = "abcdefghijklmnopqrstuvwxyz"; //Алфавит латиницы
												   //Формирование таблицы
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
	//Формирование строки, длиной дешифруемой, состоящей из повторений ключа
	for (int i = 0; i < s.length(); i++)
	{
		key_on_s += key[i % key.length()];
	}
	//Дешифрование при помощи таблицы
	for (int i = 0; i < s.length(); i++)
	{
		//Если недешифруемый символ
		if (((int)(s[i]) < 65) || ((int)(s[i]) > 122))
			result += s[i];
		else
		{
			//Поиск в первом столбце строки, начинающейся с символа ключа
			int l = 0;
			flag = false;
			//Пока не найден символ
			while ((l < 26) && (flag == false))
			{
				//Если символ найден
				if (key_on_s[i] == tabula_recta[l][0])
				{
					//Запоминаем в х номер строки
					x = l;
					flag = true;
				}
				l++;
			}
			//Уменьшаем временно регистр прописной буквы
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
			//Пока не найден столбец в x строке с символом строки
			while ((l < 26) && (flag == false))
			{
				if (dublicat == tabula_recta[x][l])
				{
					//Запоминаем номер столбца
					y = l;
					flag = true;
				}
				l++;
			}
			//Увеличиваем регистр буквы до прописной
			if (registr == 1)
			{
				//Изменяем символ на первоначальный регистр
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
void List<T>::check() {
	Node<T> *p = first;
	int h = 1;
	while (p != NULL)
	{
		if (a != 0) {
			p->data.printC(a);
		}
		p = p->pNext;
		h++;
	}
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

//добавить в конец списка
template<typename T>
void List<T>::addLastElement(T data) {
	if (first == NULL) {
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
template<typename T>
int List<T>::bisnes() {
	Node<T> *p = first;
	int sum=0;
	if (p == NULL) {
		cout << "Ничего нету" << endl;
		return 0;
	}
	while (p != NULL)
	{
		sum += p->data.profit();
		p = p->pNext;
	}
	return sum;
}
//вывод на экран
template<typename T>
void List<T>::print() {
	Node<T> *p = first;
	if (p == NULL) {
		cout << "Ничего нету" << endl;
		return;
	}
	p->data.print(1);
	while (p->pNext != NULL)
	{
		p->data.print(2);
		p = p->pNext;
	}
	p->data.print(3);
}

//сортировка
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
		else cout << "Нечего сортировать" << endl;
	}
}

//фильтрация
template<typename T>
void List<T>::filtr() {
	{
		Node<T> *p = first;
		int choice = p->data.selectFiltrCriteria();
		cout << "Введите границы" << endl;
		int minAge;
		int maxAge;
		cout << "ОТ: ";
		minAge = onlyint();
		cout << "До: ";
		maxAge = onlyint();
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

//редактирование
template<typename T>
void List<T>::edit() {
	{
		Node<T> *p = first;
		/*p->data.print();*/
		int choice = p->data.selectEditCriteria();
		cout << "Кого хотите изменить?: ";
		int number;
		int h = 0;
		int k = getSize();
		number = onlyint();
		number--;
		cout << endl;
		while (number >= k || number <0) {
			cout << "Нет такого номера, повторите ввод: ";
			number = onlyint();
			number--;
			system("cls");
		}
		while (h != number)
		{
			p = p->pNext;
			h++;
		}
		p->data.edit(choice);
	}
}

//поиск
template<typename T>
void List<T>::search() {
	{
		Node<T> *p = first;
		int choice;
		choice = p->data.selectSearchCriteria();
		char input[30];
		cout << "Введите данные для поиска: ";
		strcpy(input, onlystring(30));
		p->data.search(1, choice, input);
		while (p->pNext != NULL)
		{
			p->data.search(2, choice, input);
			p = p->pNext;
		}
		p->data.search(3, choice, input);
	}
}
//перегрузка [] для итераций
template<typename T>
T & List<T>::operator[](const int index) {
	int counter = 0;
	Node<T> *current = this->first;
	while (current != nullptr) {
		//если счетчик дошел до нужного индекса,то
		//достаем из этого элемента data
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

//удаление первого элемиента списка
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

//полная очистка списка
template<typename T>
void List<T>::clearList() {
	while (size) {
		deleteFirstElement();
	}
}

//добавление в начало списка
template<typename T>
void List<T>::addFirstElement(T data) {
	first = new Node<T>(data, first);
	size++;
}

//вставка элемента в список
template<typename T>
void List<T>::insertElement(T data, int index) {
	if (index == 0) {
		cout << "Некорректный ввод" << endl;
	}
	else if (index == 1) {
		addFirstElement(data);
	}
	else {
		Node<T> *prevElem = this->first;
		//находим предшествующий и делаем вставку через некст
		for (int i = 1; i < index - 1; i++) {
			prevElem = prevElem->pNext;
		}
		Node<T> *newNode = new Node<T>(data, prevElem->pNext);
		prevElem->pNext = newNode;
		size++;
	}
}
//удаление элемента по индексу
template<typename T>
void List<T>::deleteElement(int index) {
	index--;
	int i = getSize();
	i--;
	if (i < index) {
		system("cls");
		cout << "Невозможно удалить то, чего нет" << endl;
		return;
	}
	if (index < 0) {
		cout << "Невозможно удалить то, чего нет" << endl;
	}
	else if (index == 0) {
		first->data.print(1);
		first->data.print(3);
		deleteFirstElement();
	}
	else {
		Node<T> *prevElem = this->first;
		//находим предшествующий и делаем указатель на удаляемый эл.
		for (int i = 1; i < index - 1; i++) {
			prevElem = prevElem->pNext;
		}
		Node<T> *toDelete = prevElem->pNext;
		prevElem->pNext = toDelete->pNext;
		toDelete->data.print(1);
		toDelete->data.print(3);
		delete toDelete;
		size--;
	}
}

//удалить последний элемент списка
template<typename T>
void List<T>::deleteLastElement() {
	deleteElement(size);
}

//загрузка из файла
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

//сохранение в файл
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

