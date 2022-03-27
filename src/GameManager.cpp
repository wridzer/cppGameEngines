#include "GameManager.h"

void GameManager::_register_methods(){
    register_method("_process", &GameManager::_process);
    register_property<GameManager, Node2D*>("Enemy Instance", &GameManager::enemyInstance, nullptr);
    register_property<GameManager, int>("enimNumber", &GameManager::enimNumber, 5);
}

GameManager::GameManager(){
    // std::vector<Node2D*> enimList;
    // for (int i = 0; i < enimNumber; ++i) {
    //     Node2D *enemy = Node2D::_new();
    //     enemy = enemyInstance;
    //     enimList.push_back(enemy);
    // }
}

GameManager::~GameManager(){

}

void GameManager::_process(float delta){
    
}