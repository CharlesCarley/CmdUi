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
#include <cstdint>
#include <unordered_map>
#include "CmdUi/ColorCache.h"
#include "CmdUi/Math.h"
#include "Platform.h"

namespace Rt2::CmdUi
{
    class PlatformFile final : public Platform
    {
    private:
        OutputFileStream* _ofs{nullptr};
        int               _writes{0};
        Vec2I             _size{80, 20};

    public:
        explicit PlatformFile(const String& name);
        ~PlatformFile() override;

        void screenSizeHint(Vec2I& sz) override;
        void setScreenSize(int w, int h);

        void put(char ch) override;

        void put(const char* ch) override;

        void flush() override;

        int poll(bool block) override;

        void showCursor(bool show) override;

        void useBackBuffer(bool use) override;

        void setCursor(int16_t x, int16_t y) override;

        void resetCursor() override;

        void  close();

    };
}  // namespace Rt2::CmdUi
