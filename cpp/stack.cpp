#include<iostream>
#include<vector>
#include<deque>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	int i = 0;
	do
	{
		cout << s.top();
		i++;
		s.pop();
		cout<<"s.size()" << s.size()<<endl;
	} while (i <6);
}
