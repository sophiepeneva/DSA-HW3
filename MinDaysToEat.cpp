# DSA-HW3

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void minDaysToEat(vector<int> chocolateBox, long long average, long long& days) {
    if (chocolateBox.size() == 0)return;
    vector<int> eatenBox;
    long long sum = 0;
    for (int i = 0;i < chocolateBox.size();i++) {
        if (chocolateBox[i] - average < 0) {
            eatenBox.push_back(chocolateBox[i]);
            sum += chocolateBox[i];
        }
        if (chocolateBox[i] - average > 0) {
            eatenBox.push_back(chocolateBox[i] - average);
            sum += (chocolateBox[i] - average);
        }
    }
    if (eatenBox.empty()) {
        days++;
        return;
    }
    average = (sum%eatenBox.size() == 0) ? sum / eatenBox.size() : (sum / eatenBox.size() + 1);
    minDaysToEat(eatenBox, average, ++days);
}

void minDaysToEatArray(int* chocolateBox, int n, long long average, long long& days) {
    long long sum = 0;
    long long totalSlots = 0;
    int newArrSize = (n - average > average - 1) ? n - average : average - 1;
    if (newArrSize == 0) {
        days++;
        return;
    }
    int* eatenBox = new int[newArrSize + 1];
    for (int i = 1;i <= newArrSize;i++)eatenBox[i] = 0;
    for (int i = 1; i <= n;i++) {
        if (i - average < 0) {
            eatenBox[i]++;
            sum += i;
            totalSlots++;
        }
        else if (i - average > 0) {
            eatenBox[i - average]++;
            sum += i - average;
            totalSlots++;
        }
    }
    average = (sum%totalSlots == 0) ? sum / totalSlots : sum / totalSlots + 1;
    minDaysToEatArray(eatenBox,newArrSize, average, ++days);
}

int solutionWithArray(int n) {
    long long days = 0;
    if (n != 0) {
        long long average = 0;
        long long sum = 0;
        int* chocolateBox = new int[n+1];
        for (int i = 1;i <= n;i++) {
            chocolateBox[i] = 1;
            sum += i;
        }
        average = (sum%n == 0) ? (sum / n) : (sum / n + 1);
        minDaysToEatArray(chocolateBox, n, average, days);
    }
    return days;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int t;
    cin >> t;
    int* boxes = new int[t];
    for (int i = 0;i < t;i++) {
        cin>>boxes[i];
    }
    for (int i = 0;i < t;i++) {
        cout << solutionWithArray(boxes[i]) << endl;
    }
    return 0;
}
