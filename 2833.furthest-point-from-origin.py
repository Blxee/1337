class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        Ls, Rs = moves.count('L'), moves.count('R')

        if Rs > Ls:
            dist = len(moves) - 2 * Ls
        else:
            dist = len(moves) - 2 * Rs

        return abs(dist)
        
