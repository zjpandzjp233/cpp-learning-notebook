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
	char a[] = { 'c','p','\0' }; //�ַ������Կ��ַ�����\0�����������ַ����顣
	//��[]�Զ����������С
	cout << a;//����ʹ�� cout ��ӡ�ַ���ʱ������Ӹ����ĵ�ַ��ʼ��ӡ�ַ���ֱ���������ַ�Ϊֹ��
	
	ofstream ofs;
	ofs.open("D:\\text.txt", ios::out);
	ofs << "�������䣬�����Х"<<endl<<"����������"<<endl<<"������"<<endl;
	ofs.close();
	ifstream ifs;
	ifs.open("D:\\text.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;//����·�������ļ��������
		return 0;
	}
	char buf[100024] = { 0 };//1024��Ŀ����� ȫ�ǿ��ַ�\0
    //����һ
	//while (ifs >> buf)//���������������һ��һ�ж����ݣ����귵��false�� ifs >> buf��������������������һ�д��룬����ѭ���������л�һ��һ�����¶�����//д��bufÿһ�ж��Ǹ���ȫ����
	//{//ifs >> buf����������ȡ�ļ��е�һ�����ʣ��ɿո��Ʊ�����з��ָ����ַ�������������һ����
	//	cout << buf << endl;
	//}
	//������
	//cout << "sizeof(buf)��" << sizeof(buf) << endl;//1024
	//cout << buf << endl;//��
	//while (ifs.getline(buf,sizeof(buf)))//һ�ζ�ȡһ����//�ڶ��鲻�����У���Ϊ����ifs�Ѿ��������һ�У�������������һ�У�false
	//{
	//	cout << buf << endl;
	//}
	//������
	string bufs;
	while (getline(ifs,bufs))
	{
		cout << bufs<<endl;
	}
	ifs.close();
	//������
	//char c;
	//while ((c != ifs.get()) != EOF)//EOF�ļ�β Eed of file
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
		cout << "�ļ���ʧ��" << endl;
		return 0;
	}
	ifs2.read(( char*)&p, sizeof(person));
	cout << p.age <<"\t" << p.name << endl;
	ifs2.close();
	
	system("pause");
	return 0;
}