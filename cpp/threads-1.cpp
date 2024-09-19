
using namespace std;
#include<iostream>
#include<thread>
#include<memory>
#include<mutex>
#include<windows.h>
#include<chrono>
#include<condition_variable>//条件变量
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
		 unique_lock<timed_mutex> lgm(m0,defer_lock); //函数结束时，unique_lock对象lgm会被销毁，自动释放它所持有的锁。
		 
		 //使用try_lock_for尝试在指定的时间内（这里是1秒）获取m0的锁。如果成功获取锁，try_lock_for返回true。
		 if(lgm.try_lock_for(chrono::seconds(2)))//只有timed_mutex里有try_lock_for成员，普通mutex里没有try_lock_for
		 {
			 this_thread::sleep_for(chrono::seconds(1));
			 //m0.lock();
			 c += 1;
			 //m0.unlock();
		 }
	}
}
/*                               无法运行
static once_flag once; 
static Log* log=nullptr;
class Log//单例实例
{
	
public:
	
	Log()
	{

	};

	Log(const Log& logs) = delete;

	Log& operator=(const Log& logs) = delete;

	static Log& GetInstance()
	{
		
		call_once(once, init);//确保init只被调用一次

		return *log;
	}
	static void init()
	{
		if (!log) log = new Log;
	}
	void PrintLog(string msg)
	{

		std::cout << __TIME__ << " " << msg << std::endl;//返回当前时间 __TIME__ 

	}
};
*/
std::once_flag flag; // 全局初始化标志

void initialize()
{
	std::cout << "Initialization is done." << std::endl;
	// 这里可以放置需要执行一次的初始化代码
}

void do_work()
{
	while(1)
	{
		Sleep(500);
		std::call_once(flag, initialize); // 确保initialize只被调用一次
		std::cout << "Doing work..." << std::endl;
	}
}


class coutAPP
{
public:
	static void coutApp()//调用方式：静态函数可以通过类名直接调用，而不需要创建类的实例。例如，如果有一个静态函数func()，你可以使用ClassName.func()来调用它，而不是object.func()。
	{//实例访问：静态函数不能访问类的非静态成员，因为它们不依赖于类的任何特定实例。它们只能访问类的静态成员。
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
		{//给锁一个生命周期，否则会等到生产者全部生产完（10个）消费者才可以获取锁然后消费
			unique_lock<mutex> lock11(m3);
			//cv.notify_one();//让一个wait阻塞的线程加入工作
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
		cv.wait(lock1, [] { return !q9.empty(); });//如果真就不阻塞。//两个条件必须同时满足
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
		([this]//用于访问类成员
			{
				while (true)
				{
					unique_lock<mutex> lock2(mt3);
					cv3.wait(lock2, [this] {return!(isStop || fq.empty()); });
					if (isStop&&fq.empty())
					{
						return;
					}
					function<void()> task(move(fq.front()));//避免拷贝构造
					//此外，由于fq.front()在移动之后可能处于未定义状态，所以在队列中不应该再次使用它，除非它被重新赋值或重新初始化。
					fq.pop();
					lock2.unlock();
					task();
				}	
			}
		);
	}
}
template<class F,class... Args>
void enqueue(F &&f,Args&&... args)//省略
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
	for (auto& t : vt)//线程无法复制
	{
		t.join();
	}
}
private:
	vector<thread> vt;	
	queue < function<void()>> fq;//function<void()> 是一个可调用的函数类型，	它不接受任何参数并且不返回任何值（即它的签名是 void()）。
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
	auto Plus = [=](int bb = 99)->int {return a+bb+b; };//[=]捕获到的a、b不可修改
	cout << Plus();//118

	future<int> future_result = async(launch::async, Plus0to1000);//结果存在future_result里，Plus0to1000放后台，代码继续往下走
	cout << Plus0to1000() << endl;//1000
	cout << future_result.get()<< endl;//上下两个函数在同时执行中，get函数结束代码才会往下走。//1000

		packaged_task<int()>task(Plus0to1000);//将函数封装到task里
		auto GF=task.get_future();
		thread t1(move(task));//函数开始运行
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
	thread t2(PULSPLUS);//atomic比mutex快一丢丢
	t1.join();
	t2.join();
	cout << shared_int << endl;//4000000
	return 0;
}






