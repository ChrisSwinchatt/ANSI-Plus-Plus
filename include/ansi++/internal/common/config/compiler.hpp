/// \file      ansi++/internal/common/config/compiler.hpp
/// \brief     ANSI++ compiler/language configuration and feature-detection.
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
#ifndef ANSIXX_INTERNAL_COMMON_CONFIG_COMPILER_HPP
#define ANSIXX_INTERNAL_COMMON_CONFIG_COMPILER_HPP 1

// Check for C++11.
#if !defined(__cplusplus) || __cplusplus < 201103L
# error ANSI++ expects C++11, but the compiler does not support it.
#endif // !__cplusplus || __cplusplus < 201103L

#endif // ! ANSIXX_INTERNAL_COMMON_CONFIG_COMPILER_HPP
