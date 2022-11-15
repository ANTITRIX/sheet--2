#include <iostream>
#include<fstream>
using namespace std;
const int row = 20, col = 20;
class Universe {
private:
    bool board[row][col] = { {false} };
public:
    Universe(string filename) {
        ifstream file;
        file.open(filename);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                file >> board[i][j];
            }
        }
    }
    void display();
    void run(int n);
    void next_generation();
    int count_neighbors(int x, int y);

};
void Universe::display() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout<< (board[i][j] ? '#' : '.');

        }
        cout << endl;
    }
}
void Universe::next_generation() {
    bool temp[row][col] = { {false} };
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int neighbors = count_neighbors(i, j);
            if (board[i][j] == true) {
                /*if (neighbors < 2) {
                    temp[i][j] = false;
                }*/
                if (neighbors == 2 || neighbors == 3) {
                    temp[i][j] = true;
                }
                else {
                    temp[i][j] = false;
                }
            }
            else {
                if (neighbors == 3) {
                    temp[i][j] = true;
                }
            }
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            board[i][j] = temp[i][j];
        }
    }
}
void Universe::run(int n) {
    for (int i = 0; i < n; i++) {
        //clean the screen
        system("cls");
        cout << "Generation " << i + 1 << ":"
             << endl;
        next_generation();
        display();
        cin.get();
    }
    cout << '\n' << "Game Over" << endl;
}
int Universe::count_neighbors(int x, int y) {
    int count = -board[x][y];
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            count += board[i][j];
        }
    }
    return count;
}


int main() {
    Universe u("input.txt");
    u.display();
    //cout<<u.count_neighbors(1,0);
    //u.next_generation();
    u.run(10);

    return 0;
}