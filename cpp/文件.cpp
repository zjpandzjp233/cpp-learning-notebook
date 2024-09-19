#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class person
{
public:
	char  name[100000];
	int age;

};
int main()
{
	/*
	char a[] = { 'c','p','\0' }; //字符串是以空字符（‘\0’）结束的字符数组。
	//空[]自动计算数组大小
	cout << a;//当你使用 cout 打印字符串时，它会从给定的地址开始打印字符，直到遇到空字符为止。
	
	ofstream ofs;
	ofs.open("D:\\text.txt", ios::out);
	ofs << "今天真冷，寒风呼啸"<<endl<<"今天真无聊"<<endl<<"第三行"<<endl;
	ofs.close();
	ifstream ifs;
	ifs.open("D:\\text.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;//由于路径错误、文件名错误等
		return 0;
	}
	char buf[100024] = { 0 };//1024大的空数组 全是空字符\0
    //方法一
	//while (ifs >> buf)//这里右移运算符会一行一行读数据，读完返回false。 ifs >> buf这个代码运行完就跳到下一行代码，这里循环反复运行会一行一行往下读数据//写入buf每一行都是覆盖全部的
	//{//ifs >> buf这个操作会读取文件中的一个单词（由空格、制表符或换行符分隔的字符串），而不是一整行
	//	cout << buf << endl;
	//}
	//方法二
	//cout << "sizeof(buf)：" << sizeof(buf) << endl;//1024
	//cout << buf << endl;//空
	//while (ifs.getline(buf,sizeof(buf)))//一次读取一整行//第二遍不会运行，因为上面ifs已经读到最后一行，这里继续读最后一行，false
	//{
	//	cout << buf << endl;
	//}
	//方法三
	string bufs;
	while (getline(ifs,bufs))
	{
		cout << bufs<<endl;
	}
	ifs.close();
	//方法四
	//char c;
	//while ((c != ifs.get()) != EOF)//EOF文件尾 Eed of file
	//{
	//	cout << c;
	//}
	*/
	ofstream ofs2("person.txt", ios::out | ios::binary);
	//ofs2.open("person.txt", ios::out | ios::binary);
	person p = { "zhangshang",5 };
	ofs2.write((const char*)&p, sizeof(person));
	ofs2.close();
	ifstream ifs2;
	ifs2.open("person.txt", ios::in | ios::binary);
	if (!ifs2.is_open())
	{
		cout << "文件打开失败" << endl;
		return 0;
	}
	ifs2.read(( char*)&p, sizeof(person));
	cout << p.age <<"\t" << p.name << endl;
	ifs2.close();
	
	system("pause");
	return 0;
}