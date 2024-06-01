#include "../include/Moves.hpp"
#include "../include/PiecesDef.hpp"
#include <iostream> //debug
static int round(int num)
{
    return (num > 0) ? num : num * -1;
}

/*
     // first diagonal working 
     if (0 <= EndPos.Row && EndPos.Row <= 7 && 0 <= EndPos.Col && EndPos.Col <= 7)
     {
         for (int col = StartPos.Col , row = StartPos.Row ; col <= 7 && row <= 7 ; col++,row++) 
         {
             if (col == EndPos.Col && row == EndPos.Row)
             {
                 return true;
             }
         }
         for (int col = StartPos.Col, row = StartPos.Row; col >= 0 && row >=0; col--, row--) 
         {
             if (col == EndPos.Col && row == EndPos.Row)
             {
                 return true;
             }
         }
         for (int col = StartPos.Col, row = StartPos.Row; col >= 0 && row <= 7; col--, row++) 
         {
             if (col == EndPos.Col && row == EndPos.Row)
             {
                 return true;
             }
         }
         for (int col = StartPos.Col, row = StartPos.Row; col <= 7 && row >= 0; col++, row--) 
         {
             if (col == EndPos.Col && row == EndPos.Row)
             {
                 return true;
             }
         }
     }
     // well now this working good 😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁*/
static bool isBlack(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard , PiecePosition p_NewPosition)
{
    return (0 > p_PieceBoard[p_NewPosition.Row][p_NewPosition.Col]) ? true : false;
}
static bool isWhite(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard , PiecePosition p_NewPosition)
{
    return (0 < p_PieceBoard[p_NewPosition.Row][p_NewPosition.Col]) ? true : false;
}

// Pawn // later add promotion
#pragma region Pawn
bool possibleMoveBlackPawn(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard,const PiecePosition StartPos, const PiecePosition EndPos)
{
    // first all bad move wrting and set to false 
    if (StartPos.Row < 0 || StartPos.Row > 7 || StartPos.Col < 0 || StartPos.Col > 7 ||
        EndPos.Row < 0 || EndPos.Row > 7 || EndPos.Col < 0 || EndPos.Col > 7)
    {
        return false;
    }
    // write the one step move for all
    if (StartPos.Row + 1 == EndPos.Row && StartPos.Col == EndPos.Col)
    {
        if (p_PieceBoard[EndPos.Row][EndPos.Col] == PIECES_TYPE::EMPTY)
            return true;
    }
    // write the two step move for all
    else if (StartPos.Row == 1 && StartPos.Col == EndPos.Col)
    {
        if ( EndPos.Row == 3)
        {
            if (p_PieceBoard[EndPos.Row][EndPos.Col] == PIECES_TYPE::EMPTY)
                return true;
        }
    }
    // write to capture diagonal 
    else if ((StartPos.Col - 1 == EndPos.Col || StartPos.Col + 1 == EndPos.Col) && (StartPos.Row + 1 == EndPos.Row))
    {
        if (p_PieceBoard[EndPos.Row][EndPos.Col] != PIECES_TYPE::EMPTY)
            return true;
    }
    return false;
} // ok it is working 😁😁

 bool possibleMoveWhitePawn(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard,const PiecePosition StartPos, const PiecePosition EndPos)
{
     // first all bad move wrting and set to false 
     if (StartPos.Row < 0 || StartPos.Row > 7 || StartPos.Col < 0 || StartPos.Col > 7 ||
         EndPos.Row < 0 || EndPos.Row > 7 || EndPos.Col < 0 || EndPos.Col > 7)
     {
         return false;
     }
     // write the one step move for all
     if (StartPos.Row - 1 == EndPos.Row && StartPos.Col == EndPos.Col)
     {
         if (p_PieceBoard[EndPos.Row][EndPos.Col] == PIECES_TYPE::EMPTY)
             return true;
     }
     // write the two step move for all
     else if (StartPos.Row == 6 && StartPos.Col == EndPos.Col)
     {
         if (EndPos.Row == 4)
         {
             if (p_PieceBoard[EndPos.Row][EndPos.Col] == PIECES_TYPE::EMPTY)
                 return true;
         }
     }
     // write to capture diagonal 
     else if ((StartPos.Col - 1 == EndPos.Col || StartPos.Col + 1 == EndPos.Col) && (StartPos.Row - 1 == EndPos.Row))
     {
         
         
             if (p_PieceBoard[EndPos.Row][EndPos.Col] != PIECES_TYPE::EMPTY)
                 return true;
         
     }
     return false;

}
#pragma endregion
#pragma region King
 // lets add Castle
 bool possibleMoveKing(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard,const PiecePosition StartPos, const PiecePosition EndPos)
 {
     // write all bad moves so no need to worry
     if (StartPos.Row < 0 || StartPos.Row > 7 || StartPos.Col < 0 || StartPos.Col > 7
         || EndPos.Row < 0 || EndPos.Row > 7 || EndPos.Col < 0 || EndPos.Col > 7)
     {
         return false;
     }
     
     // single move from all side 
     if ((StartPos.Row + 1 >= EndPos.Row && EndPos.Row >= StartPos.Row - 1) &&
         (StartPos.Col + 1 >= EndPos.Col && EndPos.Col >= StartPos.Col - 1))
     {
         return true;
     }
     
     /*// Castle
     if (StartPos.Row + 2 == EndPos.Row || StartPos.Row - 2 == EndPos.Row)
     {
         // Black side 
         if (round(p_PieceBoard[7][7]) == PIECES_TYPE::WHITE_ROOK)
         {
             if ()
             p_PieceBoard[6][6] = p_PieceBoard[7][7];
             p_PieceBoard[7][7] = PIECES_TYPE::EMPTY;
             p_
         }
         // White Side 
     }
     */
     return false;
 }
