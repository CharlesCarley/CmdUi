/*
-------------------------------------------------------------------------------
    Copyright (c) Charles Carley.

  This software is provided 'as-is', without any express or implied
  warranty. In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
-------------------------------------------------------------------------------
*/
#pragma once
#include "CmdUi/Common.h"
#include "CmdUi/Math.h"
#include "Utils/String.h"

namespace Rt2::CmdUi
{
    class Context final
    {
    private:
        Vec2I        _size{0, 0};
        size_t       _capacity{0};
        int          _pitch{0};
        char*        _frameBuffer{nullptr};
        ColorBuffer* _colorBuffer{nullptr};
        uint16_t     _cbSize{0};
        uint16_t     _cbCap{0};
        uint32_t*    _colorMap{nullptr};
        Vec2I        _color{CP_TRANSPARENT, CP_TRANSPARENT};
        bool         _useExtended{false};
        Platform*    _platform{nullptr};
        Path         _workingPath{};

    public:
        Context();
        explicit Context(Platform* other);
        ~Context();

        const Vec2I& size() const;

        int width() const;
        int height() const;

        void initialize();

        void useExtendedMode(bool val);
        void resetMode();

        void clear(const char& ch = ' ') const;

        void character(char ch, int x, int y) const;

        void character(char ch, const Vec2I& pt) const;

        void string(const String& str, int x, int y) const;

        void string(const String& str, const Vec2I& pt) const;

        void integer(const uint32_t& val, int x, int y, int width = -1) const;

        void line(int x, int y, int d, int o) const;

        void line(const Vec2I& pt, int d, int o) const;

        void rectangle(int x, int y, int w, int h) const;

        void rectangle(const RectI& rect) const;

        void flush() const;

        int poll(bool block);

        void foreground(const uint8_t& idx);

        void background(const uint8_t& idx);

        void color(const uint8_t& fg, const uint8_t& bg);

        uint8_t createColor(const Color& col);

        void moveTo(const int& x, const int& y);

        void lineTo(const int& x, const int& y, const int& ori);

        void addSegment(char ch) const;

        void clearPath();

        static void sleep(const uint32_t& ms);

    private:
        void initializePalette();

        void putExtended(char ch) const;

        void insertCharacter(char ch, int x, int y) const;

        void resizeBuffers(const Vec2I& newSize);
    };

    inline void Context::useExtendedMode(const bool val)
    {
        _useExtended = val;
    }

    inline const Vec2I& Context::size() const
    {
        return _size;
    }

    inline int Context::width() const
    {
        return _size.x;
    }

    inline int Context::height() const
    {
        return _size.y;
    }

    inline void Context::foreground(const uint8_t& idx)
    {
        _color.x = idx;
    }

    inline void Context::background(const uint8_t& idx)
    {
        _color.y = idx;
    }
}  // namespace Rt2::CmdUi
