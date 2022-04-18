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