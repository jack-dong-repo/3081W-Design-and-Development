### Feedback for Lab 10

Run on October 19, 08:57:17 AM.


### Necessary Files and Structure

+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab10_advanced_git" exists.


### Git Usage

+ Pass: Run git ls-remote to check for existence of specific branch- Branch devel found

+ Pass: Checkout devel branch.



+ Pass: Run git ls-remote gather all branches in repo

		55c9dc26e66d0e025ae828f5039f86e7130805cd	refs/heads/devel

		319ad850e7043be48c2ee9229c5df839573b7bf2	refs/heads/enchance/02-passenger-class

		8a116639fab7d0d205b2be5844f8ddda9225a7ca	refs/heads/fix/01-compilation-errors

		0080555b0dfe11c852d80a0fdb636a19afd5bcaf	refs/heads/master

		5f23c9619cf5c5f2f7379b5a44bc60016303ece6	refs/heads/support-code



+ Pass: Checking for the correct number of branches

Sufficient branches found (found=2, required=2):

enchance/02-passenger-class

fix/01-compilation-errors


#### Counting commits on devel

+ Pass: Checkout devel branch.



+ Pass: Gather commit history

		[Jack Dong] 2019-10-18 (HEAD -> devel, origin/devel) lab10 compilation: added Stop::Update() to make makefile compile 

		[Jack Dong] 2019-10-17 lab10(enhance): added descriptions for header files for UML 

		[Jack Dong] 2019-10-17 adding to devel 

		[Jack Dong] 2019-10-17 Merge branch 'support-code' of github.umn.edu:umn-csci-3081-F19/csci3081-shared-upstream into devel 



		[Jack Dong] 2019-10-13 enhance(passenger.cc): 02-passenger-enchancement - added more functionality to passenger
- copied class from lab09


		[Jack Dong] 2019-10-13 (origin/enchance/02-passenger-class, enchance/02-passenger-class) Merge branch 'fix/01-compilation-errors' into devel 

		[Jack Dong] 2019-10-13 (origin/fix/01-compilation-errors, fix/01-compilation-errors) fix(local_simulator.cc): fix #1 compilation error - errors suggesting two lines use -> instead of .
- changed pass_.Update(); to pass_->Update();
- changed pass_.Report(); to pass_->Report();


		[Jack Dong] 2019-10-13 lab9 

		[Jack Dong] 2019-10-13 Merge branch 'master' of https://github.umn.edu/umn-csci-3081-f19/repo-dongx462 

		[Jack Dong] 2019-10-13 Merge branch 'support-code' of github.umn.edu:umn-csci-3081-F19/csci3081-shared-upstream into support-code 


		[Jack Dong] 2019-10-13  lab9 

		[Jack Dong] 2019-10-13 Merge branch 'support-code' of github.umn.edu:umn-csci-3081-F19/csci3081-shared-upstream 

		[Jack Dong] 2019-10-13 lab9 





		[Jack Dong] 2019-10-11 Merge branch 'master' of https://github.umn.edu/umn-csci-3081-f19/repo-dongx462 

		[Jack Dong] 2019-10-11 lab8: add passenger_factory.cc 


















+ Pass: Check git commit history
Sufficient commits (found=20,required=4)


### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 0)

+ Pass: Run ghi for total number of closed issues in Github repo (Found: 3)

