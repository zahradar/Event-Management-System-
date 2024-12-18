# Event Management System

## Overview
This Event Management System allows organizers and customers to manage and plan events. It includes features for adding, viewing, updating, and deleting events, as well as managing budgets and generating slips for events.

### Key Features:
- **Organizer Features:**
  - View Events
  - Delete Events
  - Delete Specific Event Details (e.g., Food, Lighting, Decor costs)
  
- **Customer Features:**
  - Add Events
  - Update Events
  - View Events
  - Generate Event Slips
  - Manage Event Budgets
  
## Project Requirements
- **Compiler:** C++ (Any standard C++ compiler, such as GCC or MSVC)
- **Libraries:** 
  - `<iostream>` for input/output operations
  - `<cstdlib>` for clearing the console and using system commands
  - `<string>` for handling strings
  
## Installation Instructions
1. Clone or download the repository containing the source code.
2. Open the project in your preferred C++ IDE.
3. Compile and run the program using your C++ compiler.

## Usage
Once the program is running:
1. You will be prompted to choose between **Organizer** and **Customer** options.
2. Organizers can view, delete, or modify event details.
3. Customers can add new events, update existing ones, manage budgets, and generate event slips.
4. Follow the on-screen prompts to make selections and input data.

### Example:
- **Organizers:** You can view all events, delete an event, or delete specific event details like food, lighting, or decor costs.
- **Customers:** You can add a new event by entering details such as event name, date, location, and associated costs. You can also update the event details or generate a slip containing event details and budget.

## Event Data Structure

The system uses a structure `Event` to store the following information for each event:

- **name**: Name of the event
- **date**: Date of the event
- **location**: Location of the event
- **time**: Event type (Indoor/Outdoor)
- **budget**: Total event budget
- **foodCost**: Cost for food
- **lightingCost**: Cost for lighting
- **decorCost**: Cost for decor

## Menu Options

- **Organizer Menu**:
  1. View Events
  2. Delete Event
  3. Delete Specific Detail from Event
  4. Back to Main Menu

- **Customer Menu**:
  1. Add Event
  2. Update Event
  3. View Events
  4. Generate Slip
  5. Manage Budget
  6. Back to Main Menu

## How It Works
1. **Add Event**: Customers can add new events, entering the name, date, location, and costs.
2. **Update Event**: Existing events can be updated with new details such as food cost, lighting cost, or location.
3. **Generate Slip**: A printable slip with event details and budget will be generated.
4. **Delete Event/Details**: Events or specific details (food, lighting, decor costs) can be deleted by the organizer.
5. **Manage Budget**: The organizer can manage the budget for each event.
