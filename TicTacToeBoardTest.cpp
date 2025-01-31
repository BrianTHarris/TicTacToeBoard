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
ASSERT_EQ(X, temp);

}

TEST(TicTacToeBoardTest, placepieceoutofbounds)
{
TicTacToeBoard ex;
Piece temp=ex.placePiece(4,4);
ASSERT_EQ(Invalid, temp);
temp = ex.toggleTurn();
ASSERT_EQ(X, temp);
}

TEST(TicTacToeBoardTest, placepieceinbounds)
{
TicTacToeBoard ex;
Piece temp=ex.placePiece(2,1);
ASSERT_EQ(X, temp);
}

TEST(TicTacToeBoardTest, placepieceoccpiedspot)
{
TicTacToeBoard ex;
ex.placePiece(2,1);
Piece temp=ex.placePiece(2,1);
ASSERT_EQ(X, temp);
}

TEST(TicTacToeBoardTest, getpieceoccpiedspot)
{
TicTacToeBoard ex;
ex.placePiece(2,1);
Piece temp=ex.getPiece(2,1);
ASSERT_EQ(X, temp);
}
TEST(TicTacToeBoardTest, getpieceblankspot)
{
TicTacToeBoard ex;
ex.placePiece(2,1);
Piece temp=ex.getPiece(0,1);
ASSERT_EQ(Blank, temp);
}

TEST(TicTacToeBoardTest, getpieceoutofbounds)
{
TicTacToeBoard ex;
ex.placePiece(2,1);
Piece temp=ex.getPiece(4,1);
ASSERT_EQ(Invalid, temp);
}

TEST(TicTacToeBoardTest, getwinnerdiagnoldown)
{
TicTacToeBoard ex;
ex.placePiece(1,1);//x
ex.placePiece(1,1);//o
ex.placePiece(0,0);//x
ex.placePiece(1,1);//o
ex.placePiece(2,2);//x
ASSERT_EQ(X,ex.getWinner());
}

TEST(TicTacToeBoardTest, getwinnerdiagnolup)
{
TicTacToeBoard ex;
ex.placePiece(0,0);//x
ex.placePiece(1,1);//o
ex.placePiece(0,0);//x
ex.placePiece(2,0);//o
ex.placePiece(2,2);//x
ex.placePiece(0,2);//o
ASSERT_EQ(O,ex.getWinner());
}

TEST(TicTacToeBoardTest, getwinnerdiagnoldownO)
{
TicTacToeBoard ex;
ex.placePiece(4,4);//x
ex.placePiece(1,1);//o
ex.placePiece(1,1);//x
ex.placePiece(0,0);//o
ex.placePiece(1,1);//x
ex.placePiece(2,2);//o
ASSERT_EQ(O,ex.getWinner());
}

TEST(TicTacToeBoardTest, getwinnerdiagnolupX)
{
TicTacToeBoard ex;
//ex.placePiece(0,0);//x
ex.placePiece(1,1);//x
ex.placePiece(0,0);//o
ex.placePiece(2,0);//x
ex.placePiece(2,2);//o
ex.placePiece(0,2);//x
ASSERT_EQ(X,ex.getWinner());
}

TEST(TicTacToeBoardTest, getwinnersidetoside)
{
TicTacToeBoard ex;
ex.placePiece(0,0);//x
ex.placePiece(1,1);//o
ex.placePiece(0,0);//x
ex.placePiece(1,0);//o
ex.placePiece(2,2);//x
ex.placePiece(1,2);//o
ASSERT_EQ(O,ex.getWinner());
}

TEST(TicTacToeBoardTest, getwinnersvert)
{
TicTacToeBoard ex;
ex.placePiece(0,0);//x
ex.placePiece(1,1);//o
ex.placePiece(0,0);//x
ex.placePiece(0,1);//o
ex.placePiece(2,2);//x
ex.placePiece(2,1);//o
ASSERT_EQ(O,ex.getWinner());
}

TEST(TicTacToeBoardTest, getwinnerblankspot)
{
TicTacToeBoard ex;
//ex.placePiece(0,1);
//ex.placePiece(0,2);
//ex.placePiece(2,2);
//ex.placePiece(2,1);
//ex.placePiece(1,1);
ASSERT_EQ(Invalid,ex.getWinner());
}

TEST(TicTacToeBoardTest, tiegame)
{
TicTacToeBoard ex;
ex.placePiece(0,1);
ex.placePiece(0,2);
ex.placePiece(2,2);
ex.placePiece(2,1);
ex.placePiece(1,1);
ex.placePiece(1,2);//o
ex.placePiece(1,0);//x
ex.placePiece(0,0);//o
ex.placePiece(2,0);//x
ASSERT_EQ(Blank, ex.getWinner());
}

TEST(TicTacToeBoardTest, invalidcalltoplacepiece)
{
TicTacToeBoard ex;
ex.placePiece(0,0);//x
ex.placePiece(1,1);//o
ex.placePiece(0,0);//x
ex.placePiece(0,1);//o
ex.placePiece(2,2);//x
ex.placePiece(2,1);//o
ASSERT_EQ(Invalid,ex.placePiece(0,2));
}
