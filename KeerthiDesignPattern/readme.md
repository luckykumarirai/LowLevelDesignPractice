# how to make library in c++

# compile file create o ffile

## g++ -c car.cpp bike.cpp

# comile to create archive that create library

## ar rcs vehicle_libraray.a car.o bike.o

# run code using libraray

## g++ -o cleint client.cpp vehicle_libraray.a
