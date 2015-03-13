#
# Based on Makefile from <URL: http://hak5.org/forums/index.php?showtopic=2077&p=27959 >

PROGRAM = backertrap-ada
BOARD = XMEGA256A3

############# Main application #################
all:    $(PROGRAM)
.PHONY: all

# source files
PCH = pch.h
DEBUG_INFO = YES
SOURCES = $(shell find . -name '*.cpp')
OBJECTS = $(SOURCES:.cpp=.o)
DEPS = $(OBJECTS:.o=.dep)

######## compiler- and linker settings #########
CPP = avr-g++
CPPFLAGS = -D$(BOARD) -W -Wall -Werror -pipe -I/usr/lib/avr/include
LIBSFLAGS = -L/usr/lib/avr/lib
ifdef PCH
 CPPFLAGS += -DPRECOMP
endif
ifdef DEBUG_INFO
 CPPFLAGS += -g
else
 CPPFLAGS += -O
endif

ifdef PCH
%.o: %.cpp $(PCH).gch
else
%.o: %.cpp
endif
	$(CPP) $(CPPFLAGS) -o $@ -c $<

%.dep: %.cpp
	$(CPP) $(CPPFLAGS) -MM $< -MT $(<:.cpp=.o) > $@

############ Precompiled header ################
ifdef PCH
$(PCH).gch: $(PCH)
	$(CPP) -x c++ -c $(PCH) -o $(PCH).gch $(CPPFLAGS)
endif

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
ifdef PCH
	-rm -f $(PCH).gch
endif
