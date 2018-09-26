################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Pruebas/PruebasElZarzal.cpp \
../src/Pruebas/PruebasEstudiante.cpp \
../src/Pruebas/PruebasEstudiantes.cpp \
../src/Pruebas/PruebasGestorEstudiantes.cpp \
../src/Pruebas/PruebasListaEstudiantes.cpp \
../src/Pruebas/PruebasSolicitud.cpp \
../src/Pruebas/PruebasSolicitudes.cpp \
../src/Pruebas/PruebasTitulacion.cpp \
../src/Pruebas/PruebasTitulaciones.cpp 

OBJS += \
./src/Pruebas/PruebasElZarzal.o \
./src/Pruebas/PruebasEstudiante.o \
./src/Pruebas/PruebasEstudiantes.o \
./src/Pruebas/PruebasGestorEstudiantes.o \
./src/Pruebas/PruebasListaEstudiantes.o \
./src/Pruebas/PruebasSolicitud.o \
./src/Pruebas/PruebasSolicitudes.o \
./src/Pruebas/PruebasTitulacion.o \
./src/Pruebas/PruebasTitulaciones.o 

CPP_DEPS += \
./src/Pruebas/PruebasElZarzal.d \
./src/Pruebas/PruebasEstudiante.d \
./src/Pruebas/PruebasEstudiantes.d \
./src/Pruebas/PruebasGestorEstudiantes.d \
./src/Pruebas/PruebasListaEstudiantes.d \
./src/Pruebas/PruebasSolicitud.d \
./src/Pruebas/PruebasSolicitudes.d \
./src/Pruebas/PruebasTitulacion.d \
./src/Pruebas/PruebasTitulaciones.d 


# Each subdirectory must supply rules for building sources it contributes
src/Pruebas/%.o: ../src/Pruebas/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


