/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   helper_functions.h
 * Author: Doruk.Ozkazanc
 *
 * Created on 15 Kasım 2018 Perşembe, 16:40
 */

#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include <stdio.h>
#include <stdbool.h>

#define WIDTH 4
#define HEIGHT 4


void print_board(char board[HEIGHT][WIDTH]);
void print_message(char winner);
bool move_inbounds(char* move);
char assign_cpu(char player);
bool space_available(char board[HEIGHT][WIDTH], char* move);
int make_move(char board[HEIGHT][WIDTH], char* move, char turn);
int decide_winner(char winner, char player);
int evaluate_position(char board[HEIGHT][WIDTH], char player);

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* HELPER_FUNCTIONS_H */

