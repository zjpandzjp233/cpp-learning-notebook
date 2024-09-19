
using namespace std;
#include<iostream>
#include<thread>
#include<memory>
#include<mutex>
#include<windows.h>
#include<chrono>
#include<condition_variable>//��������
#include<queue>
#include<functional>
#include<vector>
#include<future>
#include<atomic>


timed_mutex m0;



void refInThread(int& a)
{
	a++;
}

void hello(string s)
{
		cout << "hello";
		cout << "world";
		cout << "done";	
		cout << endl << s;
		return;
}
thread t;
class myclass
{
public:
	void func()
	{
		cout << "hello myclass";
	}
};
int c = 0;
void cPlus()
{
	for (int i=1; i <= 2; i++)
	{
		//lock_guard<mutex> lgm(m0);
		 unique_lock<timed_mutex> lgm(m0,defer_lock); //��������ʱ��unique_lock����lgm�ᱻ���٣��Զ��ͷ��������е�����
		 
		 //ʹ��try_lock_for������ָ����ʱ���ڣ�������1�룩��ȡm0����������ɹ���ȡ����try_lock_for����true��
		 if(lgm.try_lock_for(chrono::seconds(2)))//ֻ��timed_mutex����try_lock_for��Ա����ͨmutex��û��try_lock_for
		 {
			 this_thread::sleep_for(chrono::seconds(1));
			 //m0.lock();
			 c += 1;
			 //m0.unlock();
		 }
	}
}
/*                               �޷�����
static once_flag once; 
static Log* log=nullptr;
class Log//����ʵ��
{
	
public:
	
	Log()
	{

	};

	Log(const Log& logs) = delete;

	Log& operator=(const Log& logs) = delete;

	static Log& GetInstance()
	{
		
		call_once(once, init);//ȷ��initֻ������һ��

		return *log;
	}
	static void init()
	{
		if (!log) log = new Log;
	}
	void PrintLog(string msg)
	{

		std::cout << __TIME__ << " " << msg << std::endl;//���ص�ǰʱ�� __TIME__ 

	}
};
*/
std::once_flag flag; // ȫ�ֳ�ʼ����־

void initialize()
{
	std::cout << "Initialization is done." << std::endl;
	// ������Է�����Ҫִ��һ�εĳ�ʼ������
}

void do_work()
{
	while(1)
	{
		Sleep(500);
		std::call_once(flag, initialize); // ȷ��initializeֻ������һ��
		std::cout << "Doing work..." << std::endl;
	}
}


