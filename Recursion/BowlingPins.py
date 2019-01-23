def game_from(board: str) -> list:
    game = []
    count = 0
    for c in board:
        if c == 'I':
            count += 1
        elif count > 0:
            game.append(count)
            count = 0
    if count > 0:
        game.append(count)
    return game


def moves_for(n: int, hits: [int]) -> [list]:
    moves = []
    for hit in hits:
        left = 0
        right = n - hit
        while left <= right:
            if left == 0 and right == 0:
                continue
            elif right < 1 <= left:
                moves.append([left])
            elif left < 1 <= right:
                moves.append([right])
            else:
                moves.append([left, right])
            left += 1
            right -= 1
    return moves


def mex_of(s: set) -> int:
    mex = 0
    while mex in s:
        mex += 1
    return mex


def g_of(n: int, cache: dict) -> int:
    if n < 3:
        return n
    else:
        result = cache.get(n, None)
        if result is not None:
            return result
        moves = moves_for(n, [1,2])
        s = set()
        for move in moves:
            if len(move) == 1:
                s.add(g_of(move[0], cache))
            else:
                s.add(g_of(move[0], cache) ^ g_of(move[1], cache))
        result = mex_of(s)
        cache[n] = result
        return result


def winner(board: str, cache: dict) -> str:
    game = game_from(board)
    g = 0
    for i in game:
        g ^= g_of(i, cache)
    return 'WIN' if g != 0 else 'LOSE'


n = int(input().strip())
c = {}

for i in range(n):
    input()
    g = list(input().strip())
    print(winner(g, c))
    
