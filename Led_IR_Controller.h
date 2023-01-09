/*
 * This File has all the IR controls 
 */

 #ifndef _LED_IR_CONTROLLER_H
 #define _LED_IR_CONTROLLER_H

 #define KEY_V+ (0xFF3AC5)
 #define KEY_V- (0xFFBA45)
 #define KEY_OFF (0xFF827D)
 #define KEY_ON (0xFF02FD)

 #define KEY_RED (0xFF1AE5)
 #define KEY_RED_ORANGE (0xFF2AD5)
 #define KEY_ORANGE (0xFF0AF5)
 #define KEY_ORANGE_YELLOW (0xFF38C7)
 #define KEY_YELLOW (0xFF18E7)

 #define KEY_GREEN (0xFF9A65)
 #define KEY_GREEN_LIGHT (0xFFAA55)
 #define KEY_GREEN_CYAN (0xFF8A75)
 #define KEY_GREEN_CYAN_DARK (0xFFB847)
 #define KEY_GREEN_PEACOCK (0xFF9867)

 #define KEY_BLUE (0xFFA25D)
 #define KEY_BLUE_LIGHT (0xFF926D)
 #define KEY_VIOLET (0xFFB24D)
 #define KEY_PURPLE (0xFF7887)
 #define KEY_MAGENTA (0xFF58A7)

 #define KEY_WHITE (0xFF22DD)
 #define KEY_PINK_1 (0xFF12ED)
 #define KEY_PINK_2 (0xFF32CD)
 #define KEY_SKY_1 (0xFFF807)
 #define KEY_SKY_2 (0xFFD827)

 #define KEY_1H (0xFF28D7)
 #define KEY_2H (0xFFA857)
 #define KEY_3H (0xFF6897)
 #define KEY_4H (0xFFE817)

 #define KEY_25 (0xFF08F7)
 #define KEY_50 (0xFF8877)
 #define KEY_75 (0xFF48B7)
 #define KEY_100 (0xFFC837)

 #define KEY_JUMP_3 (0xFF30CF)
 #define KEY_JUMP_7 (0xFFB04F)
 #define KEY_FADE_3 (0xFF708F)
 #define KEY_FADE_7 (0xFFF00F)

 #define KEY_QUICK (0xFF10EF)
 #define KEY_SLOW (0xFF906F)
 #define KEY_AUTO (0xFF50AF)
 #define KEY_FLASH (0xFFD02F)

 #define KEY_MUS_1 (0xFF20DF)
 #define KEY_MUS_2 (0xFFA05F)
 #define KEY_MUS_3 (0xFF609F)
 #define KEY_MUS_4 (0xFFE01F)
 
 unsigned long keyValue[] ={KEY_V+, KEY_V-, KEY_OFF, KEY_ON, 
              KEY_RED, KEY_RED_ORANGE, KEY_ORANGE, KEY_ORANGE_YELLOW, KEY_YELLOW,
              KEY_GREEN, KEY_GREEN_LIGHT, KEY_GREEN_CYAN, KEY_GREEN_CYAN_DARK, KEY_GREEN_PEACOCK,
              KEY_BLUE, KEY_BLUE_LIGHT, KEY_VIOLET, KEY_PURPLE, KEY_MAGENTA,
              KEY_WHITE, KEY_PINK_1, KEY_PINK_2, KEY_SKY_1, KEY_SKY_2,
              KEY_1H, KEY_2H, KEY_3H, KEY_4H, KEY_25, KEY_50, KEY_75, KEY_100,
              KEY_JUMP_3, KEY_JUMP_7, KEY_FADE_3, KEY_FADE_7, 
              KEY_QUICK, KEY_SLOW, KEY_AUTO, KEY_FLASH,
              KEY_MUS_1, KEY_MUS_2, KEY_MUS_3, KEY_MUS_4
        };

char keyBuf[][44] = {"V+", "V-", "OFF", "ON", "R_1", "R_2", "R_3", "R_4", "R_5",
            "G_1", "G_2", "G_3", "G_4", "G_5", "B_1", "B_2", "B_3", "B_4", "B_5",
            "W", "P_1", "P_2", "S_1", "S_2", "1H", "2H", "3H", "4H", "25%", "50%",
            "75%", "100%", "Jump3", "Jump7", "Fade3", "Fade7", "Quick", "Slow",
            "Auto", "Flash", "Mus1", "Mus2", "Mus3", "Mus4"
        };




 #endif
