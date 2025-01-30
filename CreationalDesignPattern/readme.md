# Simple Factory 
#### while adding new type of logger we have to made in Logger_factroy so it voilting the open closed priniciple(making change in already existing code)

# how to make library in c++

## compile file create o ffile

### g++ -c car.cpp bike.cpp

## comile to create archive that create library

### ar rcs vehicle_libraray.a car.o bike.o

## run code using libraray

### g++ -o cleint client.cpp vehicle_libraray.a
  