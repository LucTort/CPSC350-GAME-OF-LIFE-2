#include "Board.cpp"
using namespace std;

class BoardUpdater
{
    public:
        BoardUpdater(); //default constructor
        ~BoardUpdater(); //destructor

        void UpdateBoard(Board&);
        void CopyBoard(Board&, Board&);
        bool DoesCellLive(int, bool);
};