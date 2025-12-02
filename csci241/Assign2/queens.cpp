/*********************************************
 Eight Queens
 Assignment 2   Csci241

 Author: Milo Zak (z1917365)
         Sebastian Lesny (z1868275)

 Purpose: Write a program that places eight
 	  queens on a chessboard (8 x 8 board)
 	  such that no queen is "attacking"
 	  another.
*********************************************/

#include <iostream>
#include <iomanip>

using namespace std;

#define N 8
/*******************************************
Class: queen_solver

Arugments: bool board -> creates board
	   queen_solver -> solves algorithm
	   		   to place the queens
	   place_queens -> creates queen pawns
	   place_queens_in_row -> puts queens
	   			  on board
	   is_safe -> shows if queens will attack
	   	      each other
	   print_solution -> prints board

Use: Creates 8 queen figures that cannot be
     able to attack one another
*******************************************/
class queen_solver
{
private:

    bool board[N][N] = {{false}};

public:

    queen_solver() = default;
    bool place_queens();
    bool place_queen_in_row(int);
    bool is_safe(int, int) const;
    void print_solution() const;
};


int main()
{
    queen_solver q;

    if (q.place_queens())
        q.print_solution();
    else
        cout << "Error - no solution found\n";

    return 0;
}

bool queen_solver::place_queens()
{
    return place_queen_in_row(0);
}

bool queen_solver::place_queen_in_row(int row)
{
    // Base case #1 - All queens have been placed successfully.
    if (row >= 8)
        return true;

    for (int col = 0; col < N; col++)
    {
        if (is_safe(row, col))
        {
            // Put a queen at board[row][col]
            board[row][col] = true;

            if (place_queen_in_row(row + 1))
                // Base case #2 - All queens in rows below this one
                // have been successfully placed.
                return true;

            // Remove the queen at board[row][col]
            board[row][col] = false;
        }
    }
    
    // Base case #3 - We were not able to place a queen anywhere in 
    // this row.
    return false;
}

bool queen_solver::is_safe(int row, int col) const
{
    // Check the rows above this column. col stays the same, row varies
    // from row - 1 down to 0.
	int i,
	    s;

	    for(i = row-1; i>=0; i--)
	    {
	    	if(board[i][col])
	    	{
	    		return false;
	    	}
	    }

    // Check the left diagonal above this row. col varies from col - 1
    // down to 0, row varies from row - 1 down to 0.
	for( s = col-1, i = row-1; i>=0 && s>=0; s--, i--)
	{
		if(board[i][s])
		{
			return false;
		}
	}

    // Check the right diagonal above this row. col varies from col + 1
    // up to 7, row varies from row - 1 down to 0.
    	for(s = col+1, i = row-1; s<N && i>=0; s++, i--)
    	{
    		if(board[i][s])
    		{
    			return false;
    		}
    	}

    return true;
}

void queen_solver::print_solution() const
{
	int i,
	    s;
	//prints queens
	for(i = 0; i<N; i++)
	{
		for(s = 0; s<N; s++)
		{
			if(board[i][s])
			{
				cout<<" 1 ";
			}
			//prints board
			else
			{
				cout<<" 0 ";
			}
		}
	cout<<endl;
	}
}
