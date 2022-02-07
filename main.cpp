/*
Project 3 - Part 1a-d / 5
Video:  Chapter 2 Part 5
User-Defined Types

Create a branch named Part1

Purpose: The entire purpose of this 5-part project is to get you 
writing C++ code that compiles and to reinforce the syntax habits 
that C++ requires.  
What you create in this project will be used as the basis of 
Project 5 in C++ Language Fundamentals.

************************
Part1 purpose:  Learn to write User-Defined Types (UDTs)

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps, all on the same branch.
    Part 1a: you will learn to think about an object in terms of 
    its sub-objects.
    
    Part 1b: you will write 4 un-related UDTs in plain english.
    
    Part 1c: you will write 1 UDT in plain english that will be 
    made of 5 related sub-objects.
    
    Part 1d: you will write plain-english UDTs for the 5 
    sub-objects that form the UDT defined in Part 1c.
    
    Part 1e: you will convert those 10 plain-english UDTs into code 
    that runs.
************************
*/

/*
Part 1a
1) Look at the picture of the car interior (Part1a pic.jpg).  
    It's in the list of files on the left in Replit.
    Fill in the blanks below which break this car interior down 
    into sub-objects.

Several sub-objects are listed below that make up this car's interior.
    you're going to name several things that you'll find on each 
    subobject.
    you're going to name several things that each subobject can do.
    If you've seen "Family Feud", we are going to do what they do 
    in that show.

    A few blanks are filled in for you already.

Main Object: Car Interior
Sub Object 1: Steering Wheel
    Name 4 things you'll find on the:    Steering Wheel
        1) paddle shifters
        2) 'cruise control' controls
        3) 'volume control' control
        4) car brand emblem

    Name 2 things you can do with the:   Steering Wheel
        1) adjust cruise control settings.
        2) set the volume
        
Sub Object 2: Instrument Cluster
    Name 4 things you'll find on the:   Instrument Cluster
        1) windshield wiper control
        2) window cleaner spray control
        3) blinker control
        4) fog light control 
    Name 3 things you can do with the:   Instrument Cluster
        1) spray washer fluid
        2) signal for left turn
        3) turn on fog lights
    
Sub Object 3: Environment Controls
    Name 3 things you'll find on the:    Environment Controls
        1) heater 
        2) defroster
        3) fan setting
    Name 3 things you can do with the:   Environment Controls
        1) adjust fan setting
        2) set heater temperature
        3) turn on defroster

Sub Object 4: Infotainment System
    Name 3 things you'll find on the:    Infotainment System
        1) radio
        2) music app
        3) traffic updates
    Name 3 things you can do with the:   Infotainment System
        1) change radio station
        2) choose song from music app
        3) get local traffic

Sub Object 5: Seat 
    Name 3 things you'll find on the:    Seat
        1) headrest
        2) heat control 
        3) lumbar control
    Name 2 things you can do with the:   Seat
        1) set lumbar height
        2) set heat level
*/

/*
Part 1b
Now you have some basic understanding of how to think of an object 
in terms of its sub-objects.

Next, write 4 un-related UDTs in plain english:
*/
/*
 example:  
 
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - the amount of water used per week.
        - amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior

    Notice that I did not use "has a vacuum cleaner" or "Has 
    eco-friendly cleaning supplies" as one of the properties.
    
    Writing 'has a ___" checks whether or not your object **has the 
    ability to do something**.
    Instead, I wrote "number of vacuum cleaners" and "number of 
    eco-friendly cleaning supplies".  
    
    These are specific objects or amounts. 
    
    In C++ terms, this means to I want you to avoid using 'bool' 
    (has a) as a member variable type.
    Instead, prefer the other primitive types.

    In addition to the usual primitives (covered in Project 2), you 
    can use 'std::string' to represent strings in this project.
 */

/*
Part 1b Assignment:
1)  Fill in the 4 UDTs below with a random UDT in plain english.
    These 4 UDTs do not need to be related.
        a) For each plain-english UDT, write out 5 traits or 
        properties and 3 things it can do.
        b) remember: these properties will eventually become
        primitives.
        c) pick properties that can eventually be represented with 
        'int float double bool char std::string'.
*/


 /*
Part 1c
You have just finished practicing writing out a UDT that is has 
5 properties and can perform 3 actions.  

Now you will write 1 UDT in plain english. 

This UDT will be different than the previous 4 you wrote: It will 
use UDTs to describe its 5 properties, as opposed to using C++ 
primitives to describe the 5 properties.

You will define these 5 'property' UDTs in Part 1d.
 */

 /*
Part 1c example:
    Cell Phone

    A Cell Phone is built using the following 5 UDTs:
        Display
        Memory
        CPU
        Radio
        Applications

    A Cell Phone has 3 things it can do:
        make a call
        send a text
        run an application.

    Notice that I did not use "has a display" or "Has memory" or 
    "has a cpu" as one of the properties of the CellPhone.
    
    Writing 'has a ___" checks whether or not your object **has 
    the ability to do something**.
    Instead, I wrote "Display" or "CPU".  These are specific 
    objects or amounts. 
    
    In C++ terms, this means to I want you to avoid using 'bool' 
    (has a) as a member variable type.
    Instead, prefer the other primitive types.

    When you choose your 5 smaller parts, remember that each of 
    these 5 Sub Objects will need to be defined with 5 primitive 
    properties and 3 actions EACH.
*/
/*
Part 1c assignment:
1) Fill in the 10th UDT below.
    Define an object that is made of 5 sub-objects.
    These parts will not be defined using Primitives, but instead 
    will be their own UDTs you'll define in Part 1d.

2) write the name of the primitive type you'll be using after each 
    property in UDTs 1-4:
    pick properties that can be represented with 
    'int float double bool char std::string'.
    example: 
        Display:
            Number of Pixels (int)
            Amount of Power consumed (milliwatt-hours) (float)
            Brightness (double)
            area in cm2 (int)
            brand (std::string)
*/