[CLOSED issue #12] :  lab10 compilation: added Stop::Update() to make makefile compile ↑

[CLOSED issue #10] :  02-passenger-enchancement [enhancement] 1 @dongx462

[CLOSED issue #9] :  01-compilation-errors [bug] 1 @dongx462





+ Pass: Run ghi for total number of issues in Github repo (Found: 3, Expected: 2) 

 [OPEN issue #] : 

[CLOSED issue #12] :  lab10 compilation: added Stop::Update() to make makefile compile ↑

[CLOSED issue #10] :  02-passenger-enchancement [enhancement] 1 @dongx462

[CLOSED issue #9] :  01-compilation-errors [bug] 1 @dongx462

 




### Test that code on  devel compiles

+ Pass: Checkout devel branch.



+ Pass: Check that directory "project" exists.

+ Pass: Change into directory "project".

+ Pass: Check that file "makefile" exists.

+ Fail: Check that make compiles.

    Make compile fails with errors:.
<pre>cd src; make -j
make[1]: Entering directory '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/src'
==== Auto-Generating Dependencies for local_simulator.cc. ====
==== Auto-Generating Dependencies for passenger_factory.cc. ====
==== Auto-Generating Dependencies for random_passenger_generator.cc. ====
==== Auto-Generating Dependencies for bus.cc. ====
g++ -MM -MF /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/local_simulator.d -MP -MT /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/local_simulator.o -W -Wall -Wextra -fdiagnostics-color=always -Wfloat-equal -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -Wno-old-style-cast -Wno-cast-align -g -std=c++11 -c -I.. -I. -I./.. -I../drivers local_simulator.cc
g++ -MM -MF /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/passenger_factory.d -MP -MT /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/passenger_factory.o -W -Wall -Wextra -fdiagnostics-color=always -Wfloat-equal -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -Wno-old-style-cast -Wno-cast-align -g -std=c++11 -c -I.. -I. -I./.. -I../drivers passenger_factory.cc
g++ -MM -MF /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/bus.d -MP -MT /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/bus.o -W -Wall -Wextra -fdiagnostics-color=always -Wfloat-equal -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -Wno-old-style-cast -Wno-cast-align -g -std=c++11 -c -I.. -I. -I./.. -I../drivers bus.cc
==== Auto-Generating Dependencies for passenger.cc. ====
g++ -MM -MF /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/random_passenger_generator.d -MP -MT /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/random_passenger_generator.o -W -Wall -Wextra -fdiagnostics-color=always -Wfloat-equal -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -Wno-old-style-cast -Wno-cast-align -g -std=c++11 -c -I.. -I. -I./.. -I../drivers random_passenger_generator.cc
==== Auto-Generating Dependencies for passenger_generator.cc. ====
g++ -MM -MF /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/passenger.d -MP -MT /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/passenger.o -W -Wall -Wextra -fdiagnostics-color=always -Wfloat-equal -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -Wno-old-style-cast -Wno-cast-align -g -std=c++11 -c -I.. -I. -I./.. -I../drivers passenger.cc
g++ -MM -MF /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/passenger_generator.d -MP -MT /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/passenger_generator.o -W -Wall -Wextra -fdiagnostics-color=always -Wfloat-equal -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -Wno-old-style-cast -Wno-cast-align -g -std=c++11 -c -I.. -I. -I./.. -I../drivers passenger_generator.cc
==== Auto-Generating Dependencies for route.cc. ====
==== Auto-Generating Dependencies for stop.cc. ====
g++ -MM -MF /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/route.d -MP -MT /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/route.o -W -Wall -Wextra -fdiagnostics-color=always -Wfloat-equal -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -Wno-old-style-cast -Wno-cast-align -g -std=c++11 -c -I.. -I. -I./.. -I../drivers route.cc
g++ -MM -MF /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/stop.d -MP -MT /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/stop.o -W -Wall -Wextra -fdiagnostics-color=always -Wfloat-equal -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -Wno-old-style-cast -Wno-cast-align -g -std=c++11 -c -I.. -I. -I./.. -I../drivers stop.cc
==== Auto-Generating Dependencies for ../drivers/transit_sim.cc. ====
g++ -MM -MF /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/objdrivers/transit_sim.d -MP -MT /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/objdrivers/transit_sim.o -W -Wall -Wextra -fdiagnostics-color=always -Wfloat-equal -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -Wno-old-style-cast -Wno-cast-align -g -std=c++11 -c -I.. -I. -I./.. -I../drivers ../drivers/transit_sim.cc
==== Compiling passenger_factory.cc into /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/passenger_factory.o. ====
g++ -fopenmp -W -Wall -Wextra -fdiagnostics-color=always -Wfloat-equal -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -Wno-old-style-cast -Wno-cast-align -g -std=c++11 -c -I.. -I. -I./.. -I../drivers  -c -fPIC -o  /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/passenger_factory.o passenger_factory.cc
==== Compiling passenger.cc into /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/passenger.o. ====
g++ -fopenmp -W -Wall -Wextra -fdiagnostics-color=always -Wfloat-equal -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -Wno-old-style-cast -Wno-cast-align -g -std=c++11 -c -I.. -I. -I./.. -I../drivers  -c -fPIC -o  /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/passenger.o passenger.cc
==== Compiling passenger_generator.cc into /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/passenger_generator.o. ====
g++ -fopenmp -W -Wall -Wextra -fdiagnostics-color=always -Wfloat-equal -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -Wno-old-style-cast -Wno-cast-align -g -std=c++11 -c -I.. -I. -I./.. -I../drivers  -c -fPIC -o  /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/passenger_generator.o passenger_generator.cc
==== Compiling route.cc into /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/route.o. ====
g++ -fopenmp -W -Wall -Wextra -fdiagnostics-color=always -Wfloat-equal -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -Wno-old-style-cast -Wno-cast-align -g -std=c++11 -c -I.. -I. -I./.. -I../drivers  -c -fPIC -o  /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/route.o route.cc
==== Compiling random_passenger_generator.cc into /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/random_passenger_generator.o. ====
g++ -fopenmp -W -Wall -Wextra -fdiagnostics-color=always -Wfloat-equal -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -Wno-old-style-cast -Wno-cast-align -g -std=c++11 -c -I.. -I. -I./.. -I../drivers  -c -fPIC -o  /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/random_passenger_generator.o random_passenger_generator.cc
==== Compiling bus.cc into /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/bus.o. ====
g++ -fopenmp -W -Wall -Wextra -fdiagnostics-color=always -Wfloat-equal -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -Wno-old-style-cast -Wno-cast-align -g -std=c++11 -c -I.. -I. -I./.. -I../drivers  -c -fPIC -o  /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/bus.o bus.cc
==== Compiling stop.cc into /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/stop.o. ====
g++ -fopenmp -W -Wall -Wextra -fdiagnostics-color=always -Wfloat-equal -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -Wno-old-style-cast -Wno-cast-align -g -std=c++11 -c -I.. -I. -I./.. -I../drivers  -c -fPIC -o  /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/stop.o stop.cc
==== Compiling local_simulator.cc into /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/local_simulator.o. ====
g++ -fopenmp -W -Wall -Wextra -fdiagnostics-color=always -Wfloat-equal -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -Wno-old-style-cast -Wno-cast-align -g -std=c++11 -c -I.. -I. -I./.. -I../drivers  -c -fPIC -o  /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/local_simulator.o local_simulator.cc
==== Compiling ../drivers/transit_sim.cc into /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/objdrivers/transit_sim.o. ====
g++ -fopenmp -W -Wall -Wextra -fdiagnostics-color=always -Wfloat-equal -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -Wno-old-style-cast -Wno-cast-align -g -std=c++11 -c -I.. -I. -I./.. -I../drivers  -c -fPIC -o  /project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/objdrivers/transit_sim.o ../drivers/transit_sim.cc
In file included from ../src/route.h:14:0,
                 from ../src/bus.h:14,
                 from bus.cc:7:
../src/./stop.h:19:23: error: Bus has not been declared
   void LoadPassengers(Bus *);
                       ^~~
route.cc: In member function void Route::Update():
route.cc:23:12: error: class Stop has no member named Update
     (*it)->Update();
            ^~~~~~
bus.cc: In member function bool Bus::LoadPassenger(Passenger*):
bus.cc:21:37: warning: unused parameter new_passenger [-Wunused-parameter]
 bool Bus::LoadPassenger(Passenger * new_passenger) {
                                     ^~~~~~~~~~~~~
makefile:86: recipe for target '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/route.o' failed
make[1]: *** [/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/route.o] Error 1
make[1]: *** Waiting for unfinished jobs....
makefile:86: recipe for target '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/bus.o' failed
make[1]: *** [/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/bus.o] Error 1
stop.cc: In member function void Stop::LoadPassengers(Bus*):
stop.cc:23:15: warning: declaration of i shadows a previous local [-Wshadow]
     for (auto i = passengers_.begin(); i != passengers_.end(); ++i) {
               ^
stop.cc:22:37: note: shadowed declaration is here
     std::list<Passenger*>::iterator i;
                                     ^
stop.cc: In member function void Stop::AddPassengers(Passenger*):
stop.cc:29:38: warning: unused parameter pass [-Wunused-parameter]
 void Stop::AddPassengers(Passenger * pass) {
                                      ^~~~
In file included from ../src/route.h:14:0,
                 from ../src/bus.h:14,
                 from ../src/simulator.h:12,
                 from ../src/local_simulator.h:11,
                 from local_simulator.cc:10:
../src/./stop.h:19:23: error: Bus has not been declared
   void LoadPassengers(Bus *);
                       ^~~
makefile:86: recipe for target '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/local_simulator.o' failed
make[1]: *** [/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/obj/transit_sim/local_simulator.o] Error 1
In file included from ../src/route.h:14:0,
                 from ./bus.h:14,
                 from ./simulator.h:12,
                 from ./local_simulator.h:11,
                 from ../drivers/transit_sim.cc:5:
../src/./stop.h:19:23: error: Bus has not been declared
   void LoadPassengers(Bus *);
                       ^~~
makefile:100: recipe for target '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/objdrivers/transit_sim.o' failed
make[1]: *** [/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/build/objdrivers/transit_sim.o] Error 1
make[1]: Leaving directory '/project/grades/Fall-2019/csci3081/kyllo089/grading-environment/grading-scripts/grading/Lab_10_Feedback/repo-dongx462/project/src'
makefile:10: recipe for target 'TransitSim' failed
make: *** [TransitSim] Error 2
</pre>



