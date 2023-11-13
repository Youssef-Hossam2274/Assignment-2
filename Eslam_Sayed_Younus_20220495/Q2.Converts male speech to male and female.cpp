//File: Q2.Converts male speech to male and female.cpp
// Purpose: Converts male speech to male and female, e.g he---> he or she 
// Author: Eslam Sayed Younus
// Section: S9
// ID: 20220495 
// TA: ……………………
// Date: 2 Nov 2023

#include<iostream>
#include<sstream>
#include<bits/stdc++.h>
using namespace std;

unordered_map<string,string> my_conversion_map;

int main(){
    my_conversion_map.insert({"him" , "him or her"});
    my_conversion_map.insert({"him." , "him or her."});
    my_conversion_map.insert({"him," , "him or her,"});
    my_conversion_map.insert({"him!" , "him or her,"});
    my_conversion_map.insert({"him\"" , "him or her\""});
    my_conversion_map.insert({"him)" , "him or her)"});
    my_conversion_map.insert({"him(" , "him or her("});
    my_conversion_map.insert({"him;" , "him or her;"});
    my_conversion_map.insert({"him?" , "him or her?"});
    my_conversion_map.insert({"him-" , "him or her-"});
    
    my_conversion_map.insert({"his" , "his or her"});
    my_conversion_map.insert({"his." , "his or her."});
    my_conversion_map.insert({"his," , "his or her,"});
    my_conversion_map.insert({"his!" , "his or her,"});
    my_conversion_map.insert({"his\"" , "his or her\""});
    my_conversion_map.insert({"his)" , "his or her)"});
    my_conversion_map.insert({"his(" , "his or her("});
    my_conversion_map.insert({"his;" , "his or her;"});
    my_conversion_map.insert({"his?" , "his or her?"});
    my_conversion_map.insert({"his-" , "his or her-"});


    my_conversion_map.insert({"He" , "He or she"});
    my_conversion_map.insert({"He'" , "He or she'"});
    my_conversion_map.insert({"He." , "He or she."});
    my_conversion_map.insert({"He," , "He or she,"});
    my_conversion_map.insert({"He!" , "He or she,"});
    my_conversion_map.insert({"He\"" , "He or she\""});
    my_conversion_map.insert({"He)" , "He or she)"});
    my_conversion_map.insert({"He(" , "He or she("});
    my_conversion_map.insert({"He;" , "He or she;"});
    my_conversion_map.insert({"He?" , "He or she?"});
    my_conversion_map.insert({"He-" , "He or she-"});
    
    my_conversion_map.insert({"he" , "he or she"});
    my_conversion_map.insert({"he'" , "he or she'"});
    my_conversion_map.insert({"he." , "he or she."});
    my_conversion_map.insert({"he," , "he or she,"});
    my_conversion_map.insert({"he!" , "he or she,"});
    my_conversion_map.insert({"he\"" , "he or she\""});
    my_conversion_map.insert({"he)" , "he or she)"});
    my_conversion_map.insert({"he(" , "he or she("});
    my_conversion_map.insert({"he;" , "he or she;"});
    my_conversion_map.insert({"he?" , "he or she?"});
    my_conversion_map.insert({"he-" , "he or she-"});
    // --------------   Maping for -reasonable- cases that he , He , his , him would occur in the input statement----------
    
    string word , final_string , input_string; 
    // getting the input using getline to catch spaces also with characters
    getline(cin , input_string); 
    // string stream to separte each word as a string to check if it is one of our four keywords  
    stringstream ss(input_string); 
    
    while (ss >> word) {
        // if the word is mapped
        if (my_conversion_map.count(word)) { 
            // getting the value for the key from the map
            string conversion = my_conversion_map[word];
            final_string = final_string + " " + conversion; // concatenating the final string 
        
        } else{
        
            final_string = final_string + " " + word; // concatenating without conversion
        
        }
    }
    cout << final_string;

    return 0;
}
