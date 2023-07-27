#!/bin/bash

run_mysed() {
	original_file="$1"
	s1="$2"
	s2="$3"

	./mysed "$original_file" "$s1" "$s2"

	if [ $? -eq 0 ]; then
		echo "ok!"
	fi
}

# Create folder structure
for i in {1..8}; do mkdir -p "tests/test$i"; done


# Test 1
original_file="tests/test1/test"
s1="Karma"
s2="Kermit"

echo "Cause Karma is my boyfriend, Karma is a God
Karma is the breeze in my hair on the weekend
Karma's a relaxing thought
Aren't you envious that for you it's not?
Sweet like honey, Karma is a cat
Purring in my lap 'cause it loves me
Flexing like a Goddamn acrobat
Me and Karma vibe like that" > "$original_file"

echo "Test 1: Replace a word"

run_mysed "$original_file" "$s1" "$s2"
echo ""

##########################################################################

# Test 2
original_file="tests/test2/test"
s1="a"
s2=" "

echo "Got a long list of ex-lovers
They'll tell you I'm insane
But I've got a blank space, baby
And I'll write your name" > "$original_file"

echo "Test 2: s2 is blank space"

run_mysed "$original_file" "$s1" "$s2"
echo ""

##########################################################################

# Test 3
original_file="tests/test3/test"
s1="o"
s2=""

echo "If you could see that I'm the one who understands you
Been here all along, so why can't you see?
You belong with me
You belong with me" > "$original_file"

echo "Test 3: s2 is empty"

run_mysed "$original_file" "$s1" "$s2"
echo ""

##########################################################################

# Test 4
original_file="tests/test4/test"
s1="a"
s2="b"

touch "$original_file"

echo "Test 4: Empty file"

run_mysed "$original_file" "$s1" "$s2"
echo ""

##########################################################################

echo "**************************** Error handler tests ****************************"
echo ""

# Test 5
original_file="tests/test5/test"
s1=""
s2="a"

echo "Nothing should happen here" > "$original_file"

echo "Test 5: s1 is empty"

run_mysed "$original_file" "$s1" "$s2"
echo ""

##########################################################################

# Test 6
original_file="tests/test6/test"
s1="a"
s2="b"

echo "Nothing should happen here" > "$original_file"

echo "Test 6: Invalid file"

run_mysed "invalid" "$s1" "$s2"
echo ""

##########################################################################

# Test 7
original_file="tests/test7/test"
s1="a"
s2="b"

mkdir "$original_file"

echo "Test 7: Is a directory"

run_mysed "$original_file" "$s1" "$s2"
echo ""

##########################################################################

# Test 8
original_file="tests/test8/test"
s1="a"
s2="b"

echo "Nothing should happen here" > "$original_file"

echo "Test 8: Invalid number of args"

./mysed "$original_file" "$s1" "$s2" "invalid arg"
echo ""

##########################################################################
