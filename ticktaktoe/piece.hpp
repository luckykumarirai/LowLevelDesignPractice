#ifndef PIECE_HPP
#define PIECE_HPP


enum pieceType {
    X,
    O
};

class Piece{
    public:
    pieceType type;
    Piece(pieceType type) : type(type){}
    virtual ~Piece(){}
};

class PieceX : public Piece{
    public:
    PieceX() : Piece(pieceType::X){}
};

class PieceO : public Piece{
    public:
    PieceO() : Piece(pieceType::O){}
};

#endif
