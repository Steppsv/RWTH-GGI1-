# Traffic Simulation System (C++)

This project implements a modular traffic simulation in C++ using object-oriented design. The system models different types of vehicles (e.g., cars and bicycles) moving through a road network with intersections, speed limits, and dynamic behavior.

The simulation supports both console-based output and graphical visualization via an external GUI framework provided with the assignment.

## Key Features
- Object-oriented design with inheritance (Fahrzeug → PKW, Fahrrad)  
- Simulation of vehicle dynamics (speed, acceleration, fuel consumption)  
- Road (Weg) and intersection (Kreuzung) modeling  
- Support for multiple road types with speed limits (e.g., Autobahn, Landstraße)  
- Time-based simulation using a global simulation clock  
- Dynamic vehicle behavior and state updates per simulation step  
- Integration with external graphical visualization (GUI)  

## System Overview
The simulation models a network of roads and intersections. Vehicles are created and assigned to roads, where they move according to defined physical and behavioral rules.

Each simulation step:
1. Advances the global simulation time  
2. Updates all vehicles (movement, fuel consumption, etc.)  
3. Handles transitions between roads and intersections  
4. Updates the graphical visualization (if enabled)  

## Architecture
- **Fahrzeug** – base class for all vehicles  
- **PKW / Fahrrad** – derived vehicle types with specific behavior  
- **Weg** – represents a road segment  
- **Kreuzung** – manages connections between roads  
- **Simulation loop** – controls time progression and updates  

The system makes extensive use of:
- Smart pointers (`unique_ptr`, `shared_ptr`)  
- Polymorphism and virtual functions  
- Modular class structure for extensibility  

## Tech Stack
- C++  
- Object-Oriented Programming (OOP)  
- STL (containers, algorithms, smart pointers)  
- External visualization library (provided GUI framework)  

## How to Run
Compile all source files and run the executable:

```bash
g++ src/*.cpp -o simulation
./simulation
