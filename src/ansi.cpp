/// \file      ansi.cpp
/// \brief     ANSI terminal control for C++.
/// \author    Chris Swinchatt <chrisswinchatt@gmail.com>
/// \copyright Copyright (c) 2015 Chris Swinchatt
/// This program is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General
/// Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option)
/// any later version.
///
/// This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
/// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
/// details.
///
/// You should have received a copy of the GNU Lesser General Public License along with this program. If not, see
/// <http://www.gnu.org/licenses/>.
#ifndef ANSI_HPP
#define ANSI_HPP 1

#include <iostream>
#include <string>

namespace ansi {
    /// ANSI escape sequences.
    enum class command {
        cursor_up,
        cursor_down,
        cursor_forward,
        cursor_backward,
        cursor_next_line,
        cursor_prev_line,
        cursor_set_col,
        cursor_set_pos,
        clear_screen,
        clear_line,
        scroll_up,
        scroll_down,
        attribute
    };

    /// Transmits ANSI control sequences to an output stream.
    ///
    /// Provides methods to instruct ANSI-compliant terminals to perform functions such as moving the cursor, erasing
    /// some or all of the display, scrolling the display, and changing display attributes such as colour.
    ///
    /// This class holds references and is therefore non-copyable.
    ///
    /// \example ansi::terminal(std::cout)
    ///
    class terminal {
    public:
        /// Construct an ANSI control interface for a particular output stream.
        /// \param stream A reference to the output stream to use. The referred object may be any sub-class of
        /// std::ostream, including std::ostringstream and std::ofstream.
        explicit terminal(std::ostream& stream);

        /// Once constructed, the interface is non-copyable.
        terminal(const terminal&) = delete;

        static const std::string& escape();
    private:
        std::ostream& m_stream;
    };
} // namespace ansi


    /// Escape an ANSI command sequence.
    /// \param sequence The command sequence to escape.
    /// \return The escaped ANSI command is returned.
    std::string escape(const std::string& sequence);

    std::string reset()
    {
        return escape("0m");
    }

    enum class console_color {
        black   = 0,
        red     = 1,
        green   = 2,
        yellow  = 3,
        blue    = 4,
        magenta = 5,
        cyan    = 6,
        white   = 7
    };

    std::string color(color_t col, bool bright = true, bool is_fg = true)
    {
        std::stringstream sstream;
        if (bright) {
            sstream << "1;";
        }
        const unsigned num = static_cast<unsigned>(color)
        sstream << (unsigned(col) + ((is_fg) ? 30 : 40)) << "m";
        return escape(sstream.str());
    }
}
