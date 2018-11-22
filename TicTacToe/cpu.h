/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cpu.h
 * Author: Doruk.Ozkazanc
 *
 * Created on 17 Kasım 2018 Cumartesi, 18:22
 */

#ifndef CPU_H
#define CPU_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "helper_functions.h"

#define WIDTH 4
#define HEIGHT 4

void copy_position(char _board[HEIGHT][WIDTH], char board[HEIGHT][WIDTH]);
int minimax(char board[HEIGHT][WIDTH], char* move, int depth, char cpu, char player, int alpha, int beta, int winner, bool maximing_player);



#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* CPU_H */

