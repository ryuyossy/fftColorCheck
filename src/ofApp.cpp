#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowPosition( 2881, 0 );
    ofSetWindowShape(1920,1080);
    ofToggleFullscreen();
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);
    // FFTのサンプル数(2の累乗)を指定して初期化
    fft.setup(pow(2.0, 12.0));
    // GUI
    gui.setup();
    gui.add(saturation.setup("Saturation", 127, 0, 255));
    gui.loadFromFile("settings.xml");
}

//--------------------------------------------------------------
void ofApp::update(){
    mesh.clear();
    fft.update(); // FFT更新
    
    buffer = fft.getBins();
    
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < buffer.size()/10; i++) {
            // 色を設定
            //float hue = ofMap(i, 0, buffer.size(), 150, 0);
            //float br = ofMap(buffer[i], 0, 1, 5, 255);
            //ofColor col;
            //col.setHsb(hue, saturation, br);
            //ofSetColor(col);
            
            // 右
            if (buffer[i] < 0.01) {
                float rx = ofGetWindowWidth() * buffer[i]*2;
            }
            float rx = ofGetWindowWidth() * buffer[i];
            //float rx = ofMap(i, 0, buffer.size(), 1000, ofGetWidth() / 2.0);
            //ofLine(rx, -ofGetWidth() / 2.0, rx, ofGetWidth() / 2.0);
            
            mesh.addVertex(ofVec3f(rx, -ofGetWidth() / 2.0, 0));
            mesh.addColor(ofFloatColor(0.01,0.3,0.3,0.2));
            mesh.addIndex(i);
            mesh.addVertex(ofVec3f(rx, ofGetWidth()));
            mesh.addColor(ofFloatColor(0.2,0,0.2,0.2));
            mesh.addIndex(i+1);
            // 左
            if (buffer[i] < 0.01) {
                float lx = ofGetWindowWidth() * buffer[i]*2;
            }
            float lx = ofGetWindowWidth() * buffer[i];
            //float lx = ofMap(i, 0, buffer.size(), 1000, -ofGetWidth() / 2.0);
            //ofLine(lx, -ofGetWidth() / 2.0, lx, ofGetWidth() / 2.0);
            
            mesh.addVertex(ofVec3f(lx, -ofGetWidth() / 2.0, 0));
            mesh.addColor(ofFloatColor(0.02,0.2,0.5,0.2));
            mesh.addIndex(i);
            mesh.addVertex(ofVec3f(lx, ofGetWidth(), 0));
            mesh.addColor(ofFloatColor(0.5,0.2,0.4,0.2));
            mesh.addIndex(i+1);
        }
        //ofRotateZ(120);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // float型の配列にFFT結果を格納
    buffer = fft.getBins();

    // グラフに描画
    ofPushMatrix();
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    //ofSetLineWidth(ofGetWidth() / float(buffer.size()));
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    ofPopMatrix();
    
    mesh.setMode(OF_PRIMITIVE_LINES);
    mesh.draw();
    
    //GUI
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