class coutAPP
{
public:
	static void coutApp()//���÷�ʽ����̬��������ͨ������ֱ�ӵ��ã�������Ҫ�������ʵ�������磬�����һ����̬����func()�������ʹ��ClassName.func()����������������object.func()��
	{//ʵ�����ʣ���̬�������ܷ�����ķǾ�̬��Ա����Ϊ���ǲ�����������κ��ض�ʵ��������ֻ�ܷ�����ľ�̬��Ա��
		cout << "CoutApp";
	}
};
condition_variable cv;
queue<int> q9;
mutex m3;
void producer()
{

	for (int i = 0; i <= 10; i++)
	{
		{//����һ���������ڣ������ȵ�������ȫ�������꣨10���������߲ſ��Ի�ȡ��Ȼ������
			unique_lock<mutex> lock11(m3);
			//cv.notify_one();//��һ��wait�������̼߳��빤��
			cv.notify_all();
			q9.push(i);
			cout << "product " << i << " Has been made." << endl;
			
		}
		Sleep(400);
	}
}
void consumer()
{
	bool isEmpty=true;
	while (true)
	{
		unique_lock<mutex> lock1(m3);
		isEmpty = q9.empty();
		cv.wait(lock1, [] { return !q9.empty(); });//�����Ͳ�������//������������ͬʱ����
		Sleep(200);
		cout << "This job has been consumed: " << q9.front() << " " << endl;
		q9.pop();
	}
}
class threadPool
{
threadPool (int num) :isStop(false)
{
	for (int i = 0; i < num; ++i)
	{
		vt.emplace_back
		([this]//���ڷ������Ա
			{
				while (true)
				{
					unique_lock<mutex> lock2(mt3);
					cv3.wait(lock2, [this] {return!(isStop || fq.empty()); });
					if (isStop&&fq.empty())
					{
						return;
					}
					function<void()> task(move(fq.front()));//���⿽������
					//���⣬����fq.front()���ƶ�֮����ܴ���δ����״̬�������ڶ����в�Ӧ���ٴ�ʹ�����������������¸�ֵ�����³�ʼ����
					fq.pop();
					lock2.unlock();
					task();
				}	
			}
		);
	}
}
template<class F,class... Args>
void enqueue(F &&f,Args&&... args)//ʡ��
{
	function<void()>task =
		bind(forward<F>(f), forward<args>(args)...);
	{
		unique_lock<mutex> lock(mt3);
		fq.emplace(move(task));
	}
	cv3.notify_one();
}
~threadPool()
{
	{
		unique_lock<mutex> lock(mt3);
		isStop = true;
	}
	cv3.notify_all();
	for (auto& t : vt)//�߳��޷�����
	{
		t.join();
	}
}
private:
	vector<thread> vt;	
	queue < function<void()>> fq;//function<void()> ��һ���ɵ��õĺ������ͣ�	���������κβ������Ҳ������κ�ֵ��������ǩ���� void()����
	mutex mt3;
	condition_variable cv3;
	bool isStop;

};
int Plus0to1000()
{
	int i = 0;
	for (i; i < 1000; ++i)
	{
		
	}
	return i;
}
void Plus0to2000(promise<int> &P)
{
	int i = 2000;
	P.set_value(i);	
	return;
}
atomic<int> shared_int=0;
void PULSPLUS()
{
	for (int i = 0; i < 2000000; i++)
	{
		shared_int++;
	}
	return;
}
int main()
{
    //thread T1(hello,"done");
	//T1.join();
	//T1.detach();

	//int b = 1;
	//thread t1(refInThread, ref(b));
	//t1.join();
	/*
	myclass m1;
	thread t2;
	t2 = thread(&myclass::func, &m1);
	t2.join();

	shared_ptr<myclass> m2 = make_shared<myclass>();
	thread t3(&myclass::func, m2);
	t3.join();
	
	thread t4(cPlus);
	thread t3(cPlus);
	t4.join();
	t3.join();
	cout << "c=" << c << endl;//c=12436
	coutAPP::coutApp();
	
	std::thread t1(do_work);
	std::thread t2(do_work);
	t1.join();
	t2.join();
	
	std::thread t1(producer);
	std::thread t2(consumer);
	t1.detach();
	t2.join();
	
	int a = 9;
	int b = 10;
	auto Plus = [=](int bb = 99)->int {return a+bb+b; };//[=]���񵽵�a��b�����޸�
	cout << Plus();//118

	future<int> future_result = async(launch::async, Plus0to1000);//�������future_result�Plus0to1000�ź�̨���������������
	cout << Plus0to1000() << endl;//1000
	cout << future_result.get()<< endl;//��������������ͬʱִ���У�get������������Ż������ߡ�//1000

		packaged_task<int()>task(Plus0to1000);//��������װ��task��
		auto GF=task.get_future();
		thread t1(move(task));//������ʼ����
		cout << Plus0to1000()<<endl;//1000
		t1.join();
		cout << GF.get() << endl;//1000
		
		
	promise<int> P;
	auto future_result = P.get_future();
	thread t1(Plus0to2000, ref(P));
	t1.join();
	cout<<future_result.get()<<endl;
	*/
	thread t1(PULSPLUS);
	thread t2(PULSPLUS);//atomic��mutex��һ����
	t1.join();
	t2.join();
	cout << shared_int << endl;//4000000
	return 0;
}






