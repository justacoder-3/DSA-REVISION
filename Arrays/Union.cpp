// brute force method (works for both sorted or non sorted arrays)
// #include <bits/stdc++.h>
// using namespace std;

// void unionOfArrays (set <int> s1, set <int> s2) {
//     s1.insert(s2.begin(),s2.end());
//     for (int i : s1) {
//         cout << i << " ";
//     }
// }

// int main () {
//     int n1, num, value;
//     cout << "Enter the number of elements : \n";
//     cin >> n1;
//     set <int> s1;
//     cout<<"Enter the elements of array : \n";
//     for(int i=0; i<n1; i++){
//         cin >> value;
//         s1.insert(value);
//     }
//     int n2;
//     cout << "Enter the number of elements : \n";
//     cin >> n2;
//     set <int> s2;
//     cout<<"Enter the elements of array : \n";
//     for(int i=0; i<n2; i++){
//         cin >> value;
//         s2.insert(value);
//     }

//     unionOfArrays(s1,s2);
// }

// optimal solution (only if the arrays are sorted)
#include <bits/stdc++.h>
using namespace std;

void unionOfArrays (vector <int> s1, vector <int> s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    vector <int> resArr;
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (s1[i] <= s2[j]) {
            if (resArr.size() == 0 || resArr.back() != s1[i]) {
                resArr.push_back(s1[i]);
            }
            i++;
        }
        else {
            if (resArr.size() == 0 || resArr.back() != s2[j]) {
                resArr.push_back(s2[j]);
            }
            j++;                        
        }
    }
    while (i < n1) {
        if ( resArr.size() == 0 || resArr.back() != s1[i] ) {
            resArr.push_back(s1[i]);
        }
        i++;
    }
    while (j < n2) {
        if ( resArr.size() == 0 || resArr.back() != s2[j] ) {
            resArr.push_back(s2[j]);
        }
        j++;
    }  
    
    for (int i = 0; i < resArr.size(); i++) {
        cout << resArr[i] << " ";
    }
}

int main () {
    int n1, value;
    cout << "Enter the number of elements : \n";
    cin >> n1;
    vector <int> s1(n1);
    cout<<"Enter the elements of array : \n";
    for(int i=0; i<n1; i++){
        cin >> s1[i];
    }
    int n2;
    cout << "Enter the number of elements : \n";
    cin >> n2;
    vector <int> s2(n2);
    cout<<"Enter the elements of array : \n";
    for(int i=0; i<n2; i++){
        cin >> s2[i];
    }

    unionOfArrays(s1,s2);

}