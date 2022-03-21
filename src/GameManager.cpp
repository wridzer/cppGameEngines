#include "GameManager.h"

GameManager::GameManager(){

}

GameManager::~GameManager(){

}

void GameManager::_register_methods(){
    register_method("_process", &GameManager::_process);
}