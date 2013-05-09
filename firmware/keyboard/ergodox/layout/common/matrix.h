/* ----------------------------------------------------------------------------
 * Copyright (c) 2012, 2013 Ben Blazak <benblazak.dev@gmail.com>
 * Released under The MIT License (see "doc/licenses/MIT.md")
 * Project located at <https://github.com/benblazak/ergodox-firmware>
 * ------------------------------------------------------------------------- */

/**                                                                 description
 * Information about the matrix
 */


#ifndef ERGODOX_FIRMWARE__FIRMWARE__KEYBOARD__ERGODOX__LAYOUT__COMMON__MATRIX__H
#define ERGODOX_FIRMWARE__FIRMWARE__KEYBOARD__ERGODOX__LAYOUT__COMMON__MATRIX__H
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------


/**                                             macros/MATRIX_LAYER/description
 * Mapping from spatial position to matrix position.
 *
 * - Spatial position: Where the key is spatially, relative to other keys, both
 *   on the keyboard and in the layout.
 * - Matrix position: The coordinate in the matrix to which a key is scanned by
 *   the update functions.
 *
 * - Location numbers are in the format `row##column`, where both 'row' and
 *   'column' are single digit hex numbers corresponding to the matrix position
 *   (which also corresponds to the row and column pin labels used in the
 *   Teensy and MCP23018 files).
 *
 * - Coordinates:
 *     - optional keys
 *         - k15, k16 (left hand thumb group)
 *         - k17, k18 (right hand thumb group)
 *     - unused keys
 *         - k36, k00 (left hand)
 *         - k37, k0D (right hand)
 *
 * - Other Info:
 *       ----------------------------------------------------
 *                 rows x columns = positions;  used,  unused
 *       per hand:    6 x  7      = 42;         40,    2
 *          total:    6 x 14      = 84;         80,    4
 *       
 *       left hand  : rows 0..5, cols 0..6
 *       right hand : rows 0..5, cols 7..D
 *       ----------------------------------------------------
 */
#define MATRIX_LAYER(                                                                                           \
            /* the name of a macro to call on all arguments */                                                  \
            M,                                                                                                  \
                                                                                                                \
            /* for unused positions */                                                                          \
            na,                                                                                                 \
                                                                                                                \
            /* left hand, spatial positions */                                                                  \
            k36,k35,k34,k33,k32,k31,k30,                                                                        \
                k25,k24,k23,k22,k21,k20,                                                                        \
            k16,k15,k14,k13,k12,k11,k10,                                                                        \
                        k03,k02,k01,k00,                                                                        \
                                                                                                                \
            /* right hand, spatial positions */                                                                 \
                k37,k38,k39,k3A,k3B,k3C,k3D,                                                                    \
                k27,k28,k29,k2A,k2B,k2C,                                                                        \
                k17,k18,k19,k1A,k1B,k1C,k1D,                                                                    \
                k07,k08,k09,k0A)                                                                                \
                                                                                                                \
    /* matrix positions */                                                                                      \
    {{ M(k07),M(k08),M(k09),M(k0A),M( na),M( na),M( na), M(k00),M(k01),M(k02),M(k03),M( na),M( na),M( na) },    \
     { M(k17),M(k18),M(k19),M(k1A),M(k1B),M(k1C),M(k1D), M(k10),M(k11),M(k12),M(k13),M(k14),M(k15),M(k16) },    \
     { M(k27),M(k28),M(k29),M(k2A),M(k2B),M(k2C),M( na), M(k20),M(k21),M(k22),M(k23),M(k24),M(k25),M( na) },    \
     { M(k37),M(k38),M(k39),M(k3A),M(k3B),M(k3C),M(k3D), M(k30),M(k31),M(k32),M(k33),M(k34),M(k35),M(k36) }}


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
#endif  // ERGODOX_FIRMWARE__FIRMWARE__KEYBOARD__ERGODOX__LAYOUT__COMMON__MATRIX__H

