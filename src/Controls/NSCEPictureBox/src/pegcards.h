/*++

Copyright (c) 1995-1997 Microsoft Corporation.  All Rights Reserved.

Module Name:

    PegCards.h

Abstract:

    Header file for resource DLL containing playing card bitmaps.

Environment:

    WIN32_WCE or WIN32_WCE emulation.

Notes:

    This DLL contains resources used to display playing cards.  It contains no executable code.
    Each playing card is 52 pixels wide, 70 pixels high.  The resources are:
        ID*CLUBS               The Club suit.  "*" is A, 2, 3, 4, 5, 6, 7, 8, 9, J, Q, K.
        ID*DIAMONDS            The Diamond suit.  "*" is A, 2, 3, 4, 5, 6, 7, 8, 9, J, Q, K.
        ID*HEARTS              The Hearts suit.  "*" is A, 2, 3, 4, 5, 6, 7, 8, 9, J, Q, K.
        ID*SPADES              The Spaces suit.  "*" is A, 2, 3, 4, 5, 6, 7, 8, 9, J, Q, K.
        IDFACEDOWN1            The WIN32_WCE horse.
        IDFACEDOWN2            The haunted castle.
        IDANNFACE2_1           Animation for the haunted castle.
        IDANNFACE2_1W,H,X,Y    Width: 27.  Height: 19.  OffsetX: 23.  OffsetY: 2.
        IDFACEDOWN3            The bubbling fish.
        IDANNFACE3_1           Animation for the bubbling fish.
        IDANNFACE3_1W,H,X,Y    Width: 29.  Height: 31.  OffsetX: 13.  OffsetY: 1.
        IDANNFACE3_2           Animation for the bubbling fish.
        IDANNFACE3_1W,H,X,Y     Width: 29.  Height: 31.  OffsetX: 13.  OffsetY: 1.
        IDFACEDOWN4            The cheating hand.
        IDANNFACE4_1           Animation for the cheating hand.
        IDANNFACE4_1W,H,X,Y    Width: 20.  Height: 24.  OffsetX: 25.  OffsetY: 2.
        IDANNFACE4_2           Animation for the cheating hand.
        IDANNFACE4_1W,H,X,Y    Width: 20.  Height: 24.  OffsetX: 25.  OffsetY: 2.
        IDFACEDOWN5            The helpful robot.
        IDANNFACE5_1           Animation for the helpful robot.
        IDANNFACE5_1W,H,X,Y    Width: 27.  Height: 13.  OffsetX: 27.  OffsetY: 2.
        IDANNFACE5_2           Animation for the helpful robot.
        IDANNFACE5_1W,H,X,Y    Width: 27.  Height: 13.  OffsetX: 27.  OffsetY: 2.
        IDFACEDOWN6            The sailboat.
        IDCARDX, IDCARDO       The X an O card (used in Solitaire to mark the end of the draw pile).
        IDCARDGHOST            The "ghost" card (used in Solitaire to mark the discard piles).

--*/
#ifndef _CARDS_H
#define _CARDS_H

// The 52 playing cards.
#define IDACLUBS        1
#define ID2CLUBS        2
#define ID3CLUBS        3
#define ID4CLUBS        4
#define ID5CLUBS        5
#define ID6CLUBS        6
#define ID7CLUBS        7
#define ID8CLUBS        8
#define ID9CLUBS        9
#define IDTCLUBS        10
#define IDJCLUBS        11
#define IDQCLUBS        12
#define IDKCLUBS        13
#define IDADIAMONDS     14
#define ID2DIAMONDS     15
#define ID3DIAMONDS     16
#define ID4DIAMONDS     17
#define ID5DIAMONDS     18
#define ID6DIAMONDS     19
#define ID7DIAMONDS     20
#define ID8DIAMONDS     21
#define ID9DIAMONDS     22
#define IDTDIAMONDS     23
#define IDJDIAMONDS     24
#define IDQDIAMONDS     25
#define IDKDIAMONDS     26
#define IDAHEARTS       27
#define ID2HEARTS       28
#define ID3HEARTS       29
#define ID4HEARTS       30
#define ID5HEARTS       31
#define ID6HEARTS       32
#define ID7HEARTS       33
#define ID8HEARTS       34
#define ID9HEARTS       35
#define IDTHEARTS       36
#define IDJHEARTS       37
#define IDQHEARTS       38
#define IDKHEARTS       39
#define IDASPADES       40
#define ID2SPADES       41
#define ID3SPADES       42
#define ID4SPADES       43
#define ID5SPADES       44
#define ID6SPADES       45
#define ID7SPADES       46
#define ID8SPADES       47
#define ID9SPADES       48
#define IDTSPADES       49
#define IDJSPADES       50
#define IDQSPADES       51
#define IDKSPADES       52

// The backs of the cards, with their animations.
#define IDFACEDOWNFIRST 61
#define IDFACEDOWN1     61
#define IDFACEDOWN2     62
#define IDFACEDOWN3     63
#define IDFACEDOWN4     64
#define IDFACEDOWN5     65
#define IDFACEDOWN6     66
#define IDFACEDOWNLAST  66
#define IDANNFACE2_1    71
#define IDANNFACE2_1W   27
#define IDANNFACE2_1H   19
#define IDANNFACE2_1X   23
#define IDANNFACE2_1Y    2
#define IDANNFACE3_1    72
#define IDANNFACE3_1W   29
#define IDANNFACE3_1H   31
#define IDANNFACE3_1X   13
#define IDANNFACE3_1Y    1
#define IDANNFACE3_2    73
#define IDANNFACE3_2W   29
#define IDANNFACE3_2H   31
#define IDANNFACE3_2X   13
#define IDANNFACE3_2Y    1
#define IDANNFACE4_1    74
#define IDANNFACE4_1W   20
#define IDANNFACE4_1H   15
#define IDANNFACE4_1X   24
#define IDANNFACE4_1Y   25
#define IDANNFACE4_2    75
#define IDANNFACE4_2W   20
#define IDANNFACE4_2H   15
#define IDANNFACE4_2X   24
#define IDANNFACE4_2Y   25
#define IDANNFACE5_1    76
#define IDANNFACE5_1W   27
#define IDANNFACE5_1H   17
#define IDANNFACE5_1X   13
#define IDANNFACE5_1Y   27
#define IDANNFACE5_2    77
#define IDANNFACE5_2W   27
#define IDANNFACE5_2H   17
#define IDANNFACE5_2X   13
#define IDANNFACE5_2Y   27

// The X an O card (used in Solitaire to mark the end of the draw pile).
#define IDCARDO         78
#define IDCARDX         79

// The "ghost" card (used in Solitaire to mark the discard piles).
#define IDCARDGHOST     80

#endif
