#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofEnableSmoothing();
	ofSetVerticalSync(true);
	
	for (int i=0; i<30; i++) {
		nodes.push_back(testNode());
		nodes.back().setPosition(ofRandom(-3.0f, +3.0f), ofRandom(-3.0f, +3.0f), ofRandom(-3.0f, +3.0f));
		nodes.back().rotate(ofRandom(180.0f), ofVec3f(ofRandom(1.0f), ofRandom(1.0f), ofRandom(1.0f)));
	}
	
	scene.init(camera);
	for (int i=0; i<nodes.size(); i++)
		scene.add(nodes[i]);
	
	camera.setPosition(2.0f, 2.0f, 2.0f);
	camera.lookAt(ofVec3f(0.0f, 0.0f, 0.0f));
	
	light.setPointLight();
	light.setPosition(-3.0f, 3.0f, 3.0f);
	light.setAttenuation();
}

//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofBackground(40);
	camera.begin();
	light.enable();
	
	ofDrawGrid(10.0f);
	scene.draw();
	
	light.disable();
	ofDisableLighting();
	camera.end();
	
//	scene.getIndexBuffer().draw(0,0);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if (key == 'c')
		camera.toggleCursorDraw();
	if (key == ' ')
		GrabScene::AssetRegister.refresh();
}
