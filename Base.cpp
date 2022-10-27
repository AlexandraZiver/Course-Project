#include "Base.h"

void DataInitialization()
{
	//�������� ��������� ����, � ������� ����� ��������� ���������� ����������, �.�. �������� �����
	ofstream _buf("Baza.txt");

	if (!_buf)
		std::cout << "������ ��������� baza �����!" << endl;

	_buf.close();
}

void Registr() {
	//���� ������ �������

	//��������� ����������
	string _name;
	int _userRecord = 0;
	string _password;
	//int n = 0 ;
	int n = AmountOfData() + 1;

	//���������  ���� � ���������� � ���� ������
	fstream Reg;
	Reg.open("Reg.txt", fstream::in | fstream::out | fstream::app); // ��������� ��� ������ � ����� app
	ofstream record_("Reg.txt", ios::out | ios::in);// ���������� � ������(��������������)
	fstream Rec;
	Rec.open("Record.csv", fstream::in | fstream::out | fstream::app);


	if (record_) {
		record_ << n << endl;
	}
	else
		cout << "������ �������� ��������� �����!" << endl;

	if (Reg) { // �������� �������� �� ����
		if (Rec) {


			std::cout << "������� ����� ";
			std::cin >> _name;

			std::cout << "������� ������ ";
			std::cin >> _password;

			Reg << _name << endl;
			Reg << _password << endl;

			Rec << _name << endl;
			Rec << _userRecord << endl;

			cout << "����������� ������ �������!" << endl;

			std::cout << " ___________________________" << endl;

		}
		else
			std::cout << "������ �������� Record �����!" << endl;
	}
	else
		std::cout << "������ �������� �����!" << endl;

	SaveData();
	Reg.close();
	record_.close();
}

void Etrancy() {
	//���� ������ �������

	//��������� ����������
	string _name;
	//int _userRecord;
	string _password;
	string Login_correct;
	string pass_correct;


	fstream Reg;
	Reg.open("Baza.txt", fstream::in | fstream::out | fstream::app); // ��������� ��� ������ � ����� app

	if (Reg) {



		while (!Reg.eof()) //���� �� ���������� �������, ���� �� �����.
		{

			Reg >> _name; //�������� ������ � ����� � ����������.
			cout << _name << endl;

			Reg >> _password;
			cout << _password << endl;
		}

		cout << "������� ���� �����: "; cin >> Login_correct;
		cout << endl;
		//cout << " Login" << Login_correct;
		cout << "������� ���� ������: "; cin >> pass_correct;
		//cout << " pass" << pass_correct;

		if ((Login_correct == _name) && (pass_correct == _password))
		{
			cout << "������ �������  �����!" << endl;
		}
		else
		{
			cout << "������ ��� ����� ������ �� ���������!" << endl;

		}

		std::cout << " ___________________________" << endl;

	}
	else
		std::cout << "������ �������� �����!" << endl;


	Reg.close();
}



bool DataCleaning()
{
	//������� ����� ��� �����������

	bool clear = false;

	//��������� ����
	fstream _buf("Reg.txt", ios::out);

	if (!_buf)
		std::cout << " Oschibka!" << endl;

	//�������
	_buf.clear();

	//��������, ��� ���� ����
	if (_buf.peek() == EOF)
		clear = true;
	else
		clear = false;

	_buf.close();

	return clear;
}

bool DataCleaning2() //2
{
	//������� ����� ��� �����������

	bool clear;

	//��������� ����
	fstream _buf("number_of_users.xml", ios::out);

	if (!_buf)
		std::cout << " Oschibka!" << endl;


	//��������, ��� ���� ����
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

	//������� ���������� ������ �� ����� // ���-�� ������������� � ����
	ifstream _buf("number_of_users.xml");
	int n;
	if (_buf) {
		_buf >> n;
	}
	else
		cout << "������ �������� ��������� �����!" << endl;

	_buf.close();

	return n;
}

void AddZero() {
	//������ ���������� �������� 0 �������������


	string _name;
	//int _userRecord;
	string _password;
	int n = 0;

	ofstream record_("number_of_users.xml", ios::out | ios::in);// ���������� � ������(��������������)

	if (record_) {
		record_ << n << endl;
	}
	else
		cout << "������ �������� ��������� �����!" << endl;
	record_.close();

}

void SaveData()
{
	//���������� ������

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

				cout << "������ �������� � �����" << " Baza" << endl;

			}
			else
				std::cout << "������ �������� ��������� �����!" << endl;
		}
		else
			std::cout << "������ ��������  �����!Record.csv" << endl;
	}
	else
		std::cout << "������ ��������  �����!Reg.txt" << endl;
	record.close();
	reading.close();
	_reading.close();
}


