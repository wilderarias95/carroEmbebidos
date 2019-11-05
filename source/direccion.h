/*
 * direccion.h
 *
 *  Created on: 1 nov. 2019
 *      Author: santiago
 */

#ifndef DIRECCION_H_
#define DIRECCION_H_

#include "MKL27Z644.h"
#include "fsl_debug_console.h"
#include <time.h>
#include <stdio.h>

void InitSteering(void);
void TurnRight (void);
void TurnLeft (void);
void KeepFw (void);

#endif /* DIRECCION_H_ */
