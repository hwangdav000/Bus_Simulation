### CSCI3081W: Iteration 3 Submission Checklist

> The iteration 3 code and documentation is due on WEDNESDAY, December 11 at 11:55pm.

**__Please copy this file into your /docs folder in iteration3__**. Place an 'x' in each of the `[ ]` boxes for items that are complete. Push this completed checklist to github. When it displays on Github, it will show an actual checkbox with a check mark.

### Compilation and Execution

- [ ] I cloned **fresh** from github onto a cselabs machine to test compilation
- [ ] Submission is on the master branch of the my personal repo "repo-<username>"
- [ ] _/project folder exists
- [ ] _/build_ is not in the repo
- [ ] _/html_ is not in _docs_
- [ ] _/latex_ is not in _docs_
- [ ] **__`make` from src completes without error.__**
- [ ] Both executables run without assert or a seg fault
- [ ] `cpplint-cse.sh *.cc` reports no errors
- [ ] `cpplint-cse.sh --root=.. *.h` reports no errors
- [ ] `doxygen docs/Doxyfile` generates the necessary doxygen documentation

### Primary Functionality

> To make grading easier, we ask that you provide the status of each of the requirements. Do not lie about the status!! It makes us grumpy -- you want your grader to be happy when s/he grades! We will be inspecting the code to confirm, but this status report can make it faster for us.

**__Please place an 'X' in the appropriate box for each requirement.__**
- Good = Fully Implemented. No _known_ bugs. No _obvious_ bugs.
- Okay = Works but some bugs (recorded as a bug/issue on github).
- Help = Attempted but not working.
- Time = No to Little Progress

| Functionality | Good | Okay | Help | Time |
| -------- | -------- | -------- | -------- | --------- |
| **__Refactoring__** |
| Refactoring 1 is completed |  |  |  |  |
| Refactoring 1 exists within either branch refactor/iter3 or branch refactor/iter2 |  |  |  |  |
| Refactoring 2 is completed |  |  |  |  |
| Refactoring 2 exists within branch refactor/iter3 |  |  |  |  |
| Refactorings do not change observable functionality |  |  |  |  |
| File release_notes.md exists and identifies locations of Refactorings | | | | |
| **__Refactoring 1__** |
| Refactoring 1 does not require changes to config file structure |  |  |  |  |
| Refactoring 1 removes possibility of users changing probability of a route's final stop to be non-zero |  |  |  
| **__Refactoring 2__** |
| File refactor.xxx exists within project/docs/ (where x = pdf or doc or txt or rtf) |  |  |  |  |
| Refactoring is clearly identified and explained |  |  |  |  |
| **__Regression Testing__** |
| Regression testing exercises full breadth of functionality |  |  |  |  |
| Regression testing is deterministic |  |  |  |  |
| Regression testing automatically determines if the program behavior is the same or has changed |  |  |  |  |
| Regression testing requires tester to determine if the output/result is as expected |  |  |  |  |

<hr>

For the table below, please specify which aspects were fixed. You should put an "x" in one of the three columns. We will restore points only for those elements that are complete and correct.

### THIS IS ESSENTIAL FOR RESTORING POINTS FOR FUNCTIONALITY. 
*You can potentially get back lost functionality points from Iteration 2, but we have to know what to look for. We will not spend time tracking down what didn't work in earlier iterations and trying to see if it is working in iteration 3. We need you to tell us what to look for, and then we will review your github issues and your updated functionality to determine your score for that item*


| Functionality | Complete in it2 | | Fixed in it3 | Still Buggy |
| -------- | -------- |-| -------- | -------- |
| **__YOU NEED TO UPDATE THIS LIST__** |  ||  |   |


### Documentation
- [ ] _mainpage.h_ or _mainpage.md_ is in the /src folder.
- [ ] I have compiled doxygen and looked at the generated mainpage.
- [ ] The mainpage includes a user guide for technical users (updated developers guide from iteration 1).
- [ ] The mainpage includes a user guide for non-technical users.
- [ ] I commented my code where necessary.
- [ ] A document named **release_notes.md** specifying names of branch(es) that hold refactoring 1 and 2, and any other assumptions is in project/src directory.

### Linter and Git
- [ ] The code complies with naming conventions for classes, methods, and members.
- [ ] There exists a history of git commit messages to show effort.
- [ ] There exists a history of issues and branches to show effort.

### Reporting of Bugs
- [ ] Viewing issues on my repo and selecting _bug_ label shows all the known bugs in my code.
- [ ] All resolved issues have been _closed_ (including bugs).


## Ready For Submission

When everything above is as you want it (or it is 11:50pm on Wednesday), it is time to submit!

- [ ] I pushed this file and any changes resulting from this checklist.
- [ ] Everything is in the **__master__** branch.

_One more thing -- check that what you think you pushed was really pushed to github on the master branch. Go to your repo on github.umn.edu and look at your files. If you can see it there, we can see it. If you can't, we can't._

Congratulations on your submission!
