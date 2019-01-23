# coding: utf-8

from __future__ import print_function, unicode_literals


class Piece(object):

    def __init__(self, color, ptype, row, col):
        self.color = color
        self.ptype = ptype
        self.row = row
        self.col = col
        self.captured = False

    def valid_moves(self, board):
        pass

    def can_move_to(self, r, c):
        if r == self.row and c == self.col:
            return False

        if r < 0 or r > 3:
            return False
        if c < 0 or c > 3:
            return False

        if board.mat[r][c] is None:
            return True
        elif board.mat[r][c].color != self.color:
            return True

        return False

    def _straight_moves(self, board):
        possible = []
        # straight up
        for row in range(1, 4):
            r, c = self.row - row, self.col
            if self.can_move_to(r, c):
                possible.append((r, c))
            if not board.is_open(r, c):
                break

        # straight down
        for row in range(1, 4):
            r, c = self.row + row, self.col
            if self.can_move_to(r, c):
                possible.append((r, c))
            if not board.is_open(r, c):
                break

        # straight left
        for col in range(1, 4):
            r, c = self.row, self.col - col
            if self.can_move_to(r, c):
                possible.append((r, c))
            if not board.is_open(r, c):
                break

        # straight right
        for col in range(1, 4):
            r, c = self.row, self.col + col
            if self.can_move_to(r, c):
                possible.append((r, c))
            if not board.is_open(r, c):
                break

        return possible

    def _diagonal_moves(self, board):
        possible = []
        # straight left up
        for rc in range(1, 4):
            r, c = self.row - rc, self.col - rc
            if self.can_move_to(r, c):
                possible.append((r, c))
            if not board.is_open(r, c):
                break

        # straight left down
        for rc in range(1, 4):
            r, c = self.row + rc, self.col - rc
            if self.can_move_to(r, c):
                possible.append((r, c))
            if not board.is_open(r, c):
                break

        # straight right up
        for rc in range(1, 4):
            r, c = self.row - rc, self.col + rc
            if self.can_move_to(r, c):
                possible.append((r, c))
            if not board.is_open(r, c):
                break

        # straight right down
        for rc in range(1, 4):
            r, c = self.row + rc, self.col + rc
            if self.can_move_to(r, c):
                possible.append((r, c))
            if not board.is_open(r, c):
                break

        return possible


class Rook(Piece):

    def valid_moves(self, board):
        possible = self._straight_moves(board)
        return possible


class Queen(Piece):

    def valid_moves(self, board):
        possible = self._straight_moves(board) + self._diagonal_moves(board)
        return possible


class Knight(Piece):

    def valid_moves(self, board):
        r, c = self.row, self.col
        possible = [
            (r - 2, c - 1), (r - 2, c + 1),
            (r - 1, c + 2), (r - 1, c - 2),
            (r + 1, c + 2), (r + 1, c - 2),
            (r + 2, c - 1), (r + 2, c + 1),
        ]
        return [(rw, cl) for rw, cl in possible if self.can_move_to(rw, cl)]


class Bishop(Piece):

    def valid_moves(self, board):
        possible = self._diagonal_moves(board)
        return possible


type_dict = {
    "B": Bishop,
    "R": Rook,
    "Q": Queen,
    "N": Knight,
}


class Pawn(Piece):

    def valid_moves(self, board):
        if self.ptype != "P":
            return type_dict[self.ptype].valid_moves(self, board)

        r, c = self.row, self.col
        if self.color == "B":
            possible = [
                (r - 1, c), (r - 1, c - 1), (r - 1, c + 1),
            ]
        else:
            possible = [
                (r + 1, c), (r + 1, c - 1), (r + 1, c + 1),
            ]
        v = [(rw, cl) for rw, cl in possible if self.can_move_to(rw, cl)]
        return v

    def can_move_to(self, r, c):
        if self.ptype != "P":
            return type_dict[self.ptype].can_move_to(self, r, c)

        if r == self.row and c == self.col:
            return False

        if r < 0 or r > 3:
            return False
        if c < 0 or c > 3:
            return False

        if board.mat[r][c] is None and c == self.col:
            return True
        elif board.mat[r][c] is not None and board.mat[r][c].color != self.color and c != self.col:
            return True

        return False


