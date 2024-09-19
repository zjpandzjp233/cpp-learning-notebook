#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	
	/*ofstream f;
	f.open("E:/f.txt", ios::out | ios::app);
	f << "zjp" << " " << "123456789" << endl;
	f << "zjp2" << " " << "6789" << endl;
	f << "zjp3" << " " << "12345" << endl;*/
	int r; int c; int Fc;
	cout << "输入数据库列数：" << endl;
	cin >> Fc;
	cout << endl;
Start:

	cout << "输入想要的行：" << endl;
	cin >> r;
	cout << "输入想要的列：" << endl;
	cin >> c;
	ifstream f2;
	f2.open("E:/f.txt", ios::in);
	int row = 1;
	int column = 1;
	string target = "";
	int index = 0;
	while (f2 >> target)
	{
	
		 ++index;
		 if (index > Fc)
		 {
			 row++;
			 index = 1;

		 }
		 //cout << "test: " << target << endl;
		 //cout << "test: "<< "row=" << row << "column=" << column << endl;
		 if (r == row && c == column)
		 {
			 cout << "target: " << target << endl;
			 break;
		 }


		 if (column == Fc)
		 {
			 column = 1;
			 continue;
		 }
		 ++column;
		
	}
	f2.close();
	system("pause");
	cout << endl;
	goto Start;
	return 0;

}
