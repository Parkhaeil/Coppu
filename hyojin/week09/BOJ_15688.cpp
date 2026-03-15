#include<iostream>
using namespace std;
int arr[1000001];
int temp[1000001];

void merge(int st,int en) {
    int mid=(st+en)/2;
    int l=st;
    int r=mid;
    for (int i=st;i<en;i++) {
        if (l==mid) temp[i]=arr[r++];
        else if (r==en) temp[i]=arr[l++];
        else if (arr[l]<=arr[r]) temp[i]=arr[l++];
        else temp[i]=arr[r++];
    }
    for (int i=st;i<en;i++) {
        arr[i]=temp[i];
    }
}

void merge_sort(int st,int en) {
    if (en==st+1) return;
    int mid=(st+en)/2;
    merge_sort(st,mid);
    merge_sort(mid,en);
    merge(st,en);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    merge_sort(0,n);
    for (int i=0;i<n;i++) {
        cout << arr[i] << '\n';
    }
}