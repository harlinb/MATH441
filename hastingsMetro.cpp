#include <iostream>
#include <fstream>
//#include <sstream>
#include <string>       // provides string class
//#include <cstdlib>
#include <stdlib.h>
#include <math.h>


using namespace std;

#define FORWARD 1
#define DEFENSE 2
#define GOALIE 3
#define MAX_VALUE 30

struct Player{
    string name;
    int value;
    double ePoints;
    int points;
    int position;
    int key;

};

int histogram[86] = {0};

Player makePlayer(string name, int value, double ePoints, int points, int position, int key){
    Player newPlayer;
    newPlayer.name=name;
    newPlayer.value = value;
    newPlayer.ePoints = ePoints;
    newPlayer.points = points;
    newPlayer.position = position;
    newPlayer.key = key;

    return newPlayer;

}


int calcMean(int histogram[86], int iter){
    int val=0;

    for(int i=0; i<86; i++){
        val = val + (i*histogram[i]);

    }

    val=(val/iter);

}


int countPoints(Player fPickArray[], Player dPickArray[], Player gPickArray[]){
    int count=0;
    int r;


    //double count for star
    r = rand()%6;
    count = count + fPickArray[r].points;
    for(int i=0;i<6;i++){
        count = count + fPickArray[i].points;
    }


    //double count for star
    r=rand()%4;
    count = count + dPickArray[r].points;
    for(int i=0; i<4; i++){
        count = count + dPickArray[i].points;
    }

    //double count for star
    r=rand()%2;
    count = count + gPickArray[r].points;
    for(int i=0; i<2; i++){
        count = count + gPickArray[i].points;
    }

    return count;

}

void run(Player fArray[81], Player dArray[27], Player gArray[23], Player fPickArray[6], Player dPickArray[4], Player gPickArray[2], int iter){
    int seed;
    bool cv = true;
    int r1;
    int r2;
    int k=0;
    int sum=24;
    int points;
    bool cv2 = true;


    printf("Enter Seed:");
    scanf("%d", &seed);
    srand(seed);

    for(int i=0; i<iter; i++){

        while(cv){

            r1 = rand()%6;
            r2 = rand()%80;



            if(sum - fPickArray[r1].value + fArray[r2].value <= 30){

                while(k<6){
                    if(fPickArray[k].key == fArray[r2].key){
                        cv2=false;
                    }
                    k++;
                }

                if(cv2){

                    sum = sum - fPickArray[r1].value;
                    fPickArray[r1] = fArray[r2];
                    sum = sum + fPickArray[r1].value;
                    cv=false;
                }

            }
            cv2 = true;
            k=0;

        }

        cv=true;

        while(cv){
            r1=rand()%4;
            r2 = rand()%27;
            if((sum - dPickArray[r1].value + dArray[r2].value) <= 30){

                while(k<4){
                    if(dPickArray[k].key == dArray[r2].key){
                        cv2=false;
                    }
                    k++;
                }

                if(cv2){

                    sum = sum - dPickArray[r1].value;
                    dPickArray[r1] = dArray[r2];
                    sum = sum + dPickArray[r1].value;
                    cv=false;

                }
            }
            cv2=true;
            k=0;

        }

        cv=true;

        while(cv){
            r2 = rand()%23;
            r1=rand()%2;
            if(sum - gPickArray[r1].value + gArray[r2].value <= 30){

                while(k<2){
                    if(gPickArray[k].key == gArray[r2].key){
                        cv2=false;
                    }
                    k++;
                }

                if(cv2){

                    sum = sum - gPickArray[r1].value;
                    gPickArray[r1] = gArray[r2];
                    sum = sum + gPickArray[r1].value;
                    cv=false;
                }
            }
            cv2=true;
            k=0;
        }

        cv=true;


        //cout<<"sum: "<<sum<<endl;
        points = countPoints(fPickArray, dPickArray, gPickArray);
        histogram[points]=histogram[points]+1;

         k=0;

    }



    points = countPoints(fPickArray, dPickArray, gPickArray);
    cout<<"Histogram:"<<endl;

    for(int p=0; p<86; p++){
        cout<< p <<": "<<histogram[p]<<endl;
    }


}




