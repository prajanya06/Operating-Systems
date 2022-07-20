#include <iostream>

using namespace std;

int allocation[10][3],need[10][3],Max[10][3],available[10][3];
int p,current[3];
bool executed[10],come;

int main (){
	cout<<"Enter No. of processes: ";
	cin>>p;
	cout<<endl;
	cout<<"Enter the current resources: ";
	cin>>current[0]>>current[1]>>current[2];
	for (int i = 0; i < p; ++i)
	{
		cout<<endl<<endl;
		cout<<"\t\t\tProcess P"<<i+1<<" Details";
		cout<<endl;
		cout<<"Enter Allocation : ";
		cin>>allocation[i][0]>>allocation[i][1]>>allocation[i][2];
		cout<<"Enter Max :";
		cin>>Max[i][0]>>Max[i][1]>>Max[i][2];
		need[i][0]=Max[i][0]-allocation[i][0];
		need[i][1]=Max[i][1]-allocation[i][1];
		need[i][2]=Max[i][2]-allocation[i][2];
	}
	cout<<endl<<endl;
	cout<<"\t\t\tTable for Bankers Algo";
	cout<<endl<<endl;
	cout<<"Initial Resources: "<<current[0]<<" "<<current[1]<<" "<<current[2]<<endl<<endl;
	cout<<"Process    Max    Allocation    Need"<<endl;
	for (int i = 0; i < p; ++i)
	{
		cout<<"  P"<<i+1<<"    ";
		cout<<"  "<<Max[i][0]<<" "<<Max[i][1]<<" "<<Max[i][2]<<"     ";
		cout<<" "<<allocation[i][0]<<" "<<allocation[i][1]<<" "<<allocation[i][2]<<"     ";
		cout<<" "<<need[i][0]<<" "<<need[i][1]<<" "<<need[i][2];
		cout<<endl;
	}
	cout<<endl<<endl;
	come=false;
	for(int i=0; i<10; ++i){
	    executed[i]=false;
	}
	int i,j;
	for (i = 0; i < p; ++i)
	{	
		for (j = 0; j < p; ++j)
		{
			while(executed[j] && j<p-1){
				j++;
			}
			if (need[j][0]<=current[0]&&need[j][1]<=current[1]&&need[j][2]<=current[2])
			{
				if (!executed[j])
				{
					executed[j]=true;
					current[0]+=allocation[j][0];
					current[1]+=allocation[j][1];
					current[2]+=allocation[j][2];
					cout<<endl;
					cout<<"Process P"<<j+1<<endl;
					cout<<"Current: "<<current[0]<<" "<<current[1]<<" "<<current[2]<<endl;
					cout<<"Process executed without deadlock";
					come=true;
					break;
				}
			}
		}
		if (!come)
		{	
			cout<<endl;
			cout<<"\t\t\tDead lock"<<endl<<endl;
			break;
		}else{
			come=false;
		}
	}
	return 0;
}