#ifndef __COMPONENT_HPP__
#define __COMPONENT_HPP__ 1

#include <string>

class ComponentModelStore;

class Component
{
    friend class ComponentModelStore;    

    public:
    virtual void do_initialize() = 0;
    virtual void do_update() = 0;
    virtual void do_delete() = 0;

    virtual ~Component();
    Component(std::string name); 

    protected:
    virtual Component* clone() = 0;
    std::string modelName;
};


#endif
