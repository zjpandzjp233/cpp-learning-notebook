#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	string s1;
	const char* c = "hello world";//const char* c = "hello world"; 将字符串字面值 "hello world" 的地址赋值给了 c 变量。这意味着 c 变量指向了字符串字面值的第一个字符 'h' 的地址。
	//加const是因为=后面是个字符串常量，只有常字符指针可以指向字符串常量
	string s2(c);
	//cout << s2;

	string s3(s2);//拷贝构造
	//cout << s3;

	//string s999(999, 's');
	//cout << s999;

	string a;//string a='a';报错 
	a = 'a';
	//cout << a;

	string ass;
	ass.assign("assign");
	//cout << ass;

	string aa;
	aa.assign("12345678", 2);//12//与aa.assign(s2, 2)不同，这个是复制后面的//llo world
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
	int i = strFind.find("99");//找不到为-1
	//cout << i<<endl;//1
	i = strFind.rfind("99");
	//cout << i << endl;//7 //rightFind,从右往左查，查到返回该字符串的第一个字符的序列

	strFind.replace(1, 3, "0");//从第一个字符开始的三个字符替换为“000000”
	//cout << strFind << endl;//200000062399

	/*如果调用字符串小于参数字符串，则返回一个负整数。
		如果调用字符串等于参数字符串，则返回0。
		如果调用字符串大于参数字符串，则返回一个正整数。*/
	string str84 = "34";
	string str85 = "33xxxx";
	if (str84.compare(str85) > 0)//比较ascII表,逐个字母比较
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