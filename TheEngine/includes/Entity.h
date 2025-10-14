#pragma once
#include <string>
#include <vector>
class Entity final{
    public:
    virtual ~Entity() = default;

    void Start() {};
    void Update(float dt) {};
    void Draw() {};
    void Destroy() {};
    std::string GetName() {return m_Name;};
    // void AddComponent(Component* cmp)
    // {
    //     m_Components.emplace_Back
    // }
    private:
    std::string m_Name;
    //les entity vont dependre de leur component, et non une classe qui herite de entitiy
    //std::vector<Composant> m_Components;
};