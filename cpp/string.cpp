#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	string s1;
	const char* c = "hello world";//const char* c = "hello world"; ���ַ�������ֵ "hello world" �ĵ�ַ��ֵ���� c ����������ζ�� c ����ָ�����ַ�������ֵ�ĵ�һ���ַ� 'h' �ĵ�ַ��
	//��const����Ϊ=�����Ǹ��ַ���������ֻ�г��ַ�ָ�����ָ���ַ�������
	string s2(c);
	//cout << s2;

	string s3(s2);//��������
	//cout << s3;

	//string s999(999, 's');
	//cout << s999;

	string a;//string a='a';���� 
	a = 'a';
	//cout << a;

	string ass;
	ass.assign("assign");
	//cout << ass;

	string aa;
	aa.assign("12345678", 2);//12//��aa.assign(s2, 2)��ͬ������Ǹ��ƺ����//llo world
	//cout << aa;

	string aaaaaaaaaa;
	aaaaaaaaaa.assign(10, 'w');
	//cout << aaaaaaaaaa;
	string s9 = "zjp";
	string s999 = "zjpjaidfobasodibf";
	string s0 = "i am ";
	string s000 = "i am ";
	s0.append(s9, 1);//i am jp
	s000.append(s999, 0, 3);//i am zjp
	//cout << s0 << endl;
	//cout << s000 << endl;

	string strFind = "299562399";
	int i = strFind.find("99");//�Ҳ���Ϊ-1
	//cout << i<<endl;//1
	i = strFind.rfind("99");
	//cout << i << endl;//7 //rightFind,��������飬�鵽���ظ��ַ����ĵ�һ���ַ�������

	strFind.replace(1, 3, "0");//�ӵ�һ���ַ���ʼ�������ַ��滻Ϊ��000000��
	//cout << strFind << endl;//200000062399

	/*��������ַ���С�ڲ����ַ������򷵻�һ����������
		��������ַ������ڲ����ַ������򷵻�0��
		��������ַ������ڲ����ַ������򷵻�һ����������*/
	string str84 = "34";
	string str85 = "33xxxx";
	if (str84.compare(str85) > 0)//�Ƚ�ascII��,�����ĸ�Ƚ�
	{
		//cout << "str84>str85" << endl;//str84>str85
	}

	string sss = "123456";
	//cout << sss.at(1);//2
	sss.at(1) = 'x';
	//cout << sss<<endl;//1x3456

	string ss1 = "hello";
	ss1.insert(1, "xxxxxx");
	//cout << ss1 << endl;//hxxxxxxello
	ss1.erase(1, 6);
	//cout << ss1 << endl;//hello

	string stri="zjpzjpabab";
	string abc = stri.substr(0, 6);
	cout << abc << endl;

}