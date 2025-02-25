//
//  main.cpp
//  CS3360-Code4 - Variance & SetOperations
//
//  Created by Darren Bowers on 2/20/25, following Professor Manouchehr Mohandesi's examples.
//

#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <numeric>

using std::cout;
using std::endl;
using std::set; 
using std::vector;

// Function to calculate probability of a set
double probability(set<int>& event, set<int> space){
    return (static_cast<double>(event.size())/space.size());
}

// Function for Set Union (A ∪ B)
set<int> set_union(set<int>& sub1, set<int>& sub2){
    set<int> result = sub1;
    result.insert(sub2.begin(), sub2.end());
    return result;
}

// Function for Set Intersection (A ∩ B)
set<int> set_intersection(set<int>& sub1, set<int>& sub2){
    set<int> result;
    for(int element : sub1){
        if(sub2.find(element) != sub2.end()){
            result.insert(element);
        }
    }
    return result;
}

// Function for Set Complement
set<int> set_complement(set<int>& sub1, set<int>& space){
    set<int> result;
    for(int element : space){
        if(sub1.find(element) == sub1.end()){
            result.insert(element);
        }
    }
    return result;
}

// Function for Expected Value (E[x])
double expected_value(vector<int>& ranVar, vector<double>& probs){
    double expectValue = 0.0;
    for(size_t i=0; i<ranVar.size(); i++){
        expectValue+=ranVar[i]*probs[i];
    }
    return expectValue; 
}

// Function for Variance (var(x)=E[x^2]-E[x]^2)
double variance(vector<int> ranVar, vector<double> probs){
    double varValue = 0.0;
    for(size_t i=0; i<ranVar.size(); i++){
        varValue += (ranVar[i]*ranVar[i]*probs[i]);
    }
    double E_X = expected_value(ranVar,probs);
    varValue = varValue-(E_X*E_X);
    return varValue;
}

int main (){

    // Sample Space S={1,2,3,4,5,6,7,8,9,10}
    set<int> sample_space ={1,2,3,4,5,6,7,8,9,10};

    // Event Samples for Set A and Set B
    set<int> A={1,2,3};
    set<int> B={3,6,7,8,9};

    // Calculate probability of events

    double P_A = probability(A, sample_space);
    double P_B = probability(B, sample_space);

    // Set for union of A and B

    set<int> A_union_B = set_union(A,B);
    double P_A_Union_B = probability(A_union_B, sample_space);

    // Set for intersection of A and B
    set<int> A_intersection_B = set_intersection(A,B);
    double P_A_Intersection_B = probability(A_intersection_B, sample_space);

    // Set complement of A (A_bar)
    set<int> A_bar = set_complement(A, sample_space);
    double P_A_bar = probability(A_bar, sample_space);

    // Display probabilities
    cout << "P(A) = " << P_A << endl;
    cout << "P(B) = " << P_B << endl;
    cout << "P(A ∪ B) = " << P_A_Union_B << endl;
    cout << "P(A ∩ B) = " << P_A_Intersection_B << endl;
    cout << "P(Ᾱ) = " << P_A_bar << endl;

    // Modeling a random variable X with probabilies
    // Example: x={1,2,3}, Probabilities={0.2,0.5,0.3}
    vector<int> random_variable = {9,6,4};
    vector<double> probabilities = {0.1,0.7,0.2};

    // Calculated expected value E[x]
    double E_X = expected_value(random_variable, probabilities);
    cout << "E[x] = " << E_X << endl;

    // Calculated variance var(x)
    double var_X = variance(random_variable, probabilities);
    cout << "Var(x) = " << var_X << endl;

    return 0;
}