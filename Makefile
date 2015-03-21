#
# Based on Makefile from <URL: http://hak5.org/forums/index.php?showtopic=2077&p=27959 >
# and <URL: http://web.mit.edu/pricem/work/6.270/Makefile >
#
# For Makefile documentation, see <URL: http://www.gnu.org/software/make/manual/make.html >

PROGRAM = backertrap-ada
BOARD = XMEGA_A3BU_XPLAINED
MCU = atxmega256a3
DEBUG_INFO = YES
FORMAT = ihex

##########

SRC = $(shell find . -name '*.cpp')
ASM_SRC = $(shell find . -name '*.S')
OBJECTS = $(SRC:.cpp=.o) $(ASM_SRC:.S=.o)
LISTING = $(SRC:.cpp=.lst) $(ASM_SRC:.S=.lst)
DEPS = $(OBJECTS:.o=.dep)

##########

CPP = avr-g++
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
SIZE = avr-size
NM = avr-nm

CPP_FLAGS = -DBOARD=$(BOARD) \
           -mmcu=$(MCU) -DF_CPU=32000000l -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums \
           -W -Wall -Werror -pipe \
           -I/usr/lib/avr/include \
           -I./3rd-party/Atmel \
           -I./3rd-party/Atmel/common/boards \
           -I./3rd-party/Atmel/common/services/clock \
           -I./3rd-party/Atmel/common/services/delay \
           -I./3rd-party/Atmel/common/services/gpio \
           -I./3rd-party/Atmel/common/services/ioport \
           -I./3rd-party/Atmel/common/services/sleepmgr \
           -I./3rd-party/Atmel/common/services/spi \
           -I./3rd-party/Atmel/common/utils \
           -I./3rd-party/Atmel/xmega/boards \
           -I./3rd-party/Atmel/xmega/boards/xmega_a3bu_xplained \
           -I./3rd-party/Atmel/xmega/drivers/cpu \
           -I./3rd-party/Atmel/xmega/drivers/pmic \
           -I./3rd-party/Atmel/xmega/drivers/sleep \
           -I./3rd-party/Atmel/xmega/drivers/usart \
           -I./3rd-party/Atmel/xmega/utils \
           -I./3rd-party/Atmel/xmega/utils/preprosessor
ifdef DEBUG_INFO
 CPP_FLAGS += -g
else
 CPP_FLAGS += -O
endif

ASM_FLAGS = -mmcu=$(MCU) -x assembler-with-cpp -Wa,-adhlns=$(<:.S=.lst),-gstabs

LIBS_FLAGS = -L/usr/lib/avr/lib

##########

all:    build
.PHONY: clean all build elf hex eep lss sym size

build: elf hex eep lss sym size

elf: $(PROGRAM).elf

hex: $(PROGRAM).hex

eep: $(PROGRAM).eep

lss: $(PROGRAM).lss

sym: $(PROGRAM).sym

size: $(PROGRAM).size

%.dep: %.cpp
	$(CPP) $(CPP_FLAGS) -MM $< -MT $(<:.cpp=.o) > $@

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -o $@ -c $<

%.o: %.S
	$(CPP) $(CPP_FLAGS) -o $@ -c $<

%.elf: $(DEPS) $(OBJECTS)
	$(CPP) $(CPP_FLAGS) $(OBJECTS) --output $@ $(LDFLAGS)

%.hex: %.elf
	$(OBJCOPY) -O $(FORMAT) -R .eeprom $< $@

%.eep: %.elf
	-$(OBJCOPY) -j .eeprom --set-section-flags=.eeprom="alloc,load" \
	--change-section-lma .eeprom=0 -O $(FORMAT) $< $@

%.lss: %.elf
	$(OBJDUMP) -h -S $< > $@

%.sym: %.elf
	$(NM) -n $< > $@

%.size: %.elf
	$(SIZE) -A $<

################ Dependencies ##################
ifneq ($(MAKECMDGOALS),clean)
include $(DEPS)
endif

################### Clean ######################
clean:
	find . -name '*~' -delete
	-rm -f $(DEPS) $(OBJECTS) \
		$(PROGRAM) $(PROGRAM).elf $(PROGRAM).hex $(PROGRAM).eep $(PROGRAM).lss $(PROGRAM).sym
