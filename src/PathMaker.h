//
//  PathMaker.h
//  ofPathMaker
//
//  Created by Justin Lange on 10/6/13.
//
//

#ifndef ofPathMaker_PathMaker_h
#define ofPathMaker_PathMaker_h

#include "ofMain.h"

enum directions { NONE, NORTH = 1, EAST = 2, SOUTH = 3, WEST = 4 };
class PathMaker {
    
    
public:
    PathMaker(int iTilesPerAxis = 8);
    
    ~PathMaker();
    
    bool solveWithBackTracking(int x, int y, int direction);
    vector<ofPoint> savePath();
    
    int newDir(int td);
    
    void drawToText();
    
    
    //vector<ofPoints> path;
    
    int         lineReps;
    int         dist;
    int         bigDist;
    int			mTilesPerAxis;
    bool**		mBoard;
    int			mSolutionCount;
    int			mTotalCallCount;
    int			mTempCallCount;
    int         eCt,wCt,nCt,sCt;
    int         squareSize;
    int         direction;
    
    
};



#endif
