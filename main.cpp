/*
Project 3 - Part 1e / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
    - if your functions return something other than 'void', add a comment explaining what is being returned.  see the example code below.
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a [-Wpadded] warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function whose parameter has a default value.
        //the parameter name is related to the work the function will perform.
        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips); //3) returns the number of miles traveled
    };

    //wash and wax car
    void washAndWaxCar(Car carA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage); //3) returns the total amount charged.
    //detail the car interior
    void detailInterior(Car carB);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  

    /*
    Pay attention to the member functions that take an instance of 'Car'
    Notice that there is a member variable of the same type.

    It makes sense to pass a Car to the function 'washAndWaxCar' because car washes service MANY cars
    However, they only service ONE car at a time.
    the carBeingServiced's value would change every time you wash and wax the car. 

    I see many students who write code emulating this format, but their usage does not make logical sense.  
    Consider the following snippet:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        // train their skills
        void trainPlayerSkills(Manager managerA);
    
        Manager teamManager;
    };

    It does not make sense to pass in a new Manager whenever you are going to train your team players.
    Soccer teams have ONE manager.

    a much more relevant usage would be adding a member function that hires a new manager:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        void hireNewManager(Manager newManager);
    
        Manager teamManager;
    };

    We can safely assume that the 'Manager' instance that is being passed in will be replacing the current 'teamManager' variable without looking at any other code.
    This is because the function name and function argument clearly indicate what they are/what they do.

    Your function names and parameter names should make LOGICAL SENSE.
    Readers of your code should be able to INTUITIVELY understand what your function implementations will do without actually seeing the implementations.

    Keep this in mind when you define your UDTs in this project part.
    */
};


/*
Thing 1) Computer
 */
struct Computer
{ 

    //1) number of processor cores (int)
    int numberOfProcessorCores;
    //2) memory In GB (int)
    int memoryInGB;
    //3) graphics accelerator (std::string)
    std::string graphicsAccelerator;
    //4) motherboard type (std::string)
    std::string motherboardType;
    //5) audio interface name (std::string)
    std::string audioInterfaceName;


    //1) run multiple processes 
    void runMultipleProcesses();
    //2) run memtest
    void runMemtest();

    //3) connect to internet
    //return true on connection success
    bool connectToInternet();


};
/*
Thing 2) Dog 
 */
struct Dog
{

    //1) hair color (std::string)
    std::string hairColor;
    //2) hair length in cm (float)
    float hairLengthInCM;
    //3) number of teeth (int)
    int numberOfTeeth;
    //4) length of tail in cm (float)
    float lengthOfTailInCm;
    //5) breed (std::string)
    std::string breed;

    //1) bark
    void bark();
    //2) run
    void run();
    //3) fetch a toy
    bool fetch(std::string toy); //returns true if the dog fetched the toy
};
/*
Thing 3) Teacher
 */
struct Teacher
{

    //1) credential type (std::string)
    std::string credentialType;
    //2) domain expertise (std::string)
    std::string domainExpertise;
    //3) number of classes taught (int)
    int numberOfClassesTaught;
    //4) years of tenure (float)
    float yearsOfTenure;
    //5) rating by students (char)
    char ratingByStudents;

    //1) give lecture
    void giveLecture();

    //2) private tutoring
    // returns the amount of money made from private tutoring
    float privateTutoring(float hourlyRate, int numberOfHours = 1); //input hourly rate and number of hours
    //3) assign homework
    void assignHomework(std::string homeworkAssignment);//input a string representation of the homework

};
/*
Thing 4) Audio Interface
 */
struct AudioInterface
{
    //1) number of inputs (int)
    int numberOfInputs;
    //2) number of outputs (int)
    int numberOfOutputs;
    //3) speaker volume level (float)
    int float speakerVolumeLevel;
    //4) color (std::string)
    std::string color;
    //5) headphone volume level (float)
    float headphoneVolumeLevel;

