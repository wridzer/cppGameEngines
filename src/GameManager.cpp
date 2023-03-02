#include "GameManager.h"

void GameManager::_register_methods(){
    register_method("_ready", &GameManager::_ready);
    register_method("_process", &GameManager::_process);
    register_method("_physics_process", &GameManager::_physics_process);
    register_method("_on_Player_hit", &GameManager::_on_Player_hit);
    register_method("_on_Enemy_dropped", &GameManager::_on_Enemy_dropped);

    register_property<GameManager, Ref<PackedScene>>("enemyInstance", &GameManager::enemyInstance, nullptr);
    register_property("enimNumber", &GameManager::enimNumber, 5);
    
    register_signal<GameManager>("ScoreChanged", Dictionary());
}

void GameManager::_init(){
    
}

void GameManager::_ready(){
    enimList = std::vector<Node2D*>();
    add_user_signal("dropped");
    for(int i = 0; i < enimNumber; i++){
        auto enemy = static_cast<Node2D*>(enemyInstance->instance());
        call_deferred("add_child", enemy);
        enemy->connect("dropped", this, "_on_Enemy_dropped");
    }
    
    _scoreLabel = (Label*) get_node("ParallaxBackground/Label");
    winScreen = (Panel*) get_node("ParallaxBackground2/Panel");

    //scoreText = "Score: " + std::to_string(score);
    //_scoreLabel->set_text(godot::String(scoreText.c_str()));
}

void GameManager::EnemyDeleted(){
    auto enemy = static_cast<Node2D*>(enemyInstance->instance());
    enemy->get_signal_connection_list("dropped").push_back(&GameManager::_on_Enemy_dropped);
    call_deferred("add_child", enemy);
    enemy->connect("dropped", this, "_on_Enemy_dropped");
}

void GameManager::_on_Enemy_dropped(){
    //score - 1
    score--;
    EnemyDeleted();
}

void GameManager::_on_Player_hit(Area2D *area){
    area->get_parent()->get_parent()->queue_free();
    EnemyDeleted();
    score++;
    //KeepScore(1);
}

//void GameManager::KeepScore(int amount) {
//    score = score + amount;
//    scoreText = "Score: " + std::to_string(score);
//    //godotString = String(scoreText.c_str());
//    //_scoreLabel->set_text(godotString);
//    //delete &tempGodotString;
//}

void GameManager::_process(float delta){

    godot::String scoreText = "Score: " + String::num_int64(score);
    //Godot::print(scoreText);
    _scoreLabel->set_text(scoreText);
    if (score > 15) {
        //turn on winscreen
        winScreen->set_visible(true);
    }
}

void GameManager::_physics_process(float delta){

}


GameManager::GameManager()
    : score(0), scoreText("") {
}

GameManager::~GameManager(){

}
