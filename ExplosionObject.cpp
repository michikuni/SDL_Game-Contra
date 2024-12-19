#include "ExplosionObject.h"

ExplosionObjects::ExplosionObjects()
{
    frame_height_ = 0;
    frame_width_ = 0;
    frame_ = 0;
}
ExplosionObjects::~ExplosionObjects()
{
}

bool ExplosionObjects::LoadImg(std::string path, SDL_Renderer *screen)
{
    bool ret = BaseObject::LoadImg(path, screen);

    if (ret)
    {
        frame_height_ = rect_.h;
        frame_width_ = rect_.w / NUM_FRAME_EXP;
    }

    return ret;
}
void ExplosionObjects::Set_clips()
{
    if (frame_height_ > 0 && frame_width_ > 0)
    {
        for (int r = 0; r <= 7; r++)
        {

            frame_clip[r].x = r * frame_width_;
            frame_clip[r].y = 0;
            frame_clip[r].w = frame_width_;
            frame_clip[r].h = frame_height_;
        }
    }
}

void ExplosionObjects::Show(SDL_Renderer *screen)
{
    SDL_Rect *current_clip = &frame_clip[frame_];
    SDL_Rect render_quad = {rect_.x, rect_.y, frame_width_, frame_height_};
    if (current_clip != NULL)
    {
        render_quad.w = current_clip->w;
        render_quad.h = current_clip->h;
    }

    SDL_RenderCopy(screen, p_object_, current_clip, &render_quad);
}