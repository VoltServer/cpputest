
#include "CppUTest/CommandLineTestRunner.h"

int main(int argc, char* argv[])
{
   // If the user passes any arguments, then run the tests using the provided
   // switches.  If they do not provide anything, we'll use our own self-
   // selected arguments.
   if (argc != 1) {
      return CommandLineTestRunner::RunAllTests(argc, argv);
   } else {
      char* defaultArgs[3];
      defaultArgs[0] = argv[0];  // Pass the executable name
      defaultArgs[1] = (char *) "-r2";    // Request two passes
      defaultArgs[2] = (char *) "-c";     // Colorize output
      return CommandLineTestRunner::RunAllTests(3, defaultArgs);
   }
}

