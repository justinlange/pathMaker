#include "testApp.h"
#include "PathMaker.h"


//--------------------------------------------------------------
void testApp::setup(){
    
    
    mBoard = new PathMaker( 12 );
    mBoard->solveWithBackTracking(5, 5, SOUTH);
    
    //drawPath.clear();

    for(int i =0; i< mBoard->savePath().size(); i++){
        //drawPath.addVertex(mBoard->savePath().at(i));
        ofRect(mBoard->savePath().at(i), 10, 10);
    }
}


//--------------------------------------------------------------
void testApp::update(){
    


}

//--------------------------------------------------------------
void testApp::draw(){
    
    drawPath.draw();
    
}




//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
