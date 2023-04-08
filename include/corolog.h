#pragma once

#include <fmt/core.h>

#include <iostream>
#include <source_location>
#include <string_view>

namespace corolog {

void log(const std::string_view message, const std::source_location location =
                                             std::source_location::current()) {
  std::clog << "file: " << location.file_name() << "(" << location.line() << ":"
            << location.column() << ") `" << location.function_name()
            << "`: " << message << '\n';
}

template <typename T>
void fun(T x) {
  log(x);
}

enum class Level { TRACE, DEBUG };

void set_level(Level level);

}  // namespace corolog