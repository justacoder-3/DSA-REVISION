#include<bits/stdc++.h>
using namespace std;

void name(int i,int n){
    if(i>n){
        return;
    }
    cout<<"Rama\n";
    i++;
    name(i,n);
}

int main(){
    int n;
    cout<<"Enter the value of n\n";
    cin>>n;
    name(1,n);
}