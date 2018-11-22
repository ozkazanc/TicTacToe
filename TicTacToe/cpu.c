/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "cpu.h"

//minimax w/ data pruning

//make a copy of the current position
//move any available spot
//create a child when you move to a spot
//run eval_position at every node
int minimax(char board[HEIGHT][WIDTH], char* move, int depth, char cpu, char player, int alpha, int beta, int winner, bool maximing_player){
    if(winner != 0  || depth == 0)     //stop recursion if the game is over or if the board is full
        return winner;
    
    if(maximing_player){
        int max_eval = -100;
        int best_row = 0;
        int best_column = 0;
        bool broken = false;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i + 1][j + 1] == ' '){
                    move[0] = i + 'a';
                    move[1] = j + 'a';
                    
                    make_move(board, move, cpu);
                    
                    winner = evaluate_position(board, cpu);
                    int eval = minimax(board, move, depth - 1, cpu, player, alpha, beta, winner, false);
                    board[i + 1][j + 1] = ' ';
                   
                    if(eval > max_eval){
                        max_eval = eval;
                        best_row = i;
                        best_column = j;
                    }
                    alpha = fmax(alpha, eval);
                    if(beta <= alpha) {
                        broken = true;
                        break;
                    }                                          
                }
            }
            if(broken) break;
        }
        move[0] = best_row + 'a';
        move[1] = best_column + 'a';
        //printf("Max Eval is: %d\n",max_eval);
        return max_eval;
    }
    else{
        int min_eval = 100;
        bool broken = false;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i + 1][j + 1] == ' '){
                    move[0] = i + 'a';
                    move[1] = j + 'a';
                    
                    make_move(board, move, player);
                    
                    winner = evaluate_position(board,cpu);
                    int eval = minimax(board, move, depth - 1, cpu, player, alpha, beta, winner, true);
                    board[i + 1][j + 1] = ' ';
                    
                    min_eval = fmin(min_eval, eval);
                    beta = fmin(beta, eval);
                    if(beta <= alpha) {
                        broken = true;
                        break;
                    }
                }
            }
            if(broken) break;
        }        
        return min_eval;
    }    
}
void copy_position(char _board[HEIGHT][WIDTH], char board[HEIGHT][WIDTH]){
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            _board[i][j] = board[i][j];
        }
    }
}