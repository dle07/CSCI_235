/*
Title: Project 0
Files: Bicycle.cpp,Bicycle.hpp
Author: Daniel Le
Email : daniel.le05@myhunter.cuny.edu
Course:CSCI 235000
Instructor: Gennadiy Maryash
Description: Preliminary project for the course, project 0. Refreshes student's ability and knowledge on classes,
implementing classes, methods, enums, consturctors, etc. by having them create a Bicycle class that models a bicycle, their aspects, functionalities, etc.
*/

#include "Bicycle.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
using namespace std;


// b_type_{rand()% 4}  // My function to convert a integer to the enum type through casting

Bicycle :: Bicycle(): curr_direction_{0.0},curr_speed_{0.0},curr_pedal_intensity_{bike_details::NONE}, 
seat_height_{10}, b_type_{bike_details::bike_type(rand()%4)} , distance_traveled_{0.0}{

};   


Bicycle :: Bicycle(int kind_of_bike): curr_direction_{0.0},curr_speed_{0.0},
curr_pedal_intensity_{bike_details::NONE}, seat_height_{10}, b_type_{bike_details::bike_type(kind_of_bike)} , distance_traveled_{0.0}{

};      //Implemented using initalization list, which is true initalizaiton

// PART 2 ****************************************************PART 2 ***************************************************************************

//Simple conditional logic    

string Bicycle :: getDirection(){
    if( curr_direction_ ==90.0){return "North";}

    else if( curr_direction_ > 0.0 && curr_direction_ < 90.0) {return "Northeast";}

    else if(curr_direction_ == 0.0 || curr_direction_ == 360.0) {return "East";}
    else if( curr_direction_ > 270.0 ) {return "Southeast";}
    else if( curr_direction_ == 270.0) {return "South";}
    else if( curr_direction_ > 180.0 && curr_direction_ <270.0) {return "Southwest";}
    else if( curr_direction_ == 180.0) {return "West";}
    else if( curr_direction_ >90.0 and curr_direction_ <180.0) return "Northwest";
    else{
        return "Error Happened";        //Used to check errors
    }
};

std :: string Bicycle :: getBikeType(){             //get string version of b_type_
    switch(b_type_){
        case 0: return "BMX";
        case 1: return "MOUNTAIN";
        case 2: return "TOURING";
        case 3: return "ROAD";
    }
};  


int Bicycle :: getSeatHeight(){      // seat_height_
    return seat_height_;
};         

float Bicycle ::  getSpeed(){           // curr_speed_
    
    return curr_speed_;
};            

float Bicycle :: getDistanceTraveled(){         // distance_traveled_
    return distance_traveled_;
}; 

string Bicycle :: getIntensity(){        // curr_pedal_intensity_ in string form of name
    switch(curr_pedal_intensity_){
        case 0: return "None";
        case 44: return "Low";
        case 88: return "Medium";
        case 132: return "High";
    }
};         



void Bicycle :: changeSeatHeight(int inches){
    if( inches >36){inches =36;}            // The constaints for inches is 0 <= inches  <=36, thus if its greater than 36, set inches to 36
    else if( inches <0){ inches =0;}             //if inches is negative, set inches to 0
    
    seat_height_ = inches;

};    

/** 
    updates direction_
    @param degrees: -360 <= degrees <= 360, and if the 
        user enters a number outside of these bounds        fmod(temp,360.0)
        adjust @param degrees to be within this range
*/
void Bicycle :: turn(float degrees){            // By the terminal angle theorem, all angles can be represented as itself +- 360 degrees,
                                                //thus if the degrees is greater than 360 or less than -360, the TERMINAL angle( the angle we're 
                                                // only concerned with ) is the remainder of degrees /360.0, aka. degrees modulus 360.0
    if( degrees < -360 || degrees >360){
        degrees = fmod(degrees, 360.0);
    }
    curr_direction_ += degrees;
    if( curr_direction_ <0) { curr_direction_ +=360;}       //If the curr direction is negative, we want to represent it in positive terms, so conduct a full rotation counter clockwise
    if( curr_direction_ >360.0){                            //If the curr_direction is still > 360, take the modulus again.
        curr_direction_= fmod(degrees,360.0);
    }
}


/**
    alters curr_speed_ depending on curr_speed_, 
        curr_pedal_intensity_, and b_type_
        
    USE THE FOLLOWING FORMULA: 
        [ (pedal intensity) / 8 ] * (bike type) + [ (pedal intensity) / 8 + (bike type) ]
*/
void Bicycle :: updateSpeed(){
    if( curr_pedal_intensity_ ==0){         //checks edge case, this is needed because the formula given above doesn't accomodate for the case in which the pedal intensity is none, or 0. This will cause speed to be 1
                                            // because you're adding 0+0+1 when all the computations are done given by the formula so we need to first check for the edge case.
        curr_speed_ =0;
        return;
    }
    curr_speed_ = ( (curr_pedal_intensity_ / 8)  * (b_type_)) +   ((curr_pedal_intensity_ / 8) + b_type_);          //Updates curr_speed_ by given formula
};


//PART 3*************************************************************************************************************


/**
   if the current intensity is not HIGH,
       increase it by one level and call updateSpeed()
*/
void Bicycle :: pedal(){
    if( getIntensity() != "High"){
        curr_pedal_intensity_ = bike_details:: pedalling_intensity(curr_pedal_intensity_ +44);
        updateSpeed();
    }
};

/**
   if the current intensity is not NONE,
       decrease it by one level and call updateSpeed()
*/
void Bicycle :: brake(){
    if( getIntensity() != "None"){
        curr_pedal_intensity_ = bike_details:: pedalling_intensity (curr_pedal_intensity_ -44);
        updateSpeed();
    }
};

/**
    given curr_speed_, curr_pedal_intensity_, b_type_, 
        and @param float duration, calculate the 
        distance traveled during the specified time;
        increment distance_traveled_ by this amount
    @param float duration: time traveled
    @return: updated distance_traveled_
*/
float Bicycle :: ride(float duration){              // By the formula for distance, it's velocity * duration
    updateSpeed();
    distance_traveled_ += curr_speed_ * duration;
    return distance_traveled_;
};

