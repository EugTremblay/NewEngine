#pragma once
#include"Engine.h"

class Entity;

using namespace homer;
/// <summary>
/// base class for all component to be added on entitys
/// </summary>
class Component
{
public:
    virtual ~Component() = default;
    Component(Entity* parent);

    virtual Entity* GetParent() { return m_Entity; };
    virtual void Start() {}
    virtual void Destroy() {}

    virtual Component* Clone(Entity* newParent) const = 0;


protected:
    Entity* m_Entity;
    //faire un igrahpic iaudio and everything pointer(forward declare)
};