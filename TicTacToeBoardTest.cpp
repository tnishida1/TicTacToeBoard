/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

//horizontal win
TEST(TicTacToeBoardTest, verticalWinTest)
{
	TicTacToeBoard TTT;
	TTT.placePiece(0,1); //x
	TTT.toggleTurn();
	TTT.placePiece(1,2); //o
	TTT.toggleTurn();
	TTT.placePiece(0,0); //x
	TTT.toggleTurn();
	TTT.placePiece(1,1); //o
	//TTT.toggleTurn();
	ASSERT_TRUE(TTT.toggleTurn() == X);
	TTT.placePiece(0,2); //x
	
	//toggle turn after win should still return x
	ASSERT_TRUE(TTT.toggleTurn()==X);
	
	ASSERT_TRUE(TTT.getWinner()==X);

	ASSERT_TRUE(TTT.getPiece(0,1)==X);
	ASSERT_TRUE(TTT.getPiece(0,0)==X);
	ASSERT_TRUE(TTT.getPiece(1,2)==O);
}

//vertical win
TEST(TicTacToeBoardTest, horizontalWinTest)
{
	TicTacToeBoard TTT;
	TTT.placePiece(0,0); //x
	TTT.toggleTurn();
	TTT.placePiece(1,1); //o
	TTT.toggleTurn();
	TTT.placePiece(1,0); //x

	TTT.toggleTurn();
	TTT.placePiece(1,2); //o
	TTT.toggleTurn();
	TTT.placePiece(2,0); //x
	
	ASSERT_TRUE(TTT.getWinner()==X);
}

//diagonal win and O win test
TEST(TicTacToeBoardTest, diag1AndOWinTest)
{
	TicTacToeBoard TTT;
	TTT.placePiece(1,0); //x
	TTT.toggleTurn();
	TTT.placePiece(0,2); //o
	TTT.toggleTurn();
	TTT.placePiece(1,0); //x
	TTT.toggleTurn();
	TTT.placePiece(1,1); //o
	TTT.toggleTurn();
	TTT.placePiece(1,0); //x
	TTT.toggleTurn();
	TTT.placePiece(2,0); //o
	ASSERT_TRUE(TTT.toggleTurn() == O);
	
	ASSERT_TRUE(TTT.getWinner()==O);
}


//diagonal win and O win test
TEST(TicTacToeBoardTest, diag2AndOWinTest)
{
	TicTacToeBoard TTT;
	TTT.placePiece(1,0); //x
	TTT.toggleTurn();
	TTT.placePiece(0,0); //o
	TTT.toggleTurn();
	TTT.placePiece(1,0); //x
	TTT.toggleTurn();
	TTT.placePiece(1,1); //o
	TTT.toggleTurn();
	TTT.placePiece(1,0); //x
	TTT.toggleTurn();
	TTT.placePiece(2,2); //o
	
	ASSERT_TRUE(TTT.getWinner()==O);
}


TEST(TicTacToeBoardTest, getWinnerToggleTest)
{
	TicTacToeBoard TTT;
	TTT.placePiece(0,0); //x
	TTT.toggleTurn();
	TTT.placePiece(1,0); //o
	TTT.toggleTurn();
	TTT.placePiece(0,1); //o
	TTT.toggleTurn();
	TTT.placePiece(1,1); //x
	TTT.toggleTurn();
	TTT.placePiece(0,2); //x
	TTT.toggleTurn();
	ASSERT_TRUE(TTT.toggleTurn()=='X');
}

//return X in tie
TEST(TicTacToeBoardTest, tieTestWorking)
{
	TicTacToeBoard TTT;
	TTT.placePiece(0,0); //x
	TTT.toggleTurn();
	TTT.placePiece(1,0); //o
	TTT.toggleTurn();
	TTT.placePiece(0,1); //o
	TTT.toggleTurn();
	TTT.placePiece(1,1); //x
	TTT.toggleTurn();
	TTT.placePiece(0,2); //x
	TTT.toggleTurn();
	ASSERT_TRUE(TTT.getWinner()=='X');
	ASSERT_TRUE(TTT.toggleTurn()=='X');
}

//return O in tie
TEST(TicTacToeBoardTest, tieTestBug)
{
	TicTacToeBoard TTT;
	TTT.toggleTurn();
	TTT.placePiece(0,0); //o
	TTT.toggleTurn();
	TTT.placePiece(1,0); //x
	TTT.toggleTurn();
	TTT.placePiece(0,1); //o
	TTT.toggleTurn();
	TTT.placePiece(1,1); //x
	TTT.toggleTurn();
	TTT.placePiece(0,2); //o
	TTT.toggleTurn();
	ASSERT_TRUE(TTT.getWinner()=='X');
}


