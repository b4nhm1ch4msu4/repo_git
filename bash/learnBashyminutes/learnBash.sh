#!/usr/bin/env bash

echo "hello world !!!"
################
### Variable ###
################
name="Tien Teo Mike"
# space around = is not allowed
# name = "mike" => error
echo $name # can work but not recommended
echo "$name"
echo '$name' # => Dont work with single quote ''

#################################
### Parameter expansion ${..} ###
#################################

# get value of a variable
echo "${name}"

# during 'expands' time, the value can be modified.
# String substitution
echo "${name/T/M}"

# substring from a variable
leng=10
echo "${name:0:5}"
echo "${name:0:leng}" # print "leng" characters from first (0) position
echo "${name: -5}"    # 5 last characters (space 󱁐 before is mandatory)

# string length:
str_leng="${#name}"
echo "$str_leng"

# indirect expansion
name_alias="name"
echo "${!name_alias}" # expand the value of name_alias

# default value
unknow_var=
echo "${unknow_var:-"default value"}" # work with empty string and null value (unknow_var=)
# that dont change value of variable, (still is null)
echo $unknow_var # dont work with 0, it will return 0.

# array
# Declare an array
arr=(one two three four five six)

echo "${arr[2]}"     # Print specific element
echo "${arr[@]}"     # Print all elements
echo "${arr[@]:2:4}" # get all elements then print 4 elements from 2 position (base 0)
echo "${#arr[@]}"    # print the number of elements
echo "${#arr[3]}"    # print the number of characters of four element
for item in "${arr[@]}"; do
  echo "$item"
done

##########################
### Build-in variables ###
##########################
echo "Last program's return value: $?"
echo "Script's PID: $$"
echo "Number of args passed to script: $#"
echo "All args passed to script: $@"
# echo "Script's arg sperated into different variable: $1 $2 ..."
