/// @file   sinSource.hpp
/// @author Enrico Fraccaroli
/// @date   Mar 16 2017
/// @copyright
/// Copyright (c) 2017 Enrico Fraccaroli <enrico.fraccaroli@gmail.com>
/// Permission to use, copy, modify, and distribute this software for any
/// purpose with or without fee is hereby granted, provided that the above
/// copyright notice and this permission notice appear in all copies.
///
/// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
/// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
/// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
/// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
/// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
/// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
/// OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

#pragma once

#include <cmath>
#include <iostream>

#define M_2_FOR_PI    6.2831853071795864

class SinSource
{
private:
    /// The sinusoid offset.
    double offset;
    /// The sinusoid amplitude.
    double amplitude;
    /// The sinusoid frequency.
    double frequency;

public:
    /// The output value.
    double out;

    /// @brief Constructor.
    SinSource(const double & _offset,
              const double & _amplitude,
              const double & _frequency) :
        offset(_offset),
        amplitude(_amplitude),
        frequency(_frequency),
        out()
    {
        // Nothing to do.
    }

    /// @brief Destructor.
    ~SinSource() = default;

    /// @brief Advance the sinusoid.
    /// @param t The current time.
    /// @return The current value.
    inline double compute(const double & t)
    {
        out = offset + amplitude * std::sin(M_2_FOR_PI * frequency * t);
        return out;
    }
};
