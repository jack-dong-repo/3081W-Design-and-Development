### Feedback for Iteration 1

Run on November 08, 13:02:09 PM.

<hr>

This feedback is being batched and will run every few hours. Note that these feedback tests are a *work in progress* and will likely be updated to contain more tests as they are developed. Check back periodically for more feedback. Take note that these tests are _incredibly slow_ because of the time it takes to compile 4 executables.

<hr>


### Basic Tests on Devel

+ Pass: Checkout devel branch.




#### Necessary Files and Structure

+ Pass: Check that directory "project" exists.

+ Pass: Check that directory "project/src" exists.

+ Pass: Check that directory "project/tests" exists.

+ Pass: Check that directory "project/docs" exists.


#### Compilation Tests

+ Pass: Change into directory "project".

+ Pass: Copy file "Copying official project makefile".



+ Pass: Copy file "Copying official src makefile".



+ Pass: Copy file "Copying official tests makefile".



+ Pass: Check that make compiles.



+ Pass: Check that file "build/bin/transit_sim" exists.

+ Pass: Change into directory "tests".

+ Pass: Check that make compiles.



+ Pass: Check that file "../build/bin/unittest" exists.

+ Pass: Change into directory "..".


#### Style Tests

+ Pass: Change into directory "src/".

+ Pass: Check that file "mainpage.h" exists.

+ Pass: Ignoring mainpage.h



+ Pass: Grading style compliancy errors (Found: 0 errors)

+ Pass: Restoring mainpage.h



+ Pass: Change into directory "..".


#### Doxygen Tests

+ Pass: Change into directory "docs/".


##### .gitignore configured properly

+ Pass: Check that file/directory "html" does not exist.

+ Pass: Check that file/directory "latex" does not exist.

+ Pass: Check that file "Doxyfile" exists.

+ Pass: Generating documentation by running doxygen

+ Pass: Check that directory "html" exists.

+ Pass: Check that file "html/classPassenger.html" exists.

+ Pass: Removing generated html and/or latex directories...



+ Pass: Change into directory "..".

+ Pass: Change into directory "..".

+ Pass: Resetting repo...




### Basic Tests on Master

+ Pass: Checkout master branch.




#### Necessary Files and Structure

+ Pass: Check that directory "project" exists.

+ Pass: Check that directory "project/src" exists.

+ Pass: Check that directory "project/tests" exists.

+ Pass: Check that directory "project/docs" exists.


#### Compilation Tests

+ Pass: Change into directory "project".

+ Pass: Copy file "Copying official project makefile".



+ Pass: Copy file "Copying official src makefile".



+ Pass: Copy file "Copying official tests makefile".



+ Pass: Check that make compiles.



+ Pass: Check that file "build/bin/transit_sim" exists.

+ Pass: Change into directory "tests".

+ Pass: Check that make compiles.



+ Pass: Check that file "../build/bin/unittest" exists.

+ Pass: Change into directory "..".


#### Style Tests

+ Pass: Change into directory "src/".

+ Pass: Check that file "mainpage.h" exists.

+ Pass: Ignoring mainpage.h



+ Pass: Grading style compliancy errors (Found: 0 errors)

+ Pass: Restoring mainpage.h



+ Pass: Change into directory "..".


#### Doxygen Tests

+ Pass: Change into directory "docs/".


##### .gitignore configured properly

+ Pass: Check that file/directory "html" does not exist.

+ Pass: Check that file/directory "latex" does not exist.

+ Pass: Check that file "Doxyfile" exists.

+ Pass: Generating documentation by running doxygen

+ Pass: Check that directory "html" exists.

+ Pass: Check that file "html/classPassenger.html" exists.

+ Pass: Removing generated html and/or latex directories...



+ Pass: Change into directory "..".

+ Pass: Change into directory "..".

+ Pass: Resetting repo...




### Git Usage

+ Pass: Run git ls-remote gather all branches in repo

		d5b8e7a1562d6d309111da754ba2ee134ab31382	refs/heads/03-stop-addpassenger

		824f74e8d36d0c922240979470dec6758fbe9e21	refs/heads/04-route-nextstop

		200531bbc21dda49d0ac549eec320582821a3aed	refs/heads/05-route-enhance

		62193f76ca567c1a166a9bad927f03eddbb4438e	refs/heads/06-bus-enhance

		058279fa54d1a7ccb5f33b80878a606cb7d2b332	refs/heads/07-route-compilation-error

		e31691683f6c8eac54b1c1bc515a2b8bde3eef5d	refs/heads/08-bus-enhance-2

		676daac7c880b7e4a017d03e86944bb5a2258b57	refs/heads/09-negative-distance

		f1f2188e19885613ba32ae2eee3d7d7d8ff54e4b	refs/heads/devel

		319ad850e7043be48c2ee9229c5df839573b7bf2	refs/heads/enchance/02-passenger-class

		8a116639fab7d0d205b2be5844f8ddda9225a7ca	refs/heads/fix/01-compilation-errors

		e50511c955c89d33164dfba5b6ed2c1cfbce1264	refs/heads/iter1deliver2

		f2041af919e85f05d1f98d450614d87a02d7d898	refs/heads/iter1deliver3

		c6408cbe99a1244b5e8cc9ada34de63d2354ab05	refs/heads/master

		511a10f70c10e56852b34849c0961fcfd7b9279e	refs/heads/support-code



