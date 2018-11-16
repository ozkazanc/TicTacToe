/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "helper_functions.h"


void print_board(char board[HEIGHT][WIDTH]){
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++)
            printf("%c", board[i][j]);
        printf("\n");
    }
}
bool move_inbounds(char* move){
    if(move[0] - 'a' + 1 < 1 || move[0] - 'a' + 1> HEIGHT - 1) {
        printf("Move out of bounds\n");
        return false;
    }
    if(move[1] - 'a' + 1 < 1 || move[1] - 'a' + 1> WIDTH - 1) {
        printf("Move out of bounds\n");
        return false;
    }
    return true;
}
bool space_available(char board[HEIGHT][WIDTH],char* move){
    if(board[move[0] - 'a' + 1][move[1] - 'a' + 1] == ' ') return true;
    else printf("Cannot move there, spot already taken\n");
    return false;
}
void make_move(char board[HEIGHT][WIDTH],char* move,char* turn,int* num_turns){
    if(!(move_inbounds(move) && space_available(board,move))) return;
    board[move[0] - 'a' + 1][move[1] - 'a' + 1] = *turn;
    *turn = assign_cpu(*turn);
    (*num_turns)--;
    return;
}
char assign_cpu(char player){
    if(player == 'x') return 'o';
    else return 'x';
}


