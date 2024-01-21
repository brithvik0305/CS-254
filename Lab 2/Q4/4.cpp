#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int customPartition(ll data[], ll left, ll right) {
    ll pivot = data[right];
    ll i = left, j = left;
    while (j < right) {
        if (data[j] < pivot) {
            swap(data[i], data[j]);
            i++;
        }
        j++;
    }
    swap(data[i], data[right]);
    return i;
}

void customMedian(ll data[], ll left, ll right, ll k, ll &resultA, ll &resultB) {
    if(left <= right) {
        ll size = right - left + 1;
        ll pivotIndex = rand() % size;
        swap(data[left + pivotIndex], data[right]);
        ll partitionIndex = customPartition(data, left, right);

        if(partitionIndex == k) {
            resultB = data[partitionIndex];
            if(resultA != -1) {
                return;
            }
        }
        else if(partitionIndex == k - 1) {
            resultA = data[partitionIndex];
            if(resultB != -1) {
                return;
            }
        }

        if(partitionIndex >= k) {
            customMedian(data, left, partitionIndex - 1, k, resultA, resultB);
        }
        else {
            customMedian(data, partitionIndex + 1, right, k, resultA, resultB);
        }
    }
    return;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("custom_output.txt", "w", stdout); 

    ll customSize;
    cin >> customSize;

    ll resultA = (customSize & 1) ? -1 : 0, resultB = -1; 

    ll customArray[customSize];
    for(int i = 0; i < customSize; i++) cin >> customArray[i];

    customMedian(customArray, 0, customSize - 1, customSize / 2, resultA, resultB);

    if(customSize & 1) cout << "Median is " << resultB << "\n";
    else cout << "Medians are " << resultA << " and " << resultB << "\n";
}
