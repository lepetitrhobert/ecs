#include <iostream>
#include <string>
#include <map>

struct Component {
    void (*processEntity)(long);
    size_t required_memory_per_entity;
};

class ComponentManager {
    public:
    long create_entity();
    void delete_entity(long id);
    
    void entity_subscribe(std::string component, long entity);
    void entity_unsubscribe(std::string component, long entity);
    void entity_update(std::string component, long entity);
        
    void add_component(std::string name, struct Component component);
    void remove_component(std::string name);
    void update_component(std::string name);
    
    private:
    std::map<std::string, struct Component> components;
    
    
};

int main(int argc, char** argv) {
    return 0;
}
