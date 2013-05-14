/* ----------------------------------------------------------------------------
 * Copyright (c) 2013 Ben Blazak <benblazak.dev@gmail.com>
 * Released under The MIT License (see "doc/licenses/MIT.md")
 * Project located at <https://github.com/benblazak/ergodox-firmware>
 * ------------------------------------------------------------------------- */

/**                                                                 description
 * A QWERTY layout adapted from the default Kinesis layout.  The position of
 * the symbol keys on the function layer was (roughly) taken from the Arensito
 * layout.
 *
 * Implements the "layout" section of '.../firmware/keyboard.h'
 */


#include "./common/definitions.h"


// ----------------------------------------------------------------------------
// matrix control
// ----------------------------------------------------------------------------

#include "./common/exec_key.c.h"


// ----------------------------------------------------------------------------
// LED control
// ----------------------------------------------------------------------------

void kb__led__logical_on(char led) {
    switch(led) {
        case 'N': kb__led__on(1); break;  // numlock
        case 'C': kb__led__on(2); break;  // capslock
        case 'S': kb__led__on(3); break;  // scroll lock
        case 'O':                 break;  // compose
        case 'K':                 break;  // kana
    };
}

void kb__led__logical_off(char led) {
    switch(led) {
        case 'N': kb__led__off(1); break;  // numlock
        case 'C': kb__led__off(2); break;  // capslock
        case 'S': kb__led__off(3); break;  // scroll lock
        case 'O':                  break;  // compose
        case 'K':                  break;  // kana
    };
}


// ----------------------------------------------------------------------------
// keys
// ----------------------------------------------------------------------------

#include "./common/keys.c.h"

KEYS__LAYER__NUM_PUSH(10, 3);
KEYS__LAYER__NUM_POP(10);


// ----------------------------------------------------------------------------
// layout
// ----------------------------------------------------------------------------

#include "./common/matrix.h"


static _layout_t _layout = {

// ............................................................................

    MATRIX_LAYER(  // layer 0 : default
// macro, unused,
       K,    nop,
// left hand ...... ......... ......... ......... ......... ......... .........
     tab,        q,        w,        e,        r,        t,   lpu1l1,
                 a,        s,        d,        f,        g,  bkslash,
shL2kcap,        z,        x,        c,        v,        b,     altL,
                                  guiL, lpupo1l1,    space,    ctrlL,  
// right hand ..... ......... ......... ......... ......... ......... .........
                                                                 esc,        y,        u,        i,        o,        p,       bs,
                                                               quote,        h,        j,        k,        l,  semicol,
                                                            lpupo2l2,        n,        m,    comma,   period,    slash, shR2kcap,
                                                                altR,    space,     guiR,    enter
   ),

// ............................................................................

    MATRIX_LAYER(  // layer 1 : function and symbol keys
// macro, unused,
       K,    nop,
// left hand ...... ......... ......... ......... ......... ......... .........
   tilde,   exclam,       at,    pound,   dollar,  percent,   lpo1l1,
            braceL,   braceR,    brktL,    brktR,  undersc,    grave,
  transp,        1,        2,        3,        4,        5, lpupo2l2,
                                transp,   transp,   transp,   transp,   
// right hand ..... ......... ......... ......... ......... ......... .........
                                                              transp,    caret,     amp , asterisk,     dash,    equal,  volumeU,
                                                               brktL,    brktR,   parenL,   parenR,  undersc,     plus,
                                                            lpupo2l2,        6,        7,        8,        9,        0,  volumeD,
                                                              transp,   transp,   transp,   transp
  ),

// ............................................................................

    MATRIX_LAYER(  // layer 2 : keyboard functions
// macro, unused,
       K,    nop,
// left hand ...... ......... ......... ......... ......... ......... .........
   btldr,      nop,     home,   arrowU,     end,    pageU,   lpu3l3,
               nop,   arrowL,   arrowD,  arrowR,    pageD,      nop,
  transp,       F1,       F2,       F3,      F4,       F5,      nop,
                                transp,  transp,   transp,   transp,
// right hand ..... ......... ......... ......... ......... ......... .........
                                                             transp,     home,    pageD,    pageU,      end,      nop,      nop,
                                                                nop,   arrowL,   arrowD,   arrowU,   arrowR,      nop,
                                                                nop,       F6,       F7,       F8,       F9,      F10,   transp,
                                                             transp,   transp,   transp,   transp
     ),

// ............................................................................

    MATRIX_LAYER(  // layer 3 : numpad
// macro, unused,
       K,    nop,
// left hand ...... ......... ......... ......... ......... ......... .........
  transp,   transp,   transp,   transp,   transp,   transp,   lpo3l3,
            transp,   transp,   transp,   transp,   transp,   transp,
  transp,   transp,   transp,   transp,   transp,   transp,   transp,
                                   ins,   transp,   transp,   transp,
// right hand ..... ......... ......... ......... ......... ......... .........
            numPop,    equal,      kp7,      kp8,      kp9,    kpSub,   transp,
             kpMul,    kpDiv,      kp4,      kp5,      kp6,    kpAdd,   
            transp,   transp,      kp1,      kp2,      kp3,  kpEnter,   transp,
            transp,   period,  kpEnter,      kp0
  ),

// ............................................................................
};

