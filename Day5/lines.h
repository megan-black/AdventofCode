#ifndef LINES_H
#define LINES_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void allocate_grid(vector<vector<int> > &grid);
void draw_line(vector<vector<int> > &grid, int x1, int y1, int x2, int y2);
int count_intersections(vector<vector<int> > grid);
void print_board(vector<vector<int> > grid);

#endif