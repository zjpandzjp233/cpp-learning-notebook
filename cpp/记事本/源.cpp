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
				while (getline(ifs, bufs))//这里将-.-文件内容传给了bufs
				{
					cout << bufs << endl;
				}
			}
		}
		ofs.open(name, ios::app);
		cout << endl << "身份码" <<name<< "输入中：";
		getline(cin, cins);		//cin >> cins;
		if (cins == "清空")
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
			cout << "ERROR：文件打开失败,请给程序管理员权限。" << endl;
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
void 质数(int max)
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
			else { result++; cout << "找到质数: " << a << endl; b = 0; }
		} while (b);
		a++;
		b = 1;
	} while (a <= max);
	cout << endl << max<<"内共有:  " << result << "个质数" << endl;

}
void 质数测速()
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

				cout0 = static_cast<double>(result) / 9592;//在C++中，当进行整数除法时，结果会向下取整。这意味着，如果除法的操作数都是整数类型，那么结果也将是整数类型，
				//如果你希望得到一个浮点数结果，可以将其中一个操作数或两个操作数都转换为浮点数类型，
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
	//std::cout << "程序执行时间：" << duration.count() << " 毫秒" << std::endl;
	cout << "单核质数跑分： " << duration.count() /100<<"（基准分：100）" << endl;
}
int main()
{
 


		LPCSTR folderName = "C:\\堆本";
		BOOL result = CreateDirectoryA(folderName, NULL);//创建文件夹
		if (result == TRUE) {
			cout << "应用数据库创建成功。" << endl;
		}

	cout << " ___________________________________________________"<<endl;
	cout << "|                    版本：1.1                      |" << endl;
	cout << "|                   程序名： 堆本                   |" << endl;
	cout << "|               说明：输入后按回车存档              |" << endl;
	cout << "|          应用需要管理员权限,*结尾自动换行         |" << endl;
	cout << "————————————————————————————————————————————————————" << endl;
	system("pause");
	cout << "请输入身份码（大于零的数）：" << endl;
	cin >> name;

	if (name == "8888")
	{
		质数测速();
		system("pause");
		return 0;
	}

	int num;
	std::string str =name; // 假设字符串只包含数字
	// 检查字符串是否只包含数字
	bool isNumber = true;
	for (char c : str) {//一种循环语句的写法，用于遍历字符串 str 中的每个字符，并将每个字符赋值给变量 c。
		if (!std::isdigit(c)) {
			isNumber = false;
			break;
		}
	}
	if (isNumber) {
		 num = std::stoi(str); // 将字符串转换为整数
	}
	else { num = 0; }
	if (num >= 100000)
	{
		质数(num);
		system("pause");
	}
	
	name = "C:\\堆本\\" + name+"-.-";
	system("cls");
	WriteCore();
	return 0;
}


