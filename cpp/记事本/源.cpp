#include<iostream>
#include<string>
#include<fstream>
#include <windows.h>
#include <chrono>
using namespace std;
ofstream ofs;
static string name;
ifstream ifs;
string bufs;
void DeleteText()
{
	ofs.open(name, ios::trunc);
	system("cls");
	string empty;
	ofs <<empty ;
	ofs.close();
}
int WriteCore()
{
	Flag:
	string cins;
	int i=0;
	

	while (true)
	{
		if (i == 0)
		{
			i++;
			ifs.open(name, ios::in);
			if (ifs.is_open())
			{
				while (getline(ifs, bufs))//���ｫ-.-�ļ����ݴ�����bufs
				{
					cout << bufs << endl;
				}
			}
		}
		ofs.open(name, ios::app);
		cout << endl << "�����" <<name<< "�����У�";
		getline(cin, cins);		//cin >> cins;
		if (cins == "���")
		{
			ofs.close();
			DeleteText();
			goto Flag;
		}
		system("cls");
		if(!cins.empty())
		{
			if (cins.back() != '*')
			{
				ofs << cins;
			}
			else { ofs << cins << endl; }
		}
		else
		{
			ofs << cins;
		}
		ofs.close();

		ifs.open(name, ios::in);
		if (!ifs.is_open())
		{
			cout << "ERROR���ļ���ʧ��,����������ԱȨ�ޡ�" << endl;
			system("pause");
			return 0;
		}
		if (i == 1)
		{
			i++;
			string temp = bufs;
			bufs += cins;
				cout << bufs << endl;
				bufs = temp;
		}
		while (getline(ifs, bufs))
		{
			cout << bufs << endl;
		}
		ifs.close();
	}

	system("pause");
	return 0;
}
void ����(int max)
{
	int a = 2;
	int m;
	int result = 0;
	bool b = 1;
	do {
		m = a;
		m--;
		do {

			if (m != 1)
			{
				if (a % m != 0)
				{
					m--;
				}
				else if (a % m == 0 && m != 1)
				{
					b = 0;
				}
			}
			else { result++; cout << "�ҵ�����: " << a << endl; b = 0; }
		} while (b);
		a++;
		b = 1;
	} while (a <= max);
	cout << endl << max<<"�ڹ���:  " << result << "������" << endl;

}
void ��������()
{
	int max = 100000;
	int a = 2;
	int m;
	int result = 0;
	bool b = 1;

	double cout0=0.5;
	int cout2 = 0;
	string show;

	auto start = std::chrono::high_resolution_clock::now();
	do {
		m = a;
		m--;
		do {

			if (m != 1)
			{

				
				if (a % m != 0)
				{
					m--;
				}
				else if (a % m == 0 && m != 1)
				{
					b = 0;
				}
			}
			else 
			{
				result++;  b = 0; 

				cout0 = static_cast<double>(result) / 9592;//��C++�У���������������ʱ�����������ȡ��������ζ�ţ���������Ĳ����������������ͣ���ô���Ҳ�����������ͣ�
				//�����ϣ���õ�һ����������������Խ�����һ����������������������ת��Ϊ���������ͣ�
				cout2 = cout0 * 100; 
				for (int i1 = 1; i1 <= cout2; i1++)
				{
					show = show + "*";
				}
				for (int i = 1; i <= 100 - cout2; i++)
				{
					show += "-";
				}
				show = "[" + show;
				show += "]";
				cout << show << endl;
				show = "";
			}
		} while (b);
		a++;
		b = 1;
	} while (a <= max);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> duration = end - start;
	//std::cout << "����ִ��ʱ�䣺" << duration.count() << " ����" << std::endl;
	cout << "���������ܷ֣� " << duration.count() /100<<"����׼�֣�100��" << endl;
}
int main()
{
 


		LPCSTR folderName = "C:\\�ѱ�";
		BOOL result = CreateDirectoryA(folderName, NULL);//�����ļ���
		if (result == TRUE) {
			cout << "Ӧ�����ݿⴴ���ɹ���" << endl;
		}

	cout << " ___________________________________________________"<<endl;
	cout << "|                    �汾��1.1                      |" << endl;
	cout << "|                   �������� �ѱ�                   |" << endl;
	cout << "|               ˵��������󰴻س��浵              |" << endl;
	cout << "|          Ӧ����Ҫ����ԱȨ��,*��β�Զ�����         |" << endl;
	cout << "��������������������������������������������������������������������������������������������������������" << endl;
	system("pause");
	cout << "����������루�������������" << endl;
	cin >> name;

	if (name == "8888")
	{
		��������();
		system("pause");
		return 0;
	}

	int num;
	std::string str =name; // �����ַ���ֻ��������
	// ����ַ����Ƿ�ֻ��������
	bool isNumber = true;
	for (char c : str) {//һ��ѭ������д�������ڱ����ַ��� str �е�ÿ���ַ�������ÿ���ַ���ֵ������ c��
		if (!std::isdigit(c)) {
			isNumber = false;
			break;
		}
	}
	if (isNumber) {
		 num = std::stoi(str); // ���ַ���ת��Ϊ����
	}
	else { num = 0; }
	if (num >= 100000)
	{
		����(num);
		system("pause");
	}
	
	name = "C:\\�ѱ�\\" + name+"-.-";
	system("cls");
	WriteCore();
	return 0;
}


