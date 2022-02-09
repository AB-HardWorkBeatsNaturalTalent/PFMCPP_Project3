/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.



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

        GraphicsAccelerator();
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

    Computer();
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
Computer::Computer()
{
    std::cout <<"Computer being constructed" << std::endl;
}
Computer::GraphicsAccelerator::GraphicsAccelerator()
{
    std::cout <<"GraphicsAccelerator being constructed "<< std::endl;
}
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
    std::cout << "memtest running" << std::endl;
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

    Dog();
    //1) bark
    void bark();
    //2) run
    void run();
    //3) fetch a toy
    bool fetch(std::string toy); //returns true if the dog fetched the toy
};

Dog::Dog()
{
    std::cout <<"Dog being constructed" << std::endl;
}

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

    Teacher();
    //1) give lecture
    void giveLecture();

    //2) private tutoring
    // returns the amount of money made from private tutoring
    float privateTutoring(float hourlyRate, int numberOfHours = 1); //input hourly rate and number of hours
    //3) assign homework
    void assignHomework(std::string homeworkAssignment);//input a string representation of the homework
};

Teacher::Teacher()
{
    std::cout << "Teacher being constructed" << std::endl;
}
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

    AudioInterface();
    //1) adjust levels
    float adjustLevels(float sliderMark); //returns the current level 
    //2) mute output
    bool muteOutput();//returns true if mute is on. false otherwise.
    //3) display input levels on GUI
    void displayInputLevelsOnGUI(float inputLevel1, float inputLevel2);//input to function is audio line in levels

};
AudioInterface::AudioInterface()
{
    std::cout << "AudioInterface constructed" << std::endl;
}
float AudioInterface::adjustLevels([[maybe_unused]]float sliderMark)
{
    return 0.5;
}
bool AudioInterface::muteOutput()
{
    std::cout << "muted output" << std::endl;
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

    Fingerboard();
    //1) fret a note
    int fretANote(int stringNumber, int fretNumber);//returns midi pitch value of fretted note
    //2) require oil
    std::string requireOil(bool required);//returns a representation of the type of oil, if required
    //3) requre new frets
    bool requireNewFrets();//returns true if the fretboard requires new frets

};

Fingerboard::Fingerboard()
{
    std::cout << "Fingerboard being constructed" << std::endl;
}
int Fingerboard::fretANote(int stringNumber, int fretNumber)
{
    return stringNumber + fretNumber + 9000;
}
std::string Fingerboard::requireOil(bool required)
{
    if(required) return "yes";
    return "no";    
}
bool Fingerboard::requireNewFrets()
{
    std::cout << "the fretboard does not require new frets" << std::endl;
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

    Tuning();
    //1) tune string up
    int tuneStringUp(); //returns pitch of string
    //2) tune string down
    int tuneStringDown(); //returns pitch of string;
    //3) set all string tunings
    void setAllStringTunings(int string1, int string2, int string3, int string4, int string5);
    //input a midi pitch value for each string
    //sets the Tuning member variables
};
Tuning::Tuning()
{
    std::cout << "Tuning constructed" << std::endl;
}
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

    GuitarString();
    //1) require retuning
    bool requireRetuning();
    //2) snap
    bool snap();
    //3) become old and dirty
    void becomeOldAndDirty();//sets the strings member variable

};
GuitarString::GuitarString()
{
    std::cout << "GuitarString being constrcuted" << std::endl;
}
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

    Pickup();
    //1) bypass 
    void bypass(bool shouldBypass); //sets bypass member variable
    //2) sense flux field
    float senseFluxField();//returns the value of the fluxfield
    //3) buck the hum
    float buckTheHum(float inputWithHum);//transforms inputWithHum to output with hum bucked.

};
Pickup::Pickup()
{
    std::cout << "Pickup constructed" << std::endl;
}
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
    std::cout << "no more hum" << std::endl;
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

        ToneAlgorithm();
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

    ToneControl();
    //1) set tone level
    float setToneLevel(float inputLevel, float adjustment); //apply adjustment to the inputlevel
    //return the adjusted tone level

    //2) require repair
    bool requireRepair();//returns true if the tone control requires repair
    //3) auto adjust
    bool autoAdjust();//returns true if autoAdjust is turned on; else false 

};
ToneControl::ToneControl()
{
    std::cout << "ToneControl being constructed" << std::endl;
}
ToneControl::ToneAlgorithm::ToneAlgorithm()
{
    std::cout << "ToneAlgorithm constructing" << std::endl;
}
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

    Guitar();
    //1) adjust tone
    bool adjustTone(Fingerboard fingerboard, float adjustAmount);//returns true if tone control adjusted the correct amount
    //2) tune a string
    int tuneAString(Tuning tuning, GuitarString guitarString, int toPitch);//input toPitch is the pitch to tune to guitarString to. Also, adjust the tuning to reflect the newly tuned string.
    // returns the value of pitch of the tuned string
    //3) sound a note
    void soundANote(int stringNumber, int fretNumber);//play audio through speakers

};

Guitar::Guitar()
{
    std::cout << "Guitar being constructed" << std::endl;
}
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
    Example::main();
    
    
    std::cout << "good to go!" << std::endl;
}
