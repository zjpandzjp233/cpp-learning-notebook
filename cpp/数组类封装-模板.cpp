#include<iostream>
#include<string>
using namespace std;

template<class t>
class myArry
{
public:
	t* pAdrress;
	int capacity;
	int size;
	myArry(int c)
	{
		capacity = c;
		size = 0;
		pAdrress = new t[c];
	}
	myArry(const myArry& m)
	{
		this->capacity = m.capacity;
		this->size = m.size;
		this->pAdrress = new t[m.capacity];
		for (int i = 0; i < this->size; i++)
		{
			this->pAdrress[i] = m.pAdrress[i];
		}
	}
	myArry& operator=(const myArry& m)//const防止myArry在函数过程被改，  也可以通过const来重载函数
	{
		//判断原来有没有数据，如果有先释放，再=过去，避免=错误吧
		if (this->pAdrress != nullptr)
		{
			delete[] pAdrress;
			pAdrress = nullptr;
			this->capacity = 0;
			this->size = 0;
		}
		this->capacity = m.capacity;
		this->size = m.size;
		this->pAdrress = new t[m.capacity];
		for (int i = 0; i < this->size; i++)
		{
			this->pAdrress[i] = m.pAdrress[i];
		}
		return *this;

	}
	void pushBack(const t& tt)//尾插法
	{
		if (capacity == size)
		{
			return;
		}
		pAdrress[size] = tt;
		size++;
	}
	void popBack()//尾删法
	{
		if (size == 0)
		{
			return;
		}
		size--;
	}
	t& operator[](int index)
	{
		if(index<=size-1)
		{
			return pAdrress[index];
		}
		cout << size<< endl; exit(0);
	}
	~myArry()
	{
		if (pAdrress != nullptr)
		{
			delete[] pAdrress;
			pAdrress = nullptr;
		}
	}
};
class person
{
public:
	string name;
	int age;
};
int test0000()
{
	myArry<int>m(3);
	m.pushBack(9);
	m.pushBack(8);
	m.pushBack(7);
	m.popBack();
	cout << m[1];

	person p;
	p.name = "paodjf";
	myArry<person>l(3);
	l.pushBack(p);

	return 0;

}

int main()
{
	 test0000();
	system("pause");
	return 0;
}