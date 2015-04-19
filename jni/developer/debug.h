#pragma once

#include <string>
#include "mcpe.h"

namespace debug{
	class debugMenu{
	public:
		static debugMenu debugMenuHandle;
	public:
		debugMenu(Level*, TileSource*);
		std::string getVersionString();
		std::string getCoordsString();
		std::string getBlockCoordsString();
		std::string getChunkCoordsString();
		std::string getFacingString();
		std::string getBiomeString();
		std::string getLightString();
	private:
		Level* currentLevel;
		TileSource* currentTS;
	};
}
