#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    image.load("GlowPlant.jpg");
    image.resize(200, 200);
    
    ofSetFrameRate(60);
    
    mesh.setMode(OF_PRIMITIVE_LINES);
    mesh.enableIndices();
//    mesh.enableColors();
    
    float intensityThreshold = 150.0;
    int w = image.getWidth();
    int h = image.getHeight();
    for (int x = 0; x < w; x++){
        for (int y = 0; y < h; y++){
            ofColor c = image.getColor(x, y);
            float intensity = c.getLightness();
            if (intensity >= intensityThreshold) {
                float saturation = c.getSaturation();
                float z = ofMap (saturation, 0, 255, -100, 100);
                ofVec3f pos(x * 10, y * 10, z);
                mesh.addVertex(pos);
                mesh.addColor(c);
                offsets.push_back(ofVec3f(ofRandom(0, 100000), ofRandom(0, 100000), ofRandom(0, 100000)));
            }
        }
    }
    
    float connectionDistance = 30;
    int numVerts = mesh.getNumVertices();
    
    for (int a = 0; a < numVerts; a++){
        ofVec3f verta = mesh.getVertex(a);
        for (int b = a + 1; b < numVerts; b++){
            ofVec3f vertb = mesh.getVertex(b);
            float distance = verta.distance(vertb);
            if (distance <= connectionDistance) {
                mesh.addIndex(a);
                mesh.addIndex(b);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){

    int numVerts = mesh.getNumVertices();
    for (int i = 0; i < numVerts; i++){
        ofVec3f vert = mesh.getVertex(i);
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor centerColor = ofColor(85, 78, 68);
    ofColor edgeColor(0);
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
    
    easyCam.begin();
    ofPushMatrix();
    ofTranslate(-ofGetWidth(), -ofGetHeight());
    mesh.draw();
    ofPopMatrix();
    easyCam.end();
    
    cout << mesh.getNumVertices() << endl;
    
    image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == 's'){
        image.save("plantMesh.png");
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
