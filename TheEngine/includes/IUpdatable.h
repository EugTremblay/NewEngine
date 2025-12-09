#pragma once
/// <summary>
///  interface to add on updatable components
/// </summary>
class IUpdatable
{
public:
    virtual void Update(float dt) = 0;
};