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

// EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, toggleturntest)
{
TicTacToeBoard ex;
Piece temp = ex.toggleTurn();
ASSERT_EQ(O, temp);

}

TEST(TicTacToeBoardTest, toggleturntest2toggle)
{
TicTacToeBoard ex;
Piece temp = ex.toggleTurn();
temp = ex.toggleTurn();
ASSERT_EQ(O, temp);

}

TEST(TicTacToeBoardTest, placepieceoutofbounds)
{
TicTacToeBoard ex;
Piece temp=ex.placePiece(4,4);
ASSERT_EQ(Invalid, temp);

}
