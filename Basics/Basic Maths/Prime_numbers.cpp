#include <iostream>
using namespace std;

int main(){
    int n1,count=0;
    cout<<"Enter the number ";
    cin>>n1;
    for(int i=1;i<=n1;i++){
        if(n1%i==0){
            count++;
        }
    }
    if(count==2){
        cout<<"Prime number ";
    }
    else{
        cout<<"Not a Prime number ";
    }
}