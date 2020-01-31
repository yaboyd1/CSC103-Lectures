/* goal: write a message to standard output
 * (will be printed in your terminal...) */

#include <iostream>
/* NOTE: "iostream" is just a C++ file on your computer.  The
 * #include <...> basically copies and pastes its contents here.
 * BTW, you can find the iostream file in the path
 * /usr/include/c++/[version of your gcc]/iostream
 * (but I don't think you'll get too much out of trying to read it...)
 * */
using std::cout;
/* the "full name" of cout is "std::cout".  "std" is like the
 * last/family name, and "cout" is like the first/given name.
 * In order to refer to cout just by its first name, we use
 * the above "using" statement.  If you want to read more,
 * the topic to search for is "namespaces". */

int main()
{
	/* the main() function is where your program begins...
	 * TODO: change the name of main to something else, try to compile,
	 * and take note of the error (you'll see something about the linker
	 * (whose name is "ld") not succeeding). */
	cout << "hello class!\n";
	/* TODO: remove the semicolon, try to compile, take note of the error
	 * message that will result. */
	return 0;
	/* NOTE: the "return 0" is used to communicate an "exit code" back to
	 * the process that ran your program (which will often be your shell).
	 * Whatever value main() returns is used as the "exit code".
	 * The exit codes are interpreted according to the following convention:
	 * An exit code of 0 is interpreted by the shell as "success",
	 * and EVERYTHING else is interpreted as some type of failure. */
	/* TODO: see for yourself: test out the following shell command using
	 * different return codes:
	 * $ ./a.out && echo "success"
	 * You'll notice that "success" is only printed when you return 0.
	 * */
	/* NOTE: the return code of the most recent command you have run
	 * is stored in a shell variable "$?".  You can examine it from
	 * your shell by running the command "echo $?" */
}

/* TODO: follow the tutorial on "building on the command line" from our
 * homepage.  Then just spend some time experimenting and see what you
 * can learn.  */

// vim:foldlevel=2
