# Project HiveMind

## What is Project HiveMind?

Project HiveMind is a project to create modular distributed computation system. That can distributed computation across multiple computers, and allow for the creation of complex distributed systems. It is designed to be modular, and allow for the creation of new modules to add new functionality.

## How does it work?

Project HiveMind is a distributed system, that uses a master/slave architecture. The master is responsible for distributing work to the slaves, and the slaves are responsible for executing the work. Shared Library(.dll file) is distributed across the network, and loaded into the slave processes. The master and slave communicate using a custom protocol, and the slaves communicate with each other using a custom protocol.
