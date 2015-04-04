TARGET = test

RAW = $(wildcard ../*.cpp *.cpp)
SOURCES = $(notdir $(RAW))
OBJECTS = $(SOURCES:.cpp=.o)
DEPS = $(SOURCES:.cpp=.d)

LIBS = /home/hoping/Downloads/gumbo-parser-master/libgumbo.a
INCLUDES += -I/home/hoping/Downloads/gumbo-parser-master/src -I..

%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ $(INCLUDES) -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: %.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ $(INCLUDES) -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
#-include $(DEPS)

all: $(TARGET)

# Tool invocations
$(TARGET): $(OBJECTS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++  -o "$(TARGET)" $(OBJECTS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJECTS) $(DEPS) $(TARGET)
	-@echo ' '

.PHONY: all clean
.SECONDARY:
