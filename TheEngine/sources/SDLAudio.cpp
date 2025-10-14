#include "SDLAudio.h"

SDLAudio::SDLAudio()
{

}

size_t SDLAudio::LoadMusic(const std::string& filename)
{
	const size_t musicId = std::hash<std::string>()(filename);

	if (m_MusicCache.count(musicId) > 0)
	{
		return musicId;
	}

	Mix_Music* music;
	music = Mix_LoadMUS(filename.c_str());

	if (music != NULL)
	{
		m_MusicCache[musicId] = music;
		return musicId;
	}
	return -1;
}

size_t SDLAudio::LoadSound(const std::string& filename)
{
	const size_t soundId = std::hash<std::string>()(filename);

	if (m_SoundCache.count(soundId) > 0)
	{
		return soundId;
	}

	Mix_Chunk* sample;
	sample = Mix_LoadWAV(filename.c_str());

	if (sample != NULL)
	{
		m_SoundCache[soundId] = sample;
		return soundId;
	}
	return -1;
}

void SDLAudio::PlayMusic(size_t id)
{
	Mix_PlayMusic(m_MusicCache[id], -1);
}

void SDLAudio::PlayMusic(size_t id, int loop)
{
	Mix_PlayMusic(m_MusicCache[id], loop);
}
void SDLAudio::PlaySFX(size_t id)
{
	Mix_PlayChannel(-1, m_SoundCache[id], 0);
}

void SDLAudio::PlaySFX(size_t id, int loop)
{
	Mix_PlayChannel(-1, m_SoundCache[id], loop);
}

void SDLAudio::PauseMusic()
{
	Mix_PauseMusic();
}

void SDLAudio::StopMusic()
{
	Mix_HaltMusic();
}

void SDLAudio::ResumeMusic()
{
	Mix_ResumeMusic();
}

void SDLAudio::SetVolume(int volume)
{
	Mix_Volume(-1, volume);
}

void SDLAudio::SetVolume(size_t soundId, int volume)
{
	Mix_VolumeChunk(m_SoundCache[soundId], volume);
	
}
