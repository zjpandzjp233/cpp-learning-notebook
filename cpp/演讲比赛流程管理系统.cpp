#include<iostream>
#include<fstream>
using namespace std;
#define zjp "zhongjiping"
#define ze "2899828783@qq.com"
class father
{
public:
	int greater(int a,int b)
	{
		if (a == b)
		{
			return 0;
		}
		if(a>b)
		{
			return a;
		}
		else
		{
			return b;
		}
	}
};
class son:public father
{
public:
	int lower(int a, int b)
	{
		if (a == b)
		{
			return 0;
		}
		if (a < b)
		{
			return a;
		}
		else
		{
			return b;
		}
	}
};
class ��֪ʶ
{
public:
	int newK(father*& f)
	{
		return f->greater(3, 9);
	}
};
int main()
{
	ofstream of;
	of.open("file.csv", ios::out | ios::app);//������˵��ios::app ��Ҫ�������ļ�ĩβ׷�����ݣ��� ios::ate �������ļ��е�����λ�ý��ж�д��������Ĭ�϶�дλ�ñ����õ��ļ�ĩβ��
	of << 54654854<<',';
	of << 546554 << ',';
	of << 654854 << ',';
	of << endl;
	of << 54654561854 << ',';
	of << 546542454 << ',';
	of << 654851111111114 << ',';
	of << 654851111111114 << ',';
	of.close();


	//cout << ze;

	father* f=new father();
	son* s = (son*)f;//����ָ��ת���� ��������Ľӿ�ʱ��
	//cout << s->greater(3, 6) << endl;

	father* f2 = new father();
	��֪ʶ x;
	//cout<<x.newK(f2);


	ofstream o;
	o.open("1.txt", ios::out);
	//o << "dfsfdsfsf 5484848484";
	o.close();
	ifstream i4;
	i4.open("1.txt", ios::in);
	
	string s7="";
	i4 >> s7;
	// cout << i4.good();0
	cout << s7 << endl;
	cerr << s7;
	if (i4.get() == EOF)//get�ɶ�ȡ�����ַ�������EOF���ж��ļ��Ƿ�Ϊ��
	{
		cout << "empty";
	}
	//Ҳ�����ã�file.good() �ĺ����ǣ�����ļ��� file ����������״̬�������Ǵ򿪵ġ��ѵ����ļ�ĩβ�����˴��󣩣���ñ��ʽ�Ľ��Ϊ flase


	system("pause");
	return 0;
	
}