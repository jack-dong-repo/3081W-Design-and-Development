### Feedback for Iter 02

Run on November 14, 13:40:28 PM.


### Basic Tests on Devel

+ Pass: Checkout devel branch



<hr>

This feedback is being batched and will run every few hours. Note that these feedback tests are a *work in progress* and will possibly be updated to contain more tests as they are developed. Check back periodically for more feedback as well as for your updated results.

<hr>


#### Necessary Files and Structure

+ Pass: Check that directory "project" exists.

+ Pass: Check that directory "project/src" exists.

+ Pass: Check that directory "project/tests" exists.

+ Pass: Check that directory "project/docs" exists.

+ Pass: Change into directory "project/src".

+ Fail: Compiling capture_transit_sim target of the src/ makefile...

<pre>make: *** No rule to make target 'capture_transit_sim'.  Stop.
</pre>



+ Skip: Check that file "../build/bin/capture_transit_sim" exists.

  This test was not run because of an earlier failing test.


#### Style Checking All src/ Files

+ Pass: Check that file "mainpage.h" exists.

+ Pass: Ignoring mainpage.h



+ Pass: Grading style compliancy errors Found: 0 errors, Expected 0.

+ Pass: Restoring mainpage.h




### Git Usage

+ Pass: Run git ls-remote gather all branches in repo

		d5b8e7a1562d6d309111da754ba2ee134ab31382	refs/heads/03-stop-addpassenger

		824f74e8d36d0c922240979470dec6758fbe9e21	refs/heads/04-route-nextstop

		200531bbc21dda49d0ac549eec320582821a3aed	refs/heads/05-route-enhance

		62193f76ca567c1a166a9bad927f03eddbb4438e	refs/heads/06-bus-enhance

		058279fa54d1a7ccb5f33b80878a606cb7d2b332	refs/heads/07-route-compilation-error

		e31691683f6c8eac54b1c1bc515a2b8bde3eef5d	refs/heads/08-bus-enhance-2

		676daac7c880b7e4a017d03e86944bb5a2258b57	refs/heads/09-negative-distance

		754c8407b7ad3b083a4dc5a8987fd6d5545a9d13	refs/heads/10-segmentation-fault

		dd071621e54af36755fe0f1bdfa3f14d04f19bee	refs/heads/11-load-onto-bus

		df5497fb4111a2a005460f3b1b00572fa23813d4	refs/heads/11-load-onto-bus-2

		f1f2188e19885613ba32ae2eee3d7d7d8ff54e4b	refs/heads/devel

		319ad850e7043be48c2ee9229c5df839573b7bf2	refs/heads/enchance/02-passenger-class

		8a116639fab7d0d205b2be5844f8ddda9225a7ca	refs/heads/fix/01-compilation-errors

		e50511c955c89d33164dfba5b6ed2c1cfbce1264	refs/heads/iter1deliver2

		f2041af919e85f05d1f98d450614d87a02d7d898	refs/heads/iter1deliver3

		1eb9a4c47ae67fe7519017083c565a72519e989e	refs/heads/lab13

		f806d42f3e2068102e769c56e077e35739821d07	refs/heads/master

		511a10f70c10e56852b34849c0961fcfd7b9279e	refs/heads/support-code



<hr>

Gathered all branches in this repo. Note that passing this test does *not* mean that a sufficient amount of branches were found.

<hr>

