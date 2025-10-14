#pragma once
#include <string>
#include "Color.h"
struct Flip
{
    bool h;
    bool v;
};
struct RectI
{
    int x;
    int y;
    int w;
    int h;
};
struct RectF
{
    float x;
    float y;
    float w;
    float h;
};
class IGraphics{
public:
    virtual ~IGraphics() = default;
    /// <summary>
    /// Initializes the service
    /// </summary>
    /// <param name="title"></param>
    /// <param name="w"></param>
    /// <param name="h"></param>
    /// <returns></returns>
    virtual bool Initialize(const std::string& title, int w, int h) = 0;
    /// <summary>
    /// Shutdown the service and deletes everything
    /// </summary>
    virtual void Shutdown() = 0;
    /// <summary>
    /// Sets the render draw color
    /// </summary>
    /// <param name="color"></param>
    virtual void SetColor(const Color& color) = 0;
    /// <summary>
    /// Clear the renderer
    /// </summary>
    virtual void Clear() = 0;
    /// <summary>
    /// Presents the current render
    /// </summary>
    virtual void Present() = 0;
    /// <summary>
    /// Draws a empty rect 
    /// </summary>
    /// <param name="x"></param>
    /// <param name="y"></param>
    /// <param name="w"></param>
    /// <param name="h"></param>
    /// <param name="color"></param>
    virtual void DrawRect(float x, float y, float w, float h, const Color& color) = 0;
    /// <summary>
    /// Draws a empty rect from a rect
    /// </summary>
    /// <param name="rect"></param>
    /// <param name="color"></param>
    virtual void DrawRect(const RectF& rect, const Color& color) = 0;
    /// <summary>
    /// Draws a filled rect
    /// </summary>
    /// <param name="x"></param>
    /// <param name="y"></param>
    /// <param name="w"></param>
    /// <param name="h"></param>
    /// <param name="color"></param>
    virtual void FillRect(float x, float y, float w, float h, const Color& color) = 0;
    /// <summary>
    /// Draws a filled rect from a rect
    /// </summary>
    /// <param name="rect"></param>
    /// <param name="color"></param>
    virtual void FillRect(const RectF& rect, const Color& color) = 0;
    virtual void DrawLine(float x1, float y1, float x2, float y2, const Color& color) = 0;
    /// <summary>
    /// Loads texture and adds it to the cache
    /// </summary>
    /// <param name="filename"></param>
    /// <returns></returns>
    virtual size_t LoadTexture(const std::string& filename) = 0;
    /// <summary>
    /// Draws a specified Texture
    /// </summary>
    /// <param name="id"></param>
    /// <param name="src"></param>
    /// <param name="dst"></param>
    /// <param name="angle"></param>
    /// <param name="flip"></param>
    /// <param name="color"></param>
    virtual void DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color) = 0;
    /// <summary>
    /// Draws a specified Texture
    /// </summary>
    /// <param name="id"></param>
    /// <param name="src"></param>
    /// <param name="dst"></param>
    /// <param name="angle"></param>
    /// <param name="flip"></param>
    /// <param name="color"></param>
    virtual void DrawTexture(size_t id, const RectF& dst, const Color& color) = 0;
    /// <summary>
    /// Draws a specified Texture
    /// </summary>
    /// <param name="id"></param>
    /// <param name="src"></param>
    /// <param name="dst"></param>
    /// <param name="angle"></param>
    /// <param name="flip"></param>
    /// <param name="color"></param>
    virtual void DrawTexture(size_t id, const Color& color) = 0;
    virtual void GetTextureSize(size_t id, int* w, int* h) = 0;
    /// <summary>
    /// Loeads ttf font and adds it to the cache
    /// </summary>
    /// <param name="filename"></param>
    /// <param name="fontSize"></param>
    /// <returns></returns>
    virtual size_t LoadFont(const std::string& filename, int fontSize) = 0;
    /// <summary>
    /// Shows a string on the screen
    /// </summary>
    /// <param name="text"></param>
    /// <param name="fontId"></param>
    /// <param name="x"></param>
    /// <param name="y"></param>
    /// <param name="color"></param>
    virtual void DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color) = 0;
    virtual void GetTextSize(const std::string& text, size_t fontId, int* w, int* h) = 0;
    };