#include <iostream>
using namespace std;

int main(){
    int a,b;
    cout<<"Enter the numbers : ";
    cin>>a>>b;
    if(a==0){
        cout<<b;
    }
    else if(b==0){
        cout<<a;
    }
    while(a!=0 && b!=0){
        if(a>b){
            a=a%b;
        }
        else if(b>a){
            b=b%a;
        }
    }
    cout<<"The GCD is "<<(a==0?b:a);
}