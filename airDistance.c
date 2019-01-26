/*
 * Author: Evan L. Portz
 * Date: 01/25/2019
 * Class: CSCE 155E
 * Title: Hack #2
 * 
 * This program prompts the user to input two location's latitude and longitude in order to compute its air distance.
 * 
 */
#include <stdio.h>
#include <math.h>				// I'm using basic trigonometry functions to compute the distance formula
#include <stdbool.h>			// I'm using boolean equations to restrict input domains

int main()
{
	double latA = 0.0;			// Latitude of Location A, φ
	double longA = 0.0;			// Longitude of Location A
	double latB = 0.0;			// Latitude of Location B, φ
	double longB = 0.0;			// Longitude of Location B
	
	double airDistance;			// The final answer to the equation, d
	
	int earthRadius = 6371;			// Average radius of the Earth, R
	const double MATH_PIE = 3.141592;			// Value of pie, π

			printf("Enter location's A latitude: ");
			scanf("%lf", &latA);
					if ((latA >= -90) && (latA <= 90))			// These series of if statements and boolean equations are put here in order to prevent the user from inserting bad inputs
					{
						printf("Enter location's A longitude: ");
						scanf("%lf", &longA);
					
					if ((longA >= -180) && (longA <= 180)) 
					{
						printf("Enter location's B latitude: ");
						scanf("%lf", &latB);
					
					if ((latB >= -90) && (latB <= 90)) 
					{
						printf("Enter location's B longitude: ");
						scanf("%lf", &longB);
					
					if ((longB >= -180) && (longB <= 180)) 
					{
						double rlatA = (latA / 180) * MATH_PIE;			// These are conversions from degrees to radians
						double rlatB = (latB / 180) * MATH_PIE;			// This also creates a new variable holding the new value for the formula
						double rlongA = (longA / 180) * MATH_PIE;		// I decided to create a new variable in order for the user's input to be printed back correctly at the very end
						double rlongB = (longB / 180) * MATH_PIE;
						
						double deltaAB = rlongB - rlongA;			// This is the creation of delta in the formula, ∆
						
						airDistance = acos( (sin(rlatA) * sin(rlatB)) + (cos(rlatA) * cos(rlatB) * cos(deltaAB)) ) * earthRadius;			// This is the Spherical Law of Cosines formula
						
						printf("Location Distance\n========================\n");			// Finally, the user's inputs and the result are printed on screen
						printf("Origin:       (%f, %f)\n", latA, longA);
						printf("Destination:  (%f, %f)\n", latB, longB);
						printf("Air Distance is %f kms ", airDistance);
					}
					else 
					{
						printf("Invalid Input! ");			// These remaining else statements are intended to print "Invalid Input!" if the user enters a number out of the ranges for latitude and longitude
					return 0;
					}
					}
					else 
					{
						printf("Invalid Input! ");
					return 0;
					}
					}
					else 
					{
						printf("Invalid Input! ");
					return 0;
					}
					}
					else 
					{
						printf("Invalid Input! ");
					return 0;
					}
					
					return 0;
}


