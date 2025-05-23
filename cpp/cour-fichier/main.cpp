#include <iostream>  
#include <fstream>  
#include <filesystem> // Ensure this is included for std::filesystem  

using namespace std;  

int main()  
{
    const char *filePath = "../../../input.txt"; // Relative path to the file
   std::ifstream inputFile(filePath);  

   if (!inputFile) {  
       std::cerr << "Error opening file.\n";  
       // Correct placement of std::filesystem::current_path()  
       std::cout << "Current working directory: " << std::filesystem::current_path() << '\n';  
       return 1;  
   }

   std::cout << "Reading from file...\n";

   /*std::string line;
   while (std::getline(inputFile, line)) {
       std::cout << line << '\n';
   }*/

   /*char c;
   while (inputFile.get(c)) {
       std::cout << c;
   }*/

   int number;
   while (inputFile >> number) {
       std::cout << number << '\n';
   }

   inputFile.close();  
   return 0;  
}
