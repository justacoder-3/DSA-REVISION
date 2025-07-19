//Normal approach
#include <bits/stdc++.h>
using namespace std;

void pallindrome(int i,int n,string &s){
    if(i>=s.size()/2){
        return;
    }
    swap(s[i],s[s.size()-i-1]);
    pallindrome(i+1,n,s);
}

int main(){
    string s,s1;
    int i;
    cout<<"Enter the string\n";
    cin>>s;
    s1=s;
    pallindrome(0,s.size(),s);
    cout<<"The reversed string is "<<s<<"\n";
    if(s1==s){
        cout<<"Pallindrome-YES";
    }
    else{
        cout<<"Pallindrome-NO";
    }
}

//Efficient approach
#include <bits/stdc++.h>
using namespace std;

bool pallindrome(int i,int n,string &s){
    if(i>=n/2){
        return true;
    }
    if(s[i]!=s[n-i-1]){
        return false;
    }
    return pallindrome(i+1,n,s);
}

int main(){
    string s;
    int i;
    cout<<"Enter the string\n";
    cin>>s;
    if(pallindrome(0,s.size(),s)){
        cout<<"PALLINDROME-YES\n";
    }
    else{
        cout<<"PALLINDROME-NO\n";
    }
}
