#include <bits/stdc++.h>
using namespace std;
int main ()
{
	struct process 
	{
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
	};
	struct process p[100];
	
	// TO select type of scheduler
	cout << "press 1 for FCFS \n2 for SJF preemptive\n3 for SJF non-preemptive \n4 for Priority preemptive \n5 for Priority non_preemptive \n6 for Round Robin:  \n";
	int x;
	cin >> x;
	
	
	//First algorithms FCFS 
	
	if (x == 1)
	{
		int num1;
		float avrw1 = 0, sum1 = 0, avrt1 = 0;
		struct process p1[100];
		struct process temp;
		cout << "Enter the number of processes: ";
		cin >> num1;
		for (int i = 0; i < num1; i++)
		{
			cout << "Enter arrival and burst time of process " << i + 1 << " :";
			cin >> p1[i].arrival_time;
			cin >> p1[i].burst_time;
			p1[i].pid = i + 1;
		}
		for (int i = 0; i < num1; i++)
		{
			for (int j = 0; j < num1 - i - 1; j++)
			{
				if (p1[j].arrival_time > p1[j + 1].arrival_time)
				{
					temp = p1[j];
					p1[j] = p1[j + 1];
					p1[j + 1] = temp;
				}
			}
		}
		for (int i = 0; i < num1; i++)
		{
			sum1 = sum1 + p1[i].burst_time;
			p1[i].turnaround_time = sum1;
			p1[i].waiting_time = p1[i].turnaround_time - p1[i].burst_time;
			avrw1 = avrw1 + p1[i].waiting_time;
			avrt1 = avrt1 + p1[i].turnaround_time;
		}
		cout << "pid" << "               ";
		for (int i = 0; i < num1; i++)
		{
			cout << p1[i].pid << "       ";
		}
		cout << endl << endl;
		cout << "arrival_time" << "      ";
		for (int i = 0; i < num1; i++)
		{
			cout << p1[i].arrival_time << "       ";
		}
		cout << endl << endl;
		cout << "burst_time" << "        ";
		for (int i = 0; i < num1; i++)
		{
			cout << p1[i].burst_time << "       ";
		}
		cout << endl << endl;
		cout << "turnaround_time" << "   ";
		for (int i = 0; i < num1; i++)
		{
			cout << p1[i].turnaround_time << "       ";
		}
		cout << endl << endl;
		cout << "waiting_time" << "      ";
		for (int i = 0; i < num1; i++)
		{
			cout << p1[i].waiting_time << "       ";
		}
		cout << endl << endl;
		avrw1 = avrw1 / num1;
		avrt1 = avrt1 / num1;
		cout << "Average waiting time = " << avrw1 << endl;
		cout << "Average turnarround time = " << avrt1 << endl;
		
		
		
	}
	
	// SJF Preemptive
	else if (x == 2)
	{
		
		
		
	}
	
	
	//SJF Non-Preemptive
	else if (x == 3)
	{
		
	}
	
	//Priority Preemptive
	else if (x == 4)
	{
		
		
	}
	
	
	//Priority Non-Preemptive
	else if (x == 5)
	{
		
		
		
	}
	
	//Round Robin
	
	else if (x == 6)
	{
		
		
	}
	else
	{
		cout <<"Invalid input" ;
	}
	return 0 ;
}