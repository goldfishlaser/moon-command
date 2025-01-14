
  /*                          
 
  /\\,/\\,                   
 /| || ||                    
 || || ||   /'\\  /'\\ \\/\\ 
 ||=|= ||  || || || || || || 
~|| || ||  || || || || || || 
 |, \\,\\, \\,/  \\,/  \\ \\ 
_-                           

GNU General Public License v3.0 
Author: Melanie Allen

*/ 


#include <stdio.h> 
#include <time.h> 
#include "lib.c"

// Calculate moon phase and provide advice

const char* getMoonPhase(int year, int month, int day) { 
    int c, e; 
    double jd; 
    int b; 
    
    if (month < 3) { year--; month += 12; } ++month; 
    
    c = 365.25 * year; 
    e = 30.6 * month; 
    jd = c + e + day - 694039.09; // jd is total days elapsed 
    jd /= 29.5305882; // divide by the moon cycle (29.53 days) 
    b = jd; // int(jd) -> b, take integer part of jd 
    jd -= b; // subtract integer part to leave fractional part of original jd 
    b = jd * 8 + 0.5; // scale fraction from 0-8 and round by adding 0.5 
    b = b & 7; // 0 and 8 are the same so turn 8 into 0 
    
    switch (b) { 
        case 0: return "It is the New Moon 🌑. Take time for reflection and planning new projects.\n"; 
        case 1: return "It is the Waxing Crescent 🌒. Begin putting new plans into action.\n"; 
        case 2: return "It is the First Quarter 🌓. Identify and tackle obstacles.\n"; 
        case 3: return "It is the Waxing Gibbous 🌔. Continue what has been working most effectively.\n"; 
        case 4: return "It is the Full Moon 🌕. An energetic period for going the extra mile.\n"; 
        case 5: return "It is the Waning Gibbous 🌖. Drop anything that isn't effective or isn't going to close.\n"; 
        case 6: return "It is the Last Quarter 🌗 Complete the finishing touches.\n"; 
        case 7: return "It is the Waning Crescent 🌘. Time for rest.\n"; 
        default: return "Error\n"; } } 
        
        int main() { time_t t = time(NULL); 
        struct tm tm = *localtime(&t); 
        int year = tm.tm_year + 1900; 
        int month = tm.tm_mon + 1; 
        int day = tm.tm_mday; 
        
        printf("%d-%02d-%02d: ", year, month, day); 
        printf("%s\n", getMoonPhase(year, month, day)); 
        
        return 0; 
        }
