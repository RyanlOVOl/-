#pragma once
#include <easyX.h>
#include "constant.h"
#include "rule.h"

#ifndef FUNCTIONS_H  // �������뱣��
#define FUNCTIONS_H

extern int chessData[10][9];
void RenderChessboard(void);
void RenderChess();
void RenderChoose(int row,int column);
void InitData();

void RenderCanDownPos();
LPCTSTR DataToChess(int data);
#endif


