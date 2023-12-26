/*_____________________________________________________________________________
 │                                                                            |
 │ COPYRIGHT (C) 2023 Mihai Baneu                                             |
 │                                                                            |
 | Permission is hereby  granted,  free of charge,  to any person obtaining a |
 | copy of this software and associated documentation files (the "Software"), |
 | to deal in the Software without restriction,  including without limitation |
 | the rights to  use, copy, modify, merge, publish, distribute,  sublicense, |
 | and/or sell copies  of  the Software, and to permit  persons to  whom  the |
 | Software is furnished to do so, subject to the following conditions:       |
 |                                                                            |
 | The above  copyright notice  and this permission notice  shall be included |
 | in all copies or substantial portions of the Software.                     |
 |                                                                            |
 | THE SOFTWARE IS PROVIDED  "AS IS",  WITHOUT WARRANTY OF ANY KIND,  EXPRESS |
 | OR   IMPLIED,   INCLUDING   BUT   NOT   LIMITED   TO   THE  WARRANTIES  OF |
 | MERCHANTABILITY,  FITNESS FOR  A  PARTICULAR  PURPOSE AND NONINFRINGEMENT. |
 | IN NO  EVENT SHALL  THE AUTHORS  OR  COPYRIGHT  HOLDERS  BE LIABLE FOR ANY |
 | CLAIM, DAMAGES OR OTHER LIABILITY,  WHETHER IN AN ACTION OF CONTRACT, TORT |
 | OR OTHERWISE, ARISING FROM,  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR  |
 | THE USE OR OTHER DEALINGS IN THE SOFTWARE.                                 |
 |____________________________________________________________________________|
 |                                                                            |
 |  Author: Mihai Baneu                           Last modified: 15.Dec.2023  |
 |                                                                            |
 |___________________________________________________________________________*/
 
#include "stm32f4xx.h"
#include "stm32rtos.h"
#include "queue.h"
#include "gpio.h"

void gpio_init()
{
    /* disable JTAG */
    MODIFY_REG(GPIOA->MODER,    GPIO_MODER_MODER15_Msk,     0);                         /* JTDI disabled */
    MODIFY_REG(GPIOB->MODER,    GPIO_MODER_MODER4_Msk,      0);                         /* NJTRST disabled */
    //MODIFY_REG(GPIOB->MODER,    GPIO_MODER_MODER3_Msk,      0);                         /* JTDO disabled */

    /* configure LED pin */
    MODIFY_REG(GPIOA->MODER,    GPIO_MODER_MODER1_Msk,     GPIO_MODER_MODER1_0);        /* set the pin as output */
    MODIFY_REG(GPIOA->OTYPER,   GPIO_OTYPER_OT1_Msk,        0);                         /* push pull */
    MODIFY_REG(GPIOA->OSPEEDR,  GPIO_OSPEEDR_OSPEED1_Msk,   0);                         /* low speed */
    MODIFY_REG(GPIOA->PUPDR,    GPIO_PUPDR_PUPD1_Msk,       0);                         /* no pull up, no pull down */
}

void gpio_set_led()
{
    GPIOA->BSRR = GPIO_BSRR_BS1;
}

void gpio_reset_led()
{
    GPIOA->BSRR = GPIO_BSRR_BR1;
}
