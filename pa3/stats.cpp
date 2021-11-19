
#include "stats.h"

// initialize the private vectors so that, for each color channel, 
// (x,y) is the cumulative sum of the the color values from (0,0)
// to (x,y). 
// Note that the hue (h) value of each pixel is represented by
// its cartesian coordinates: X = cos(h) and Y = sin(h). 
// This is done to simplify distance and average computation.
stats::stats(PNG & im) {
    //there are private vectors: sumHueX, sumHueY, sumSat, sumLum, 

//background:
    //first figure out how hue is translated into cartesian coordinates
    //then figure out base cases. 
        //A 1x1 (1 pixel) img, with certain HSLA values, write a test to see if this is initialised properly 
        //A 2x2 (4 pixel) img, w/ certain HSLA vals, write a test to see if init properly

//implementation:

}

long stats::rectArea(pair<int,int> ul, pair<int,int> lr){

/* your code here */

}

HSLAPixel stats::getAvg(pair<int,int> ul, pair<int,int> lr){

/* your code here */

}

double stats::entropy(pair<int,int> ul, pair<int,int> lr){

    vector<int> distn;

    /* using private member hist, assemble the distribution over the
    *  given rectangle defined by points ul, and lr into variable distn.
    *  You will use distn to compute the entropy over the rectangle.
    *  if any bin in the distn has frequency 0, then do not add that 
    *  term to the entropy total. see .h file for more details.
    */

    /* my code includes the following lines:
        if (distn[i] > 0 ) 
            entropy += ((double) distn[i]/(double) area) 
                                    * log2((double) distn[i]/(double) area);
    */
    
    return  -1 * entropy;
}
