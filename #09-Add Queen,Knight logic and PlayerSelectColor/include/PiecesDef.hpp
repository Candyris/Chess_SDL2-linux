#pragma once
// BLACK Piece PATH

#define BLACK_PAWN_PATH "assets/Pieces_IMG/Chess_pawnBlack60.png"
#define BLACK_BISHOP_PATH "assets/Pieces_IMG/Chess_bishipBlack60.png"
#define BLACK_KNIGHT_PATH "assets/Pieces_IMG/Chess_knightBlack60.png"
#define BLACK_ROOK_PATH "assets/Pieces_IMG/Chess_rookBlack60.png"
#define BLACK_QUEEN_PATH "assets/Pieces_IMG/Chess_queenBlack60.png"
#define BLACK_KING_PATH "assets/Pieces_IMG/Chess_kingBlack60.png"

// WHITE Piece PATH

#define WHITE_PAWN_PATH "assets/Pieces_IMG/Chess_pawnWhite60.png"
#define WHITE_BISHOP_PATH "assets/Pieces_IMG/Chess_bishipWhite60.png"
#define WHITE_KNIGHT_PATH "assets/Pieces_IMG/Chess_knightWhite60.png"
#define WHITE_ROOK_PATH "assets/Pieces_IMG/Chess_rookWhite60.png"
#define WHITE_QUEEN_PATH "assets/Pieces_IMG/Chess_queenWhite60.png"
#define WHITE_KING_PATH "assets/Pieces_IMG/Chess_kingWhite60.png"  
#define EMPTY_PATH "assets/Pieces_IMG/EMPTY.png"


namespace PIECES_TYPE {
    const int EMPTY = 0;
    const int WHITE_KING = 1;
    const int WHITE_QUEEN = 2;
    const int WHITE_BISHOP = 3;
    const int WHITE_KNIGHT = 4;
    const int WHITE_ROOK = 5;
    const int WHITE_PAWN = 6;
    const int BLACK_KING = -1;
    const int BLACK_QUEEN = -2;
    const int BLACK_BISHOP = -3;
    const int BLACK_KNIGHT = -4;
    const int BLACK_ROOK = -5;
    const int BLACK_PAWN = -6;
};


#define MAX_PIECES_SPACE 64
#define MAX_PIECES_LINE 8
#define MAX_DIFFERENT_TYPES_PIECES 16

#include <array>
class Player
{
public:
    Player(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_BoardPiece) : BoardPieces(p_BoardPiece)
    {}
    ~Player(){} // dont decided on now
    bool isSeleted;
    int row;
    int col;
    std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> BoardPieces;
};