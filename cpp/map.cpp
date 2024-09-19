#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
class compare
{
public:
	bool operator()(int v1, int v2)const
	{
		return v1 > v2;
	}
};

void print(map<int,string,compare> m)
{
	for (map<int, string,compare>::iterator it = m.begin(); it != m.end(); ++it)
	{
		cout << (*it).first; cout << "  ";
		cout << (*it).second;
		cout << endl;
	}
}
int main()
{
	//�������ظ�keyֵ��multimap����
	map<int, string,compare> m; //map<int, string> m;
	m.insert(pair<int, string>(1, "zjp1"));
	m.insert(pair<int, string>(3, "zjp3"));
	m.insert(pair<int, string>(2, "zjp2"));//��������ʽת��
	m.insert(make_pair(0,"zjp0"));
	m[9] = "zjp9";//������[key]ֵ������ʱ��map���Զ�������ӦkeyֵΪ0����
	//cout << m[3]<<endl;
	//print(m);
	//���������=��ֵ������
	// 
	//size���� empty���� swap���� ������
	//insert(elem) clear() erase(pos������)������һ��Ԫ�صĵ�����   erase(begin,end)������һ��Ԫ�صĵ�����    erase(key)

    //find(key),����key�Ƿ���ڣ����ڷ��ص������������ڷ��ء�end����
	//count��key�� ͳ��key�ĸ���

	for (int i = 0; i >= 0 && i < 99; i += 1, i *= i)//������
	{
		//cout << i << endl;
	}


	//multimap <double, int, greater<double>>groupscore;//һ��multimap���������Խ�������
	// ����һ�� multimap�����յ÷ֽ�������
	std::multimap<double, int, std::greater<int>> groupscore;

	// ���һЩ�û��÷���Ϣ
	groupscore.insert({ 98.5, 101 });
	groupscore.insert({ 92.0, 102 });
	groupscore.insert({ 98.5, 103 });
	groupscore.insert({ 87.5, 104 });

	// ���� multimap����ʾ������Ϣ
	for (const auto& pair : groupscore)//��������
	{
		std::cout << "�÷�: " << pair.first << ", �û�ID: " << pair.second << std::endl;
	}



}