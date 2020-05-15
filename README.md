**NOTE**: Please make sure that **all Tests** pass before pushing any changes. 

### Run Tests:

- cd `tests`
- `make`
- `../build/bin/unittest`

### Style Check:

- `[path_to_cpplint]/cpplint/cpplint-cse.sh --root=[path_target_dir] [file_name]`


### Running the Simulator:

#### Step by step for CSE Labs or vole users

**<port_number> can be anything. Try and pick numbers above 8000 and not multiples of 10.**

1. Navigate to base project directory(project/)  
2. Make and start server:
```
$ cd src
$ make <sim target>
$ cd ..
$./build/bin/<sim executable> <port_number>
```
#### You must run by doing `./build/bin/<sim executable> <port_number>`.
#### You _cannot_ cd to bin/ and run `./<sim executable> <port_number>`
3. Navigate to the following address on your VOLE browser (Firefox/Chrome):
```
http://127.0.0.1:<port_number>/web_graphics/project.html
```
  
#### Step by step for ssh users
You can SSH using a Windows machine with Git Bash.
```
ssh -L <port number>:127.0.0.1:<port_number> <x500>@<cse_labs_computer>.cselabs.umn.edu
```
**<port_number> can be anything. Try and pick numbers above 8000 and not multiples of 10.**

1. Navigate to base project directory(project/)  
2. make and start server:
```
$ cd src
$ make <sim target>
$ cd ..
$./build/bin/<sim executable> <port_number>
```
#### You must run by doing `./build/bin/<sim executable> <port_number>`.
#### You _cannot_ cd to bin/ and run `./<sim executable> <port_number>`
3. Navigate to the following address on your LOCAL machine using your LOCAL browser (Firefox/Chrome):
```
http://127.0.0.1:<port_number>/web_graphics/project.html
```

Note that for lab14, the `sim target` and `sim executable` that you build are both called `vis_sim`. Use `vis_sim` in place of the `<sim target>` and `<sim executable>` arguments above.
