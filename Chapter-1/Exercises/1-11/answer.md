I would test the word count program by creating a collection of small test inputs where I already know the expected number of lines, words, and characters. First, I would test the simplest cases, such as an empty file, a file with only one character, a file with one word, and a file with one line containing several words separated by single spaces.

Then I would test whitespace edge cases. I would use inputs with leading spaces, trailing spaces, multiple spaces between words, blank lines, tabs, and newlines. These cases are important because the program’s definition of a word depends on transitions between whitespace and non-whitespace characters.

I would also test files that contain only whitespace, such as only spaces, only tabs, only newlines, or a mixture of all three. These should count characters and lines where appropriate, but they should not count any words.

Next, I would test punctuation and special characters. For example, I would try inputs like hello, world!, one-two, don't, and strings made entirely of punctuation. This would help determine whether the program counts words based only on whitespace separation, rather than trying to interpret punctuation as word boundaries.

I would also test unusual or difficult inputs, such as very long lines, files with no whitespace at all, files that do not end with a newline, and files containing non-printable characters. These cases could expose assumptions in the program about line length, final newlines, or character handling.

Finally, I would compare the program’s output against the expected counts for each test case. If possible, I would automate these tests so that changes to the program could be checked quickly.