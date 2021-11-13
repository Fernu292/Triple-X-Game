#include<iostream>
using namespace std;

void PrintIntroduction(int Difficulty){
    cout<<"\nYou are a secret agent breaking into a leve: "<<Difficulty<<endl;
    cout<<"secure server room... \nEnter the correct code to continue..."<<endl;

}

bool PlayGame(int difficulty){

    PrintIntroduction(difficulty);

    const int CodeA = rand()%difficulty+4;
    const int CodeB = rand()%difficulty+4;
    const int CodeC = rand()%difficulty+4;

    const int CodeSum = CodeA+CodeB+CodeC;
    const int CodeProduct = CodeA*CodeB*CodeC;

    //Print the sum as a code
    cout<<endl;
    cout<<"There are 3 numbers in the code"<<endl;
    cout<<"+ The codes add-up to: "<<CodeSum<<endl;
    cout<<"+ Te codes multuply to give: "<<CodeProduct<<endl;

    int guessA, guessB, guessC;

    cin>>guessA>>guessB>>guessC;
    

    int guessSum = guessA+guessB+guessC;
    int guessProduct = guessA*guessB*guessC;

    //Check if the player accert in the code 
    if(guessSum == CodeSum && guessProduct==CodeProduct){
        cout<<"***Good work agent! you have extracted a file keep going***"<<endl;
        return true;
    }
    else{
        cout<<"***You entered the wrong code! Careful agent Try again! ***"<<endl;

        return false;
    }
    
}

int main(){
     
    int difficultLevel =1;
    int const MaxDifficulty = 5;
    while (difficultLevel<=MaxDifficulty)
    {
        bool bLevelComplete;

        bLevelComplete = PlayGame(difficultLevel);


        cin.clear(); //Clear any erros
        cin.ignore();//Discards the buffer

        if(bLevelComplete){
            //increase the lever dificulty

            ++difficultLevel;

        }
        
    }
    

    cout<<"Concratulations for complete all levels of this game";
   
    return 0;
}