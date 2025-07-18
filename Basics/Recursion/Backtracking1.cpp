#include<bits/stdc++.h>
using namespace std;

void backtracking1(int n){
    if(n<=1){
        return;
    }
    n--;
    backtracking1(n);
    cout<<n<<"\n";
}

int main(){
    int n;
    cout<<"Enter the value of n\n";
    cin>>n;
    backtracking1(n+1);
}
