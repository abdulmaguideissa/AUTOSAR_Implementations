/**************************************************************
* Non Autosar file.
* File name:  Bit_Manipulation.h
* Decription: File that contains all the required Macros to manipulate
              the hardware of the uC.
* Author:     Abdulmaguid Eissa.
***************************************************************/

#ifndef BIT_MANIPULATION_H
#define BIT_MANIPULATION_H

/* Setting bit in a register */
#define SET_BIT(reg, bit)                    (reg |= (1 << bit))

/* Clearing a bit in a register */
#define CLEAR_BIT(reg, bit)                  (reg &= (~(1 << bit)))

/* Toggle a bit value in a register */
#define TOGGLE_BIT(reg, bit)                 (reg ^= (1 << bit))

/* Check if a bit is set */
#define BIT_IS_SET(reg, bit)                 (reg & (1 << bit))

/* Check if a bit is clear */
#define BIT_IS_CLEAR(reg, bit)               (!(reg & (1 << bit)))

/* Assigining a specific value to a register by setting */
#define SET_VAL(reg, val)                    (reg |= val)

/* Assigining a specific value to a register by clearing */
#define CLEAR_VAL(reg, val)                  (reg &= (~val))

/* Adding a value to a register */
#define ADD_VAL(reg, val)                    (reg += val)

/* Read a rgister value */
#define READ_REG_VAL(reg, range)             (reg & range)


#endif /* BIT_MANIPULATION_H */