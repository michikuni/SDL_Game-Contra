
#include "BaseObject.h"

BaseObject::BaseObject() //Dinh nghia ham
{
    p_object_=NULL;
    rect_.x = 0;
    rect_.y = 0;
    rect_.w = 0;
    rect_.h = 0;
}
BaseObject::~BaseObject()
{
    Free();
}

bool BaseObject::LoadImg(std :: string path, SDL_Renderer* screen)
{
    Free();
    SDL_Texture* new_texture = NULL;

    SDL_Surface* load_surface = IMG_Load(path.c_str());
    if(load_surface != NULL) //Kiem tra xem load_surface co chay khong
    {
        SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format,COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B)); //Xoa background cua nhan vat 
        new_texture = SDL_CreateTextureFromSurface(screen, load_surface);      //Chuyen surface ve texture
        if(new_texture != NULL)     //Sau khi convert thanh cong
        {
            rect_.w = load_surface->w;
            rect_.h = load_surface->h;
        }
        SDL_FreeSurface(load_surface);
    }
    p_object_ = new_texture;

    return p_object_ != NULL;
}

void BaseObject::Render(SDL_Renderer* des, const SDL_Rect* clip   /* = NULL */)
{
    SDL_Rect renderquad = {rect_.x, rect_.y, rect_.w, rect_.h} ;   //Vi tri, kich thuoc tam anh

    SDL_RenderCopy(des, p_object_, clip, &renderquad); //Day thong so p_object_ len des voi kich thuoc va vi tri renderquad
}

void BaseObject::Free()
{
    if(p_object_ != NULL)
    {
        SDL_DestroyTexture(p_object_);
        p_object_ = NULL;
        rect_.w = 0;
        rect_.h = 0;
    }
}