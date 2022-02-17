#pragma once
#include "LeakedObjectDetector.h"
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
        ~GraphicsAccelerator();
        //accelerate the graphics
        void accelerateGraphics();//attempts to run code in parallel
        //set price of Graphics accelerator
        bool setPrice(float newPrice = 100.0f);
        //output cuda version and number of cores
        std::string outputCUDAVersionAndCores() const;//returns a string representing the cuda capbility 

        void printMaxSLI();

        void boostTheGraphics(int toMultiply);
        int parallelSpeedIncreaseFactor(int desiredFactor);
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
    std::string audioInterfaceName;
    std::string computerName;

    Computer(std::string pcName);
    //1) run multiple processes 
    void runMultipleProcesses() const;
    //2) run memtest
    void runMemtest() const;
    //3) update Graphics Driver
    //return true on connection success
    bool updateGraphicsDriver(const GraphicsAccelerator& graphicsAccelerator) const;
    //input the graphics accelerator to update drivers for
    //returns true if driver updated successfully;
    double analyzeEnergyConsumption(int numberOfSecondsPoweredOn);
    std::string memoryTopologyBlocksPerCore();
    void printMemInGB();
    JUCE_LEAK_DETECTOR(Computer)
};
