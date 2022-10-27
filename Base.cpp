#include "Base.h"

void DataInitialization()
{
	//создадим временный файл, в котором будет храниться актуальная информация, т.е. создадим буфер
	ofstream _buf("Baza.txt");

	if (!_buf)
		std::cout << "Ошибка созданиня baza файла!" << endl;

	_buf.close();
}

void Registr() {
	//ввод данных вручную

	//временные переменные
	string _name;
	int _userRecord = 0;
	string _password;
	//int n = 0 ;
	int n = AmountOfData() + 1;

	//открываем  файл и записываем в него данные
	fstream Reg;
	Reg.open("Reg.txt", fstream::in | fstream::out | fstream::app); // открываем для записи в конец app
	ofstream record_("Reg.txt", ios::out | ios::in);// записывает в начало(перезаписывает)
	fstream Rec;
	Rec.open("Record.csv", fstream::in | fstream::out | fstream::app);


	if (record_) {
		record_ << n << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	if (Reg) { // проверка открылся ли файл
		if (Rec) {


			std::cout << "Введите Логин ";
			std::cin >> _name;

			std::cout << "Введите пароль ";
			std::cin >> _password;

			Reg << _name << endl;
			Reg << _password << endl;

			Rec << _name << endl;
			Rec << _userRecord << endl;

			cout << "Регистрация прошла успешно!" << endl;

			std::cout << " ___________________________" << endl;

		}
		else
			std::cout << "Ошибка открытия Record файла!" << endl;
	}
	else
		std::cout << "Ошибка открытия файла!" << endl;

	SaveData();
	Reg.close();
	record_.close();
}

void Etrancy() {
	//ввод данных вручную

	//временные переменные
	string _name;
	//int _userRecord;
	string _password;
	string Login_correct;
	string pass_correct;


	fstream Reg;
	Reg.open("Baza.txt", fstream::in | fstream::out | fstream::app); // открываем для записи в конец app

	if (Reg) {



		while (!Reg.eof()) //Пока не закончатся символы, идем по циклу.
		{

			Reg >> _name; //Передаем данные с файла в переменную.
			cout << _name << endl;

			Reg >> _password;
			cout << _password << endl;
		}

		cout << "Введите свой логин: "; cin >> Login_correct;
		cout << endl;
		//cout << " Login" << Login_correct;
		cout << "Введите свой пароль: "; cin >> pass_correct;
		//cout << " pass" << pass_correct;

		if ((Login_correct == _name) && (pass_correct == _password))
		{
			cout << "Данные введены  верно!" << endl;
		}
		else
		{
			cout << "Пароль или логин введен не правильно!" << endl;

		}

		std::cout << " ___________________________" << endl;

	}
	else
		std::cout << "Ошибка открытия файла!" << endl;


	Reg.close();
}



bool DataCleaning()
{
	//очистка файла для регистрации

	bool clear = false;

	//открываем файл
	fstream _buf("Reg.txt", ios::out);

	if (!_buf)
		std::cout << " Oschibka!" << endl;

	//очищаем
	_buf.clear();

	//проверка, что файл чист
	if (_buf.peek() == EOF)
		clear = true;
	else
		clear = false;

	_buf.close();

	return clear;
}

bool DataCleaning2() //2
{
	//очистка файла для регистрации

	bool clear;

	//открываем файл
	fstream _buf("number_of_users.xml", ios::out);

	if (!_buf)
		std::cout << " Oschibka!" << endl;


	//проверка, что файл чист
	if (_buf.peek() == EOF) {
		clear = true;
		AddZero();

	}
	else
		clear = false;

	_buf.close();

	return clear;
}

int AmountOfData() {

	//выводит количество данных из файла // кол-во пользователей в игре
	ifstream _buf("number_of_users.xml");
	int n;
	if (_buf) {
		_buf >> n;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	_buf.close();

	return n;
}

void AddZero() {
	//ставит изначально значение 0 пользователей


	string _name;
	//int _userRecord;
	string _password;
	int n = 0;

	ofstream record_("number_of_users.xml", ios::out | ios::in);// записывает в начало(перезаписывает)

	if (record_) {
		record_ << n << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;
	record_.close();

}

void SaveData()
{
	//сохранение данных

	ifstream reading("Reg.txt");
	ifstream _reading("Record.csv");
	ofstream record("Baza.txt", ios::out);
	ofstream record_("number_of_users.xml", ios::out);


	if (reading) {
		if (_reading) {
			if (record) {

				//vremennie peremennie
				string _name;
				int _userRecord;
				string _password;
				string name_chek;
				int n;

				reading >> n;
				record_ << n << endl;

				for (int i = 0; i < n; i++) {
					reading >> _name;
					record << _name << endl;

					_reading >> name_chek;

					if (name_chek == _name)
					{
						_reading >> _userRecord;
						record << _userRecord << endl;
					}

					reading >> _password;
					if (i < n - 1)
						record << _password << endl;
					else
						record << _password;
				}

				cout << "Данные сохраены в файле" << " Baza" << endl;

			}
			else
				std::cout << "Ошибка открытия буферного файла!" << endl;
		}
		else
			std::cout << "Ошибка открытия  файла!Record.csv" << endl;
	}
	else
		std::cout << "Ошибка открытия  файла!Reg.txt" << endl;
	record.close();
	reading.close();
	_reading.close();
}


