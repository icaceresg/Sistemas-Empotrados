#include "leon3_uart.h"
#include "leon3_bprint.h"

int8_t leon3_print_string(char *str)
{
	uint32_t i = 0;
	uint32_t write_timeout = 0;

	while (str[i] != '\0')
	{
		leon3_putchar(str[i]);
		i++;
	}
	return (leon3_uart_tx_fifo_is_empty());
}

int8_t leon3_print_uint8(uint8_t i)
{
	uint8_t aux;
	if (i < 10)
		leon3_putchar(i + '0');
	else if (i < 100)
	{
		leon3_putchar((i / 10) + '0');
		leon3_putchar((i % 10) + '0');
	}
	else
	{
		aux = i % 100;
		leon3_putchar((i / 100) + '0');
		leon3_putchar((aux / 10) +'0');
		leon3_putchar((aux % 10) + '0');
	}
	return (leon3_uart_tx_fifo_is_empty());
}

