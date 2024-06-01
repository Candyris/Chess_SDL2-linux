#pragma once
#include <array>
#include "MoveDef.hpp"
#include "PiecesDef.hpp"

class Moves
{
public:
    static bool VaildMove(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard, PiecePosition p_OldPosition, PiecePosition p_NewPosition);
};

