### CSci-3081W Project Support Code Makefile ###

# File History: This combines Prof. Keefe's Makefiles from past years
# with TA John Harwell's 3081W Makefiles from Fall 2016, which introduced
# auto-dependency generation and several other exciting features.


### Section 0: Change this when compiling on non-CSELabs machines ###

PROJECT_NAME = config_sim
PROJECT_NAME2 = my_regression_test
# Path to root of repo
REPOROOTDIR = $(shell git rev-parse --show-toplevel)

# Path to web and library code
# driver file for visualization_simulator is ‘main.cpp’ in the web directory of
# the project directory of the path assigned to CS3081DIR above --> Take a look
# the files in this project directory are necessary to build the visualizer sim.
CS3081DIR = /classes/grades/Fall-2019/csci3081/project


### Section I: Definitions ###

# Root of the source tree for the project (e.g., could be just . or ./src)
SRCDIR = .
DRIVERDIR = ../drivers

# Output directories for the build process
PROJ_DIR = $(REPOROOTDIR)/project
BUILDDIR = $(PROJ_DIR)/build
WEBDIR = $(CS3081DIR)/web
BINDIR = $(BUILDDIR)/bin
OBJDIR = $(BUILDDIR)/obj/$(PROJECT_NAME)
# Below you need to assign WEBOBJDIR to store the object files for
# building the visulizer and configuation panel.
# the value of WEBOBJDIR will be similar to OBJDIR above (but not the same).
# it will use the BUILDIR directory as the root and store object files for the
# web objects in a new object directory (webobj, for example) which should contain a
# directory with the same name as the target
DRIVEROBJDIR = $(BUILDDIR)/objdrivers
WEBOBJDIR = $(BUILDDIR)/webobj/visualizer_sim
# Below are the libraries and library directories necessary to create
# the visual simulation executable, the C++ linker needs these
VISLIBS = -lCppWebServer -lwebsockets -lcrypto -lssl -lz
LIBDIR = -L$(CS3081DIR)/external/lib

EXTERNAL_DIR = $(PROJ_DIR)/src/external
#MINGFX_DIR = $(EXTERNAL_DIR)/MinGfx/build/install  #not using in F19

# The name of the executable to create
EXEFILE = $(BINDIR)/$(PROJECT_NAME)
EXEFILE2 = $(BINDIR)/$(PROJECT_NAME2)

