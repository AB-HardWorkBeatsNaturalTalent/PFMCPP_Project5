#include "Computer.h"
Computer::Computer(std::string pcName) : numberOfProcessorCores(5),  memoryInGB(32), motherboardType("micro ATX"), audioInterfaceName("ableton"), computerName(pcName)
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
std::string Computer::GraphicsAccelerator::outputCUDAVersionAndCores() const
{
    return "hello world";
}

void Computer::GraphicsAccelerator::printMaxSLI()
{        
    std::cout << "max sli capability: " << this->maxSLICapability << std::endl;
}

void Computer::runMultipleProcesses() const
{
    //imagine running in parallel
}
void Computer::runMemtest() const
{    
    std::cout << "memtest running on " << memoryInGB << "GB" << std::endl;
}
bool Computer::updateGraphicsDriver(const GraphicsAccelerator& gA) const
{
    std::string throwAway = gA.outputCUDAVersionAndCores();  
    return true;
}
void Computer::printMemInGB()
{
    std::cout << this->memoryInGB << " GB of RAM in this model" << std::endl;
}

Computer::GraphicsAccelerator::~GraphicsAccelerator()
{
    std::cout << "GraphicsAccelerator destructor" << std::endl;
}
void Computer::GraphicsAccelerator::boostTheGraphics(int multiply)
{
    if(multiply >0)
    {
        int testValue = 0;
        while(multiply > 0)
        {
            ++testValue;
            std::cout << "Boosted!" << std::endl;
            --multiply;
        }
        std::cout << "Out of Boost" << std::endl;
    }
    else
    {
        std::cout << "zero or negative boost only" << std::endl;
    }
} // part 5 begin.

int Computer::GraphicsAccelerator::parallelSpeedIncreaseFactor(int desiredFactor)
{
    int totalCoresProcessing = 0;
    for(int i = 0; i <= maxSLICapability; ++i)
    {
        std::cout << "boosted processor core block i: " << i * desiredFactor << std::endl;
        totalCoresProcessing += i * desiredFactor;
        if(i == 6) break;
    }
    std::cout << "more money more problems solved" << std::endl;
    return totalCoresProcessing;
}

double Computer::analyzeEnergyConsumption(int numberOfSecondsPoweredOn)
{
    double consumed = numberOfSecondsPoweredOn * memoryInGB * .0345;
    if(graphicsAccelerator.isGSyncCapable)
    {
        consumed *= 4;
    }
    std::cout << "for the sake of science; energy consumed: " << consumed << std::endl;
    return consumed;

}

std::string Computer::memoryTopologyBlocksPerCore()
{
    //number of cores & number of GB RAM
    int memoryPerCore = memoryInGB / numberOfProcessorCores;
    
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
        --numberOfProcessorCores;
    }
    return memoryTopology;
}