/*
Part 1d
You now know how to define a UDT that is composed of other UDT.
Now you will learn how to break down those sub-object UDTs into 
their 5 properties and 3 actions.

The goal of Part 1d is to get you to think about breaking down an 
object into smaller and smaller objects, until the smallest object 
is made of up only C++ primitives and std::string. 

Revisiting the previous example:  
Cell Phone

A Cell Phone is made up of the following 5 properties/sub-objects 
and 3 actions:
    Display
    Memory
    CPU
    Radio
    Applications
3 actions:
    make a call
    send a text
    run an application.

These 5 properties can be broken down into their own sub-objects 
and properties. 

If we break down the first property 'Display' into its 5 properties 
we get:
    brightness
    amount of power consumed.
    pixels
    width in cm
    height in cm

the Display's brightness can be represented with a Primitive, 
such as a double. 

The amount of power consumed can also be represented with a 
Primitive, such as a float or integer (i.e. 250mWa)

The 'pixels' property must be represented with an array of Pixel 
instances, as the screen has more than 1 row of pixels.
    Arrays have not been discussed and can't be used in this 
    project.
    Instead, we can use an Integer primitive to store the 
    Number of Pixels:

Display:
    Number of Pixels
    Amount of Power consumed (milliwatt-hours)
    Brightness
    width in cm
    height in cm

As you can see, the 'Display' UDT has been broken down to the 
point of being able to describe it with C++ primitives. 
*/

/*
Part 1d assignment:
1) Fill in #5 - #9 below with plain-english UDTs for the 5 
properties you created for UDT #10. 
    example: 
        If #10's first property was 'Engine', then `Thing 5)` 
        will be `Engine`. 
        You will need to provide 5 properties and 3 member 
        functions of that Engine object in plain English.
        Remember to pick properties that can be represented 
        with 'int float double bool char std::string'.

2) write the name of the primitive type you'll be using after 
each property for UDTs 5 - 9.
    You already did this for UDTs 1-4 in Part 1c.
    Pick properties that can be represented with 
    'int float double bool char std::string'
    example: 
        Display:
            Number of Pixels (int)
            Amount of Power consumed (milliwatt-hours) (float)
            Brightness (double)
            width in cm (int)
            height in cm (int)
*/


/*
You've just defined 10 UDTs!
4 of them are unrelated (UDTs 1-4).
5 of them form the sub-objects that make up the 10th UDT. 

Move them below this block comment and put them in numerical order 
(1 - 10).

The next thing that will happen is that I will review the 
pseudo-code that you have written.
Send me a DM to review your pull request when the project is ready for review.
*/


/*
Thing 1) Computer
5 properties:
    1) number of processor cores
    2) memory In GB
    3) graphics accelerator
    4) chassis size
    5) audio interface
3 things it can do:
    1) run multiple processes 
    2) run memtest
    3) connect to internet
 */

/*
Thing 2) Dog 
5 properties:
    1) hair color
    2) hair length
    3) number of teeth
    4) length of tail
    5) breed
3 things it can do:
    1) bark
    2) run
    3) fetch
 */

/*
Thing 3) Teacher
5 properties:
    1) credential type
    2) domain expertise
    3) number of classes taught
    4) years of tenure
    5) rating by students
3 things it can do:
    1) give lecture
    2) private tutoring
    3) assign homework
 */

/*
Thing 4) Audio Interface
5 properties:
    1) number of inputs
    2) number of outputs
    3) speaker volume level
    4) meter
    5) headphone volume level
3 things it can do:
    1) adjust levels
    2) mute output
    3) display input levels
 */

/*
Thing 5) Fingerboard
5 properties:
    1) type of wood (std::string)
    2) number of frets (int)
    3) length in cm (float)
    4) width in cm (float)
    5) number of inlays (int)
3 things it can do:
    1) fret a note
    2) require oil
    3) requre new frets
 */

/*
Thing 6) Tuning
5 properties:
    1) string 1 midi tuning (int)
    2) string 2 midi tuning (int)
    3) string 3 midi tuning (int)
    4) string 4 midi tuning (int)
    5) string 5 midi tuning (int)
3 things it can do:
    1) tune string up
    2) tune string down
    3) set all string tunings to default
 */

/*
Thing 7) Strings
5 properties:
    1) gauge (int)
    2) material name (std::string)
    3) manufacturer name (std::string)
    4) cost in USD (float)
    5) timbre description (std::string)
3 things it can do:
    1) require retuning
    2) snap
    3) become old and dirty
 */

/*
Thing 8) Pickups
5 properties:
    1) type of metal (std::string)
    2) number of pickups (int)
    3) timbre discription (std::string)
    4) is humbucker (bool)
    5) color (std::string)
3 things it can do:
    1) bypass 
    2) sense flux field
    3) buck the hum
 */

/*
Thing 9) Tone Control
5 properties:
    1) front pickup tone control setting (float)
    2) rear pickup tone control setting  (float)
    3) knob color (std::string)
    4) knob material (std::string)
    5) is smooth to turn (bool)
3 things it can do:
    1) set tone level
    2) require repair
    3) auto adjust
 */


/*
Thing 10) Guitar
5 properties:
    1) Fingerboard 
    2) Tuning 
    3) Strings 
    4) Pickups 
    5) Tone Control 
3 things it can do:
    1) adjust tone
    2) tune a string
    3) sound a note
 */

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
