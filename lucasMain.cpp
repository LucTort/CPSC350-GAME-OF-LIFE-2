// #include "Board.cpp"
#include "ReadFile.cpp"

using namespace std;

int main(int argc, char **argv)
{
    Board *myBoard = new Board();

    BoardUpdater *boardUpdater = new BoardUpdater();

    for(int i = 0; i < 1; ++i)
    {
        myBoard->printBoard();

        boardUpdater->UpdateBoard(*myBoard);
    }




    return 0;
}