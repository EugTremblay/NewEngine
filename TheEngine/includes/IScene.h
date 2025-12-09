#pragma once
/// <summary>
/// Scene interface used to create scenes
/// </summary>
class IScene {
public:
    virtual ~IScene() = default;
    /// <summary>
    /// Loads the scene
    /// </summary>
    virtual void Load() = 0;
};