#include<bits/stdc++.h>
using namespace std;

using ll = long long;

// Merge function
vector<ll> combineArrays(vector<ll> arr1, vector<ll> arr2) {
    if(arr1.size() > arr2.size()) return combineArrays(arr2, arr1);

    vector<ll> Combined(arr1.size() + arr2.size());

    ll ind1 = 0, ind2 = 0, indC = 0;

    while(ind1 < arr1.size()) {
        if(arr1[ind1] <= arr2[ind2]) Combined[indC++] = arr1[ind1++];
        else Combined[indC++] = arr2[ind2++];
    }

    while(ind2 < arr2.size()) {
        Combined[indC++] = arr2[ind2++];
    }
    
    return Combined;
}

// Union function
vector<ll> mergeUniqueArrays(vector<ll> arr1, vector<ll> arr2) {
    if(arr1.size() > arr2.size()) return mergeUniqueArrays(arr2, arr1);

    vector<ll> UniqueMerge;

    ll ind1 = 0, ind2 = 0;

    while(ind1 < arr1.size()) {
        if(arr1[ind1] <= arr2[ind2]) UniqueMerge.push_back(arr1[ind1++]);
        else UniqueMerge.push_back(arr2[ind2++]);
        while(ind1 < arr1.size() && arr1[ind1] == UniqueMerge.back()) ind1++;
        while(ind2 < arr2.size() && arr2[ind2] == UniqueMerge.back()) ind2++;
    }

    while(ind2 < arr2.size()) {
        UniqueMerge.push_back(arr2[ind2++]);
        while(ind2 < arr2.size() && arr2[ind2] == UniqueMerge.back()) ind2++;
    }

    return UniqueMerge;
}

// Intersection function
vector<ll> commonElements(vector<ll> arr1, vector<ll> arr2) {
    if(arr1.size() > arr2.size()) return commonElements(arr2, arr1);

    vector<ll> Common;

    ll ind1 = 0, ind2 = 0;

    while(ind1 < arr1.size() && ind2 < arr2.size()) {
        if(arr1[ind1] == arr2[ind2]){
            if (Common.empty() || Common.back() != arr1[ind1]) Common.push_back(arr1[ind1]);
            ind1++;
            ind2++;
        }
        while(ind1 < arr1.size() && arr1[ind1] < arr2[ind2]) ind1++;
        while(ind2 < arr2.size() && arr1[ind1] > arr2[ind2]) ind2++;
    }
    
    return Common;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);    

    ll size1, size2;
    cin >> size1 >> size2;

    vector<ll> array1(size1), array2(size2);

    for(int i = 0; i < size1; i++) cin >> array1[i];
    for(int i = 0; i < size2; i++) cin >> array2[i];

    vector<ll> Combined, UniqueMerge, Common;

    Combined = combineArrays(array1, array2);
    cout << "Merge : \n";
    for(auto x: Combined) cout<<x<<" ";

    UniqueMerge = mergeUniqueArrays(array1, array2);
    cout << "\n\nUnion :\n";
    for(auto x: UniqueMerge) cout<<x<<" ";

    Common = commonElements(array1, array2);
    cout << "\n\nIntersection : \n";
    for(auto x: Common) cout<<x<<" ";
}
