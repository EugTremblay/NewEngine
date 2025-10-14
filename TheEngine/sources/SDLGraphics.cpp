#pragma once
#include "SDLGraphics.h"
#include"SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
	


SDLGraphics :: SDLGraphics()
	:m_IsInit(false),
	m_Window(nullptr),
	m_Renderer(nullptr),
	m_TextureBuffer(nullptr)
{

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {

	    SDL_Log(SDL_GetError());
		
	}
}

bool SDLGraphics::Initialize(const std::string& title, int w, int h)
{

	int _x = SDL_WINDOWPOS_CENTERED;
	int _y = SDL_WINDOWPOS_CENTERED;
	Uint32 _flag = SDL_WINDOW_TOOLTIP;

	// _window est une variable de type SDL_Window* 
	m_Window = SDL_CreateWindow(title.c_str(), _x, _y, w, h, _flag);
	if (!m_Window)
	{
		//m_Logger->Log(SDL_GetError());
		return false;
	}



	_flag = SDL_RENDERER_ACCELERATED;

	m_Renderer = SDL_CreateRenderer(m_Window, 0, _flag);

	TTF_Init();

	if (!m_Renderer) {

		SDL_Log(SDL_GetError());
		return false;
	}

	m_IsInit = true;
	return m_IsInit;
}

void SDLGraphics::Shutdown()
{
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	TTF_Quit();
	SDL_Quit();
}

void SDLGraphics::SetColor(const Color& color)
{
	SDL_SetRenderDrawColor(m_Renderer, color.red,color.green,color.blue,color.alpha);
}

void SDLGraphics::Clear()
{
	SetColor(Color::Black);
	SDL_RenderClear(m_Renderer);
	
}

void SDLGraphics::Present()
{
	SDL_RenderPresent(m_Renderer);
}

void SDLGraphics::DrawRect(float x, float y, float w, float h, const Color& color)
{
	RectF  rect = { x,y,w,h };
	DrawRect(rect, color);
}

void SDLGraphics::DrawRect(const RectF& rect, const Color& color)
{
	SDL_FRect rekt = { rect.x,rect.y,rect.w,rect.h };
	SetColor(color);
	SDL_RenderDrawRectF(m_Renderer, &rekt);
}

void SDLGraphics::FillRect(float x, float y, float w, float h, const Color& color)
{
	RectF  rect = { x,y,w,h };
	FillRect(rect, color);
}

void SDLGraphics::FillRect(const RectF& rect, const Color& color)
{
	SDL_FRect rekt = { rect.x,rect.y,rect.w,rect.h };
	SetColor(color);
	SDL_RenderFillRectF(m_Renderer, &rekt);
}

void SDLGraphics::DrawLine(float x1, float y1, float x2, float y2, const Color& color)
{
}

size_t SDLGraphics::LoadTexture(const std::string& filename)
{
	const size_t textureId = std::hash<std::string>()(filename);

	if (m_TextureCache.count(textureId) > 0)
	{
		return textureId;
	}

	SDL_Texture* texture = IMG_LoadTexture(m_Renderer, filename.c_str());

	if (texture != NULL)
	{
		m_TextureCache[textureId] = texture;
		return textureId;
	}
	return -1;
}

void SDLGraphics::DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color)
{
	//Flip
	int sdlFlip = SDL_FLIP_NONE;
	if (flip.h) {
		sdlFlip = SDL_FLIP_HORIZONTAL;
	}
	if (flip.v) {
		sdlFlip |= SDL_FLIP_VERTICAL;
	}
	SDL_RendererFlip finalFlip = static_cast<SDL_RendererFlip>(sdlFlip);
	SDL_Rect sdlSrc = { src.x, src.y, src.w, src.h };
	SDL_Rect sdlDst = { 
		static_cast<int>( dst.x),
		static_cast<int>(dst.y),
		static_cast<int>(dst.w),
		static_cast<int>(dst.h) };
	//Voir avec prof, src rect dont work
	SDL_RenderCopyEx(m_Renderer, m_TextureCache[id], NULL, &sdlDst, angle, nullptr, finalFlip);
	//TODO COLOR
	//SDL_SetTextureColorMod(m_TextureCache[id], color*);
}

void SDLGraphics::DrawTexture(size_t id, const RectF& dst, const Color& color)
{
	/*SDL_Rect sdlDst = { dst.x,dst.y,dst.w,dst.h };
	SDL_RenderCopy(m_Renderer, m_TextureCache[id], &sdlDst, &sldDst);*/
}

void SDLGraphics::DrawTexture(size_t id, const Color& color)
{
}

void SDLGraphics::GetTextureSize(size_t id, int* w, int* h)
{
}

size_t SDLGraphics::LoadFont(const std::string& filename, int fontSize)
{
	const size_t fontId = std::hash<std::string>()(filename);

	if (m_FontCache.count(fontId) > 0)
	{
		return fontId;
	}

	TTF_Font* font = TTF_OpenFont(filename.c_str(), fontSize);

	if (font != NULL)
	{
		m_FontCache[fontId] = font;
		return fontId;
	}
	return -1;

}

void SDLGraphics::DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color)
{
	if (m_FontCache.count(fontId) > 0)
	{
		TTF_Font* font = m_FontCache[fontId];
		SDL_Color col = {
			.r = color.red,
			.g = color.green,
			.b = color.blue,
			.a = color.alpha
		};
		SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(),col);

		m_TextureBuffer = SDL_CreateTextureFromSurface(m_Renderer, surface);
		SDL_Rect rect = { 
			static_cast<int>(x),
			static_cast<int>(y),
			surface->w,
			surface->h
		};
		SDL_RenderCopy(m_Renderer, m_TextureBuffer, nullptr, &rect);
		SDL_FreeSurface(surface);
		SDL_DestroyTexture(m_TextureBuffer);
	}
}

void SDLGraphics::GetTextSize(const std::string& text, size_t fontId, int* w, int* h)
{
}
