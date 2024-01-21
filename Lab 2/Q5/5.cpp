#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("custom_output.txt", "w", stdout); 

    ll customSize;
    cin >> customSize;

    ll customArray[customSize];
    for(int i = 0; i < customSize; i++) cin >> customArray[i];

    int firstMin = INT_MAX;
    int secondMin = INT_MAX;

    for(int i = 0; i < customSize; i++) {
        if(customArray[i] <= firstMin) {
            secondMin = firstMin;
            firstMin = customArray[i];
        }
        else if(customArray[i] < secondMin) {
            secondMin = customArray[i];
        }
    }

    cout << "First : " << firstMin << "\nSecond : " << secondMin << "\n";
}