#pragma endregion
#pragma region Rook
 static bool possibleMoveRook(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard,const PiecePosition StartPos, const PiecePosition EndPos)
 {
     // first all bad move wrting and set to false 
     if (StartPos.Row < 0 || StartPos.Row > 7 || StartPos.Col < 0 || StartPos.Col > 7 ||
         EndPos.Row < 0 || EndPos.Row > 7 || EndPos.Col < 0 || EndPos.Col > 7)
     {
         return false;
     }
     // write all from position of rook up with row
     if (StartPos.Col == EndPos.Col) // this logic is right 
     {
         for (int i = StartPos.Row - 1; i >= 0; i--)
         { 
             if (i == EndPos.Row) 
             {
                 if (p_PieceBoard[i][StartPos.Col] != PIECES_TYPE::EMPTY)
                    return true;
                 return true;
             }
             if (p_PieceBoard[i][StartPos.Col] != PIECES_TYPE::EMPTY)
             {
                 break;
             }
            
         }
         // write all from position of rook down with row
         for (int i = StartPos.Row + 1; i <= 7; i++)
         {
             if (i == EndPos.Row)
             {
                 if (p_PieceBoard[i][StartPos.Col] != PIECES_TYPE::EMPTY)
                     return true;
                 return true;
             }
             if (p_PieceBoard[i][StartPos.Col] != PIECES_TYPE::EMPTY)
             {
                 break;
             }
         }
     }
     // write all from position of rook right with col
     if (StartPos.Row == EndPos.Row)
     {
         for (int i = StartPos.Col - 1 ; i >= 0; i--)
         {
             if (i == EndPos.Col)
             {
                 if (p_PieceBoard[StartPos.Row][i] != PIECES_TYPE::EMPTY)
                     return true;
                 return true;
             }
             if (p_PieceBoard[StartPos.Row][i] != PIECES_TYPE::EMPTY)
             {
                 break;
             }
         }
         // write all from position of rook right with col
         for (int i = StartPos.Col + 1; i <= 7; i++)
         {
             if (i == EndPos.Col)
             {
                 if (p_PieceBoard[StartPos.Row][i] != PIECES_TYPE::EMPTY)
                     return true;
                 return true;
             }
             if (p_PieceBoard[StartPos.Row][i] != PIECES_TYPE::EMPTY)
             {
                 break;
             }
         }
     }
     return false;
 } // this is now working 
