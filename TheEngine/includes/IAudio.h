#pragma once  
#include <string>
class IAudio{
public:
    virtual ~IAudio() = default;
    /// <summary>
    /// Loads music and adds it to the cache
    /// </summary>
    /// <param name="filename"></param>
    /// <returns></returns>
    virtual size_t LoadMusic(const std::string& filename) = 0;
    /// <summary>
    /// Loads sound and adds it to the cache
    /// </summary>
    /// <param name="filename"></param>
    /// <returns></returns>
    virtual size_t LoadSound(const std::string& filename) = 0;
    /// <summary>
    /// Plays music that loops indefinitly
    /// </summary>
    /// <param name="id"></param>
    virtual void PlayMusic(size_t id) = 0;
    /// <summary>
    /// Plays music and loops the specified amount of times
    /// </summary>
    /// <param name="id"></param>
    /// <param name="loop"></param>
    virtual void PlayMusic(size_t id, int loop) = 0;
    /// <summary>
    /// Plays a sound effect once
    /// </summary>
    /// <param name="id"></param>
    virtual void PlaySFX(size_t id) = 0;
    /// <summary>
    /// Plays a sound effect the sepecified ammount of times
    /// </summary>
    /// <param name="id"></param>
    /// <param name="loop"></param>
    virtual void PlaySFX(size_t id, int loop) = 0;
    /// <summary>
    /// Pauses music until ResumeMusic is called
    /// </summary>
    virtual void PauseMusic() = 0;
    /// <summary>
    /// Stops the music
    /// </summary>
    virtual void StopMusic() = 0;
    /// <summary>
    /// Resumes the previously paused music
    /// </summary>
    virtual void ResumeMusic() = 0;
    /// <summary>
    /// Sets volume for every sound
    /// </summary>
    /// <param name="volume"></param>
    virtual void SetVolume(int volume) = 0;
    /// <summary>
    /// Sets volume for a specified sound
    /// </summary>
    /// <param name="soundId"></param>
    /// <param name="volume"></param>
    virtual void SetVolume(size_t soundId, int volume) = 0;
private:

};