#include <iostream>
using namespace std;

int main(){
    int n1,n2,n3,count=0;
    cout<<"Enter the number ";
    cin>>n1;
    n3=n1;
    if(n1>0){
        while(n1>0){
            n2=n1%10;
            count=count+(n2*n2*n2);
            n1=n1/10;
        }
        cout<<count<<"\n";
        if(count==n3){
            cout<<"Armstrong numbers - True ";
        }
        else{
            cout<<"Armstrong numbers - False ";
        }
    }
    else{
        cout<<"Number is less than zero";
    }
}
