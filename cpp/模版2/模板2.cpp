#include"son.cpp"//��ȥ��son��cppȻ��Ҳ��ȥ��son��h

template<class T,class B>//��������ʱ����ģ�庯��
void compare(T a, B b)
{
	if (a == b)
	{
		cout << "yyyyyyyyyyyyyy";
	}
	else 
	{
		cout << "nnnnnnn";
	}
}
template<>void compare(person<string, int> a, person<string, int> b)//������compare����ʱ�������������ʵ�ʴ��ݵĲ���������ȷ��ʹ���ĸ��汾�ĺ�����������ݵĲ���������person<string, int>����ô�ͻ�ʹ������ػ��ĺ����汾��
{
	if (a.name == b.name)
	{
		cout << "yyyyyyyyyyyyyy";
	}
	else
	{
		cout << "nnnnnnn";
	}
}
template<class T >
class person2
{
	T m;
};


int main()
{
	//person<string,int> p1;
	//person<string, int> p2;
	//p1.name = "zjp";
	//p2.name = "zjp";
	//compare(p1, p2);
	son<string,int> s1(1);
	cout << s1.m2 << endl;
	cerr << si.m2 << endl;
	system("pause");
	return 0;

}