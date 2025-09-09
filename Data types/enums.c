/* Key terms & code: - enumeration 
    - A list of constant integer values 
*/

int main() {
    /* If not specified enums values begin from 0 and progress naturally */
    /* In this case NO = 0 and YES = 1 */
    /* Names in an enum must be different but values can be the same */
    enum boolean { NO, YES };

    // enumeration constants can have their value specified or not 
    // specified values:
    enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t', NEWLINE = '\n'};

    // unspecified values:
    enum months { JAN = 1, FEB, MAR, APR, MAY, JUN,
                  JUL, AUG, SEP, OCT, NOV, DEC};
    /* FEB = 2, MAR = 3, APR = 4 and so on */
}