    //1) adjust levels
    float adjustLevels(float sliderMark); //returns the current level 
    //2) mute output
    bool muteOutput();//returns true if mute is on. false otherwise.
    //3) display input levels on GUI
    void displayInputLevelsOnGUI(float inputLevel1, float inputLevel2);//input to function is audio line in levels

};
/*
Thing 5) Fingerboard
 */
struct Fingerboard
{

    //1) type of wood (std::string)
    std::string typeOfWood;
    //2) number of frets (int)
    int numberOfFrets;
    //3) length in cm (float)
    float lengthInCm;
    //4) width in cm (float)
    float widthInCm;
    //5) number of inlays (int)
    int numberOfInlays;

    //1) fret a note
    int fretANote(int stringNumber, int fretNumber);//returns midi pitch value of fretted note
    //2) require oil
    std::string requireOil(bool required);//returns a representation of the type of oil, if required
    //3) requre new frets
    bool requireNewFrets();//returns true if the fretboard requires new frets

};
/*
Thing 6) Tuning
*/
struct Tuning
{
    //1) string 1 midi tuning (int)
    int string1MidiTuning;
    //2) string 2 midi tuning (int)
    int string2MidiTuning;  
    //3) string 3 midi tuning (int)
    int string3MidiTuning;
    //4) string 4 midi tuning (int)
    int string4MidiTuning;
    //5) string 5 midi tuning (int)
    int string5MidiTuning;

    //1) tune string up
    int tuneStringUp(); //returns pitch of string
    //2) tune string down
    int tuneStringDown(); //returns pitch of string;
    //3) set all string tunings
    void setAllStringTunings(int string1, int string2, int string3, int string4, int string5);
    //input a midi pitch value for each string
    //sets the Tuning member variables
};
/*
Thing 7) String
 */
struct String
{
    //1) gauge (int)
    int gauge();
    //2) material name (std::string)
    std::string materialName;
    //3) manufacturer name (std::string)
    std::string manufacturerName;
    //4) cost in USD (float)
    float costInUSD;
    //5) is old and dirty (bool)
    bool isOldAndDirty;

    //1) require retuning
    bool requireRetuning();
    //2) snap
    bool snap();
    //3) become old and dirty
    void becomeOldAndDirty();//sets the strings member variable

};
/*
Thing 8) Pickup
 */
struct Pickup
{
    //1) type of metal (std::string)
    std::string typeOfMetal;
    //2) number of pickups (int)
    int numberOfPickups;
    //3) timbre discription (std::string)
    std::string timbreDescription;
    //4) is humbucker (bool)
    bool isHumbucker;
    //5) bypass (bool)
    bool bypassPickup;

    //1) bypass 
    void bypass(bool shouldBypass); //sets bypass member variable
    //2) sense flux field
    float senseFluxField();//returns the value of the fluxfield
    //3) buck the hum
    float buckTheHum(float inputWithHum);//transforms inputWithHum to output with hum bucked.

};
/*
Thing 9) Tone Control
 */
struct ToneControl
{
    //1) front pickup tone control setting (float)
    float frontPickupToneControlSetting;
    //2) rear pickup tone control setting  (float)
    float rearPickupToneControlSetting;
    //3) knob color (std::string)
    std::string knobColor;
    //4) knob material (std::string)
    std::string knobMaterial;
    //5) is smooth to turn (bool)
    bool isSmoothToTurn;

    //1) set tone level
    float setToneLevel(float inputLevel, float adjustment); //apply adjustment to the inputlevel
    //return the adjusted tone level

    //2) require repair
    bool requireRepair();//returns true if the tone control requires repair
    //3) auto adjust
    bool autoAdjust();//returns true if autoAdjust is turned on; else false 

};

/*
Thing 10) Guitar
 */
struct Guitar
{

    //1) Fingerboard 

    //2) Tuning 

    //3) Strings 

    //4) Pickups 

    //5) Tone Control 


    //1) adjust tone

    //2) tune a string

    //3) sound a note

};
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
