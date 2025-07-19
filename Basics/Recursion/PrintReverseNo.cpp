//Prints Reverse numbers
#include<bits/stdc++.h>
using namespace std;

void reversenumbers(int n,int i){

    if(n==0){
        return;
    }
    cout<<n<<"\n";
    n--;
    reversenumbers(n,i);
}

int main(){
    int n;
    cout<<"Enter the value of n\n";
    cin>>n;
    cout<<"The numbers are :\n";
    reversenumbers(n,1);
}