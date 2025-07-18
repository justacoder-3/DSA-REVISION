#include <iostream>
using namespace std;

int main(){
    int n1,count=0;
    cout<<"Enter the number ";
    cin>>n1;
    for(int i=1;i<=n1;i++){
        if(n1%i==0){
            cout<<i<<" ";
            count++;
        }
        // else{
        //     cout<<"Not a divisor "<<i<<"\n";
        // }
    }
    cout<<"Count="<<count;
}