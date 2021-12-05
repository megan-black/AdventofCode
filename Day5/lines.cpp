#include "lines.h"

int main()
{
    ifstream fin;
    fin.open("./input.txt");

    vector<vector<int> > grid;
    allocate_grid(grid);

    string cur_line;
    int a = 0;
    while(!fin.eof())
    {
        /* Getting the coordinates!! */
        fin >> cur_line;
        int x1, y1, x2, y2;
        string sx1, sx2, sy1, sy2;
        //x1 y1
        stringstream s_stream(cur_line);
        getline(s_stream, sx1, ',');
        x1 = stoi(sx1);
        getline(s_stream, sy1, '\n');
        y1 = stoi(sy1);
        // -->
        fin >> cur_line;
        // x2 y2
        fin >> cur_line;
        stringstream s_stream2(cur_line);
        getline(s_stream2, sx2, ',');
        x2 = stoi(sx2);
        getline(s_stream2, sy2, '\n');
        y2 = stoi(sy2);
        
        /* mark the parts where line is */
        draw_line(grid, x1, y1, x2, y2);
        // print_board(grid);
        // break;
    }
    /* check how many points are > 1 */
    cout << "Count: " << count_intersections(grid) << endl;
}

void allocate_grid(vector<vector<int> > &grid)
{
    vector<int> temp;
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            temp.push_back(0);
        }
        grid.push_back(temp);
    }
}

void draw_line(vector<vector<int> > &grid, int x1, int y1, int x2, int y2)
{
    // 424,924 -> 206,706
    int xdelta = x2 - x1;
    int ydelta = y2 - y1;
    if(!xdelta && !ydelta)
            return;
    else if(!xdelta && ydelta){ // vertical
        int x = x1;
        int ybegin = (y1 < y2 ? y1 : y2);
        for(int y = ybegin; y <= ybegin + abs(ydelta); ++y)
            grid[x][y] += 1;
    }
    else if(xdelta && !ydelta){ // horizontal
        int y = y1;
        int xbegin = (x1 < x2 ? x1 : x2);
        for(int x = xbegin; x <= xbegin + abs(xdelta); ++x){
            grid[x][y] += 1;
        }
    }

    /* Adding diagonal for part 2, remove to get part 1 result */
    else {
        int cx = x1, cy = y1;
        int sign_x = (x1 < x2 ? 1 : -1);
        int sign_y = (y1 < y2 ? 1 : -1); 
        while(cx != x2 and cy != y2){
            grid[cx][cy] += 1;
            cx = cx + sign_x;
            cy = cy + sign_y;
        }
        grid[cx][cy] += 1;
    }
}

int count_intersections(vector<vector<int> > grid)
{
    int count = 0;
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            if(grid[i][j] > 1)
                count++;
        }
    }
    return count;
}

void print_board(vector<vector<int> > grid)
{
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++)
            cout << grid[i][j] << ' ';
        cout << endl;
    }
}