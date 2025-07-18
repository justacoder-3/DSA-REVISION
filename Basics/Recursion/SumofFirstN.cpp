//Sum of first n natural numbers
#include<bits/stdc++.h>
using namespace std;

int sum(int count,int n){
    if(n==0){
        return count;
    }
    count=count+n;
    n--;
    return sum(count,n);
}

int main(){
    int n;
    cout<<"Enter the number\n";
    cin>>n;
    int a=sum(0,n);
    cout<<a;
}

//Little bit Optimized way of the first method
#include<bits/stdc++.h>
using namespace std;

int sum(int count,int n){
    if(n==0){
        return count;
    }
    return sum(count+n,n-1);
}

int main(){
    int n;
    cout<<"Enter the number\n";
    cin>>n;
    int a=sum(0,n);
    cout<<a;
}

// Sum of first n numbers using recursion
#include<bits/stdc++.h>
using namespace std;

int sum1(int n){
    int count;
    if(n==1){
        return 1;
    }
    return count=n+sum1(n-1);
}

int main(){
    int n;
    cout<<"Enter the number\n";
    cin>>n;
    int a=sum1(n);
    cout<<a;
}

//Factorial
#include <bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n==1){
        return 1;
    }
    return n*factorial(n-1);
}

int main(){
    int n,f;
    cout<<"Enter the number \n";
    cin>>n;
    f=factorial(n);
    cout<<f;
}