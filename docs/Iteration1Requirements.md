# TransitSim: a Proof-of-Concept Transit System Simulator

## Iteration 1 - VERSION 7, October 30th - NOTE, THIS DOCUMENT IS SUBJECT TO CHANGE. CHECK IT EVERY DAY OR TWO
* Version 7 - removed the other stale link to Doxygen information, replaced with live and useful links
* Version 6 - Update GetTotalWait description in Priority 1
* Version 5 - clarifications about Unit Test creation instructions
* Version 4 - added Table of Contents, small wording adjustments
* Version 3 - Changed Delivery Requirements for Iteration 1 Preliminary Delivery 1: Submit your diagram in a PDF file via the Canvas using the item named Iteration 1 Preliminary Deliverable 1
* Version 2 - removed stale link to Doxygen information, replaced with live and useful links
<hr>

| Date | Item | Description |
|:----:|:-----|:------------|
| TUE, Oct 22, 11:55pm | UML diagram of proposed solution | **Submit via Canvas and Github on devel.**|
| WED, Oct 30, 11:55pm | Preliminary testing submission   | Pass automated tests. **Submit tests within `passenger_UT.cc` via Github on devel.** |
| WED, Nov 06, 11:55pm | Documentation and Code Implementation | Automated tests and inspection. **Submit all deliverables in their proper directories via Github on master.** |

Your project should demonstrate thoughtful software development with good design quality while rigorously following the process you learned in Lab 10. This iteration will help you to establish those good habits. You will create design documents including a UML diagram. You will use Doxygen compliant comments to comment your code and then automatically generate code documentation. Code style will comply to the Google Style Guide. Intermediate deadlines will keep you on track in the iterative process you are using to develop Iteration 1, and the project this semester.

#### Deliverables and Submission Process

Everything **EXCEPT THE PDF FILES YOU SUBMIT CONTAINING YOUR UML** will be submitted via Github. We will pull your repository at the specified due dates and grade according to the contents of your **_devel_** branch at that time. Your _final_ iteration 1 submission will contain all of the above changes within your **_master_** branch. Only merge **devel** into **master** when you have completed the entire Iteration 1.

**_Please verify that your submission compiles on a CSELABs machine and it is complete. You will receive no grade or be heavily penalized if your code does not compile upon submission._**

The schedule is very tight, and it is important that you keep up with the project. The project will continue to build throughout the semester, and if you get behind, it will be very difficult to catch up. For this reason, **late assignments will not be accepted**, but you will receive partial credit for partial completion of the requirements.

You can convert this requirements document to pdf using this tool: http://www.markdowntopdf.com/

<hr>

