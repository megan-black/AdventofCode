#include "bingo.h"

int main() {
    
    vector <int> nums;
    // loads the input and calls functions to check winning boards 
    // and eventually prints out winning score!
    load_file(nums);
    return 0;
}

void load_file(vector<int> &numbers)
{
    ifstream fin;
    fin.open("./input.txt");
    
    string nums;
    fin >> nums;   
    numbers = process_nums(nums);
    
    vector<vector<struct Dict> > board;
    vector<struct Dict> temp;

    int lowest_win_index = 10000, curr_win_index = 0, curr_score;
    int winning_board = 0, curr_board = 0;;
    while(!fin.eof()){
        struct Dict d;
        string one_num = "";
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                fin >> one_num;
                d.value = stoi(one_num);
                d.marked = 0;
                temp.push_back(d);
            }
            board.push_back(temp);
            temp.clear();
        }
        curr_win_index = check_board_win(board, numbers);
        if(curr_win_index < lowest_win_index) {
            curr_score = determine_score(board);
            lowest_win_index = curr_win_index;
            winning_board = curr_board;
        }
        board.clear();
    }
    int score = curr_score * numbers[lowest_win_index];
    cout << "The winning score is " << score << "!\n";
}

/* Get the vector of ints from the string read from the first line of input */
vector<int> process_nums(string nums_str)
{
    stringstream str_stream(nums_str);  
    string inter;
    vector<int> nums;
    while(getline(str_stream, inter, ','))
        nums.push_back(stoi(inter));
    return nums;
}

void print_board(vector<vector<struct Dict> > board)
{
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++)
            cout << board[i][j].marked << ' ';
        cout << endl;
    }
}

int check_board_win(vector<vector<struct Dict> > &board, vector<int> nums)
{
    int n;
    for(n = 0; n < nums.size(); n++) {
        search_board(board, nums[n]);
        if(check_win(board) == 1) {
            break;
        }
    }
    return n--;
}

void search_board(vector<vector<struct Dict> > &board, int n) 
{
    for(int i = 0; i < 5; i++) 
        for(int j = 0; j < 5; j++)
            if(board[i][j].value == n) {
                board[i][j].marked = 1;
            }
}

bool check_win(vector<vector<struct Dict> > board)
{
    int count = 0;
    // check rows
    for(int i = 0; i < 5; i++) {
        count = 0;
        for(int j = 0; j < 5; j++) {
            if(board[i][j].marked == 1)
                count += 1;
            else   
                continue;
        }
        if(count == 5)
            return 1;
    }

    // check cols
    for(int i = 0; i < 5; i++) {
        count = 0;
        for(int j = 0; j < 5; j++) {
            if(board[j][i].marked == 1)
                count += 1;
            else   
                continue;
        }
        if(count == 5)
            return 1;
    }
    return 0;
}

int determine_score(vector<vector<struct Dict> > board)
{
    int sum_unmarked = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(board[i][j].marked == 0)
                sum_unmarked += board[i][j].value;
        }   
    }
    return sum_unmarked;
}