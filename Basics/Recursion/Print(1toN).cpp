//Print numbers from 1 to n
#include<bits/stdc++.h>
using namespace std;

void numbers(int i,int n){
    if(i==1){
        cout<<"The numbers are \n";
    }
    if(i==n+1){
        return;
    }
    cout<<i<<"\n";
    i++;
    numbers(i,n);
}

int main(){
    int n;
    cout<<"Enter the value of n\n";
    cin>>n;
    numbers(1,n);
}