int main( int argc, char* argv[] ) {
    int iter;
    int mean=0;
    

    //Forwards
    Player f1 = makePlayer("James Neal", 3, 8.5, 2, FORWARD, 1);
    Player f2 = makePlayer("Jonathan Toews",3, 7.75, 2, FORWARD, 2);
    Player f3 = makePlayer("Evgeni Malkin", 4, 7.67, 4, FORWARD, 3);
    Player f4 = makePlayer("Joe Thorton", 3, 6.33, 2, FORWARD, 4);
    Player f5 = makePlayer("Sidney Crosby", 4, 5.83, 6, FORWARD, 5);
    Player f6 = makePlayer("Patrick Sharp", 3, 5.33, 3, FORWARD, 6);
    Player f7 = makePlayer("Eric Staal", 3, 5.17, 2, FORWARD, 7);
    Player f8 = makePlayer("Radim Vrbata", 3, 5, 1, FORWARD, 8);
    Player f9 = makePlayer("Alexander Semin", 2, 4.92, 1, FORWARD, 9);
    Player f10 = makePlayer("Joe Pavelski", 3, 4.75, 5, FORWARD, 10);
    Player f11 = makePlayer("Kyle Turris", 2, 4.67, 4, FORWARD, 11);
    Player f12 = makePlayer("Logan Couture", 3, 4.5, 2, FORWARD, 12);
    Player f13 = makePlayer("Phil Kessel", 3, 4.4, 3, FORWARD, 13);
    Player f14 = makePlayer("Claude Giroux", 3, 4.33, 6, FORWARD, 14);
    Player f15 = makePlayer("Wayne Simmonds", 2, 4.33, 3, FORWARD, 15);
    Player f16 = makePlayer("Clarke MacArthur", 2, 4.33, 4, FORWARD, 16);
    Player f17 = makePlayer("Jason Spezza", 3, 4.17, 2, FORWARD, 17);
    Player f18 = makePlayer("Jiri Hudler", 3, 4.1, 2, FORWARD, 18);
    Player f19 = makePlayer("Tyler Seguin", 3, 3.92, 4, FORWARD, 19);
    Player f20 = makePlayer("Chris Kunitz", 3, 3.58, 2, FORWARD, 20);
    Player f21 = makePlayer("Gustav Nyquist", 1, 3.5, 6, FORWARD, 21);
    Player f22 = makePlayer("Patrick Marleau", 3, 3.5, 4, FORWARD, 22);
    Player f23 = makePlayer("Gabriel Landeskog", 2, 3.33, 4, FORWARD, 23);
    Player f24 = makePlayer("Brad Marchand", 2, 3.17, 1, FORWARD, 24);
    Player f25 = makePlayer("Patrik Elias", 2, 3, 2, FORWARD, 25);
    Player f26 = makePlayer("Marian Gaborik", 2, 3, 2, FORWARD, 26);
    Player f27 = makePlayer("Joffrey Lupul", 2, 3, 3, FORWARD, 27);
    Player f28 = makePlayer("Corey Perry", 4, 3, 3, FORWARD, 28);
    Player f29 = makePlayer("Valtteri Filppula", 2, 3, 3, FORWARD, 29);
    Player f30 = makePlayer("Mike Richards", 2, 3, 2, FORWARD, 30);
    Player f31 = makePlayer("Jamie Benn", 3, 3, 4, FORWARD, 31);
    Player f32 = makePlayer("Mikael Backlund", 1, 3, 1, FORWARD, 32);
    Player f33 = makePlayer("Matt Duchene", 3, 3, 3, FORWARD, 33);
    Player f34 = makePlayer("Nick Bonino", 2, 3, 2, FORWARD, 34);
    Player f35 = makePlayer("Anze Kopitar", 3, 3, 2, FORWARD, 35);
    Player f36 = makePlayer("Jeff Skinner", 2, 3, 3, FORWARD, 36);
    Player f37 = makePlayer("Andrew Coglian", 2, 3, 1, FORWARD, 37);
    Player f38 = makePlayer("Ales Hemsky", 2, 3, 1, FORWARD, 38);
    Player f39 = makePlayer("Jaromir Jagr", 2, 3, 0, FORWARD, 39);
    Player f40 = makePlayer("Taylor Hall", 3, 3, 3, FORWARD, 40);
    Player f41 = makePlayer("David Legwand", 2, 3, 2, FORWARD, 41);
    Player f42 = makePlayer("Wheeler", 2, 3, 3, FORWARD, 42);
    Player f43 = makePlayer("Foligno", 1, 3, 1, FORWARD, 43);
    Player f44 = makePlayer("Patrice", 2, 3, 4, FORWARD, 44);
    Player f45 = makePlayer("Cammalleri", 2, 3, 5, FORWARD, 45);
    Player f46 = makePlayer("Tyler Johnson", 1, 3, 1, FORWARD, 46);
    Player f47 = makePlayer("Johansen", 2, 3, 2, FORWARD, 47);
    Player f48 = makePlayer("James Van", 3, 3, 2, FORWARD, 48);
    Player f49 = makePlayer("Johan F", 2, 3, 1, FORWARD, 49);
    Player f50 = makePlayer("Backes", 3, 3, 6, FORWARD, 50);
    Player f51 = makePlayer("Oshie", 3, 3, 6, FORWARD, 51);
    Player f52 = makePlayer("Antoine", 2, 3, 3, FORWARD, 52);
    Player f53 = makePlayer("Thomas V", 3, 3, 4, FORWARD, 53);
    Player f54 = makePlayer("Jarome", 2, 3, 2, FORWARD, 54);
    Player f55 = makePlayer("Lucic", 2, 3, 1, FORWARD, 55);
    Player f56 = makePlayer("Brassard", 1, 3, 1, FORWARD, 56);
    Player f57 = makePlayer("Getzlaf", 4, 3, 4, FORWARD, 57);
    Player f58 = makePlayer("Stamkos", 4, 3, 3, FORWARD, 58);
    Player f59 = makePlayer("Daniel A", 2, 3, 1, FORWARD, 59);
    Player f60 = makePlayer("Andrew ladd", 2, 3, 1, FORWARD, 60);
    Player f61 = makePlayer("Martin St Louis", 3, 3, 0, FORWARD, 61);
    Player f62 = makePlayer("Nugent-Hopkins", 2, 3, 2, FORWARD, 62);
    Player f63 = makePlayer("Max Pac", 2, 3, 3, FORWARD, 63);
    Player f64 = makePlayer("Adam Henrique", 1, 3, 2, FORWARD, 64);
    Player f65 = makePlayer("Callahan", 2, 3, 3, FORWARD, 65);
    Player f66 = makePlayer("Backstrom", 3, 3, 1, FORWARD, 66);
    Player f67 = makePlayer("Jess Carter", 2, 3, 0, FORWARD, 67);
    Player f68 = makePlayer("Mackinnon", 2, 3, 1, FORWARD, 68);
    Player f69 = makePlayer("Tyler Bozak", 2, 3, 3, FORWARD, 69);
    Player f70 = makePlayer("Reilly Smith", 2, 3, 0, FORWARD, 70);
    Player f71 = makePlayer("Shane Doan", 2, 3, 3, FORWARD, 71);
    Player f72 = makePlayer("Teddy Purcel", 2, 3, 0, FORWARD, 72);
    Player f73 = makePlayer("Mathieu P", 2, 3, 4, FORWARD, 73);
    Player f74 = makePlayer("Teemu", 1, 3, 3, FORWARD, 74);
    Player f75 = makePlayer("Soderberg", 1, 3, 1, FORWARD, 75);
    Player f76 = makePlayer("Ryan O'Reilly", 2, 3, 1, FORWARD, 76);
    Player f77 = makePlayer("Alexander O", 4, 3, 3, FORWARD, 77);
    Player f78 = makePlayer("Mikkel B", 2, 3, 3, FORWARD, 78);
    Player f79 = makePlayer("David K", 3, 3, 0, FORWARD, 79);
    Player f80 = makePlayer("Artem A", 1, 3, 0, FORWARD, 80);
    Player f81 = makePlayer("Patrik B", 1, 3, 1, FORWARD, 81);


    //Defensemen

    Player d1 = makePlayer("Erik Karlsson", 3, 4.42, 5, DEFENSE, 1);
    Player d2 = makePlayer("Shea Weber", 2, 4.33, 2, DEFENSE, 2);
    Player d3 = makePlayer("Oliver Ekman-Larsson", 2, 4, 2, DEFENSE, 3);
    Player d4 = makePlayer("Duncan Keith", 3, 4, 2, DEFENSE, 4);
    Player d5 = makePlayer("Matt Niskanen", 1, 3.5, 1, DEFENSE, 5);
    Player d6 = makePlayer("Andrei Markov", 2, 3.17, 2, DEFENSE, 6);
    Player d7 = makePlayer("Ryan Suter", 2, 3.17, 3, DEFENSE, 7);
    Player d8 = makePlayer("Kevin Shattenkirk", 2, 2.5, 2, DEFENSE, 8);
    Player d9 = makePlayer("Victor Hedman", 2, 2.42, 2, DEFENSE, 9);
    Player d10 = makePlayer("PK Subban", 3, 2.32, 3, DEFENSE, 10);
    Player d11= makePlayer("Eric Gelinas", 1, 2.33, 0, DEFENSE, 11);
    Player d12 = makePlayer("Niklas Hjalmarsson", 1, 2.41, 0, DEFENSE, 12);
    Player d13 = makePlayer("Brent Seabrook", 2, 2.12, 2, DEFENSE, 13);
    Player d14 = makePlayer("Torey Krug", 2, 2, 0, DEFENSE, 14);
    Player d15 = makePlayer("Jason Garrison", 2, 2, 0, DEFENSE, 15);
    Player d16 = makePlayer("Brian Campbell", 2, 2, 1, DEFENSE, 16);
    Player d17 = makePlayer("Andrei", 2, 1.83, 2, DEFENSE, 17);
    Player d18 = makePlayer("Wisniewski", 2, 1.83, 4, DEFENSE, 18);
    Player d19 = makePlayer("Brodie", 1, 1.83, 4, DEFENSE, 19);
    Player d20 = makePlayer("Meszaros", 1, 1.83, 1, DEFENSE, 20);
    Player d21 = makePlayer("Maatta", 1, 1.83, 0, DEFENSE, 21);
    Player d22 = makePlayer("Zidlicky", 2, 1.83, 1, DEFENSE, 22);
    Player d23 = makePlayer("Tyutin", 1, 1.83, 0, DEFENSE, 23);
    Player d24 = makePlayer("Rielly", 1, 1.83, 1, DEFENSE, 24);
    Player d25 = makePlayer("Streit", 1, 1.83, 2, DEFENSE, 25);
    Player d26 = makePlayer("Enstrom", 1, 1.83, 2, DEFENSE, 26);
    Player d27 = makePlayer("Jay Bouwmeester", 2, 1.83, 2, DEFENSE, 27);
    Player d28 = makePlayer("Demers", 1, 1.83, 1, DEFENSE, 28);
    Player d29 = makePlayer("Kimmo", 1, 1.83, 2, DEFENSE, 29);
    Player d30 = makePlayer("Doughty", 2, 1.83, 2, DEFENSE, 30);
    Player d31 = makePlayer("Kronwall", 2, 1.83, 1, DEFENSE, 31);
    Player d32 = makePlayer("Gilbert T", 1, 1.83, 0, DEFENSE, 32);
    Player d33 = makePlayer("Voynov", 2, 1.83, 2, DEFENSE, 33);
    Player d34 = makePlayer("Lovejoy", 1, 1.83, 0, DEFENSE, 34);
    Player d35 = makePlayer("Chara", 2, 1.83, 1, DEFENSE, 35);
    Player d36 = makePlayer("Pietrangelo", 2, 1.83, 2, DEFENSE, 36);
    Player d37 = makePlayer("Hamilton, Dougie", 1, 1.83, 2, DEFENSE, 37);
    Player d38 = makePlayer("Benoit", 1, 1.83, 2, DEFENSE, 38);
    Player d39 = makePlayer("Gudas, Radko", 1, 1.83, 3, DEFENSE, 39);
    Player d40 = makePlayer("DeKeyser", 1, 1.83, 0, DEFENSE, 40);
    Player d41 = makePlayer("Trouba", 1, 1.83, 0, DEFENSE, 41);
    Player d42 = makePlayer("Andrew Macdonald", 1, 1.83, 1, DEFENSE, 42);
    Player d43 = makePlayer("Matt Carle", 1, 1.83, 1, DEFENSE, 43);
    Player d44 = makePlayer("Nick Leddy", 1, 1.83, 0, DEFENSE, 44);
    Player d45 = makePlayer("Jake Gardiner", 1, 1.83, 4, DEFENSE, 45);
    Player d46 = makePlayer("Francois b", 1, 1.83, 0, DEFENSE, 46);
    Player d47 = makePlayer("John Calrson", 2, 1.83, 1, DEFENSE, 47);
    Player d48 = makePlayer("Erik Johnson", 1, 1.83, 0, DEFENSE, 48);
    Player d49 = makePlayer("Mike Green", 2, 1.83, 0, DEFENSE, 49);


    //Goalies
    Player g1 = makePlayer("Carey Price", 3, 7, 7, GOALIE, 1);
    Player g2 = makePlayer("Jimmy Howard", 3, 7, 3, GOALIE, 2);
    Player g3 = makePlayer("Mike Smith", 3, 7, 0, GOALIE, 3);
    Player g4 = makePlayer("Steve Mason", 3, 7, 4, GOALIE, 4);
    Player g5 = makePlayer("Corey Crawford", 3, 7, 2, GOALIE, 5);
    Player g6 = makePlayer("Jon Quick", 3, 7, 7, GOALIE, 6);
    Player g7 = makePlayer("Antti Niemi", 3, 7, 3, GOALIE, 7);
    Player g8 = makePlayer("Anton Khubodin", 3, 7, 3, GOALIE, 8);
    Player g9 = makePlayer("Henrik", 3, 7, 7, GOALIE, 9);
    Player g10 = makePlayer("Marc-Andre", 4, 7, 2, GOALIE, 10);
    Player g11 = makePlayer("Jonas", 3, 7, 5, GOALIE, 11);
    Player g12 = makePlayer("Karri", 2, 7, 6, GOALIE, 12);
    Player g13 = makePlayer("Halak", 3, 7, 1, GOALIE, 13);
    Player g14 = makePlayer("Bobrovsky", 3, 7, 0, GOALIE, 14);
    Player g15 = makePlayer("Kuemper", 2, 7, 0, GOALIE, 15);
    Player g16 = makePlayer("Chad Johnson", 3, 7, 0, GOALIE, 16);
    Player g17 = makePlayer("Roberto", 4, 7, 2, GOALIE, 17);
    Player g18 = makePlayer("Tuukka", 4, 7, 6, GOALIE, 18);
    Player g19 = makePlayer("Semyon", 3, 7, 4, GOALIE, 19);
    Player g20 = makePlayer("Lehner", 2, 7, 3, GOALIE, 20);
    Player g21 = makePlayer("Bishop", 3, 7, 3, GOALIE, 21);
    Player g22 = makePlayer("Eddie Lack", 2, 7, 5, GOALIE, 22);
    Player g23 = makePlayer("Ryan Miller", 3, 7, 4, GOALIE, 23);


    Player T1 =makePlayer("Start", 2, 0, 2, 0, 0);

    Player fArray[81]={f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44, f45, f46, f47, f48, f49, f50, f51, f52, f53, f54, f55, f56, f57, f58, f59, f60, f61, f62, f63, f64, f65, f66, f67, f68, f69, f70, f71, f72, f73, f74, f75, f76, f77, f78, f79, f80, f81};
    Player dArray[49]={d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15, d16, d17, d18, d19, d20, d21, d22, d23, d24, d25, d26, d27, d28, d29, d30, d31, d32, d33, d34, d35, d36, d37, d38, d39, d40, d41, d42, d43, d44, d45, d46, d47, d48, d49};
    Player gArray[23]={g1, g2, g3, g4, g5, g6, g7, g8, g9, g10, g11, g12, g13, g14, g15, g16, g17, g18, g19, g20, g21, g22, g23};

    Player fPickArray[6] = {T1, T1, T1, T1, T1, T1};
    Player dPickArray[4] = {T1, T1, T1, T1};
    Player gPickArray[2] = {T1, T1};


    cout<<"How many iterations? :";
    scanf("%d",&iter);
    run(fArray, dArray, gArray, fPickArray, dPickArray, gPickArray, iter);
    mean = calcMean(histogram, iter);
    

    cout<<"Mean is: "<<mean<<endl;
    return 0;
}

