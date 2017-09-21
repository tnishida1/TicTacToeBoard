#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
	// if there is no value for turn of X or O, assume that its the first turn and it should be X
	//constructor wasn't called before toggleTurn
	//if getwinner is not turn, so if its x, it can be Blank, Invalid, y.
	//or y, blank, invalid, x

	if(getWinner() == turn) 
	{
		return turn;
	}
	else if(getWinner() == Blank) //and and an or
	{
		return X;
	}
	else
	{
		if(turn == X)
		{
			turn = O;
			return O;
		}
		else if(turn == O)
		{
			turn = X;
			return X;
		}
	}
	//return Blank;
}
	//if there is a winner you dont need to toggleTurn anymore
	//return Invalid;

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
	board[row][column] = turn;
	return Invalid;
	//return Invalid;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
	return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
	for(int i=0;i<3;i++)
	{
		// Checks for vertical win
		if (board[0][i] != Blank && board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return turn;
		// Checks for horizontal win
		else if (board[i][0] != Blank && board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return turn;
	}
	//diag win 1
	if(board[0][0] != Blank && board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return turn;
	//diag win 2
	else if(board[0][2] != Blank && board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return turn;
	else //check for invalid, no win TIE
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(board[i][j] == Blank)
				return Invalid;
			}
		}
	}
	return Blank;
}
