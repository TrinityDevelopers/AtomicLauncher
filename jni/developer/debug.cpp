#include "debug.h"
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace debug; //Remove namespace temporarily


debugMenu::debugMenu(Level* curLevel, TileSource* curTS){
	currentLevel = curLevel;
	currentTS = curTS;
}


std::string debugMenu::getVersionString(){
	return "Minecraft Pocket Edition " + Common::getGameVersionString();
}

std::string debugMenu::getCoordsString() {
	std::stringstream coords;
	float x = currentLevel->getLocalPlayer()->x;
	float y = currentLevel->getLocalPlayer()->y;
	float z = currentLevel->getLocalPlayer()->z;
	coords << "XYZ: " << x << " / " << y << " / " << z;
	return coords.str();
}

std::string debugMenu::getBlockCoordsString() {
	std::stringstream blockCoords;
	int x = currentLevel->getLocalPlayer()->x;
	int y = currentLevel->getLocalPlayer()->y;
	int z = currentLevel->getLocalPlayer()->z;
	blockCoords << "Block: " << x << " " << y << " " << z;
	return blockCoords.str();
}

std::string debugMenu::getChunkCoordsString() {
	std::stringstream chunkCoords;
	int x = currentLevel->getLocalPlayer()->x;
	int y = currentLevel->getLocalPlayer()->y;
	int z = currentLevel->getLocalPlayer()->z;
	chunkCoords << "Chunk: " << (x & 0xf) << " " << (y & 0xf) << " " << (z & 0xf) << " in " << x / 16 << " " << y / 16 << " " << z / 16;
	return chunkCoords.str();
}

std::string debugMenu::getFacingString() {
	std::stringstream facing;
	double rotX = currentLevel->getLocalPlayer()->rotX;
	rotX = (floor(rotX * 10 + 0.5)) / 10;
	double rotY = currentLevel->getLocalPlayer()->rotY;
	rotY = (floor(rotY * 10 + 0.5)) / 10;
	std::string compassFacing;
	if (rotX >= 0) rotX = fmod(rotX, 360);
	if (rotX > 0) {
		if (rotX > 315 || rotX < 45) compassFacing = "South (Towards positive Z) ";
		else if (rotX > 45 && rotX < 135) compassFacing = "West (Towards negative X) ";
		else if (rotX > 135 && rotX < 225) compassFacing = "North (Towards negative Z) ";
		else if (rotX > 225 && rotX < 315) compassFacing = "East (Towards positive X) ";
	}
	else {
		if ((360 + rotX) > 315 || (360 + rotX) < 45) compassFacing = "South (Towards positive Z) ";
		else if ((360 + rotX) > 45 && (360 + rotX) < 135) compassFacing = "West (Towards negative X) ";
		else if ((360 + rotX) > 135 && (360 + rotX) < 225) compassFacing = "North (Towards negative Z) ";
		else if ((360 + rotX) > 225 && (360 + rotX) < 315) compassFacing = "East (Towards positive X) ";
	}
	facing << "Facing: " << compassFacing << "(" << rotX << " / " << rotY << ")";
	return facing.str();
}

std::string debugMenu::getBiomeString() {
	TilePos coords = *new TilePos(currentLevel->getLocalPlayer()->x, currentLevel->getLocalPlayer()->y, currentLevel->getLocalPlayer()->z);
	return "Biome: " + biomeTypeNames[currentTS->getBiome(coords)->getBiomeType()];
}

std::string debugMenu::getLightString() {
	std::stringstream light;
	TilePos coords(currentLevel->getLocalPlayer()->x, currentLevel->getLocalPlayer()->y, currentLevel->getLocalPlayer()->z);
	int skyLight = currentTS->getBrightness(LightLayer::Sky, coords);
	int blockLight = currentTS->getBrightness(LightLayer::Block, coords);
	int totalLight = (skyLight + blockLight <= 15) ? skyLight + blockLight : 15;
	light << "Light: " << totalLight << " (" << skyLight << " sky, " << blockLight << " block)";
	return light.str();
}
