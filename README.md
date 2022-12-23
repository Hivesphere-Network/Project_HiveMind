# Project HiveMind

## What is Project HiveMind?

Project HiveMind is a project to create modular distributed computation system. That can distributed computation across multiple computers, and allow for the creation of complex distributed systems. It is designed to be modular, and allow for the creation of new modules to add new functionality.

## How does it work?

Project HiveMind is a distributed system, that uses a master/slave architecture. The master is responsible for distributing work to the slaves, and the slaves are responsible for executing the work. Shared Library(.dll file) is distributed across the network, and loaded into the slave processes. The master and slave communicate using a custom protocol, and the slaves communicate with each other using a custom protocol.

## Building Project HiveMind

### Prerequisites

* Visual Studio 2022
* Premake 5.0.0-beta2

### Building

1. Clone the repository using `git clone --recursive https://github.com/PramudithaPothuwila/Project_HiveMind.git`
2. Run `premake5 vs2022` to generate the Visual Studio 2022 solution.
3. Open the solution in Visual Studio 2022 and build the solution.

