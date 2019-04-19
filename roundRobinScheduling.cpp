// this project is implemented by *****navid pourhadi*****
// this project is about round robin scheduling for OS lab class in kharazmi university
//this project written in c++ language and use linked list for implementing it	


#include<iostream>
using namespace std;

struct process{
	int pid;
	int arrivalTime;
	int executionTime;
};

struct node{
	process process;
	node * nxt;
};


int main(){
	
	
	
	
	cout<<"------------------------------------------------------------------------"<<endl
		<<"------------------------Round Robin scheduler---------------------------"<<endl
		<<"------------------------------------------------------------------------"<<endl;
		
	int quantom;
	cout<<"how much is the quantom of scheduling? ";
	cin>>quantom;	
	
	int process_size;
	cout<<"how many processes do you have? ";
	cin>>process_size;
	
	process processes[process_size];
	for(int i=0;i<process_size;i++){
		processes[i].pid = i;
		cout << "when process"<<i<<" arrived? ";
		cin >> processes[i].arrivalTime;
		cout << "how much is the execution time of process"<<i<<"? ";
		cin >> processes[i].executionTime;
	}
	
	
	node * head = NULL;
	node * active = NULL;
	int duration = quantom;
	int i = 0;
	//we set this scheduling for 500 clock
	while(i != 500){
		cout<<i<<endl;
		
		//add processes that arrived in this clock
		for(int j = 0 ; j < process_size ; j++){
			if (processes[j].arrivalTime == i){
				
				if(head == NULL | head == 0){
					node * temp =new node;
					temp->process = processes[j];
					head = temp;
					temp->nxt = head;
				}
				else{
					node * temp1 = head;
					while (temp1->nxt != head)
						temp1 = temp1->nxt;
					node * temp2 = new node;
					temp2->process = processes[j];
					temp2->nxt = head;
					temp1->nxt = temp2;
						
				}
				cout<<"new node added"<<endl;
			}
		}
		// find process that should be execute 
		if(active == NULL & head != NULL){
			
			active = head;
			duration = quantom;
		}
		//execute process
		if (active!=NULL & duration > 0 & head != NULL){
			active->process.executionTime--;
			duration--;
			cout<<i+1<<" --->   process"<<active->process.pid<<" executed and "<<active->process.executionTime<<" clocks of this process left." <<endl;
			
			
			//when a process complete
			
			if(active->process.executionTime == 0){
				
				
				if (active != head){
					cout<<"\n********************* process "<<active->process.pid<<" finished ************************\n"<<endl;
					node * temp = head;
					while(temp->nxt != active)
						temp=temp->nxt;
					temp->nxt = active->nxt;
					temp = active;
					active = active->nxt;
					delete temp;
					duration = quantom;	
					
				}
				
				else if(active == head){
					cout<<"\n********************* process "<<active->process.pid<<" finished ************************\n"<<endl;
					if (head->nxt == head){
						node * temp = head;
						active = NULL;
						head = NULL;
						delete temp;
						duration = quantom;
						
					}
					
					else {
						node * temp = head;
						while(temp->nxt != head)
							temp = temp->nxt;
						head = head->nxt;
						temp->nxt = head;
						duration = quantom;
						active = active->nxt;	
							
					}
					
				}
			}
			
			
			
		}
		
		if(duration == 0){
				active = active->nxt;
				duration = quantom;
				cout<<"\n\n\n\n\n                     process changed                    \n\n\n\n\n";
			}

		
		i++;	
	}
	
	
	
	return 0;
}
