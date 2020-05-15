You can convert this requirements document to pdf using this tool: <http://www.markdowntopdf.com/>

| <span id="a1">Date</a> | Item | Description |
|:----:|:-----|:------------|
| WED, December 4, 11:55pm | [Refactoring Requirements Due](#refactor) | submit via GitHub |
| WED, December 11, 11:55pm | [Final submission of Iteration 3](#deliver) | Automated tests and inspection |

>Your software is a reflection of your understanding of the requirements as specified in this document. If you do not understand any portion of the requirements or you think that the requirements are underspecified, it is your responsibility to get clarification from the instructor or a TA. Please read this document carefully and review it often _WELL IN ADVANCE_ and often before turning in your iteration for assessment.

## Version 3: December 6th, 2019 - updated instructions on length of mainpage. User guide must be  3 - 4 pages _IN ADDITION TO_ the developers guide you created for iteration 1 (and are updating for this iteration). Also, the number of regression tests required for iteration 3 has been updated. Review the sections in the specification below that discuss the aforementioned items for more details. 

## Version 2: December 4th, 2019 - added instructions on mainpage.h font and line spacing; instructions for including the code for refactoring 1 and refactoring 2 in branches, and requirements for adding a release_notes.document specifying the branch or branches that contain the refactoring 1  and the refactoring 2 code. Clarified Bug Fixing requirement in assessment.

# Releasing to the public: Iteration 3  

Congratulations! With the first two iterations complete, we head to our project release: Iteration 3. Our simulator is taking the last turn towards its long tail: the journey towards deployment and inevitable, unending maintenance. Well, we'll at least get to the deployment part. Specifically, we will now stop adding major functionality and instead focus on improving quality before launch to our users.

The emphasis in this iteration will be on getting your project to the point where it is such a solid platform and code base that it is ready to be used by both end users of the software and other developers outside of your team.  Writing is essential at this stage of software refinement – documentation, guidelines, tutorials, etc.

* Correctness

	Most development focuses on getting the most important functionality working under the most common circumstances. Bug fixing is when we can finally stop worrying so much about adding the next top-level function set, and instead fix what's already there (and broken). 
	**Note:** This particular section could potentially be worth lots of your time. 
	**_You can receive up to 100% of the points for any simulation functionality for which you lost points in Iteration 2 functionality (development) by fixing the bugs_** __- IF you properly tracked those bugs using GitHub Issues before the Iteration 2 deadline.__
	**However**, _if you did **not** create GitHub Issues for your bugs and fixes_, __you can receive up to 50% of the points for any simulation functionality for which you lost points in Iteration 2.__

	Your mainpage is the entry-point to your documentation. Each of your user sets will use it as the landing page. We've started the Developer guide. Now, we add a short User Guide. How does a non-developer user (any of the stakeholders we identify in our class and lab discussions) get and use your system? How do they run (and tweak) simulations?

	This is where your choices for user input come into play. Whether you decided on command line arguments or interactive data gathering, you now need to explain to a potential user how to input the necessary parameters for their simulation: where the config file is located, how long for the simluation to run, and how long the simulation should wait before generating a bus (once per route).
	
* High Quality Code

	You will refactor your code to improve its quality with respect to readability or efficiency. Refactoring is the process of changing functional code. It is not feature enhancement, and it should have no impact on the outward behavior of the system. It may improve efficiency. You must select a meaningful refactoring from a large list posted by Martin Fowler on the web. We have provided instructions for three specific refactors that explain how to complete the refactor and what to submit. You are welcome to select another meaningful refactoring for Refactoring 2 if you wish.


#### Table of Contents

<ol type="I">
  <li> <a href="#reqs">Iteration 3 Requirements</a>
  <ol type="A">
    <li><a href="#reqs_doc">Documentation Requirements</a>
    <ol type="i">
      <li> <a href="#doxy">Doxygen</a>
      <li> <a href="#style">Style Compliance</a>
      <li> <a href="#bug">Bug Tracking</a>
    </ol>
    <li><a href="#reqs_dev">Code Development Requirements</a>
    <ol type="i">
	  <li> <a href="#bugfix">Bug Fixing</a>
      <li> <a href="#refactor">Refactoring</a>
      <li> <a href="#testing">Regression Testing</a>
    </ol>
    <li><a href="#peer">Peer Response</a>
  </ol>
  <li> <a href="#deliver">Deliverables and Submission</a>
  <li> <a href="#assess">Assessment</a>
  <li> <a href="#resources">Resources</a>
</ol>

<hr>



## <a name="reqs">Iteration Requirements</a>

#### Overview

The goal of this iteration is to wrap up functionality and increase quality before release to the public.

<hr>

#### <a name="reqs_doc">Documentation Requirements</a>

- Doxygen generated index.html that is the entry point to your software.
- Google Style compliance
- Bug Reporting through issues

Code documentation comes in many forms for many audiences. For this iteration, **your audience is all stakeholders** who will be using our software project. We'll be using a variety of tools towards this end.

- ##### <a name="doxy">Doxygen</a>

  The index page of your Doxygen html documentation should be complete and well written. This will be a second draft of the writing in mainpage.h, and probably the final draft. It should provide a brief overview/introduction to the software, then discuss specifics in the design and implementation that will assist any programmer who will be a new contributor to the code, and finally provide a user guide for non-technical users to be able to download, configure, and operate the simulator. If the text were on an 8.5x11 piece of paper, your ~~entire mainpage.h~~ user guide should be 3-4 pages. Moreover, the font size you should use should be 10 or 11 point, and the line spacing should be the word default, which is 1.15 points. 

  As part of your fresh clone prior to submission, please also compile the Doxygen and look at the generated webpages.

  > Make sure to place the Doxyfile in _project/docs_.  Set the output directory to: `OUTPUT_DIRECTORY = ./docs` so that when it is compiled from the _project_ directory it will put the html and latex folders in the docs directory/folder.
  
  Additionally, continue to refine your in-code Doxygen documentation. This should include a brief description for **all** classes in the src directory and full documentation of Bus, Stop, Route and Passenger, as well as any other classes you made to assist in their primary responsibilities (PassengerLoaders, RouteFactory, etc.), if you made them. 

- ##### <a name="style">Google Style Guide Compliance</a>

  <https://google.github.io/styleguide/cppguide.html>

  Please comply to the Google C++ Style. Running cpplint on your code should generate 0 errors. Check that your methods are CamelCase and your variables are lower case, each word in the variable name is separated by an underscore, and variables that are attributes of a class end in an underscore.

- ##### <a name="bug">Bug Tracking</a>

  Again for this final iteration, create Git issues to document bugs, feature enhancements, refactoring, documentation, clean-up, etc. As you address significant issues, create a branch off of devel. Note: you can address several issues within a single branch. Follow the protocol you learned in lab 10. 

  As in the previous iteration, code should be developed in a branch off of the devel branch. Please do not delete your branches after they are merged - that enables us to grade that aspect of your development.

  Commit messages for less significant modification can be composed at the command line, but should be consistent in style and be informative with regard to what changes were made where. You can make minor edits on the devel branch, but the version you keep in your development branch should always compile without compile errors and Google style issues and execute.

  Do not merge the devel branch with master until the final implementation in the devel branch is ready for submission.
  
  Any existing bugs at the time of submission **must** have Issues for partial credit to be given.

<hr>

#### <a name="reqs_dev">Code Development Requirements</a>

In this iteration, you will be fixing bugs.

- ##### <a name="bugfix">Bug Fixing</a>

  You should fix all of your bugs, so that the code functions as required in Iterations 1 & 2. As described above, not only will Iteration 1 & 2 functionality be tested again, you may receive up to 100% of any value you lost in Iteration 2 functionality (development) for bugs YOU HAD, and HAVE ENTERED GITHUB ISSUES FOR (during iteration 2), AND SUBSEQUENTLY FIX AND CLOSE IN ITERATION 3. You will receive up to 50% of any value you lost in Iteration 2 functionality (development) for bugs you begin to track now, by entering GitHub Issues for these defects, fixing the defect, and then closing the issue.

  For Iteration 3 grading, no bugs which would be considered critical should remain. Minor bugs (small functionality irregularities, typos, rare occurrences, etc.) will not reduce your score. If you are unsure whether your bug is critical or minor, go to an office hour or speak to an instructor.

- ##### <a name="refactor">Refactoring</a>

	This portion of iteration 3 requires you to refactor your iteration 2 code. Because we want you to do the refactoring independently of completing the priorities of iteration 2, you will need to complete the following steps for each refactor.

	Create a new branch for your refactoring task. You must follow the naming conventions for this branch since we will be checking only this branch for your work. Create the following branch in your repository: refactor/iter3. Again, you **must** follow the naming conventions set forth in the following instructions since we will not search for your documents if they are not in these locations with the required names. Follow the git-usage document to create a substantial commit message when pushing the refactor branch.
	
	###### Refactoring 1 (Pushed from Iteration 2)

	We also want to refactor one element of the project which could cause errors, especially now that we're pulling from user-defined configuration files. The current version of the probability list for stops includes the value for the final stop on a route. With nowhere to go, that probability needs to be 0. But, with configuration files, this can't be guaranteed without some changes to our code. Refactor the code so that there is no probability (even if provided by configuration) for the final stop in a route, and that the simulator does not use or try to access such a probability for the final stop in a route.	
	
	* If you have completed this refactoring in iteration 2, merge it into its own branch named **refactor/iter2** and remove the refactoring from the final version of the code you submit via your master branch.  
	
	* If you have not yet done this refactoring, you should do it in its own branch, named: **refactor/iter2** - and make sure it is not included in final version of the code you submit via your master branch. 
	
	* Otherwise, if you have already completed this refactoring and the refactoring for iteration 3 in the branch named: **refactor/iter3** - that is perfectly acceptable. However, note that the code for the refactoring should not be in the final version of the code that you merge into and sumbit via your master branch. 
	
	###### Refactoring 2
	
	Below is the link to Martin Fowler's Refactoring.com page - it lists 91(!) possible refactorings: 
	
	<https://refactoring.com/catalog/>
	
	There are (at least) three you should consider for this iteration: Replace Temp With Query, Change Variable and/or Method Names, or Extract Method. You are required to select  one refactoring (one of these three given or one of your own choosing) and create a document explaining your use of the refactoring. Note: if you choose a refactoring other than one of the three listed below, you should complete the steps in a similar manner to those in these examples (branching, creating the document, listing files, explaining what you did, etc.).

	1. Replace Temp With Query

		Look through your code and identify a temporary variable that is referenced multiple times and holds the result of an expression. Create a function that evaluates the expression and replace all references to the temp with this function call. Complete the following tasks:

		IN THE BRANCH refactor/iter3, refactor the code in your iteration3 source code (/project/src).

		Create a text or web-viewable document called refactor.xxx (where xxx is a placeholder for the suffixes: pdf, doc, txt, or rtf - but note, we would prefer a pdf file) in the /docs directory, that contains these:

		* A list of the files and methods added and/or changed.
		* The code, filename, and line number where the temporary variable was defined.
		* The name of the new method you created and where it is located. Identify clearly also where any changes were made to call the new function.
		* A brief explanation of what behavior this is replacing. What does the new function specifically do? (No more than one paragraph.)

	2. Change Variable and/or Method Names

		Look through your code and identify two names (either class variables or methods) that do not provide meaningful information about the data they store or their functionality, respectively. Update your variable and/or method names and make all necessary naming changes. Complete the following tasks:

		1. IN THE BRANCH refactor/iter3, refactor the code in the original file(s) in your iteration 3 source code (/project/src).

		Create a text or web-viewable document called refactor.xxx (where xxx is a placeholder for the suffixes: pdf, doc, txt, or rtf - but note, we would prefer a pdf file) in your /docs folder, that contains:

		* A list of the files and methods where you are making your changes.
		* The original variable and/or method names that you are changing and what their new names are called after the refactor.
		* A brief explanation of how your new names are better than the old ones (no more than one paragraph.)

	3. Extract Method

		Look through your code and identify a method that is too long and extract at least one method from this. Be sure to update all method calls as needed. Look at Lab09(?) if you get stuck on how to approach this. Complete the following tasks:

		1. IN THE BRANCH refactor/iter3, refactor the code in the original file(s) in your iteration 3 source code (/project/src).

		2. Create a text or web-viewable document called refactor.xxx (where xxx is a placeholder for the suffixes: pdf, doc, txt, or rtf - but note, we would prefer a pdf file) in your /docs folder that contains:

		* A list of the files and the method(s) you are changing.
		* The location of the changes. Be sure you explain briefly what you are doing at each location.
		* A brief explanation of how this improves your code (no more than one paragraph.)

- ##### <a name="testing">Regression Testing</a>

	Regression tests (pushed from Iteration 2 to Iteration 3):

	* For regression tests, the goal is to verify that features that worked once stay working, even as you continue to add to the code.
	* For our simulations, that probably means some relatively simple and structured scenario that can be reused and in which we know the exact output.
	* To use this testing strategy with Google Test, you should add store any config files you need in project/config/ and anything else that might be helpful in project/resources/, while attempting to ensure that changes you make to create the regression test do not  break anything that was already working.
	
**One important change to this iteration 2 regression test requirment is that for iteration 3 you are required to create only ONE (1) regression test. As specified in lab 15, the regression test you create _must be different_ than the regression test we give you in lab 15.**

<hr>

#### <a name="peer">Peer Response</a>

We will be working in class to complete peer responses regarding your choices for refactoring, so you must have a draft of your refactoring that is well formatted, grammar, and spell checked ready to bring to class on Thrusday December 5th. You are REQUIRED to bring 3 printed copies to class on Thursday December 5th to participate in the peer review / response or you will recieve a zero for the refactoring portion of your grade on iteration 3. 

<hr>

## <a name="deliver">Deliverables and Submission Process</a>

For the final deliverable deadline, everything will be submitted via Github in your **__master__** branch. We will pull your repository at the specified due dates and grade according to the contents at that time. You should be developing in your devel branch, but at the time of submission, merge devel with master, commit changes to master, and push to github.umn.edu.

You should include a document named: **release_notes.md** in your project/src directory. The contents of the document should specify the branch or branches where your refactoring for iteration 2 and iteration 3 reside, and any other assumptions that you have made in your development efforts in order to assist us in grading your simulation. It is in your own best interest to do this to ensure the grading team can properly review your efforts and assign you a grade.  

**Late assignments will not be accepted**, but anything you do submit on time will receive partial credit for partial completion of the requirements.

Your software will be assessed through testing and by the TAs. The process for testing will be to `make clean` then `make`. We **highly encourage** you to freshly clone your repo on a **cselabs machine** and also `make clean` and `make` to confirm all is working well.

<hr>

## <a name="assess">Assessment</a>

This is the breakdown for point distribution:

20% : Iteration \#3
- 30% : Doxygen
  - 15% : User Guide
  - 15% : Updated Developer Guide
  - release_nodes.md document in project/src specifiying location of refactoring for iteration 2 and 3 and other assumptions
- 10% : Style Compliance
- 10% : Refactoring 1 Completed
- 10% : Refactoring 2 Completed
- 10% : Regression Testing
- 15% : Git Usage (Issues, commit messages and branching)
- 15% : Compiles and runs without seg fault **and no major bugs**

<hr>

## <a name="resources">Resources</a>

Local System and Compilation:
- Repo: https://github.umn.edu/umn-csci-3081-f19/csci3081-shared-upstream
- Compilation: https://gcc.gnu.org/
- Linux quick reference: http://www-users.cs.umn.edu/~larson/repo-website-resources/website/examples/csresources/linux.html
- Makefile Resources: https://www.gnu.org/software/make/manual/make.html
- More Makefile Resources: https://opensource.com/article/18/8/what-how-makefile

Testing:
- https://github.com/google/googletest
- Unit Testing: https://martinfowler.com/bliki/UnitTest.html

Style:
- https://google.github.io/styleguide/cppguide.html
- https://github.com/google/styleguide/tree/gh-pages/cpplint
- https://www.python.org/downloads/

Documentation:
- http://www.doxygen.nl/manual/docblocks.html
- https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet
- https://www-numi.fnal.gov/offline_software/srt_public_context/WebDocs/doxygen-howto.html

IDEs:
- Xemacs: https://www.xemacs.org/
- vi: http://www.lagmonster.org/docs/vi.html
- Atom: https://atom.io/
- Sublime: https://www.sublimetext.com/
- Eclipse: https://eclipse.org/

<hr>
