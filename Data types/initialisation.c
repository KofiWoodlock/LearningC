/* key terms & code 
*/

int main() {

    /* External & static variables are initialised to 0 
    automatic and register variables have undefined (garbage) initial values
    */

    // for scalar variables may be initialised when defined 
    int x = 1;
    char squote = '\'';
    long day = 1000L * 60L * 60L * 24L; /* millisecond day */

    // external and static variables must be initialised with a constant
    // expression which is done once conceptually before runtime 

    /* For automatic and register variables initialisation is done every time
    the block or function is executed and the initialiser does not need to be 
    constant */

    return 0;
}