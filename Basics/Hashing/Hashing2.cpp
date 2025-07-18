#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout<<"Enter the string: \n";
    cin>>s;

    int hash[26]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']+=1;
    }

    int q;
    cout<<"For how many characters do you want the frequency for ?\n";
    cin>>q;
    while(q--){
        char c;
        cout<<"Enter the character: \n";
        cin>>c;
        cout<<"The frequency is: "<<hash[c-'a']<<endl;
    }
    return 0;
}

