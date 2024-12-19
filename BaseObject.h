
#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_

#include "CommonFunc.h"


class BaseObject{
public:
    BaseObject();
    ~BaseObject();
    void SetRect(const int& x, const int& y) {rect_.x = x, rect_.y = y;}    //Set kích thước cho rect
    SDL_Rect GetRect() const {return rect_;}   //Lấy ra rect cho hàm ấy
    SDL_Texture* GetObject() const {return p_object_;}    //Lấy ra p_object_

    virtual bool LoadImg(std :: string path, SDL_Renderer* screen);//Lắp ảnh bít map bên trên đối tượng p_object_ sau đó dùng p_object_ để fill vào màn hình
    void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);//Lắp ảnh bít map bên trên đối tượng p_object_ sau đó dùng p_object_ để fill vào màn hình
    void Free();

protected:
    SDL_Texture* p_object_;   //Biến lưu trữ hình ảnh
    SDL_Rect  rect_;     //Biến lưu thước của hình ảnh đó
};




#endif