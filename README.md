# Railway Reservation System - Mini Project
## Problem Statement:
To write a C Program to check for the Availability of Trains, reserving a Ticket, Cancelling a Reserved Ticket, Preparing Chart in Railway Reservation System using Structures and File Pointers.
      This Railway Reservation System contains the following Procedures:
1)	Checking the Availability of Trains
2)	Booking or Reserving Tickets
3)	Cancellation of Tickets:
a.	Full Cancellation 
b.	Partial Cancellation
4)	 Chart Preparation
Here, Cancellation contains two procedures, that is, Full Cancellation and Partial Cancellation. The Full Cancellation cancels all the Tickets booked whereas the Partial Cancellation cancels a Single Ticket through the Name of the Ticket that is given by the User.
## Abstract:
Software has to be developed for automating the manual reservation system of railways. The System should standalone in Nature. It should be designed to provide functionalities like booking or reserving a ticket in which the user should be able to apply for the tickets of any train and of any class. The brief explanation about the reservation system is here:
## Reservation Details:
The Railway Reservation System facilitates the Passengers to enquire about the trains available on the basis of source and destination, Booking and Cancellation of Tickets, enquire about the status of the reserved ticket, etc. The aim of case study is to design and develop a Database maintaining the records of different trains, trains status, and details of the passengers. It is the Computerized System of Reserving a seat of the Train in advance. Online reservation has made the process for reservation of seats very much easier than before.
Objectives of this system it to be a user-friendly agency, to create a most effective utilization of resources and increase the performance human resource, to merge into very efficient catering services in the agency sector.
Some of the advantages of the Railway reservation system are – Convenient, Saves Time and Effort, Towards the Greener Planet, provides an information about the reservation status, availability of seats, Improved and Advanced customer support and facilitation through better industry techniques in the areas of rail catering, travel, hospitality and tourism.
## Algorithm:
1)	Start
2)	Declare Structures, Variables and File Pointers.
3)	Display the Welcome Screen & Menu Options.
4)	Develop the Procedures for Each Options.
5)	Call the Procedures [Availability Checking, Tickets Booking, Cancellation, Chart Display] for User chosen Options.
6)	Display the Available Trains, if Availability Checking was selected.
7)	Read the Inputs for Booking Tickets, if Ticket Booking was selected and do the following process:
a.	Check the Validation for the Input Data.
b.	Check for the Concession of Fees if Passenger is Senior Citizen (or) Child below 5 years.
c.	Detect the Concession Fees from the Charges, if 7b is True.
d.	Save (or) Append the Details of Every Passenger in a Text File.
8)	Cancel all the Tickets, if Full Cancellation was selected.
9)	Read the Inputs for Cancellation, if Partial Cancellation was selected.
a.	Cancel the Ticket, if the Input matches.
b.	Otherwise, Display the message “Tickets Not Found”.
10)	Display the messages for every Operations performed
11)	Display the Chart, if Chart Display was chosen
12)	Repeat Step 3 to Step 12 until Exit Option is Selected by the User
13)	 Stop
