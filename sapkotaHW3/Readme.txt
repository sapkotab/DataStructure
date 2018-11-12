Using the mystring.hPreview the document and mystring.cpp, (instead of including the standard <string> library)

1) implement a text file formatting program. It takes a text file data.txt as an input file. The file has a few lines of text but the length(column) of the line is arbitrary. One line could have anywhere between 1 to 200 characters before a new line (carriage return). Your program should ask the number of column to the user and format the text file accordingly. For example, if a user types 65, every line should be aligned 65 long. You may have to combine two lines to one to eliminate the white spaces and blank lines, or split one to two.

2) in cases you need to change line in the middle of a word, you need to use a hyphen (- ) to connect a word between two lines.

3) There should be no more than one white space between two words. Multiple spaces, newlines or tabs must be replaced with a space.

You can assume that a hyphen can be added after the maximum column. So if you're formatting a text to 60 columns and a word is starting at the 60th column, you can add hyphen at 61st. Only the hyphen can come at 61st.

For the output, display the formatted text on screen and save it to data.out.
 

Hint: read Appendix F for the file I/O and string handling. You may find eat_white( ) function useful for removing white spaces. Read Standard C String & Character  (Links to an external site.)Links to an external site.and use appropriate functions like strcpy, strcat, memcmp etc.