#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int turn, n=2, i, j, val, wc;
	cout << "Enter total number of process: ";
	cin >> n;
	bool flag[n];
	memset(flag,false,sizeof(flag));
	turn = i = j = 0;
	cout << "\t\tInitial Values" << endl;
	for(int x=0; x<n; x++)
	{
		cout << "flag[" << x << "] = " << flag[x] << endl; 
	}
	cout << "turn = " << turn << endl << endl;
	cout << "\t\tInside the loop" << endl;
	do
	{
		flag[i] = true;
		turn = j;
		cout << endl <<"flag["<< i << "] = " << flag[i] << endl;
		cout << "turn = " << turn << endl;
		wc = 0;
		while(flag[i] && turn == j)
		{
			if(wc >= 5)
			{
				cout << "P" << i << " is waiting for too long" << endl;
				cout << "After P" << i-1 << " this will be executed" << endl;
				i=i-1;
				break;
			}
			cout << "P" << i << " is waiting" <<endl;
			cout << "Enter 0 if any process finished its execution: ";
			cin >> val;
			if(val == 0)
			{
				break;
			}
			else
			{
				cout << "Warning! P" << i-1 << " is running" << endl;
			}
			wc++;
		}
		cout << "P" << i << " is in critical section" <<endl;
		cin >> val;
		if(val == 0)
		{
			cout << "P" << i << " is terminated manually"  << endl;
			cout << "P" << i << " is in reminder section" <<endl;
		}
		else
		{
			cout << "P" << i << " is running in backgound" << endl;
		}
		flag[i] = false;
		cout << "flag["<< i << "] = " << flag[i] << endl;
		i++;
		cout << "New Process is coming" << endl;
	}while(1);
	return 0;
}
