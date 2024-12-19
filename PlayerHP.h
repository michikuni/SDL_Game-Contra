#ifndef PLAYER_HP_H_
#define PLAYER_HP_H_

#include "CommonFunc.h"
#include "BaseObject.h"

class PlayerHP : public BaseObject
{
public:
    PlayerHP();
    ~PlayerHP();

    void SetNum(const int& num) {number_ = num; }
    void AddPos(const int& Xpos);
    void Show(SDL_Renderer* screen);
    void Init(SDL_Renderer* screen);\
    
    void InitCrease();
    void Decrease();
private:
    int number_;
    std::vector<int> pos_list_;
};

class PlayerMoney : public BaseObject
{
public:
    PlayerMoney();
    ~PlayerMoney();
    void Init(SDL_Renderer* screen);
    void Show(SDL_Renderer* screen);
    void SetPos(const int& x, const int& y){x_pos_ = x; y_pos_ = y;}
private:
    int x_pos_;
    int y_pos_;


};

#endif