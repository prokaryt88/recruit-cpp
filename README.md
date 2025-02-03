# C++ Coding Excercise

## Phase 1
Follow the prompts in stats.cpp to perform the following:
1. Read a sequence of integers from standard input. Stop at EOF or
   invalid input.
2. Populate a Stats class with the sum, max, and average (as a double) 
   of the input.
3. Print the count, sum, max, and average of the input to standard output.

## Phase 2
Create a minimal unit test for the Stats calcuator. Cover at least 3 interesting
input vectors. Modify main() so that:
- If no arguments are provided, the program behaves as it did in phase 1.
- If "--test" is provided, run the unit tests, print a summary, and exit with
  code 0 if all tests pass, 1 if any fail.

## Docker

The example has been tested with the gcc:14-bookworm Docker image. You may
find it useful to use this to ensure a consistent environment and minimize
changes to your system. The following will run an ephemeral container to
build and run the example.

    docker run --rm -it -u $(id -u):$(id -g) -v $(pwd):/app \
               -w /app gcc:14-bookworm \
               sh -c 'make && ./stats < sample.txt'
