//
// breakout.c
// hacker edition
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

//paddle position constants
#define PADDLEX 170 
#define PADDLEY 550

//paddle dimentions constants
#define PADDLEH 10
#define PADDLEW 80

//bricks dimentions constants
#define BHEIGHT 10
#define BWIDTH 36

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(int argc, char* argv[])
{
    //handling GOD MODE
        // ensure proper usage
        bool isGOD = false;
        if (argc == 2)
        {   
            char* in = argv[1];
            char* cmp = "GOD";
            if(strcmp(in,cmp) == 0){
            isGOD = true;
            printf("GOD Mode Is Active\n");
            }
            else
            {
            printf("GOD MODE USES : ./breakout GOD \n");
                return -1;
            }
        }
        if(argc > 2 ){
        printf("GOD MODE USES : ./breakout GOD \n");
            return -2;
        }
    //paddle width control constant
    int paddleWidth = PADDLEW;
    
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);
    sendForward(ball);  //send ball forword.
    
    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);
    sendBackward(label);    //send label backwords

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;

    //velocity constants for x and y directions for velocity of ball
    double velocityX = 0.025;
    double velocityY = 0.039; 
    
    //wait for click before starting
    waitForClick();

    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {   
        // if GOD MODE is active handle ball with god powers else handle control to user
        if(isGOD == true ){
            // moves paddle only in x direction with movement of ball.
                double x = getX(ball);
                if(x > paddleWidth/2 && x < WIDTH-(paddleWidth/2))
                {
                    setLocation(paddle, x-(paddleWidth/2), PADDLEY );
                }
        }
        else
        {
            //moving paddle with mouse movement in x direction only.
            // check for mouse event
            GEvent Mevent = getNextEvent(MOUSE_EVENT);
            // if we heard one
            if (Mevent != NULL)
            {
                // if the Mevent was a mouse movement
                if (getEventType(Mevent) == MOUSE_MOVED)
                {
                    // moves paddle only in x direction with movement of mouse.
                    double x = getX(Mevent);
                    if(x > paddleWidth/2 && x < WIDTH-(paddleWidth/2))
                    {
                        setLocation(paddle, x-(paddleWidth/2), PADDLEY );
                    }
                }
            }
        }
        //move ball with given velocity constants.
            move(ball, velocityX, velocityY );
                       
        
            // bounce off right edge of window
            if (getX(ball) + getWidth(ball) >= getWidth(window))
            {
                velocityX = -velocityX;
            }
            // bounce off left edge of window
            else if (getX(ball) <= 0)
            {
                velocityX = -velocityX;
            }
            //bounce off the top edge of window
            else if (getY(ball) <= 0)
            {
                velocityY = -velocityY;
            }
            //if ball touch bottom edge decrese a life and reset the ball at center of window and lunnch again after click.
            else if(getY(ball) + getHeight(ball) >= getHeight(window)) 
            {
                lives = lives-1;
                waitForClick();
                setLocation(ball, WIDTH/2, HEIGHT/2);
                    //close window if live finishes.
                    if(lives == 0){
                    closeGWindow(window);
                    }
            }
        //ball movement, edge bounce , and lives calculation part end here.
        //detect collsion of ball with other objects.
            //paddlecollde is the object with ball collided.
            GObject collide = detectCollision(window ,ball);
                if(collide == paddle){
                    velocityY = -velocityY;
                    
                    //funkey fun with color
                    char* colorpaddle = malloc(20*sizeof(char));
                    colorpaddle = getColorGObject(ball);
                    setColor(paddle,colorpaddle);
                    freeGObject(colorpaddle);
                }
                if(collide == label ){
                    //funkey fun with color
                    char* colorlabel = malloc(20*sizeof(char));
                    colorlabel = getColorGObject(ball);
                    setColor(label,colorlabel);               
                    freeGObject(colorlabel);
                }
             //collidedObj is the object with ball collides.
             GObject collidedObj = detectCollision(window, ball);   
             if(collidedObj){   
             if(collidedObj != paddle && collidedObj != label){
                    //funkey fun with color
                    char* colorball = malloc(20*sizeof(char));
                    colorball = getColorGObject(collidedObj);
                    setColor(ball,colorball);
                    freeGObject(colorball);
                //variable scoring based on rows  of bricks.    
                    double loc = getY(collidedObj);
                    if((int)loc == 110){
                    points=points+2;
                    }
                    if((int)loc == 95){
                    points=points+4;
                    }
                     if((int)loc == 80){
                    points=points+6;
                    }                   
                      if((int)loc == 65){
                    points=points+8;
                    }                  
                     if((int)loc == 50){
                    points=points+10;
                    }                   
                    //if collided object is brick then remove bricks and increse and update score and decrese no of bricks and bounce ball.
                    removeGWindow(window, collidedObj);
                    //variable points based on color or row no
                    bricks--;
                    updateScoreboard(window, label, points);
                    velocityY = -velocityY;
                // speed and paddle size control  
                    velocityY = velocityY+((float)bricks/68533.00);
                    paddleWidth = PADDLEW - (((ROWS*COLS)-bricks)/1.3 );
                    setSize(paddle, paddleWidth ,PADDLEH);
                    freeGObject(colorball);
                    freeGObject(collidedObj);
                }
          }
    }
    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    freeGObject(paddle);
    freeGObject(ball);
    freeGObject(label);
    return 0;
}
//main function ends and other functions starts here.
/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // initiate bricks each of different colour.
    int i,j,posX=1,posY=50;
    for(i=0;i<ROWS;i++)    {
        for(j=0;j<COLS;j++)   {
        GRect brick = newGRect(posX+(j*40) ,posY+(i*15), BWIDTH, BHEIGHT);
       setFilled(brick, true);
        if(i==0){   //these if conditions choose colour for each line of bricks.
            setColor(brick, "RED");
        }
        if(i==1){
            setColor(brick, "BLUE");
        }
        if(i==2){
            setColor(brick, "CYAN");
        }
        if(i==3){
            setColor(brick, "YELLOW");
        }
        if(i==4){
            setColor(brick, "MAGENTA");
        }
        add(window, brick);
        }
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    
    // create a new GOvel ( i.e. ball ) at center of window
    GOval ball = newGOval( (WIDTH/2)-RADIUS, (HEIGHT/2)-RADIUS, 2*RADIUS, 2*RADIUS);    //ball at center of window
    setColor(ball, "BLACK");
    setFilled(ball, true);
    add(window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    // create and return a paddle of type GRect
     GRect paddle = newGRect(PADDLEX ,PADDLEY , PADDLEW, PADDLEH);
        setFilled(paddle, true);
        setColor(paddle, "BLACK");
        add(window, paddle);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // initaes a scorebord and return type GLabel
        double x,y;
        GLabel label = newGLabel("0");
        setFont(label, "Arial-45");
        x = (getWidth(window) - getWidth(label)) / 2;
        y = (getHeight(window) + getFontAscent(label)) / 2;
        setLocation(label, x, y-50);
        add(window, label);
        sendBackward(label);    //send label backwords

    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
