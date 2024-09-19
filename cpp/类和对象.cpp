#include<iostream>
using namespace std;

const double PI =3.1415926;

class circle {
	// 访问权限 ，属性 ，行为
public:
	int r;
	
		double out() {
			return 2 * PI * r;
		}
	
	
};
void loger()
{
	
	int count =0;
	bool done = 1;
	char* p;

		do{
			
			int i=0;
			char chars;
			cin >>chars;
			 p = &chars;
			p[i] = *p;
			if (chars == '*')
			{
				done = 0;
			}
			count++;
			i++;
		} while (done);
	FLAG:
		string cinss;
		cin >> cinss;
		while (cinss == "**")
		{
			for (int i = 1; i <= count; ++i)
			{
				cout << p[i - 1];
			}
		}
		goto FLAG;
		system("pause");
	
}
int main(){
	/*
	circle c1;
	c1.r = 99;
	cout << c1.out() << endl;
	*/

	

	system("pause");
	return 0;
}
