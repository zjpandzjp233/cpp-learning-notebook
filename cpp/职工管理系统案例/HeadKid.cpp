#include"head Kid.h"
#include"Kid.h"

HeadKid::HeadKid(int ID ,int deptID,string name)
{
	m_ID = ID;
	m_DeptID=deptID;
	m_Name = name;
}
void HeadKid::ShowInfo()
{
	cout << "ְ����ţ�" << m_ID<<"\t";
	cout << "ְ��������" << m_Name << "\t";
	cout << "��λ���:"<<m_DeptID << "\t";
	cout << "��λ:" << GetDeptName() << "\t" << endl;
	bool m_fileIsEmpty = 0;
}
string HeadKid::GetDeptName()
{
	return "�೤";
}

LittleKid::LittleKid(int ID, int deptID, string name)
{
	m_ID = ID;
	m_DeptID = deptID;
	m_Name = name;
}
void LittleKid::ShowInfo()
{
	cout << "ְ����ţ�" << m_ID << "\t";
	cout << "ְ��������" << m_Name << "\t";
	cout << "��λ���:" << m_DeptID << "\t";
	cout << "��λ:" << GetDeptName() << "\t" << endl;


}
string LittleKid::GetDeptName()
{
	return "С��";
}