#pragma once
#include<iostream>
using namespace std;
#include"Kid.h"
#include<fstream>
#define FILENAME "KidFile.txt"
class KidsManager  
{
public:
	KidsManager();
	~KidsManager();

	int KidNumber;
	Kid** KidArray;
	void add_kid();
	void Show_Menu();
	void initialkid();
	void exitsystem();
	void save();
	bool m_fileIsEmpty;
	void deleteKid();
	int kidExist(int id);
	int getKidNum();
	void showInfo();
	void test();
};