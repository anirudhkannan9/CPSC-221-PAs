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

// TEST_CASE("stats::basic stats 1x1", "[weight=1][part=stats]") {
//     PNG data(1, 1);
//     HSLAPixel* pix = data.getPixel(0, 0);
//     pix->h = 0; // presumed defaults: s = 0, l = 1.0, a = 1.0. This config leads to just white. May need to change these 
//     pix->s = 1.0;
//     pix->l = 0.5;
//     pix->a = 1.0;

//     data.writeToFile("testimgs/basicStats1x1.png");
//     stats s(data);
    
//     vector<int> sizeOne;
//     sizeOne.resize(1);
//     size_t ONE = sizeOne.capacity();

//     REQUIRE(s.sumHueX.size() == ONE);
//     REQUIRE(s.sumHueX[0].size() == ONE);
//     REQUIRE(s.sumHueX[0][0] == 1.0);

//     REQUIRE(s.sumHueY.size() == ONE);
//     REQUIRE(s.sumHueY[0].size() == ONE);
//     REQUIRE(s.sumHueY[0][0] == 0.0);
// }

TEST_CASE("stats::basic stats 2x2", "[weigh=1][part=stats]") {
    PNG data(2, 2);

    for (unsigned int x = 0; x < data.width(); x++) {
        for (unsigned int y = 0; y < data.height(); y++) {
            HSLAPixel* currPix = data.getPixel(x, y);
            if ((x == y && x == 0) || (x == y && x == 1)) { //red pixels: top L, bottom R. i.e. (0, 0) & (1, 0)
                currPix->h = 0; // presumed defaults: s = 0, l = 1.0, a = 1.0. This config leads to just white. May need to change these 
                currPix->s = 1.0;
                currPix->l = 0.5;
                currPix->a = 1.0;
            } else { //blue pixels: top R, bottom L i.e. (0, 1), (1, 0)
                currPix->h = 270; // presumed defaults: s = 0, l = 1.0, a = 1.0. This config leads to just white. May need to change these 
                currPix->s = 1.0;
                currPix->l = 0.5;
                currPix->a = 1.0;
            }
        }
    }

    data.writeToFile("testimgs/basicStats2x2.png");
    stats s(data);
    
    vector<int> sizeTwo;
    sizeTwo.resize(2);
    size_t TWO = sizeTwo.capacity();

    REQUIRE(sumHueX.size() == TWO);
    REQUIRE(sumHueX[0].size() == TWO);
    REQUIRE(sumHueX[1].size() == TWO);

    REQUIRE(sumHueX[0][0] == 1);
    REQUIRE(sumHueX[0][1] == 1);
    REQUIRE(sumHueX[1][0] == 1);
    REQUIRE(sumHueX[1][1] == 2);

    REQUIRE(sumHueY.size() == TWO);
    REQUIRE(sumHueY[0].size() == TWO);
    REQUIRE(sumHueY[1].size() == TWO);

    REQUIRE(sumHueY[0][0] == 0);
    REQUIRE(sumHueY[0][1] == -1);
    REQUIRE(sumHueY[1][0] == -1);
    REQUIRE(sumHueY[1][1] == -2); 
}

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

