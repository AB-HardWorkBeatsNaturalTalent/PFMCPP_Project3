 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
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
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */
struct Foot
{
    void stepForward();
    int stepSize();

};

void Foot::stepForward()
{
    //step
}

//defining outside of type declaration requires fully qualified name.
int Foot::stepSize()
{
    return 1; //sounds about right
}

struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;
    Foot leftFoot;
    Foot rightFoot;

    int run(int howFast, bool startWithLeftFoot);
};

//defining outside of type declaration requires fully qualified name.
int Person::run( [[maybe_unused]]int howFast, bool startWithLeftFoot)
{
    if(startWithLeftFoot)
    {
        return distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize();
    }
    return distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize();   
        
}

 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have warnings about 'unused parameter', you aren't using one of your function parameters in your implementation.
    use the parameter in your implementation.
    If you have warnings about 'overshadow', a local variable in the function has the same name as a class member.
    change the name of your local variable so it is different from the class member's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */


/*
Thing 1) Computer
 */
struct Computer
{ 
    struct GraphicsAccelerator
    {
        //number of cuda cores
        int numberOfCUDACores = 1200;
        //model name 
        std::string modelName = "default GPU";
        //is gsync capable
        bool isGSyncCapable = true;
        //price
        float price = 100.00f;
        //maximum SLI capability
        int maxSLICapability = 2;

        //accelerate the graphics
        void accelerateGraphics();//attempts to run code in parallel
        //set price of Graphics accelerator
        bool setPrice(float newPrice = 100.0f);
        //output cuda version and number of cores
        std::string outputCUDAVersionAndCores();//returns a string representing the cuda capbility 
    };

    //1) number of processor cores (int)
    int numberOfProcessorCores  = 4;
    //2) memory In GB (int)
    int memoryInGB = 16;
    //3) graphics accelerator (std::string)
    GraphicsAccelerator graphicsAccelerator;
    //4) motherboard type (std::string)
    std::string motherboardType = "ATX";
    //5) audio interface name (std::string)
    std::string audioInterfaceName = "Apogee";

    //1) run multiple processes 
    void runMultipleProcesses();
    //2) run memtest
    void runMemtest();
    //3) update Graphics Driver
    //return true on connection success
    bool updateGraphicsDriver(GraphicsAccelerator graphicsAccelerator);
    //input the graphics accelerator to update drivers for
    //returns true if driver updated successfully;

};
void Computer::GraphicsAccelerator::accelerateGraphics()
{
    //do nothing
}
bool Computer::GraphicsAccelerator::setPrice([[maybe_unused]]float toPrice)
{
    return false;
}
std::string Computer::GraphicsAccelerator::outputCUDAVersionAndCores()
{
    return "hello world";
}

void Computer::runMultipleProcesses()
{
    //imagine running in parallel
}
void Computer::runMemtest()
{
    //memtest
}
bool Computer::updateGraphicsDriver(GraphicsAccelerator gA)
{
    std::string throwAway = gA.outputCUDAVersionAndCores();  
    return true;
}

/*
Thing 2) Dog 
 */
struct Dog
{

    //1) hair color (std::string)
    std::string hairColor = "golden";
    //2) hair length in cm (float)
    float hairLengthInCM = 2.034467f;
    //3) number of teeth (int)
    int numberOfTeeth = 3;
    //4) length of tail in cm (float)
    float lengthOfTailInCm = 2.09f;
    //5) breed (std::string)
    std::string breed = "retriever";

    //1) bark
    void bark();
    //2) run
    void run();
    //3) fetch a toy
    bool fetch(std::string toy); //returns true if the dog fetched the toy
};

void Dog::bark()
{
    std::cout << "Fido barks" << std::endl;
}
void Dog::run()
{
    std::cout << "Fido runs" << std::endl;
}
bool Dog::fetch(std::string toy)
{
    std::cout << "Fido tried to fetch" << toy << "but fell down" << std::endl;
    return false;
}

/*
Thing 3) Teacher
 */
struct Teacher
{

    //1) credential type (std::string)
    std::string credentialType = "no credential";
    //2) domain expertise (std::string)
    std::string domainExpertise= "philosophy";
    //3) number of classes taught (int)
    int numberOfClassesTaught = 6;
    //4) years of tenure (float)
    float yearsOfTenure = 1;
    //5) rating by students (char)
    char ratingByStudents  = 'A';

    //1) give lecture
    void giveLecture();

    //2) private tutoring
    // returns the amount of money made from private tutoring
    float privateTutoring(float hourlyRate, int numberOfHours = 1); //input hourly rate and number of hours
    //3) assign homework
    void assignHomework(std::string homeworkAssignment);//input a string representation of the homework
};

