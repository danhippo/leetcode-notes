#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;
int main(){
    int arr[] = { 1, 2, 3, 4, 5 };
    vector<int> v(arr, arr + 5);

    vector<int>::iterator begin = v.begin();
    vector<int>::iterator end = v.end();

    vector<int>::iterator it;
    for (it = begin; it != end; it++)
    {
        cout << *it << endl;
    }
}