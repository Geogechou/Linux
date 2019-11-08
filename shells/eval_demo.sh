# this shell script about that use eval command to execute input string
a=100
b=200
echo input a eval expression
read line
eval "$line"
echo "the result is"
echo $result
