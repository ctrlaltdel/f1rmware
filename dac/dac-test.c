/*
 * Copyright 2010 - 2012 Michael Ossmann
 *
 * This file is part of HackRF.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#include <libopencm3/lpc43xx/gpio.h>
#include <libopencm3/lpc43xx/scu.h>
#include <libopencm3/lpc43xx/dac.h>

#include "setup.h"
#include "output.h"

#define PORT_LED1 GPIO2
#define PIN_LED1 (1<<2)

int main(void)
{
	int i;
	cpu_clock_init();
	cpu_clock_set(204);

	scu_pinmux(P4_2,SCU_GPIO_NOPULL|SCU_CONF_FUNCTION0);
	GPIO2_DIR |= PIN_LED1;

    dac_init(false);

	while (1) 
	{
        int i;
        for(i=0;i<cut_raw_len;i+=1) {
            //uint16_t data = cut_raw[i] | (cut_raw[i+1] << 8);
            //uint16_t data = cut_raw[i+1] | (cut_raw[i] << 8);
            uint16_t data = cut_raw[i];
		    gpio_set(PORT_LED1, PIN_LED1); /* LED off */
            dac_set(data);
            //dac_set(i);
		    delay(765);
		    gpio_clear(PORT_LED1, PIN_LED1); /* LED off */
        }
        dac_set(0x3FF);
		//delay(5);
        dac_set(0x0);
		//delay(5);
	}

	return 0;
}
