#include "PlayerHP.h"

PlayerHP::PlayerHP()
{
    number_ = 0;
}

PlayerHP::~PlayerHP()
{

}

void PlayerHP::AddPos(const int& xp)
{
    pos_list_.push_back(xp);
}

void PlayerHP::Init(SDL_Renderer *screen)
{
    bool ret = LoadImg("Pictu/player_hp.png", screen);
    number_ = 3;
    if(pos_list_.size() > 0)
    {
        pos_list_.clear();
    }
    AddPos(20);
    AddPos(60);
    AddPos(100);
}
void PlayerHP::Show(SDL_Renderer* screen)
{
    for(int i=0; i<pos_list_.size(); i++)
    {
        rect_.x = pos_list_.at(i);
        rect_.y =  0;
        Render(screen);

    }
}

void PlayerHP::Decrease()
{
    number_--;
    pos_list_.pop_back();
}

void PlayerHP::InitCrease()
{
    number_++;
    int last_pos = pos_list_.back();
    last_pos += 40;
    pos_list_.push_back(last_pos);  
}

PlayerMoney::PlayerMoney()
{
    x_pos_ = 0;
    y_pos_ = 0;
}

PlayerMoney::~PlayerMoney()
{

}

void PlayerMoney::Init(SDL_Renderer * screen)
{
    bool ret = LoadImg("Pictu/money.png", screen);
}

void PlayerMoney::Show(SDL_Renderer * screen)
{
    rect_.x = x_pos_;
    rect_.y = y_pos_;
    Render(screen);
}