#pragma endregion
#pragma region Bishop
 static bool possibleMoveBishop(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard,const PiecePosition StartPos, const PiecePosition EndPos)
 {
     // first all bad move wrting and set to false 
     if (StartPos.Row < 0 || StartPos.Row > 7 || StartPos.Col < 0 || StartPos.Col > 7 ||
         EndPos.Row < 0 || EndPos.Row > 7 || EndPos.Col < 0 || EndPos.Col > 7)
     {
         return false;
     }
     // local declaration of row and col
     int _row = 0, _col = 0;
     // Diagonal 1 upper
     _row = StartPos.Row - 1;
     _col = StartPos.Col - 1;
     while (_row >= 0 && _col >= 0)
     {
         if (_row == EndPos.Row && _col == EndPos.Col)
         {
             if (p_PieceBoard[_row][_col] != PIECES_TYPE::EMPTY)
                 return true;
             return true;
         }
             if (p_PieceBoard[_row][_col] != PIECES_TYPE::EMPTY)
             {
                 break;
             }
             _row--; _col--;
         
     }
     // Diagonal 1 lower
     _row = StartPos.Row + 1;
     _col = StartPos.Col + 1;
     while (_row <= 7 && _col <= 7)
     {
         if (_row == EndPos.Row && _col == EndPos.Col)
         {
             if (p_PieceBoard[_row][_col] != PIECES_TYPE::EMPTY)
                 return true;
             return true;
         }
             if (p_PieceBoard[_row][_col] != PIECES_TYPE::EMPTY)
             {
                 break;
             }
             _row++; _col++;
         
     }
     // first diagonal is working 😁😁
     //Diagonal 2 upper
     _row = StartPos.Row - 1;
     _col = StartPos.Col + 1;
     while (_row >= 0 && _col <= 7)
     {
         if (_row == EndPos.Row && _col == EndPos.Col)
         {
             if (p_PieceBoard[_row][_col] != PIECES_TYPE::EMPTY)
                 return true;
             return true;
         }
         if (p_PieceBoard[_row][_col] != PIECES_TYPE::EMPTY)
         {
             break;
         }
         _row--; _col++;

     }
    // Diagonal 2 lower
     _row = StartPos.Row + 1;
     _col = StartPos.Col - 1;
     while (_row <= 7 && _col >= 0)
     {
         if (_row == EndPos.Row && _col == EndPos.Col)
         {
             if (p_PieceBoard[_row][_col] != PIECES_TYPE::EMPTY)
                 return true;
             return true;
         }
         if (p_PieceBoard[_row][_col] != PIECES_TYPE::EMPTY)
         {
             break;
         }
         _row++; _col--;

     }
     return false;
 }
#pragma endregion
#pragma region Queen
 bool possibleMoveQueen(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard,const PiecePosition StartPos, const PiecePosition EndPos)
 {
     if (0 <= EndPos.Row && EndPos.Row <= 7 && 0 <= EndPos.Col && EndPos.Col <= 7)
     {// well queen have same movement as bishop and rook combine
         if (possibleMoveRook(p_PieceBoard,StartPos, EndPos) || possibleMoveBishop(p_PieceBoard, StartPos, EndPos))
         {
             return true;
         }
     }
     return false;
 }
