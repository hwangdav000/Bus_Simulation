### CSCI3081W: Iteration 2 Submission Checklist

> The iteration 2 code and documentation is due on WEDNESDAY, November 27 at 11:55pm.

> VERSION 3: Added "root" flag to CPPLINT check for .cc files

> VERSION 2: Updated Doxygen requirements to run from within docs/

**__Please copy this file into your project/docs folder__**. Place an 'x' in each of the `[ ]` boxes for items that are complete. Push this completed checklist to github. When it displays on Github, it will show an actual checkbox with a check mark.

_Note: This checklist is not authoratative. If something is missing on the checklist, that does not imply it is not needed or that you don't need to do it. The requirments and rubric are the source-of-truth on what you need to do. This is merely a guide to help walk you through submission._

### Compilation and Execution

- [x] I cloned **fresh** from github onto a cselabs machine to test compilation.
- [x] Submission is on the master branch of the my personal repo "repo-<username>".
- [x] _/project folder exists.
- [x] _/build_ is not in the repo.
- [x] _/html_ is not in _docs_.
- [x] _/latex_ is not in _docs_.
- [x] **__`make` from project/src completes without error.__**
- [x] Both executables run without assert or a seg fault when given a config filename.
- [x] `cpplint-cse.sh --root=.. *.cc` reports no errors for your code.
- [x] `cpplint-cse.sh --root=.. *.h` reports no errors for your code.
- [x] `doxygen Doxyfile` generates the documentation.
- [x] Config files held in project/config.
- [x] Test files held in project/tests.
- [x] **__`make` from project/tests completes without error.__**

### Primary Functionality

> To make grading easier, we ask that you provide the status of each of the requirements. Do not lie about the status!! It makes us grumpy -- you want your grader to be happy when s/he grades! We will be inspecting the code to confirm, but this status report can make it faster for us.

**__Please place an 'X' in the appropriate box for each requirement.__**
- Good = Fully Implemented. No _known_ bugs. No _obvious_ bugs.
- Okay = Works but some bugs (recorded as a bug/issue on github).
- Help = Attempted but not working.
- Time = No to Little Progress

| Functionality | Good | Okay | Help | Time |
| -------- | -------- | -------- | -------- | --------- |
| **__Configuration__** |
| Simulation properly uses config files to run simulations | x |  |  |  |
| Invalid config file names are handled gracefully |x  |  |  |  |
| Missing config file name is handled gracefully | x |  |  |  |
| **__Visualization__**
| Routes are displayed properly |x  |  |  |  |
| Stops are displayed properly |x  |  |  |  |
| Bus appears at a stop when loading/unloading passengers |  |x  |  |  |
| **__Testing__** |
| Testing covers Bus class | x |  |  |  |
| Testing covers Route class | x |  |  |  |
| Testing covers Stop class | x |  |  |  |
| Testing covers Passenger class |x  |  |  |  |
| Command line interaction is tested appropriately |x  |  |  |  |
| Testing covers error-prone concepts |  |x  |  |  |

<hr>

### Documentation

- [x ] Class methods fit within a single perspective of abstraction.
- [x ] Class and variable names are informative.
- [x ] Public method comments describe intent.
- [x ] _mainpage.h_ or _mainpage.md_ is in the /src folder.
- [x ] I have compiled doxygen and looked at the generated mainpage.
- [x ] I commented my code where necessary.

### Linter and Git
- [x ] My code complies with the style guide.
- [x ] The code complies with naming conventions for classes, methods, and members.
- [x ] There exists a history of git commit messages to show effort.
- [x ] There exists a history of issues and branches to show effort.

### Reporting of Bugs
- [x ] Viewing issues on my repo and selecting _bug_ label shows all the known bugs in my code.

## Ready For Submission

When everything above is as you want it (or it is 11:50pm on Wednesday), it is time to submit!

- [x ] I pushed this file and any changes resulting from this checklist.
- [x ] Everything is in the **__master__** branch.

_One more thing -- check that what you think you pushed was really pushed to github on the master branch. Go to your repo on github.umn.edu and look at your files. If you can see it there, we can see it. If you can't, we can't._

Congratulations on your submission!
