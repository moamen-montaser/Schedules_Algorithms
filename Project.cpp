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
		struct process p2[100];
		float avrw2;
		float avrt2;
		float avrr2;
		float cpu_utilization;
		int total_turnaround_time = 0;
		int total_waiting_time = 0;
		int total_response_time = 0;
		int total_idle_time = 0;
		float throughput;
		int burst_remaining[100];
		int is_completed[100];

		memset(is_completed, 0, sizeof(is_completed));

		cout << setprecision(2) << fixed;
		int num2;
		cout << "Enter the number of processes: ";
		cin >> num2;

		for (int i = 0; i < num2; i++) {
			cout << "Enter arrival and burst time of process " << i + 1 << ": ";
			cin >> p2[i].arrival_time;
			cin >> p2[i].burst_time;
			p2[i].pid = i + 1;
			burst_remaining[i] = p2[i].burst_time;
		}

		int current_time = 0;
		int completed = 0;
		int prev = 0;

		while (completed != num2) {
			int idx = -1;
			int mn = 10000000;
			for (int i = 0; i < num2; i++) {
				if (p2[i].arrival_time <= current_time && is_completed[i] == 0) {
					if (burst_remaining[i] < mn) {
						mn = burst_remaining[i];
						idx = i;
					}
					if (burst_remaining[i] == mn) {
						if (p2[i].arrival_time < p2[idx].arrival_time) {
							mn = burst_remaining[i];
							idx = i;
						}
					}
				}
			}

			if (idx != -1) {
				if (burst_remaining[idx] == p2[idx].burst_time) {
					p2[idx].start_time = current_time;
					total_idle_time += p2[idx].start_time - prev;
				}
				burst_remaining[idx] -= 1;
				current_time++;
				prev = current_time;

				if (burst_remaining[idx] == 0) {
					p2[idx].completion_time = current_time;
					p2[idx].turnaround_time = p2[idx].completion_time - p2[idx].arrival_time;
					p2[idx].waiting_time = p2[idx].turnaround_time - p2[idx].burst_time;
					p2[idx].response_time = p2[idx].start_time - p2[idx].arrival_time;

					total_turnaround_time += p2[idx].turnaround_time;
					total_waiting_time += p2[idx].waiting_time;
					total_response_time += p2[idx].response_time;

					is_completed[idx] = 1;
					completed++;
				}
			}
			else {
				current_time++;
			}
		}

		int min_arrival_time = 10000000;
		int max_completion_time = -1;
		for (int i = 0; i < num2; i++) {
			min_arrival_time = min(min_arrival_time, p2[i].arrival_time);
			max_completion_time = max(max_completion_time, p2[i].completion_time);
		}

		avrt2 = (float)total_turnaround_time / x;
		avrw2 = (float)total_waiting_time / x;
		avrr2 = (float)total_response_time / x;
		cpu_utilization = ((max_completion_time - total_idle_time) / (float)max_completion_time) * 100;
		throughput = float(x) / (max_completion_time - min_arrival_time);

		cout << endl << endl;

		cout << "pid" << "               ";
		for (int i = 0; i < num2; i++)
		{
			cout << p2[i].pid << "       ";
		}
		cout << endl << endl;
		cout << "arrival_time" << "      ";
		for (int i = 0; i < num2; i++)
		{
			cout << p2[i].arrival_time << "       ";
		}
		cout << endl << endl;
		cout << "burst_time" << "        ";
		for (int i = 0; i < num2; i++)
		{
			cout << p2[i].burst_time << "       ";
		}
		cout << endl << endl;
		cout << "turnaround_time" << "   ";
		for (int i = 0; i < num2; i++)
		{
			cout << p2[i].turnaround_time << "       ";
		}
		cout << endl << endl;
		cout << "waiting_time" << "      ";
		for (int i = 0; i < num2; i++)
		{
			cout << p2[i].waiting_time << "       ";
		}
		cout << endl << endl;
		avrw2 = avrw2 / num2;
		avrt2 = avrt2 / num2;
		cout << "Average waiting time = " << avrw2 << endl;
		cout << "Average turnarround time = " << avrt2 << endl;		
		
		
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