# The list of files to compile for this project.  Defaults to all
# of the .cpp and .cc files in the source directory.  (We use both .cpp
# and .cc in order to support two different popular naming conventions.)
SRCFILES = $(wildcard $(SRCDIR)/*.cc) $(wildcard $(SRCDIR)/*.cpp)
# Below, you need to add a variable named WEBSRCFILES which will be similar to
# the SRCFILES but point to the directory that contains the source code files
# (.cc, and .ccp files) for the web server. Take a look at the CS3081DIR listed above
# and find where the *.cc files are.
WEBSRCFILES = $(wildcard $(CS3081DIR)/web/*.cpp) $(wildcard $(CS3081DIR)/web/*.cc)
# For each of the source files found above, replace .cpp (or .cc) with
# .o in order to generate the list of .o files make should create.
OBJFILES = $(notdir $(patsubst %.cc,%.o,$(patsubst %.cpp,%.o,$(SRCFILES))))
# Below, you need to add a variable named WEBOBJFILES which will be similar to
# the OBJFILES but use the web source files (WEBSRCFILES)
WEBOBJFILES = $(notdir $(patsubst %.cc,%.o,$(patsubst %.cpp,%.o,$(WEBSRCFILES))))
# Add -Idirname to add directories to the compiler search path for finding .h files
INCLUDEDIRS = -I.. -I$(SRCDIR) -I$(SRCDIR)/.. -I$(DRIVERDIR) -I$(CS3081DIR)/web -isystem$(CS3081DIR)/external/include -isystem$(CS3081DIR)/external/include/cppwebserver -isystem$(CS3081DIR)/external/include/gtest -isystem$(CS3081DIR)/external/include/websockets

# Above, you'll need to add the include directives specified in the README.md
# file that specify the directories which hold the source code and other files
# necessary to create the executable file for visual simulation below.
# You might want to add them to the same line, or be sure to use the make
# line continuation character if you add them one line at a time.

# The command to run for the C++ compiler and linker
CXX = /soft/gcc/7.1.0/Linux_x86_64/bin/g++
OMP = -fopenmp

# Arguments to pass to the C++ compiler.
# -c is required, it tells the compiler to output a .o file
#CXXFLAGS = -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wfloat-equal -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -Wno-old-style-cast -Wno-cast-align -g -std=c++11 -c $(INCLUDEDIRS)

CXXFLAGS = -W -Wall -Wextra -fdiagnostics-color=always -Wfloat-equal -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -Wno-old-style-cast -Wno-cast-align -g -std=c++11 -c $(INCLUDEDIRS)

-include ../../Makefile.local

# Below you set the LDFLAGS variable to arguments to pass to the C++ linker
# for the visualizer sim such as -L<pathname>, but not -l<name>
# locate the variable assigned those items defined earlier an assign it accordingly

LDFLAGS = $(LIBDIR)
# Below you need to set the LDLIBS variable to library names to pass to the C++ linker
# for the visualizer sim such as -l<name>.
# Locate the variable assigned those items defined earlier and assign it accordingly

LDLIBS = $(VISLIBS)
# This is a list of "phony targets" -- targets that do not specify the name of a file.
# Rather they specify the name of a recipe to run whenever make is envoked with the target name.
# Below, for the visual sim, you'll need to add the variable you created above
# that holds the path to the web server's object files
.PHONY: clean all $(BINDIR) $(OBJDIR) $(WEBOBJDIR)


# The default target which will be run if the user just types "make"
# Below, you'll need change the line to the make the "target" for the
# visual simulation

all: config_sim vis_sim my_regression_test
config_sim: $(EXEFILE)
my_regression_test: $(EXEFILE2)

#vis_sim: $(EXEFILE2)
# This rule says that each .o file in $(OBJDIR)/ depends on the
# presence of the $(OBJDIR)/ directory.
$(addprefix $(OBJDIR)/, $(OBJFILES)): | $(OBJDIR)

# Below, you'll need to add a version of the rule above that uses the WEBOBJDIR,and
# WEBOBJFILES you defined earlier to build the visual simulation

$(addprefix $(WEBOBJDIR)/, $(WEBOBJFILES)): | $(WEBOBJDIR)

# And, this rule provides a recipe for creating that objdir.  The same rule applies
# to the bindir, where the exe will be output.
# Below, you will need to add the reference to the variable that holds the path to
# the object directories for the visual simulation that you defined earlier
$(OBJDIR) $(BINDIR) $(DRIVEROBJDIR) $(WEBOBJDIR):
	@mkdir -p $@

$(WEBOBJDIR) $(OBJDIR) $(BINDIR) $(DRIVEROBJDIR):
	@mkdir -p $@

# COMPILING (USING A PATTERN RULE):
# Since every .cpp (or .cc) file must be compiled into a .o, we will write this
# recipe using a pattern rule.  Using this recipe, any file that matches the pattern
# $(SRCDIR)/filename.cpp can be turned into $(OBJDIR)/filename.o.

# The same thing will also work for files with a .cc extension
$(OBJDIR)/%.o: $(SRCDIR)/%.cc
	@echo "==== Auto-Generating Dependencies for $<. ===="
	$(call make-depend-cxx,$<,$@,$(subst .o,.d,$@))
	@echo "==== Compiling $< into $@. ===="
	$(CXX) $(OMP) $(CXXFLAGS) $(CXXLIBDIRS) -c -fPIC -o  $@ $<

# Below, you'll need to add a 2 (TWO) rules to compile the web visualizer and
# configuration panel for the visual simulation similar to the rule above.
# It will use the variable with the location of
# (that is, path to) the object files for the visual simulation that you defined
# earlier for the target
# and the path to the source code files for the visual simulation,
# specifically:
#                 $(CS3081DIR)/web
# in the dependencies.
# One rule will make C++ objects from  .cpp source files
# The other rule will make objects from .cc source files

# The other rule will make objects from .cc source files
$(WEBOBJDIR)/%.o: $(CS3081DIR)/web/%.cpp
	@echo "==== Auto-Generating Dependencies for $<. ===="
	$(call make-depend-cxx,$<,$@,$(subst .o,.d,$@))
	@echo "==== Compiling $< into $@. ===="
	$(CXX) $(OMP) $(CXXFLAGS) $(CXXLIBDIRS) -c -fPIC -o  $@ $<

# One rule will make C++ objects from  .cpp source files
$(WEBOBJDIR)/%.o: $(CS3081DIR)/web/%.cc
	@echo "==== Auto-Generating Dependencies for $<. ===="
	$(call make-depend-cxx,$<,$@,$(subst .o,.d,$@))
	@echo "==== Compiling $< into $@. ===="
	$(CXX) $(OMP) $(CXXFLAGS) $(CXXLIBDIRS) -c -fPIC -o  $@ $<

# The same thing will also work for files with a .cc extension
#$(DRIVEROBJDIR)/%_driver.o: $(DRIVERDIR)/%_driver.cc | $(DRIVEROBJDIR)
#	@echo "==== Auto-Generating Dependencies for $<. ===="
#	$(call make-depend-cxx,$<,$@,$(subst .o,.d,$@))
#	@echo "==== Compiling $< into $@. ===="
#	$(CXX) $(OMP) $(CXXFLAGS) $(CXXLIBDIRS) -c -fPIC -o  $@ $<

#NEED TO ADD EXECUTABLE RULE FOR BUILDING TransitSim.obj
$(DRIVEROBJDIR)/$(PROJECT_NAME).o: $(DRIVERDIR)/configuration_sim.cc | $(DRIVEROBJDIR)
	@echo "==== Auto-Generating Dependencies for $<. ===="
	$(call make-depend-cxx,$<,$@,$(subst .o,.d,$@))
	@echo "==== Compiling $< into $@. ===="
	$(CXX) $(OMP) $(CXXFLAGS) $(CXXLIBDIRS) -c -fPIC -o  $@ $<

$(DRIVEROBJDIR)/$(PROJECT_NAME2).o: $(DRIVERDIR)/my_regression_driver.cc | $(DRIVEROBJDIR)
	@echo "==== Auto-Generating Dependencies for $<. ===="
	$(call make-depend-cxx,$<,$@,$(subst .o,.d,$@))
	@echo "==== Compiling $< into $@. ===="
	$(CXX) $(OMP) $(CXXFLAGS) $(CXXLIBDIRS) -c -fPIC -o  $@ $<

# WITH AUTO-GENERATED DEPENDENCIES:
# Note that there are actually two steps to the compiling recipe above.  The second
# step should be familiar, it just calls g++ to compile the .cpp into a .o.  But,
# the first step is an advanced topic.  It calls the custom function make-depend-cxx()
# defined below, which calls the g++ compiler with special flags (the -M* parts)
# that tell g++ to output a make-compatable list of all of the .h files included
# by the specified C++ source file.  All of these .h files should be listed as
# dependencies of the .cpp file that is being compiled because if any of the included
# .h files change, our .cpp file will need to be recompiled in order to stay up to
# date.  So, we want to be thorough and capture all of these dependencies in our
# Makefile.  We could do this manually.  For each .cpp file we would need to add a
# rule to this Makefile that lists dependies, and would look something like this:
#    file1.o:  file1.cpp file1.h file2.h mydir/file3.h myotherdir/file4.h
# where all of the .h files are either included by file1.cpp or by each other.
# It's tedious and error prone to try to track down all these dependencies manually.
# So, instead, we ask the compiler to generate a list of dependencies for us and
# save it out to a new text file with a .d extension.  This text file lists the
# dependencies using the same Makefile syntax we would use if we wrote them down
# manually.  Read more about auto-dependency generation here:
# http://make.mad-scientist.net/papers/advanced-auto-dependency-generation
# usage: $(call make-depend,source-file,object-file,depend-file)
make-depend-cxx=$(CXX) -MM -MF $3 -MP -MT $2 $(CXXFLAGS) $1

# Once the make-depend-cxx() function auto-generates the .d text file of additional
# dependency rules, we need to load it into make, as if those rules were actually
# written in this file.  This is done with make's own "include" command, which
# enables us to include one Makefile within another.
-include $(addprefix $(OBJDIR)/,$(OBJFILES:.o=.d))

# Below, add an include directive for the visualization simulation, similar
# to the -include line above, that refers to the variables you defined
# for the visual simulation earlier (which were assigned paths to the
# object directory and object files for the visual simulation.

-include $(addprefix $(WEBOBJDIR)/,$(WEBOBJFILES:.o=.d))

# LINKING:
# This rule is for the linking step of building a program.  The dependencies mean that
# the executable target that we are building depends upon all of the .o files that are
# generated by the compiler as well as the $(BINDIR), which must exist so we can
# output the exe there.  The recipe that follows calls g++ to tell it to link all the
# .o files into an executable program.
$(EXEFILE): $(addprefix $(OBJDIR)/, $(OBJFILES)) $(DRIVEROBJDIR)/$(PROJECT_NAME).o | $(BINDIR)
	@echo "==== Linking $@. ===="
	$(CXX) $(OMP) $(LDFLAGS) $(addprefix $(OBJDIR)/, $(OBJFILES)) $(DRIVEROBJDIR)/$(PROJECT_NAME).o -o $@ $(LDLIBS)

$(EXEFILE2): $(addprefix $(OBJDIR)/, $(OBJFILES)) $(DRIVEROBJDIR)/$(PROJECT_NAME2).o | $(BINDIR)
	@echo "==== Linking $@. ===="
	$(CXX) $(OMP) $(LDFLAGS) $(addprefix $(OBJDIR)/, $(OBJFILES)) $(DRIVEROBJDIR)/$(PROJECT_NAME2).o -o $@ $(LDLIBS)

#$(EXEFILE2): $(addprefix $(OBJDIR)/, $(OBJFILES)) $(addprefix $(WEBOBJDIR)/, $(WEBOBJFILES)) | $(BINDIR)
#	@echo "==== Linking $@. ===="
#	$(CXX) $(OMP) $(LDFLAGS) $(addprefix $(OBJDIR)/, $(OBJFILES)) $(addprefix $(WEBOBJDIR)/, $(WEBOBJFILES)) -o $(BINDIR)/$@ $(LDLIBS)

# Below you'll need to add a target/dependency and rule to make the visual simulation
# create the executable similar to the one BELOW, but using the variables that
# you defined pointing to the  components of the visual simulation (WEBOBJDIR,
# WEBOBJFILES) that you defined earlier. The vis_sim target will also need the OBJDIR and OBJFILES.
# For example:
#vis_sim: ...


# Below you'll need to add a target/dependency and rule to make the visual simulation
# create the executable similar to the one BELOW, but using the variables that
# you defined pointing to the  components of the visual simulation (WEBOBJDIR,
# WEBOBJFILES) that you defined earlier. The vis_sim target will also need the OBJDIR and OBJFILES.
# For example:
#vis_sim: ...


%_test: $(DRIVEROBJDIR)/%_driver.o $(addprefix $(OBJDIR)/, $(OBJFILES)) | $(BINDIR)
	@echo "==== Linking $@. ===="
	$(CXX) $(OMP) $(LDFLAGS) $(addprefix $(OBJDIR)/, $(OBJFILES)) $< -o $(BINDIR)/$@ $(LDLIBS)

vis_sim: $(addprefix $(OBJDIR)/, $(OBJFILES)) $(addprefix $(WEBOBJDIR)/, $(WEBOBJFILES)) | $(BINDIR)
	@echo "==== Linking $@. ===="
	$(CXX) $(OMP) $(LDFLAGS) $(addprefix $(OBJDIR)/, $(OBJFILES)) $(addprefix $(WEBOBJDIR)/, $(WEBOBJFILES)) -o $(BINDIR)/$@ $(LDLIBS)

check-style:
	@echo "==== Checking style is correct ===="
	$(REPOROOTDIR)/cpplint/cpplint.py --root=.. *.cc *.h

check-style-cse:
	@echo "==== Checking style is correct ===="
	$(REPOROOTDIR)/cpplint/cpplint-cse.sh --root=.. *.cc *.h

# Clean up the project, removing ALL files generated during a build.
# BELOW, You should add a remove command to get rid of the object files
# created for the visual simulation (located in path assigned to WEBOBJDIR)
clean:
	@rm -rf $(OBJDIR)
	@rm -rf $(WEBOBJDIR)
	@rm -rf $(EXEFILE)
	@rm -rf $(BUILDDIR)/obj/$(PROJECT_NAME2)
	@rm -rf $(BUILDDIR)/bin/$(PROJECT_NAME2)
	@rm -rf $(BUILDDIR)/objdrivers/$(PROJECT_NAME).d
	@rm -rf $(BUILDDIR)/objdrivers/$(PROJECT_NAME).o
	@rm -rf $(BUILDDIR)/objdrivers/$(PROJECT_NAME2).d
	@rm -rf $(BUILDDIR)/objdrivers/$(PROJECT_NAME2).o
	@rm -rf $(BINDIR)/*_test
	@rm -rf $(BUILDDIR)/bin/rtout1
	@rm -rf $(BUILDDIR)/bin/rtout2
	@rm -rf $(BUILDDIR)/bin/vis_sim
