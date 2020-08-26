#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> board(4, vector<int> (4, 0));

//returns the max number on the board
int max_board() {
    int maxf = INT_MIN;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            maxf = max(maxf, board[i][j]);
        }
    }
    return maxf;
}

//prints the board
void print_board() {
    int maxf = max_board();
    int digits = 0;
    while (maxf) {
        digits++;
        maxf/=10;
    }
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            int temp = board[i][j];
            int digits2 = 0;
            if (temp == 0)
                digits2++;
            else {
                while(temp) {
                    digits2++;
                    temp/=10;
                }
            }
            
            cout<<"| ";
            for (int k=1; k<=digits-digits2; k++)
                cout<<" ";
            cout<<board[i][j]<<" ";
        }
        cout<<"|"<<endl;
    }
}

//checks if board is empty or full
bool check_empty() {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (board[i][j]==0) 
                return true;
        }
    }
    return false;
}

//fills 2 at an empty space
void random_generator() {
    int x = rand()%4;
    int y = rand()%4;

    while (board[x][y] != 0) {
        x = rand()%4;
        y = rand()%4;
    }

    board[x][y] = 2;
}

void move_left() {
    for (int i=0; i<4; i++) {
        vector<bool> check(4, false);
        for (int j=3; j>0; j--) {
            if (board[i][j-1] == 0) {
                board[i][j-1] = board[i][j];
                board[i][j] = 0;
            }
            else if (board[i][j] == board[i][j-1] && check[j] == false) {
                board[i][j-1] = 2*board[i][j-1];
                board[i][j] = 0;
                check[j-1] = true;
            }
        }
    }

    for (int i=0; i<4; i++) {
        for (int j=3; j>0; j--) {
            if (board[i][j-1] == 0) {
                board[i][j-1] = board[i][j];
                board[i][j] = 0;
            }
        }
    }
}

void move_right() {
    for (int i=0; i<4; i++) {
        vector<bool> check(4, false);
        for (int j=0; j<3; j++) {
            if (board[i][j+1] == 0) {
                board[i][j+1] = board[i][j];
                board[i][j] = 0;
            }
            else if (board[i][j] == board[i][j+1] && check[j] == false) {
                board[i][j+1] = 2*board[i][j+1];
                board[i][j] = 0;
                check[j+1] = true;
            }
        }
    }

    for (int i=0; i<4; i++) {
        for (int j=0; j<3; j++) {
            if (board[i][j+1] == 0) {
                board[i][j+1] = board[i][j];
                board[i][j] = 0;
            }
        }
    }
}

void move_up() {
    for (int j=0; j<4; j++) {
        vector<bool> check(4, false);
        for (int i=3; i>0; i--) {
            if (board[i-1][j] == 0) {
                board[i-1][j] = board[i][j];
                board[i][j] = 0;
            }
            else if (board[i][j] == board[i-1][j] && check[i] == false) {
                board[i-1][j] = 2*board[i-1][j];
                board[i][j] = 0;
                check[i-1] = true;
            }
        }
    }

    for (int j=0; j<4; j++) {
        for (int i=3; i>0; i--) {
            if (board[i-1][j] == 0) {
                board[i-1][j] = board[i][j];
                board[i][j] = 0;
            }
        }
    }
}

void move_down() {
    for (int j=0; j<4; j++) {
        vector<bool> check(4, false);
        for (int i=0; i<3; i++) {
            if (board[i+1][j] == 0) {
                board[i+1][j] = board[i][j];
                board[i][j] = 0;
            }

            else if (board[i+1][j] == board[i][j] && check[i] == false) {
                board[i+1][j] = 2*board[i+1][j];
                board[i][j] = 0;
                check[i+1] = true;
            }
        }
    }

    for (int j=0; j<4; j++) {
        for (int i=0; i<3; i++) {
            if (board[i+1][j] == 0) {
                board[i+1][j] = board[i][j];
                board[i][j] = 0;
            }
        }
    }
}



int main() {
    cout<<"Welcome to 2048!"<<endl;
    random_generator();
    random_generator();
    print_board();
    cout<<"Enter first move: ";
    char c;
    cin>>c;

    while (c) {
        if (c=='e')
            break;

        if (max_board() == 2048)
            break;
        
        if (!check_empty()) 
            break;

        if (c=='l') {
            move_left();
            random_generator();
            print_board();
        }
        else if (c=='r') {
            move_right();
            random_generator();
            print_board();
        }
        else if (c=='u') {
            move_up();
            random_generator();
            print_board();
        }
        else if (c=='d') {
            move_down();
            random_generator();
            print_board();
        }
        cout<<"Enter next move: ";
        cin>>c;
    }

    cout<<"Your max score is "<<max_board()<<endl;

    if (max_board() == 2048)
        cout<<"You won!!"<<endl;

    else if (!check_empty())
        cout<<"You lost, loser"<<endl;

    else if (c=='e')
        cout<<"You have chosen to quit. Bye!"<<endl;
    
    return 1;
}

