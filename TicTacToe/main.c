/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Doruk.Ozkazanc
 *
 * Created on 15 Kasım 2018 Perşembe, 16:15
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "helper_functions.h"
#include "cpu.h"

#define WIDTH 4
#define HEIGHT 4
#define MAX_STRING_LEN 20
int main(int argc, char** argv) {
    char again = 'y';
    while(again == 'y'){
        char board[HEIGHT][WIDTH] = {' ','a','b','c',
                                     'a',' ',' ',' ',
                                     'b',' ',' ',' ', 
                                     'c',' ',' ',' '};
        char current_position[HEIGHT][WIDTH];
        char move[MAX_STRING_LEN];
        char player;
        char cpu;    
        char turn = 'x';    //x always moves first        
        char empty;         //get rid of the '\n' in the buffer

        int winner = 0;
        int num_turns = 9;

        printf("Choose side x or o: ");
        scanf("%c",&player);
        scanf("%c",&empty);     
        cpu = assign_cpu(player);

        while(num_turns != 0 && winner == 0){                 
            if(turn == player){
                print_board(board); 
                printf("Make a move: ");
                scanf("%s",move);
                scanf("%c",&empty);

                if(!make_move(board,move,turn)) continue;
            }
            else {
                copy_position(current_position, board);
                minimax(current_position, move, num_turns, cpu, player, -100, 100, 0, true);
                if(!make_move(board,move,turn)) continue;
            }

            turn = assign_cpu(turn);
            winner = evaluate_position(board,player);
            num_turns--;
        }
        print_board(board);
        print_message(winner);
        
        printf("Want to play again?(y/n): ");
        scanf("%c",&again);
        scanf("%c",&empty);
    }
    printf("Thanks for playing!\n");
    return (EXIT_SUCCESS);
}

