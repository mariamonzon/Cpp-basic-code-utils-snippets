#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <iomanip>
#include <set>

using namespace std;

double mean( vector<int>a, int n){
    double sum = 0.0; 
    for(int i = 0; i < n; i++) {
        sum += a[i]; 
    }
   return sum/(double)n;
}

double mean( vector<int>a,vector<int>w, int n){
  // Compute weighted mean 
  double mulsum = 0;
  double wsum = 0;
  for (int i = 0; i < n; i++) {
      mulsum += a[i] * w[i];
      wsum += w[i];
    }
  return mulsum / wsum;
  }

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    // Read the input values
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    double sum = 0.0; 
    for(int i = 0; i < n; i++) {
        sum += a[i]; 
    }
    // Compute the mean
    double mean =  sum / (double)n;
    
    // Compute the median
    sort(begin(a), end(a));
    double median = a[n / 2];
    // If n is odd
    if ( !(n % 2) ) {
        median = (median + a[n / 2 - 1])/2;
    }
    // Order the arrays to compute the mode
    map<int, int> f;
    int mode = 0;
    for (int elem : a) {
        f[elem]++;
    }
    for (auto elem : f) {
        if (elem.second > f[mode]) {
            mode = elem.first;
        }
    }
    
    //Print results
    cout<<fixed;         
    cout.precision(1);
    cout << mean << endl;
    cout << median << endl;
    cout << mode << endl;

    return 0;
