clear
g++ -std=c++17 -Wall -Wshadow -Wfatal-errors $1 -o ~/Documents/contest/out
~/Documents/contest/out < ~/Documents/contest/input.in
rm ~/Documents/contest/out
exit 0
