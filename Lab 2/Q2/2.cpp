#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void customSort(ll data[], ll startIdx1, ll startIdx2, ll size) {
    while(startIdx1 < size && startIdx2 < size && startIdx1 < startIdx2) {
        if(data[startIdx1] <= data[startIdx2]) startIdx1++;
        else {
            ll value = data[startIdx2];
            ll idx = startIdx2;
            while(idx != startIdx1) {
                data[idx] = data[idx - 1];
                idx--;
            }
            data[startIdx1] = value;
            startIdx2++;
            startIdx1++;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("custom_output.txt", "w", stdout);    

    ll size1, size2;
    cin >> size1 >> size2;

    ll customArray[size1 + size2];
    for(int i = 0; i < size1 + size2; i++) cin >> customArray[i];

    customSort(customArray, 0, size1, size1 + size2);

    cout << "Merging with inplace algo : \n";
    for(int i = 0; i < size2 + size1; i++) cout << customArray[i] << " ";
}
