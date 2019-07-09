#include <bits/stdc++.h>
using namespace std;

class HandsShaking{
public:
    long countPerfect(int n){
        long array[50];
        array[0] = 1;
        array[2] = 1;
        array[4] = 2;
        for (int i = 6; i <= n; i = i+2){
            long sum = 0;
            for (int j = 0; j < i; j = j+2){
                sum += array[j] * array[i-j-2];
            }
            array[i] = sum;
        }
        return array[n];
    }
};