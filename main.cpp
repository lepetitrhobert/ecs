#include <iostream>

#include "Component.hpp"
#include "ComponentModelStore.hpp"

class ComponentTest : public Component {
    public:
    virtual void do_initialize() {
        std::cout << "do_initialize()" << std::endl;
    }

    virtual void do_update() {
        std::cout << "do_update()" << std::endl;
    }

    virtual void do_delete() {
        std::cout << "do_delete()" << std::endl;
    }

    ComponentTest(std::string name) : Component(name) {}
    
    virtual ~ComponentTest() {}

    protected:
    virtual Component* clone() {
        return new ComponentTest(modelName);
    }
};

int main(int argc, char** argv) {
    ComponentModelStore* cms = ComponentModelStore::getInstance();
    Component* testModel = new ComponentTest("test");

    cms->registerComponentModel(testModel);
    
    Component* cloned = cms->createComponent("test");
    
    cloned->do_initialize();
    cloned->do_update();
    cloned->do_delete();

    delete cms;
    delete testModel;
    delete cloned;

    return 0;
}
