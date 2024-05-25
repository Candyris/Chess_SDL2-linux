#pragma once
#include <array>
#include "MoveDef.hpp"
#include "PiecesDef.hpp"
// all includes of Pieces
static bool possibleMoveBlackPawn(const PiecePosition StartPos, const PiecePosition EndPos);
static bool possibleMoveWhitePawn(const PiecePosition StartPos, const PiecePosition EndPos);

class Moves
{
public:
    static bool VaildMove(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard, PiecePosition p_OldPosition, PiecePosition p_NewPosition);
    // static bool isGameOver(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard);
    // static PieceColor getWinner(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard);

};


// i have fix the issus for error and i am only focusing on basic move of piece not legal move ????


// progress uptil now 