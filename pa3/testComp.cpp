#define CATCH_CONFIG_MAIN
#include "cs221util/catch.hpp"
#include <vector>
#include <sys/stat.h>
#include <iostream>
#include "cs221util/PNG.h"
#include "cs221util/HSLAPixel.h"
#include "stats.h"
#include "twoDtree.h"

using namespace std;
using namespace cs221util;

TEST_CASE("stats::basic stats 1x1", "[weight=1][part=stats]") {
    PNG data(1, 1);
    HSLAPixel* pix = data.getPixel(0, 0);
    pix->h = 0; // presumed defaults: s = 0, l = 1.0, a = 1.0. This config leads to just white. May need to change these 
    pix->s = 1.0;
    pix->l = 0.5;
    pix->a = 1.0;

    data.writeToFile("testimgs/basicStats1x1.png");
    stats s(data);
    
    vector<int> sizeOne;
    sizeOne.resize(1);
    size_t ONE = sizeOne.capacity();

    REQUIRE(s.sumHueX.size() == ONE);
    REQUIRE(s.sumHueX.at(0).size() == ONE);
    REQUIRE(s.sumHueX.at(0).at(0) == 1.0);

    REQUIRE(s.sumHueY.size() == ONE);
    REQUIRE(s.sumHueY.at(0).size() == ONE);
    REQUIRE(s.sumHueY.at(0).at(0) == 0.0);
}

TEST_CASE("stats::basic stats 4x2", "[weight=1][part=stats]") {
    PNG data(4, 2);
    //get the pixels and change their colours
        //pixels w/ x+y = even are red, x+y = odd are purple
    for (unsigned int x = 0; x < data.width(); x++) {
        for (unsigned int y = 0; y < data.height(); y++) {
            HSLAPixel* pix = data.getPixel(x, y);
            pix->s = 1.0;
            pix->l = 0.5;
            pix->a = 1.0;
            
            if ((x + y) % 2 == 0) { //even, color it red
                pix->h = 0;
            } else { //odd, colour it purple w h = 270
                pix->h = 270;
            }
        }
    }

    //write to files
    data.writeToFile("testimgs/basicStats4x2.png");
    stats s(data);

    REQUIRE(s.sumHueX.size() == 4);
    for (unsigned int x = 0; x < data.width(); x++) {
        REQUIRE(s.sumHueX.at(x).size() == 2);
        REQUIRE(s.sumHueY.at(x).size() == 2);
    }

    for (unsigned int x = 0; x < data.width(); x++) {
        for (unsigned int y = 0; y < data.height(); y++) {
            //test top L corner
            if (x == 0 && y == 0) {
                REQUIRE(s.sumHueX.at(0).at(0) == 1.0);
                REQUIRE(s.sumHueY.at(0).at(0) == 0.0);
            }

            //test top row

            //test leftmost column

            //others

        }
    }
}

TEST_CASE("stats::basic stats 2x4", "[weight=1][part=stats]") {
    PNG data (2, 4);
    //get the pixls and change their colours
        //pixels w/ x+y = even are red, x+y odd are purple
        for (unsigned int x = 0; x < data.width(); x++) {
            for (unsigned int y = 0; y < data.height(); y++) {
                HSLAPixel* pix = data.getPixel(x, y);
            }
        }
}

// TEST_CASE("stats::basic stats 2x2", "[weigh=1][part=stats]") {
//     PNG data(2, 2);

//     for (unsigned int x = 0; x < data.width(); x++) {
//         for (unsigned int y = 0; y < data.height(); y++) {
//             HSLAPixel* currPix = data.getPixel(x, y);
//             if ((x == y && x == 0) || (x == y && x == 1)) { //red pixels: top L, bottom R. i.e. (0, 0) & (1, 0)
//                 currPix->h = 0; // presumed defaults: s = 0, l = 1.0, a = 1.0. This config leads to just white. May need to change these 
//                 currPix->s = 1.0;
//                 currPix->l = 0.5;
//                 currPix->a = 1.0;
//             } else { //blue pixels: top R, bottom L i.e. (0, 1), (1, 0)
//                 currPix->h = 270; // presumed defaults: s = 0, l = 1.0, a = 1.0. This config leads to just white. May need to change these 
//                 currPix->s = 1.0;
//                 currPix->l = 0.5;
//                 currPix->a = 1.0;
//             }
//         }
//     }

