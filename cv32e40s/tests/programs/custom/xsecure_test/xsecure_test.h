/*
**
** Copyright 2020 OpenHW Group
**
** Licensed under the Solderpad Hardware Licence, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     https://solderpad.org/licenses/
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
**
*******************************************************************************
**
** Directed test for Zc extension   exersizes instructions and scenarios
**                                  not likely to becovered by randomly
**                                  generated tests.
**
*******************************************************************************
*/


#ifndef __XSECURE_TEST_H__
#define __XSECURE_TEST_H__

#include <stdint.h>
#include <stdbool.h>
#include "corev_uvmt.h"
// Enable debug messages, note that this will change test timing
//#define DEBUG_MSG

#define TIMER_REG_ADDR       ((volatile uint32_t *) (CV_VP_INTR_TIMER_BASE))
#define TIMER_VAL_ADDR       ((volatile uint32_t *) (CV_VP_INTR_TIMER_BASE + 4))



//       Global Variables                 //
volatile uint32_t failureCount;


//       Functions from Assebly file      //

// Assembly function to enable interrupts
extern volatile void  enable_all_irq();


//       Function Headers                 //
void vp_assert_irq(uint32_t mask, uint32_t cycle_delay);
uint32_t vp_random_num(uint32_t upper_bound, uint32_t lower_bound);


//           Interrupt Handlers           //
__attribute__((interrupt ("machine"))) void m_external_irq_handler(void);


#endif
