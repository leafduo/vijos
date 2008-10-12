#include <iostream>

using namespace std;

int main()
{
	for (;!cin.eof();)
	{
		char temp;
		cin>>temp;
		if (temp=='\n')
		        temp='~';
		cout<<temp;
	}
	return 0;
}
