//File: Q5. Top 10 players.cpp
// Purpose: print an updated version of top 10 players 
// Author: Eslam Sayed Younus
// Section: S9
// ID: 20220495 
// TA: ……………………
// Date: 4 Nov 2023

#include<iostream>
#include<sstream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
struct player
{
    string name;
    int score;
    bool exist {false};
};

player players_arr[11]; // one index help when sorting
int pos_last_player = -1; // save the position of the last player in the list

void view_menu(){
    cout <<"1 - Add new player\n"
         <<"2 - Print the top 10\n"
         <<"3 - Print highest score for a player\n"
         <<"0 - Exit\n"
         << "press a number from the previous menu to make an action\n";
}

void sorting_players_list(){

    if (pos_last_player > 0) { // if not it is not effective to iterate
        for (int i = pos_last_player ; i >= 1; i--) {
            if (players_arr[i].score > players_arr[i - 1].score){
                swap(players_arr[i] , players_arr[i - 1]);
            }
        }
    }
}

void print_list(){
    cout << "TOP 10 players list\n";
    if(pos_last_player >= 10) { // it will not exceed 10 but for insurance
        for(int i = 0; i <= 9; i++) {
            player temp_player = players_arr[i];
            cout << temp_player.name << "       score: " <<temp_player.score << "\n";
        }
    } else {
        for(int i = 0; i <= pos_last_player; i++) {
            player temp_player = players_arr[i];
            cout << temp_player.name << "       score: " <<temp_player.score << "\n";
        }
    }
    cout << "\n\n\n";
}

player defining_player(string name, int score, bool status){
    player new_player;
    new_player.name = name;  
    new_player.score = score;  
    new_player.exist = status;
    return new_player;
}

void add_new_player(){
    string player_name;
    int player_score;
    cout << "enter player's name: ";
    cin >> player_name;
    cout << "enter player's score: ";
    cin >> player_score;
    
    if(pos_last_player < 10) {
        players_arr[++pos_last_player] = player(defining_player(player_name , player_score , 1));
        sorting_players_list();
    } else {
        players_arr[10] = player(defining_player(player_name , player_score , 1)); // overright this out of range position as it is don't care value 
        sorting_players_list();
    }
}

void print_highest_score_for_player(){
    string search_player_name;
    cout << "enter player's name: ";
    cin >> search_player_name;
    for (int i = 0; i <= 10; i++) { // searching over the top 10 only 
        if(players_arr[i].exist == 1 && players_arr[i].name == search_player_name ){
            cout << "The highest score for " << search_player_name << " is: " << players_arr[i].score
                << "\n\n\n";
            break;
        }
    }
    
}

int main(){
    view_menu(); // starting point for the program
    int system_running = 1;
    int input_command;

    while (system_running) {
        cin >> input_command;
        switch (input_command) {
            case 0:
                system_running = 0;
                break;
            case 1:
                add_new_player();
                view_menu();
                break;
            case 2:
                print_list();
                view_menu();
                break;
            case 3:
                print_highest_score_for_player();
                view_menu();
                break;
            default:
                cout << "please enter a valid command number\n";
                view_menu();
                break;
        }
    }
    return 0;
}
