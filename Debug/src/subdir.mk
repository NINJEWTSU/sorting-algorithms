################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BubbleSort.cpp \
../src/sorting\ algorithms.cpp 

OBJS += \
./src/BubbleSort.o \
./src/sorting\ algorithms.o 

CPP_DEPS += \
./src/BubbleSort.d \
./src/sorting\ algorithms.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sorting\ algorithms.o: ../src/sorting\ algorithms.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/sorting algorithms.d" -MT"src/sorting\ algorithms.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


