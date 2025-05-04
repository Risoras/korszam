#include <cmath>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <string>



int const N = 1000;             //number of gas particles

double const a = 30;          //cube's edge length
double const Vmax = 4000000000000;       //maximum initial velocity
double const epsilon = 10.22;




struct gas{                     //stores the gas's properties

    double position [N][3];
    double velocity [N][3];
    double acceleration [N][3];
};


void initial_conditions (gas& G) {


    int p = 0;

    for (int i = 0; i < 10; i++)     // initial positions

        for (int j = 0; j < 100; j++){

            G.position[p][0] = (i+0.5)*a/10 ;
            G.position[p][1] = (i+0.5)*a/10 ;
            G.position[p][2] = (i+0.5)*a/10 ;
            p++;
        }

    for (int i = 0; i < N; i++ )       // initial velocities 
    {
        G.velocity[i][0] = Vmax * (2* std::rand() / RAND_MAX -1);
        G.velocity[i][1] = Vmax * (2* std::rand() / RAND_MAX -1);
        G.velocity[i][2] = Vmax * (2* std::rand() / RAND_MAX -1);
    }


}

void accel(gas& G) {        //calculates acceleration

    double rSqd;
    double rij[3];
    double F;

    for (int i = 0; i < N; i++) {     //set acceleration to 0

        G.acceleration[i][0] = 0;
        G.acceleration[i][1] = 0;
        G.acceleration[i][2] = 0;
    }

    for (int i = 0; i < N-1; i++)
        for (int j = i+1; j > N; j++){

            rSqd = 0;

            rij[0] = G.position[i][0] - G.position[j][0];
            rij[1] = G.position[i][1] - G.position[j][1];
            rij[2] = G.position[i][2] - G.position[j][2];

            rSqd += rij[0] * rij[0];
            rSqd += rij[1] * rij[1];
            rSqd += rij[2] * rij[2];

            if (rSqd < 4){             //only close particles affect each other

                F = 24 * epsilon * (2 * std::pow(rSqd, -7) - std::pow(rSqd, -4));

                G.acceleration[i][0] += rij[0] * F;
                G.acceleration[i][1] += rij[1] * F;
                G.acceleration[i][2] += rij[2] * F;

                G.acceleration[j][0] -= rij[0] * F;
                G.acceleration[j][1] -= rij[1] * F;
                G.acceleration[j][2] -= rij[2] * F;
            }
        }


    double Fwall;
    double sqRwall;

    for (int i = 0; i < N; i++)                         //this simulates the wall
        for (int j =0; j < 3; j++)
    {

            if (G.position[i][j] < 2){
                
                sqRwall = std::pow(G.position[i][j],2);
                Fwall = 24 * epsilon * (2 * std::pow(sqRwall, -7) - std::pow(sqRwall, -4));
                G.acceleration[i][j] += Fwall;
            }

            else if (G.position[i][j] > a-2){

                sqRwall = std::pow(10-G.position[i][j],2);
                Fwall = 24 * epsilon * (2 * std::pow(sqRwall, -7) - std::pow(sqRwall, -4));
                G.acceleration[i][j] -= Fwall;

            }

    }
   

}


void vel_ver(gas& G, double dt){            //velocity-Verlet implementation

    accel(G);

    for (int i = 0; i < N; i++) {
        G.velocity[i][0] += 0.5 * G.acceleration[i][0] * dt;
        G.velocity[i][1] += 0.5 * G.acceleration[i][1] * dt;
        G.velocity[i][2] += 0.5 * G.acceleration[i][2] * dt;
    }

    for (int i = 0; i < N; i++){
        G.position[i][0] += G.velocity[i][0] * dt;
        G.position[i][1] += G.velocity[i][1] * dt;
        G.position[i][2] += G.velocity[i][2] * dt;

    }


    accel(G);

    for (int i = 0; i < N; i++){
        G.velocity[i][0] += 0.5 * G.acceleration[i][0] * dt;
        G.velocity[i][1] += 0.5 * G.acceleration[i][1] * dt;
        G.velocity[i][2] += 0.5 * G.acceleration[i][2] * dt;
    }

}


void temperature(gas& G, std::ofstream& file) {             //calculates temperature

    double E = 0;

    for (int i = 0; i < N; i++){
        E += std::pow(G.velocity[i][0], 2);
        E += std::pow(G.velocity[i][1], 2);
        E += std::pow(G.velocity[i][2], 2);
    }


    file << E/N * 1/3 << "\n";
}


int main() {

    time_t begin = std::time(NULL);

    double dt = 0.000000000000001;
    std::srand(time(NULL));

    gas G;

    initial_conditions(G);

    std::ofstream file("T.txt");

    for (int i = 0; i < 10000; i++){
        vel_ver(G, dt);
        temperature(G, file);
    }
    file.close();

    time_t end = std::time(NULL);

    std::cout << "took " << end-begin << " seconds\n";

    return 0;
}