## Table of Contents
1. [Documentation and Code Implementation Requirements](#1)
    * 1.1 [Overview](#1.1)
    * 1.2 [Functional Requirements](#1.2)
2. [Priority Levels](#2)
    * 2.1 [General Understanding](#2.1)
    * 2.2 [Priority Level 1 : Passengers and Stops](#2.2)
    * 2.3 [Priority Level 2 : Routes and Output Refactoring](#2.3)
        * 2.3.1 [Routes](#2.3.1)
        * 2.3.2 [Output Refactoring](#2.3.2)
    * 2.4 [Priority Level 3 : Buses](#2.4)
    * 2.5 [Challenge](#2.5)
3. [Unit Testing with Google Test](#3)
4. [Google Style Guide Compliance](#4)
5. [Documentation](#5)
    * 5.1 [UML](#5.1)
    * 5.2 [Doxygen](#5.2)
6. [Assessment](#6)
    * 6.1 [Documentation Assessment](#6.1)
        * 6.1.1 [Draft of UML Diagram](#6.1.1)
        * 6.1.2 [Complete Iteration Documentation](#6.1.2)
            * 6.1.2a [Design Document and UML](#6.1.2a)
            * 6.1.2b [Google Style Compliance](#6.1.2b)
            * 6.1.2c [Doxygen Documentation](#6.1.2c)
            * 6.1.2d [Github Isues](#6.1.2d)
            * 6.1.2e [Self-Documenting Code](#6.1.2e)
    * 6.2 [Code Assessment](#6.2)
        * 6.2.1 [Preliminary Testing Submission](#6.2.1)
        * 6.2.2 [Completed Iteration Code](#6.2.2)
7. [Getting Started](#7)
8. [Important Notes to Remember](#8)
9. [Resources](#9)

<hr>

_NOTE: the above links will likely not work outside of a website interface like Github._

## 1. Documentation and Code Implementation Requirements <a name="1">

### 1.1 Overview <a name="1.1">

The goal of this software project is to develop a rudimentary transit simulator in which simulations can be controlled via external configuration (without code change) and be visualized within a graphics window. 

In this iteration, you will put all the pieces in place for development including base code, unit tests with Google Test, class structure, Google style guide compliance, design documentation using UML, doxygen
documentation, Git usage, and self-documenting code (i.e. good organization and naming conventions). Teaching staff will also be working diligently to provide the structure and support for development, testing, and documentation. Automation in unit testing, style compliance, in-house Github testing, and documentation will make this an easier process, however it means that you will have to develop within the constraints of these systems. Often there is a learning curve and a lot of systems trouble-shooting to get it all working, so start early!

In the first iteration, we will limit the simulation to a single scenario involving campus transit via bus here at the University of Minnesota. This will suit us fine as we are still building out our core functionality for the project in Iteration 1. Iterations 2 and 3 will put the core functionality to greater use and extend it. 

### 1.2 Functional Requirements <a name="1.2">

You are being provided with a significant initial code base. The first iteration is focused on building domain entities and getting practiced in the software development process. It is also a drop into the depths of C++ syntax. If you have any questions about the provided code, please ask. We do not expect you to understand all pf the constructs in this code. Below is an outline of the required functionality.

The code is organized such that simulation behavior (i.e. the model) is separate from the visualization (i.e. the view), which allows for automated unit testing using Google Test. In addition, there have been a few entities which have been made into abstractions to allow for extension (and for grading). The _Simulator_ is the primary driver of the application. For now, the only implementation of this is the _LocalSimulator_. 

_LocalSimulator_ is relatively primative. It is hard-coded with the campus's transit system in mind. There is no external control of the simulation; it can only be change by modifying the code. This isn't ideal. But, the _Simulator_ abstraction allows for us to build additional subclasses which will provide for more functionality. Functionality that will be implemented via additional subclasses that will be included in Iteration 2 will enable visualization and configuration. However, this iteration's hard-coded simulator will serve one purpose well: allowing us to build out our domain and test it.

<hr>

## 2. Priority Levels <a name ="2">

**REQUIREMENTS you need to fulfill**

> This is just functionality. Along the way, please document the code using Doxygen syntax and test for Google Style compliance using cpplint. Refer back to Lab 08 to help refresh your memory.

Below is a prioritized list of feature enhancements, fixes, and refactoring of the code. **Complete all functionality in one priority level before moving on to the next.** In this way, if we run out of time, the low priority items will be dropped from the requirements.

### 2.1 General understanding <a name ="2.1">

The statistics we have are route-based: we know how likely it is that a passenger will show up at that stop in each time unit. When more than one bus is generated for a route, we need to be careful with stops. After a bus has passed a stop, it is possible for passengers to "show up" to stops the bus has already passed. However, when another bus is created for the same route, the new bus should come and pick up these passengers. This means that each bus may have its own understanding of its own route, but the stops have relationships with multiple buses in the simulation. This is something we will discuss and work through in class.

Buses do not make more than one trip through their routes. When they finish both of their routes (outbound and inbound), the bus should be removed from the simulation. This prevents us from doing interesting things with fuel cost and tracking, but also lowers complexity in a few different places.

Before discussing various levels of priority for our domain entities, there is one method which requires a special note: `Report`.

###### _ Report _

All of our domain entities will have this method. This method was created during the high-level design discussions. This output format has been specified and will very likely not change. You should not (need to) modify this method. It is used not only for functional purposes for visualization of data in a non-graphical application, but also for verifying functional operation in testing.

### 2.2 Priority Level 1 : Passengers and Stops <a name ="2.2">

#### Passenger

Be sure to confirm that all values of the Passengers state are accurate after your methods execute. Particularly, that the Passenger counts all of the timesteps in the simulation from the time step it is generated to the timestep it gets off of its bus at its destination (both inclusive).

There are three methods which warrant further discussion:

###### _ Update _

All of our domain objects will call `Update`. This method must make whatever changes to state that are required of the simulation during a timestep. When the simulation is running, a passenger is doing one of three things for that time step: waiting at a stop, riding on a bus as it moved, or getting on/off the bus.

_NOTE: if you are familiar with graphics or animations, this is akin to a frame update- what changes need to happen during this frame?_

###### _ Get Total Wait _

Returns the sum of all timesteps the Passenger has waited at a stop before getting on the bus PLUS the time the passenger was on the bus. This time *does* include the timestep during which the Passenger gets on a bus (attributed to time on bus).

###### _ Report _

This method was created during the high-level design discussions. This output format has been specified and will very likely not change. You should not (need to) modify this method.


#### Stop

Represents each place a bus stops to pick up and drop off passengers. It should be noted that for a real-world stop on a bus route, often there are stopping locations on opposite sides of the street. In our simulation, we treat these stops as two _different_ stops in our vernacular. The default location is the Coffman Memorial Union stop, for now.

One method needs further discussion: `LoadPassengers`.

#####  _ Load Passengers _

This method was included in the Lab 09 starter code, but is absent here in the project base code. It is actually a bit of an interesting case. This does *NOT* need to remain in the implementation. It was suggested in design, but not conclusively decided. It could be a starting point for your design decisions. If it is not, you are allowed to ignore it.

Two data members also deserve further explanation.

##### _ longitude _
##### _ latitude _

Together, they represent the location of the stop. This information is not currently of use, but will become necessary in Iteration 2.


### 2.3 Priority Level 2 : Routes and Output Refactoring <a name ="2.3">

#### 2.3.1 Routes <a name ="2.3.1">

Routes are a series of stops. This makes sense in the real world and in our system. As such, our current idea of a route is to have an instance hold references to each of its stops as well as the distances between each stop. The current understanding is that each Route differs slightly from the real-world of a "route" in that our Routes are always _one-way_. This is partially to simplify the model. Having passengers show up at a stop and be able to go in either direction would make the Stop concept more complicated. When displaying the stops, it is far easier to display by keeping each direction of the route as a distinct concept. For example, in this first iteration, you can see that we have an eastbound route for the campus connector as well as a westbound route (despite the fact that the connector actually travels in a lumpy circle).

#### 2.3.2 Output Refactoring <a name ="2.3.2">

In early prototyping and debugging of individual units, it is very common to simply use the display for output of information. `std::cout` is a familiar friend in this. However, once we get to a point where we want to have persistent access to results, we will want flexibility in operation and ease in testing program output. To this end, we will refactor our code to allow for the use of other `ostream` objects in place of `std::cout` for the `Report()` methods that exist within our system.

Find each instance of this method and refactor the code to include the ability to give the method an instance of an `ostream` object (which may or may not be `std::cout` in the end). Remember _refactoring means to modify the internal functionality of the code while maintaining the same observable behavior outside the system._ Our methods should still work the same way from the outside (assume that our simulator will be similarly updated to use this new functionality. You may also do this yourself in your testing.

### 2.4 Priority Level 3 : Buses <a name ="2.4">

Now that the other three classes are (relatively) complete, we can build our final domain object, the Bus.  Buses move and pick up/drop off passengers. To that end, our buses have a speed (a distance to move per time unit) and a max capacity for passengers. Glaringly absent is how the Bus keeps track of the passengers on that Bus. In addition, our two common methods (`Update` and `Report`) are missing as well. Each of these will need to be added for this system to work well.

### 2.5 Challenge [NOTE: This is UNGRADED, only for fun.] <a name ="2.5">

Extend the local simulation with command line control of the time between bus generations. Allow the user to place an integer value as an argument when invoking the simulation from the command line. Use this integer to control the bus generation in LocalSimulator.

<hr>

## 3. Unit Testing with Google Test <a name ="3">

https://github.com/google/googletest

Unit tests are essential in a large-scale project because the entire code base can be tested regularly and automatically _as it is being developed_. In the strictest application of **Test-Driven Development (TDD)**, the tests are written _before_ the code, which helps solidify requirements and write testable code.

A sample test file is provided in the `/project/tests` directory. This directory must be a sibling to your _src_ directory and will be home to all of your test files. When you _make_ the tests, they will generate an executable (in `build/bin`) which, when executed, displays a report of the tests. Use this file as a guide to your own testing. While the requirements for testing in **Preliminary Deliverable #2** (more later) are rather light, you can expect a much more robust testing requirement in later iterations. Do not slack on making good tests for your code!

Refer back to Lab 08 is remember how you wrote unit tests for the Date class and its methods.

## 4. Google Style Guide Compliance <a name ="4">

https://google.github.io/styleguide/cppguide.html

Consistency in code organization, naming conventions, file structure, and formatting makes code easier to read and integrate. There are many options with various merits, so it is up to the development team to establish these conventions, or, in the words of Kevin Wendt: "The only style guide that really matters is the one your boss uses." We decided to use the Google Style guide because it is published, documented, and has automated tests. We don't agree with every decision, but we are complying so that we are all coding to a single standard.

To test your code for Google Style compliance, you can run cpplint on a CSELABs machine (which will be how style compliance is checked on submission):

```
cd src
../../cpplint/cpplint-cse.sh --root=.. *.h
../../cpplint/cpplint-cse.sh *.cc
```

The tag `--root=..` impacts the header guard. The header guards provided in the base code all start with `SRC`. If you are getting errors due to the header guard because it is expecting `INCLUDE_SRC` or no `SRC` **do not change the header guard.** Instead, check that the `--root` flag is set properly. If the `--root` flag is like we have above and is still giving you errors, please notify staff so that we can figure out how to fix it.

Refer back to Lab 08 for more information on Doxygen.

<hr>

## 5. Documentation <a name ="5">

- UML diagram
- Doxygen generated web pages including `mainpage.h`
- Self-Documenting code that is Google Style compliant

Code documentation comes in many forms for many audiences. For this project, **your audience is other programmers**, who need to understand class interfaces, function parameters, function behavior, code organization, class organization, and code logic. Self-documenting code (i.e. using good organization and naming conventions) is an efficient means of communicating, since you have to write the code anyway. _Good_ comments -not too much, not too little- help guide others through the logic and class interfaces. For the larger picture of code and class structure, use UML diagrams and Doxygen-generated (automatic) web pages.

_NOTE: `mainpage.h` will NOT have to be style compliant. Please ignore linter errors on this file. If there is automated feedback running for style and there are still linter errors related to `mainpage.h`. please notify instructional staff._

### 5.1 UML <a name ="5.1">

The UML diagram is a visual aid that helps other programmers better understand the code structure. It should include only those aspects that are essential, otherwise your diagram will get too cluttered and overwhelm the reader. Here are some things to keep in mind as you are designing your UML:

- Make the most important classes prominent in the layout (i.e. your eye tends to focus in that general area when you first look at it).
- Lay out the classes so that the connections have as few crossovers as possible.
- Do not include setters and getters in your methods list unless there is something special about them that you need to communicate.
- You should not include structs or enumerated types unless they add value to the understanding of the overall code structure.
- If a class is composed of another class, you can show that association with a solid line arrow (if there is only 1) or using the _compose_ diamond.
- Include cardinality where appropriate.
- Add comments to classes and/or relationships to clarify the interaction or to point out subtleties that are essential to using the code.

The iteration 1 UML should reflect the changes you made while completing the code requirements. We will be looking for proper use of UML components, and a correct depiction of the code structure.

There are many free tools that you can use to create the UML. **Submit your UML as a .pdf file.**  If you cannot save your UML diagram directly to a PDF format, take a picture of it, embed the picture in a Microsoft word document, save the document as a PDF and submit it.

### 5.2 Doxygen <a name ="5.2">

Doxygen automatically generates documentation of class and code structure when you follow some simple conventions for commenting within your code (_see_ http://www.doxygen.nl/manual/docblocks.html and other references in section 9 below). We will be discussing Doxygen in class and in lab. To start with, look over the documentation provided with the code base to understand how to document classes, methods, parameters, and even _todo's_ and _bugs_ in your code. In lab, you learned how to compile with your Doxyfile and generate web pages. Please look over the generated web pages for missing and incorrect information. The requirements for Doxygen include:

- the file `/docs/Doxyfile` to generate documentation (this file is provided, so you shouldn't have to do anything with regard to this requirement).

- a `mainpage.h` file that serves as the homepage of your automated documentation. This is an introduction to the code to other programmers who might be new to the project and need to understand it to contribute to the project.

- fully documented classes and methods.

- The `/html` directory should *not* be in your repo in github.

> As part of your fresh clone prior to submission, please also compile the Doxygen and look at the generated webpages.

All of these elements of documentation will be assessed, accounting for a significant portion of your grade for each iteration (for this iteration - iteration 1, documentation will account for 1/2 of your grade). Think about these two extremes: 1) your code functions perfectly and you have almost no documentation - you will likely fail on this iteration; 2) your code is not functional and will only compile when you comment most of it out, but if you have complete, great documentation - you will likely get a decent grade on this iteration. Get in the habit of creating the documentation along with the code.

<hr>

## 6. Assessment <a name ="6">

Your software **must compile on a cselabs machine or it will not be graded, and you will receive a zero for your submission**. We will not grade your project unless it compiles. As long as you provide a version that compiles, we will evaluate those aspects that are partially functional for partial credit. In other words, <u>comment it out if it breaks compilation</u>.

Your software will be assessed through automatic testing and by the TAs. You will receive immediate feedback whenever you push to github (although not now - we will let you know when those scripts are in place). At the deadline, all submissions will be downloaded and the automated testing will no longer be available. Through both automated testing and the TAs, the process for testing will be to `make clean` then `make`. We **highly encourage** you too freshly clone your repo on a **CSELABs machine** and to then `make clean` and `make`, followed by a run of your tests to confirm all is working well before submitting your tests and code.

This is the breakdown for point distribution:

**20% : Iteration \#1**
- 10% : UML (base code, draft). Refine for submission with Final Documentation.
- 10% : Preliminary Testing Submission
- 40% : Final Documentation
- 40% : Final Code

### 6.1 Documentation Assessment ( 50% ) <a name ="6.1">

#### 6.1.1 Draft of UML Diagram ( 10% ) <a name ="6.1.1">

**Preliminary Deliverable #1** will require you to turn in a UML diagram of the project code. You will depict project code you've already been given, but also your proposed solution structure for the entities that you'll be developing in this iteration. **__At this point in time, the reality is that it is YOU who needs to understand the code we have provided,  and this exercise will be a tremendous help in that regard, saving you hours when you start to code.__**  Keep in mind that UML is a visual aid and should include only those aspects that are essential, otherwise your diagram will get too cluttered and overwhelming to the reader. Keep in mind that you can add notes and clarification within the document.

This is a draft of the final product, and we anticipate that it will be revised and improved. We will be looking for general proper use of UML syntax, and a correct depiction of the code structure of the existing project code (code from shared-upstream's support-code branch). **Submit your Prelimary Deliverable 1 UML diagram as a .pdf file through the Iteration 1 Preliminary Deliverable 1 item on the class Canvas site. Your diagram should be named: UML_DRAFT**.

#### 6.1.2 Complete Iteration Documentation ( 40% ) <a name ="6.1.2">

##### 6.1.2a Design Document and UML <a name ="6.1.2a">

Documentation includes a design overview of the core domain elements (the classes you're building) provided in mainpage.h in /src and your final UML diagram saved in /docs. **The UML diagram you submit with your final submission for the iteration should reside in a file named: UML_FINAL_1.** The mainpage overview should be written in prose and be at least 1 page of text (if it were on an 8.5x11 paper), probably not more than 2. It should highlight important design elements, such as the separation of the graphics from the simulator, and the structure of your domain elements. We will
look for a well written and well organized document that clearly articulates the design. It must stand alone in the
sense that anyone reading it should not have to look at code to understand the design. This may require images of UML and/or snippets of code included.

##### 6.1.2b Google Style Compliance <a name ="6.1.2b">

We will run the automated test using 'cpplint' to check compliance. There are a few additional elements for compliance that _cpplint_ does not check for, thus TAs will inspect for those. In general, minor or isolating deviations from the Google Style guide are acceptable. Significant and persistent variations, however, will be docked.

##### 6.1.2c Doxygen Documentation <a name ="6.1.2c">

We will compile the code to generate _Doxygen_ web pages. All classes and major functions must be documented as specified in the _Doxygen_ documentation.

##### 6.1.2d GitHub Issues <a name ="6.1.2d">

Your repository must include Issues that communicate to the TAs. If there are no bugs in your code, include a GitHub Issue that states that there are no known bugs to report  and that further verification is necessary (never say that there aren't bugs, because we know that that is typically not the case :-). We anticipate that a few bugs will exist in your project and they will reveal themselves during testing. If you have a few bugs AND you report them, then you will lose fewer points than if you don't report them - provided the bugs aren't preventing the simulation from running to completion. Also, keep in mind that development will continue throughout the semester, and if you can't fix your code this iteration, you might have an opportunity in the next one, so keep use github to keep track of all your bugs.

##### 6.1.2e Self-Documenting Code <a name ="6.1.2e">

TAs will inspect code for good naming conventions, good code organization, and internal comments to highlight logic. You should not nest conditional statements too deep. Methods should not be more than a screen full, if possible. Names should be descriptive of the variable's or function's purpose. Like elements should be next to each other in the file.

### 6.2 Code Assessment ( 50% ) <a name ="6.2">

#### 6.2.1 Preliminary Testing Submission ( 10% ) <a name ="6.2.1">

In the week prior to the due date of the completed iteration, we will confirm that you have submitted work for **Preliminary Deliverable #2**. You must include at least three (3) unit tests of your Passenger class to receive full points for the preliminary submission. There will be no manual inspection of the code at this point -- it is strictly a test for completed functionality and testing. We will ensure that your tests are effective using automatic means, similar to the Testing lab. There will be transparency in this process in that you will know what functionality will be tested, and you will see the results. Points earned at this stage are independent of the 40% points for the final submission.

**Please add your tests to the `passenger_UT.cc` file already given to you within the testing directory. Any additional testing files will not be inspected.**

#### 6.2.2 Completed Iteration Code ( 40% ) <a name ="6.2.2">

Code functionality will be tested with automated tests through Github, which in turn run the automated unit tests of Google Test. We expect to have basic feedback running by the end of week two of Iteration 1. In that case, you will see _some_ of the elements we'll be testing in our assessment. Review the automated feedback prior to final submission, as it will identify any issues with directory structure, compilation issues, or failed unit tests. Assessment will also include a visual inspection of the simulation and its output, as well as a visual inspection of the code.

<hr>

## 7. Getting Started <a name ="7">

**AFTER** reading this document, pull the shared class repository to obtain the base code and merge it into your `devel` branch. Remember that you should _not_ be working within `master` during each iteration. Refer back to Lab 10 if you are still confused about branches and branching.

<hr>

## 8. Important notes to remember <a name ="8">

```
Your software is a reflection of your understanding of the requirements as specified in this document. 
If you do not understand any portion of the requirements or you think that the requirements are 
underspecified, it is your responsibility to get clarification from the instructor or a TA. Please read 
this document carefully and review it prior to turning in your iteration for assessment.
```
```
The ONLY supported environment is the CSELabs environment. This is where we will run your code for 
assessment, and where you should absolutely ensure that your project will compile and run. It is 
recommended to log onto a CSELabs machine, do a **clean** pull of your repo (i.e., pull into a brand new 
directory), and then build and test your project.
```

<hr>

## 9. Resources <a name ="9">

Local System and Compilation:
- Repo: https://github.umn.edu/umn-csci-3081-f19/csci3081-shared-upstream
- Compilation: https://gcc.gnu.org/
- Linux quick reference: http://www-users.cs.umn.edu/~larson/repo-website-resources/website/examples/csresources/linux.html
- Makefile Resources: http://www-users.cs.umn.edu/~larson/repo-website-resources/website/examples/csresources/cpp.html

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