class Board(object):

    def __init__(self):
        self.mat = [[None for i in range(4)] for u in range(4)]
        self.white = []
        self.black = []

    def add_piece(self, color, ptype, row, col):
        if ptype == "Q":
            piece = Queen(color, ptype, row, col)
        elif ptype == "N":
            piece = Knight(color, ptype, row, col)
        elif ptype == "B":
            piece = Bishop(color, ptype, row, col)
        elif ptype == "R":
            piece = Rook(color, ptype, row, col)
        elif ptype == "P":
            piece = Pawn(color, ptype, row, col)
        else:
            raise Exception("Invalid type")

        self.mat[row][col] = piece
        if color == "W":
            self.white.append(piece)
        elif color == "B":
            self.black.append(piece)

    def move_to(self, piece, row, col):
        self.mat[piece.row][piece.col] = None
        if self.mat[row][col] is not None:
            captured = self.mat[row][col]
            captured.captured = True
        self.mat[row][col] = piece

        piece.row = row
        piece.col = col
        if piece.ptype == "P":
            # promotion
            if piece.color == "W" and piece.row == 3:
                return True
            elif piece.color == "B" and piece.row == 0:
                return True

        return False

    def undo_move(self, captured, piece, prev_r, prev_c, was_pawn):
        self.move_to(piece, prev_r, prev_c)
        if was_pawn:
            piece.ptype = "P"
        if captured:
            cr, cc = captured.row, captured.col
            self.mat[cr][cc] = captured
            captured.captured = False

    def is_open(self, r, c):
        if r < 0 or r > 3:
            return False
        if c < 0 or c > 3:
            return False
        if self.mat[r][c] is None:
            return True
        return False

    def white_can_win(self, turns_left):
        if turns_left <= 0:
            return False

        white_pieces = self.white

        q = []
        for piece in white_pieces:
            if piece.captured is True:
                continue

            valid_moves = piece.valid_moves(self)
            for r, c in valid_moves:
                captured = self.mat[r][c]
                if captured is not None and captured.ptype == "Q":
                    return True

                q.insert(0, (piece, r, c))

        for piece, r, c in q:
            prev_r, prev_c = piece.row, piece.col
            captured = self.mat[r][c]
            was_pawn = self.move_to(piece, r, c)

            ptypes = [piece.ptype]
            before = piece
            if was_pawn:
                ptypes = ["B", "R", "N"]
            for ptype in ptypes:
                piece.ptype = ptype

                # if for all follow-up opponent moves, we can find a winning move within the limit, return True
                if self.black_cannot_avoid_loss(turns_left - 1):
                    self.undo_move(captured, piece, prev_r, prev_c, was_pawn)
                    return True

            self.undo_move(captured, piece, prev_r, prev_c, was_pawn)

        return False

    def black_cannot_avoid_loss(self, turns_left):
        if turns_left <= 0:
            return False

        black_pieces = self.black

        for piece in black_pieces:
            if piece.captured is True:
                continue

            valid_moves = piece.valid_moves(self)
            for r, c in valid_moves:
                prev_r, prev_c = piece.row, piece.col
                captured = self.mat[r][c]

                if captured is not None and captured.ptype == "Q":
                    return False

                was_pawn = self.move_to(piece, r, c)
                ptypes = [piece.ptype]
                before = piece
                if was_pawn:
                    ptypes = ["B", "R", "N"]
                for ptype in ptypes:
                    piece.ptype = ptype

                    if not self.white_can_win(turns_left - 1):
                        self.undo_move(captured, piece, prev_r, prev_c, was_pawn)
                        return False

                self.undo_move(captured, piece, prev_r, prev_c, was_pawn)

        return True

    def __repr__(self):
        s = []

        for i, row in enumerate(self.mat[::-1]):
            s.append("{} ".format(4 - i))
            for col in row:
                if col is None or col.captured is True:
                    s.append(".")
                elif col.color == "W":
                    s.append(col.ptype.upper())
                elif col.color == "B":
                    s.append(col.ptype.lower())
            s.append("\n")
        s.append("  ABCD")
        return "".join(s)

if __name__ == '__main__':
    games = int(input())
    for g in range(games):
        board = Board()

        cols = "ABCD"

        w, b, m = map(int, input().split(" "))
        for i in range(w):
            ptype, col, row = input().split(" ")
            col = cols.index(col)
            row = int(row) - 1
            board.add_piece("W", ptype, row, col)

        for i in range(b):
            ptype, col, row = input().split(" ")
            col = cols.index(col)
            row = int(row) - 1
            board.add_piece("B", ptype, row, col)

        print("YES" if board.white_can_win(m) else "NO")