/*
## C++智能指针：简明易懂的解释

**C++智能指针**是一种特殊的对象，它可以自动管理动态分配的内存。简单来说，它就像一个“聪明”的指针，能帮你记住什么时候应该释放内存，从而避免内存泄漏。

### 为什么需要智能指针？

在C++中，我们经常使用`new`运算符来动态分配内存，但如果忘记使用`delete`释放内存，就会导致内存泄漏。智能指针就是为了解决这个问题而诞生的。

### C++常用的智能指针类型

* **std::unique_ptr:**
  * 独占所有权：同一时间只能有一个unique_ptr指向一个对象。
  * 自动释放：当unique_ptr超出作用域时，它所指向的对象会被自动释放。
* **std::shared_ptr:**
  * 共享所有权：多个shared_ptr可以指向同一个对象，当最后一个shared_ptr被销毁时，对象才会被释放。
  * 引用计数：shared_ptr内部维护了一个引用计数，用来跟踪有多少个shared_ptr指向同一个对象。
* **std::weak_ptr:**
  * 弱引用：weak_ptr不能直接访问它所指向的对象，必须先转换为shared_ptr。
  * 防止循环引用：weak_ptr常用于打破循环引用，避免内存泄漏。

### 智能指针的工作原理

智能指针内部通常维护一个指向动态分配对象的指针，以及一个引用计数（对于shared_ptr）。当智能指针被销毁时，它会检查引用计数，如果引用计数为0，则会调用对象的析构函数，释放内存。

### 智能指针的优势

* **自动内存管理:** 避免了手动管理内存的繁琐和易错。
* **提高代码安全性:** 减少了内存泄漏的风险。
* **增强代码可读性:** 智能指针使得代码更易于理解和维护。

### 智能指针的使用示例

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
	std::shared_ptr<MyClass> ptr3 = ptr2; // 引用计数加1

	// weak_ptr
	std::weak_ptr<MyClass> weak_ptr = ptr2;

	// ...
}
```

### 总结

C++智能指针是现代C++编程中非常重要的工具，它能有效地帮助我们管理动态内存，提高代码的安全性、可靠性和可维护性。在实际开发中，我们应该尽量使用智能指针来代替裸指针，以避免内存泄漏等问题。

**深入学习建议：**

* **引用计数机制:** 详细了解shared_ptr的引用计数实现原理。
* **循环引用:** 学习如何使用weak_ptr来解决循环引用问题。
* **自定义删除器:** 了解如何为智能指针自定义删除器。
* **智能指针的最佳实践:** 学习如何在不同的场景下选择合适的智能指针。

**希望这个解释对你有帮助！** 如果你还有其他问题，欢迎随时提问。








                                     
									在c++的一个线程里写this_thread::sleep_for(chrono::seconds(5));和Sleep(5000)有什么区别

平台依赖性：

this_thread::sleep_for 是跨平台的，可以在任何支持C++11或更高版本的平台上使用。
Sleep 是特定于Windows平台的，如果你的代码需要在非Windows平台上运行，使用 Sleep 将不可行。

使用方式：
使用 this_thread::sleep_for 时，你需要包含 <thread> 和 <chrono> 头文件，并使用 std::chrono 中的类型，例如 std::chrono::seconds 或 std::chrono::milliseconds。
使用 Sleep 时，你只需要包含 <windows.h> 头文件，然后直接调用 Sleep 函数。


notify_one():

这个方法的作用是唤醒一个等待在 condition_variable 上的线程。如果有多个线程在等待，notify_one() 只会唤醒其中一个，具体唤醒哪一个是不确定的。
通常在某个条件已经满足时调用，比如数据已经准备好，可以被消费。

wait():
这个方法用于挂起当前线程，直到接收到 notify_one() 或 notify_all() 的通知，或者在超时时间到达。
wait() 通常与一个互斥锁（mutex）一起使用，以确保在等待期间对共享资源的访问是互斥的。








Lambda 表达式，也称为匿名函数，是C++11引入的一种便捷的函数定义方式。Lambda 表达式允许你在需要一个函数对象的地方快速定义一个函数，而不需要写出完整的函数定义。

### Lambda 表达式的结构

Lambda 表达式的基本语法如下：

```cpp
[capture] (parameters) -> return_type { function_body }
```

- **[capture]**：捕获子句，用于定义从外部作用域捕获的变量。可以是值捕获（`x` 或 `&x`），也可以是隐式捕获（`[&]` 或 `[=]`）。
在Lambda表达式的捕获子句中，使用[=]表示默认捕获所有外部作用域中的局部变量，但是以值的方式进行捕获。这意味着每个捕获的变量都会被复制一份，Lambda表达式内部使用的是这些变量的副本。

这里是[=]捕获方式的一些要点：

值捕获：Lambda表达式内部使用的是外部变量的值的副本，而不是引用。因此，即使原变量的值发生变化，Lambda内部使用的值也不会受到影响。

适用于不可变数据：当你知道捕获的变量在Lambda表达式执行期间不会被修改，或者你只需要读取这些变量的值时，使用[=]是合适的。

简化代码：使用[=]可以避免显式列出每个要捕获的变量，使代码更加简洁。

与[&]的区别：使用[&]时，Lambda表达式会通过引用捕获所有外部变量，这意味着Lambda内部对这些变量的修改会影响到原始变量。

与[]的区别：使用[]（空捕获子句）时，Lambda表达式不会捕获任何外部变量，它只能访问全局变量或者通过参数传递给它的变量。
- **(parameters)**：参数列表，定义了Lambda表达式接受的参数。
- **-> return_type**：返回类型，指定Lambda表达式的返回类型。如果Lambda表达式只有一条返回语句，可以省略返回类型。
- **{function_body}**：函数体，Lambda表达式要执行的代码。

### Lambda 表达式的使用场景

1. **简化函数对象的使用**：当你需要一个只使用一次的小型函数时，使用Lambda表达式可以避免定义一个完整的函数。

2. **使用外部变量**：Lambda表达式可以捕获并使用定义在其外部的变量。

3. **作为参数传递**：Lambda表达式可以作为参数传递给函数，例如传递给算法函数或事件处理器。

4. **闭包**：Lambda表达式可以捕获外部变量，并在捕获后的环境中执行，形成闭包。

### 示例

#### 基本使用

```cpp
auto add = [](int a, int b) { return a + b; };
int result = add(5, 3); // result is 8
```

#### 捕获外部变量

```cpp
int value = 10;
auto printValue = [value] { std::cout << value << std::endl; };
printValue(); // 输出 10
```

#### 使用默认捕获

```cpp
int number = 5;
auto increment = [&] { number++; };
increment();
std::cout << number; // 输出 6
```

#### 带参数的Lambda表达式

```cpp
auto add = [](int a, int b) -> int { return a + b; };
int result = add(5, 3); // result is 8

在Lambda表达式中，->符号用来指定返回类型。Lambda表达式可以隐式地推断返回类型，但当Lambda表达式包含多条语句或者你想要明确指定返回类型时，就需要使用->后面跟上返回类型的语法。
```

#### 使用Lambda表达式与算法

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> v = {1, 2, 3, 4, 5};
auto isEven = [](int i) { return i % 2 == 0; };

auto it = std::find_if(v.begin(), v.end(), isEven); // 找到第一个偶数
std::cout << "First even number: " << *it << std::endl;
```

Lambda 表达式是C++中非常强大的特性，它们提供了一种灵活、简洁的方式来定义函数对象。通过捕获外部变量和定义简洁的函数体，Lambda表达式使得代码更加紧凑和易于理解。

使用 std::function 时，需要根据具体的函数签名实例化模板，例如：

cpp
std::function<int(int, int)> func = someFunction;
这里 someFunction 必须符合具有两个 int 类型参数并返回一个 int 类型值的函数签名
。当 std::function 对象没有包装任何可调用元素时，它是一个空函数，调用它将抛出 std::bad_function_call 异常
*/