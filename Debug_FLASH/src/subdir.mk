################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/CLOCK.c \
../src/FTM.c \
../src/GPIO.c \
../src/LPUART.c \
../src/NVIC.c \
../src/function.c \
../src/main.c 

OBJS += \
./src/CLOCK.o \
./src/FTM.o \
./src/GPIO.o \
./src/LPUART.o \
./src/NVIC.o \
./src/function.o \
./src/main.o 

C_DEPS += \
./src/CLOCK.d \
./src/FTM.d \
./src/GPIO.d \
./src/LPUART.d \
./src/NVIC.d \
./src/function.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/CLOCK.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


