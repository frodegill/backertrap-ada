#
# Based on Makefile from <URL: http://hak5.org/forums/index.php?showtopic=2077&p=27959 >

PROGRAM = backertrap-ada
BOARD = XMEGA256A3

############# Main application #################
all:    $(PROGRAM)
.PHONY: all

# source files
DEBUG_INFO = YES
SOURCES = $(shell find . -name '*.cpp')
OBJECTS = $(SOURCES:.cpp=.o)
DEPS = $(OBJECTS:.o=.dep)

######## compiler- and linker settings #########
CPP = avr-g++
CPPFLAGS = -D$(BOARD) -W -Wall -Werror -pipe -I/usr/lib/avr/include
LIBSFLAGS = -L/usr/lib/avr/lib
ifdef DEBUG_INFO
 CPPFLAGS += -g
else
 CPPFLAGS += -O
endif

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -o $@ -c $<

%.dep: %.cpp
	$(CPP) $(CPPFLAGS) -MM $< -MT $(<:.cpp=.o) > $@

############# Main application #################
$(PROGRAM):	$(OBJECTS) $(DEPS)
	$(CPP) -o $@ $(OBJECTS) $(LIBSFLAGS)

################ Dependencies ##################
ifneq ($(MAKECMDGOALS),clean)
include $(DEPS)
endif

################### Clean ######################
clean:
	find . -name '*~' -delete
	-rm -f $(PROGRAM) $(OBJECTS) $(DEPS)