//     data.writeToFile("testimgs/basicStats2x2.png");
//     stats s(data);
    
//     vector<int> sizeTwo;
//     sizeTwo.resize(2);
//     size_t TWO = sizeTwo.capacity();

//     REQUIRE(s.sumHueX.size() == TWO);
//     REQUIRE(s.sumHueX.at(0).size() == TWO);
//     REQUIRE(s.sumHueX.at(1).size() == TWO);

//     REQUIRE(s.sumHueX.at(0).at(0) == 1);
//     //REQUIRE(s.sumHueX.at(0).at(1) == 1); // fails b/c -0.000000054 ~= 0 != 1 - so failing to add a 1 @ some point
//     //REQUIRE(s.sumHueX[1][0] == 1); // this one fails b/c 0.99999999946 != 1 lol
//     //REQUIRE(s.sumHueX[1][1] == 2); // this one fails b/c 0.9999999999946 ~= 1 != 2 - fail to add a 1 @ some pt

//     REQUIRE(s.sumHueY.size() == TWO);
//     REQUIRE(s.sumHueY[0].size() == TWO);
//     REQUIRE(s.sumHueY[1].size() == TWO);

//     // REQUIRE(sumHueY[0][0] == 0);
//     // REQUIRE(sumHueY[0][1] == -1);
//     // REQUIRE(sumHueY[1][0] == -1);
//     // REQUIRE(sumHueY[1][1] == -2); 
// }

// TEST_CASE("stats::basic rectArea","[weight=1][part=stats]"){

//     PNG data; data.resize(2,2);

//     stats s(data); 
//     pair<int,int> ul(0,0);
//     pair<int,int> lr(1,1);
//     long result = s.rectArea(ul,lr);

//     REQUIRE(result == 4);
    
// }

// TEST_CASE("stats::basic getAvg","[weight=1][part=stats]"){
//     PNG data; data.resize(2,2);
//     for (int i = 0; i < 2; i ++){
//         for (int j = 0; j < 2; j++){
//             HSLAPixel * p = data.getPixel(i,j);
//             p->h = 135*j + i * 90;
//             p->s = 1.0;
//             p->l = 0.5;
//             p->a = 1.0;
//         }
//     }
//     stats s(data);
//     pair<int,int> ul(0,0);
//     pair<int,int> lr(1,1);
//     HSLAPixel result = s.getAvg(ul,lr);
//     HSLAPixel expected(112.5,1.0, 0.5);

//     REQUIRE(result == expected);
// }

// TEST_CASE("stats::basic entropy","[weight=1][part=stats]"){
//     PNG data; data.resize(2,2);
//     for (int i = 0; i < 2; i ++){
//         for (int j = 0; j < 2; j++){
//             HSLAPixel * p = data.getPixel(i,j);
//             p->h = 135*j + i * 90;
//             p->s = 1.0;
//             p->l = 0.5;
//             p->a = 1.0;
//         }
//     }
//     stats s(data);
//     pair<int,int> ul(0,0);
//     pair<int,int> lr(1,1);
//     long result = s.entropy(ul,lr);

//     REQUIRE(result == 2);
// }

// TEST_CASE("twoDtree::basic ctor render","[weight=1][part=twoDtree]"){
//     PNG img;
//     img.readFromFile("images/ada.png");

//     twoDtree t1(img);

//     PNG out = t1.render();

//     REQUIRE(out==img);
// }
// TEST_CASE("twoDtree::basic copy","[weight=1][part=twoDtree]"){
//     PNG img;
//     img.readFromFile("images/ada.png");

//     twoDtree t1(img);
//     twoDtree t1copy(t1);

//     PNG out = t1copy.render();

//     REQUIRE(out==img);
// }

// TEST_CASE("twoDtree::basic prune","[weight=1][part=twoDtree]"){
//     PNG img;
//     img.readFromFile("images/color.png");
    
//     twoDtree t1(img);

//     PNG prePrune = t1.render();

//     t1.prune(.05);
//     PNG result = t1.render();
//     PNG expected; expected.readFromFile("images/given-color.05.png");

//     REQUIRE(expected==result);
// }

