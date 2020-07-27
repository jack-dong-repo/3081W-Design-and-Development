**Refactoring 1:**
During lecture Dr. Challou clarified that it was acceptable to simply change the last stop’s probability generation to zero. With this information I applied this fix to passenger_generator.cc and random_passenger_generator.cc. These fixes reflected starting in branch 22-between-stops (first cc file) and branch 23-regression-test (second cc file).

It was not until 23-regression-test when piazza post @1159 mentioned this was not enough. I changed passenger_generator.cc such that the last stop’s probability is not within generation_probabilities_ at all.

**Refactoring 2:**
I applied “Extract Method” as I was developing my program within drivers/configuration_sim.cc. I chose to write about these extractions because Piazza post @1124 permitted refactors outside of /src/ and because I significantly used extraction during my implementation. Branch 16-config-sim accounts for only 2 args. Each branch after 16 until 24 adds to the program.

Since my goals were to implement parameter handling for different number of arguments, I had many repeat functions such as (1) check if simulation time was a positive number (2) check if bus deployment time is a positive number (3) check if inputted file can be opened. Since I wanted my program to handle one to four arguments, these three functions had to be applied four times. In addition, I extracted how the program handles each number of arguments from the main method so (into ArgN(...) functions where N is an integer from one to four). This way parameter handling goes from over half the main program to just one line. This structure makes the main function much cleaner, shorter, and it prevents readers from being overwhelmed / distracted from the other functionalities of main().

Update (12/09): I moved all the methods to /src/config_sim_helper.h as in branch 25-config-helper.
For the purposes of exercising refactoring and minimizing complications, I used static methods instead of creating a new class.

**Assumption 1:**
I chose the first suggestion in lab 15. My regression test is called drivers/regression2_driver.cc instead of the suggested drivers/regression_test2.cc so it would follow the makefile and other driver names conventions. I created regression2 versions of local simulator. The current setup generates the same passengers for testing purposes. For more realistic results, comment out src/passenger_factory.cc line 15.

  #define CONSTPASS 1

**Assumption 2:**
[src/config_sim_helper.h:23 - static/global string variables are not permitted]

Google style discourages the use of string global variables, but for data type and  file handling ease I decided against this rule. If resolving this is a must, I would make CheckFile(), all the ArgN() methods, and ArgumentHandling() return std::string - which would be the filename that works (config.txt or custom) and work through handling char * vs std::string variables. Having the filename as a global variable makes assigning strings much easier for future devs.

**Assumption 3:**
It was not until 12/09 when I learned how to properly link Github issues and commits. Up until now I viewed them as different features so I would create branches and issues, but just close issues when it’s resolved without clarifying which commit. For iteration 3  I manually entered details through the Github UI.

**Assumption 4:**
I have CONSTPASS commented out in final turn in, and I also added how to use it in the main page developer guide.
