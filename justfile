c_flags_one := "-c -fPIC -Wall -Wextra -Wpedantic -O2"
c_flags_two := "-shared"
# ld_flags := ":w-lm"
src := "src"
build := "build"
object := "object"
bin := "bin"
target := "libexo"

# just commands
build:
    just clean
    mkdir {{build}}
    mkdir {{build}}/{{object}}
    mkdir {{build}}/{{bin}}
    cc {{c_flags_one}} {{src}}/*.c
    mv *.o {{build}}/{{object}}
    cc {{c_flags_two}} -o {{build}}/{{bin}}/{{target}} {{build}}/{{object}}/*.o
    
run:

build-run:

clean:
    rm -rf {{build}}