void Teacher::giveLecture()
{

}
float Teacher::privateTutoring(float hourlyRate, int numberOfHours)
{
    return hourlyRate * numberOfHours;
}
void Teacher::assignHomework(std::string homeworkAssignment)
{
    std::cout << homeworkAssignment << " assigned to class" << std::endl;
}


/*
Thing 4) Audio Interface
 */
struct AudioInterface
{
    //1) number of inputs (int)
    int numberOfInputs = 2;
    //2) number of outputs (int)
    int numberOfOutputs = 2;
    //3) speaker volume level (float)
    float speakerVolumeLevel = -6.0;
    //4) color (std::string)
    std::string color = "red";
    //5) headphone volume level (float)
    float headphoneVolumeLevel = -6.0;

    //1) adjust levels
    float adjustLevels(float sliderMark); //returns the current level 
    //2) mute output
    bool muteOutput();//returns true if mute is on. false otherwise.
    //3) display input levels on GUI
    void displayInputLevelsOnGUI(float inputLevel1, float inputLevel2);//input to function is audio line in levels

};

float AudioInterface::adjustLevels([[maybe_unused]]float sliderMark)
{
    return 0.5;
}
bool AudioInterface::muteOutput()
{
    return true;
}
void AudioInterface::displayInputLevelsOnGUI(float inputLevel1, float inputLevel2)
{
    float nonsense = inputLevel1 * inputLevel2;
    std::cout << "displayed levels: " << nonsense << std::endl;
}

/*
Thing 5) Fingerboard
 */
struct Fingerboard
{

    //1) type of wood (std::string)
    std::string typeOfWood = "bamboo";
    //2) number of frets (int)
    int numberOfFrets = 23;
    //3) length in cm (float)
    float lengthInCm = 23.04f;
    //4) width in cm (float)
    float widthInCm = 6.9f;
    //5) number of inlays (int)
    int numberOfInlays = 7;

    //1) fret a note
    int fretANote(int stringNumber, int fretNumber);//returns midi pitch value of fretted note
    //2) require oil
    std::string requireOil(bool required);//returns a representation of the type of oil, if required
    //3) requre new frets
    bool requireNewFrets();//returns true if the fretboard requires new frets

};

int Fingerboard::fretANote(int stringNumber, int fretNumber)
{
    return stringNumber + fretNumber + 9000;
}
std::string Fingerboard::requireOil(bool required)
{
    if(required)
    {
        return "yes";
    }
    else
    {
        return "no";
    }
}
bool Fingerboard::requireNewFrets()
{
    return false;
}


/*
Thing 6) Tuning
*/
struct Tuning
{
    //1) string 1 midi tuning (int)
    int string1MidiTuning = 10;
    //2) string 2 midi tuning (int)
    int string2MidiTuning = 15;  
    //3) string 3 midi tuning (int)
    int string3MidiTuning = 20;
    //4) string 4 midi tuning (int)
    int string4MidiTuning = 25;
    //5) string 5 midi tuning (int)
    int string5MidiTuning = 30;

    //1) tune string up
    int tuneStringUp(); //returns pitch of string
    //2) tune string down
    int tuneStringDown(); //returns pitch of string;
    //3) set all string tunings
    void setAllStringTunings(int string1, int string2, int string3, int string4, int string5);
    //input a midi pitch value for each string
    //sets the Tuning member variables
};

int Tuning::tuneStringUp()
{
    std::cout << "up-tuned" << std::endl;
    return 100;
}
int Tuning::tuneStringDown()
{
    std::cout << "down-tuned" << std::endl;
    return 0;
}
void Tuning::setAllStringTunings(int string1, int string2, int string3, int string4, int string5)
{
    std::cout << "all-tuned to: " << string1 << ", " << string2 << ", " << string3 << ", "  << string4 << ", " << string5 << std::endl;   
}


/*
Thing 7) GuitarString
 */
struct GuitarString
{
    //1) gauge (int)
    int gauge = 14;
    //2) material name (std::string)
    std::string materialName = "nylon";
    //3) manufacturer name (std::string)
    std::string manufacturerName = "rippity doo";
    //4) cost in USD (float)
    float costInUSD = 10.50f;
    //5) is old and dirty (bool)
    bool isOldAndDirty = false;

    //1) require retuning
    bool requireRetuning();
    //2) snap
    bool snap();
    //3) become old and dirty
    void becomeOldAndDirty();//sets the strings member variable

};
    bool GuitarString::requireRetuning()
    {
        std::cout << "guitar is perpetually out of tune" << std::endl;
        return true;
    }
    bool GuitarString::snap()
    {
        return false;
    }
    void GuitarString::becomeOldAndDirty()
    {
        std::cout << "crusty, grimy, and dark, the string goes dull" << std::endl; 
    }


/*
Thing 8) Pickup
 */
