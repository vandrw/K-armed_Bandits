## How to Run
To run the code, go to a terminal, set the present working directory as K-armed_Bandits and run the following commands:

```
make
make run
```

If you wish to create all the data at once and show a graph for each problem, run the command:
```
make all
```
This might take between 5 and 10 minutes, depending on hardware.

## Project Structure
* __bin__: The output executables will appear here.
* __build__: This folder contains all object files, and is removed on a `make clean`.
* __data__: The data created by the program is saved here as a csv file.
* __docs__: The graphs and other resources regarding the description go here.
* __include__: All project header files. All necessary third-party header files that do not exist under /usr/local/include are also placed here.
* __src__: The application and only the application’s source files.
