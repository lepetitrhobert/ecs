#include <iostream>
#include <string>
#include <map>

struct Component {
    void (*initializeEntity)(long, void*)
    void (*processEntity)(long, void*);
    void (*deleteEntity)(long, void*);
    size_t required_memory_per_entity;
};

class ComponentManager {
    public:
    static long createEntity()                                              { return ComponentManager::get()->create_entity(); }
    static void deleteEntity(long id)                                       {        ComponentManager::get()->delete_entity(id); }
    static void entitySubscribe(std::string component, long entity)         {        ComponentManager::get()->entity_subscribe(component, id); }
    static void entityUnsubscribe(std::string component, long entity)       {        ComponentManager::get()->entity_unsubscribe(component, id); }
        
    static void addComponent(std::string name, struct Component component)  {        ComponentManager::get()->add_component(name, component); }
    static void removeComponent(std::string name);                          {        ComponentManager::get()->remove_component(name); }
    static void updateComponent(std::string name);                          {        ComponentManager::get()->update_component(name); }    
    
    private:
    long next_id;
    std::map<std::string, std::pair<struct Component, void*> components; 
    
    static ComponentManager* get() {
        static ComponentManager* instance = 0;
        if(instance == 0)
            instance = new ComponentManager;
        return instance;
    }
    
    ComponentManager() : next_id(0) {}
    ~ComponentManager() {
        std::map<std::string, std::pair<struct Component, void*>>::iterator it;  
        for(it=components->begin(); it != components.end(); it++) {
            free(it->second->second);
        }
    }    
    
    long create_entity() {
        return next_id++;
    }

    void delete_entity(long id) {
        
    }
    
    void entity_subscribe(std::string component, long entity) {
    }

    void entity_unsubscribe(std::string component, long entity) {
    }    

    void entity_update(std::string component, long entity) {
    }    
   
    void add_component(std::string name, struct Component component) {
    }

    void remove_component(std::string name) {
    }

    void update_component(std::string name) {
    }
};

int main(int argc, char** argv) {
    return 0;
}
