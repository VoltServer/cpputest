
#include "CppUTest/CommandLineTestRunner.h"

int main(int argc, char* argv[])
{
   // If the user passes any arguments, then run the tests using the provided
   // switches.  If they do not provide anything, we'll use our own self-
   // selected arguments.
   if (argc != 1) {
      return CommandLineTestRunner::RunAllTests(argc, argv);
   } else {
      char* defaultArgs[4];
      defaultArgs[0] = argv[0];  // Pass the executable name
      defaultArgs[1] = (char *) "-r2";    // Request two passes
      defaultArgs[2] = (char *) "-c";     // Colorize output
#ifdef OUTPUT_JUNIT_XML
      defaultArgs[3] = (char *) "-ojunit"; // output JUnit ant style XML (for CircleCI)
#else
      defaultArgs[3] = (char *) "-onormal"; // otherwise we're running locally, use normal output
#endif
      return CommandLineTestRunner::RunAllTests(4, defaultArgs);
   }
}

