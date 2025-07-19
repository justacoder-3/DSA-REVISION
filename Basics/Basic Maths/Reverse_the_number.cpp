// Fake Method
#include <iostream>
using namespace std;

int main(){
    int n,a;
    cout<<"Enter the number ";
    cin>>n;
    while(n>0){
        a=n%10;
        n=n/10;
        cout<<a;
    }
    cout<<"\nDone!";
}

// Original Method
#include <iostream>
using namespace std;

int main(){
    int n,a,b=0;
    cout<<"Enter the number ";
    cin>>n;
    while(n>0){
        a=n%10;
        b=(b*10)+a;
        n=n/10;
    }
    cout<<b;
    cout<<"\nDone!";
}