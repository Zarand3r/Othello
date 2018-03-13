Group Members: Richard Bao and June Kim

Richard created the randomMove and greedyMove implementations, and created the heuristic scoring function, as well as the helper functions in board.cpp.

June created the minimax and doMinimax implementations, using recursion to create an n-ply algorithm. June also greatly improved the scoring function in board.cpp. 


Our minimax algorithm utilizes recursion to look several moves ahead to find the best move (the one that will result in the best future state). It scores the board state based on how the occupancy of corner tiles, which are advantageous. It assumes that the opponent also chooses the best future move. We tried to implement alpha beta and pruning, but we were too busy to complete that task. 