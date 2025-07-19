#include<bits/stdc++.h>
using namespace std;

void backtracking2(int i,int n){
    if(i>n){
        return;
    }
    i++;
    backtracking2(i,n);
    cout<<i<<"\n";
}

int main(){
    int n;
    cout<<"Enter the value of n\n";
    cin>>n;
    cout<<"The numbers are \n";
    backtracking2(0,n-1);
}