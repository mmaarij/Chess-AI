#ifndef CYBERPEA_H
#define CYBERPEA_H
#include "chessPlayer.h"
#include"ENUM.h"
#include <iostream>
#include <time.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define PAWN 10
#define KNIGHT 30
#define BISHOP 30
#define ROOK 50
#define QUEEN 90
#define KING 1000
#define CHECK 1000

class Data
{
    public:
        float score;
        int index;
};

class CyberPea : public chessPlayer {

    private:

        // ********** HEATMAPS **********

        float blackPawn[8][8] =
        {
            {7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0},
            {5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0},
            {1.0, 1.0, 2.0, 3.0, 3.0, 2.0, 1.0, 1.0},
            {0.5, 0.5, 1.0, 2.5, 2.5, 1.0, 0.5, 0.5},
            {1.0, 1.0, 1.0, 2.0, 2.0, 1.0, 1.0, 1.0},
            {0.5, -0.5, -1.0, 0.0, 0.0, -1.0, -0.5, 0.5},
            {0.5, 1.0, 1.0, -2.0, -2.0, 1.0, 1.0, 0.5},
            {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
        };

        float whitePawn[8][8] =
        {
            {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
            {0.5, 1.0, 1.0, -2.0, -2.0, 1.0, 1.0, 0.5},
            {0.5, -0.5, -1.0, 0.0, 0.0, -1.0, -0.5, 0.5},
            {1.0, 1.0, 1.0, 2.0, 2.0, 1.0, 1.0, 1.0},
            {0.5, 0.5, 1.0, 2.5, 2.5, 1.0, 0.5, 0.5},
            {1.0, 1.0, 2.0, 3.0, 3.0, 2.0, 1.0, 1.0},
            {5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0},
            {7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0}
        };

        float Knight[8][8] =
        {
            {-5.0, -4.0, -3.0, -3.0, -3.0, -3.0, -4.0, -5.0},
            {-4.0, -2.0, 0.0, 0.0, 0.0, 0.0, -2.0, -4.0},
            {-3.0, 0.0, 1.0, 1.5, 1.5, 1.0, 0.0, -3.0},
            {-3.0, 0.5, 1.5, 2.0, 2.0, 1.5, 0.5, -3.0},
            {-3.0, 0.0, 1.5, 2.0, 2.0, 1.5, 0.0, -3.0},
            {-3.0, 0.5, 1.0, 1.5, 1.5, 1.0, 0.5, -3.0},
            {-4.0, -2.0, 0.0, 0.5, 0.5, 0.0, -2.0, -4.0},
            {-5.0, -4.0, -3.0, -3.0, -3.0, -3.0, -4.0, -5.0}
        };

        float blackBishop[8][8] =
        {
            { -2.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -2.0},
            {-1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0},
            {-1.0, 0.0, 0.5, 1.0, 1.0, 0.5, 0.0, -1.0},
            {-1.0, 0.5, 0.5, 1.0, 1.0, 0.5, 0.5, -1.0},
            {-1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, -1.0},
            {-1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0},
            {-1.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.5, -1.0},
            {-2.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -2.0}
        };

        float whiteBishop[8][8] =
        {
            {-2.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -2.0},
            {-1.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.5, -1.0},
            {-1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0},
            {-1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, -1.0},
            {-1.0, 0.5, 0.5, 1.0, 1.0, 0.5, 0.5, -1.0},
            {-1.0, 0.0, 0.5, 1.0, 1.0, 0.5, 0.0, -1.0},
            {-1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0},
            { -2.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -2.0}
        };

        float blackRook[8][8] =
        {
            {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
            {0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5},
            {-0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5},
            {-0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5},
            {-0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5},
            {-0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5},
            {-0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5},
            {0.0, 0.0, 0.0, 0.5, 0.5, 0.0, 0.0, 0.0}
        };

        float whiteRook[8][8] =
        {
            {0.0, 0.0, 0.0, 0.5, 0.5, 0.0, 0.0, 0.0},
            {-0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5},
            {-0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5},
            {-0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5},
            {-0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5},
            {-0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5},
            {0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5},
            { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}

        };

        float Queen[8][8] =
        {
            { -2.0, -1.0, -1.0, -0.5, -0.5, -1.0, -1.0, -2.0},
            {-1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0},
            {-1.0, 0.0, 0.5, 0.5, 0.5, 0.5, 0.0, -1.0},
            {-0.5, 0.0, 0.5, 0.5, 0.5, 0.5, 0.0, -0.5},
            {0.0, 0.0, 0.5, 0.5, 0.5, 0.5, 0.0, -0.5},
            {-1.0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.0, -1.0},
            {-1.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, -1.0},
            {-2.0, -1.0, -1.0, -0.5, -0.5, -1.0, -1.0, -2.0}
        };

        float blackKing[8][8] =
        {
            { -3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0},
            {-3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0},
            {-3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0},
            {-3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0},
            {-2.0, -3.0, -3.0, -4.0, -4.0, -3.0, -3.0, -2.0},
            {-1.0, -2.0, -2.0, -2.0, -2.0, -2.0, -2.0, -1.0},
            {2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 2.0, 2.0},
            {2.0, 3.0, 1.0, 0.0, 0.0, 1.0, 3.0, 2.0}
        };

        float whiteKing[8][8] =
        {
            {2.0, 3.0, 1.0, 0.0, 0.0, 1.0, 3.0, 2.0},
            {2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 2.0, 2.0},
            {-1.0, -2.0, -2.0, -2.0, -2.0, -2.0, -2.0, -1.0},
            {-2.0, -3.0, -3.0, -4.0, -4.0, -3.0, -3.0, -2.0},
            {-3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0},
            {-3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0},
            {-3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0},
            { -3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0}
        };


        int DEPTH;

    public:

        // Constructor
        CyberPea(int depth, Color playerColor = White):chessPlayer("CyberPea", playerColor) {
            this->DEPTH = depth;
        }


        // Decide Move
        void decideMove(gameState* state, action* Move, int maxDepth)
        {
            int TotalMoves = state->Actions.getActionCount(); //= state->computePossibleActions();
            cout << endl << "Total Possible Moves: " << TotalMoves << endl;

            if (TotalMoves == 0)
            {
                Move->fromRow = Move->fromCol = Move->toRow = Move->toCol = 0;
                return;
            }

            Data bestMove;
            int totalComputations = 0;

            cout << "Search Depth: " << DEPTH << endl;

            auto start = high_resolution_clock::now(); // start measuring execution time

            bestMove = minimax(state, DEPTH, INT_MIN, INT_MAX, totalComputations); // alpha = -inf | beta = +inf
            int SelectedMove = bestMove.index;

            auto stop = high_resolution_clock::now(); // stop measuring execution time

            // cout << "Total Computations Taken Into Account: " << totalComputations << endl; // *** moved this inside minmax function with carrige return ***
            auto duration = duration_cast <milliseconds> (stop - start);
            cout << endl << "Execution Time: " << duration.count() << " milliseconds" << endl;
            
            state->Actions.getAction(SelectedMove, Move);

            int piece = state->Board.board[Move->fromRow][Move->fromCol];
            showMove(piece, Move);
            
            return;
        }


        void showMove(int piece, action * Move)
        {
            string moveMade = "Move ";

            if (piece > 0)
                moveMade += "White ";
            else if (piece < 0)
                moveMade += "Black ";

            switch (piece)
            {
            case 4:
            case -4:
                moveMade += "Rook";
                break;

            case 2:
            case -2:
                moveMade += "Knight";
                break;

            case 3:
            case -3:
                moveMade += "Bishop";
                break;

            case 5:
            case -5:
                moveMade += "Queen";
                break;

            case 6:
            case -6:
                moveMade += "King";
                break;

            case 1:
            case -1:
                moveMade += "Pawn";
                break;

            }

            moveMade = moveMade + " (" + to_string(Move->fromRow) + ", " + to_string(Move->fromCol) + ") To (" + to_string(Move->toRow) + ", " + to_string(Move->toCol) + ")";

            cout << moveMade << endl;
        }


        // Minimax + Alpha Beta Pruning
        Data minimax (gameState* state, int depth, float alpha, float beta, int &totalComputations)
        {
            //we want to compute all possible moves here.
            int TotalMoves = state->Actions.getActionCount();
            actionList tempList;
            action tempAction;
            
            totalComputations++;
            cout << "\rTotal Computations Taken Into Account: " << totalComputations;

            if (depth == 0 || TotalMoves == 0) // base case
            {
                Data leaf;
                leaf.score = evaluateScore(state);
                return leaf;
            }
            else
            {
                //backup action list
                for (int i = 0; i < TotalMoves; i++)
                {
                    state->Actions.getAction(i, &tempAction);
                    tempList.addAction(tempAction);
                }
            }

            if (state->getPlayer() == White) // ******************** MAXIMIZING PLAYER ********************
            {
                Data maxEval;
                maxEval.score = INT_MIN;

                for (int i = 0; i < TotalMoves; i++)
                {
                    // backup board state
                    int backupBoard[8][8];
                    for (int r = 0; r < 8; r++)
                    {
                        for (int c = 0; c < 8; c++)
                        {
                            backupBoard[r][c] = state->Board.board[r][c];
                        }
                    }

                    //select move from list
                    state->Actions.getAction(i, &tempAction);
                    // make look-ahead move on board and change player
                    state->applyMove(tempAction);
                    
                    // ********** RECURSIVE CALL **********
                    Data eval = minimax(state, depth - 1, alpha, beta, totalComputations);

                    // undo look-ahead move on board // restore backed up board
                    for (int r = 0; r < 8; r++)
                    {
                        for (int c = 0; c < 8; c++)
                        {
                            state->Board.board[r][c] = backupBoard[r][c];
                        }
                    }
                    state->setPlayer(White);
                    state->Actions.resetActions();

                    //restore action list
                    for (int j = 0; j < TotalMoves; j++)
                    {
                        tempList.getAction(j, &tempAction);
                        state->Actions.addAction(tempAction);
                    }

                    // select max
                    if (eval.score > maxEval.score)
                    {
                        maxEval.score = eval.score;
                        maxEval.index = i;
                    }
                    
                    // alpha pruning
                    alpha = max(alpha, eval.score);
                    if (beta <= alpha)
                        break;

                }
                return maxEval;
            }

            else                             // ******************** MINIMIZING PLAYER ********************
            {
                Data minEval;
                minEval.score = INT_MAX;

                for (int i = 0; i < TotalMoves; i++)
                {
                    // backup board state
                    int backupBoard[8][8];
                    for (int r = 0; r < 8; r++)
                    {
                        for (int c = 0; c < 8; c++)
                        {
                            backupBoard[r][c] = state->Board.board[r][c];
                        }
                    }

                    //select move from list
                    state->Actions.getAction(i, &tempAction);
                    // apply selected look-ahead move on board and change player
                    state->applyMove(tempAction);

                    // ********** RECURSIVE CALL **********
                    Data eval = minimax(state, depth - 1, alpha, beta, totalComputations);

                    // undo look-ahead move on board // restore backed up board
                    for (int r = 0; r < 8; r++)
                    {
                        for (int c = 0; c < 8; c++)
                        {
                            state->Board.board[r][c] = backupBoard[r][c];
                        }
                    }
                    state->setPlayer(Black);
                    state->Actions.resetActions();

                    //restore action list
                    for (int j = 0; j < TotalMoves; j++)
                    {
                        tempList.getAction(j, &tempAction);
                        state->Actions.addAction(tempAction);
                    }

                    // select min
                    if (eval.score < minEval.score)
                    {
                        minEval.score = eval.score;
                        minEval.index = i;
                    }

                    // beta pruning
                    beta = min(beta, eval.score);
                    if (beta <= alpha)
                        break;
                }
                return minEval;
            }
            
        }


        // Evaluate Function with Piece Scoing and Positional Evaluation (Heat Maps)
        float evaluateScore(gameState* state)
        {
            float tempScore = 0;

            // evaluate move score
            for (int x = 0; x < 8; x++)
            {
                for (int y = 0; y < 8; y++)
                {
                    if (state->Board.board[x][y] == 1) // WHITE PAWN
                    {
                        tempScore += PAWN;
                        tempScore += (whitePawn[x][y] * 2);
                    }

                    else if (state->Board.board[x][y] == -1) // BLACK PAWN
                    {
                        tempScore -= PAWN;
                        tempScore -= (blackPawn[x][y] * 2);
                    }
                        
                    else if (state->Board.board[x][y] == 4) // WHITE ROOK
                    {
                        tempScore += ROOK;
                        tempScore += (whiteRook[x][y] * 2);
                    }

                    else if (state->Board.board[x][y] == -4) // BLACK ROOK
                    {
                        tempScore -= ROOK;
                        tempScore -= (blackRook[x][y] * 2);
                    }

                    else if (state->Board.board[x][y] == 2) // WHITE KNIGHT
                    {
                        tempScore += KNIGHT;
                        tempScore += (Knight[x][y] * 2);
                    }

                    else if (state->Board.board[x][y] == -2) // BLACK KNIGHT
                    {
                        tempScore -= KNIGHT;
                        tempScore -= (Knight[x][y] * 2);
                    }

                    else if (state->Board.board[x][y] == 3) // WHITE BISHOP
                    {
                        tempScore += BISHOP;
                        tempScore += (whiteBishop[x][y] * 2);
                    }

                    else if (state->Board.board[x][y] == -3)  // BLACK BISHOP
                    {
                        tempScore -= BISHOP;
                        tempScore -= (blackBishop[x][y] * 2);
                    }

                    else if (state->Board.board[x][y] == 5)  // WHITE QUEEN
                    {
                        tempScore += QUEEN;
                        tempScore += (Queen[x][y] * 2);
                    }

                    else if (state->Board.board[x][y] == -5) // BLACK QUEEN
                    {
                        tempScore -= QUEEN;
                        tempScore -= (Queen[x][y] * 2);
                    }

                    else if (state->Board.board[x][y] == 6) // WHITE KING
                    {
                        tempScore += KING;
                        tempScore += (whiteKing[x][y] * 2);
                    }

                    else if (state->Board.board[x][y] == -6) // BLACK KING
                    {
                        tempScore -= KING;
                        tempScore -= (blackKing[x][y] * 2);
                    }
                }
            }

            // see if check state reached
            Color player = state->getPlayer();
            Color oppose;
            if (player == White)
                oppose = Black;
            else
                oppose = White;

            if (state->kingUnderThreat(oppose)) // if opposing king threatened (check) then that's a very good move
            {
                if (player == White)
                    tempScore += CHECK; // maximise for white
                else
                    tempScore -= CHECK; // minimise for black
            }


            // return final evaluation / score
            return tempScore;
        }
};


#endif // CYBERPEA_H


/*

    Artificial Intelligence
    Section G
    Assignment #1

    Completed By Team CyberPea

    Members
    Muhammad Maarij 19L-2347
    Mohib Ali Kazmi 19L-1246

*/