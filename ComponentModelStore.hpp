#ifndef __COMPONENT_STORE_HPP__
#define __COMPONENT_STORE_HPP__ 1

#include <map>
#include <string>

#include "Component.hpp"

class ComponentModelStore
{
    public:
    Component* createComponent(std::string modelName);
    void registerComponentModel(Component* model);

    static ComponentModelStore* getInstance();
    ~ComponentModelStore();

    private:
    ComponentModelStore();    

    std::map<std::string, Component*> componentModelStore;
};

#endif

