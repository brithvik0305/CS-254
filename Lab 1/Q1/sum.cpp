#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int m1,m2;
    if(a[1]>=a[0]){
        m1=a[1];
        m2=a[0];
    }else{
        m1=a[0];
        m2=a[1];
    }
    for(int i=2;i<n;i++){
        if(a[i]>=m1){
            m2=m1;
            m1=a[i];
        }else if(a[i]>=m2){
            m2=a[i];
        }
    }
    cout << m1+m2 << endl;
    return 0;
}