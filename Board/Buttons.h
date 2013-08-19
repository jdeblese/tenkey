/*
           Tenkey Controller
   Copyright (C) Jan-willem De Bleser, 2013.

      jw [at] thescrapyard [dot] org
*/

/*
  Copyright 2013  Jan-willem De Bleser (jw [at] thescrapyard [dot] org)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaims all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

/*         *** Based on ***             */
/*
             LUFA Library
     Copyright (C) Dean Camera, 2013.

  dean [at] fourwalledcubicle [dot] com
           www.lufa-lib.org
*/

#ifndef __BUTTONS_USER_H__
#define __BUTTONS_USER_H__

	/* Includes: */
		#include "LUFA/Common/Common.h"

	/* Enable C linkage for C++ Compilers: */
		#if defined(__cplusplus)
			extern "C" {
		#endif

	/* Preprocessor Checks: */
		#if !defined(__INCLUDE_FROM_BUTTONS_H)
			#error Do not include this file directly. Include LUFA/Drivers/Board/Buttons.h instead.
		#endif

	/* Public Interface - May be used in end-application: */
		/* Macros: */
			/** Button mask for the first button on the board. */
			#define BUTTONS_BUTTON1      (1 << 7)

			#define BUTTONS_DDR  DDRD
			#define BUTTONS_PORT PORTD
			#define BUTTONS_PIN  PIND

		/* Inline Functions: */
		#if !defined(__DOXYGEN__)
			static inline void Buttons_Init(void)
			{
				BUTTONS_DDR  &= ~BUTTONS_BUTTON1;
				BUTTONS_PORT |=  BUTTONS_BUTTON1;
			}

			static inline void Buttons_Disable(void)
			{
				BUTTONS_DDR  &= ~BUTTONS_BUTTON1;
				BUTTONS_PORT &= ~BUTTONS_BUTTON1;
			}

			static inline uint8_t Buttons_GetStatus(void) ATTR_WARN_UNUSED_RESULT;
			static inline uint8_t Buttons_GetStatus(void)
			{
				return ((BUTTONS_PIN & BUTTONS_BUTTON1) ^ BUTTONS_BUTTON1);
			}
		#endif

	/* Disable C linkage for C++ Compilers: */
		#if defined(__cplusplus)
			}
		#endif

#endif

/** @} */

