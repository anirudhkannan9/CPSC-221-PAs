
#include "stats.h"

// initialize the private vectors so that, for each color channel, 
// (x,y) is the cumulative sum of the the color values from (0,0)
// to (x,y). 
// Note that the hue (h) value of each pixel is represented by
// its cartesian coordinates: X = cos(h) and Y = sin(h). 
// This is done to simplify distance and average computation.
stats::stats(PNG & im) {
    //there are private vectors: sumHueX, sumHueY, sumSat, sumLum, 
    //TODO: *If h ≥ 360, wrap around so subtract 360. As a guard - not an assumption*

//TODO: background:
    //first figure out how hue is translated into cartesian coordinates
    //  e.g. h = 0° => 0*(π/180) = 0rad. float hueX = std::cos(0) => hueX = 1
    //       h = 50° => 50*(π/180) => 0.872665rad. float hueX = cos(0.872665) = 0.642788
    //       h = 180° => 180*(π/180) = πrad. float hueX = cos(π) = -1 
    //       h = 243° => 243*(π/180) => 4.24115 rad. float hueX = cos(4.24115) = -.4453991
    //       h = 360° => 360*(π/180) => 2π rad. float hueX = cos(2π) = 1
    // i.e. hueX = cos(PI*pix->h/180) hueY = sin(PI*pix->h/180)

    //then figure out base cases. 
        //A 2x2 (4 pixel) img, w/ certain HSLA vals, write a test to see if init properly

//TODO: implementation:
    //implement for just e.g. hue first and make sure that's working

    //loop through all pixls in the img
    //for each pixel
        //get its hue
        //convert into hueX & hueY
        //is it the very first pixel in the rectangle?
            //Y: just add the values themselves to the right position
            //N: add curr values + prev cumSum => add the currentCumSum to the right position
}

long stats::rectArea(pair<int,int> ul, pair<int,int> lr)
{
    return 0;

}

HSLAPixel stats::getAvg(pair<int,int> ul, pair<int,int> lr)
{
    return HSLAPixel();

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
    
   // return  -1 * entropy; //calc the entropy, and then return the -ve of it
   return -1.0;
}
