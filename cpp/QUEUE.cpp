#include<iostream>
#include<queue>
using namespace std;
int main()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	while (!q.empty())
	{
		cout <<"dui tou"<< q.front() <<"    size:" <<q.size()<< endl;
		cout << "dui wei" << q.back() << endl;
		q.pop();
		cout << endl;
	}
}