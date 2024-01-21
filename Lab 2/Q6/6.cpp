#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int customPartition(vector<ll>& arr, ll left, ll right){
    ll pivotValue = arr[right];
    ll i = left, j = left;
    while (j < right) {
        if (arr[j] < pivotValue) {
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }
    swap(arr[i], arr[right]);
    return i;
}

void customMedian(vector<ll>& arr, ll left, ll right, ll k, ll& resultA, ll& resultB) {
    if(left <= right){
        ll n = right - left + 1;
        ll pivot = rand() % n;
        swap(arr[left + pivot], arr[right]);
        ll index = customPartition(arr, left, right);

        if(index == k){
            resultB = arr[index];
            if(resultA != -1) {
                return;
            }
        }
        else if(index == k - 1){
            resultA = arr[index];
            if(resultB != -1){
                return;
            }
        }

        if(index >= k){
            customMedian(arr, left, index - 1, k, resultA, resultB);
        }
        else{
            customMedian(arr, index + 1, right, k, resultA, resultB);
        }
    }
    return;
}

int findMedian(vector<ll> arr){
    ll median1 = -1, median2 = -1, size = arr.size();
    customMedian(arr, 0, size-1, size/2, median1, median2);
    return median2;
}

int medianPosition(ll arr[], int left, int right){
    if(left == right) return left;
    vector<ll> subArray;
    for(int i = left; i <= right; i++)
        subArray.push_back(arr[i]);
    int medianValue = findMedian(subArray);
    for(int i = left; i <= right; i++)
        if(arr[i] == medianValue)
            return i;
}

int customPartition(ll arr[], ll left, ll right){
    int pivotIndex = medianPosition(arr, left, right);
    swap(arr[pivotIndex], arr[right]);
    int pivot = arr[right];
    int low = left;
    for(int i = left; i < right; i++){
        if(arr[i] < pivot)
            swap(arr[i], arr[low++]);
    }
    swap(arr[low], arr[right]);
    return low;
}

void customQuickSort(ll arr[], ll low, ll high){
    if(low < high){ 
        int partitionIndex = customPartition(arr, low, high); 
        customQuickSort(arr, low, partitionIndex - 1);
        customQuickSort(arr, partitionIndex + 1, high);
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("custom_output.txt", "w", stdout); 
    
    ll customSize;
    cin >> customSize;

    ll customArray[customSize];
    for(int i = 0; i < customSize; i++) cin >> customArray[i];

    customQuickSort(customArray, 0, customSize - 1);
    for(int i = 0; i < customSize; i++) cout << customArray[i] << " ";
}
