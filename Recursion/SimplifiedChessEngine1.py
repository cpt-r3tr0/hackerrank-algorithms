from copy import deepcopy

INDEX_1 = "1234" # row
INDEX_2 = "ABCD" # column

def parse_piece(player, board):
    type, column, row = input().split()
    board[INDEX_1.index(row)][INDEX_2.index(column)] = player + type

def player_won(board, player):
    # won if the enemy has no queen
    search_tile = invert_player(player) + "Q"
    return not any(tile == search_tile for sub_board in board for tile in sub_board)

def invert_player(player):
    if player == "W":
        return "B"
    elif player == "B":
        return "W"
    else:
        raise ValueError("player can only be 'W' or 'B', not '%s'" % player)

# obstructed by own piece or not on board
def is_tile_obstructed(board, row, column, player):
    return row not in range(len(board)) or column not in range(len(board[row])) or player == board[row][column][0]

def generate_possible_moves(board, row, column):
    tile = board[row][column]
    player = tile[0]
    type = tile[1]

    # Knight
    if type == "N":
        moves = [(1, 2), (-1, 2), (1, -2), (-1, -2), (2, 1), (-2, 1), (2, -1), (-2, -1)]
        for move in moves:
            dest_row = row + move[0]
            dest_col = column + move[1]
            if not is_tile_obstructed(board, dest_row, dest_col, player):
                yield dest_row, dest_col
    else:
        # get directions
        directions = []
        # horizontal and vertical
        if type == "Q" or type == "R":
            directions += [(0, 1), (0, -1), (1, 0), (-1, 0)]
        # diagonal
        if type == "Q" or type == "B":
            directions += [(1, 1), (-1, 1), (1, -1), (-1, -1)]

        for dir in directions:
            dir_row, dir_col = dir
            cur_row, cur_col = row + dir_row, column + dir_col

            while not is_tile_obstructed(board, cur_row, cur_col, player):
                yield cur_row, cur_col
                # break if on enemy
                if board[cur_row][cur_col][0] == invert_player(player):
                    break
                cur_row += dir_row
                cur_col += dir_col

def can_win(board, current_player, moves_left):

    if player_won(board, "W"):
        return True
    if player_won(board, "B"):
        return False
    if moves_left == 0:
        return False
    """for next_board in generate_possible_boards(board, current_player):
        assert all(len(tile) == 2 for sub_board in next_board for tile in sub_board)
        if can_win(next_board, invert_player(current_player), moves_left - 1):
            return True
    return False
    if current_player == "W":
        anyall = any
    else:
        anyall = all
    return anyall(can_win(next_board, invert_player(current_player), moves_left - 1) for next_board in generate_possible_boards(board, current_player))"""

    ret = current_player != "W"
    for row in range(len(board)):
        for column in range(len(board[row])):

            tile = board[row][column]
            if current_player == tile[0]:
                for move in generate_possible_moves(board, row, column):
                    dest_row, dest_col = move
                    """new_board = deepcopy(board)

                    # execute move
                    new_board[row][column] = "__"
                    new_board[dest_row][dest_col] = tile

                    yield new_board"""

                    dest_tile = board[dest_row][dest_col]

                    # execute move
                    board[row][column] = "__"
                    board[dest_row][dest_col] = tile

                    stop = False
                    if current_player == "W":
                        if ret == False:
                            ret = can_win(board, invert_player(current_player), moves_left - 1)
                            if ret == True:
                                stop = True
                    else:
                        if ret == True:
                            ret = can_win(board, invert_player(current_player), moves_left - 1)
                            if ret == False:
                                stop = True

                    # undo move
                    board[row][column] = tile
                    board[dest_row][dest_col] = dest_tile

                    if stop:
                        return ret
    return ret

# main loop
for _ in range(int(input())):

    # parse input
    num_white, num_black, max_moves = map(int, input().split())
    board = [["__" for _ in range(4)] for _ in range(4)] # 4x4 grid of "__"
    for _ in range(num_white):
        parse_piece("W", board)
    for _ in range(num_black):
        parse_piece("B", board)

    # calculate and output
    if can_win(board, "W", max_moves):
        print("YES")
    else:
        print("NO")
