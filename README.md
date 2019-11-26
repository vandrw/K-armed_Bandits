## How to Run
To run the code, go to a terminal, set the present working directory as K-armed_Bandits and run the following commands:

```
make
make run
```

## Project Structure
* __bin__: The output executables will appear here.
* __build__: This folder contains all object files, and is removed on a `make clean`.
* __include__: All project header files. All necessary third-party header files that do not exist under /usr/local/include are also placed here.
* __src__: The application and only the application’s source files.

## TO DO
- [x] Implement user interaction
- [ ] Implement Gaussian (normal) and Bernoulli distribution
- [ ] Implement Exporation/ Exploitation using:
    - [ ] Epsilon-Greedy
    - [ ] Optimistic initial values
    - [ ] Reinforcement comparison
    - [ ] Boltzmann exploration 
