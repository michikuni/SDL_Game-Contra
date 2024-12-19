#ifndef EXPLOSION_H_
#define EXPLOSION_H_

#include "BaseObject.h"
#include "CommonFunc.h"

#define NUM_FRAME_EXP 8

class ExplosionObjects : public BaseObject
{
public:
    ExplosionObjects();
    ~ExplosionObjects();
private:
    int frame_width_;
    int frame_height_;

    unsigned int frame_; 
    SDL_Rect frame_clip[8];
public:
    void Set_clips();
    void Set_frame(const int& fr) { frame_ = fr; }
    virtual bool LoadImg(std::string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* screen);
    int get_frame_width() const { return frame_width_; }
    int get_frame_height() const { return frame_height_; }
};



#endif