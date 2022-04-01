#include "GameManager.h"

void GameManager::_register_methods(){
    register_method("_ready", &GameManager::_ready);
    register_method("_process", &GameManager::_process);
    register_method("_physics_process", &GameManager::_physics_process);
    register_method("_on_Player_hit", &GameManager::_on_Player_hit);

    register_property<GameManager, Ref<PackedScene>>("enemyInstance", &GameManager::enemyInstance, nullptr);
    register_property("enimNumber", &GameManager::enimNumber, 5);
    
    register_signal<GameManager>("ScoreChanged", Dictionary());
}

void GameManager::_init(){
    
}

void GameManager::_ready(){
    enimList = std::vector<Node2D*>();
    enemyCounter = 0;
    for(int i = 0; i < enimNumber; i++){
        auto enemy = static_cast<Node2D*>(enemyInstance->instance());
        call_deferred("add_child", enemy);
        //add_child(enemy);
        enimList.push_back(enemy);
    }
    
    _scoreLabel = (Label*) get_node("ParallaxBackground/Label");
    winScreen = (Panel*) get_node("ParallaxBackground2/Panel");
}

void GameManager::EnemyDeleted(){
    auto enemy = static_cast<Node2D*>(enemyInstance->instance());
    call_deferred("add_child", enemy);
    enimList.push_back(enemy);
    score--;
}

void GameManager::_on_Player_hit(Area2D *area){
    score++;
    area->get_parent()->get_parent()->queue_free();
    EnemyDeleted();
    std::cout << score << std::endl;
}

void GameManager::_process(float delta){

    if (score < 15){
        for(int i = 0; i < enimList.size(); ++i){
            if(enimList[i]->get_position().y > get_viewport()->get_size().y + 50){
                EnemyDeleted();
                enimList[i]->queue_free();
                enimList.erase(enimList.begin() + i);
            }
        }

        //Okay maar WAAROM MOET IK EEN INT NAAR STRING CONVERTEN EN DAN NOG SPECIFIEK NAAR EEN GODOT STRING?!?!?!??!?!?!?!?!?!
        //ik wil gewoon:
        //_scoreLabel->set_text("Score: " + score);
        std::string standardString = std::to_string(score);
        godot::String godotString = godot::String(standardString.c_str());
        _scoreLabel->set_text("Score: " + godotString);

    } else {
        //turn on winscreen
        winScreen->set_visible(true);
    }
}

void GameManager::_physics_process(float delta){
}


GameManager::GameManager()
: score(0)
{
    
}

GameManager::~GameManager(){

}
