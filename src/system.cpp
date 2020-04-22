#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"
#include "processor.h"
#include "system.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

// Define custom constructor
System::System()
    : os_(LinuxParser::OperatingSystem()), kernel_(LinuxParser::Kernel()){
        
        // Initialize processor
        Processor processor;
        cpu_ = processor;

        // Initialize processes
        vector<int> pids = LinuxParser::Pids();
        for (int pid : pids) {
            processes_.push_back(Process(pid));
        }

    };

//  -  Return the system's CPU
Processor& System::Cpu() { return cpu_; }

//  -  Return a container composed of the system's processes
vector<Process>& System::Processes() { return processes_; }

//  -  Return the system's kernel identifier (string)
std::string System::Kernel() { return kernel_; }

//  -  Return the system's memory utilization
float System::MemoryUtilization() { return LinuxParser::MemoryUtilization(); }

//  -  Return the operating system name
std::string System::OperatingSystem() { return os_; }

//  -  Return the number of processes actively running on the system
int System::RunningProcesses() { return LinuxParser::RunningProcesses(); }

//  -  Return the total number of processes on the system
int System::TotalProcesses() { return LinuxParser::TotalProcesses(); }

//  -  Return the number of seconds since the system started running
long int System::UpTime() { return LinuxParser::UpTime(); }