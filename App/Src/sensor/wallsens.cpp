#include "wallsens.hpp"
namespace sensor{
    std::unique_ptr<WallParameter> Wall::thresh_ = nullptr;
    Wall::Wall(){
        if (!Wall::thresh_) {
        Wall::thresh_ = std::make_unique<WallParameter>();  // 動的メモリ割り当て（スマートポインタを使って）
        }
        for (int i = 0; i < 4; ++i) {
        Wall::thresh_->dir[i] = 100;  // すべてのdirを10に設定
        }
        std::unique_ptr<pxstr::Creater> pxstr_c = std::make_unique<pxstr::Creater>();
        pxstr_ = pxstr_c->Create();
        pxstr_ -> Init();
        ir_ = std::make_unique<ir::Driver>();
        tim1_ = std::make_unique<tim::Wait>(htim1);
    }
    void Wall::ReadVal(){
        ir_ -> On();//ir光らせる
        tim1_ -> Us(20);//充電まつ
        pxstr_ -> ReadVal();//読む
        ir_ -> Off();//ir消す
        WallParameter* temp = pxstr_ -> get_val_ptr();//代入
        // for (int i = 0; i < 4; i++) {
        //     std::cout << "dir[" << i << "] = " << temp->dir[i] << std::endl;
        //     std::cout << "thresh[" << i << "] = " << thresh_->dir[i] << std::endl;
        // }
        for (int i = 0; i < 4; i++) {
            if (temp->dir[i] > Wall::thresh_->dir[i]) { 
                wp_->dir[i] = 1;
            } else {
                wp_->dir[i] = 0;
            }
        }//wp_とthresh_比べてwp_のがデカければ1,小さければ0.
    }
    WallParameter* Wall::get_val_ptr(){
        return wp_;
    }
}