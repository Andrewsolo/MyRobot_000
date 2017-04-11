################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../include/ \
../include/libraries/ \
../include/libraries/Servo/ \
../include/libraries/Servo/src/ \
../include/libraries/Servo/src/avr/ \
../src/ \
../src/libraries/ \
../src/libraries/Servo/ \
../src/libraries/Servo/src/ \
../src/libraries/Servo/src/avr/


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../Main.cpp \
../Motor.cpp \
../Motors.cpp \
../NewPing.cpp \
../SerialTask.cpp \
../ServoTask.cpp \
../src/libraries/Servo/src/avr/Servo.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
Main.o \
Motor.o \
Motors.o \
NewPing.o \
SerialTask.o \
ServoTask.o \
src/libraries/Servo/src/avr/Servo.o

OBJS_AS_ARGS +=  \
Main.o \
Motor.o \
Motors.o \
NewPing.o \
SerialTask.o \
ServoTask.o \
src/libraries/Servo/src/avr/Servo.o

C_DEPS +=  \
Main.d \
Motor.d \
Motors.d \
NewPing.d \
SerialTask.d \
ServoTask.d \
src/libraries/Servo/src/avr/Servo.d

C_DEPS_AS_ARGS +=  \
Main.d \
Motor.d \
Motors.d \
NewPing.d \
SerialTask.d \
ServoTask.d \
src/libraries/Servo/src/avr/Servo.d

OUTPUT_FILE_PATH +=MyRobot_000.elf

OUTPUT_FILE_PATH_AS_ARGS +=MyRobot_000.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+=  \
C:/AVR/Projects/MyRobot_000/MyRobot_000/ArduinoCore/Debug/libArduinoCore.a

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler















./%.o: .././%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 4.9.2
	$(QUOTE)C:\AVR\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=16000000L -DARDUINO=10800 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x0043 -DUSB_MANUFACTURER="\"Arduino LLC\""  -I"C:\AVR\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.1.130\include" -I"..\\..\ArduinoCore\include\core" -I"..\\..\ArduinoCore\include\variants\standard" -I"..\include\libraries\Servo\src" -I"..\include\libraries\Servo\src\avr" -I"..\include\libraries\Servo\src\sam" -I"..\include\libraries\Servo\src\samd"  -Os -fno-threadsafe-statics -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -w -mmcu=atmega328p -B "C:\AVR\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.1.130\gcc\dev\atmega328p" -c -std=gnu++11 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/libraries/Servo/src/avr/%.o: ../src/libraries/Servo/src/avr/%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 4.9.2
	$(QUOTE)C:\AVR\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=16000000L -DARDUINO=10800 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x0043 -DUSB_MANUFACTURER="\"Arduino LLC\""  -I"C:\AVR\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.1.130\include" -I"..\\..\ArduinoCore\include\core" -I"..\\..\ArduinoCore\include\variants\standard" -I"..\include\libraries\Servo\src" -I"..\include\libraries\Servo\src\avr" -I"..\include\libraries\Servo\src\sam" -I"..\include\libraries\Servo\src\samd"  -Os -fno-threadsafe-statics -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -w -mmcu=atmega328p -B "C:\AVR\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.1.130\gcc\dev\atmega328p" -c -std=gnu++11 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR8/GNU Linker : 4.9.2
	$(QUOTE)C:\AVR\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="MyRobot_000.map" -Wl,--start-group -Wl,-lm -Wl,-lArduinoCore  -Wl,--end-group -Wl,-L"C:\AVR\MyProjects\MyRobot_000\MyRobot_000\MyRobot_000" -Wl,-L"C:\Users\ANSO\Documents\Arduino\libraries\NewPing" -Wl,-L"C:\AVR\Projects\MyRobot_000\MyRobot_000\ArduinoCore\Debug"  -Wl,--gc-sections -mmcu=atmega328p -B "C:\AVR\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.1.130\gcc\dev\atmega328p" -Os  
	@echo Finished building target: $@
	"C:\AVR\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "MyRobot_000.elf" "MyRobot_000.hex"
	"C:\AVR\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "MyRobot_000.elf" "MyRobot_000.eep" || exit 0
	"C:\AVR\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "MyRobot_000.elf" > "MyRobot_000.lss"
	"C:\AVR\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "MyRobot_000.elf" "MyRobot_000.srec"
	"C:\AVR\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "MyRobot_000.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "MyRobot_000.elf" "MyRobot_000.a" "MyRobot_000.hex" "MyRobot_000.lss" "MyRobot_000.eep" "MyRobot_000.map" "MyRobot_000.srec" "MyRobot_000.usersignatures"
	