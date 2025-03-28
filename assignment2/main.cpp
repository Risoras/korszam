#include <cmath>
#include <iostream>
#include "vector.hpp"

bool vector_compare(Vector2d<double> const& V1, Vector2d<double> const& V2);  //compares two vectors, returns "true" if they are the same, made it so that I have to type less



int main()            // tests vector.hpp to see if it works correctly
{

    std::cout << "this tests vector.hpp \n";

    Vector2d<double> v{};                     // testing "<<" and ">>"
    std::cout << "give a vector: \n";
    std::cin >> v;
    std::cout << v << "\n" << "cin and cout work \n";

    Vector2d<double> v1{2.5, 3.6}, v2{-4.7, 1.2};     // vectors I'll use to test vector.hpp
    double a = 1.4, b = 2;

    Vector2d<double> add_check{-2.2, 4.8}, sub_check{7.2, 2.4}, div_check{1.25, 1.8}, mult_check{3.5, 5.04};    // correct values for vector operations I calculated by hand
    double dot_check = -7.43, length_check = 4.3829214, sqlength_check = 19.21;

    double error = 1e-7;   // maximum difference between pre-calculated values and vector.hpp operators/functions
    int problems = 0;      // to count how many operators/functions don't work

    Vector2d v_add = v1 + v2, v_sub = v1 - v2, v_multL = a * v1, v_multR = v1 * a, v_div = v1/b;   // vector operators which will be checked for accuracy/function
    Vector2d v11 = v1, v12 = v1, v13 = v1, v14 = v1;      // I have to copy v1 for the assignment operators
    v11 += v2;
    v12 -= v2;
    v13 *= a;
    v14 /= b;

// this is (too) many if statements to check if vector operations work correctly (I have no better idea how to do it)

    if ( abs(sqlength(v1) - sqlength_check) > error ){     // checks the sqlength() function
        std::cout << "square length doesn't work \n";
        problems++;
    }

    if ( abs(length(v1) - length_check) > error ){     // checks the lenght() function
        std::cout << "length doesn't work \n";
        problems++;
    }

    if ( abs(dot(v1, v2) - dot_check) > error){       // checks the dot() function
        std::cout << "dot doesn't work \n";
        problems++;
    }

    if ( vector_compare(v_add, add_check) == false){     // checks the "+" operator
        std::cout << "addition doesn't work \n";
        problems++;
    }

    if ( vector_compare(v_sub, sub_check) == false){     // checks the "-" operator
        std::cout << "subtraction doesn't work \n";
        problems++;
    }

    if ( vector_compare(v_multL, mult_check) == false){           // checks the "*" operator from the left
        std::cout << "scalar multiplication from the left doesn't work \n";
        problems++;
    }

    if ( vector_compare(v_multR, mult_check) == false){           // checks the "*" operator from the right
        std::cout << "scalar multiplication from the right doesn't work \n";
        problems++;
    }

    if ( vector_compare(v_div, div_check) == false){                  // checks the "/" operator
        std::cout << "division by scalar doesn't work \n";
        problems++;
    }

    if ( vector_compare(v11, add_check) == false){                   // checks the "+=" operator
        std::cout << "+= doesn't work \n";
        problems++;
    }

    if ( vector_compare(v12, sub_check) == false){            // checks the "-=" operator
        std::cout << "-= doesn't work \n";
        problems++;
    }

    if ( vector_compare(v13, mult_check) == false){             // checks the "*=" operator
        std::cout << "*= doesn't work \n";
        problems++;
    }

    if ( vector_compare(v14, div_check) == false){            // checks the "/=" operator
        std::cout << "/= doesn't work \n";
        problems++;
    }


    if (problems == 0) {
        std::cout << "everything works";
    } else {
        std::cout << "number of problems: \n" << problems;
    }

    return 0;
}





bool vector_compare(Vector2d<double> const& V1, Vector2d<double> const& V2) {


    bool same = false;
    if (abs(V1.x - V2.x) < 1e-7 && abs(V1.y - V2.y) < 1e-7) {
        same = true;
    }

    return same;
}

