#pragma once

#include <utf8.h>

#include <iterator>
#include <string>
#include <string_view>

namespace hoshidicts::jni {

inline std::string utf16_to_utf8(std::u16string_view input) {
  std::string output;
  utf8::utf16to8(input.begin(), input.end(), std::back_inserter(output));
  return output;
}

inline std::u16string utf8_to_utf16(std::string_view input) {
  std::u16string output;
  utf8::utf8to16(input.begin(), input.end(), std::back_inserter(output));
  return output;
}

}  // namespace hoshidicts::jni
