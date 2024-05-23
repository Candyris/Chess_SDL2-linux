#include "../include/Moves.hpp"
#include "../include/PiecesDef.hpp"
#include <iostream> //debug

// Pawn // later add promotion
#pragma region Pawn
bool possibleMoveBlackPawn(const PiecePosition StartPos, const PiecePosition EndPos)
{
    if (0 <= StartPos.Row && StartPos.Row <= 7)
    {
        if (StartPos.Row + 1 == EndPos.Row) {
            if (0 == StartPos.Col)
            {
                if (EndPos.Col >= 0 && EndPos.Col <= StartPos.Col + 1)
                    return true;
            }
            else if (StartPos.Col == 7)// 7 is the last column of Board 
            {
                if (EndPos.Col <= 7 && EndPos.Col >= StartPos.Col - 1)
                    return true;
            }
            else if (EndPos.Col > 0 && EndPos.Col < 7)
            {
                if ( StartPos.Col - 1 <= EndPos.Col&& EndPos.Col <= StartPos.Col + 1 )
                    return true;
            }
        }
        else if (StartPos.Row + 2 == EndPos.Row && StartPos.Row == 1)
        {
            if (StartPos.Col == EndPos.Col) // later add this condition from before 
                return true;
        }
        else
        {
            return false; 
        }
    } 
    // breaking point so i can see when this statement reaches.
    return false;
}

// lets add capture of piece basic mechanicals not legal move 
 bool possibleMoveWhitePawn(const PiecePosition StartPos, const PiecePosition EndPos)
{
    if (7 > StartPos.Row && StartPos.Row > 0)
    {
        if (StartPos.Row - 1 == EndPos.Row ) {
            if ( StartPos.Col == 0 )
            {
                if (EndPos.Col >= 0 && EndPos.Col <= StartPos.Col + 1)
                    return true;
            }
            else if (StartPos.Col == 7)// 7 is the last column of Board 
            {
                if (EndPos.Col <= 7 && EndPos.Col >= StartPos.Col - 1)
                    return true;
            }
            else if (0 < StartPos.Col  && StartPos.Col < 7) // change this for bug of not moving diagonal of pawn
            {
                if (StartPos.Col - 1 <= EndPos.Col && EndPos.Col <= StartPos.Col + 1)
                    return true;
            }
            // later add condition for enspassant
            
            return false;
        }
        else if (StartPos.Row - 2 == EndPos.Row && StartPos.Row == 6)
        {
            if (StartPos.Col == EndPos.Col) // later add this condition from before 
                return true;
        }
        else
        {
            return false;
        }
    }
    return false;

}
#pragma endregion
#pragma region King
 bool possibleMoveKing(const PiecePosition StartPos, const PiecePosition EndPos)
 {
     if (0 <= EndPos.Row && EndPos.Row <= 7 && 0 <= EndPos.Col && EndPos.Col <= 7)
     {
         if ((StartPos.Row + 1 >= EndPos.Row && EndPos.Row >= StartPos.Row - 1) &&
             (StartPos.Col + 1 >= EndPos.Col && EndPos.Col >= StartPos.Col - 1))
         {
             return true;
         }
     }
     return false;
 }
#pragma endregion
#pragma region Rook
 bool possibleMoveRook(const PiecePosition StartPos, const PiecePosition EndPos)
 {
     if (0 <= EndPos.Row && EndPos.Row <= 7 && 0 <= EndPos.Col && EndPos.Col <= 7)
     {
         if (StartPos.Col == EndPos.Col || StartPos.Row == EndPos.Row)
             return true;
     }
     return false;
 }
#pragma endregion
#pragma region Bishop
 bool possibleMoveBishop(const PiecePosition StartPos, const PiecePosition EndPos)
 {
     // first diagonal working 
     if (0 <= EndPos.Row && EndPos.Row <= 7 && 0 <= EndPos.Col && EndPos.Col <= 7)
     {
         // well there is a problem with that i only checking for one diagonal other i dont have idea right now 
         for (int col = StartPos.Col , row = StartPos.Row ; col <= 7 && row <= 7 ; col++,row++) // ok do it wrong way but still fun
         {
             std::cout << "COl     :" << col << ", ROW       :" << row << std::endl;
             std::cout << "OLD Col :" << EndPos.Col << ", OLD row :" << EndPos.Row << std::endl;

             if (col == EndPos.Col && row == EndPos.Row)
             {
                 return true;
             }
         }
         for (int col = StartPos.Col, row = StartPos.Row; col >= 0 && row >=0; col--, row--) // ok do it wrong way but still fun
         {
             std::cout << "COl :" << col << "ROW :" << row << std::endl;
             std::cout << "OLD Col :" << EndPos.Col << "OLD row :" << EndPos.Row << std::endl;
             if (col == EndPos.Col && row == EndPos.Row)
             {
                 return true;
             }
         }
         // second diagonal not working 
         for (int col = StartPos.Col, row = StartPos.Row; col >= 0 && row <= 7; col--, row++) // ok do it wrong way but still fun
         {
             std::cout << "COl     :" << col << ", ROW       :" << row << std::endl;
             std::cout << "OLD Col :" << EndPos.Col << ", OLD row :" << EndPos.Row << std::endl;

             if (col == EndPos.Col && row == EndPos.Row)
             {
                 return true;
             }
         }
         for (int col = StartPos.Col, row = StartPos.Row; col <= 7 && row >= 0; col++, row--) // ok do it wrong way but still fun
         {
             std::cout << "COl :" << col << "ROW :" << row << std::endl;
             std::cout << "OLD Col :" << EndPos.Col << "OLD row :" << EndPos.Row << std::endl;
             if (col == EndPos.Col && row == EndPos.Row)
             {
                 return true;
             }
         }
     }
     // well now this working good 😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁
     return false;
 }
#pragma endregion
bool Moves::VaildMove(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard, PiecePosition p_OldPosition, PiecePosition p_NewPosition)
{
    for (int row = 0; row < MAX_PIECES_LINE; row++)
    {
        std::cout << "[ ROW ]: " << row <<" : { ";
        for (int col = 0; col < MAX_PIECES_LINE; col++)
        {
            std::cout << p_PieceBoard[row][col] <<" , ";
        }
        std::cout << " } " << std::endl;
    }
    // later handle array for legal move
    bool _WrongMove = true;
    int _PIECETYPE = p_PieceBoard[p_OldPosition.Row][p_OldPosition.Col];
    std::cout << "PIECE TYPE " << _PIECETYPE << std::endl;
    switch (_PIECETYPE)
    {
    case PIECES_TYPE::BLACK_PAWN:
        _WrongMove = (possibleMoveBlackPawn(p_OldPosition, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::WHITE_PAWN:
        _WrongMove = (possibleMoveWhitePawn(p_OldPosition, p_NewPosition)) ? true : false;
        break; 
    
    case PIECES_TYPE::BLACK_KING:
        _WrongMove = (possibleMoveKing(p_OldPosition, p_NewPosition)) ? true : false;
        break;
    
    case PIECES_TYPE::WHITE_KING:
        _WrongMove = (possibleMoveKing(p_OldPosition, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::BLACK_ROOK:
        _WrongMove = (possibleMoveRook(p_OldPosition, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::WHITE_ROOK:
        _WrongMove = (possibleMoveRook(p_OldPosition, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::BLACK_BISHOP:
        _WrongMove = (possibleMoveBishop(p_OldPosition, p_NewPosition)) ? true : false;
        break;
    case PIECES_TYPE::WHITE_BISHOP:
        _WrongMove = (possibleMoveBishop(p_OldPosition, p_NewPosition)) ? true : false;
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
