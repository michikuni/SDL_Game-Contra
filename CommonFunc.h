#ifndef COMMOM_FUNCTION_H_
#define COMMOM_FUNCTION_H_

#include<iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <SDL.h> 
#include <SDL_image.h>

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

//screen
const int FRAME_PER_SECOND = 30; //fps
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 640;
const int SCREEn_BPP = 32;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;

const int RENDER_DRAW_COLOR =0xff;

#define BLANK_TILE 0
#define TILE_SIZE 64  //Kich thuoc mat luoi

#define MAX_MAP_X 400   //Kich thuoc chieu ngang map
#define MAX_MAP_Y 10    //Kich thuoc chieu doc map

#define STATE_MONEY 4

struct Input  //MainObject
{
    int left_;
    int right_;
    int up_;
    int down_; 
    int jump_;
};

struct Map //GameMap
{
    int start_x_;
    int start_y_;

    int _max_x;
    int _max_y;

    int tile[MAX_MAP_Y][MAX_MAP_X];
    std::string file_name_;
};

namespace SDLCommonFunc
{
    bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
}

#endif