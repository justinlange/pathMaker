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

enum directions { NONE, NORTH = 1, SOUTH = 2, EAST = 3, WEST = 4 };
class PathMaker {
    
    
public:
    PathMaker(int iTilesPerAxis = 8);
    
    ~PathMaker();
    
    bool solveWithBackTracking(int x, int y, int direction);
    void callSolver();
    
    vector<ofPoint> savePathAsPoints();
    
    vector<ofPoint> makeVector(int x, int y);
    vector<ofPoint> myVector;
    
    
    int newDir(int td);
    
    void drawToText();
    bool checkForAllSolutions();
    ofPolyline  returnPolyline();
    
    int returnX();
    int returnY();
    
    
    vector<ofPoint> path;
    
    ofPolyline      mLine;
    
    int         mMult;
    int         lineReps;
    int         margin;
    int         bigDist;
    int			mTilesPerAxis;
    bool**		mBoard;
    int			mSolutionCount;
    int			mTotalCallCount;
    int			mTempCallCount;
    int         eCt,wCt,nCt,sCt;
    int         squareSize;
    int         direction;
    int         mTilesFilled;

    
    
};



#endif
