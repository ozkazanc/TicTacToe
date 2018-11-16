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

#define WIDTH 4
#define HEIGHT 4
#define MAX_STRING_LEN 20
int main(int argc, char** argv) {
    char board[HEIGHT][WIDTH] = {' ','a','b','c',
                                 'a',' ',' ',' ',
                                 'b',' ',' ',' ', 
                                 'c',' ',' ',' '};
    char player;
    char cpu;
    char turn = 'x';
    char move[MAX_STRING_LEN];
    
    int num_turns = 9;
    printf("Choose side x or o: ");
    scanf("%c",&player);
    
    cpu = assign_cpu(player);
    int i = 0;
    while(num_turns != 0){
        print_board(board);
        printf("Make a move: ");
        scanf("%s",move);
        
        make_move(board,move,&turn,&num_turns);
    }
    print_board(board);
    return (EXIT_SUCCESS);
}

