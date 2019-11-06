################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Horizontal_Controller.cpp \
../src/PID_v1.cpp \
../src/Sub_Controller.cpp \
../src/Thruster_Controller.cpp \
../src/helloworld.cpp 

OBJS += \
./src/Horizontal_Controller.o \
./src/PID_v1.o \
./src/Sub_Controller.o \
./src/Thruster_Controller.o \
./src/helloworld.o 

CPP_DEPS += \
./src/Horizontal_Controller.d \
./src/PID_v1.d \
./src/Sub_Controller.d \
./src/Thruster_Controller.d \
./src/helloworld.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


