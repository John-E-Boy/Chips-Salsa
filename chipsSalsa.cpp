#include <iostream>
#include <iomanip>
#include "input.h"
using namespace std ; 

// Prototypes
void fillJarsSoldArray(int arJar[], string arName[], const int s) ;
void printSales(int arJar[], string arName[], const int s) ;
void getHighestLowestSelling(int& high, int& low, int arJar[], const int s) ;
int getTotal(int arJar[],const int s) ;


int main(){

  const int size = 5 ; // Use in for loops, equal to array size 
  string arNames[size] = {"mild" ,"medium", "sweet" , "hot" , "zesty"} ; // Intialize name array 
  int arJars[size] ; // Intialize sale array
  int totals ; // For keeping total
  int highest = 0 ; // For getting highest 
  int lowest = 0 ; // For getting lowest

  // Get sales numbers
  fillJarsSoldArray(arJars, arNames, size) ; 
  
  // Print sales numbers
  printSales(arJars, arNames, size) ;
  cout << endl ; 

  // Get total jars sold
  totals = getTotal (arJars, size) ;
  
  // Get highest and lowest
  getHighestLowestSelling (highest, lowest, arJars, size ) ;
  cout << endl ; 

  // Display total, highest, and lowest
  cout << "The total number of jars sold is " << totals << endl ; 
  
  cout << "The highest selling type is " << arNames[highest] << endl ; 
  
  cout << "The highest selling type is " << arNames[lowest] << endl ;
  

  return 0 ;
}



// This function will get the number of jars sold
void fillJarsSoldArray(int arJar[], string arName[], const int s)
{
  for (int i = 0 ; i < s ; i++)
    {
      
      cout << "Enter the number of jars sold for " << arName[i] << ": " ;
      arJar[i] = getInt(0,1000000, "Invalid. Enter a number between 0 and 1000000: ") ;
      cout << endl ; 
    }
  cout << endl ; 
}

// This function will print out the number of jars sold and the type sold
void printSales(int arJar[], string arName[], const int s)
{
  for (int i = 0; i < s; i++)
    {
      cout << left << setw(10) <<  arName[i] << right<< setw(10) << arJar[i] << endl ;
    }
}

// This function will get the culmulative amount of jars sold
int getTotal(int arJar[], const int s)
{
  
  int total = 0 ;
  
  for (int i = 0; i < s ; i++)
    {
      total = arJar[i] + total ;
    }

  return total ;
}

// This function will find the lowest and highest amount sold
void getHighestLowestSelling(int& high, int& low, int arJar[], const int s)
{
 
   for (int i = 0; i < s; i++)
    {
      if (arJar[high] < arJar[i])
	{
	  high = i ; // Get highest 
	}

      if (arJar[low] > arJar[i])
	{
	  low = i ; // Get lowest 
	}
    }
}
