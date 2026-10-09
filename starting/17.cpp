#include <iostream>
#include <vector>
#include <string>

using namespace std;

int count = 0;
vector<string> board(8);

// Backtracking function
void backtrack(int row, int cols, int d1, int d2) {
    // If we reached row 8, we successfully placed 8 queens
    if (row == 8) {
        count++;
        return;
    }
    
    // Try placing a queen in each column of the current row
    for (int col = 0; col < 8; ++col) {
        // Check if the square is free
        if (board[row][col] == '.') {
            // Calculate diagonal identifiers
            // d1 ranges from -7 to 7, so we add 7 to make it 0 to 14
            int diag1 = row - col + 7; 
            // d2 ranges from 0 to 14
            int diag2 = row + col;     
            
            // Check if column or diagonals are already attacked
            bool col_safe = !(cols & (1 << col));
            bool d1_safe  = !(d1 & (1 << diag1));
            bool d2_safe  = !(d2 & (1 << diag2));
            
            if (col_safe && d1_safe && d2_safe) {
                // Place queen by setting the corresponding bits and recurse to next row
                backtrack(row + 1, 
                          cols | (1 << col), 
                          d1 | (1 << diag1), 
                          d2 | (1 << diag2));
            }
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Read the 8x8 board
    for (int i = 0; i < 8; ++i) {
        cin >> board[i];
    }
    
    // Start backtracking from row 0 with empty bitmasks
    backtrack(0, 0, 0, 0);
    
    // Output the result
    cout << count << "\n";
    
    return 0;
}