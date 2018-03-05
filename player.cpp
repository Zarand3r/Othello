#include "player.hpp"

/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish
 * within 30 seconds.
 */
Player::Player(Side s) {
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;

    /*
     * TODO: Do any initialization you need to do here (setting up the board,
     * precalculating things, etc.) However, remember that you will only have
     * 30 seconds.
     */
    side = s; 
    other = (s == BLACK) ? WHITE : BLACK;
    board = new Board();
    board->set(s, 3, 3);
    board->set(s, 4, 4);
}

/*
 * Destructor for the player.
 */
Player::~Player() {
    delete board; 
}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be
 * nullptr.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return nullptr.
 */

// Heuristic function, only meant to beat the simpleplayer
int Player::score(Move *m)  {
    Board copy = board->copy();
    copy.set(side, m->x, m->y);
    int score = copy->getScore();
    if ((m->getX == 0) || (m->getX == 7) && (m->getY == 0) || (m->getY == 7))   {
        score += 3;
    }
    else if ((m->getX == 1) || (m->getX == 6) && (m->getY == 1) || (m->getY == 6))  {
        score -= 3; 
    }
    delete copy;
    return score; 
}

Move *Player::doMove(Move *opponentsMove, int msLeft) {
    /*
     * TODO: Implement how moves your AI should play here. You should first
     * process the opponent's move before calculating your own move
     */
    board.set(other, opponentsMove->getX(), opponentsMove->getY());
    if (board.hasMoves(side))    {
        // We could iterate through all the empty squares, use the checkmove method
        // of board class to see if the move is possible, calculate score, and 
        // then pick the move that is the best score.
        int best = -100;
        bestx;
        besty 
        for (int x = 0; x < 7; x++)    {
            for (int y = 0; y < 7; y++) {
                Move m(x, y);
                score = score(&m);
                if (board->checkMove(&m, side) && score > best)  {
                    best = score;
                    bestx = m->getX;
                    besty = m->getY;  
                }
            }
        }
        Move *bestmove = new Move(bestx, besty);
        return bestmove;
        // A more efficient way would be to look at the stones we have, and explore
        // in all four directions. If there is a stone of the other side next to our stone,
        // we keep moving in the direction, until we find an empty square.
        // We make a list of all these empty squares, and these are our possible moves. 
        // We then choose one by comparing their scores. 
        // To compare scores we make a copy of the board, update it, and then get the score of that
    }
    return nullptr;
}
