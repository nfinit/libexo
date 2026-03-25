# Variables #

c_flags_one := "-c -fPIC -Wall -Wextra -Wpedantic -O2"
c_flags_two := "-shared"
c_flags_test := "-Wall -Wextra -Wpedantic -O2"
src := "src"
build := "build"
object := "object"
bin := "bin"
build_target := "libexo"
test := "test"
test_target := "libexo_test"

# Aliases #

alias b := build
alias r := run
alias br := build-run
alias t := test

# Regular commands #

default:
    just --list

# Builds the libexo library
build:
    just clean
    mkdir {{build}}
    mkdir {{build}}/{{object}}
    mkdir {{build}}/{{bin}}
    cc {{c_flags_one}} {{src}}/*.c
    mv *.o {{build}}/{{object}}
    cc {{c_flags_two}} -o {{build}}/{{bin}}/{{build_target}} {{build}}/{{object}}/*.o

# Runs the libexo executable    
run:

# Builds the libexo library and runs the executable
build-run:

# Removes old build directory
clean:
    rm -rf {{build}}

# Test commands #

# Runs libexo tests
test:
    just test-build
    just test-run

[private]
test-build:
    just clean
    mkdir {{build}}
    mkdir {{build}}/{{test}}
    cc {{c_flags_test}} {{test}}/*.c {{src}}/frontend/colour_print.c -o {{build}}/{{test}}/{{test_target}}

[private]
test-run:
    ./{{build}}/{{test}}/{{test_target}}
    
