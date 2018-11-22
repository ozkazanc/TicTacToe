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
void print_message(char winner){
    if(winner == 1) printf("Congrats, you win!\n");
    else if(winner == -1) printf("You lose, try again!\n");
    else printf("It's a draw!\n");
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
bool space_available(char board[HEIGHT][WIDTH], char* move){
    if(board[move[0] - 'a' + 1][move[1] - 'a' + 1] == ' ') return true;
    else printf("Cannot move there, spot already taken\n");
    return false;
}
int make_move(char board[HEIGHT][WIDTH], char* move, char turn){
    if(!(move_inbounds(move) && space_available(board,move))) return 0;
    board[move[0] - 'a' + 1][move[1] - 'a' + 1] = turn;    
    return 1;
}
//Switches the x to an o and vice-versa
char assign_cpu(char player){
    if(player == 'x') return 'o';
    else return 'x';
}
int decide_winner(char winner, char player){
    if(winner == player) return 1;
    else return -1;
}

//evaluate a given position for the player, if the player wins return 1,
//if the position is a draw return 0, if the player loses return -1
int evaluate_position(char board[HEIGHT][WIDTH], char player){
    if(board[1][1] != ' '){
        if(board[1][1] == board[1][2] && board[1][1] == board[1][3])    return(decide_winner(board[1][1],player));
        if(board[1][1] == board[2][1] && board[1][1] == board[3][1])    return(decide_winner(board[1][1],player));
        if(board[1][1] == board[2][2] && board[1][1] == board[3][3])    return(decide_winner(board[1][1],player));
    }
    if(board[1][2] != ' '){
        if(board[1][2] == board[2][2] && board[1][2] == board[3][2])    return(decide_winner(board[1][2],player));
    }
    if(board[1][3] != ' '){
        if(board[1][3] == board[2][3] && board[1][3] == board[3][3])    return(decide_winner(board[1][3],player));
        if(board[1][3] == board[2][2] && board[1][3] == board[3][1])    return(decide_winner(board[1][3],player));        
    }
    if(board[2][1] != ' '){
        if(board[2][1] == board[2][2] && board[2][1] == board[2][3])    return(decide_winner(board[2][1],player));
    }
    if(board[3][1] != ' '){
        if(board[3][1] == board[3][2] && board[3][1] == board[3][3])    return(decide_winner(board[3][1],player));
    } 
    return 0;
}

