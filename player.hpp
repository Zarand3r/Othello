#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "common.hpp"
#include "board.hpp"
using namespace std;

class Player {

private:
	Side side; 
	Side other;

public:
	Board *board; 
    Player(Side side);
    ~Player();

    int score(Move *m, Side s);
    Move *randomMove(Move *opponentsMove);
    Move *greedyMove(Move *opponentsMove);
    int minimax(Board *copy, Move * m, int depth, bool maximizingPlayer);
    Move *doMinimax(Move * opponentsMove, int msLeft);
    Move *doMove(Move *opponentsMove, int msLeft);

    // Flag to tell if the player is running within the test_minimax context
    bool testingMinimax;
};

#endif
