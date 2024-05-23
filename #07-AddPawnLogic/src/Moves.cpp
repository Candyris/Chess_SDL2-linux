#include "../include/Moves.hpp"
#include "../include/PiecesDef.hpp"
#include <iostream> //debug

// Pawn

bool possibleMoveBlackPawn(const PiecePosition StartPos, const PiecePosition EndPos)
{
    if (0 < StartPos.Row && StartPos.Row < 7)
    {
        if (StartPos.Row + 1 == EndPos.Row) {
            std::cout << "OLD ROW : " << StartPos.Row + 1 << " , NEW ROW " << EndPos.Row << " ; " << std::endl;
            if (0 == StartPos.Col)
            {
                if (EndPos.Col > 0 && EndPos.Col < StartPos.Col + 1)
                    return true;
            }
            else if (StartPos.Col == 7)// 7 is the last column of Board 
            {
                if (EndPos.Col < 7 && EndPos.Col > StartPos.Col - 1)
                    return true;
            }
            else if (EndPos.Col > 0 && EndPos.Col < 7)
            {
                if ( StartPos.Col - 1 <= EndPos.Col&& EndPos.Col <= StartPos.Col + 1 )
                    return true;
            }
            else
            {
                return true;
            }

            return false;
        }
        else if (StartPos.Row + 2 == EndPos.Row && StartPos.Row == 1)
        {
            std::cout << "OLD ROW : " << StartPos.Row + 2 << " , NEW ROW "  << EndPos.Row << " ; "<< std::endl;
            return true;
        }
        else
        {
            std::cout << "OLD ROW : " << StartPos.Row  << " , NEW ROW " << EndPos.Row << " ; " << std::endl;
            return false;
        }
    }
    return false;
}
// lets add capture of piece basic mechanicals not legal move 
 bool possibleMoveWhitePawn(const PiecePosition StartPos, const PiecePosition EndPos)
{
    if (7 > StartPos.Row && StartPos.Row > 0)
    {
        if (StartPos.Row - 1 == EndPos.Row ) {
            std::cout << "OLD ROW : " << StartPos.Row - 1 << " , NEW ROW ;" << EndPos.Row << " ; "<< std::endl;
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
                if (StartPos.Col - 1 <= EndPos.Col && EndPos.Col <= StartPos.Col + 1)
                    return true;
            }
            // later add condition for enspassant
            else
            {
                return true;
            }
            return false;
        }
        else if (StartPos.Row - 2 == EndPos.Row && StartPos.Row == 6)
        {
            std::cout << "OLD ROW : " << StartPos.Row - 2 << " , NEW ROW " << EndPos.Row << " ; " << std::endl;
            return true;
        }
        else
        {
            std::cout << "OLD ROW : " << StartPos.Row   << " , NEW ROW " << EndPos.Row << " ; " << std::endl;
            return false;
        }
    }
    return false;

}


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
        _WrongMove = false;

        if (possibleMoveBlackPawn(p_OldPosition,p_NewPosition))
        {
            _WrongMove = true;
        }
        std::cout << "Black Pawn state" << possibleMoveBlackPawn(p_OldPosition, p_NewPosition) << std::endl;
        break;
    case PIECES_TYPE::WHITE_PAWN:
        _WrongMove = false;

        if (possibleMoveWhitePawn(p_OldPosition, p_NewPosition))
        {
            _WrongMove = true;
        }
        std::cout << "White Pawn state" << possibleMoveBlackPawn(p_OldPosition, p_NewPosition) << std::endl;
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
