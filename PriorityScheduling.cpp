#include <iostream>

using namespace std;

int main()
{
    int Pri[10], A[10], B[10], Wt[10], Tat[10], P[10], n;
    cout<<"Enter Total Number of process: ";
    cin>>n;
    for(int i=0; i<n; i++){
        cout<<"Arrival Time: ";
        cin>>A[i];
        P[i]=i+1;
    }
    for(int i=0; i<n; i++){
        cout<<"Burst Time : ";
        cin>>B[i];
    }
    for(int i=0; i<n; i++){
        cout<<"Priority: ";
        cin>>Pri[i];
    }
    for(int i=0; i<n; i++){
        int pos=i;
        for(int j=i+1; j<n; j++){
            if(Pri[j]<Pri[pos]){
                pos=j;
            }
        }
        int temp=Pri[i];
        Pri[i]=Pri[pos];
        Pri[pos]=temp;
        temp=B[i];
        B[i]=B[pos];
        B[pos]=temp;
        temp=P[i];
        P[i]=P[pos];
        P[pos]=temp;
        temp=A[i];
        A[i]=A[pos];
        A[pos]=temp;
    }
    for(int i=0; i<n; i++){
        int pos=i;
        for(int j=i+1; j<n; j++){
            if(A[j]<A[pos]){
                pos=j;
            }
        }
        int temp=A[i];
        A[i]=A[pos];
        A[pos]=temp;
        temp=Pri[i];
        Pri[i]=Pri[pos];
        Pri[pos]=temp;
        temp=B[i];
        B[i]=B[pos];
        B[pos]=temp;
        temp=P[i];
        P[i]=P[pos];
        P[pos]=temp;
    }
    int total=0;
    for(int i=0; i<n; i++){
        Wt[i]=0;
        for(int j=0; j<i; j++){
            Wt[i]+=B[j];
        }
        total+=Wt[i];
    }
    int avg_w=total/n;
    total=0;
    for(int i=0; i<n; i++){
        Tat[i]=B[i]+Wt[i];
        total+=Tat[i];
    }
    int avg_t=total/n;
    cout<<"Process          Priority          Arrival Time            Burst Time            Waiting Time              Turn Around Time"<<endl;
    for(int i=0; i<n; i++){
        cout<<"  "<<P[i]<<"        "<<Pri[i]<<"         "<<A[i]<<"          "<<B[i]<<"            "<<Wt[i]<<"              "<<Tat[i]<<endl;
    }
    cout<<endl;
    cout<<"Average Waiting Time: "<<avg_w<<endl;
    cout<<"Average Turnaround Time: "<<avg_t<<endl;
    return 0;
}