/*
## C++����ָ�룺�����׶��Ľ���

**C++����ָ��**��һ������Ķ����������Զ�����̬������ڴ档����˵��������һ������������ָ�룬�ܰ����סʲôʱ��Ӧ���ͷ��ڴ棬�Ӷ������ڴ�й©��

### Ϊʲô��Ҫ����ָ�룿

��C++�У����Ǿ���ʹ��`new`���������̬�����ڴ棬���������ʹ��`delete`�ͷ��ڴ棬�ͻᵼ���ڴ�й©������ָ�����Ϊ�˽���������������ġ�

### C++���õ�����ָ������

* **std::unique_ptr:**
  * ��ռ����Ȩ��ͬһʱ��ֻ����һ��unique_ptrָ��һ������
  * �Զ��ͷţ���unique_ptr����������ʱ������ָ��Ķ���ᱻ�Զ��ͷš�
* **std::shared_ptr:**
  * ��������Ȩ�����shared_ptr����ָ��ͬһ�����󣬵����һ��shared_ptr������ʱ������Żᱻ�ͷš�
  * ���ü�����shared_ptr�ڲ�ά����һ�����ü��������������ж��ٸ�shared_ptrָ��ͬһ������
* **std::weak_ptr:**
  * �����ã�weak_ptr����ֱ�ӷ�������ָ��Ķ��󣬱�����ת��Ϊshared_ptr��
  * ��ֹѭ�����ã�weak_ptr�����ڴ���ѭ�����ã������ڴ�й©��

### ����ָ��Ĺ���ԭ��

����ָ���ڲ�ͨ��ά��һ��ָ��̬��������ָ�룬�Լ�һ�����ü���������shared_ptr����������ָ�뱻����ʱ�����������ü�����������ü���Ϊ0�������ö���������������ͷ��ڴ档

### ����ָ�������

* **�Զ��ڴ����:** �������ֶ������ڴ�ķ������״�
* **��ߴ��밲ȫ��:** �������ڴ�й©�ķ��ա�
* **��ǿ����ɶ���:** ����ָ��ʹ�ô������������ά����

### ����ָ���ʹ��ʾ��

```c++
#include <memory>

class MyClass {
public:
	MyClass() { std::cout << "MyClass constructor\n"; }
	~MyClass() { std::cout << "MyClass destructor\n"; }
};

int main() {
	// unique_ptr
	std::unique_ptr<MyClass> ptr1(new MyClass);

	// shared_ptr
	std::shared_ptr<MyClass> ptr2 = std::make_shared<MyClass>();
	std::shared_ptr<MyClass> ptr3 = ptr2; // ���ü�����1

	// weak_ptr
	std::weak_ptr<MyClass> weak_ptr = ptr2;

	// ...
}
```

### �ܽ�

C++����ָ�����ִ�C++����зǳ���Ҫ�Ĺ��ߣ�������Ч�ذ������ǹ���̬�ڴ棬��ߴ���İ�ȫ�ԡ��ɿ��ԺͿ�ά���ԡ���ʵ�ʿ����У�����Ӧ�þ���ʹ������ָ����������ָ�룬�Ա����ڴ�й©�����⡣

**����ѧϰ���飺**

* **���ü�������:** ��ϸ�˽�shared_ptr�����ü���ʵ��ԭ��
* **ѭ������:** ѧϰ���ʹ��weak_ptr�����ѭ���������⡣
* **�Զ���ɾ����:** �˽����Ϊ����ָ���Զ���ɾ������
* **����ָ������ʵ��:** ѧϰ����ڲ�ͬ�ĳ�����ѡ����ʵ�����ָ�롣

**ϣ��������Ͷ����а�����** ����㻹���������⣬��ӭ��ʱ���ʡ�








                                     
									��c++��һ���߳���дthis_thread::sleep_for(chrono::seconds(5));��Sleep(5000)��ʲô����

ƽ̨�����ԣ�

this_thread::sleep_for �ǿ�ƽ̨�ģ��������κ�֧��C++11����߰汾��ƽ̨��ʹ�á�
Sleep ���ض���Windowsƽ̨�ģ������Ĵ�����Ҫ�ڷ�Windowsƽ̨�����У�ʹ�� Sleep �������С�

ʹ�÷�ʽ��
ʹ�� this_thread::sleep_for ʱ������Ҫ���� <thread> �� <chrono> ͷ�ļ�����ʹ�� std::chrono �е����ͣ����� std::chrono::seconds �� std::chrono::milliseconds��
ʹ�� Sleep ʱ����ֻ��Ҫ���� <windows.h> ͷ�ļ���Ȼ��ֱ�ӵ��� Sleep ������


notify_one():

��������������ǻ���һ���ȴ��� condition_variable �ϵ��̡߳�����ж���߳��ڵȴ���notify_one() ֻ�ỽ������һ�������廽����һ���ǲ�ȷ���ġ�
ͨ����ĳ�������Ѿ�����ʱ���ã����������Ѿ�׼���ã����Ա����ѡ�

wait():
����������ڹ���ǰ�̣߳�ֱ�����յ� notify_one() �� notify_all() ��֪ͨ�������ڳ�ʱʱ�䵽�
wait() ͨ����һ����������mutex��һ��ʹ�ã���ȷ���ڵȴ��ڼ�Թ�����Դ�ķ����ǻ���ġ�








Lambda ���ʽ��Ҳ��Ϊ������������C++11�����һ�ֱ�ݵĺ������巽ʽ��Lambda ���ʽ����������Ҫһ����������ĵط����ٶ���һ��������������Ҫд�������ĺ������塣

### Lambda ���ʽ�Ľṹ

Lambda ���ʽ�Ļ����﷨���£�

```cpp
[capture] (parameters) -> return_type { function_body }
```

- **[capture]**�������Ӿ䣬���ڶ�����ⲿ�����򲶻�ı�����������ֵ����`x` �� `&x`����Ҳ��������ʽ����`[&]` �� `[=]`����
��Lambda���ʽ�Ĳ����Ӿ��У�ʹ��[=]��ʾĬ�ϲ��������ⲿ�������еľֲ�������������ֵ�ķ�ʽ���в�������ζ��ÿ������ı������ᱻ����һ�ݣ�Lambda���ʽ�ڲ�ʹ�õ�����Щ�����ĸ�����

������[=]����ʽ��һЩҪ�㣺

ֵ����Lambda���ʽ�ڲ�ʹ�õ����ⲿ������ֵ�ĸ��������������á���ˣ���ʹԭ������ֵ�����仯��Lambda�ڲ�ʹ�õ�ֵҲ�����ܵ�Ӱ�졣

�����ڲ��ɱ����ݣ�����֪������ı�����Lambda���ʽִ���ڼ䲻�ᱻ�޸ģ�������ֻ��Ҫ��ȡ��Щ������ֵʱ��ʹ��[=]�Ǻ��ʵġ�

�򻯴��룺ʹ��[=]���Ա�����ʽ�г�ÿ��Ҫ����ı�����ʹ������Ӽ�ࡣ

��[&]������ʹ��[&]ʱ��Lambda���ʽ��ͨ�����ò��������ⲿ����������ζ��Lambda�ڲ�����Щ�������޸Ļ�Ӱ�쵽ԭʼ������

��[]������ʹ��[]���ղ����Ӿ䣩ʱ��Lambda���ʽ���Ჶ���κ��ⲿ��������ֻ�ܷ���ȫ�ֱ�������ͨ���������ݸ����ı�����
- **(parameters)**�������б�������Lambda���ʽ���ܵĲ�����
- **-> return_type**���������ͣ�ָ��Lambda���ʽ�ķ������͡����Lambda���ʽֻ��һ��������䣬����ʡ�Է������͡�
- **{function_body}**�������壬Lambda���ʽҪִ�еĴ��롣

### Lambda ���ʽ��ʹ�ó���

1. **�򻯺��������ʹ��**��������Ҫһ��ֻʹ��һ�ε�С�ͺ���ʱ��ʹ��Lambda���ʽ���Ա��ⶨ��һ�������ĺ�����

2. **ʹ���ⲿ����**��Lambda���ʽ���Բ���ʹ�ö��������ⲿ�ı�����

3. **��Ϊ��������**��Lambda���ʽ������Ϊ�������ݸ����������紫�ݸ��㷨�������¼���������

4. **�հ�**��Lambda���ʽ���Բ����ⲿ���������ڲ����Ļ�����ִ�У��γɱհ���

### ʾ��

#### ����ʹ��

```cpp
auto add = [](int a, int b) { return a + b; };
int result = add(5, 3); // result is 8
```

#### �����ⲿ����

```cpp
int value = 10;
auto printValue = [value] { std::cout << value << std::endl; };
printValue(); // ��� 10
```

#### ʹ��Ĭ�ϲ���

```cpp
int number = 5;
auto increment = [&] { number++; };
increment();
std::cout << number; // ��� 6
```

#### ��������Lambda���ʽ

```cpp
auto add = [](int a, int b) -> int { return a + b; };
int result = add(5, 3); // result is 8

��Lambda���ʽ�У�->��������ָ���������͡�Lambda���ʽ������ʽ���ƶϷ������ͣ�����Lambda���ʽ������������������Ҫ��ȷָ����������ʱ������Ҫʹ��->������Ϸ������͵��﷨��
```

#### ʹ��Lambda���ʽ���㷨

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> v = {1, 2, 3, 4, 5};
auto isEven = [](int i) { return i % 2 == 0; };

auto it = std::find_if(v.begin(), v.end(), isEven); // �ҵ���һ��ż��
std::cout << "First even number: " << *it << std::endl;
```

Lambda ���ʽ��C++�зǳ�ǿ������ԣ������ṩ��һ�������ķ�ʽ�����庯������ͨ�������ⲿ�����Ͷ�����ĺ����壬Lambda���ʽʹ�ô�����ӽ��պ�������⡣

ʹ�� std::function ʱ����Ҫ���ݾ���ĺ���ǩ��ʵ����ģ�壬���磺

cpp
std::function<int(int, int)> func = someFunction;
���� someFunction ������Ͼ������� int ���Ͳ���������һ�� int ����ֵ�ĺ���ǩ��
���� std::function ����û�а�װ�κοɵ���Ԫ��ʱ������һ���պ��������������׳� std::bad_function_call �쳣
*/