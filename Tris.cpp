#include <iostream>
#include <sstream>
using namespace std;
 
string tris[3][3];
int cell[2];
 
string int_to_str(int x) {
   stringstream ss;
   ss << x;
   return ss.str();
}
 
void loadMatrix(string tris[3][3]){
    int counter=0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            tris[i][j] = "|" + int_to_str(counter++);
        }
    }
}
 
void showMatrix(string tris[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tris[i][j];
            if (j == 2) cout << endl;
        }
    }
}
 
int findPos (string tris[3][3], int pos){
    int find = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tris[i][j] == "|" + int_to_str(pos)) {
                cell[0] = i;
                cell[1] = j;
                find = 1;
            }
        }
    }
    return find;
}
 
int setMatrix(string tris[3][3], int pos, string symbol){
    int set = 0;
    if (findPos(tris,pos) == 1) {
        tris[cell[0]][cell[1]] = "|" + symbol;
        set = 1;
    }
    else cout << "Invalid location!\n";
    return set;
}
 
int main() {
     
    string player1, player2, run, symbol;
    run = "y";
    int hand, pos;  
    loadMatrix(tris);
    showMatrix(tris);
    hand = 1;
    do {
        switch(hand){
            case 1:
                symbol = "X";
                do {
                    cout << endl;
                    cout << "[PLAYER 1] indicates location: ";
                    cin >> pos;
                } while (!setMatrix(tris,pos,symbol));
                hand = 2;
                showMatrix(tris);
                break;
            case 2:
                symbol = "O";
                do {
                    cout << endl;
                    cout << "[PLAYER 2] indicates location: ";
                    cin >> pos;
                } while(!setMatrix(tris, pos, symbol));
                hand = 1;
                showMatrix(tris);
                break;
        }
        cout << "Do you want to continue? [y / n]: ";
        cin >> run; 
        cout << endl;
    } while (run == "y");
        if (run == "n") {
            cout << "Game over" << endl;
        }
     
    return 0;
}