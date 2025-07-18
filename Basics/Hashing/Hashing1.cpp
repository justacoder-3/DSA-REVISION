#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int hash[13]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]+=1;
    }

    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        cout<<hash[num]<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of the array: \n";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int hash[13]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]+=1;
    }

    cout<<"For how many numbers do you want the frequency ?\n";
    int q;
    cin>>q;
    while(q--){
        int num;
        cout<<"Enter the number you want the frequency for ?\n";
        cin>>num;
        cout<<"The frequency is : "<<hash[num]<<endl;
    }

}
