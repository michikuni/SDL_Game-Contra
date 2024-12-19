#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include <vector>
#include "CommonFunc.h"
#include "BaseObject.h"
#include "BulletObject.h"

#define Gravity 0.8
#define MAX_FALL_SPEED 10
#define PLAYER_SPEED 8
#define PLAYER_JUMP_VAL 20

class MainObject : public BaseObject //Khoi tao MainObject ke thua BaseObject
{
    public:
    MainObject();
    ~MainObject();

    enum WalkType
    {
        WALK_RIGHT = 0,
        WALK_LEFT = 1,
    };

    bool LoadImg(std::string path, SDL_Renderer* screen); //Thong so rieng kich thuoc anh
    void Show(SDL_Renderer* des);  //Show tung frame
    void HandleInputAction(SDL_Event events, SDL_Renderer* screen); //Xu ly di chuyen
    void set_clip();  //Ham tao clip 

    void DoPlayer(Map& map_data_);
    void CheckToMap(Map& map_data_);
    void SetMapXY(const int map_x, const int map_y){map_x_ = map_x;map_y_ = map_y;}
    void CenterEntityOnMap(Map& map_data); 
    void UpdateImagePlayer(SDL_Renderer* des);
    SDL_Rect GetRectFrame();

    void set_bullet_list(std::vector<BulletObject*> bullet_list)
    {
        p_bullet_list_ = bullet_list;
    }
    std::vector<BulletObject*> get_bullet_list() const {return p_bullet_list_;}
    void HandleBullet(SDL_Renderer* des);
    void RemoveBullet(const int& idx);
    void IncreaseMoney();
    int get_frame_width() const {return width_frame_; }
    int get_frame_height() const {return height_frame_; }
    void set_come_back_time(const int& cb_time){come_back_time_ = cb_time; }
    int GetMoneyCount() const {return money_count;}
    private: 
        int money_count;
        std :: vector<BulletObject*> p_bullet_list_;
        float x_val_;  //Khoang cach di chuyen moi nut bam trai phai
        float y_val_;   //Khoang cach di chuyen moi nut len xuong
        float x_pos_;  // Vi tri hien tai cua nhan vat
        float y_pos_;  //Vi tri hien tai cua nhan vat

        int width_frame_; //Kich thuoc cua nhan vat ung voi tung frame
        int height_frame_; 

        SDL_Rect frame_clip_[8]; //Luu cac frame
        Input input_type_;  //Luu trang thai
        int frame_;  //Luu chi so frame
        int status_;  //Kieu di chuyen, phai hay trai
         
        bool on_ground_;

        int map_x_;
        int map_y_;
        

        int come_back_time_;


};



#endif