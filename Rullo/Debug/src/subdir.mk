################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Casilla.cpp \
../src/Pruebas_Casilla.cpp \
../src/Pruebas_Tablero.cpp \
../src/Tablero.cpp \
../src/entorno.cpp \
../src/juego.cpp \
../src/uexRulloBase.cpp 

OBJS += \
./src/Casilla.o \
./src/Pruebas_Casilla.o \
./src/Pruebas_Tablero.o \
./src/Tablero.o \
./src/entorno.o \
./src/juego.o \
./src/uexRulloBase.o 

CPP_DEPS += \
./src/Casilla.d \
./src/Pruebas_Casilla.d \
./src/Pruebas_Tablero.d \
./src/Tablero.d \
./src/entorno.d \
./src/juego.d \
./src/uexRulloBase.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


