#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

/**
 * @brief Set the value of a single bit in a register
 * 
 * @param REG   The register to modify
 * @param BIT   The bit position to set (0-based)
 */
#define SET_BIT(REG, BIT)     ((REG) |= (1U << (BIT)))

/**
 * @brief Clear the value of a single bit in a register
 * 
 * @param REG   The register to modify
 * @param BIT   The bit position to clear (0-based)
 */
#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(1U << (BIT)))

/**
 * @brief Toggle the value of a single bit in a register
 * 
 * @param REG   The register to modify
 * @param BIT   The bit position to toggle (0-based)
 */
#define TOGGLE_BIT(REG, BIT)  ((REG) ^= (1U << (BIT)))

/**
 * @brief Get the value of a single bit in a register
 * 
 * @param REG   The register to read from
 * @param BIT   The bit position to read (0-based)
 * @return      The value of the specified bit (0 or 1)
 */
#define GET_BIT(REG, BIT)     (((REG) >> (BIT)) & 1U)

/**
 * @brief Set all bits in a register
 *
 * @param REG   The register to modify
 */
#define SET_REG(REG)          ((REG) = 0xFF)

/**
 * @brief Clear all bits in a register
 *
 * @param REG   The register to modify
 */
#define CLEAR_REG(REG)        ((REG) = 0x00)

/**
 * @brief Get the value of a register
 *
 * @param REG   The register to read from
 * @return      The value of the register
 */
#define GET_REG(REG)          (REG)

/**
 * @brief Toggle all bits in a register
 *
 * @param REG   The register to modify
 */
#define TOGGLE_REG(REG)       ((REG) ^= 0xFF)

#endif /* LIB_BIT_MATH_H_ */
