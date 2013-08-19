#include "ComponentModelStore.hpp"

#include<iostream>

ComponentModelStore::ComponentModelStore() : componentModelStore() {}

ComponentModelStore::~ComponentModelStore() {}

ComponentModelStore* ComponentModelStore::getInstance() {
    static ComponentModelStore* instance = 0;
    if(instance == 0)
        instance = new ComponentModelStore;

    return instance;
}

void ComponentModelStore::registerComponentModel(Component* model)
{
    if(model == 0) {
        std::cout << "Can't register (Component*)nullptr." << std::endl;
    }

    std::pair<std::map<std::string, Component*>::iterator, bool> ret;
    ret = componentModelStore.insert( std::pair<std::string, Component*>(model->modelName, model));

    if(ret.second == false) {
        std::cout << "Component <" << model->modelName << "> was already registered." << std::endl;
    } else {
        std::cout << "Successfully registered component model named <" << model->modelName << ">." << std::endl;
    }
}

Component* ComponentModelStore::createComponent(std::string modelName) {
    std::map<std::string, Component*>::iterator it = componentModelStore.find(modelName);
    if(it == componentModelStore.end()) {
        std::cout << "Couldn't find Component model named <" << modelName << ">." << std::endl;
        return 0;
    } else {
        std::cout << "Found component named <" << modelName << ">, creating new instance." << std::endl;
        return it->second->clone();
    }
}
