//File: Q8. Fractal Pattern.cpp
// Purpose: Print a specific pattern of asterisks
// Author: Eslam Sayed Younus
// Section: S9
// ID: 20220495 
// TA: ……………………
// Date: 2 Nov 2023

#include<iostream>
#include<sstream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

void print_char(string ch , int l){ // print char l times
    for (int i = 0; i < l; i++) {
        cout << ch;
    }
}

int number_of_asterisks(int l , int n){ // how many stars in even order lines
    // l is the current in recursion call  and n is the first n ever entered from the user 
    for (;l % n != 0;) {
        n /= 2;
    } 
    return n;
}

bool even_or_odd(int m){
    if(m % 2 == 0){
        return 1; // even
    }
    return 0; // odd
}

int indexing(int l){
    if (even_or_odd(l)) { // true if even
        return log2(l); // taking log2 to a multiple of 2 (always integer) 
    }
    return 0; // 0 index  if odd
}

static void half_pattern(int n , int i){
    static int orig_n = n;
    static int sz = n / 2; // sz --> number of repeated patterns of asterisks once
    static vector<int> v(sz , 0); // intiating vector of zeros once [to know how many every multiple of two repeated]
    
    if( n==1 ){ // base case
        print_char("  ",i); print_char( "  " ,v[0] ); cout << "* "  << endl;
        ++v[0]; // first one asterisks is printed 
    } else {
        half_pattern(n - 1 , i);
        int n_asterisks = number_of_asterisks(n , orig_n);
        int idx = indexing(n_asterisks);
        print_char("  ", i); print_char("  " , v[idx]); print_char("* " , n_asterisks);
        v[idx] += n_asterisks; // remark that we have printed another one of that number of asterisks
        cout << endl;
    }
}

void pattern(int n , int i){
    half_pattern(n , i); // first half
    half_pattern(n - 1 , i); // second half
}

int main(){
    int n , i;
    cin >> n >> i;
    pattern(n, i);
    return 0;
}
