#include "hoshidicts_jni_strings.hpp"

#include <iostream>
#include <string>
#include <string_view>

namespace {

void expect(bool condition, std::string_view message) {
  if (!condition) {
    std::cerr << message << '\n';
    std::exit(1);
  }
}

}  // namespace

int main() {
  const std::u16string supplementary_word = u"\U00020B9Fり付ける";
  const std::string standard_utf8 =
      "\xF0\xA0\xAE\x9F\xE3\x82\x8A\xE4\xBB\x98\xE3\x81\x91\xE3\x82\x8B";

  const std::string encoded = hoshidicts::jni::utf16_to_utf8(supplementary_word);
  expect(encoded == standard_utf8, "supplementary UTF-16 input must encode as standard UTF-8");

  const std::u16string decoded = hoshidicts::jni::utf8_to_utf16(standard_utf8);
  expect(decoded == supplementary_word, "standard UTF-8 input must decode back to UTF-16");

  return 0;
}
