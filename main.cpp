**************************************************************************/

#include <iostream>
#include <numeric> //used only for library type method
using namespace std;



int main (int argc, char **argv)
{

  cout << "You have entered " << argc << " arguments:" << "\n";

  //if wrong number of inputs are there
  if (argc <= 2)
    {
      cout << "Incorrect number of arguments " << endl;
      return 0;
    }


  int i = 2;
  int result = 0;
    
  //if user inputs pointer as a first argument  
  if(std::string(argv[1]) == "pointer") 
    {

  //loop through all the argv
  for (int index = 2; index < argc; index++)
	{
	
    //convert char* to long and then calculate sum
	  long arg = strtol (argv[index], NULL, 10);
	  result = result + arg;

	}

   //final result
   cout << "Result using pointer is " << result << endl;
   return 0;
  }

   //if library is the input by user
   else if(std::string(argv[1]) == "library") // Works fine
    {

    long arg[argc-2]; //total number of element minus first two being function name and type of calculation
    int index = 0;
    for (index = 2; index < argc; index++)
	{
	  
    //populate array of long
	  arg[index-2] = strtol (argv[index], NULL, 10);
	}
	
     int result = 0;
     //using stl function for sum,
     result = accumulate(arg,arg+index-2, result);
      

      cout << "Result using library is " << result << endl;
      return 0;
    }
    
    else
    {
        return 0;
    }



  return 0;
}
