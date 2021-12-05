#ifndef BINGO_H
#define BINGO_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Dict {
    bool marked;
    int value;
};

void load_file(vector<int>&);
vector<int> process_nums(string);
vector<int> process_line(string line);
void print_board(vector<vector<struct Dict> > board);
int check_board_win(vector<vector<struct Dict> > &board, vector<int> nums);
void search_board(vector<vector<struct Dict> > &board, int n);
bool check_win(vector<vector<struct Dict> > board);
int determine_score(vector<vector<struct Dict> > board);



#endif