struct Pickup
{
    //1) type of metal (std::string)
    std::string typeOfMetal = "gold";
    //2) number of pickups (int)
    int numberOfPickups = 2;
    //3) timbre discription (std::string)
    std::string timbreDescription = "warm";
    //4) is humbucker (bool)
    bool isHumbucker = false;
    //5) bypass (bool)
    bool bypassPickup = false;

    //1) bypass 
    void bypass(bool shouldBypass); //sets bypass member variable
    //2) sense flux field
    float senseFluxField();//returns the value of the fluxfield
    //3) buck the hum
    float buckTheHum(float inputWithHum);//transforms inputWithHum to output with hum bucked.

};

    void Pickup::bypass([[maybe_unused]]bool shouldBypass)
    {
        std::cout << "never bypass a great opportunity" << std::endl;
    }
    float Pickup::senseFluxField()
    {
        return 3.14159f;
    }
    float Pickup::buckTheHum(float inputWithHum)
    {
        return inputWithHum / 2.0f;
    }

/*
Thing 9) Tone Control
 */
struct ToneControl
{
    struct ToneAlgorithm
    {
        //1 tone color 1
        int color1 = 10;
        //2 tone color 2
        int color2 = 12;
        //3 tone color 3
        int color3 = 14;
        //4 upper Limit
        float upperLimit = 1.0f;
        //5 lower Limit
        float lowerLimit = 0.0f;

        //1 set tone colors
        void setToneColors(int color1, int color2, int color3);//input each color to set
        //2 set upper limit
        bool setUpperLimit(float upperLimit = 1.0f);
        //return true if success, else false;
        //3 set lower limit
        bool setLowerLimit(float lowerLimit = 0.0f);
        //return true if success, else false;
    };



    //1) front pickup tone control setting (float)
    float frontPickupToneControlSetting = 1.0f;
    //2) rear pickup tone control setting  (float)
    float rearPickupToneControlSetting = 1.0f;
    //3) knob color (std::string)
    std::string knobColor = "silver";
    //4) knob material (std::string)
    std::string knobMaterial = "plastic";
    //5) is smooth to turn (bool)
    bool isSmoothToTurn = true;

    //1) set tone level
    float setToneLevel(float inputLevel, float adjustment); //apply adjustment to the inputlevel
    //return the adjusted tone level

    //2) require repair
    bool requireRepair();//returns true if the tone control requires repair
    //3) auto adjust
    bool autoAdjust();//returns true if autoAdjust is turned on; else false 

};

    void ToneControl::ToneAlgorithm::setToneColors(int c1, int c2, int c3)
    {
        std::cout << "tone color set to " << c1 << ", " << c2 << ", " << c3 << std::endl;
    }

    bool ToneControl::ToneAlgorithm::setUpperLimit(float upperLimit1)
    {
        std::cout << upperLimit1 << std::endl;
        return true;
    }

    bool ToneControl::ToneAlgorithm::setLowerLimit(float lowerLimit1)
    {
        std::cout << lowerLimit1 << std::endl;
        return true;
    }

    float ToneControl::setToneLevel(float input, float adjust)
    {
        std::cout << input << " is good" << std::endl;
        float toReturn = input - adjust;
        std::cout << (input - adjust) << " is adjusted amount" << std::endl;

        return toReturn;
    }

    bool ToneControl::requireRepair()
    {
        return true;
    }

    bool ToneControl::autoAdjust()
    {
        return true;
    }

/*
Thing 10) Guitar
 */
struct Guitar
{

    //1) Fingerboard 
    Fingerboard fingerboard;
    //2) Tuning 
    Tuning tuning;
    //3) GuitarString 
    GuitarString guitarString;
    //4) Pickup 
    Pickup pickup;
    //5) Tone Control 
    ToneControl toneControl;

    //1) adjust tone
    bool adjustTone(Fingerboard fingerboard, float adjustAmount);//returns true if tone control adjusted the correct amount
    //2) tune a string
    int tuneAString(Tuning tuning, GuitarString guitarString, int toPitch);//input toPitch is the pitch to tune to guitarString to. Also, adjust the tuning to reflect the newly tuned string.
    // returns the value of pitch of the tuned string
    //3) sound a note
    void soundANote(int stringNumber, int fretNumber);//play audio through speakers

};

    bool Guitar::adjustTone(Fingerboard fb, float adj)
    {
        std::cout << "adjust tone by: " << adj << std::endl; 
        return fb.requireNewFrets();
    }
    int Guitar::tuneAString(Tuning t, GuitarString gs, int pitch)
    {
        if(gs.requireRetuning())
        {
            std::cout << "nice guitar string: " << std::endl;
        }       
        return t.tuneStringUp() * pitch / 2;
    }
    void Guitar::soundANote(int whichString, int whichFret)
    {
        std::cout << "string " << whichString << " sounds good" << "at fret " << whichFret << std::endl;
    }


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
