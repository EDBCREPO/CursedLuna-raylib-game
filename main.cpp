#include <nodepp/nodepp.h>
#include <nodepp/worker.h>

using namespace nodepp;

#include "assets/script/game.cpp"
#include "assets/scenes/scene_2.cpp"
#include "assets/scenes/scene_1.cpp"
#include "assets/scenes/scene_0.cpp"

void onMain() {

    rl::Init( 800, 600, 120, "Cursed Luna" ); 
    rl::AppendScene( rl::scene::scene_0 );
    rl::HideCursor();

    rl::SetAttr( "Scene", array_t<function_t<void,ptr_t<rl::Scene>>>({
        rl::scene::scene_0, rl::scene::scene_1, rl::scene::scene_2
    }) );

    rl::SetAttr( "Sprite", array_t<rl::Texture>({
        rl::LoadTexture( "./assets/sprites/effect/selector.png" ),
        rl::LoadTexture( "./assets/sprites/effect/recharge.png" ),
        rl::LoadTexture( "./assets/sprites/player/player.png" ),
        rl::LoadTexture( "./assets/sprites/effect/items.png" ),
        rl::LoadTexture( "./assets/sprites/enemy/enemy.png" ),
        rl::LoadTexture( "./assets/sprites/effect/bala.png" ),
        rl::LoadTexture( "./assets/sprites/effect/prop.png" )
    }) );

    rl::SetAttr( "Sound", array_t<rl::Sound>({

    }) );

    rl::onClose([](){

        forEach( x, rl::GetAttr("Sprite").as<array_t<rl::Texture>>() ){ 
             if( rl::IsTextureValid(x) ){ rl::UnloadTexture(x); }
        }

        forEach( x, rl::GetAttr("Sound").as<array_t<rl::Sound>>() ){ 
             if( rl::IsSoundValid(x) ){ rl::UnloadSound(x); }
        } 
        
        console::log("Closed"); rl::Close();

    });

    rl::onDraw([=](){ rl::DrawFPS( 10, 10 ); });

}
