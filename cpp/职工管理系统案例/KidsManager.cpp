#include "KidsManager.h"
#include"head Kid.h"
#include"Kid.h"
void KidsManager::test()
{
	delete KidArray[1];
	KidArray[1] = new HeadKid(2, 2, "9");
	save();
}
void KidsManager::initialkid()
{
	int ii = 0;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int ID;
	string name;
	int dID;
	while (ifs >> ID && ifs >> dID && ifs >> name)
	{
		Kid* kid = nullptr;
		if (dID == 1)
		{
			kid = new HeadKid(ID, dID, name);
		}
		else if (dID == 2)
		{
			kid = new LittleKid(ID, dID, name);
		}
		KidArray[ii] = kid;
		ii++;

	}
	ifs.close();

}
void KidsManager::deleteKid()
{
	int ID = 0;
	if (m_fileIsEmpty)
	{
		cout << "emptyfile" << endl;
	}
	else
	{
		cout << "delete which number ID ?" << endl;
		cin >> ID;
		int index=kidExist(ID);
		if (index != -1)
		{
			for (int i = 0; i < KidNumber - 1; i++)
			{
				KidArray[i] = KidArray[i + 1];
			}
		}
		else
		{
			cout << "ID not found"<<endl;
		}
	}
	KidNumber--;
	save();
	cout << "delete successfull" << endl;
	system("pause");
	system("cls");
}
int KidsManager::kidExist(int id)
{
	
	for (int i = 0; i < KidNumber; i++)
	{
		cout << "kidarr3:" << KidArray[2]->m_ID << endl;
		cout << i << endl; cout <<"kidnum:" << KidNumber << endl;
		if (id == KidArray[i]->m_ID)
		{
			return i;
			break;
		}
		
	}
	return -1;
}
KidsManager::KidsManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		KidNumber = 0;
		KidArray = nullptr;
		bool m_fileIsEmpty = 1;
		ifs.close();
		return;
	}

	char cha;
	ifs >> cha;//如果你希望读取文件的第一个字符，需要在打开文件后直接执行该语句；如果你希望读取文件的最后一个字符，则需要先将文件指针移动到文件结尾处，再执行该语句。
	//这两行代码是为了读取文件中的第一个字符并进行判断。

	//	如果文件是空的，那么在执行"ifs >> cha"时会立即达到文件结尾，即"ifs.eof()"将返回true。通过这个判断，可以得知文件是否为空，然后输出相应的提示信息。

	//	如果文件不为空，那么可以继续执行后续的读取操作。

	//	因此，这两行代码的意义是为了检查文件是否为空，并根据结果做出相应的处理。
	if (ifs.eof())
	{
		cout << "文件不存在0" << endl;
		KidNumber = 0;
		KidArray = nullptr;
		bool m_fileIsEmpty = 1;
		ifs.close();

		return;
	}
	int num= getKidNum();
	cout << "当前存储的员工人数：" << num << endl;
	KidNumber = num;
	KidArray = new Kid * [num];
	initialkid();//不要加void，不然不运行；
}
int KidsManager::getKidNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int ID;
	string name;
	int dID;
	int num=0;
	while (ifs >> ID &&ifs>>dID &&ifs >> name)//ifs >> id 遇到空格时 id 就读取完毕，跳到 ifs >> name,读到末尾会有一个变false，跳出循环
	{
		num++;
	}
	ifs.close();
	return num;
}
KidsManager::~KidsManager()
{
	if (KidArray != nullptr)
	{
		delete[] KidArray;
		KidArray = nullptr;
		
	}
}
void  KidsManager::save()
{
	ofstream ofss;
	ofss.open(FILENAME, ios::out);
	for (int i = 0; i < KidNumber; i++)
	{

		ofss << KidArray[i]->m_DeptID << " "
			<< KidArray[i]->m_ID << " "
			<< KidArray[i]->m_Name << " " << endl;
	}
	ofss.close();

}
void KidsManager::Show_Menu()
{
	cout << "___________________________________" << endl;
	cout << "欢迎使用幼儿园管理系统！" << endl;
	cout << "0.退出管理程序" << endl;
	cout << " 1.增加职工信息" << endl;
	cout << "2.显示职工信息" << endl;
	cout << " 3.删除离职职工信息 " << endl;
	cout << "4.修改职工信息" << endl;
	cout << " 5.查找职工信息" << endl;
	cout << " 6.按照编号排序" << endl;
	cout << "7.清空所有文档" << endl;
	cout << "______________________________________" << endl;
	cout << endl;
}
void KidsManager::showInfo()
{
	if (m_fileIsEmpty)
	{
		cout << "文件不存在*********" << endl;
	}
	else
	{
		cout<<"***********" << KidNumber<<endl;
		for (int i = 0; i < KidNumber; i++)
		{
			KidArray[i]->ShowInfo();
		}
	}
	system("pause");
	system("cls");
}
void KidsManager::exitsystem()
{
	cout << "欢迎下次使用!" << endl;
	system("pause");
	exit(0);
}
void KidsManager::add_kid()
{
	cout << "请选择添加个数" << endl;
	int addnum;
	cin >> addnum;
	Kid** newSpace=nullptr;
	if (addnum > 0)
	{
		int newsize = KidNumber + addnum;
		newSpace = new Kid * [newsize];//new了一个数组过去，newSpace是那个数组的内存地址
		if (KidArray != nullptr)
		{
			for (int i = 0; i <KidNumber; i++)
			{
				newSpace[i] = KidArray[i];
			}
		}

		for (int i = 0; i < addnum; i++)
		{
			int ID;
			string name;
			int dSelect=0;
			cout << "输入第" << i + 1 << "个员工的ID编号" << endl;
			cin >> ID;
			cout << "输入第" << i + 1 << "个员工的姓名" << endl;
			cin >> name;
			cout << "选择第" << i + 1 << "个员工的岗位" << endl;
			cout << "1.班长" << endl;
			cout << "2.小孩" << endl;
			cin >> dSelect;
			Kid* kid=nullptr;//不初始化报错；
			switch (dSelect)
			{
			case 1:kid = new HeadKid(ID, 1, name);
				break;
		
			case 2:
			{
				kid = new LittleKid(ID, 2, name);

			}
			break;
			default:
				break;
			}
			newSpace[KidNumber + i] = kid;
		}
		
		delete[] KidArray;
		KidArray = nullptr;
		KidNumber = newsize;
		bool m_fileIsEmpty = 0;
		KidArray = newSpace;
		save();
		cout << "成功添加" << addnum<<"个" << endl;
	}
	else { cout << "重新输入" << endl; }
	system("pause"); system("cls");
}
