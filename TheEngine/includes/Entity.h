#pragma once
#include <string>
#include <vector>
#include <map>
#include "Component.h"
#include "IUpdatable.h"
#include "IDrawable.h"
#include "ICollideable.h"
/// <summary>
/// Each object added in the world will be a Entity
/// </summary>
class Entity final{
    public:
    virtual ~Entity() = default;

    void Start() ;
    void Update(float dt) ;
    void Draw() ;
    void Destroy() ;
    Entity* Clone();
    /// <summary>
    /// returns the name of the entity
    /// </summary>
    /// <returns></returns>
    std::string GetName() {return m_Name;};
    /// <summary>
    /// tells if the entity should be active in the scene
    /// </summary>
    /// <param name="active"></param>
    void SetActive(bool active) { m_IsActive = active; };

    /// <summary>
    /// Adds a component to the entity and to its respective vectors
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <returns></returns>
    template<typename T>
    T* AddComponent()
    {
        T* component = new T(this);
        const type_info* type = &typeid(T);

        m_Components.emplace(type, component);

        IUpdatable* updatable = dynamic_cast<IUpdatable*>(component);
        IDrawable* drawable = dynamic_cast<IDrawable*>(component);
        ICollideable* collideable = dynamic_cast<ICollideable*> (component);
        if (updatable != nullptr)
        {
            m_Updates.push_back(updatable);
        }
        if (drawable != nullptr)
        {
            m_Draws.push_back(drawable);
        }
        if (collideable != nullptr)
        {
            //Engine::Get().physics.addCollider
          // m_Draws.push_back(drawable);
        }

        return component;
    }

    /// <summary>
    /// Returns a specified component
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <returns></returns>
    template<typename T>
    T* GetComponent()
    {
        const type_info* type = &typeid(T);
        auto Component = m_Components.find(type);
        return Component == m_Components.end()? nullptr:dynamic_cast<T*>(Component->second);
    }
    float GetX() {
        return m_X;
    }
    float GetY() {
        return m_Y;
    }
    float GetW() {
        return m_W;
    }
    float GetH() {
        return m_H;
    }
    void SetX(float x){
        m_X = x;
    }
    void SetY(float y) {
        m_Y = y;
    }
    void SetW(float w) {
        m_W = w;
    }
    void SetH(float h) {
        m_H = h;
    }
    private:
   
    std::string m_Name;
    float m_X, m_Y,m_W,m_H;
    std::map<const type_info*, Component*> m_Components;
    std::vector<IUpdatable*> m_Updates;
    std::vector<IDrawable*> m_Draws;
    int m_NumberOfClones;
protected:
    bool m_IsActive = true;
    friend class WorldService;
    Entity(std::string name);
    Entity(const Entity& other);
};