#pragma endregion
#pragma region Knight
 bool possibleMoveKnight(const PiecePosition StartPos, const PiecePosition EndPos)
 {
     if (0 <= EndPos.Row && EndPos.Row <= 7 && 0 <= EndPos.Col && EndPos.Col <= 7)
     {
         if (StartPos.Row -1 == EndPos.Row && StartPos.Col + -2 == EndPos.Col)
         {
             return true;
         }
         else if (StartPos.Row + 1 == EndPos.Row && StartPos.Col - 2 == EndPos.Col)
         {
             return true;
         }
         else if (StartPos.Row + 2 == EndPos.Row && StartPos.Col - 1 == EndPos.Col)
         {
             return true;
         }
         else if (StartPos.Row - 2 == EndPos.Row && StartPos.Col - 1 == EndPos.Col)
         {
             return true;
         }
         else if (StartPos.Row - 2 == EndPos.Row && StartPos.Col + 1 == EndPos.Col)
         {
             return true;
         }
         else if (StartPos.Row - 1 == EndPos.Row && StartPos.Col + 2 == EndPos.Col)
         {
             return true;
         }
         else if (StartPos.Row + 1 == EndPos.Row && StartPos.Col + 2 == EndPos.Col)
         {
             return true;
         }
         else if (StartPos.Row + 2 == EndPos.Row && StartPos.Col + 1 == EndPos.Col)
         {
             return true;
         }
     }
     return false;
 }


#pragma endregion

bool Moves::VaildMove(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard, PiecePosition p_OldPosition, PiecePosition p_NewPosition)
{
    
    // later handle array for legal move
    bool _WrongMove = true;
    
    int _PIECETYPE = p_PieceBoard[p_OldPosition.Row][p_OldPosition.Col];
    switch (_PIECETYPE)
    {
    case PIECES_TYPE::BLACK_PAWN:
        _WrongMove = (possibleMoveBlackPawn(p_PieceBoard, p_OldPosition, p_NewPosition)) && (!isBlack(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::WHITE_PAWN:
        _WrongMove = ((possibleMoveWhitePawn(p_PieceBoard, p_OldPosition, p_NewPosition)) && (!isWhite(p_PieceBoard,p_NewPosition))) ? true : false;
        break; 
    // its working let's do it to all 
    case PIECES_TYPE::BLACK_KING:
        _WrongMove = (possibleMoveKing(p_PieceBoard,p_OldPosition, p_NewPosition)) && (!isBlack(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::WHITE_KING:
        _WrongMove = (possibleMoveKing(p_PieceBoard,p_OldPosition, p_NewPosition)) && (!isWhite(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::BLACK_ROOK:
        _WrongMove = (possibleMoveRook(p_PieceBoard,p_OldPosition, p_NewPosition)) && (!isBlack(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::WHITE_ROOK:
        _WrongMove = (possibleMoveRook(p_PieceBoard,p_OldPosition, p_NewPosition)) && (!isWhite(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::BLACK_BISHOP:
        _WrongMove = (possibleMoveBishop(p_PieceBoard, p_OldPosition, p_NewPosition)) && (!isBlack(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::WHITE_BISHOP:
        _WrongMove = (possibleMoveBishop(p_PieceBoard ,p_OldPosition, p_NewPosition)) && (!isWhite(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::BLACK_QUEEN:
        _WrongMove = (possibleMoveQueen(p_PieceBoard, p_OldPosition, p_NewPosition)) && (!isBlack(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::WHITE_QUEEN:
        _WrongMove = (possibleMoveQueen(p_PieceBoard,p_OldPosition, p_NewPosition)) && (!isWhite(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::BLACK_KNIGHT:
        _WrongMove = (possibleMoveKnight(p_OldPosition, p_NewPosition)) && (!isBlack(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::WHITE_KNIGHT:
        _WrongMove = (possibleMoveKnight(p_OldPosition, p_NewPosition)) && (!isWhite(p_PieceBoard, p_NewPosition)) ? true : false;
        break;
    }
    return _WrongMove;
}


/*
bool Candy::Moves::isGameOver(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard)
{
    return false;
}

PieceColor Candy::Moves::getWinner(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard)
{
    return PieceColor();
}
*/
