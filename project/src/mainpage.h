/*!
 * @file mainpage.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_

/** \mainpage CSCI3081W - Bus Simulation

### Synopsis: <br>
The goal is to simulate the University of Minnesota Twin Cities bus system. Each stop along the routes, except the last, generates passengers who are waiting for their bus and have a destination stop in mind. When a bus reaches that stop, it first unload any passengers who’d like to offboard then onboards the passengers at the stop. Buses will deploy at the beginning of their routes in increments; and the time in between deployment can be customized. Buses start at the "outgoing" route, then return back into the garage through the "incoming" route. <br>

This page will expand and explain the Passenger, Stop, Route, and Bus classes; and understanding the simulation results. <br>

\image html vis_sim.png Visualization Simulator width=800cm

# Users’ Guide <br> <br>
#### How to download project: <br>
 - Go to project repo here: https://github.umn.edu/umn-csci-3081-f19/repo-dongx462<br>
 - Select "Clone or Download" in green and follow the directions in <br>
https://git-scm.com/book/en/v2/Git-Basics-Getting-a-Git-Repository under "Cloning an Existing Repository"  <br>

#### On Windows:<br>
Open Git Bash and connect using SSH by entering in the following: <br>
"ssh -L [port_number]:localhost:[port_number] [x500]@[cse_labs_computer].cselabs.umn.edu" <br>
where port number is a number greater than 8000 and not a multiple of 10. <br>

#### On Unix: <br>
Open terminal <br>

#### On MacOS:<br>
Open terminal and connect using SSH by entering in "ssh <x500>@<cse_labs_computer>.cselabs.umn.edu" <br>

### Directory: <br>
- Build: contains all the simulation and compilation .o files <br>
- Config: contains a default configuration file for config_sim, and where users add custom files <br>
- Docs: contains Doxyfile, iteration requirements and checklists, UML diagrams, and refactor documentation <br>
- Drivers: main functions <br>
- SRC: CC and header files, of all the classes needed to run simulations <br>
- Tests: unit testing for passenger, bus, route, stop <br>
- Web_Graphics: back-end code for visualization simulator <br>

The makefile within project directory uses the makefile within /project/src/.

## Visualization simulator <br>
### How to operate visualizer simulation:<br>
 - Enter "cd CSCI3081/repo-dongx462/project/src"<br>
 - Enter "make vis_sim"<br></ul>
 - Enter "cd .."<br>
 - Enter "./build/bin/vis_sim [port_number_2]" where this port is also greater than 8000 and not the same port <br>
in initial setup (if on Windows) <br>
 - Open Firefox or Chrome and enter in "localhost:[port_number_2]/web_graphics/project.html" <br>
 - Customize number of steps to run and time steps if desired and select Start to begin <br>
 - Result will look exactly like the first image <br>

If the browser refuses to connect or displays an error message, double-check if the port number matches.
Entering "./build/bin/vis_sim 8009" connects to "localhost:8009/web_graphics/project.html". <br>

### Interpreting the Visualization simulator <br>
Busses will deploy from the leftmost bus stop at time 0. After each time interval, customized in the last step above, another bus will deploy. The number of passengers waiting at each stop and riding on each bus can be observed by moving the cursor over each item. The bus will pick up all people at its stop, and drop them off at their destination. <br>

The user will notice the later stops on the route will have more passengers than the earlier stops. This is because passengers only move forward in the route. <br> <br>

## Configuration simulator <br>
The stops and routes can be customized. To do so, a file containing the data of the stops and routes must be inputted. The following will clarify on the formatting. <br>

### Configuration file format:<br>
The file can be named anything and uses txt file extension. The file content needs to be formatted as below. Anything in square brackets are customizable.<br>

> ROUTE_GENERAL_, [general route] <br>
> STOP Name, Long, Lat, Pass Gen, Prob <br>
> ROUTE, [first route] <br>
> STOP, [stop name, longitude, latitude, probability] <br>
> . <br>
> . <br>
> . <br>
> STOP, [stop name, longitude, latitude, probability] <br>
> ROUTE, [next route] <br>
> STOP, [stop name, longitude, latitude, probability] <br>
> . <br>
> . <br>
> . <br>
> STOP, [stop name, longitude, latitude, probability] <br>

These will turn the stop and route data into code usable by the simulation. <br>

### How to operate configuration simulation: <br>
- Save the file within "/project/config" <br>
- Open the terminal to "/project/src" <br>
- Enter "make" into the terminal <br>
- Enter "cd .." such that current directory is /src/ <br>
- Now there’s multiple options for starting the simulation. Enter any of the following <br>
\code{makefile}
          ./build/bin/config_sim
          ./build/bin/config_sim <new_config_file.txt>
          ./build/bin/config_sim <new_config_file.txt> <num_time_steps>
          ./build/bin/config_sim <new_config_file.txt> <num_time_steps> <time_steps_between_busses>
\endcode

In the case if the data in brackets are not entered, cannot be opened, or numbers do not work, the program will prompt the end user for the data again. If the file cannot be opened, it will ask if the default file will work. End user will need to restart the program to enter in their preferred file. <br>

Examples of incorrect inputs that are handled: <br>
\code{makefile}
          ./build/bin/config_sim config.txtt -123 -4
          ./build/bin/config_sim config.txt 0 0
          ./build/bin/config_sim file_does_not_exist.txt 123 20
\endcode

Note when the program asks for confirmation, the only acceptable answers are “y” and “n” without quotes. It will not accept “yes” or “no” despite conveying congruent meanings. <br>

\image html config_yesno.png Examples of wrong inputs width=300cm

The program will only accept non-negative, non-zero integers. Anything else will not work. <br>

\image html config_time_ints.png Handling negatives and zeros for time width=300cm

## Developers' Guide: <br>
The developers' guide goes into detail of each class and simulator. For details about how to operate the simulations, please read through the Users' Guide. <br>

The simulation uses linux environment. Download the program from the following: https://github.umn.edu/umn-csci-3081-f19/repo-dongx462<br>

### Visualization simulator: <br>
- Run make from within src <br>
- Cd into project directory and run ./build/bin/vis_sim [port_number] <br>
- Run localhost:[port_number]/web_graphics/project.html <br>

### Configuration simulator: <br>
- For formatting, review the file requirements in Users' Guide <br>
- The new configuration file must be in /project/config/ <br>
- Run make from within src <br>
- Cd into the project directory and run ./build/bin/config_sim [...] <br>

The following are the classes that make up the simulations' foundations. Continue for each classes' details. <br>
\image html uml_final.png Final UML diagram width=800cm

### Passenger Class <br>
- Constructor parameters: int destination_stop_id, std::string name <br>

\image html passenger_uml.png Passenger attributes width=200cm

If the passenger is at the stop, Update() will increment the wait_at_stop_ variable; and if they’re on the bus, then time_on_bus_ will be incremented.It tracks the passenger’s status by seeing if their time on the bus greater than one, and GetOnBus() will initialize it to one.<br>

### Stop Class <br>
- Constructor parameters: int id, double longitude, double latitude <br>
\image html stop_uml.png Stop attributes width=200cm

If no coordinates are entered, constructor defaults to the Westbound Coffman Union stop location (longitude 44.973723, latitude -93.235365). <br> <br>
When a bus arrives, stop calls AddPassenger(Bus *) - it takes in a bus object, then iterates through the stop’s passenger_ list, and calls bus->LoadPassenger(Passenger*) on each until LoadPassengers return false. If successful, pop the passenger from the stop’s list and increment num_loaded_to_bus. Return the number of people successfully boarded upon completion. <br>

Stop has a data struct that contains the stop’s ID number as a string, Position data struct that contains longitude and latitude, and number of people waiting at the bus stop. There are getters and setters for coordinates (returns Position struct), passenger count (returns integer length of passenger_ list), and ID (integer number).  The Update method will iterate through the passengers list and call passenger->update on each person.<br>

### Route Class <br>
- Constructor parameters: std::string name, Stop ** stops, double * distances, int num_stops, PassengerGenerator * pass_gen <br>
\image html route_uml.png Route attributes width=200cm

The constructor iterates through the stops and distance pointer arrays, and push_back each element into std::list<Stop *> and std::list<double> arrays respectively. It passes in Passenger Generator and it calls GeneratePassengers(), which begins the creation of people within each stop. Destination_stop_ is initialized to the first stop within the stop list and destination_stop_index_ to zero. <br>

Clone() returns a duplicate object - with the same name, pointer array of stop pointers, distances, number of stops, and instance of passenger generator. It’s used in the simulator classes that will be discussed later. <br>

The Update method iterates through the list of stops and calls Stop->Update() on each. It will update each person’s time at the stop in all the stops along the route. <br>

After the iteration, It calls UpdateRouteData() which is a struct that contains the metrics used in the visual simulator. It turns and returns all the stops within the list into a vector of stop data, and the route name. <br>

Route has a private variable that tracks the current destination stop. This is updated through NextStop() where an iterators loops through the stops list until it reaches the current destination stop, then increments by one. Then increment the destination stop index by one as well. <br>

The same concept is used in GetNextStopDistance(), which uses std::advance (iterator, destination_stop_index_). <br>

IsAtEnd() returns true if the destination stop equals the last stop in the list, false otherwise, which is used in the bus class to determine if the route’s completion status. <br>

The following methods aid in updating and returning route data. GetPrevCoordinates uses two iterators (one trailing the other) - if the first iterator equals the current destination, return the second iterator; else, set the second iterator to the first one. If the route points to the first stop of the list, return the first stop. <br>

GetLastStopPosition() returns the last stop of the route’s Position coordinates - it is a helper method for a functionality within the bus class. <br>

### Bus Class <br>
- Constructor parameters: std::string name, Route * in, Route * out, int capacity, double speed <br>
\image html bus_uml.png Bus attributes width=200cm

Current_route_ points to outgoing route first then incoming. Distance_remaining_ is used to track distance until the next stop. <br>

LoadPassenger(Passenger *) push_backs the new passenger, calls passenger->GetOnBus(), and returns true  if max capacity isn’t reached; else return false. <br>

UnloadPassengers(Stop*) iterates through the bus’s passenger list and calls stop->AddPassenger(Passenger*) on that person if the current destination ID matches the person’s destination ID. It erases the person from the bus’s list and reset the iterator from the beginning to avoid null pointers. <br>

Move() subtracts the distance remaining to next stop by the speed of the bus, then returns true if distance remaining is epsilon (it arbitrarily uses 0.00005) or less and false otherwise. It uses epsilon to catch minisual non-negative, non-zero decimals due to floating point values.

<br> Update is the primary method where all the data gets updated. It first calls Move() such that the bus progresses, then checks if the bus is currently at a stop or still in transit. If it is a stop and the trip isn’t complete, it <br>

- updates the bus data struct <br>
- unloads passengers at the current destination stop <br>
- loads passengers from the stop onto the bus <br>
- updates the destination stop to the next stop <br>
- updates the distance remaining to reflect the new destination stop <br>

If the bus is currently at the end of the outgoing route and it’s at a stop, it changes the route from outgoing to incoming then reset the distance remaining variable to zero. Update the bus data struct to reflect any recent changes. <br>

IsTripComplete only returns true if the bus is at the end of its current route, if the current route is equal to incoming route, and if distance remaining is less than epsilon, else otherwise. <br>

Other helper methods include returning the current route’s destination stop’s ID which returns an integer, current route’s destination stop which returns a stop pointer, the current occupancy of the bus as size_t, and the max capacity as an integer. <br>

Bus data struct contains the name of the id as a string, position coordinates as a Position struct, num_passengers as size_t, and capacity as an integer. <br>

Since the bus is always in transit or at a stop, the latitude and longitude coordinates will always be changing. If the bus is at a stop GetUpdateCoordinates returns the current stops position coordinates, and if it’s in transit it will return the midpoint between the current and previous stops’ geocoordinates. <br>

### Passenger Generation Classes <br>
PassengerFactory has three static const char arrays which a random number generator will combine one element from each array into a passenger name. <br>
\image html passengerfactory_uml.png Passenger Factory attributes width=200cm

PassengerGenerator is an abstract class that takes in a list of probabilities of type double and a list of stop pointers. Index i of probabilities indicate stop i has a probability[i] of generating passengers at that stop. The method GeneratePassengers is virtual and gets implemented in the derived class <br>

 \image html passengergen.png Passenger Generator attributes width=200cm

RandomPassengerGenerator. In this method, for each stop, if a random number generator falls within the stop’s passenger generating probability, create a new passenger using passenger factory and call Stop->AddPassenger(Passenger *), then finally return the total number of passengers generated. <br>

\image html rpassengergen_uml.png Random Passenger Generator attributes and inheritance width=200cm

### Visualization simulator <br>
The visualizer uses the data structs within the data.structs.h file. The structs are implemented in their respective classes (eg. route class contains the route data struct class). They contain the information displayed in the visualizer: stops need the longitude, latitude, and number of people waiting; busses need the longitude, latitude, number of people riding the bus, and max capacity; route contains the list of stops. <br>

\image html structs_uml.png Data structs attributes width=500cm

Backend programs, copyright credits to the fall 2019 3081W staff, are within /classes/grades/Fall-2019/csci3081/project. <br>

### Configuration simulator <br>
The driver simulator is configuration_sim.cc within project/drivers - it utilizes two helper classes configuration_simulator.cc and config_manager.cc within project/src. <br>

Config Manager reads in route name, stop list, distance list, and probability data from the config text file in project/config; then creates route classes out of them to be placed within a route vector. It will not create duplicate stops in the same route. <br>

Configuration simulator starts and updates the simulation. The start method initializes the time since the last bus array and simulation time to zero; then reports and updates all the routes. <br>

The update method increments the simulation time first Then check if new busses need to be generated given the new simulation time - if so create a new bus object using incoming and outgoing routes and push_back into list of busses. Next iterate through the current list of buses and call update on each. If the busses’ trips are complete, erase them. Finally call update and report on all the routes as well. <br>

Configuration Sim is where the main method is. It must account for if the end-user enters any permutation of custom config text file, total simulation length, and time between each bus. If the file cannot be open the file, it asks if the default config file will suffice. <br>

If the simulation length arguments and bus deploy times are invalid, prompt the user again for positive integer arguments until arguments work. Next, it creates instances of config manager and configuration simulator to read in user-entered config file. Push_back the time between buses into a vector*, and store the total simulation time as an integer. Enter in those data as arguments for the configuration_simulator start() method. Call update the simulation length number of times. <br>

(*The data type is a vector because different busses may have different deploy intervals.)

### Regression Testing <br>
There is r_local_simulator and r_local_simulator2 cc and header files within /src/ for testing simulation functionality. To generate the same named passengers, go into src/passenger_factory.cc and uncomment the line with "CONSTPASS". Then make regression[2]_test within src. <br>

With how the makefile works, the name of the regression executable must match the first part of the driver's name. For example, drivers/regression2_driver.cc only compiles with "make regression2_test". It must end in "_test". <br>

### Makefile <br>
The makefile within /src/ will compile configuration sim and visualization sim by default (entering "make" into the terminal). The results are within /project/build/ directory. It makes it very convenient so there's no manual linking or compiling. If other simulations or compilations are desired, enter "make [name_test]", "make [name_driver]", and/or "make [name_sim]". <br>

There is a makefile within the project directory that uses the /src/ makefile. <br>

To add compilations and simulations to the /src/ makefile, add the following: <br>

\code{makefile}
$(DRIVEROBJDIR)/[name.o]:
    $(DRIVERDIR)/[name.cc] | $(DRIVEROBJDIR)
    @echo "==== Auto-Generating Dependencies for $<. ===="
    $(call make-depend-cxx,$<,$@,$(subst .o,.d,$@))
    @echo "==== Compiling $< into $@. ===="
    $(CXX) $(OMP) $(CXXFLAGS) $(CXXLIBDIRS) -c -fPIC -o  $@ $<
\endcode

and <br>
\code{makefile}
[name_sim]:
      $(addprefix $(OBJDIR)/, $(OBJFILES)) $(DRIVEROBJDIR)/[name_sim.o] | $(BINDIR)
      @echo "==== Linking $@. ===="
      @$(CXX) $(OMP) $(LDFLAGS) $(addprefix $(OBJDIR)/, $(OBJFILES)) $(DRIVEROBJDIR)/[name_sim.o] -o $(BINDIR)/$@ $(LDLIBS)
\endcode

where name.o, name.cc, name_sim.o are the new simulator files.
 */

#endif  // SRC_MAINPAGE_H_
