# Moon Command

This project is a command line tool that tells you the phase of the moon and some advice.

## Quickstart

You will need to have build-essentials, gcc, and clang installed. 

After downloading the file, go to your directory in the command line and enter

'''sudo make install-moon'''

If you look at the source you will see there are other options as well.

## How It Works

Based on your system time and date, it will calculate what phase of the moon is using the formula:

    if (month < 3) { year--; month += 12; } ++month; 
    
    c = 365.25 * year; 
    e = 30.6 * month; 
    jd = c + e + day - 694039.09; // jd is total days elapsed 
    jd /= 29.5305882; // divide by the moon cycle (29.53 days) 
    b = jd; // int(jd) -> b, take integer part of jd 
    jd -= b; // subtract integer part to leave fractional part of original jd 
    b = jd * 8 + 0.5; // scale fraction from 0-8 and round by adding 0.5 
    b = b & 7; // 0 and 8 are the same so turn 8 into 0 

The possible outputs are:
* It is the New Moon 🌑. Take time for reflection and planning new projects.
* It is the Waxing Crescent 🌒. Begin putting new plans into action.
* It is the First Quarter 🌓. Identify and tackle obstacles.
* It is the Waxing Gibbous 🌔. Continue what has been working most effectively.
* It is the Full Moon 🌕. An energetic period for going the extra mile.
* It is the Waning Gibbous 🌖. Drop anything that isn't effective or isn't going to close.
* It is the Last Quarter 🌗 Complete the finishing touches.
* It is the Waning Crescent 🌘. Time for rest.
* Error


## Attribution

Used neoeno toy-c-project-template and copilot.
