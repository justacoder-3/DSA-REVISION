#include <iostream>
using namespace std;

int main(){
    int n1,n2,a,count=0;
    cout<<"Enter the number ";
    cin>>n1;
    n2=n1;
    if(n2>0){
        while(n2>0){
            a=n2%10;
            count=(count*10)+a;
            n2=n2/10;
        }
        cout<<count<<"\n";
        if(count==n1){
            cout<<"Yes, its a Pallindrome \n";
        }
        else{
            cout<<"Nope, not a Pallindrome";
        }
    }
    else{
        cout<<"Number must be greater than zero ";
    }
}