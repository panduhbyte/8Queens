#include <iostream>
#include <stdlib.h> // For rand
using namespace std;

void trace(int, int); // Backtracks to find all possible solutions.
bool safe(int, int); // Returns true if no other Qs can attack
void pBoard(); // Print Board
int row[10];
int count = 1;

int main(){
    trace(1,8);

    return 0;
}

void trace(int xTwo,int board){
    for(int xOne = 1 ; xOne <= board ;xOne++){
        if(safe(xTwo, xOne)){
            // Safely moving on to next row.
            row[xTwo] = xOne;
            if (xTwo==board){
                cout<<"Solution Number: "<<count<<endl;
                count++;
                cout<<row[1]<<row[2]<<row[3]<<row[4];
                cout<<row[5]<<row[6]<<row[7]<<row[8]<<endl;
                pBoard();
                cout<<endl;
            }else{
                trace(xTwo+1,board);
            }
        }
    }
}

bool safe(int xTwo , int xOne){
    for(int yOne = 1; yOne<=(xTwo-1); yOne++){
        // Checks if columns and diagonals are safe.
        if((row[yOne] == xOne) || (abs(row[yOne] - xOne) == abs(yOne - xTwo))){
            return false;
        }
    }
    return true;
}

void pBoard(){
    int hold;
    for(int i = 1; i <= 8; i++){
        hold = row[i];
        for(int j = 1; j <= 8; j++){
            if(hold == j) cout<<"1,";
            else cout << "0,";
        }
        cout << endl;
    }
}