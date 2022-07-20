// First Come First Serve
#include <iostream>

using namespace std;

int main()
{
	int n=0;
	cout<<"Size of array: ";
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
	    cin>>arr[i];
	}
	int head;
	cout<<"Head: ";
	cin>>head;
	int seek_count=0;
	int distance, cur_track;
	for (int i = 0; i < n; i++) {
		cur_track = arr[i];
		distance = abs(cur_track - head);
		seek_count += distance;
		head = cur_track;
	}
	cout << "number of seek operations = "<< seek_count << endl;
	cout << "Seek Sequence is: " << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}
