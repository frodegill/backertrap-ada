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
CSRC = $(shell find . -name '*.c')
ASM_SRC = ./3rd-party/Atmel/xmega/applications/xmega_a3bu_xplained_demo/qtouch/qt_asm_xmega.s \
          ./3rd-party/Atmel/xmega/drivers/cpu/ccp.s \
          ./3rd-party/Atmel/xmega/drivers/nvm/nvm_asm.s
OBJECTS = $(SRC:.cpp=.o) $(CSRC:.c=.o) $(ASM_SRC:.s=.o)
LISTING = $(SRC:.cpp=.lst) $(CSRC:.c=.lst) $(ASM_SRC:.s=.lst)
DEPS = $(OBJECTS:.o=.dep)

##########

CC  = avr-gcc
CPP = avr-g++
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
SIZE = avr-size
NM = avr-nm
LD = avg-gcc

CXX_FLAGS = -DBOARD=$(BOARD) \
            -D CONFIG_NVM_IGNORE_XMEGA_A3_D3_REVB_ERRATA \
            -D GFX_MONO_C12832_A1Z=1 \
            -D IOPORT_XMEGA_COMPAT \
            -D NUMBER_OF_PORTS=1 \
            -D QTOUCH_STUDIO_MASKS=1 \
            -D QT_DELAY_CYCLES=1 \
            -D QT_NUM_CHANNELS=4 \
            -D SNS=F \
            -D SNSK=F \
            -D _QTOUCH_ \
            -D _SNS1_SNSK1_SAME_PORT_ \
            -mmcu=$(MCU) -DF_CPU=32000000l -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums \
            -W -Wall -pipe \
            -I/usr/lib/avr/include \
            -I. \
            -isystem ./3rd-party/Atmel \
            -isystem ./3rd-party/Atmel/common/boards \
            -isystem ./3rd-party/Atmel/common/components/display/st7565r \
            -isystem ./3rd-party/Atmel/common/services/clock \
            -isystem ./3rd-party/Atmel/common/services/delay \
            -isystem ./3rd-party/Atmel/common/services/gpio \
            -isystem ./3rd-party/Atmel/common/services/ioport \
            -isystem ./3rd-party/Atmel/common/services/sleepmgr \
            -isystem ./3rd-party/Atmel/common/services/spi \
            -isystem ./3rd-party/Atmel/common/utils \
            -isystem ./3rd-party/Atmel/xmega/boards \
            -isystem ./3rd-party/Atmel/xmega/boards/xmega_a3bu_xplained \
            -isystem ./3rd-party/Atmel/xmega/drivers/cpu \
            -isystem ./3rd-party/Atmel/xmega/drivers/pmic \
            -isystem ./3rd-party/Atmel/xmega/drivers/sleep \
            -isystem ./3rd-party/Atmel/xmega/drivers/usart \
            -isystem ./3rd-party/Atmel/xmega/utils \
            -isystem ./3rd-party/Atmel/xmega/utils/preprosessor
ifdef DEBUG_INFO
 CXX_FLAGS += -g
else
 CXX_FLAGS += -O
endif

CC_FLAGS = $(CXX_FLAGS) -std=gnu99

CPP_FLAGS = $(CXX_FLAGS) -DHIDE_UNUSED_PARAMS -Werror

ASM_FLAGS = -mmcu=$(MCU) -x assembler-with-cpp -Wa,-adhlns=$(<:.s=.lst),-gstabs

LIBS_FLAGS = -L/usr/lib/avr/lib \
             -L./3rd-party/Atmel/xmega/applications/xmega_a3bu_xplained_demo/qtouch

LIBS = -lavrxmega6g1-4qt-k-0rs

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

%.dep: %.c
	$(CC) $(CC_FLAGS) -MM $< -MT $(<:.c=.o) > $@

%.dep: %.s

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -o $@ -c $<

%.o: %.c
	$(CC) $(CC_FLAGS) -o $@ -c $<

%.o: %.s
	$(CPP) $(ASM_FLAGS) -o $@ -c $<

%.elf: $(DEPS) $(OBJECTS)
	$(LD) $(CPP_FLAGS) $(OBJECTS) --output $@ $(LIBS) $(LIBS_FLAGS)

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
