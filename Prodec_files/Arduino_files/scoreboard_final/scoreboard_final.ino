//4 segment connection
int la[4] = {2,3,4,5}; // first
int lb[4] = {6,7,8,9}; // second


int BCD[10][4] ={
{0,0,0,0},
{0,0,0,1},
{0,0,1,0},
{0,0,1,1},
{0,1,0,0},
{0,1,0,1},
{0,1,1,0},
{0,1,1,1},
{1,0,0,0},
{1,0,0,1}}; //BCD code


void calculate(int); //functions for calculating the left and right segment of a team.
void data_write(int,int);   //functions for writing left and right segment

int up_pin=10; //button pin for increment the score
int down_pin=11; //button pin for decrement the score


int read_down=0; //variable to read the state of the down button
int read_up=0;  //variable to read the state of the up button

int score=0; //variable to store the actual score
int score_dup=0;
int score_a=0; //variable to store the first digit of score
int score_b=0;  //varible to store the second digit of score
void setup()
{
    // setting button pin an input
    pinMode(up_pin,INPUT);
    pinMode(down_pin,INPUT);
    // setting all pins as output
    for(int i=0;i<4;i++)
    {
    pinMode(la[i],OUTPUT);
    pinMode(lb[i],OUTPUT);
    }

}
void loop()
{
    // reading the two button
    read_up=digitalRead(up_pin);
    read_down=digitalRead(down_pin);
    
    if (read_up==1)
    {   
        score+=1;
        read_up=0;
        calculate(score);
    }
    else if (read_down==1)
    {   
        score-=1;
        read_down=0;
        calculate(score);
    }
//delay(200);
}

void calculate(int score)
{
    score_dup=score;
    score_b=0;
    score_a=0;
    
    if (score<10)
    {
        score_b=score;
        score_a=0;
    }
    else
    {
        score_b=score % 10;
        score_a=score_dup/10;
    }
    data_write(score_a,score_b);
    
    
}


void data_write(int left,int right) 
{
    for (int j=0; j < 4; j++) 
    {
        digitalWrite(la[j], BCD[left][j]);
    }
 
    for (int j=0; j < 4; j++) 
    {
        digitalWrite(lb[j], BCD[right][j]);
    }
  delay(400);
}
