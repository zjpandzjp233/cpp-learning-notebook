#include "KidsManager.h"
#include"Kid.h"
#include"head Kid.h"
int main()
{
	KidsManager KM;
	int choice = 0;
while(true)
{
	KM.Show_Menu();
	cout << "ÇëÊäÈëÄãµÄÑ¡Ôñ" << endl;
	cin >> choice;
	switch (choice)
	{
	case 0:
		KM.exitsystem();
		break;
	case 1:KM.add_kid();
		break;
	case 2:KM.showInfo();
		break;
	case 3:KM.deleteKid();
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:KM.test();
		break;
	default:
		system("cls");
		break;

	}
}
	system("pause");
	return 0;
}