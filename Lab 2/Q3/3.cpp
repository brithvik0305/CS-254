#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void customMerge(ll data[], ll idx1, ll idx2, ll size) {
    while(idx1 < size && idx2 < size && idx1 < idx2) {
        if(data[idx1] <= data[idx2]) idx1++;
        else {
            ll value = data[idx2];
            ll idx = idx2;
            while(idx != idx1) {
                data[idx] = data[idx - 1];
                idx--;
            }
            data[idx1] = value;
            idx2++;
            idx1++;
        }
    }
}

void customMergeSort(ll data[], ll start, ll end) {
    if(start < end) {
        ll middle = start + (end - start) / 2;
        customMergeSort(data, start, middle);
        customMergeSort(data, middle + 1, end);
        customMerge(data, start, middle, end);
    }
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("custom_output.txt","w",stdout); 

    ll customSize;
    cin >> customSize;

    ll customArray[customSize];
    for(int i = 0; i < customSize; i++) cin >> customArray[i];

    customMergeSort(customArray, 0, customSize - 1);

    cout << "After sorting with inplace algo : \n";
    for(int i = 0; i < customSize; i++) cout << customArray[i] << " ";
}
