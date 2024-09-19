#include<iostream>
#include<functional>
using namespace std;

int main()
{
	negate<int> n1;
	cout<<n1(50)<<endl;//-50
	
	plus<int> p1;
	cout << p1(2, 8)<<endl;
	greater<int> g;
	cout << g(9, 98);
}