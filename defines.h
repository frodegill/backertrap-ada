#ifndef _DEFINES_H_
#define _DEFINES_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license


#define MAX_PAGE_STACK_SIZE (16)

#ifndef UNUSED_PARAM
# define UNUSED_PARAM(x)
#endif

#if defined(_ASSERT_ENABLE_)
# define ASSERT_PARAM(x) x
#else
# define ASSERT_PARAM(x)
#endif

#if (BOARD == XMEGA_A3BU_XPLAINED)
# include "common/boards/board.h"
# include "common/services/delay/delay.h"
# include "common/services/gpio/gpio.h"
# include "common/services/ioport/ioport.h"
# include "common/services/sleepmgr/sleepmgr.h"
# include "common/services/spi/usart_spi.h"
# include "common/utils/interrupt.h"
# include "xmega/drivers/cpu/xmega_reset_cause.h"
# include "xmega/drivers/nvm/nvm.h"
# include "xmega/drivers/pmic/pmic.h"
# include "xmega/drivers/rtc32/rtc32.h"
# include "common/components/display/st7565r/st7565r.h"
# include "xmega/drivers/sleep/sleep.h"
# include "xmega/drivers/tc/tc.h"
# include "xmega/drivers/usart/usart.h"
# include "xmega/boards/xmega_a3bu_xplained/led.h"
//# define DISPLAY_NHDC12832A1ZFSWFBW3V3
//# define STORAGE_AT45DB642D
#else
# error You have to define your board in the Makefile
#endif

#endif // _DEFINES_H_
