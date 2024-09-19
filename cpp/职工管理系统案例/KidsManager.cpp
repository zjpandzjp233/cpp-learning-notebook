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
		cout << "�ļ�������" << endl;
		KidNumber = 0;
		KidArray = nullptr;
		bool m_fileIsEmpty = 1;
		ifs.close();
		return;
	}

	char cha;
	ifs >> cha;//�����ϣ����ȡ�ļ��ĵ�һ���ַ�����Ҫ�ڴ��ļ���ֱ��ִ�и���䣻�����ϣ����ȡ�ļ������һ���ַ�������Ҫ�Ƚ��ļ�ָ���ƶ����ļ���β������ִ�и���䡣
	//�����д�����Ϊ�˶�ȡ�ļ��еĵ�һ���ַ��������жϡ�

	//	����ļ��ǿյģ���ô��ִ��"ifs >> cha"ʱ�������ﵽ�ļ���β����"ifs.eof()"������true��ͨ������жϣ����Ե�֪�ļ��Ƿ�Ϊ�գ�Ȼ�������Ӧ����ʾ��Ϣ��

	//	����ļ���Ϊ�գ���ô���Լ���ִ�к����Ķ�ȡ������

	//	��ˣ������д����������Ϊ�˼���ļ��Ƿ�Ϊ�գ������ݽ��������Ӧ�Ĵ���
	if (ifs.eof())
	{
		cout << "�ļ�������0" << endl;
		KidNumber = 0;
		KidArray = nullptr;
		bool m_fileIsEmpty = 1;
		ifs.close();

		return;
	}
	int num= getKidNum();
	cout << "��ǰ�洢��Ա��������" << num << endl;
	KidNumber = num;
	KidArray = new Kid * [num];
	initialkid();//��Ҫ��void����Ȼ�����У�
}
int KidsManager::getKidNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int ID;
	string name;
	int dID;
	int num=0;
	while (ifs >> ID &&ifs>>dID &&ifs >> name)//ifs >> id �����ո�ʱ id �Ͷ�ȡ��ϣ����� ifs >> name,����ĩβ����һ����false������ѭ��
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
	cout << "��ӭʹ���׶�԰����ϵͳ��" << endl;
	cout << "0.�˳��������" << endl;
	cout << " 1.����ְ����Ϣ" << endl;
	cout << "2.��ʾְ����Ϣ" << endl;
	cout << " 3.ɾ����ְְ����Ϣ " << endl;
	cout << "4.�޸�ְ����Ϣ" << endl;
	cout << " 5.����ְ����Ϣ" << endl;
	cout << " 6.���ձ������" << endl;
	cout << "7.��������ĵ�" << endl;
	cout << "______________________________________" << endl;
	cout << endl;
}
void KidsManager::showInfo()
{
	if (m_fileIsEmpty)
	{
		cout << "�ļ�������*********" << endl;
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
	cout << "��ӭ�´�ʹ��!" << endl;
	system("pause");
	exit(0);
}
void KidsManager::add_kid()
{
	cout << "��ѡ����Ӹ���" << endl;
	int addnum;
	cin >> addnum;
	Kid** newSpace=nullptr;
	if (addnum > 0)
	{
		int newsize = KidNumber + addnum;
		newSpace = new Kid * [newsize];//new��һ�������ȥ��newSpace���Ǹ�������ڴ��ַ
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
			cout << "�����" << i + 1 << "��Ա����ID���" << endl;
			cin >> ID;
			cout << "�����" << i + 1 << "��Ա��������" << endl;
			cin >> name;
			cout << "ѡ���" << i + 1 << "��Ա���ĸ�λ" << endl;
			cout << "1.�೤" << endl;
			cout << "2.С��" << endl;
			cin >> dSelect;
			Kid* kid=nullptr;//����ʼ������
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
		cout << "�ɹ����" << addnum<<"��" << endl;
	}
	else { cout << "��������" << endl; }
	system("pause"); system("cls");
}
