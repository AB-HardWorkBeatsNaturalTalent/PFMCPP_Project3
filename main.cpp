/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.

 5) Remember to use pre-increment/decrement in your loops. 
 You can learn why post-increment/decrement is not ideal here:
 https://en.cppreference.com/w/cpp/language/operator_incdec 
 
 6) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            bar.num += 1;                    //2a)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()





/*
Thing 1) Computer
 */
struct Computer
{ 
    struct GraphicsAccelerator
    {
        //is gsync capable
        bool isGSyncCapable;
        //number of cuda cores
        int numberOfCUDACores;
        //model name 
        std::string modelName = "default GPU";
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

        void boostTheGraphics()
        {
            int testValue = 0;
            while(isGSyncCapable)
            {
                testValue = 1;
                std::cout << "Boosted!" << std::endl;
                break;
            }
            std::cout << "Out of Boost" << std::endl;
        } // part 5 begin.
        int parallelSpeedIncreaseFactor(int desiredFactor)
        {
            int totalCoresProcessing = 0;
            for(int i = 0; i <= int(price); ++i)
            {
                std::cout << "boosted processor core block i: " << i*desiredFactor << std::endl;
                totalCoresProcessing += i*desiredFactor;
                if(i == 6) break;
            }
            std::cout << "more money more problems solved" << std::endl;
            return totalCoresProcessing;
        }
        
    };

    //1) number of processor cores (int)
    int numberOfProcessorCores;
    //2) memory In GB (int)
    int memoryInGB;
    //3) graphics accelerator (std::string)
    GraphicsAccelerator graphicsAccelerator;
    //4) motherboard type (std::string)
    std::string motherboardType;
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

    double analyzeEnergyConsumption(int numberOfSecondsPoweredOn)
    {
        double consumed = numberOfSecondsPoweredOn * memoryInGB * .0345;
        if(graphicsAccelerator.isGSyncCapable)
        {
            consumed *= 4;
        }
        std::cout << "for the sake of science; energy consumed: " << consumed << std::endl;
        return consumed;

    }
    std::string memoryTopologyBlocksPerCore()
    {
        //number of cores & number of GB RAM
        auto memoryPerCore = memoryInGB / static_cast<double>(numberOfProcessorCores);
        
        std::string memoryTopology = "";        
        while(numberOfProcessorCores > 0)
        {
            for(int i = 0; i <= memoryPerCore; ++i)
            {
                memoryTopology += "block: ";
                memoryTopology += std::to_string(i);
                memoryTopology += "core :";
                memoryTopology += std::to_string(numberOfProcessorCores);
                memoryTopology += "\n"; 
            }
            numberOfProcessorCores--;
        }
        return memoryTopology;
    }

};
Computer::Computer() : numberOfProcessorCores(5), memoryInGB(32), motherboardType("micro ATX")
{
    std::cout << "Computer being constructed" << std::endl; 
}
Computer::GraphicsAccelerator::GraphicsAccelerator() : isGSyncCapable(true), numberOfCUDACores(1200)
{
    std::cout << "GraphicsAccelerator being constructed" << std::endl;
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
    std::cout << "memtest running on " << memoryInGB << "GB" << std::endl;
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
    std::string hairColor;
    //2) hair length in cm (float)
    float hairLengthInCM;
    //3) number of teeth (int)
    int numberOfTeeth;
    //4) length of tail in cm (float)
    float lengthOfTailInCm;
    //5) breed (std::string)
    std::string breed;

    float cutHairToNewLength(float newLengthInCm)
    {
        float amountCutOff = 0.0f;
        if(newLengthInCm < hairLengthInCM)
        {
            amountCutOff = hairLengthInCM - newLengthInCm;
            std::cout << "amount cut off:" << amountCutOff << std::endl;
            while(amountCutOff > 0)    
            {
                bark();
                amountCutOff--;
            }
        }
        return amountCutOff;
    }

    Dog();
    //1) bark
    void bark();
    //2) run
    void run();
    //3) fetch a toy
    bool fetch(std::string toy); //returns true if the dog fetched the toy
};

Dog::Dog() : hairColor("black"), hairLengthInCM(3.01f), numberOfTeeth(2), lengthOfTailInCm(6.09f), breed("pitbull")
{
    std::cout << "Dog being constructed" << std::endl;
}

void Dog::bark()
{
    std::cout << "Fido barks like a mean " << breed <<  std::endl;
}
void Dog::run()
{
    std::cout << "Fido runs with his " << hairColor << "blowing in the wind" << std::endl; 
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
    std::string domainExpertise;
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
    /*1) add some new member functions to EACH of your types.     
    2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold*/
    void sayMeaninglessNumbers(int startingWith)
    {
        if(startingWith > 0)
        {        
            int numberOfStuff = numberOfClassesTaught * startingWith;
            std::cout << "I have taught " << numberOfStuff << "things" << std::endl;
            std::cout << "that is " ;
            while(startingWith > 0)
            {
                std::cout << startingWith--;
            }
            std::cout << std::endl;
            return;
        }
        std::cout << "i have only taught 1 thing" << std::endl;        
    }
};

