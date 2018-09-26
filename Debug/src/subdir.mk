################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ColecionEstudiantes.cpp \
../src/EDI2015-16.cpp \
../src/ElZarzal.cpp \
../src/Estudiante.cpp \
../src/Estudiantes.cpp \
../src/ListaEstudiantes.cpp \
../src/Solicitud.cpp \
../src/Solicitudes.cpp \
../src/Titulacion.cpp \
../src/Titulaciones.cpp \
../src/uifiles.cpp 

OBJS += \
./src/ColecionEstudiantes.o \
./src/EDI2015-16.o \
./src/ElZarzal.o \
./src/Estudiante.o \
./src/Estudiantes.o \
./src/ListaEstudiantes.o \
./src/Solicitud.o \
./src/Solicitudes.o \
./src/Titulacion.o \
./src/Titulaciones.o \
./src/uifiles.o 

CPP_DEPS += \
./src/ColecionEstudiantes.d \
./src/EDI2015-16.d \
./src/ElZarzal.d \
./src/Estudiante.d \
./src/Estudiantes.d \
./src/ListaEstudiantes.d \
./src/Solicitud.d \
./src/Solicitudes.d \
./src/Titulacion.d \
./src/Titulaciones.d \
./src/uifiles.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


