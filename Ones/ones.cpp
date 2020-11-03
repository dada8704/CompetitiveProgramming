#include<iostream>
using namespace std;


int main(void)
{
	int input_n;

	while( cin >> input_n )
	{
		int ans = 1;
		unsigned long long int ones = 1;
		int up = 0;
		int flag = 0;
		int now = 0;
		for(;;)
		{
			now = ((ones) % input_n);
			up = ((now + up) % input_n);
			if (up  == 0)
			{
				cout << ans << endl;
				break;
			}
			if (ones > input_n) flag = 1;
			
			if (flag) ones = now * 10;
			else ones = ones * 10;

			/*
			if (ones == 0)
			{
				cout<<"fail"<<endl;
				break;
			}*/
			ans++;
		}

	}
	return 0;
}