Teacher::Teacher() : domainExpertise("philosophy")
{
    std::cout << "Teacher being constructed" << std::endl;
}
void Teacher::giveLecture()
{
    std::cout << "class of " << domainExpertise <<std::endl;
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
    int numberOfInputs;
    //2) number of outputs (int)
    int numberOfOutputs;
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

    void changeInterfaceColor(std::string colorTo)
    {
        color = colorTo;
        for(int  i = numberOfInputs; i > 0 ; --i)
        {
            std::cout << color << std::endl;
            if(i%2 == 0)
            {
                color = "red";
                continue;
            }
            color = colorTo;
        }
        std::cout << "end color is: " << color << std::endl;
    }

};
AudioInterface::AudioInterface() : numberOfInputs(2), numberOfOutputs(4)
{
    std::cout << "AudioInterface constructed with" << numberOfInputs << "number of Inputs" << std::endl;
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
    std::string typeOfWood;
    //2) number of frets (int)
    int numberOfFrets;
    //3) length in cm (float)
    float lengthInCm;
    //4) width in cm (float)
    float widthInCm;
    //5) number of inlays (int)
    int numberOfInlays;

    Fingerboard();
    //1) fret a note
    int fretANote(int stringNumber, int fretNumber);//returns midi pitch value of fretted note
    //2) require oil
    std::string requireOil(bool required);//returns a representation of the type of oil, if required
    //3) requre new frets
    bool requireNewFrets();//returns true if the fretboard requires new frets

};

Fingerboard::Fingerboard() : typeOfWood("bamboo"), numberOfFrets(23), lengthInCm(23.4f), widthInCm(6.9f), numberOfInlays(3)
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
    int string1MidiTuning;
    //2) string 2 midi tuning (int)
    int string2MidiTuning;  
    //3) string 3 midi tuning (int)
    int string3MidiTuning;
    //4) string 4 midi tuning (int)
    int string4MidiTuning;
    //5) string 5 midi tuning (int)
    int string5MidiTuning;

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
Tuning::Tuning() : string1MidiTuning(1), string2MidiTuning(2), string3MidiTuning(3), string4MidiTuning(4), string5MidiTuning(10)
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
    int gauge;
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
GuitarString::GuitarString() : gauge(14)
{
    std::cout << "GuitarString being constrcuted" << std::endl;
}
bool GuitarString::requireRetuning()
{
    std::cout << "guitar is perpetually out of tune on " << gauge << "strings" << std::endl;
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
    std::cout << "Pickup constructed with " << typeOfMetal << "metal" << std::endl;
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
        int color1;
        //2 tone color 2
        int color2;
        //3 tone color 3
        int color3;
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
ToneControl::ToneAlgorithm::ToneAlgorithm(): color1(10), color2(11), color3(12)
{
    std::cout << "ToneAlgorithm constructing with upper limit: " <<  upperLimit << "and lower limit: " << lowerLimit <<std::endl;
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

//GraphicsAccelerator methods
    auto computerGraphicsAccelerator = Computer::GraphicsAccelerator();
    computerGraphicsAccelerator.outputCUDAVersionAndCores();
    computerGraphicsAccelerator.accelerateGraphics();
    computerGraphicsAccelerator.setPrice(400.0f);

    std::cout << "cuda info: " << computerGraphicsAccelerator.outputCUDAVersionAndCores() << std::endl;

//Computer methods
    auto computer = Computer();
    std::cout << "updated graphics: " << computer.updateGraphicsDriver(computerGraphicsAccelerator) << std::endl;
    computer.runMemtest();
    computer.runMultipleProcesses();

//Dog methods
    auto dog = Dog();
    dog.bark();
    dog.run();
    std::cout <<"successful fetch? :: " << dog.fetch(" a small baby child ") << std::endl;

//Teacher methods
    auto teacher = Teacher();
    teacher.assignHomework("lesson 2");
    teacher.giveLecture();    
    std::cout << "money made: " << teacher.privateTutoring(50.00f) << std::endl;

//AudioInterface methods
    auto audioInterface = AudioInterface();
    audioInterface.displayInputLevelsOnGUI(.67f, .84f);
    audioInterface.muteOutput();    
    std::cout << "level adjusted to: " << audioInterface.adjustLevels(.2f) << std::endl;

//Fingerboard methods
    auto fingerboard = Fingerboard();    
    fingerboard.requireNewFrets();
    fingerboard.requireOil(true);
    std::cout << "midi of fretted note: " << fingerboard.fretANote(1, 6) << std::endl;

//Pickup methods
    auto pickup = Pickup();
    pickup.bypass(true);
    pickup.buckTheHum(23.9f);    
    std::cout << "fluxfield is: "  << pickup.senseFluxField() << std::endl;


//Tuning methods
    auto tuning = Tuning();
    tuning.setAllStringTunings(1, 3, 5, 7, 9);
    tuning.tuneStringDown();
    std::cout << "up-tuned string pitch" << tuning.tuneStringUp() << std::endl;

//GuitarString methods
    auto guitarString = GuitarString();
    guitarString.becomeOldAndDirty();
    guitarString.requireRetuning();    
    std::cout << "did it snap: " << guitarString.snap() << std::endl;


//ToneControl methods
    auto toneControl = ToneControl();  
    toneControl.setToneLevel(3.9f, 2.0f);
    toneControl.requireRepair();
    std::cout << "auto adjusted tone: "  << toneControl.autoAdjust() << std::endl;

//ToneAlgorithm methods
    auto toneAlgorithm = ToneControl::ToneAlgorithm();
    toneAlgorithm.setUpperLimit(1.09f);
    toneAlgorithm.setToneColors(1, 2, 3);
    std::cout << "lower limit set to:" << toneAlgorithm.setLowerLimit(.02f) << std::endl;

//Guitar methods
    auto guitar = Guitar();
    guitar.soundANote(3, 9);
    guitar.tuneAString(tuning, guitarString, 12);
    std::cout << "guitar tone adjusted" << guitar.adjustTone(fingerboard, 1.09f) << std::endl;

    std::cout << "good to go!" << std::endl;
}
