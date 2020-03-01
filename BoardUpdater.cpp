#include "BoardUpdater.h"

//default constructor
BoardUpdater::BoardUpdater()
{

}



void  BoardUpdater::UpdateBoard(Board& currentBoard)
{
    int surroundingCells = 0;
    Board *placeholderBoard = new Board(currentBoard.width, currentBoard.height);


    //
    //outer loop                                                                          

     for (int xBoard = 0; xBoard < currentBoard.width; ++xBoard)
     {
         for (int yBoard= 0; yBoard < currentBoard.height; ++yBoard)
         {
           //inner loop
           for(int xLocal = -1; xLocal < 2; ++xLocal)
           {
               for(int yLocal = -1; yLocal < 2; ++yLocal)
                {
                    //cout << xLocal << " " << yLocal << ":";
                    
                    if ( ! (
                    (xBoard + xLocal < 0 )
                    || (yBoard + yLocal < 0 ) 
                    || (xBoard + xLocal > (currentBoard.height - 1 ) )
                    || (yBoard + yLocal > (currentBoard.width - 1) )
                    || ( ( (yBoard + yLocal) == 0) && ( (xBoard + xLocal) == 0) )
                    ))
                     {      
                          if (currentBoard.isCellAlive( (xBoard + xLocal) , (yBoard + yLocal) ) )
                          {
                               surroundingCells++;
                               cout << "There is a cell at" <<  (xBoard + xLocal) << " " << (yBoard + yLocal) << endl;
                          }
                          
                    }//if
                    
                }//for
                
           }//for


            //end inner loop

            placeholderBoard->setCellState(xBoard, yBoard, DoesCellLive(surroundingCells, currentBoard.isCellAlive(xBoard, yBoard) ));

            surroundingCells = 0;
         }//for
     }//for
     CopyBoard(*placeholderBoard, currentBoard);
}//UpdateBoard

void  BoardUpdater::CopyBoard(Board& boardToCopy, Board& boardToUpdate)
{
     for (int i = 0; i < boardToCopy.width; ++i)
    {
        for (int j = 0; j < boardToCopy.height; ++j)
        {
           *(*(boardToUpdate.boardArray+i)+j) = *(*(boardToCopy.boardArray+i)+j);
        }
    }
}

bool BoardUpdater::DoesCellLive(int surroundingCells, bool currentState)
{
    //cout << surroundingCells << " ";

    if (surroundingCells >= 4)
        return false;
    else if (surroundingCells == 3)
        return true;
    else if (surroundingCells >= 2)
        return currentState;
    else 
         return false;
}