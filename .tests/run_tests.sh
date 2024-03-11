#!/bin/bash

# Compile and run tests for your library

# Set paths
LIBRARY_DIR="."
INCLUDE_DIR="."
TESTS_DIR=".tests"

# Compile test files
compile_tests() {
    echo "Compiling tests..."
    for test_file in $TESTS_DIR/*.c; do
        test_name=$(basename $test_file .c)
        echo "Compiling $test_name..."
        cc -o .tests/$test_name $test_file -I$INCLUDE_DIR -L$LIBRARY_DIR -lft
        if [ $? -ne 0 ]; then
            echo "Compilation failed for $test_name"
            exit 1
        fi
    done
}

# Run tests
run_tests() {
    echo "Running tests..."
    for test_executable in $TESTS_DIR/test_*; do
        if [ -x $test_executable ]; then
            echo "Running $test_executable..."
            ./$test_executable
            rm $test_executable
        fi
    done
}

# Main function
main() {
    compile_tests
    run_tests
}

# Run main function
main
