#pragma once

/**
 * \brief Function to generate words for the 'Memorable Password' option, this will generate words and combine them using '-'. (Example fruit-understood-bedroom9)
 * 
 * \param word_amount size_t Value that determines how many words will be generated in total.
 * \param caps   Weather the words will be capitalised, for example for example Foo-Bar4-Baz-Qux.
 * \param number This boolean determines weather a random number within a random word will be generated, for example foo-bar4-baz-qux.
 *
 * \return void

 */
auto GenerateWords(size_t word_amount, bool caps, bool number) -> void;

/**
 * \brief Generates random password using random letters, numbers and optionally symbols (Example: qA3]q{)*Z]MW<6kqA3]q{)*Z]MW<6k)
 * 
 * \param length size_t Value to decide the length of the random password.
 * \param allowSymbols Allows symbols to be included in the password. If enabled, symbols will be highlighted in red.
*  \return void
 */
auto GenerateRandomPassword(size_t length, bool allowSymbols) -> void;

/**
 * \brief Generates a random PIN. (Example: 10306150)
 * 
 * \param length size_t Value to decide the length of the random pin.
 * \return void
 */
auto GeneratePIN(size_t length) -> void;
