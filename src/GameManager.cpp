#include "GameManager.h"

void GameManager::_register_methods(){
    register_method("_ready", &GameManager::_ready);
    register_method("_process", &GameManager::_process);
    register_method("_physics_process", &GameManager::_physics_process);
    register_method("_on_Player_hit", &GameManager::_on_Player_hit);
    register_method("_on_Enemy_dropped", &GameManager::_on_Enemy_dropped);

    register_property<GameManager, Ref<PackedScene>>("enemyInstance", &GameManager::enemyInstance, nullptr);
    register_property("enimNumber", &GameManager::enimNumber, 5);
    register_property("ScoreToWin", &GameManager::ScoreToWin, 10);
    
    register_signal<GameManager>("GameEnded");
}

void GameManager::_init(){
    
}

void GameManager::_ready(){
    add_user_signal("dropped");
    add_user_signal("GameEnded");
    for(int i = 0; i < enimNumber; i++){
        auto enemy = static_cast<Node2D*>(enemyInstance->instance());
        call_deferred("add_child", enemy);
        enemy->connect("dropped", this, "_on_Enemy_dropped");
        connect("GameEnded", enemy, "_on_game_end");
    }
    
    _scoreLabel = (Label*) get_node("ParallaxBackground/Label");
    winScreen = (Panel*) get_node("ParallaxBackground2/Panel");
    UpdateScore();
}

void GameManager::EnemyDeleted(){
    auto enemy = static_cast<Node2D*>(enemyInstance->instance());
    enemy->get_signal_connection_list("dropped").push_back(&GameManager::_on_Enemy_dropped);
    call_deferred("add_child", enemy);
    enemy->connect("dropped", this, "_on_Enemy_dropped");
    connect("GameEnded", enemy, "_on_game_end");
}

void GameManager::_on_Enemy_dropped(){
    score--;
    EnemyDeleted();
    UpdateScore();
}

void GameManager::_on_Player_hit(Area2D *area){
    area->get_parent()->get_parent()->queue_free();
    EnemyDeleted();
    score++;
    UpdateScore();
}

void GameManager::UpdateScore(){
    godot::String scoreText = "Score: " + String::num_int64(score);
    _scoreLabel->set_text(scoreText);
    // End Game
    if (score >= ScoreToWin) {
        winScreen->set_visible(true);
        emit_signal("GameEnded");
    }
}


void GameManager::_process(float delta){

}

void GameManager::_physics_process(float delta){

}


GameManager::GameManager()
    : score(0), scoreText(""){
}

GameManager::~GameManager(){

}
