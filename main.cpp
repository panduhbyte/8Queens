#include <iostream>
using namespace std;

void trace(int, int); // Backtracks to find all possible solutions.
bool safe(int, int); // Returns true if no other Qs can attack
int row[10];

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
                cout<<row[1]<<row[2]<<row[3]<<row[4];
                cout<<row[5]<<row[6]<<row[7]<<row[8]<<endl;
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