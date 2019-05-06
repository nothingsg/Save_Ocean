#pragma once
#include <ctime>
#include <graphics.h>
#include "Vect2.h"
#include "Vect3.h"
#include "Matrix2.h"
#include "Matrix3.h"
#include "Random.h"
#include <vector>

#define PI 3.141592653589793238462643383249901429f


void Draw_line(const Vect2 &start, const Vect2 &end);
void Show_Text(const Vect2 &position, const LPCTSTR &text);
void Draw_Modle(std::vector<Vect2> modle, Vect2 position, Matrix2 rotate, float scale = 1.0f, bool IS_loop = true);
void Draw_UI(std::vector<Vect2> modle, Vect2 position, Matrix2 rotate, float scale = 1.0f, bool IS_loop = true);

Vect2 GetMousePos(HWND hWnd);
#define is_key_down(key) ((GetAsyncKeyState(key) & 0x8000) ? 1:0)