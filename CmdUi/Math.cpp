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
#include "CmdUi/Math.h"
#include <cstdio>

namespace Rt2::CmdUi
{
    Vec2I Vec2I::maxPoint(const Vec2I& rhs) const
    {
        return {
            std::max<int>(x, rhs.x),
            std::max<int>(y, rhs.y),
        };
    }

    Vec2I Vec2I::minPoint(const Vec2I& rhs) const
    {
        return {
            std::min<int>(x, rhs.x),
            std::min<int>(y, rhs.y),
        };
    }

    const char* Color::extractSequence(const char* buf) const
    {
        const ColorU u(Rgb);
        _scratch[Clamp(
            (int)snprintf(
                _scratch,
                31,
                buf,
                (int)u.b[RByte],
                (int)u.b[GByte],
                (int)u.b[BByte]),
            0,
            31)] = 0;
        return _scratch;
    }

    const char* Color::foreground() const
    {
        return extractSequence(RgbFormatFg);
    }

    const char* Color::background() const
    {
        return extractSequence(RgbFormatBg);
    }
} // namespace Rt2::Ui
