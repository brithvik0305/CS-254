#include <bits/stdc++.h>
using namespace std;
// Time complexity of this code is O(n+k*log n)
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    priority_queue<int> pq(a.begin(), a.end());
    for(int i=0; i<k-1; i++)
        pq.pop();
    cout << k << "th largest element is: " << pq.top() << endl;
}