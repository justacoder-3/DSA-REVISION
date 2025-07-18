#include <iostream>
using namespace std;

int main(){
    int n,a,count=0;
    cout<<"Enter the number ";
    cin>>n;
    if(n>0){
        while(n>0){
            a=n%10;
            n=n/10;
            count=count+1;
            cout<<"Digit = "<<a<<" "<<"Count = "<<count<<"\n";
        }
        cout<<"Final count : "<<count;
    }
    else{
        cout<<"Number must be greater than 0 ";
    }
}