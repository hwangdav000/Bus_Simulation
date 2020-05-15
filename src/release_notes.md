refactoring for Iteration 2

refactoring done is for configuration sim
- compiling with no arg was giving seg faults
- fixed when merging devel to master in drivers/configuration_sim.cc

refactoring for Iteration 3

regression testing is merged into master
- new regression src files are
src/new_local_simulator.cc
src/new_local_simulator.h
- new regression driver file is
drivers/my_regression_driver.cc
- includes all files from lab 15

To Compile Regression Tests
1. Commented out CONSTPASS in passenger_factory.cc
in my final delivery. To get regression testing to
work then need to uncomment CONSTPASS this will make
all passengers the same.
2. Run make all, or run make my_regression_test in src folder
3. In project run './build/bin/my_regression_test > rtout1'
4. In project run './build/bin/my_regression_test > rtout2'
5. In project cd to /build/bin/ and run 'diff rtout1 rtout2' to see
if there are any differences in regression test.

refactor/iter3 branch
 - NOT merged into master
 - refactored so last stop has prob of 0
 passenger generation in config_manager in src
 - refactoring 2
iii EXTRACT METHOD used
extracted method from update in Bus.cc
created method to check if bus is at stop and if so
call process -> this method unloads and loads passengers at stop
- SetNext(Route * set_route_, int option_)

ASSUMPTION
- RUN config_sim from project folder so ex:
./build/bin/config_sim <args>
- Also RUN vis_sim from project folder
