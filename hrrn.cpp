#include<iostream>
#include<algorithm>

using namespace std;

struct node{
    char pname[50];
    int btime;
    int atime;
    int wtime;
    float rr=0;
}a[50];

void insert(int n){
    int i;
    for(i=0;i<n;i++){
        cin>>a[i].pname;
        cin>>a[i].atime;
        cin>>a[i].btime;
        a[i].rr=0;
        a[i].wtime=-a[i].atime;
    }
}

bool btimeSort(node a,node b){
    return a.btime < b.btime; 
}

bool atimeSort(node a,node b){
    return a.atime < b.atime; 
}

bool rrtimeSort(node a,node b){
    return a.rr > b.rr; 
}

void disp(int n){
    sort(a,a+n,btimeSort);
    sort(a,a+n,atimeSort);
    int ttime=0,i;
    int j,tArray[n];
    for(i=0;i<n;i++){
        j=i;
        while(a[j].atime<=ttime&&j!=n){
            j++;
        }
        for(int q = i;q<j;q++){
            a[q].wtime=ttime-a[q].atime;
            a[q].rr=(float)(a[q].wtime+a[q].btime)/(float)a[q].btime;
        }
        sort(a+i,a+j,rrtimeSort);
        tArray[i]=ttime;
        cout<<endl;
        ttime+=a[i].btime;
    }
    tArray[i] = ttime;
    float averageWaitingTime=0;
    float averageResponseTime=0;
    float averageTAT=0;
    cout<<"\n";
    cout<<"Name  AT\tBT\tCT\tTAT\tWT"<<endl;
    for (i=0; i<n; i++){
        cout <<'P'<< a[i].pname << "\t"; 
        cout << a[i].atime << "\t";
        cout << a[i].btime << "\t";
        cout << tArray[i+1] << "\t"; 
        cout << tArray[i+1]-a[i].atime<< "\t"; 
        averageTAT+=tArray[i+1]-a[i].atime;
        cout << a[i].wtime << "\t"; 
        averageWaitingTime+=a[i].wtime;
        cout<<endl;
    }
    cout<<endl;
    cout<<"Average WT: "<<(float)averageWaitingTime/(float)n<<endl;
    cout<<"Average TAT: "<<(float)averageTAT/(float)n<<endl;
}

int main(){
    int nop,choice,i;
    cout<<"number of processes: ";
    cin>>nop;
    cout<<"Name AT & BT of processes: "<<endl;
    insert(nop);
    disp(nop);
    return 0;
}
